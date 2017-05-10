#pragma once
#pragma once

#include <iostream>

using namespace std;

class Jogador
{
private:
	int m_id, m_nivel;
	int m_pontuacao, m_idade;
	string m_nome;
public:
	Jogador();
	~Jogador();

	void SetID(int id);
	void SetNome(string nome);
	void SetNivel(int nivel);
	void SetPontuacao(int pontuacao);
	void SetIdade(int idade);

	int GetID();
	string GetNome();
	int GetNivel();
	int GetPontuacao();
	int GetIdade();
};