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
	Stack *operandos;
	Stack *operadores;

	int k = 0;

	char eq[] = "((((4+3)-(5*2))/(7-3))";

	char res[20];

	operandos = createStack(strlen(eq));
	operadores = createStack(strlen(eq));

	int comp[10];
	for (int i = 0; i < 10; i++)
	{
		comp[i] = i;
	}



	while (k < strlen(eq))
	{
		if (eq[k] == '(' || eq[k] == '*' || eq[k] == '+' || eq[k] == '-' || eq[k] == '/')
		{
			add(operandos, eq[k]);
		}
		else
			add(operadores, eq[k]);

		if (eq[k] == ')')
		{
			//dostuff
		}
	}

	system("PAUSE");
	return 0;
}