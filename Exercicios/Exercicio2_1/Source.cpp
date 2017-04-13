#include <iostream>
#include <vector>
#include "Competidor2.h"

#define TAMANHO 10

using namespace std;

//struct Competidor {
//	string m_nome;
//	int m_id, m_pontuacao;
//};

int main() {

	vector<Competidor*> competidores(TAMANHO);
	int opcao, capacidade = 0, id;
	string nome;

	for (int i = 0; i < TAMANHO; i++) {
		competidores[i] = new Competidor();
	}

	cout << "Bem vindo ao app de dados dos competidores. O que deseja fazer?" << endl;

	do {

		cout << "1 - Cadastrar competidor" << endl;
		cout << "2 - Buscar competidor" << endl;
		cout << "3 - Listar todos os competidores" << endl;
		cout << "4 - Excluir competidor" << endl;
		cout << "5 - Atualizar pontuacao de um competidor" << endl;
		cout << "0 - Sair do programa" << endl;

		cout << "Digite o numero correspondente a sua opcao e tecle Enter: ";
		cin >> opcao;
		cout << endl;

		switch (opcao) {
		case 1:
			if (capacidade < 10) {
				cout << "Digite o nome do competidor: ";
				cin >> nome;
				//competidores[capacidade]->SetNome(nome);
				//competidores[capacidade]->SetId(capacidade);
				//cout << endl;
				//capacidade++;
				cout << "Competidor cadastrado com sucesso!" << endl;
				cout << endl;
			}
			else
				cout << "Numero maximo de cadastros permitidos atingido. Para novos cadastros, exclua um ou mais cadastros existentes." << endl;

			break;

		case 2:
			cout << "Digite a ID do competidor: ";
			cin >> id;
			cout << endl;

			for (int i = 0; i < capacidade; i++) {
				if (competidores[i]->GetId() == id) {
					cout << "Usuario encontrado!" << endl;
					cout << competidores[i]->GetNome() << " - " << competidores[i]->GetPontuacao() << " ponto(s)" << endl;
					cout << endl;
				}
			}

			break;

		case 3:
			cout << "Lista de competidores:" << endl;
			cout << endl;
			for (int i = 0; i < capacidade; i++) {
				cout << competidores[i]->GetNome() << " - " << competidores[i]->GetPontuacao() << " ponto(s)" << endl;
			}
			cout << endl;

			break;

		case 4:
			cout << "Digite a ID do competidor que deseja excluir: ";
			cin >> id;

			for (int i = 0; i < capacidade; i++) {
				if (competidores[i]->GetId() == id) {
					if (id + 1 < capacidade)
						competidores[id] = competidores[id + 1];
					else {
						competidores[id] = new Competidor();
						competidores[id]->SetId(5000);
					}
					id++;
				}
			}
			capacidade--;
			cout << "Competidor deletado com sucesso!" << endl;
			cout << endl;

			break;

		case 5:
			cout << "Digite a ID para a qual voce deseja alterar a pontuacao: ";
			cin >> id;

			for (int i = 0; i < capacidade; i++) {
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

		case 0:
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