#ifndef __arvores_h__
#define __arvores_h__

typedef struct no{

    int info;
    struct no *sae;
    struct no *sad;

}arv;

arv *cria_vazia();
arv *cria(int info, arv*esq, arv*dir);
void mostrar(arv *a);
arv *deleta(arv *a);
int pertence(arv *a, int valor);
int altura(arv *a);
int conta_nos(arv *a);
int conta_folhas(arv *a);
void imprime_pre(arv *a);
void imprime_pos(arv *a);
int soma_valores(arv *a);
arv *copia(arv*a);
float media(arv *a);
int cont_impares(arv*a);
int arvores_iguais(arv *a, arv *b);
int menor(arv *a);
int maior(arv *a);
int cheia(arv *a);
int conta_no_interno(arv *a);
arv *ensere(arv *a, int valor);

#endif