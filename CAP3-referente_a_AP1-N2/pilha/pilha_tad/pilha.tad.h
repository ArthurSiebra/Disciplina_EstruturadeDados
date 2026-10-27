#ifndef _pilha_tad_h__
#define __pilha_tad_h__

typedef struct Lista{

    char link[100];
    struct Lista *prox;

}lista;

typedef struct Pilha{

    lista *topo;
    
}pilha;

pilha *cria();
void liberar_pilha(pilha *p);
void imprime_pilha(pilha *p);
void push_pilha(pilha *p, char *link);
char *pop_pilha(pilha *p);
void chorme_pilha(pilha *atual, pilha *voltar);
int cont_pilha(pilha *p);
int pilha_contem(pilha *p, char *info);
void pilha_removetodos(pilha *p, const char *info);
pilha *clone_pilha(pilha *p);
void pilha_inverte(pilha *p);
void pilha_concatena(pilha *p1, pilha *p2);

#endif

