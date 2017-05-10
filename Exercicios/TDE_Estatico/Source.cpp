#include <iostream>
#include <string>
#include "Jogador.h"

#define TAM 10

using namespace std;

int main() {
	Jogador *jogadores[TAM]; //array de jogadores
	int opc, quantidade = 0;
	bool flag;

	for (int i = 0; i < TAM; i++) //criando os jogadores
		jogadores[i] = new Jogador();

	cout << "App de Jogadores! Escolha uma opcao: " << endl;

	do {
		cout << "1 - Cadastrar" << endl;
		cout << "2 - Listar" << endl;
		cout << "3 - Buscar por ID" << endl;
		cout << "4 - Excluir" << endl;
		cout << "0 - Sair" << endl;

		cout << "Selecione a opcao: ";
		cin >> opc;

		if (opc >= 5 || opc <= -1)
			cout << "Escolha uma opcao valida!" << endl;

		switch (opc) {
		case 1: //CADASTRAR JOGADOR
			if (quantidade < 10) {
				//seta o id
				jogadores[quantidade]->SetID(quantidade);

				//guarda o nome
				string nome;
				cout << "Digite o nome do jogador: ";
				cin >> nome;
				jogadores[quantidade]->SetNome(nome);

				//guarda o nivel
				int nivel;
				cout << "Digite o nivel do jogador: ";
				cin >> nivel;
				while (nivel <= 0 || nivel >= 6) { //valores permitidos para nivel: 1, 2, 3, 4 ou 5
					cout << "Valor invalido. Digite um valor entre 1 e 5: ";
					cin >> nivel;
				}
				jogadores[quantidade]->SetNivel(nivel);

				//guarda a pontuação
				int pontuacao;
				cout << "Digite a pontuacao: ";
				cin >> pontuacao;
				jogadores[quantidade]->SetPontuacao(pontuacao);

				//guarda a idade
				int idade;
				cout << "Digite a idade: ";
				cin >> idade;
				jogadores[quantidade]->SetIdade(idade);

				//fim
				quantidade++;
				cout << "Jogador cadastrado com sucesso!" << endl;
			}
			else {
				cout << "Sem espaco na lista!" << endl;
			}
			break;

		case 2: //LISTAR TODOS (nome, id e pontuacao)
			cout << "Lista de jogadores: " << endl;
			for (int i = 0; i < quantidade; i++)
				cout << "ID: " << jogadores[i]->GetID() << " | " <<
				"Nome: " << jogadores[i]->GetNome() << " | " <<
				"Pontuacao: " << jogadores[i]->GetPontuacao() << endl;
			cout << endl;
			break;

		case 3: //BUSCAR POR ID (mostrar todos os dados)
			int id;
			flag = false;
			cout << "Digite a ID que deseja buscar: ";
			cin >> id;

			for (int i = 0; i < quantidade; i++) {
				if (jogadores[i]->GetID() == id) {
					cout << "Usuario encontrado!" << endl;
					flag = true;
					cout << "ID: " << jogadores[i]->GetID() << " | " <<
						"Nome: " << jogadores[i]->GetNome() << " | " <<
						"Nivel: " << jogadores[i]->GetNivel() << " | " <<
						"Pontuacao: " << jogadores[i]->GetPontuacao() << " | " <<
						"Idade: " << jogadores[i]->GetIdade() << endl;
				}
			}

			if (flag == false)
				cout << "Jogador nao encontrado." << endl;

			break;

		case 4: //EXCLUIR JOGADOR
				//int id;
			char op;
			flag = false;
			cout << "Digite a ID do jogador que deseja excluir: ";
			cin >> id;

			for (int i = 0; i < quantidade; i++) {
				if (jogadores[i]->GetID() == id) {
					cout << "Usuario encontrado!" << endl;
					flag = true;
					cout << "ID: " << jogadores[i]->GetID() << " | " <<
						"Nome: " << jogadores[i]->GetNome() << " | " <<
						"Nivel: " << jogadores[i]->GetNivel() << " | " <<
						"Pontuacao: " << jogadores[i]->GetPontuacao() << " | " <<
						"Idade: " << jogadores[i]->GetIdade() << endl;
					cout << endl;
				}
			}

			if (flag == false)
				cout << "Jogador nao encontrado." << endl;

			if (flag) {
				cout << "Eh este o jogador que deseja excluir? Y/N: ";
				cin >> op;
				if (op == 'y' || op == 'Y') {
					for (int i = 0; i < quantidade; i++)
						if (jogadores[i]->GetID() == id) {
							jogadores[i]->SetID(id - 1);
							if (id + 1 < quantidade)
								jogadores[id] = jogadores[id + 1];
							else {
								jogadores[id] = new Jogador();
								jogadores[id]->SetID(5000);
							}
							id++;
						}
					quantidade--;
					cout << "Jogador deletado com sucesso!" << endl;
				}
				else {
					cout << "Exclusao cancelada." << endl;
				}
			}
			break;

		case 0: //SAIR DO APP
			opc = 0;
			cout << "App encerrado." << endl;
			break;
		default:
			break;

		}
	} while (opc != 0);

	system("pause");
	return 0;
}