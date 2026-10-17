#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void insertHead(struct Node** head, int x) {
	struct Node* aux = (struct Node*)malloc(sizeof(struct Node));
	aux->data = x;
	aux->next = *head;
	*head = aux;
}

void insertTail(struct Node** head, int x) {
	struct Node* aux = (struct Node*)malloc(sizeof(struct Node));
	aux->data = x;
	aux->next = NULL;
	if (*head == NULL) {
		*head = aux;
		return;
	}
	struct Node* t = *head;
	while (t->next != NULL) {
		t = t->next;
	}
	t->next = aux;
}

int removeValue(struct Node** head, int x) {
	struct Node* prev = NULL;
	struct Node* t = *head;
	while (t != NULL && t->data != x) {
		prev = t;
		t = t->next;
	}
	if (t == NULL) {
		return 0;
	}
	if (prev == NULL) {
		*head = t->next;
	}
	else {
		prev->next = t->next;
	}
	free(t);
	return 1;
}

void reverse(struct Node** head) {
	struct Node* prev = NULL;
	struct Node* t = *head;
	while (t != NULL) {
		struct Node* next = t->next;
		t->next = prev;
		prev = t;
		t = next;
	}
	*head = prev;
}

void print(struct Node* head) {
	printf("Lista: ");
	for (struct Node* t = head; t != NULL; t = t->next) {
		printf("%d%s", t->data, t->next ? " -> " : "");
	}
	printf("\n");
}

void freeList(struct Node** head) {
	while (*head != NULL) {
		struct Node* next = (*head)->next;
		free(*head);
		*head = next;
	}
}

int main() {
	struct Node* head = NULL;
	int n;

	printf("Cate numere doriti sa introduceti? ");
	if (scanf("%d", &n) == 1 && n > 0) {
		for (int i = 0; i < n; i++) {
			int x;
			printf("Introduceti numarul %d: ", i + 1);
			if (scanf("%d", &x) != 1) {
				break;
			}
			insertHead(&head, x);
			print(head);
		}
	}
	else {
		int demo[] = { 7, 3, 9, 1, 5 };
		printf("\nNu s-au introdus date, se folosesc valori demonstrative.\n");
		for (int i = 0; i < 5; i++) {
			insertHead(&head, demo[i]);
		}
		print(head);
	}

	insertTail(&head, 100);
	printf("\nDupa adaugarea lui 100 la final:\n");
	print(head);

	if (head != NULL && removeValue(&head, head->data)) {
		printf("Dupa stergerea primului element:\n");
		print(head);
	}

	reverse(&head);
	printf("Lista inversata:\n");
	print(head);

	freeList(&head);
	return 0;
}
