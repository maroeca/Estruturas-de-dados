#include <iostream>
#include <vector>
#include "Competidor2.h"

#define TAM 10

using namespace std;

int main() {

	vector<Competidor*> competidores;
	Competidor *aux;
	int opcao, capacidade = 0, id;
	string nome;

	cout << "Bem vindo ao app de dados dos competidores. O que deseja fazer?" << endl;

	do {

		cout << "1 - Cadastrar competidor" << endl;
		cout << "2 - Buscar competidor" << endl;
		cout << "3 - Listar todos os competidores" << endl;
		cout << "4 - Excluir competidor" << endl;
		cout << "5 - Atualizar pontuacao de um competidor" << endl;
		cout << "0 - Sair do programa" << endl;

		cout << "Escolha uma opcao e tecle Enter: ";
		cin >> opcao;
		cout << endl;

		system("CLS");

		switch (opcao) {
		case 1:  //CADASTRAR COMPETIDOR
			cout << "Digite o nome do competidor: ";
			cin >> nome;

			aux = new Competidor();
			aux->SetNome(nome);
			aux->SetId(capacidade);

			competidores.push_back(aux);

			cout << endl;
			capacidade++;
			cout << "Competidor cadastrado com sucesso!" << endl;
			cout << endl;

			break;

		case 2:  //BUSCAR COMPETIDOR
			cout << "Digite a ID do competidor: ";
			cin >> id;
			cout << endl;

			for (int i = 0; i < competidores.size(); i++) {
				if (competidores[i]->GetId() == id) {
					cout << "Usuario encontrado!" << endl;
					cout << competidores[i]->GetNome() << " - " << competidores[i]->GetPontuacao() << " ponto(s)" << endl;
					cout << endl;
				}
			}

			break;

		case 3: //LISTAR COMPETIDORES
			cout << "Lista de competidores:" << endl;
			cout << endl;
			for (int i = 0; i < competidores.size(); i++) {
				cout << "ID: " << competidores[i]->GetId() << " - " << competidores[i]->GetNome() << " - " << competidores[i]->GetPontuacao() << " ponto(s)" << endl;
			}
			cout << endl;

			break;

		case 4: //EXCLUIR COMPETIDOR
			cout << "Digite a ID do competidor que deseja excluir: ";
			cin >> id;

			for (int i = 0; i < competidores.size(); i++) {
				if (competidores[i]->GetId() == id) {
					competidores[id]->SetId(id - 1);

					if (id + 1 < competidores.size())
						competidores[id] = competidores[id + 1];
					else {
						competidores[id] = new Competidor();
						competidores[id]->SetId(5000);
					}

					id++;
				}
			}
			competidores.pop_back();
			capacidade--;
			cout << "Competidor deletado com sucesso!" << endl;
			cout << endl;

			break;

		case 5: //ATUALIZAR PONTUAÇÃO
			cout << "Digite a ID para a qual voce deseja alterar a pontuacao: ";
			cin >> id;

			for (int i = 0; i < competidores.size(); i++) {
				if (competidores[i]->GetId() == id) {
					int pontuacao;
					cout << "Competidor encontrado! Digite sua nova pontuacao: ";
					cin >> pontuacao;
					competidores[i]->SetPontuacao(pontuacao);
					cout << "Pontuacao atualizada com sucesso!" << endl;
					cout << endl;
				}
			}

			break;

		case 0: //SAIR DO PROGRAMA
			opcao = 0;
			cout << "App encerrado." << endl;
			cout << " " << endl;
			break;

		default:
			cout << "Opcao inexistente. Escolha uma opcao valida." << endl;
			break;
		}
		

	} while (opcao != 0);

	system("pause");
	return 0;
}