#include <iostream>
#include <time.h>
#include <vector>

#define TAM 100

void IniciaVetor(int vet[])
{
	int a = TAM;
	for (int i = 0; i < TAM; i++)
	{
		vet[i] = a--;
	}
}

void ImprimeVetor(int vetor[])
{
	for (int i = 0; i < TAM; i++)
	{
		std::cout << vetor[i] << " ";
	}
}

int InsertSort(int vetor[]) {
	int cont = 0;

	for (int i = 1; i < TAM; i++) {
		int escolhido = vetor[i];
		int j = i - 1;

		while ((j >= 0) && (vetor[j] > escolhido)) {
			vetor[j + 1] = vetor[j];
			j--;
			cont++;
		}

		vetor[j + 1] = escolhido;
	}

	return cont;
}


int BubbleSort(int v[])
{
	int aux;
	int contTrocas = 0;
	for (int i = 0; i < TAM; i++)
	{
		for (int j = i + 1; j < TAM; j++)
		{
			if (v[i] > v[j])
			{
				contTrocas++;
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
			}
		}
	}
	return contTrocas;
}

int quickSort(int vet[], int comeco, int fim) {
	int pivot, aux;
	int esquerda, direita;
	int contTrocas = 0;

	pivot = vet[(comeco + fim) / 2];
	esquerda = comeco;
	direita = fim;

	while (esquerda <= direita) {
		while (vet[esquerda] < pivot)
			esquerda++;

		while (vet[direita] > pivot)
			direita--;

		if (esquerda <= direita) {
			aux = vet[esquerda];
			vet[esquerda] = vet[direita];
			vet[direita] = aux;
			esquerda++; direita--;
			contTrocas++;
		}
	}

	if (direita > comeco)
		quickSort(vet, comeco, direita);

	if (esquerda < fim)
		quickSort(vet, direita + 1, fim);

	return contTrocas;
}

int main()
{
	srand(time(NULL));
	int vetor[TAM];
	int bubble, quick, insert;

	IniciaVetor(vetor);
	ImprimeVetor(vetor);
	std::cout << std::endl << std::endl;

	bubble = BubbleSort(vetor);
	ImprimeVetor(vetor);//oi

	std::cout << std::endl;
	std::cout << "BubbleSort: " << bubble << " trocas." << std::endl << std::endl;

	IniciaVetor(vetor);
	quick = quickSort(vetor, 0, TAM - 1);
	ImprimeVetor(vetor);
	std::cout << std::endl;
	std::cout << "QuickSort: " << quick << " trocas." << std::endl << std::endl;

	IniciaVetor(vetor);
	insert = InsertSort(vetor);
	ImprimeVetor(vetor);
	std::cout << std::endl;
	std::cout << "InsertSort: " << insert << " trocas." << std::endl;

	system("PAUSE");
	return 0;

}