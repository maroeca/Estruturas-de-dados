#pragma once
#include <string>
#include <iostream>
using namespace std;

class Competidor
{
private:
	string m_nome;
	int m_id, m_pontuacao;
public:
	Competidor();
	~Competidor();

	std::string GetNome();
	void SetNome(std::string nome);

	int GetId();
	void SetId(int id);

	int GetPontuacao();
	void SetPontuacao(int pontuacao);
};