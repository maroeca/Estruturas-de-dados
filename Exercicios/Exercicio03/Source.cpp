#include <iostream>
#include "hash.h"
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	hash ObjetoHash;

	ObjetoHash.Inserir("auto");
	ObjetoHash.Inserir("asm");
	ObjetoHash.Inserir("bool");
	ObjetoHash.Inserir("break");
	ObjetoHash.Inserir("case");
	ObjetoHash.Inserir("catch");
	ObjetoHash.Inserir("char");
	ObjetoHash.Inserir("class");
	ObjetoHash.Inserir("const");
	ObjetoHash.Inserir("const_cast");
	ObjetoHash.Inserir("continue");
	ObjetoHash.Inserir("default");
	ObjetoHash.Inserir("delete");
	ObjetoHash.Inserir("do");
	ObjetoHash.Inserir("double");
	ObjetoHash.Inserir("dynamic_cast");
	ObjetoHash.Inserir("else");
	ObjetoHash.Inserir("enum");
	ObjetoHash.Inserir("explicit");
	ObjetoHash.Inserir("extern");
	ObjetoHash.Inserir("false");
	ObjetoHash.Inserir("float");
	ObjetoHash.Inserir("for");
	ObjetoHash.Inserir("friend");
	ObjetoHash.Inserir("goto");
	ObjetoHash.Inserir("if");
	ObjetoHash.Inserir("inline");
	ObjetoHash.Inserir("int");
	ObjetoHash.Inserir("long");
	ObjetoHash.Inserir("mutable");
	ObjetoHash.Inserir("namespace");
	ObjetoHash.Inserir("new");
	ObjetoHash.Inserir("operator");
	ObjetoHash.Inserir("private");
	ObjetoHash.Inserir("protected");
	ObjetoHash.Inserir("public");
	ObjetoHash.Inserir("register");
	ObjetoHash.Inserir("reinterpret_cast");
	ObjetoHash.Inserir("return");
	ObjetoHash.Inserir("short");
	ObjetoHash.Inserir("signed");
	ObjetoHash.Inserir("sizeof");
	ObjetoHash.Inserir("static");
	ObjetoHash.Inserir("static_cast");
	ObjetoHash.Inserir("struct");
	ObjetoHash.Inserir("switch");
	ObjetoHash.Inserir("template");
	ObjetoHash.Inserir("this");
	ObjetoHash.Inserir("throw");
	ObjetoHash.Inserir("true");
	ObjetoHash.Inserir("try");
	ObjetoHash.Inserir("typedef");
	ObjetoHash.Inserir("typeid");
	ObjetoHash.Inserir("typename");
	ObjetoHash.Inserir("union");
	ObjetoHash.Inserir("unsigned");
	ObjetoHash.Inserir("using");
	ObjetoHash.Inserir("virtual");
	ObjetoHash.Inserir("void");
	ObjetoHash.Inserir("volatile");
	ObjetoHash.Inserir("wchar_t");
	ObjetoHash.Inserir("while");

	int opcao = 0;
	int aux;
	string palavra = "";

	while (opcao != 4) {
		cout << "      **** MENU ****" << endl << endl;
		cout << "Total de palavras reservadas = 62\nEspalhadas em uma tabela hash de tamanho 10\n\n";
		cout << "1 - Buscar uma palavra reservada" << endl;
		cout << "2 - Imprimir tabela por indice" << endl;
		cout << "3 - Imprimir toda a tabela" << endl;
		cout << "4 - Para finalizar" << endl;

		cout << endl << endl << "Digite sua opcao: " << endl;
		cin >> opcao;
		switch (opcao) {
		case 1:
			while (palavra != "sair") {
				cout << "Para terminar a busca, digite sair\nBuscar por: " << endl;
				cin >> palavra;
				if (palavra != "sair") {
					ObjetoHash.BuscaPalavra(palavra);
				}
			}
			break;
		case 2:
			cout << endl << "Digite o indice que deseja imprimir\nOBS: de 0 a 9" << endl;
			cin >> aux;
			if (aux == 0) {
				ObjetoHash.ImprimirItensNoIndice(0);
				cout << endl;
			}
			if (aux == 1) {
				ObjetoHash.ImprimirItensNoIndice(1);
				cout << endl;
			}
			if (aux == 2) {
				ObjetoHash.ImprimirItensNoIndice(2);
				cout << endl;
			}
			if (aux == 3) {
				ObjetoHash.ImprimirItensNoIndice(3);
				cout << endl;
			}
			if (aux == 4) {
				ObjetoHash.ImprimirItensNoIndice(4);
				cout << endl;
			}
			if (aux == 5) {
				ObjetoHash.ImprimirItensNoIndice(5);
				cout << endl;
			}
			if (aux == 6) {
				ObjetoHash.ImprimirItensNoIndice(6);
				cout << endl;
			}
			if (aux == 7) {
				ObjetoHash.ImprimirItensNoIndice(7);
				cout << endl;
			}
			if (aux == 8) {
				ObjetoHash.ImprimirItensNoIndice(8);
				cout << endl;
			}
			if (aux == 9) {
				ObjetoHash.ImprimirItensNoIndice(9);
				cout << endl;
			}
			break;
		case 3:
			cout << endl;
			ObjetoHash.ImprimirTabela();
			break;
		default:
			cout << "Escolha invalida!" << endl << endl;
			break;
		}
		return 0;
	}
}