#include<stdio.h>
#include<stdlib.h>

void desalocar(float **m, int l);
float **somar(float **mat1, float **mat2, int l, int c);

float **somar(float **mat1, float **mat2, int l, int c){

    if (mat1 == NULL || mat2 == NULL)
        return NULL;

    float **matsoma = (float**)malloc(sizeof(float*)*l);

    if(matsoma == NULL)
        return NULL;

    for (int i = 0; i < l; i++){

        matsoma[i] = (float*)malloc(sizeof(float)*c);

        if (matsoma[i] == NULL){
            desalocar(matsoma, i);
            return NULL;
        }
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matsoma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return matsoma;
}

void desalocar(float **m, int l){

    if(m == NULL)
        return;

    for(int i = 0; i < l; i++)
        free(m[i]);

    free(m);
}