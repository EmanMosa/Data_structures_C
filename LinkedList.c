#include "stdio.h"
#define _CAR_SECURE_NO_WARNINGS

struct node
{
	int data;
	struct node* next;
};
struct node* head;
struct node* tail;
struct node* Append(int num);
struct node*  InsertAtHead(int);
struct node* InsertAtPosition(int num, int index);
void Print();
struct node* DeleteAtPosition(int index);

struct node* InsertAtPosition(int num, int index) {
	int count = 0;
	struct node* pointer = head;
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = num;
	tmp->next = NULL;
	if (index == 0) {
		head = insertToHead(num);

	}
	else
	{
		while (count!=(index-1))
		{
			pointer = pointer->next;
			count++;

		}
		tmp->next = pointer->next;
		pointer->next = tmp;
	}
	head = pointer;
	return head;
}
struct node* Append(int num) {
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

	return head;


}
struct node* InsertAtHead( int num) {
	struct node* tmp=(struct node*)malloc(sizeof(struct node));

	tmp->data = num;
	tmp->next = head;
	head= tmp;

	return head;


}
void Print() {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp = head;
	while (tmp!=NULL)
	{
		
		printf("%d    ", tmp->data);
		tmp = tmp->next;
	}

}
struct node* DeleteAtPosition(int index) {

	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	struct node* after = (struct node*)malloc(sizeof(struct node));
	struct node* befor = (struct node*)malloc(sizeof(struct node));

	int i = index;
	tmp = head;
	

	while (tmp != NULL && i > 0)
	{	
		after = tmp->next;
		if (i == 2 && tmp->next != NULL) {

			tmp->next =after->next;
			head = tmp;
			break;

		}
		
		tmp = tmp->next;

		i--;


	}
	return head;
}

