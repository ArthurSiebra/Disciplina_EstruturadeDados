#include <stdio.h>
#include <stdlib.h>

//Alocando Vetor

//Se eu tivese feito na função só *x eu estaria apenas criando uma cópia do poteiro mas eu tenho que alterar, ou seja tenho que usar **x já que fazemos o ponteiro apontar para o ponteirio x.

void alocar(float **x, int n)
{
    *x=(float*)malloc(n*(sizeof(float)));
   //Faz o endereço de x reservar um espaço de memória do tipo float(4bytes) pra ele a depender da resposta do usuário como um ventor porém não estático mas dinâmico.
        for (int i = 0; i < n; i++)
        {
            printf("digite qualquer valor numro: %d\n", i+1 );
            scanf("%f",&(*x)[i]);
            //Mesma coisa que *(*x+i).
            //Atribui o conteúdo.
        }
}
int main()
{
    int n;
    printf("digite o tamanho desse vetor dinamico:\n");
    scanf("%d",&n);
    if(n>0)
    {
       float *v;
       alocar(&v,n);
        for (int i = 0; i < n; i++)
        {
            printf("%f\n",v[i]);
        }
     free(v);
     //Free vai servir para liberar o espaço da memória.
    }
    return 0;
}