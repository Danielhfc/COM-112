#ifndef COM112_FILE_H
#define COM112_FILE_H

void saida(int *v, int tam);//cria e salva os dados no com112_saida.txt
void entrada(int *v,int tam,int escolha); //cria e insere os dados no arquivo com112_entrada.txt com112_relatorio.txt 
void relatorioEscreve(int n,float tempo,int comp,int mov,int sort);//escreve no relatório.txt
void relatorioEscreveTodos(int n,float tempo,int comp,int mov,int sort);//escreve no relatórioTodos.txt

#endif
