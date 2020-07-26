#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "file.h"
#include "sort.h"

int menu()
{
    int opcao;
    printf("\n-------------------MENU-------------------\n");
    printf("|           1. Bubble Sort               |\n");
    printf("|           2. Selection Sort            |\n");
    printf("|           3. Insertion Sort            |\n");
    printf("|           4. Merge Sort                |\n");
    printf("|           5. Quick Sort                |\n");
    printf("|           6. Relatorio                 |\n");
    printf("|           7. Sair                      |\n");
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
else if((c=fgetc(arq)) == EOF )
{
  printf("Arquivo vazio");
  return 1;
}
rewind(arq);
while((fgets(s,50,arq)) != NULL){
printf("\n%s\n", s);
}
fclose(arq);
return 0;
}


int relatorioTodos(int tam,int tipo)
{
char s[50],c;
FILE *arq;
if(tipo == 0)
  arq = fopen("com112_relatorio_aleatorio.txt","r");

else if(tipo == 1)
  arq = fopen("com112_relatorio_crescente.txt","r");

  else
  arq = fopen("com112_relatorio_decrescente.txt","r");

if(arq == NULL)
    {
      printf("\nErro, nao foi possivel ler o arquivo\n");
      return 1;
    }
else if((c=fgetc(arq)) == EOF )
{
  printf("Arquivo vazio");
  return 1;
}
rewind(arq);
while((fgets(s,50,arq)) != NULL){ 
printf("\n%s\n", s);
}
fclose(arq);
return 0;
}

void copiaVetor(int vetn[],int vet[], int tam){
  int i;
  for(i=0;i<tam;i++)
  {
    vetn[i] = vet[i];
  }
  return;
}


int main()
{
  int *v,*v1,*aleatorio,*crescente,*decrescente,*aleatorio2,*crescente2,*decrescente2, tam, opcao,comp=0,mov=0,escolha,i,k;
    
  float tempo;

  clock_t t_ini,t_fim;

  printf("Digite a quantidade de numeros da sua sequencia:");
  scanf("%d", &tam); 

do{
printf("\n-------------------ORDEM-------------------\n");
printf("|           1. Aleatorio                    |\n");
printf("|           2. Crescente                    |\n");
printf("|           3. Decrescente                  |\n");
printf("-------------------------------------------\n");
  printf("Escolha: ");
scanf("%d", &escolha);
if(escolha!=1 && escolha!=2 && escolha!=3)
printf("Opcão inválida!\n");
}while(escolha!=1 && escolha!=2 && escolha!=3);


  v = (int*) malloc(tam*sizeof(int)); 
  v1 = (int*) malloc(tam*sizeof(int));
  aleatorio = (int*) malloc(tam*sizeof(int));
  aleatorio2 = (int*) malloc(tam*sizeof(int));
  crescente = (int*) malloc(tam*sizeof(int));
  crescente2 = (int*) malloc(tam*sizeof(int));
  decrescente = (int*) malloc(tam*sizeof(int));
  decrescente2 = (int*) malloc(tam*sizeof(int));
  entrada(v,tam,escolha); 
  for(i = 0;i < tam; i++)
    aleatorio[i] = rand() % 10000;

  for(i = 0;i < tam; i++)
    crescente[i] = i;

  for(i = tam-1,k=0;i >= 0; i--,k++)
    decrescente[k] = i;

 
  do{
  opcao = menu();
  switch(opcao)
  {
    case 1: 
      copiaVetor(v1, v, tam);
      t_ini = clock();
      bubble_sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);
      relatorioEscreve(tam, tempo,comp,mov,1);
      saida(v1,tam); 
      break;
    case 2:
      copiaVetor(v1, v, tam);
      t_ini = clock();
      selection_Sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);
      relatorioEscreve(tam, tempo,comp,mov,2);
      saida(v1,tam); 
      break;
    case 3:
      copiaVetor(v1, v, tam);
      t_ini = clock();
       insertion_sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);
      relatorioEscreve(tam, tempo,comp,mov,3);
      saida(v1,tam);
      break;
    case 4:
        comp = 0;
        mov = 0;
      copiaVetor(v1, v, tam); 
      t_ini = clock();
      mergeSort(v1,0,tam-1,&comp,&mov,tam);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000.00);
      relatorioEscreve(tam, tempo,comp,mov,4);
      saida(v1,tam);
    break;
    case 5: 
    comp = 0;
    mov = 0;
      copiaVetor(v1, v, tam); 
      t_ini = clock();
      quickSort(v1,0,tam-1,&comp,&mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);
      relatorioEscreve(tam, tempo,comp,mov,5);
      saida(v1,tam); 
      break;
    case 6: 
      relatorio(tam);
    break;

    case 7: 
          printf("\nSaindo...\n");
      free(v);
      free(v1);
    break;
    default: 
      printf("Numero invalido");
      break;
  } 
}while(opcao!=7);
return 0;
}