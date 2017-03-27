#include <iostream>
#include <stdio.h>

int searchS(int v[], int size, int value, FILE *fp)
{
	for (int i = 0; i < size; i++)
	{
		if (v[i] == value)
		{
			//fprintf(fp, "Busca Sequencial: %d\n",i); //imprime no arquivo
			//std::cout << "Tentativas busca sequencial: " << i << std::endl;
			return i;
		}
	}

	std::cout << "nao encontrei o elemento" << std::endl;
	return -1;
}


int searchB(int v[], int size, int value, FILE *fp)
{
	int min = 0;
	int max = size - 1;
	int med;
	int count = 0;

	while (min <= max)
	{
		med = (min + max) / 2;
		if (value == v[med])
		{
			//fprintf(fp, "Busca Binaria: %d\n\n", count); //imprime no arquivo
			//std::cout << "Tentativas busca binaria: " << count << " valor: " << med << std::endl;
			count++;
			return count;
		}
		if (value < v[med])
		{
			max = med - 1;
			count++;
		}
		else
		{
			min = med + 1;
			count++;
		}
	}
	std::cout << "Valor nao encontrado" << std::endl;
	return -1;
}

int SearchH(int v[], int key, FILE* fp)
{
	int i = 0;
	if (v[key] == key)
		i++;
	return i;

}

void preencheVetor(int v[], int tam) //preenche o vetor
{
	for (int i = 0; i < tam; i++)
	{
		v[i] = i;
	}
}

int main()
{
	int vetor[1000];
	int value;
	int tentativaB, tentativaS, tentativaH;
	FILE *fp; //declaração do arquivo

	char arq[] = "buscas.txt"; //string com o nome do arquivo e a extenção

	if ((fopen_s(&fp, arq, "a")) == 0) //fopen_s pra abrir o arquivo e ja verifica se deu certo "a" é o tipo de operação(ler,gravar...)
	{
		std::cout << "O arquivo foi aberto!" << std::endl;
	}
	else
	{
		std::cout << "O arquivo nao pode ser aberto!" << std::endl;
		return 0;
	}

	preencheVetor(vetor, 1000);

	/*for (int i = 0; i < 1000; i++)
	{
	vetor[i] = i;
	}*/

	std::cout << "Escolha um valor de 0 a 999 para fazer a busca: " << std::endl;
	std::cin >> value;

	tentativaS = searchS(vetor, 1000, value, fp);
	fprintf(fp, "%d", tentativaS); //imprime no arquivo
	std::cout << "Tentativas busca sequencial: " << tentativaS << std::endl;

	tentativaB = searchB(vetor, 1000, value, fp);
	fprintf(fp, "    %d", tentativaB); //imprime no arquivo
	std::cout << "Tentativas busca binaria: " << tentativaB << std::endl;

	tentativaH = SearchH(vetor, value, fp);
	fprintf(fp, "    %d\n", tentativaH);
	std::cout << "Tentativas busca por hash: " << tentativaH << "\nvalor: " << value << std::endl;

	fclose(fp); //fecha o arquivo

	system("pause");
	return 0;
}