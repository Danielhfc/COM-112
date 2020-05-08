#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_file.h"

void bubble_sort(int vetor[], int n)
{
    clock_t t_ini, t_fim; //variaveis para ver o tempo de execução
    float tempo;
    int k, j, aux, comp=0, mov=0;

    t_ini = clock();
    for (k = n - 1; k > 0; k--)//percorre o vetor de traz pra frente
    {
        for (j = 0; j < k; j++)//percorre o elemento A[j] até A[k] 
        {
            comp++;//toda vez que houver comparação, a variável será incrementada
            if (vetor[j] > vetor[j + 1])//Caso o proximo numero seja menor que o atual, ambos devem trocar
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                mov += 2;//toda vez que houver movimentações, a variável será incrementada
            }
        }
    }
    t_fim = clock();
    tempo = (t_fim - t_ini)*1000/CLOCKS_PER_SEC;
    printf("Bubble Sort realizado com sucesso");
    //o tempo de execução será igual a diferença das variáveis.
    relatorioEscreve(n,tempo,comp,mov,1);//chama a função para escrever no arquivo do relatorio
    return;
}

void selection_Sort(int vet[],int n) 
{ 
    clock_t t_ini, t_fim;//variaveis para ver o tempo de execução
    float tempo;
    int minIndex,comp=0,mov=0;
    int aux;

    t_ini = clock();
    for (int i = 0; i < n-1; i++) 
    { 
        minIndex = i; 
        for (int j = i+1; j < n; j++)
        {
          comp++;
          if (vet[j] < vet[minIndex])
            minIndex = j;
        }
        // Troca
        aux = vet[i];
        vet[i] = vet[minIndex];
        vet[minIndex] = aux;
        mov+=2;        
    }
    t_fim = clock();
    tempo = (t_fim - t_ini)*1000/CLOCKS_PER_SEC;//calculo do tempo de execução
    relatorioEscreve(n,tempo,comp,mov,2);//chama a função para escrever no arquivo do relatorio
    printf("Selection Sort realizado com sucesso");
    return;
} 

void insertion_sort(int vetor[], int n)
{
    clock_t t_ini, t_fim; //variaveis para ver o tempo de execução
    float tempo;
    int k, j, aux,comp=0,mov=0;
    t_ini = clock();
    for (k = 1; k <= n - 1; k++)//percorre o vetor
    {
        aux = vetor[k];
        j = k - 1;
        comp++;//numero de comparações
        while (j >= 0 && aux < vetor[j])//compara o próximo vetor com o vetor na posição j
        {
            vetor[j + 1] = vetor[j];
            j--;
            mov++;//numero de movimentações
        }
        vetor[j + 1] = aux;
        mov++;//numero de movimentações
    }
    t_fim = clock();
    tempo = (t_fim - t_ini)*1000/CLOCKS_PER_SEC;//calculo do tempo de execução
    relatorioEscreve(n,tempo,comp,mov,3);//chama a função para escrever no arquivo do relatorio
    printf("Insertion Sort realizado com sucesso");
    return;
}
