#pragma once
#include "Competidor.h"
class Registro
{
public:
	Registro();
	~Registro();

	void AddCompetidor(Competidor* cadastros[]);
	void SearchCompetitor(Competidor* cadastros[]);
	void ListCompetitors(Competidor* cadastros[]);
	void DeleteCompetitor(Competidor* cadastros[]);
	void GetNext(int id, Competidor* cadastros[]);
	void AddScore(Competidor* cadastros[]);
	int GetCapacidade();
	void SetCapacidade(int capacidade);

private:
	int opcao;
	Competidor *cadastros[10];
	int capacidade;
};