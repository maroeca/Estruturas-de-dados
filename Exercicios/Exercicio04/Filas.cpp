#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;

#define MAX 3

//Struct da fila
 struct fila{
	int contEntrada; //controla o tamanho do vetor na entrada de elementos
	int contSaida; //controle de saida de elemntos
	string elementos[MAX]; //array dos elementos do tipo string
	int inicio; //controle de inicio da fila
	int	fim; //controle do fim da fila
	
};

 //adiciona elementos na fila
int incluirNaFila(struct fila* f, string dado)
{
	if (f->contEntrada == MAX) //testa se a fila não está cheia
	{
		std::cout << "Fila Cheia!!" << std::endl;
		return -1;
	}
	else
	{
		f->elementos[f->fim] = dado; //coloca o dado desejado ao final da fila
		f->fim = (f->fim + 1) % MAX; // muda a posição do fim pra proxima posição
		f->contEntrada++; // adiciona 1 ao tamanho
		f->contSaida = f->contEntrada; //saida recebe entrada para fazer o controle na retirada
		std::cout << "Dado incluido!" << std::endl;
	}
}
//retira elementos da fila
int retiraDaFila(struct fila* f)
{
	if (f->contSaida == 0) //testa o tamanho, se for 0 não há elementos
	{
		std::cout << "Fila Vazia ou todos slots utilizados!" << std::endl;
		return -1;
	}
	else
	{
		//*dado = f->elementos[f->inicio];  // coloca o dado numa variavel
		std::cout << "Elemento retirado: "<< f->elementos[f->inicio] << std::endl << std::endl; //imprime o dado retirado
		f->inicio = (f->inicio + 1) % MAX; // muda a posição do inicio
		f->contSaida--; // controle de saida para saber se fila está vazia
		return 0;
	}
}
//inicia os elementos da fila
void iniciaFila(struct fila *f)
{
	f->fim = 0;
	f->inicio = 0;
	f->contEntrada = 0;
	f->contSaida = 0;
	//std::cout << "Fila inicializada!" << std::endl;
}
//imprime toda a fila
void imprimeFila(struct fila *f)
{
	for (int i = 0; i < f->contEntrada; i++)
	{
		std::cout << f->elementos[i] << std::endl;
	}
}

int main()
{	
	struct fila *filaCont; //variavel da fila
	int opcao; //opcao do usuario
	string dado; //dados a serem adicionados na fila
	filaCont = new fila; 

	iniciaFila(filaCont); //inicia a fila com 0

	std::cout << " \t\t\t\t\t\t--Fila linear-- " << std::endl << std::endl;

	do {		
		std::cout << "Escolha uma opcao: " << std::endl;
		std::cout << "1 - Incluir na fila" << std::endl;
		std::cout << "2 - Remover da fila" << std::endl;
		std::cout << "3 - Imprimir elementos da fila" << std::endl;
		std::cout << "0 - Sair" << std::endl;

		std::cin >> opcao; //lê opccao do usuario

		system("CLS"); //limpa a tela

		switch (opcao) //faz o switch das opcoes
		{
		case 1:
			std::cout << "Digite o nome que quer incluir? " << std::endl;
			std::cin >> dado; //le o dado a ser incluido
			incluirNaFila(filaCont, dado); 
			
			break;
		case 2:
			retiraDaFila(filaCont); //retira o primeiro elemento da fila
			break;
		case 3:
			imprimeFila(filaCont);
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