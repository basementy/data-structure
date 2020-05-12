#include <stdio.h>
#include <stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // Váriavel global - Ponteiro para o primeiro nó

// Cria um novo nó e retorna um pointeiro para ele
struct Node* GetNewNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

// Insere um nó no inicio da lista
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);

	if(head == NULL) {
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

// Insere um nó no final da lista
void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);

	if(head == NULL) {
		head = newNode;
		return;
	}

	while(temp->next != NULL) temp = temp->next; // Go To last Node

	temp->next = newNode;
	newNode->prev = temp;
}

// Imprime todos os elementos da lista em ordem direta
void Print() {
	struct Node* temp = head;

	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}

	printf("\n");
}

// Imprime todos os elementos da lista em ordem inversa
void ReversePrint() {
	struct Node* temp = head;

	if(temp == NULL) return; // Caso a lista esteja vazia

	// Indo para o último nó
	while(temp->next != NULL) {
		temp = temp->next;
	}

	// Retrocede usando o ponteiro anterior
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}

	printf("\n");
}

int main() {
	head = NULL; // Lista vazia. Setando o head como NULL

  // Chama uma inserção e impressão, tanto na direção direta quanto na reversa.
	InsertAtTail(2); Print(); ReversePrint();
	InsertAtTail(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	InsertAtTail(8); Print(); ReversePrint();
}
