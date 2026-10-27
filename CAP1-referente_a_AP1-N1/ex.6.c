#include <stdio.h>
#include <stdlib.h>

void desalocar(float **m, int l) {
    if (m == NULL) return;
    for (int i = 0; i < l; i++) {
        free(m[i]);
    }
    free(m);
}

// Retorna um vetor com os elementos (excluindo maior e menor)
// O tamanho do novo vetor é gravado na variavel apontada por 'novo_tamanho'
float *maioremenor(float **mat, int l, int c, int *novo_tamanho) {
    if (mat == NULL || l <= 0 || c <= 0) {
        *novo_tamanho = 0;
        return NULL;
    }

    float maior = mat[0][0];
    float menor = mat[0][0];

    // 1. Encontra maior e menor valores
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] > maior) maior = mat[i][j];
            if (mat[i][j] < menor) menor = mat[i][j];
        }
    }

    // 2. Conta quantos elementos são diferentes do maior e do menor
    int qtd = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != maior && mat[i][j] != menor) {
                qtd++;
            }
        }
    }

    *novo_tamanho = qtd;

    if (qtd == 0) return NULL; // Todos os elementos eram iguais ao maior ou menor

    // 3. Aloca um vetor apenas com o tamanho exato dos elementos restantes
    float *vetor_resultado = (float*) malloc(sizeof(float) * qtd);
    if (vetor_resultado == NULL) return NULL;

    // 4. Preenche o vetor
    int k = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != maior && mat[i][j] != menor) {
                vetor_resultado[k] = mat[i][j];
                k++;
            }
        }
    }

    return vetor_resultado;
}