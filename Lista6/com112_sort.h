#ifndef COM112_SORT_H
#define COM112_SORT_H

#endif

void bubble_sort(int vetor[], int n);
void selection_Sort(int vet[],int n);
void insertion_sort(int vetor[], int n);
void mergeSort(int *V,int inicio,int fim,int *comp,int *mov);
void merge(int *v, int inicio, int meio, int fim,int *comp,int *mov);
int particiona(int *v,int inicio,int final,int *comp,int *mov);
void quickSort(int *v,int inicio,int fim,int *comp,int *mov);