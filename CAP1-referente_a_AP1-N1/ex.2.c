#include <stdio.h>
#include <stdlib.h>

void desalocar(int **m, int n);

//Alocando uma matriz dinâmicamente
int main(){
  int n;
  scanf ("%d", &n);

  int **mat = (int**)malloc(n * sizeof(int*));
  
  //Primeira vez usando verificação, deixa o código seguro.
  if(!mat){
    printf("erro de alocação");
    exit(1);
  }

  for (int i = 0; i < n; i++)
  {
      mat[i] = (int*)malloc(n * sizeof(int));

      if (!mat[i])
      {

        printf("erro de alocacao");
        desalocar(mat, i);
        return 1;

      }
  }

  desalocar(mat,n);

  return 0;
}

//Desalocando uma matriz
void desalocar(int **m, int n){

  if(!m)
    return;

  for(int i=0; i<n; i++)
    free(m[i]);

  free(m);
}