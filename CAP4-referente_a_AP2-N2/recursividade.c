#include<stdio.h>
#include<stdlib.h>

int fatorial(int valor){

    if(valor < 0){
        printf("não existe fatorial de negativo");
        exit(1);
    }
    if(valor == 0){
       return  1;
    }
    else{
        valor *= fatorial(valor-1);
    }
    return valor;
}

int soma_ate_n(int n){

    if(n == 0)
        return 0;

    return n += soma_ate_n(n-1);
}

int elevado(int valor, int grau){

    if(grau == 0)
        return 1;

   return valor * elevado(valor,grau-1);
}

void cont_regressiva(int n){

    if(n == 0){

        printf("0");
        return ;
    }
    printf("%d", n);
    cont_regressiva(n-1);
    
}

int somavetor(int v[], int tamanho){
    if(tamanho == 0){
        return 0;
    }
    return v[tamanho-1] = somavetor(v, tamanho-1);
}