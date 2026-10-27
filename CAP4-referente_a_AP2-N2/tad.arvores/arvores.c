#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

arv *cria_vazia(){
    return NULL;
}

arv *cria(int info, arv*esq, arv*dir){

    arv* a = (arv*)malloc(sizeof(arv));
    a->info = info;
    a->sad = dir;
    a->sae = esq;

    return a;
}
void mostrar(arv *a){

    if(a == NULL)
        return;

    mostrar(a->sae);
    printf(a->info);
    mostrar(a->sad);
}

arv *deleta(arv *a){

    if(a!= NULL){

        deleta(a->sae);
        deleta(a->sad);
        free(a);
    }
    return NULL;
}

int pertence(arv *a, int valor){

    if(a == NULL)
        return 0;
    
    else if(a->info == valor)
        return 1;

    else if(valor < a->info)
        return pertence(a->sae, valor);

    else
        return pertence(a->sad,valor);
}

int altura(arv *a){

    if(a == NULL)
        return 0;
    int ales = altura(a->sae);
    int aldi = altura(a->sad);

    if(ales > aldi)
        return 1+ales;
    else 
        return 1+aldi;
}

int conta_nos(arv *a){

    if(a == NULL){
        return 0;
    }
    return 1 + conta_nos(a->sae) + conta_nos(a->sad); 
}

int conta_folhas(arv *a){

    if(a == NULL){
        return 0;
    }
    if(a->sad == NULL && a->sae == NULL)
        return 1;
    
    return conta_folhas(a->sad) + conta_folhas(a->sae);
}
void imprime_pre(arv *a){

    if(a == NULL)
        return;

    printf("%d\n", a->info);
    imprime_pre(a->sae);
    imprime_pre(a->sad);
}

void imprime_pos(arv *a){

    if(a == NULL)
        return;

    imprime_pos(a->sae);
    imprime_pos(a->sad);
    printf("%d\n", a->info);
}

int soma_valores(arv *a){

    if(a == NULL)
        return 0;

    return a->info + soma_valores(a->sae)+soma_valores(a->sad);
}

arv *copia(arv*a){

    if(a==NULL)
        return NULL;

    arv *clone = (arv*)malloc(sizeof(arv));
    clone ->info = a->info;
    clone ->sae = copia(a->sae);
    clone ->sad = copia(a->sad);

    return clone;
}

float media(arv *a){

    if(a == NULL)
        return 0;

    return soma_valores(a)/(float)conta_nos(a);
}

int cont_impares(arv*a){

    if(a == NULL)
        return 0;

    if(a->info % 2 != 0)
        return 1 + cont_impares(a->sae)+ cont_impares(a->sad);

    return cont_impares(a->sae) + cont_impares(a->sad);
}

int arvores_iguais(arv *a, arv *b){

    if(a == NULL && b == NULL)
        return 1;

    if(b == NULL || a == NULL)
        return 0;

    if(a->info != b->info)
        return 0;

    return arvores_iguais(a->sad,b->sad) && arvores_iguais(a->sae,b->sae);
}

int menor(arv *a){

    if(a == NULL)
        printf("vazia");
        return -1;

    if(a->sae == NULL)
        return a->info;

    return menor(a->sae);
}

int maior(arv *a){

    if(a == NULL){
        printf("arvore vazia");
        exit(1);
    }

    if(a->sad == NULL)
        return a->info;

    return maior(a->sad);
}

int cheia(arv *a){

    if(a == NULL)
        return 1;

    if(a->sad == NULL && a->sae == NULL)
        return 1;

    if(a->sad != NULL && a->sae != NULL)
        return cheia(a->sad) && cheia(a->sae);

    return 0;
}

int conta_no_interno(arv *a){

    if(a == NULL)
        return 0;

    if(a->sad == NULL && a->sae == NULL)
        return 0;

    return 1 + conta_no_interno(a->sad) + conta_no_interno(a->sae);
}

arv *ensere(arv *a, int valor){

    if(a == NULL){

        arv *novo = (arv*)malloc(sizeof(arv));

        if(novo == NULL)
            exit(1);

        novo->info = valor;
        novo->sae = NULL;
        novo->sad = NULL;

        return novo;
    }

    if(valor > a->info)
        a->sad = ensere(a->sad, valor);
    else if(valor < a->info)
        a->sae = ensere(a->sae, valor);

    return a;
}
