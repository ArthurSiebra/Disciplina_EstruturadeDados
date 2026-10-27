#include <stdio.h>
#include <stdlib.h>

float *exmenemaior(float *v, int n) {
    if (v == NULL || n <= 2)
        return NULL;

    float *v2 = (float*) malloc(sizeof(float) * (n - 2));
    if (v2 == NULL)
        return NULL;

    float maior = v[0];
    float menor = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] > maior)
            maior = v[i];
        if (v[i] < menor)
            menor = v[i];
    }

    int k = 0;
    int tirou_menor = 0;
    int tirou_maior = 0;

    for (int i = 0; i < n; i++) {
        //Ignora a primeira ocorrencia do menor elemento
        if (v[i] == menor && !tirou_menor) {
            tirou_menor = 1;
            continue;
        }
        //Ignora a primeira ocorrencia do maior elemento
        if (v[i] == maior && !tirou_maior) {
            tirou_maior = 1;
            continue;
        }

        v2[k] = v[i];
        k++;
    }

    return v2;
}