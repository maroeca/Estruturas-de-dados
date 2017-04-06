#include <iostream>
#include <stdlib.h>
#include <vector>

#define TAM 1000
#define KEYS 10000

//std::vector <int> vetprimo;
//void vetorPrimo()
//{
//	int cont = 0;
//	for (int i = 0; i < 10000; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				cont++;
//			}
//			if (cont == 2)
//				vetprimo.push_back(i);
//		}
//	}
//}

void zeraVetor(int v[]) //inicia os vetores com 0
{
	for (int i = 0; i < TAM; i++)
	{
		v[i] = 0;
	}
}

//void testaColisaoPrimo(int v[])
//{
//	for (int i = 0; i < vetprimo.size; i++)
//	{
//		int h = vetprimo[i] % i;
//		v[h]++;
//	}
//}

void testaColisão(int v[]) //testa as colisoes nas posicoes
{
	for (int i = 0; i < 10000; i++)
	{
		int h = i % TAM;
		v[h]++;
	}
}

bool isCousin(int num)
{
	int cont = 0;
	for (int i = 1; i <= num; i++)
	{
		if ((num % i) == 0)
		{
			cont++;
		}
	}
	if (cont == 2)
		return true;
	else
		return false;
}
void testaColisaoPrimo(int v[]) //testa as colisoes nas posicoes
{
	int h = 0;
	for (int i = 0; i < KEYS; i++)
	{
		if (isCousin(i)) {
			h = i % TAM;
			v[h]++;
		}
	}
}
//funciona git 
int main()
{
	int v[TAM];
	int vprimo[TAM];
	FILE* fp;
	FILE* fpprimo;

	char arqprimo[] = "ColisoesPrimo.txt";
	if ((fopen_s(&fpprimo, arqprimo, "w")) == 0)
	{
		std::cout << "Fpprimo foi aberto!" << std::endl;
	}
	else
	{
		std::cout << "Fpprimo não abriu" << std::endl;
		return 0;
	}
	char arq[] = "Colisoes.txt"; //string com o nome do arquivo e a extenção

	if ((fopen_s(&fp, arq, "w")) == 0) //fopen_s pra abrir o arquivo e ja verifica se deu certo "a" é o tipo de operação(ler,gravar...)
	{
		std::cout << "O arquivo foi aberto!" << std::endl;
	}
	else
	{
		std::cout << "O arquivo nao pode ser aberto!" << std::endl;
		return 0;
	}
	zeraVetor(v);
	zeraVetor(vprimo);
	testaColisão(v);	
	testaColisaoPrimo(vprimo);

	for (int i = 0; i < TAM; i++)
	{
		fprintf(fp, "%d\n", v[i]);
		fprintf(fpprimo, "%d\n", vprimo[i]);
	}

	fclose(fp);
	fclose(fpprimo);





	system("PAUSE");
	return 0;
}