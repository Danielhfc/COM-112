#include<stdio.h>
#include<stdlib.h>

#include "com112_file.h"

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

void entrada(int *v,int tam,int escolha){
    int i,k=0;
    if(escolha == 1)
    {
       for(i = 0;i < tam; i++){
        v[i] = rand() % 10000;
       }// preenche o vetor com dados aleatorios
      
    }
    else if(escolha == 2){
        for(i = 0;i < tam; i++)
        {
        v[i] = i;
        }
    }
    
    else
      { 
      for(i = tam-1;i >= 0; i--,k++){
        v[k] = i;
      }
    }
    //Cria os arquivos do relatorio e da entrada
    FILE *arq;
    FILE *rel;
    FILE *rt;
    arq = fopen("com112_entrada.txt", "w+");
    rel = fopen("com112_relatorio.txt","w");
    rt = fopen("com112_relatorioTodos.txt", "w");
    
    if(arq == NULL && rel == NULL && rt == NULL)
    {
      printf("\nErro, nao foi possivel criar o arquivo\n");
      return;
    }
    else
    printf("\nArquivo criado com sucesso\n");

    fprintf(rel, "Numero de elementos ordenados: %d\n",tam);
    fprintf(arq,"%d\n",tam); // A primeira linha deve conter a quantidade de numeros
    fprintf(rt, "%d\n", tam);

    for(i = 0;i < tam; i++)// preenche o arquivo com dados do vetor.
      fprintf(arq,"%d ",v[i]);
  
    fclose(arq);
    fclose(rel);
    fclose(rt);
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
    case 4: fprintf(arq, "Metodo Merge Sort\n"); break;
    case 5: fprintf(arq, "Metodo Quick Sort\n"); break;
    default: break;
  }
  if(arq == NULL)
  {
    printf("\nArquivo nao existe\n");
  }
   else
    {
      fprintf(arq, "Tempo de Execusao: %f ms\n", tempo);
      fprintf(arq, "Comparaçôes: %d\n", comp);
      fprintf(arq, "Movimentações: %d\n", mov);
      fprintf(arq, "----------------------------------\n");
    }
  fclose(arq);
  return;
}

void relatorioEscreveTodos(int n,float tempo,int comp,int mov,int sort)//escreve no relatórioTodos.txt
{
  FILE *arq;
  arq = fopen("com112_relatorioTodos.txt", "a+");
  switch(sort)
  {
    case 1: fprintf(arq, "Metodo Bubble Sort\n"); break;
    case 2: fprintf(arq, "Metodo Selection Sort\n"); break;
    case 3: fprintf(arq, "Metodo Insertion Sort\n"); break;
    case 4: fprintf(arq, "Metodo Merge Sort\n"); break;
    case 5: fprintf(arq, "Metodo Quick Sort\n"); break;
    default: break;
  }
  if(arq == NULL)
  {
    printf("\nArquivo nao existe\n");
  }
   else
    {
      fprintf(arq, "Tempo de Execusao: %f ms\n", tempo);
      fprintf(arq, "Comparaçôes: %d\n", comp);
      fprintf(arq, "Movimentações: %d\n", mov);
      fprintf(arq, "----------------------------------\n");
    }
  fclose(arq);
  return;
}