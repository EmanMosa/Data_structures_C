#include "stdio.h"
#include "stdbool.h"
#define _CAR_SECURE_NO_WARNINGS

struct node
{
	int data;
	struct node* next;
	struct node* prev;

};
struct node* head;
struct node* CreateNewNode(int x) {
	struct node* NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->data = x;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}
void Print() {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp = head;
	while (tmp != NULL)
	{

		printf("%d    ", tmp->data);
		tmp = tmp->next;
	}

}
void InsertAtHead(int x) {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));

	if (head == NULL) {
		head = CreateNewNode(x);
	}
	else {
		tmp = head;
		head = CreateNewNode(x);
		tmp->prev = head;
		head->next = tmp;

	}
}
void Append(int x) {
	struct node* tmp = head;
	if (head == NULL) {
		head = CreateNewNode(x);
	}
	else {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = CreateNewNode(x);
		tmp->next->prev = tmp;
	}
}
bool isEmpty() {
	if (head == NULL) {
		return true;

	}
	return false;
}
int length() {
	struct node* tmp = head;
	int count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}
struct node* SwapNodes(struct node* list) {
	struct node* node = (struct node*)malloc(sizeof(struct node));

	return node;
}
void Sort() {
	struct node* tmp = head;
	struct node* node = (struct node*)malloc(sizeof(struct node));

	struct node* sortList = NULL;
	while (tmp != NULL)
	{
		if (tmp->data < tmp->next->data) {
			node = tmp->next;
			tmp->next = node->next;
			node->next = tmp;
			node->prev = tmp->prev;
			tmp->prev = node;
			if (tmp->next != NULL)
				tmp->next->prev = tmp;
			if (tmp == head) {
				head = node;
			}

			tmp = tmp->prev;
		}
		tmp = tmp->next;
	}
}
int main() {
	head = NULL;
	int num;
	int node;
	printf("how mony node do you want :");
	scanf_s("%d", &num);
	for (int i = 1; i <= num; i++) {
		printf("enter the node number %d :     ", i);
		scanf_s("%d", &node);
		//InsertAtHead(node);
		Append(node);

	}
	Sort();
	Print();
	if (isEmpty())
		printf("\nthe link list is empty\n");
	else
		printf("\nsize of the linked List is %d \n", length());
}