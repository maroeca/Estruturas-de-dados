#include <iostream>
#include <string>
#include "Competidor.h"
#include "Registro.h"

#define TAM 3

	
int main()
{
	Competidor* cadastros[TAM];
	//int capacidade = 0;
	Registro reg;
	bool flag = true;
	char confirm;
	int opcao;

	for (int i = 0; i < TAM; i++)
	{
		cadastros[i] = new Competidor();
	}

	do
	{
		std::cout << "\n Registro de Competidores" << std::endl;
		std::cout << "\n> Digite a opcao que deseja: " << std::endl
			<< "1 - Adicionar cadastro" << std::endl
			<< "2 - Pesquisar cadastro" << std::endl
			<< "3 - Listar todos os competidores" << std::endl
			<< "4 - Excluir um competidor" << std::endl
			<< "5 - Atualizar pontuacao" << std::endl
			<<  "> ";

		std::cin >> opcao;
		system("CLS");

		switch (opcao)
		{
		case 1:
			if (reg.GetCapacidade() < TAM)
				reg.AddCompetidor(cadastros);
			else
				std::cout << "Nao eh possivel criar mais cadastros" << std::endl;
			break;

		case 2:
			if (reg.GetCapacidade() > 0)
				reg.SearchCompetitor(cadastros);
			else
				std::cout << "Nao ha cadastros para pesquisar" << std::endl;
			break;

		case 3:
			if (reg.GetCapacidade() > 0)
				reg.ListCompetitors(cadastros);
			else
				std::cout << "Nao ha cadastros para listar" << std::endl;
			break;

		case 4:
			if (reg.GetCapacidade() > 0)
				reg.DeleteCompetitor(cadastros);
			else
				std::cout << "Nao ha cadastros para deletar" << std::endl;
			break;

		case 5:
			if (reg.GetCapacidade() > 0)
				reg.AddScore(cadastros);
			else
				std::cout << "Nao ha cadastros para adicionar score" << std::endl;
			break;

		default:
			std::cout << "Opcao invalida" << std::endl;
			break;
		}

		std::cout << "\nDeseja realizar outra tarefa? Digite y/n" << std::endl
			<< "> ";
		std::cin >> confirm;  

		if (confirm == 'n')
			flag = false;
	} while (flag);

	system("Pause");
	return 0;
}

