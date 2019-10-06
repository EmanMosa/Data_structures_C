#include "stdio.h"
#define _CAR_SECURE_NO_WARNINGS

struct node
{
	int data;
	struct node* next;
};
struct node* head;
struct node* tail;
struct node* insertToTail(int num);
struct node* insertNodeToIndex(int node, int index) {
	struct node* in = (struct node*)malloc(sizeof(struct node));
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	struct node* after = (struct node*)malloc(sizeof(struct node));

	int i = index;
	tmp = head;
	in->data = node;

	while (tmp != NULL && i > 0)
	{
		after = tmp;
		if (i == 2 && tmp->next != NULL) {

			in->next = after->next;
			tmp->next = in;
			head = tmp;
			break;

		}
		else if (tmp->next == NULL && i == 2) {
			return insertToTail(node);
		}
		tmp = tmp->next;

		i--;


	}
	return head;
}
struct node* insertToTail(int num) {
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
struct node* insertToHead(int num) {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));

	tmp->data = num;
	tmp->next = head;
	head = tmp;

	return head;


}
void printList() {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp = head;
	while (tmp != NULL)
	{

		printf("%d    ", tmp->data);
		tmp = tmp->next;
	}

}
struct node* DeleteIndex(int index) {

	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	struct node* after = (struct node*)malloc(sizeof(struct node));
	struct node* befor = (struct node*)malloc(sizeof(struct node));

	int i = index;
	tmp = head;


	while (tmp != NULL && i > 0)
	{
		after = tmp->next;
		if (i == 2 && tmp->next != NULL) {

			tmp->next = after->next;
			head = tmp;
			break;

		}

		tmp = tmp->next;

		i--;


	}
	return head;
}
void main() {

	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* tail = (struct node*)malloc(sizeof(struct node));
	head = tail;
	int num;
	int node;
	printf("how mony node do you want :");
	scanf_s("%d", &num);
	for (int i = 1; i <= num; i++) {
		printf("enter the node number %d :     ", i);
		scanf_s("%d", &node);
		//head=insertToHead(node);
		head = insertToTail(node);
	}
	head = insertNodeToIndex(5, 2);
	head = insertNodeToIndex(5, 3);
	/*head = insertNodeToIndex(5, 6);
	head = insertNodeToIndex(5,8);
	head = insertNodeToIndex(5, 10);*/
	head = DeleteIndex(2);
	head = DeleteIndex(5);

	printList();


}
