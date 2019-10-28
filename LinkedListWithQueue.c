

#include "stdio.h"
#define _CAR_SECURE_NO_WARNINGS

struct node
{
	int data;
	struct node* next;
};
struct node* head;
struct node* tail;
void Append(int num);
void InsertAtHead(int);
void InsertAtPosition(int num, int index);
void Print();
void  DeleteAtPosition(int index);
void Reverse() {
	struct node* tmp = head;
	struct node* revers = (struct node*)malloc(sizeof(struct node));
	while (tmp != NULL) {
		tmp = tmp->next;
	}


}
void InsertAtPosition(int num, int index) {
	int count = 0;
	struct node* pointer = head;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;
	if (index == 0) {
		Append(num);

	}
	else
	{
		while (count != (index - 1))
		{
			pointer = pointer->next;
			count++;

		}
		newNode->next = pointer->next;
		pointer->next = newNode;
	}

}
void Append(int num) {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = num;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
	}




}
void InsertAtHead(int num) {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));

	tmp->data = num;
	tmp->next = head;
	head = tmp;



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
void DeleteAtPosition(int index) {
	int count = 0;
	struct node* pointer = head;
	//struct node* newNode = (struct node*)malloc(sizeof(struct node));

	if (index == 0) {
		head = head->next;

	}
	else
	{
		while (count != (index - 1))
		{
			pointer = pointer->next;
			count++;

		}
		pointer->next = pointer->next->next;
	}

}




void Enquene(int var) {
	Append(var);

}
int Dequeue() {
	struct node* tmp = head;
	head = head->next;
	return tmp->data;
}
int main()
{
	int var;
	int result;
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* tail = (struct node*)malloc(sizeof(struct node));
	head = tail;
	
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &var);
		Enquene(var);
	}
	 result = Dequeue();
	printf("%d",result);
}