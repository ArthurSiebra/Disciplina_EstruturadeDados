#ifndef __tad_het_h__
#define __tad_het_h__

typedef enum tipo{RET,TRI,CIR} Tipo;

typedef struct Lista_het{

    Tipo geometria;
    void *info;
    struct Lista_het *prox;

}lista_het;

typedef struct Circulo{

    float r;

}circulo;

typedef struct Triangulo{

    float b;
    float h;

}triangulo;

typedef struct retangulo{
    
    float b;
    float h;

}retangulo;

lista_het *cria_tri(float b, float h);
lista_het *cria_cir(float r);
lista_het *cria_ret(float b, float h);
lista_het *ensere(lista_het*lh, Tipo geometria);
void lh_mostrar(lista_het*l);
float maior_area(lista_het*l);
int lsthet_tamanho(lista_het *l);
void imprime_maiores_areas(lista_het *l, float limite);
float percentual_elementos_tipo(lista_het*l, Tipo geometria);
lista_het *remove_tipo(lista_het *l, Tipo geometria);
float area_media_tipo(lista_het *l, Tipo geometria);

#endif