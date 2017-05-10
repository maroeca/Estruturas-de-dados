#include "Jogador.h"

Jogador::Jogador()
{
	m_id = 0;
	m_idade = 0;
	m_nivel = 0;
	m_pontuacao = 0;
}


Jogador::~Jogador()
{
}

void Jogador::SetID(int id)
{
	m_id = id;
}

int Jogador::GetID()
{
	return m_id;
}

void Jogador::SetNome(string nome)
{
	m_nome = nome;
}

void Jogador::SetNivel(int nivel)
{
	m_nivel = nivel;
}

void Jogador::SetPontuacao(int pontuacao)
{
	m_pontuacao = pontuacao;
}

void Jogador::SetIdade(int idade)
{
	m_idade = idade;
}

string Jogador::GetNome()
{
	return m_nome;
}

int Jogador::GetNivel()
{
	return m_nivel;
}

int Jogador::GetPontuacao()
{
	return m_pontuacao;
}

int Jogador::GetIdade()
{
	return m_idade;
}