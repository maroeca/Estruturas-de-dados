//#include<stdio.h>
//#include<iostream>
//#include<conio.h>
//#define SIZE 3
//
//void enQueue(int);
//void deQueue();
//void display();
//
//int cQueue[SIZE], front = -1, rear = -1;
//
//int main()
//{
//	int choice, value;
//	//clrscr();
//	while (1) {
//		printf("\n****** MENU ******\n");
//		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
//		printf("Enter your choice: ");
//		scanf_s("%d", &choice);
//		switch (choice) {
//		case 1: printf("\nEnter the value to be insert:  ");
//			scanf_s("%d", &value);
//			enQueue(value);
//			break;
//		case 2: deQueue();
//			break;
//		case 3: display();
//			break;
//		case 4: return 0;
//		default: printf("\nPlease select the correct choice!!!\n");
//		}
//	}
//}
//void enQueue(int value)
//{
//	if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
//		printf("\nCircular Queue is Full! Insertion not possible!!!\n");
//	else {
//		if (rear == SIZE - 1 && front != 0)
//			rear = -1;
//		cQueue[++rear] = value;
//		printf("\nInsertion Success!!!\n");
//		if (front == -1)
//			front = 0;
//	}
//}
//void deQueue()
//{
//	if (front == -1 && rear == -1)
//		printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
//	else {
//		printf("\nDeleted element : %d\n", cQueue[front++]);
//		if (front == SIZE)
//			front = 0;
//		if (front - 1 == rear)
//			front = rear = -1;
//	}
//}
//void display()
//{
//	if (front == -1)
//		printf("\nCircular Queue is Empty!!!\n");
//	else {
//		int i = front;
//		printf("\nCircular Queue Elements are : \n");
//		if (front <= rear) {
//			while (i <= rear)
//				printf("%d\t", cQueue[i++]);
//		}
//		else {
//			while (i <= SIZE - 1)
//				printf("%d\t", cQueue[i++]);
//			i = 0;
//			while (i <= rear)
//				printf("%d\t", cQueue[i++]);
//		}
//	}
//}


#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;

#define TAMANHO 4 //"N"

//Struct da fila
struct fila {
	
	string elementos[TAMANHO]; //array dos elementos do tipo string
	int inicio; //controle de inicio da fila "p"
	int	fim; //controle do fim da fila "u"
};

int incluirNaFila(struct fila* f, string dado)
{
	if (f->fim + 1 == f->inicio || ((f->fim +1) % TAMANHO == f->inicio)) //testa se a fila não está cheia
	{
		std::cout << "Fila Cheia!!" << std::endl;
		return -1;
	}
	else
	{		
		f->elementos[f->fim] = dado; //coloca o dado desejado ao final da fila
		f->fim = (f->fim +1) % TAMANHO; // muda a posição do fim pra proxima posição
		std::cout << "Dado incluido!" << std::endl;
		if (f->inicio == -1)
			f->inicio = 0;
	}
}
//retira elementos da fila
int retiraDaFila(struct fila* f)
{
	if (f->fim == f->inicio) //testa o tamanho, se for 0 não há elementos
	{
		std::cout << "Fila Vazia ou todos slots utilizados!" << std::endl;
		return -1;
	}
	else
	{
		//*dado = f->elementos[f->inicio];  // coloca o dado numa variavel
		std::cout << "Elemento retirado: " << f->elementos[f->inicio] << std::endl << std::endl; //imprime o dado retirado
		f->inicio = (f->inicio + 1) % TAMANHO; // muda a posição do inicio
		return 0;
	}
}
//inicia os elementos da fila
void iniciaFila(struct fila *f)
{
	f->fim = 0;
	f->inicio = 0;
}
//imprime toda a fila
void imprimeFila(struct fila *f)
{
	int i = f->inicio; // recebe inicio da fila
	if (f->inicio <= f->fim) //
	{
		while (i <= f->fim)
			std::cout << f->elementos[i++] << std::endl;
	}
	else
	{
		while (i <= TAMANHO - 1)
			std::cout << f->elementos[i++] << std::endl;
		i = 0;
		while (i< f->fim)
		{
			std::cout << f->elementos[i++] << std::endl;
		}
	}
}

int main()
{
	struct fila *filaCont; //variavel da fila
	int opcao; //opcao do usuario
	string dado; //dados a serem adicionados na fila
	filaCont = new fila;

	iniciaFila(filaCont); //inicia a fila com 0

	std::cout << "--Fila Circular--" << std::endl << std::endl;

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
			std::cout << "Digite o dado que quer incluir: " << std::endl;
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