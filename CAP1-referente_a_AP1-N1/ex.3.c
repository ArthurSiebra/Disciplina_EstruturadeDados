#include <stdio.h>
#include <stdlib.h>

float **transposta(float **mat, int l, int c);
void desalocar(float **m, int linhas);

int main() {
    int linhas, colunas;

    if (scanf("%d %d", &linhas, &colunas) != 2 || linhas <= 0 || colunas <= 0) {
        printf("Dimensoes invalidas.\n");
        return 1;
    }

    //Aloca matriz original (linhas x colunas)
    float **matriz = (float**) malloc(sizeof(float*) * linhas);
    if (matriz == NULL) return 1;

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (float*) malloc(sizeof(float) * colunas);
        if (matriz[i] == NULL) {
            desalocar(matriz, i); //Libera apenas as linhas alocadas ate aqui
            return 1;
        }
    }

    //Leitura dos elementos
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("digite o elemento(%d)(%d): ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    //Calculo da transposta
    float **mat2 = transposta(matriz, linhas, colunas);

    if (mat2 == NULL) {
        printf("Erro ao alocar a matriz transposta.\n");
        desalocar(matriz, linhas);
        return 1;
    }

    //Impressao da matriz transposta (colunas x linhas)
    printf("\nMatriz Transposta:\n");
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%.2f ", mat2[i][j]);
        }
        printf("\n");
    }

    //Desalocacao segura de ambas as matrizes
    desalocar(matriz, linhas);
    desalocar(mat2, colunas);

    return 0;
}

//Função para calcular a matriz transposta (retorna NULL se falhar)
float **transposta(float **mat, int l, int c) {
    if (mat == NULL) return NULL;

    //A transposta tera 'c' linhas e 'l' colunas
    float **mat_trans = (float**) malloc(sizeof(float*) * c);
    if (mat_trans == NULL) return NULL;

    for (int i = 0; i < c; i++) {
        mat_trans[i] = (float*) malloc(sizeof(float) * l);
        if (mat_trans[i] == NULL) {
            desalocar(mat_trans, i); //Limpa o que ja foi alocado em mat_trans
            return NULL;
        }
    }

    // Atribuicao dos valores trocando linhas por colunas
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            mat_trans[j][i] = mat[i][j];
        }
    }

    return mat_trans;
}

//Função auxiliar para desalocar matrizes dinâmicas com seguranca
void desalocar(float **m, int linhas) {
    if (m == NULL) return;

    for (int i = 0; i < linhas; i++) {
        free(m[i]);
    }
    free(m);
}