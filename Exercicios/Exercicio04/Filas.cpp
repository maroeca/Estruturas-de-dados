#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 14

//Struct da fila
 struct fila{
	int tamanho;
	char dado;
	int inicio, fim;
	//fila *prox;

};
//Struct com ptr que indicam o inicio e fim da fila
//typedef struct {
//	fila *inicio;
//	fila *fim;
//}fila_enca;

int incluirNaFila(struct fila* f, char dado)
{
	if (f->tamanho == MAX)
	{
		std::cout << "Fila Cheia!!" << std::endl;
	}
}

int main()
{


	system("PAUSE");
	return 0;
}