#pragma once
#include<string>
#include<iostream>

class Competidor
{
public:
	Competidor();
	~Competidor();

	void AddNome(std::string nome);
	void AddScore(int score);
	void AddId(int id);

	void setId(int id);

	std::string GetNome();
	void PrintNome();
	int GetScore();
	int GetId();
	std::string name;

private:
	int id,
		score;

};

