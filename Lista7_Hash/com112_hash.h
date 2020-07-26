#ifndef COM112_SORT_H
#define COM112_SORT_H


struct aluno {
  int matricula;
  char nome[30];
  float n1, n2;
};

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int chaveDivisao(int chave, int TABLE_SIZE);
int insereHash_SemColisao(Hash* ha, struct aluno al);
int buscaHash_SemColisao(Hash* ha,int mat, struct aluno* al);

#endif