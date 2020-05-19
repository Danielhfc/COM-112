#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_file.h"
#include "com112_sort.h"

void saida(int *v, int tam){
  FILE *sai;
  //Cria o arquivo de saida
  sai = fopen("com112_saida.txt", "w+");
  
  if(sai == NULL)
    {
      printf("\nErro, nao foi possivel criar o arquivo\n");
      return;
    }
    else{
      fprintf(sai,"%d\n",tam); // A primeira linha deve conter a quantidade de numeros
      for(int i = 0;i < tam; i++)// preenche o arquivo com dados do vetor.
        fprintf(sai,"%d ",v[i]);
      printf("\ncom112_saida.txt atualizado");
    }   
fclose(sai);
return;
}

void entrada(int *v,int tam){
    int i;
    for(i = 0;i < tam; i++)// preenche o vetor com dados aleatorios
      v[i] = rand() % 100;

    //Cria os arquivos do relatorio e da entrada
    FILE *arq;
    FILE *rel;
    arq = fopen("com112_entrada.txt", "w+");
    rel = fopen("com112_relatorio.txt","w");
    
    if(arq == NULL && rel == NULL)
    {
      printf("\nErro, nao foi possivel criar o arquivo\n");
      return;
    }
    else
    printf("\nArquivo criado com sucesso\n");

    fprintf(rel, "Numero de elementos ordenados: %d\n",tam);
    fprintf(arq,"%d\n",tam); // A primeira linha deve conter a quantidade de numeros
    for(i = 0;i < tam; i++)// preenche o arquivo com dados do vetor.
      fprintf(arq,"%d ",v[i]);

    fclose(arq);
    fclose(rel);
    printf("Dados inseridos com sucesso");
  return;
}

void relatorioEscreve(int n,float tempo,int comp,int mov,int sort)//escreve no relatório.txt
{
  FILE *arq;
  arq = fopen("com112_relatorio.txt", "a+");
  switch(sort)
  {
    case 1: fprintf(arq, "Metodo Bubble Sort\n"); break;
    case 2: fprintf(arq, "Metodo Selection Sort\n"); break;
    case 3: fprintf(arq, "Metodo Insertion Sort\n"); break;
    default: break;
  }
  if(arq == NULL)
  {
    printf("\nArquivo nao existe\n");
  }
   else
    {
      fprintf(arq, "Tempo de Execusao: %.3f/ms\n", tempo);
      fprintf(arq, "Comparacoes: %d\n", comp);
      fprintf(arq, "Movimentacoes: %d\n", mov);
      fprintf(arq, "----------------------------------\n");
    }
  fclose(arq);
  return;
}