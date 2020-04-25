#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    float sal;
    char *nome;
}funcionario;

void preencheDados(funcionario fun[],int i) // preenche o vetor com dados fornecidos pelo usuários.
{
  fun[i].nome = (char *)malloc(sizeof(char)); //alocação dinamica
  printf("Digite o nome do funcionario: ");
  scanf(" %[^\n]", fun[i].nome);

  printf("Digite o salario do funcionario: ");
  scanf("%f", &fun[i].sal);  
  printf("\n");
  }

void selectionSortSal(funcionario fun[],int tam){ //Coloca o vetor em ordem decrescente de salário
  int marcador,maior,i,temp,troca;
  char *string;
  
  string = (char *)malloc(sizeof(char)); //alocação dinamica

  for(i = 0;i < tam-1;i++){
      marcador = 0;
      troca = 0;
  while(marcador < tam-1){ 
      maior = i+1; //primeiro elemento dos desordenados
      if(fun[maior].sal > fun[marcador].sal){ //Troca de lugar o maior numero do vetor com o primeiro elemento desordenado
          temp = fun[marcador].sal;
          fun[marcador].sal = fun[maior].sal;
          fun[maior].sal = temp;      

          string = strcpy(string,fun[marcador].nome);//troca os nomes de posição para igualar ao salario 
          fun[marcador].nome = strcpy(fun[marcador].nome,fun[maior].nome);
          fun[maior].nome = strcpy(fun[maior].nome,string); 
          troca = 1;
      }
  marcador++; 
  
  }
if (troca == 0) return; //Evitar repetições quando ja estiver ordenado
}
}
void selectionSortNome(funcionario fun[],int tam){ //Coloca o vetor em ordem alfabetica
  int marcador,maior,i,temp,troca;
  char *string;
  
  string = (char *)malloc(sizeof(char));//alocação dinamica

  for(i = 0;i < tam-1;i++){
      marcador = 0; 
      troca = 0;
  while(marcador < tam-1){
      maior = i+1; //primeiro elemento dos desordenados
      if(strcmp(fun[marcador].nome,fun[maior].nome) > 0){ //Esta comparação sera verdade quando o 1 elemento for menor alfabeticamente
          temp = fun[marcador].sal;  //Troca de lugar o nome com o primeiro elemento desordenado 
          fun[marcador].sal = fun[maior].sal;
          fun[maior].sal = temp;      

          string = strcpy(string,fun[marcador].nome);//Troca de lugar o salario para igualar ao nome
          fun[marcador].nome = strcpy(fun[marcador].nome,fun[maior].nome);
          fun[maior].nome = strcpy(fun[maior].nome,string); 
          troca = 1;
      }
  marcador++;
  }
 if(troca == 0) return; //Evitar repetições quando ja estiver ordenado
}
}

int main(void) {
    funcionario fun[10];
  int i,tam = 10;

  for(i=0;i<tam;i++) preencheDados(fun,i);
  
  printf("Imprimindo os dados dos funcionarios:\n");
  for(i=0;i<tam;i++) printf("Nome = %s\nSalario = %f\n\n",fun[i].nome,fun[i].sal);  

  selectionSortSal(fun,tam);
  printf("Imprimindo os dados dos funcionarios com salario em ordem decrescente:\n");
  for(i=0;i<tam;i++) printf("Nome = %s\nSalario = %f\n\n",fun[i].nome,fun[i].sal);  

  selectionSortNome(fun,tam);
  printf("Imprimindo os dados dos funcionarios com nome em ordem alfabetica:\n");
  for(i=0;i<tam;i++) printf("Nome = %s\nSalario = %f\n\n",fun[i].nome,fun[i].sal);  

  for(i=0;i<tam;i++) free(fun[i].nome);
}