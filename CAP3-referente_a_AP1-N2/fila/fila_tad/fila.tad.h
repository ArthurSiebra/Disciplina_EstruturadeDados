#ifndef __fila_tad_h__
#define __fila_tad_h__

typedef struct list_p{

    int prioridade;

    char nome[50];

    struct list_p *prox;

}List_p;

typedef struct fila_p{

    List_p *fim;
    List_p *ini;

}Fila_p;

int fila_vazia(Fila_p* f);
Fila_p* fila_cria();
void fila_enqueue(Fila_p* f, int prioridade, char* nome);
List_p* fila_dequeue(Fila_p* f);
void fila_free(Fila_p* f);
void fila_imprime(Fila_p* f);
int tamanhofila(Fila_p *f);
List_p *busca(Fila_p *f, char *nome);
void Fila_remove(Fila_p *f, char *nome);
float fila_media_prioridade(Fila_p *f);
int maiorprioridade(Fila_p *f);
void fila_filtra_prioridade(Fila_p *f, int prioridade);
Fila_p *fila_clone(Fila_p *f);
Fila_p *fila_inverte(Fila_p *f);
Fila_p *mescla(Fila_p *f1, Fila_p *f2);
Fila_p *fila_merge(Fila_p *f1, Fila_p *f2);
void inverte(Fila_p *f);

#endif