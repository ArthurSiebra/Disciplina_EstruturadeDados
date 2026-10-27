#include <stdio.h>
#include <stdlib.h>

void desalocar(float **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; i++) {
        free(m[i]);
    }
    free(m);
}

float **somarcrescente(float **mat1, float **mat2, int a, int b) {
    if (mat1 == NULL || mat2 == NULL) return NULL;

    float **matsomcres = (float**) malloc(sizeof(float*) * a);
    if (matsomcres == NULL) return NULL;

    for (int i = 0; i < a; i++) {
      
        matsomcres[i] = (float*) malloc(sizeof(float) * b);
        if (matsomcres[i] == NULL) {
            desalocar(matsomcres, i);
            return NULL;
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            matsomcres[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
//Ordenação em ordem crescente Bubble Sort
    int total = a * b;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            //Mapeamento do elemento atual
            int li1 = j / b;
            int co1 = j % b;

            //Mapeamento do próximo elemento
            int li2 = (j + 1) / b;
            int co2 = (j + 1) % b;

            //Troca os elementos de posição se estiverem fora de ordem
            if (matsomcres[li1][co1] > matsomcres[li2][co2]) {
                float temp = matsomcres[li1][co1];
                matsomcres[li1][co1] = matsomcres[li2][co2];
                matsomcres[li2][co2] = temp;
            }
        }
    }

    return matsomcres;
}