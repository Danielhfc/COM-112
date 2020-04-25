#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produtos{
    int codigo;
    float preco;
    char *descricao;
}produto;

void preencheDados(produto prod[],int i) // preenche o vetor com dados fornecidos pelo usuários.
{
  prod[i].descricao = (char *)malloc(sizeof(char)); //alocação dinamica
  printf("Digite o descricao do produto: ");
  scanf(" %[^\n]", prod[i].descricao);

  printf("Digite o preco do produto: ");
  scanf("%f", &prod[i].preco);  

  printf("Digite o codigo do produto: ");
  scanf("%d", &prod[i].codigo);  
  printf("\n");
  }

void insertionSortdescricao(produto prod[],int tam){ //Coloca o vetor em ordem alfabetica
  int marcador=1,maior,i,temp1,temp2,pos;
  char *string;
  
  string = (char *)malloc(sizeof(char));//alocação dinamica

 for(marcador = 1;marcador < tam;marcador++){ //marcador deve começar no 1
   pos = marcador-1;
   string = strcpy(string,prod[marcador].descricao); //alocar os valores para variaveis temporarias
   temp1 = prod[marcador].preco;
   temp2 = prod[marcador].codigo;

   while(pos >= 0 && strcmp(string,prod[pos].descricao) < 0 ){//Continua alterando posições enquanto a posição nao for negativa e o procximo nome seja menor
     prod[pos+1].descricao = strcpy(prod[pos+1].descricao,prod[pos].descricao);
     prod[pos+1].codigo = prod[pos].codigo;
     prod[pos+1].preco = prod[pos].preco;
     pos = pos-1;
   }
   prod[pos+1].descricao = strcpy(prod[pos+1].descricao,string);//Ultimo valor ordenado
   prod[pos+1].codigo = temp1;
   prod[pos+1].preco = temp2;
 }
}

int buscaSequencial(produto prod[], int tam, int cod){ // encontra a posição do valor dado no vetor.
  int i;
  for(i=0;i<tam;i++){
      if(cod == prod[i].codigo) //Quando a funcão encontrar o valor no vetor, o for é interrompido e retorna a quantidade de valores encontrados
        return i;
  }
  return i;
}

int main(void) {
    produto prod[10];
  int i,tam = 10, comparados,cod;

  for(i=0;i<tam;i++) preencheDados(prod,i);
  
  printf("Imprimindo os dados dos produtos:\n");
  for(i=0;i<tam;i++) printf("descricao = %s\npreco = %f\ncodigo = %d\n\n",prod[i].descricao,prod[i].preco,prod[i].codigo);   

  insertionSortdescricao(prod,tam);
  printf("Imprimindo os dados dos produtos em ordem alfabetica:\n");
  for(i=0;i<tam;i++) printf("descricao = %s\npreco = %f\ncodigo = %d\n\n",prod[i].descricao,prod[i].preco,prod[i].codigo); 

  printf("Digite o codigo do produto desejado: ");
  scanf("%d",&cod);
  comparados = buscaSequencial(prod,tam,cod);

  if(comparados < tam) //Se a quantidade de codigos comparados for maior que o vetor, o codigo nao esta no vetor
    printf("Foram comparados %d codigos ate encontrar o produto desejado\n",comparados+1);
  else
    printf("O valor chave nao esta no vetor");

  for(i=0;i<tam;i++) free(prod[i].descricao);
}