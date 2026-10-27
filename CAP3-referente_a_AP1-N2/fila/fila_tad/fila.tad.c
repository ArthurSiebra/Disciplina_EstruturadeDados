#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fila.tad.h"

int fila_vazia(Fila_p* f){
    return f->ini == NULL;
}

Fila_p* fila_cria(){

    Fila_p* queue = (Fila_p*)malloc(sizeof(Fila_p));

    if(queue == NULL)
        exit(1);

    queue->ini = NULL;
    queue->fim = NULL;

    return queue;
}

void fila_enqueue(Fila_p* f, int prioridade, char* nome){

    List_p* elemento = (List_p*)malloc(sizeof(List_p));

    if(elemento == NULL)
        exit(1);

    elemento->prioridade = prioridade;

    strcpy(elemento->nome, nome);

    elemento->prox = NULL;

    if(fila_vazia(f)){
        f->ini = elemento;
        f->fim = elemento;
    }
    else{
        f->fim->prox = elemento;
        f->fim = elemento;
    }
}

List_p* fila_dequeue(Fila_p* f){

    if(fila_vazia(f))
        return NULL;

    List_p* p = f->ini;
    List_p* maior_prioridade = p;

    while(p != NULL){

        if(p->prioridade > maior_prioridade->prioridade)
            maior_prioridade = p;

        p = p->prox;
    }

    p = f->ini;
    List_p* ant = NULL;

    while(p != maior_prioridade){
        ant = p;
        p = p->prox;
    }

    if(ant == NULL){
        f->ini = p->prox;
    }
    else{
        ant->prox = p->prox;
    }

    if(p == f->fim){
        f->fim = ant;
    }

    p->prox = NULL;

    return p;
}

void fila_free(Fila_p* f){

    List_p* aux;
    List_p* p = f->ini;

    while(p != NULL){

        aux = p;
        p = p->prox;

        free(aux);
    }

    free(f);
}

void fila_imprime(Fila_p* f){

    printf("\n### FILA DO BANCO ###\n");

    for(List_p* p = f->ini; p != NULL; p = p->prox){

        printf("Prioridade: %d - Nome: %s\n",p->prioridade,p->nome);
    }
}

int tamanhofila(Fila_p *f){

    int cont = 0;
    for(List_p *p = f->ini; p!=NULL; p = p->prox, cont++);

    return cont;
}

List_p *busca(Fila_p *f, char *nome){

    
    for(List_p *percorrer = f->ini; percorrer != NULL; percorrer = percorrer->prox){

        if(strcmp(nome,percorrer->nome)==0){
            return percorrer;
        }
    }

    printf("O nome não foi achado...\n");
    return NULL;
}

void Fila_remove(Fila_p *f, char *nome){
    
    List_p *anterior=NULL;
    List_p *percorrer=f->ini;

    while(percorrer!=NULL){
        
        if(strcmp(percorrer->nome,nome)==0){
            List_p *temp = percorrer;

            if(anterior == NULL){
                f->ini = percorrer->prox;
            }
            else{
                anterior->prox = percorrer->prox;
            }

            if(temp == f->fim){
                f->fim = anterior;
            }

            percorrer = percorrer->prox;
            free(temp);
        }
        else{
            anterior = percorrer;
            percorrer = percorrer->prox;
        }
    }
}

float fila_media_prioridade(Fila_p *f){

    if(f->ini == NULL)
        return 0;

    int somaprioridade=0;
    int i=0;

    for(List_p *percorrer = f->ini;percorrer!= NULL; percorrer=percorrer->prox,i++)
        somaprioridade+=percorrer->prioridade;
    
    return somaprioridade/(float)i;
}

int maiorprioridade(Fila_p *f){

    if(f->ini == NULL){
        printf("sua fila estar vazia");
        exit(1);
    }

    List_p *percorre = f->ini;
    List_p *maior = f->ini;

    for(percorre = f->ini; percorre!= NULL; percorre = percorre->prox){

        if(percorre->prioridade > maior->prioridade){
            maior = percorre;
        }
    }

    return maior->prioridade;
}

void fila_filtra_prioridade(Fila_p *f, int prioridade){

    if(f->ini == NULL){
        printf("sua fila esta vazia\n");
        return;
    }
    for(List_p *p =f->ini; p!= NULL; p= p->prox){

        if(p->prioridade >= prioridade){
            printf("nome: %s, prioridade: %d\n", p->nome, p->prioridade);
        }
    }
}

Fila_p *fila_clone(Fila_p *f){

    List_p *percorrer = f->ini;
    Fila_p *filacopia = fila_cria();

    for(percorrer = f->ini; percorrer!= NULL; percorrer= percorrer->prox){

        fila_enqueue(filacopia,percorrer->prioridade,percorrer->nome);

    }
    return filacopia;
}

Fila_p *fila_inverte(Fila_p *f){
    
    Fila_p *invertida = fila_cria();
    for(List_p *p = f->ini; p!= NULL; p= p->prox){

        List_p *aux = (List_p*)malloc(sizeof(List_p));
        if(!aux)
            exit(2);

        strcpy(aux->nome,p->nome);
        aux->prioridade = p->prioridade;

        aux->prox = invertida->ini;
        invertida->ini = aux;

        if(invertida->fim == NULL){
            invertida->fim = aux;
        }
    }
    return invertida;
}

Fila_p *mescla(Fila_p *f1, Fila_p *f2){

    if(f1->ini == NULL){
        free(f1);
        return f2;
    }
    if(f2->ini == NULL){
        free(f2);
        return f1;
    }

    f1->fim->prox = f2->ini;
    f1->fim = f2->fim;

    free(f2);
    return f1;
}

Fila_p *fila_merge(Fila_p *f1, Fila_p *f2){

    if(f1->ini == NULL && f2->ini == NULL){
        printf("Suas filas estao vazias\n");
        exit(1);
    }
    if(f1->ini == NULL){
        free(f1);
        return f2;
    }
    if(f2->ini == NULL){
        free(f2);
        return f1;
    }

    f1->fim->prox = f2->ini;
    f1->fim = f2->fim;

    free(f2);
    return f1;
}
void inverte(Fila_p *f){

    List_p *percorrer = f->ini;
    List_p *ant =NULL;
    List_p *prox = NULL;

    f->fim = f->ini;
    
    while(percorrer != NULL){

        prox = percorrer->prox;
        percorrer->prox = ant;
        ant = percorrer;
        percorrer = prox;
    }

    f->ini = ant;
}