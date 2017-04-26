#include <iostream>
#include <vector>

using std::vector;

vector<int>filaEnc;

void incluirNaFila(int dado)
{
	filaEnc.push_back(dado); //adiciona um dado na ultima posição
}

void retiraDaFila()
{
	if (filaEnc.empty()) //verifica se a fila está vazia
	{
		std::cout << "Fila vazia" << std::endl;
	}
	else
	{
		std::cout <<"Elemento retirado: "<< filaEnc[0] << std::endl; //imprime o primeiro elemento da fila
		filaEnc.erase(filaEnc.begin()); //remove o elemento da fila
	}		
}

void imprimeFila()
{
	if (filaEnc.empty())
	{
		std::cout << "Fila vazia!" << std::endl;
	}
	else
	{
		for (int i = 0; i < filaEnc.size(); i++)
		{
			std::cout << filaEnc[i] << std::endl; //imprime os elementos da fila
		}
	}
}

int main()
{
	struct fila *filaCont; //variavel da fila
	int opcao; //opcao do usuario
	int dado; //dados a serem adicionados na fila

	std::cout << "--Fila Encadeada--" << std::endl << std::endl;

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
			incluirNaFila(dado);

			break;
		case 2:
			retiraDaFila(); //retira o primeiro elemento da fila
			break;
		case 3:
			imprimeFila();
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