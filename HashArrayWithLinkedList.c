#include "stdio.h"
#include "stdbool.h"
#define _CAR_SECURE_NO_WARNINGS
#define SIZE 20
struct Node
{
	int data;
	int key;
	struct Node* next;

};
struct Node* hashArray[SIZE];

void display() {
	int i = 0;
	for (i = 0; i < SIZE; i++) {
		if (hashArray[i] != NULL) {
			struct Node* tmp = hashArray[i];
			while (tmp!= NULL) {

				printf(" (%d,%d)", tmp->key, tmp->data);
				tmp = tmp->next;
			}
			printf("\n");


		}
		else {
			printf("-");
			printf("\n");
		}
	}
	printf("\n");
}
int hashCode(int key) {
	return key % SIZE;
}
void insert(int key, int data ) {
	int flag = 0;
	int index = hashCode(key);
	bool isHeadEmpty = hashArray[index] == NULL;
	if (isHeadEmpty) {
		hashArray[index] = (struct Node*)malloc(sizeof(struct Node));
		hashArray[index]->key = index;
		hashArray[index]->data = data;
		hashArray[index]->next = NULL;
	}
	else
	{
		struct Node* Head = hashArray[index];
		if (Head->next == NULL) {
			if (Head->data > data) {
				struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->data = data;
				newNode->key = index;
				newNode->next = Head;
				Head->next = NULL;
				hashArray[index] = newNode;

				
			}
		}
		else {
			struct Node*  head = hashArray[index];
			struct Node* tmp = head;
			if (tmp->data > data)
			{
				struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->data = data;
				newNode->key = index;
				newNode->next = tmp->next;
				head = newNode;
				flag = 1;


			}
			while (tmp->next!=NULL&&flag==0)
			{

			
				if (tmp->next->data >data)
					{
					struct Node*newNode= (struct Node*)malloc(sizeof(struct Node));
					newNode->data = data;
					newNode->key = index;
					newNode->next = tmp->next;
					tmp->next = newNode;
					flag = 1;

					
				}
				tmp = tmp->next;
			}
			if (flag == 0) {
				tmp->next = (struct Node*)malloc(sizeof(struct Node));
				tmp->next->data = data;
				tmp->next->key = index;
				tmp->next->next = NULL;
			}

		}

		

	}
}
void Sort(struct Node* head) {

}
int main() {

	insert(1, 20);
	insert(2, 70);
	insert(4, 80);
	insert(4, 25);
	insert(4, 44);
	insert(4, 32);
	insert(4, 11);
	insert(4, 78);
	insert(4, 97);
	display();
}