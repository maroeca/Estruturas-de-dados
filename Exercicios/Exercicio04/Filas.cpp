#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 14

//Struct da fila
 struct fila{
	int tamanho;
	char fila[MAX];
	int inicio, fim;
	//fila *prox;
};
//Struct com ptr que indicam o inicio e fim da fila
//typedef struct {
//	fila *inicio;
//	fila *fim;
//}fila_enca;

 //adiciona elementos na fila
int incluirNaFila(struct fila* f, char dado)
{
	if (f->tamanho == MAX) //testa se a fila não está cheia
	{
		std::cout << "Fila Cheia!!" << std::endl;
		return -1;
	}
	else
	{
		f->fila[f->fim] = dado; //coloca o dado desejado ao final da fila
		f->fim = (f->fim + 1) % MAX; // muda a posição do fim pra proxima posição
		f->tamanho++; // adiciona 1 ao tamanho
	}
}
//retira elementos da fila
int retiraDaFila(struct fila* f, char dado)
{
	if (f->tamanho == 0) //testa o tamanho, se for 0 não há elementos
	{
		std::cout << "Fila Vazia!!" << std::endl;
		return -1;
	}
	else
	{
		dado = f->fila[f->inicio];  // não entendi isso e tirei, não faz sentido
		std::cout << dado << std::endl << std::endl; //imprime o dado
		f->inicio = (f->inicio + 1) % MAX; // muda a posição do inicio
		f->tamanho--; // retira 1 do tamanho
		return 0;
	}
}
//inicia os elementos da fila
void iniciaFila(struct fila *f)
{
	f->fim = 0;
	f->inicio = 0;
	f->tamanho = 0;
}

int main()
{
	struct fila *filaCont;
	int opcao;
	char dado;

	iniciaFila(filaCont);

	do {
		switch (opcao)
		{
		case 1:
			std::cout << "Digite o nome que quer incluir? " << std::endl;
			std::
			incluirNaFila(filaCont, dado);
		default:
			break;
		}

	} while (opcao != 0);


	system("PAUSE");
	return 0;
}