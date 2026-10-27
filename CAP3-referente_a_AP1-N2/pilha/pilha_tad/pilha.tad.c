#include<stdio.h>
#include<stdlib.h>
#include "pilha.tad.h"
#include<string.h>

pilha *cria(){

    pilha *p = (pilha*)malloc(sizeof(pilha));
    if(!p)
        exit(1);
    
    p->topo = NULL;

    return p;
}
void liberar_pilha(pilha *p){

    lista*aux;
    while(p->topo!=NULL){
        aux=p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
}
void imprime_pilha(pilha *p){
    
    printf("sua pilha:\n");

    for(lista *l = p->topo; l!= NULL; l = l->prox)
        printf("%s\n", l->link);
}
void push_pilha(pilha *p, char *link){

    lista *info = (lista*)malloc(sizeof(lista));

    if(!info)
        exit(1);

    strcpy(info->link, link);

    info->prox = p->topo;
    p->topo = info;
}
char *pop_pilha(pilha *p){

    if(p->topo == NULL)
        exit(2);

    lista*guardar = p->topo;

    char *v = malloc(strlen(guardar->link)+1) ;
    if(!v)
        exit(1);

    strcpy(v,guardar->link);
    p->topo=guardar->prox;

    free(guardar);

    return v;
}
void chorme_pilha(pilha *atual, pilha *voltar){

    int op;
    char *link;
    char buffer[100];
    do{
        printf("--MENU--\n");
        printf("(1) para enserir nova aba, (2) voltar aba, (3) avancar aba e (0) sair\n");
        printf("--digite a opção:--");
        scanf("%d", &op);

        switch(op){
            case 1:

                printf("ensira a url:\n ");
                scanf("%99s", buffer);

                push_pilha(atual, buffer);
                liberar_pilha(voltar);

            break;

            case 2:

                link = pop_pilha(atual);

                push_pilha(voltar, link);
                free(link);
                link = NULL;

            break;

            case 3:
                link = pop_pilha(voltar);

                push_pilha(atual, link);
                free(link);
                link = NULL;

            break;

            default:
                printf("digite uma op valida:\n");
            break;
        }
    }while(op!=0);
}
int cont_pilha(pilha *p){
    
    if(p->topo == NULL)
        return 0;

    int i = 0;

    for(lista *perco = p->topo; perco!=NULL; perco = perco->prox, i++);

    return i;
}
int pilha_contem(pilha *p, char *info){
    
    for(lista *l = p->topo; l!=NULL; l = l->prox){

        if(strcmp(l->link,info)==0)
            return 1;
    }
    return 0;
}
void pilha_removetodos(pilha *p, const char *info){

    pilha *aux=cria();

    char *link=NULL;

        while(p->topo!=NULL){

           link = pop_pilha(p);
            if(strcmp(link,info)!=0)
                push_pilha(aux,link);

            free(link);

        }

        while(aux->topo!=NULL){

            link = pop_pilha(aux);
            push_pilha(p,link);

            free(link);
        }
        free(aux);
}
pilha *clone_pilha(pilha *p){

    pilha *aux = cria();
    pilha *clone = cria();
    char *link = NULL;

    for(lista *l = p->topo; l!=NULL; l=l->prox)
        push_pilha(aux,l->link);

    while(aux->topo!=NULL){

        link = pop_pilha(aux);
        push_pilha(clone,link);
        free(link);
    }
    free(aux);

    return clone;
}
void pilha_inverte(pilha *p){

    pilha* inverte = cria();
    char *link = NULL;
    while(p->topo!=NULL){

        link = pop_pilha(p);
        push_pilha(inverte,link);
        free(link);
    }
    p->topo = inverte->topo;
    free(inverte);
}
void pilha_concatena(pilha *p1, pilha *p2){

    pilha *aux = cria();
    char *link = NULL;
    
    while(p2->topo!=NULL){
        link = pop_pilha(p2);
        push_pilha(aux,link);
        free(link);
    }
    while(aux->topo != NULL){
        link= pop_pilha(aux);
        push_pilha(p1,link);
        free(link);
    }
    free(aux);
}

