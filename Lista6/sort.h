#ifndef _SORT_H
#define _SORT_H

void bubble_sort(int vetor[], int n, int *comp, int *mov);
void selection_Sort(int vet[],int n, int *comp, int *mov);
void insertion_sort(int vetor[], int n, int *comp, int *mov);
void merge(int *v, int inicio, int meio, int fim,int *comp,int (*mov),int tamanho);
void mergeSort(int *V,int inicio,int fim,int *comp,int *mov,int tamanho);
void troca(int *x,int i,int j);
int particiona(int *x,int p, int r,int *comp,int *mov);
void quickSort(int *x,int p,int r,int *comp,int *mov);

#endif