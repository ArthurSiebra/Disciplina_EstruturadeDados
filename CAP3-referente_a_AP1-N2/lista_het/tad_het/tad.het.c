#include <stdio.h>
#include <stdlib.h>
#include "tad.het.h"

lista_het *cria_tri(float b, float h){

    triangulo *t =(triangulo*)malloc(sizeof(triangulo));
    if(!t)
        exit(2);
    
    t->b = b;
    t->h = h;

    lista_het *lh = (lista_het*)malloc(sizeof(lista_het));
    if(!lh)
        exit(1);

    lh->geometria = TRI;
    lh->info = t;
    lh->prox = NULL;

    return lh;
}

lista_het *cria_cir(float r){

    circulo *c = (circulo*)malloc(sizeof(circulo));
    if(!c)
        exit(2);

    c->r = r;

    lista_het *lh = (lista_het*)malloc(sizeof(lista_het));
    if(!lh)
        exit(1);

    lh->geometria = CIR;
    lh->info = c;
    lh->prox = NULL;

    return lh;
}

lista_het *cria_ret(float b, float h){
     
    retangulo *r = (retangulo*)malloc(sizeof(retangulo));
    if(!r)
        exit(2);

    r->b = b;
    r->h = h;

    lista_het *lh = (lista_het*)malloc(sizeof(lista_het));
    if(!lh)
        exit(1);

    lh->geometria = RET;
    lh->info = r;
    lh->prox = NULL;

    return lh;
}
lista_het *ensere(lista_het*lh, Tipo geometria){

    lista_het *elemento = NULL;

    switch(geometria){

        case TRI:

            float b, h;

            printf("dgite a altura:");
            scanf("%f", &h);
            printf("digite a base:");
            scanf("%f",&b);

            elemento = cria_tri(b,h);
        break;

        case CIR:

            float r;

            printf("digite o raio do circulo");
            scanf("%f",&r);

            elemento = cria_cir(r);

        break;

        case RET:

            float b, h;

            printf("digite a altura");
            scanf("%f",&h);
            printf("digite a base:");
            scanf("%f",&b);

            elemento = cria_ret(b,h);

        break;
    }
    if(lh == NULL){

        lh = elemento;
    }
    else{

        elemento->prox=lh;
        lh = elemento;
    }
    return lh;
}
void lh_mostrar(lista_het*l){

    for(lista_het *p = l; p!= NULL; p=p->prox){

        switch(p->geometria){

            case RET:
                retangulo*r = (retangulo*)p->info;
                printf("---RETANGULO---\n");
                printf("base: %f, altura: %f",r->b, r->h );
            break;

            case CIR:
                circulo*c = (circulo*)p->info;
                printf("---Circulo---\n");
                printf("raio: %f", c->r);
            break;

            case TRI:
                triangulo*t= (triangulo*)p->info;
                printf("---triangulo---");
                printf("base: %f, altura: %f\n", t->b, t->h);
            break;

            default:
                printf("tipo de dado inexistente\n");
                break;
        }
    }
}
float maior_area(lista_het*l){

    float maior_area = 0, area;
    lista_het *p=l;

    for(p=l;p!=NULL;p=p->prox){

        switch(p->geometria){

            case TRI:
                triangulo*t=(triangulo*)p->info;
                area = (t->b*t->h)/2.0;
            break;
            
            case CIR:
                circulo*c=(circulo*)p->info;
                area = c->r*c->r*3.14;
            break;
            
            case RET:
                retangulo*r=(retangulo*)p->info;
                area = (r->b*r->h);
            break;

            default:
                printf("tipo nao exite\n");
            break;
        }

        if(maior_area<area)
            maior_area = area;
    }
    return maior_area;
}

int lsthet_tamanho(lista_het *l){

    int cont = 0;

    for(lista_het *p = l; p != NULL; p = p->prox){
        cont++;
    }

    return cont;
}
void imprime_maiores_areas(lista_het *l, float limite){

    lista_het *p=l;
    float area;

    for(p=l;p!=NULL;p=p->prox){
        switch(p->geometria){

            case TRI:

                triangulo*t=(triangulo*)p->info;
                area = (t->b*t->h)/2.0;

                if(area>limite){

                    printf("---triangulo---\n");
                    printf("base: %f, altura: %f\n", t->b, t->h);

                }
            break;
            
            case CIR:

                circulo*c=(circulo*)p->info;
                area = c->r*c->r*3.14;

                if(area>limite){

                    printf("---Circulo---\n");
                    printf("raio: %f", c->r);
                }
            break;
            
            case RET:
                retangulo*r=(retangulo*)p->info;
                area = (r->b*r->h);

                if(area>limite){
                    printf("---retangulo---\n");
                    printf("base: %f, altura: %f\n", r->b,r->h);
                }
            break;

            default:
                printf("tipo nao exite\n");
            break;
        }
    }

}
float percentual_elementos_tipo(lista_het*l, Tipo geometria){

    int cont_elementos=0, cont_total=0;
    float percentual;

    if(l==NULL){
        printf("lista vazia\n");
        return 0;
    }

    for(lista_het *p = l; p!= NULL; p=p->prox){

        cont_total++;
        if(p->geometria == geometria){
            cont_elementos++;
        }
    }

    return (cont_elementos*100)/(float)cont_total;
}

lista_het *remove_tipo(lista_het *l, Tipo geometria){

    lista_het *percorrer=l;
    lista_het *ant = NULL;

    while(percorrer!=NULL){

        if(percorrer->geometria == geometria){

            lista_het*temp=percorrer;
            if(ant == NULL){

                l = percorrer->prox;
                percorrer = l;
            }
            else{
                ant->prox = percorrer->prox;
                percorrer=percorrer->prox;
            }
            free(temp->info);
            free(temp);
        }
        else{
            ant = percorrer;
            percorrer = percorrer->prox;
        }
    }
    return l;
}
float area_media_tipo(lista_het *l, Tipo geometria){

    if(l==NULL){
        printf("lista vazia...\n");
        return 0;
    }
    
    float soma_area=0,area;
    int i=0;

    for(lista_het*p=l;p!=NULL;p=p->prox){

        if(p->geometria == geometria){

            switch(geometria){

                case TRI: 
                    i++;
                    triangulo*t=(triangulo*)p->info;
                    area = (t->b*t->h)/2.0;
                    soma_area+=area;
                break;

                case RET:
                    i++;
                    retangulo*r=(retangulo*)p->info;
                    area = r->b*r->h;
                    soma_area+=area;
                    break;
            
                case CIR:
                    i++;
                    circulo*c=(circulo*)p->info;
                    area = c->r*c->r*3.14;
                    soma_area+=area;
                break;

                default:
                    printf("tipo invalido");
                break;
            }

        }
    }

        if(i==0){
            printf("nenhum elemento encontrado\n");
            return 0;
        }

    return soma_area/i;
}
