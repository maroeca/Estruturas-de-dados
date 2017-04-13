#pragma once
#include "Competidor2.h"
#include<vector>
class Registro
{
public:
	Registro();
	~Registro();

	void AddCompetidor(std::vector<Competidor*> cadastros);
	void SearchCompetitor(std::vector<Competidor*> cadastros);
	void ListCompetitors(std::vector<Competidor*> cadastros);
	void DeleteCompetitor(std::vector<Competidor*> cadastros);
	void GetNext(int id, std::vector<Competidor*> cadastros);
	void AddScore(std::vector<Competidor*> cadastros);
	int GetCapacidade();
	void SetCapacidade(int capacidade);

private:
	int opcao;
	Competidor *cadastros[10];
	int capacidade;
};