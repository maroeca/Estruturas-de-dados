#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class hash
{
private:
	static const int TamanhoTabela = 10; //define o tamanho da tabela dentro da classe

	struct item {
		string reservada;
		item *prox;
	};

	item* TabelaHash[TamanhoTabela]; //ponteiro com o tamanho da tabela

public:
	int Hash(string chave);
	void Inserir(string reservada);
	int NumeroDeItensNaLista(int indice);
	void ImprimirTabela();
	void ImprimirItensNoIndice(int indice);
	void BuscaPalavra(string reservada);

	hash();
	~hash();

};

#endif // HASH_H
