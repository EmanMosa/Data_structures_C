#include "stdio.h"
#include "stdbool.h"
#define _CAR_SECURE_NO_WARNINGS
#define SIZE 20
struct Node
{
	int data;
	int key;

};
struct Node* hashArray[SIZE];

void display() {
	int i = 0;
	for (i = 0; i < SIZE; i++) {
		if (hashArray[i] != NULL)
			printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
		else
			printf("-");
	}
	printf("\n");
}
int hashCode(int key) {
	return key % SIZE;
}
void insert(int key, int data ) {
	int index = hashCode(key);
	if (hashArray[index] == NULL) {
		hashArray[index] = (struct Node*)malloc(sizeof(struct Node));
		hashArray[index]->key = key;
		hashArray[index]->data = data;
	}
	else
	{
		while (hashArray[index] != NULL) {
			index++;
		}
		hashArray[index] = (struct Node*)malloc(sizeof(struct Node));
		hashArray[index]->key = key+1;
		hashArray[index]->data = data;

	}
}
int main() {

	insert(1, 20);
	insert(2, 70);
	insert(4, 80);
	insert(4, 25);
	insert(12, 44);
	insert(14, 32);
	insert(17, 11);
	insert(13, 78);
	insert(37, 97);
	display();
}