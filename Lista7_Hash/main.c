#include <stdio.h>
#include <stdlib.h>
#include "com112_hash.h"

void preencheAluno(struct aluno *al){//Preenche a struct com dados do aluno
  printf("Digite a matrícula do aluno: ");
  scanf("%d",&al->matricula);

  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]", al->nome);

  printf("Digite as notas N1 e N2 do aluno: ");
  scanf("%f %f", &al->n1, &al->n2);
}

int menu(){//Funcao para criar o menu
  int opcao;
  printf("\n-------------------MENU------------------\n");
  printf("|    1. Criar tabela hash               |\n");
  printf("|    2. Liberar tabela hash             |\n");
  printf("|    3. Inserir elemento (sem colisão)  |\n");
  printf("|    4. Consultar elemento (sem colisão)|\n");
  printf("|    5. Sair                            |\n");
  printf("-----------------------------------------\n");
  printf("Opcao:");
  scanf("%d", &opcao);
  return opcao;
}

int main(){
  Hash* ha=NULL;
  int opcao,x, tam,mat;
  struct aluno al;

  do
  {
    opcao = menu();
    switch(opcao)
    {
      case 1://Cria a Hash com o tamanho dado pelo usuario
        printf("Digite o tamanho da tabela:\n");
        scanf("%d", &tam);
        ha = criaHash(tam);
      break;

      case 2://Libera o Hash
        liberaHash(ha);
      break;

      case 3://Insere os dados da struct dada pelo usuario
        preencheAluno(&al);//preenche a struct

         x = insereHash_SemColisao(ha, al);//insere os dados
         if(x == 1)//Deu certo
          printf("\nValor inserido com sucesso!");
         else
          printf("\nErro ao inserir o valor");
      break;

      case 4: //Encontra na Hash pela matricula
        printf("Digite a matrícula do aluno que deseja encontrar: ");
        scanf("%d",&mat);

         x = buscaHash_SemColisao(ha,mat, &al);//busca na Hash
         if(x == 1)
          printf("\nMatricula:%d\nNome:%s\nN1:%.2f\nN2:%.2f\n",al.matricula,al.nome,al.n1,al.n2);//printa os dados do aluno procurado
         else
          printf("\nA matricula nao foi encontrada");
      break;

      case 5: //Ao sair, o Hash deve ser liberado
      liberaHash(ha);
        printf("\nSaindo...\n");
      break;

      default: //Caso o usuario digite o numero errado
        printf("Digite outro numero");
      break;
    }
  }while(opcao != 5);
}