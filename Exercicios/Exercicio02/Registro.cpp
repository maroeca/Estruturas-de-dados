#include "Registro.h"
#include "Competidor.h"
#include <iostream>

Registro::Registro()
{
	//Competidor* cadastros[10];
	capacidade = 0;
}

Registro::~Registro()
{
}

void Registro::AddCompetidor(Competidor* cadastros[])
{
	std::string nome;
	std::cout << "\nDigite o nome do competidor: " << std::endl
		<< "> ";
	std::cin >> nome;
	cadastros[capacidade]->AddNome(nome);
	cadastros[capacidade]->AddId(capacidade);
	capacidade++;
	std::cout << "Nome adicionado com sucesso" << std::endl;
}

void Registro::SearchCompetitor(Competidor* cadastros[])
{
	bool flag = false;
	int id;

	std::cout << "\nDigite o id do competidor: " << std::endl
		<< "> ";
	std::cin >> id;

	for (int i = 0; i < capacidade && flag == false; i++)
	{
		if (cadastros[i]->GetId() == id)
		{
			flag = true;
			std::cout << "Usuario encontrado: " << std::endl
				<< cadastros[i]->GetNome() << std::endl
				<< "Score: " << cadastros[i]->GetScore() << std::endl;
		}
	}

	if (!flag)
		std::cout << "Cadastro nao encontrado" << std::endl;
}

void Registro::ListCompetitors(Competidor* cadastros[])
{
	for (int i = 0; i < capacidade; i++)
	{
		std::cout << cadastros[i]->GetNome() << " - " << cadastros[i]->GetScore() << std::endl;
	}
}

void Registro::DeleteCompetitor(Competidor* cadastros[])
{
	int id;
	bool flag = false;

	std::cout << "\nDigite o id do competidor que deseja deletar:" << std::endl
		<< "> ";
	std::cin >> id;

	for (int i = 0; i < capacidade; i++)
	{
		if (cadastros[i]->GetId() == id) //vai percorrer todo o resto da lista e preencher o espaco que foi deletado
		{
			GetNext(i, cadastros);
			id++;
		}
	}
	capacidade--;
	std::cout << "Competidor deletado!" << std::endl;
}

void Registro::GetNext(int id, Competidor* cadastros[])
{
	if (id + 1 < capacidade)
		cadastros[id] = cadastros[id + 1]; //cadastro recebe os dados do proximo da lista
	else
	{
		cadastros[id] = new Competidor(); // Reseta o competidor
		cadastros[id]->AddId(5000);
	}
}

void Registro::AddScore(Competidor* cadastros[])
{
	int id;
	bool flag = false;

	std::cout << "\nDigite o id que deseja atualizar score:" << std::endl
		<< "> ";
	std::cin >> id;

	for (int i = 0; i < capacidade && flag == false; i++)
	{
		if (cadastros[i]->GetId() == id)
		{
			int score;
			std::cout << "Competidor encontrado! Digite o novo score:" << std::endl
				<< "> ";
			std::cin >> score;
			cadastros[i]->AddScore(score);
			flag = true;
			std::cout << "Score atualizado com sucesso" << std::endl;
		}
	}

	if (!flag)
		std::cout << "Competidor nao encontrado" << std::endl;
}

int Registro::GetCapacidade()
{
	return capacidade;
}

void Registro::SetCapacidade(int capacidade)
{
	this->capacidade = capacidade;
}
