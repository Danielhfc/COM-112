#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_file.h"
#include "com112_sort.h"

int menu()// menu para o usuario
{
    int opcao;
    printf("\n-------------------MENU-------------------\n");
    printf("|           1. Bubble Sort               |\n");
    printf("|           2. Selection Sort            |\n");
    printf("|           3. Insertion Sort            |\n");
    printf("|           4. Relatorio                 |\n");
    printf("|           5. Sair                      |\n");
    printf("------------------------------------------\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int relatorio(int tam)
{
char s[50],c;
FILE *arq;
arq = fopen("com112_relatorio.txt","r");
if(arq == NULL)
    {
      printf("\nErro, nao foi possivel ler o arquivo\n");
      return 1;
    }
else if((c=fgetc(arq)) == EOF )//Caso o arquivo esteja vazio
{
  printf("Arquivo vazio");
  return 1;
}
while((fgets(s,50,arq)) != NULL){ //Ler o arquivo linha por linha e imprime na tela
printf("\n%s\n", s);
}
fclose(arq);
return 0;
}

void copiaVetor(int vetn[],int vet[], int tam){//faz a cópia do vetor v para o vetor vn
  int i;
  for(i=0;i<tam;i++)
  {
    vetn[i] = vet[i];
  }
  return;
}

int main()
{
  int *v,*v1, tam, opcao;
  printf("Digite a quantidade de numeros da sua sequencia:");
  scanf("%d", &tam); //tamanho do vetor
  v = (int*) malloc(tam*sizeof(int)); //Alocações dinamicas
  v1 = (int*) malloc(tam*sizeof(int));
  entrada(v,tam); // chama a função para criar o arquivo de entrada
 
 
  do{
  opcao = menu();
  switch(opcao)//Opções para o usuário
  {
    case 1: //bubble sort
      copiaVetor(v1, v, tam);//copia o vetor para evitar perder o vetor com os numeros desorganizados.
      bubble_sort(v1,tam);
      saida(v1,tam); //chama a função para criar o arquivo de saida
      break;
    case 2:
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      selection_Sort(v1, tam);
      saida(v1,tam); //chama a função para criar o arquivo de saida
      break;
    case 3:
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      insertion_sort(v1,tam);
      saida(v1,tam); //chama a função para criar o arquivo de saida
      break;
    case 4:
      relatorio(tam); //imprime o relatorio
      break;
    case 5: // Sair do programa
      printf("\nSaindo...\n");
      free(v);
      free(v1);
    break;
    default: 
      printf("Numero invalido");
  } 
}while(opcao!=5);
return 0;
}