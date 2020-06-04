#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "com112_file.h"
#include "com112_sort.h"


int menu();
int relatorio(int tam);
int relatorioTodos(int tam);
void copiaVetor(int vetn[],int vet[], int tam);

int main()
{
  int *v,*v1, tam, opcao,comp=0,mov=0,escolha;
  clock_t t_ini, t_fim;
  float tempo;

  printf("Digite a quantidade de numeros da sua sequencia:");
  scanf("%d", &tam); //tamanho do vetor

do{
printf("\n-------------------ORDEM-------------------\n");
printf("|           1. Aleatorio                    |\n");
printf("|           2. Crescente                    |\n");
printf("|           3. Decrescente                |\n");
printf("-------------------------------------------\n");
  printf("Escolha: ");
scanf("%d", &escolha);
if(escolha!=1 && escolha!=2 && escolha!=3)
printf("Opcão inválida!\n");
}while(escolha!=1 && escolha!=2 && escolha!=3);


  v = (int*) malloc(tam*sizeof(int)); //Alocações dinamicas
  v1 = (int*) malloc(tam*sizeof(int));
  entrada(v,tam,escolha); // chama a função para criar o arquivo de entrada
 
  do{
  opcao = menu();
  switch(opcao)//Opções para o usuário
  {
    case 1: //bubble sort
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
      bubble_sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreve(tam, tempo,comp,mov,1);
      saida(v1,tam); //chama a função para criar o arquivo de saida
      break;
    case 2:
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
      selection_Sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreve(tam, tempo,comp,mov,2);
      saida(v1,tam); //chama a função para criar o arquivo de saida
      break;
    case 3:
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
       insertion_sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreve(tam, tempo,comp,mov,3);
      saida(v1,tam); //chama a função para criar o arquivo de saida
      break;
    case 4:
        comp = 0;
        mov = 0;
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
      mergeSort(v1,0,tam-1,&comp,&mov,tam);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000.00);//calculo do tempo de execução
      relatorioEscreve(tam, tempo,comp,mov,4);
      saida(v1,tam); //chama a função para criar o arquivo de saida
    break;
    case 5: //Quick Sort
    comp = 0;
    mov = 0;
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
      quickSort(v1,0,tam-1,&comp,&mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreve(tam, tempo,comp,mov,5);
      saida(v1,tam); //chama a função para criar o arquivo de saida
      break;
    case 6: 
      relatorio(tam);
    break;
    case 7:
    //Bubble_sort
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
      bubble_sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreveTodos(tam, tempo,comp,mov,1);
      saida(v1,tam); //chama a função para criar o arquivo de saida
    
    //Selection_sort
       copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
      selection_Sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreveTodos(tam, tempo,comp,mov,2);
      saida(v1,tam); //chama a função para criar o arquivo de saida

    //Insertion_sort
    copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
       insertion_sort(v1, tam, &comp, &mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreveTodos(tam, tempo,comp,mov,3);
      saida(v1,tam); //chama a função para criar o arquivo de saida

      //Merge_sort
      comp = 0;
        mov = 0;
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
      mergeSort(v1,0,tam,&comp,&mov,tam);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreveTodos(tam, tempo,comp,mov,4);
      saida(v1,tam); //chama a função para criar o arquivo de saida

      //Quick_sort
      comp = 0;
    mov = 0;
      copiaVetor(v1, v, tam); //copia o vetor para evitar perder o vetor com os numeros desorganizados.
      t_ini = clock();
      quickSort(v1,0,tam-1,&comp,&mov);
      t_fim = clock();
      tempo = (t_fim - t_ini)/(CLOCKS_PER_SEC/1000);//calculo do tempo de execução
      relatorioEscreveTodos(tam, tempo,comp,mov,5);
      saida(v1,tam); //chama a função para criar o arquivo de saida

      relatorioTodos(tam); //imprime o relatorio de todos
      break;
    case 8: 
          printf("\nSaindo...\n");
      free(v);
      free(v1);
    break;
    default: 
      printf("Numero invalido");
      break;
  } 
}while(opcao!=8);
return 0;
}

int menu()// menu para o usuario
{
    int opcao;
    printf("\n-------------------MENU-------------------\n");
    printf("|           1. Bubble Sort               |\n");
    printf("|           2. Selection Sort            |\n");
    printf("|           3. Insertion Sort            |\n");
    printf("|           4. Merge Sort                |\n");
    printf("|           5. Quick Sort                |\n");
    printf("|           6. Relatorio                 |\n");
    printf("|           7. Relatorio Todos           |\n");
    printf("|           8. Sair                      |\n");
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
rewind(arq);
while((fgets(s,50,arq)) != NULL){ //Ler o arquivo linha por linha e imprime na tela
printf("\n%s\n", s);
}
fclose(arq);
return 0;
}

int relatorioTodos(int tam)
{
char s[50],c;
FILE *arq;
arq = fopen("com112_relatorioTodos.txt","r");
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
rewind(arq);
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
