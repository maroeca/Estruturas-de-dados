#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <iostream>

//estrutura que representa a pilha
struct Stack {
	int top;
	int capacity;
	int size;
	char *array;
};

//função para criar uma pilha de dada capacidade. inicializa o tamanho da pilha em 0
struct Stack *createStack(int capacity) {
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));  //tipo, malloc, tamanho
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char*)malloc(stack->capacity * sizeof(char));
	return stack;
}

//pilha cheia quando top é igual ao último index
int isFull(Stack *stack) {
	return stack->top == stack->capacity - 1;
}

//pilha vazia quando top é igual a -1
int isEmpty(Stack *stack) {
	return stack->top == -1;
}

//função para add um item na pilha. aumenta top em 1
void add(Stack *stack, char item) {
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	stack->size++;
}

//função para remover um item da pilha. diminui top em 1
char remove(Stack *stack) {
	if (isEmpty(stack))
		return INT_MIN; //menor valor armazenável numa variável int
	//stack->size--;
	return stack->array[stack->top--];
}

//função que irá reverter os caracteres
void reverse(char str[]) {
	//cria uma pilha de capacidade igual ao comprimento da string
	int n = strlen(str);
	Stack *stack = createStack(n);

	//add todos os caracteres da string na pilha
	for (int i = 0; i < n; i++)
		add(stack, str[i]);

	//remove todos os caracteres da pilha e os coloca de volta no array str
	for (int i = 0; i < n; i++)
		str[i] = remove(stack);
}

int main()
{
	Stack *pilhaChacter;
	Stack *pilhaEspaco;
	std::vector<char> result;

	int i = 0;
	char frase[] = "ESTE EXERCICIO E MUITO FACIL ";

	for (int i = 0; i < strlen(frase); i++)
	{
		std::cout << frase[i];
	}
	std::cout << std::endl;

	pilhaChacter = createStack(strlen(frase)); //inicia as pilhas
	pilhaEspaco = createStack(strlen(frase));

	pilhaChacter->size = 0;

	//passa por todos os elementos da string verificando se é espaço
	while (i <= strlen(frase))
	{
		//se não for, adiciona na pilha de caracter
		if (frase[i] != ' ')
		{
			add(pilhaChacter, frase[i]);
			//std::cout << frase[i];
		}
		//se for, adiciona na pilha de espaço e desempilha numa string
		else
		{
			add(pilhaChacter, frase[i]);
			for (int j = 0; j <= pilhaChacter->size; j++)
			{
				result.push_back(remove(pilhaChacter));
			}
			pilhaChacter->size = 0;
		}
		i++;
	}

	for (int k = 0; k < result.size(); k++)
	{
		std::cout << result[k];// << std::endl << std::endl;
	}

	system("PAUSE");
	return 0;
}