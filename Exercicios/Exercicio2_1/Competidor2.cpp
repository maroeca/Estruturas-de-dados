#include "Competidor2.h"

Competidor::Competidor()
{
	m_id = 0;
	m_pontuacao = 0;
}

Competidor::~Competidor()
{
}

std::string Competidor::GetNome()
{
	return m_nome;
}

void Competidor::SetNome(std::string nome)
{
	m_nome = nome;
}

int Competidor::GetId()
{
	return m_id;
}

void Competidor::SetId(int id)
{
	m_id = id;
}

int Competidor::GetPontuacao()
{
	return m_pontuacao;
}

void Competidor::SetPontuacao(int pontuacao)
{
	m_pontuacao = pontuacao;
}