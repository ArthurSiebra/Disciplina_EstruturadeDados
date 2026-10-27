#include<stdio.h>
//Struct faz você criar uma nova estrutura, é como criar um novo tipo. Usaremos futuramente para criar estruturas bastante usadas  para a estruturização dos dados.
struct pessoa
{
  int idade;
  float peso, altura;
  char cor[15];
};
typedef struct pessoa pessoa;

int main()
{
    int tam;
    printf("digite a quantidade de pessoas\n");

    scanf("%d",&tam);
    pessoa jogador[tam];
    for (int i = 0; i < tam; i++)
    {
        printf("Digite a altura, peso , idade e cor respectivamente do jogador %d\n", i+1);
        scanf("%f", &jogador[i].altura);
        scanf("%f", &jogador[i].peso);
        scanf("%d", &jogador[i].idade);
        scanf("%s", &jogador[i].cor);
    }
    
    return 0;

}