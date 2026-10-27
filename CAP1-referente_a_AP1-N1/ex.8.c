#include <stdio.h>
#include <stdlib.h>
//Multiplicação de matrizes
void desalocar(float **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; i++) {
        free(m[i]);
    }
    free(m);
}

float **multiplicar(float **mat1, int l1, int c1, float **mat2, int l2, int c2) {

    if (mat1 == NULL || mat2 == NULL || c1 != l2)
        return NULL;

    float **matmult = (float**) malloc(sizeof(float*) * l1);

    if (matmult == NULL)
        return NULL;

    for (int i = 0; i < l1; i++) {

        matmult[i] = (float*) malloc(sizeof(float) * c2);

        if (matmult[i] == NULL) {
            desalocar(matmult, i);
            return NULL;
        }
    }

   
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            
            matmult[i][j] = 0.0; 
            
            for (int k = 0; k < c1; k++) {
                matmult[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return matmult;
}