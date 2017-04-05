#include <iostream>
#include <stdlib.h>

#define TAM 1000
#define KEYS 10000

void zeraVetor(int v[]) //inicia os vetores com 0
{
	for (int i = 0; i < TAM; i++)
	{
		v[i] = 0;
	}
}

void testaColisão(int v[]) //testa as colisoes nas posicoes
{
	for (int i = 0; i < KEYS; i++)
	{
		int h = i%TAM;
		v[h]++;
	}
}
//funciona git 
int main()
{
	int v[TAM];
	FILE* fp;

	char arq[] = "Colisoes.txt"; //string com o nome do arquivo e a extenção

	if ((fopen_s(&fp, arq, "a")) == 0) //fopen_s pra abrir o arquivo e ja verifica se deu certo "a" é o tipo de operação(ler,gravar...)
	{
		std::cout << "O arquivo foi aberto!" << std::endl;
	}
	else
	{
		std::cout << "O arquivo nao pode ser aberto!" << std::endl;
		return 0;
	}
	zeraVetor(v);
	testaColisão(v);

	for (int i = 0; i < TAM; i++)
	{
		fprintf(fp, "%d\n", v[i]);
	}

	fclose(fp);





	system("PAUSE");
	return 0;
}