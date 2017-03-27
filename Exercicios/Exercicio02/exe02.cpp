#include <iostream>
#include <string>
#include "Competidor.h"
#include "Registro.h"


	
int main()
{
	Competidor* cadastros[10];
	//int capacidade = 0;
	Registro reg;
	bool flag = true;
	char confirm;
	int opcao;

	for (int i = 0; i < 10; i++)
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

		switch (opcao)
		{
		case 1:
			if (reg.GetCapacidade() <= 10)
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

//void AddCompetidor()
//{
//	std::string nome;
//	std::cout << "\nDigite o nome do competidor: " << std::endl
//		<< "> ";
//	std::cin >> nome;
//	cadastros[capacidade]->AddNome(nome);
//	cadastros[capacidade]->AddId(capacidade);
//	capacidade++;
//	std::cout << "Nome adicionado com sucesso" << std::endl;
//}
//
//void SearchCompetitor()
//{
//	bool flag = false;
//	int id;
//
//	std::cout << "\nDigite o id do competidor: " << std::endl
//		<< "> ";
//	std::cin >> id;
//
//	for (int i = 0; i < capacidade && flag == false; i++)
//	{
//		if (cadastros[i]->GetId() == id)
//		{
//			flag = true;
//			std::cout << "Usuario encontrado: " << std::endl
//			<< cadastros[i]->GetNome() << std::endl
//			<< "Score: " << cadastros[i]->GetScore() << std::endl;
//		}
//	}
//
//	if (!flag)
//		std::cout << "Cadastro nao encontrado" << std::endl;
//}
//
//void ListCompetitors()
//{
//	for (int i = 0; i < capacidade; i++)
//	{
//		std::cout << cadastros[i]->GetNome() << " - " << cadastros[i]->GetScore() << std::endl;
//	}
//}
//
//void DeleteCompetitor()
//{
//	int id;
//	bool flag = false;
//
//	std::cout << "\nDigite o id do competidor que deseja deletar:" << std::endl
//		<< "> ";
//	std::cin >> id;
//
//	for (int i = 0; i < capacidade; i++)
//	{
//		if (cadastros[i]->GetId() == id) //vai percorrer todo o resto da lista e preencher o espaco que foi deletado
//		{
//			GetNext(i);
//			id++;
//		}
//	}
//	capacidade--;
//	std::cout << "Competidor deletado!" << std::endl;
//}
//
//void GetNext(int id)
//{
//	if (id + 1 < capacidade)
//		cadastros[id] = cadastros[id + 1]; //cadastro recebe os dados do proximo da lista
//	else
//	{
//		cadastros[id] = new Competidor(); // Reseta o competidor
//		cadastros[id]->AddId(5000);
//	}
//}
//
//void AddScore()
//{
//	int id;
//	bool flag = false;
//
//	std::cout << "\nDigite o id que deseja atualizar score:" << std::endl
//		<< "> ";
//	std::cin >> id;
//
//	for (int i = 0; i < capacidade && flag == false; i++)
//	{
//		if (cadastros[i]->GetId() == id)
//		{
//			int score;
//			std::cout << "Competidor encontrado! Digite o novo score:" << std::endl
//				<< "> ";
//			std::cin >> score;
//			cadastros[i]->AddScore(score);
//			flag = true;
//			std::cout << "Score atualizado com sucesso" << std::endl;
//		}
//	}
//
//	if (!flag)
//		std::cout << "Competidor nao encontrado" << std::endl;
//}