#include <stdio.h>
#include <stdlib.h>

void preencheVetor( int vet[],int tam) // preenche o vetor com dados fornecidos pelo usuários.
{
  int i;
  for(i=0;i<tam;i++){
    printf("Digite um valor para o vetor: \n");
    scanf("%d", &vet[i]);
  }
  
}

void bubleSort(int vet[],int tam){
  int i,j, aux, troca;

  for(i = 0;i < tam;i++){
    troca = 0;
    for(j = 0;j < tam-1; j++)
      if(vet[j] < vet[j+1]){ //Caso o valor em j+1 seja maior que o valor em j, estes valores trocarão de posição
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
        troca = 1;
      }
      if(troca == 0) return; //Evitar repetições quando ja estiver ordenado
  }
  
}

int main(void) {
  int *vet,n,i,tam = 10;
  vet = (int*)malloc(tam*sizeof(int));

  preencheVetor(vet,tam);
  
  printf("Imprimindo o vetor:\n ");
  for(i=0;i<tam;i++) printf("%d ",vet[i]);

  bubleSort(vet,tam);
  printf("\nImprimindo o vetor ordenado: \n");
  for(i=0;i<tam;i++) printf("%d ",vet[i]);

  free(vet);
}