#ifndef COM_112SORT_H
#define COM_112SORT_H

void bubble_sort(int vetor[], int n, int *comp, int *mov);//método de ordenação bubble sort
void selection_Sort(int vet[],int n, int *comp, int *mov);//método de ordenação selection sort
void insertion_sort(int vetor[], int n, int *comp, int *mov);//método de ordenação insertion sort
void merge(int *v, int inicio, int meio, int fim,int *comp,int (*mov),int tamanho);//Metodo merge do merge sort
void mergeSort(int *V,int inicio,int fim,int *comp,int *mov,int tamanho);//Metodo merde sort
void troca(int *x,int i,int j);//Prepara vetor Quick
int particiona(int *x,int p, int r,int *comp,int *mov);//particiona o vetor
void quickSort(int *x,int p,int r,int *comp,int *mov);//método de ordenação quick sort


#endif
