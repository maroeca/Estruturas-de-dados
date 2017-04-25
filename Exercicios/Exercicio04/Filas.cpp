#include <iostream>
#include <string>
//#include <stdio.h>
#include <stdlib.h>


#define MAX 3
//Struct da fila
 struct fila{
	int tamanho;
	char elementos[MAX];
	int inicio;
	int	fim;
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
		f->elementos[f->fim] = dado; //coloca o dado desejado ao final da fila
		f->fim = (f->fim + 1) % MAX; // muda a posição do fim pra proxima posição
		f->tamanho++; // adiciona 1 ao tamanho
		std::cout << "Dado incluido!" << std::endl;
	}
	/*return 0;*/
}
//retira elementos da fila
int retiraDaFila(struct fila* f, char *dado)
{
	if (f->tamanho == 0) //testa o tamanho, se for 0 não há elementos
	{
		std::cout << "Fila Vazia!!" << std::endl;
		return -1;
	}
	else
	{
		//*dado = f->elementos[f->inicio];  // não entendi isso e tirei, não faz sentido
		std::cout << "Elemento retirado: "<< f->elementos[f->inicio] << std::endl << std::endl; //imprime o dado
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
	std::cout << "Fila inicializada!" << std::endl;
}

int main()
{
	
	struct fila *filaCont;
	int opcao;
	char dado;
	filaCont = new fila;
	//opcao = 3;

	iniciaFila(filaCont);
	
	do {		
		std::cout << " --Fila linear-- " << std::endl;
		std::cout << "Escolha uma opcao: " << std::endl;
		std::cout << "1 - Incluir na fila" << std::endl;
		std::cout << "2 - Remover da fila" << std::endl;
		std::cout << "0 - Sair" << std::endl;

		std::cin >> opcao;

		system("CLS");

		switch (opcao)
		{
		case 1:
			std::cout << "Digite o nome que quer incluir? " << std::endl;
			std::cin >> dado;
			incluirNaFila(filaCont, dado);
			
			break;
		case 2:
			/*std::cout << "Elemento retirado: ";*/
			retiraDaFila(filaCont, &dado);
			break;
		case 0:
			std::cout << "Programa finalizado!" << std::endl;
			return 0;
			break;
		default:
			break;
		}

	} while (opcao != 0);


	system("PAUSE");
	return 0;
}