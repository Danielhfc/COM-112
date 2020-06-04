#include <stdio.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

void bubble_sort(int vetor[], int n, int *comp, int *mov)
{
    int i,k, aux;
  *comp = 0;
  *mov = 0;
  for(k=1;k <=n;k++){
    for(i=0;i<=n-2;i++){
      (*comp)++;
      if(vetor[i] > vetor[i+1]){
        (*mov)++;
        aux = vetor[i];
        vetor[i] = vetor[i+1];
        vetor[i+1] = aux;
      }
    }
  }
    printf("Bubble Sort realizado com sucesso");
    return;
}

void selection_Sort(int vet[],int n, int *comp, int *mov) 
{ 
    int minIndex;
    int aux;
    *comp = 0;
    *mov = 0;
    for (int i = 0; i < n-1; i++) 
    { 
        minIndex = i; 
        for (int j = i+1; j < n; j++)
        {
          (*comp)++;
          if (vet[j] < vet[minIndex])
            minIndex = j;
        }
        // Troca
        aux = vet[i];
        vet[i] = vet[minIndex];
        vet[minIndex] = aux;
        *mov = *mov + 2;        
    }
    printf("Selection Sort realizado com sucesso");
    return;
} 

void insertion_sort(int vetor[], int n, int *comp, int *mov)
{
    int k, j, aux;
    *comp = 0;
    *mov = 0;
    for (k = 1; k <= n - 1; k++)//percorre o vetor
    {
        aux = vetor[k];
        j = k - 1;
        (*comp)++;//numero de comparações
        while (j >= 0 && aux < vetor[j])//compara o próximo vetor com o vetor na posição j
        {
            (*comp)++;
            vetor[j + 1] = vetor[j];
            j--;
            (*mov)++;//numero de movimentações
        }
        vetor[j + 1] = aux;
        (*mov) += 2;//numero de movimentações
    }
    printf("Insertion Sort realizado com sucesso");
    return;
}

void merge(int *v, int inicio, int meio, int fim,int *comp,int (*mov),int tamanho)
{
    int poslivre, p1, p2, i;
    int aux[10000];
    p1=inicio;
    p2=meio+1;
    poslivre = inicio;

   while(p1 <= meio && p2 <= fim){
     (*comp)++;
     if(v[p1] <= v[p2]){
       aux[poslivre] = v[p1];
       p1++;
     }

     else{
      aux[poslivre] = v[p2];
      p2++;
     }
     poslivre = poslivre+1;
     }

    for(i = p1;i<=meio;i++){
      aux[poslivre] = v[i];
      poslivre++;
    }

    for(i = p2;i<=fim;i++){
      aux[poslivre] = v[i];
      poslivre++;
    }

    for(i = inicio;i<=fim;i++){
      v[i] = aux[i];
      (*mov)++;
    }
    return;
}

void mergeSort(int *V,int inicio,int fim,int *comp,int *mov,int tamanho)
{
  int meio;
  if(inicio<fim){
    meio =(inicio+fim)/2;
    mergeSort(V,inicio,meio,comp,mov,tamanho);
    mergeSort(V,meio+1,fim,comp,mov,tamanho);
    merge(V,inicio,meio,fim,comp,mov,tamanho);
  }
  return;
}

void troca(int *x,int i,int j){
  int aux;
  aux = x[i];
  x[i] = x[j];
  x[j] = aux;
  return;
}

int particiona(int *x,int p, int r,int *comp,int *mov){
  int pivo,i,j;
  pivo = x[(p+r)/2];
  i = p-1;
  j = r+1;
  while(i<j){
    do{
      (*comp)++;
      j = j-1;
    }while(x[j]>pivo);
    do{
      (*comp)++;
      i = i+1;
    } while(x[i]<pivo);
    if(i<j){
       troca(x,i,j);
       (*mov)++;
    }
  }
  return j;
}

void quickSort(int *x,int p,int r,int *comp,int *mov){
int q;
if(p < r){
  q = particiona(x, p, r, comp, mov);
  quickSort(x, p,q,comp,mov);
  quickSort(x, q+1,r,comp,mov);
}
}
