#include "stdio.h"
#include "stdbool.h"
#define _CAR_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdbool.h"
#define _CAR_SECURE_NO_WARNINGS
struct Task
{
	int key;
	char* name;
	char* status;
	struct Task* left;
	struct Task* right;


};
struct Task* creatNewNode(int key,char*name,char* status)
{
	struct Task* node = (struct Task*)malloc(sizeof(struct Task));
	node->key = key;
	node->name = name;
	node->status = status;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
struct Task* insert(int key, struct Task* node,char*name, char*status)
{
	if (node == NULL)
	{
		return(creatNewNode(key,name,status));
	}
	else
	{
		if (key < node->key)
		{
			node->left=insert(key, node->left,name,status);
		}
		else if (key >= node->key)
		{
			node->right=insert(key, node->right,name, status);
		}
		return node;

	}
}
struct Task* Search(int key, struct Task* leaf)
	{
		if (leaf != NULL)
		{
			if (key == leaf->key)
				return leaf;
			if (key < leaf->key)
				return Search(key, leaf->left);
			else
				return Search(key, leaf->right);
		}
		else return NULL;
	}
struct Task* Update(int key,struct Task *root) {
	struct Task* keyNode = Search(key, root);
	keyNode->status = "completed";
	return root;
}
//not completed
int FindDiff(struct Task* root) {
	int counter = 0;
	int counter1 = 0;
	if (root == NULL) {
		return;
	}
	return FindDiff(root->right);
	return FindDiff(root->left);
	if (root->status == "not completed")
		 counter++;
	else
		 counter1++;
	return counter - counter1;
}
struct Task *tasks;
int id = 4124;
int main() {
	
	char* status = "not completed";
	tasks = insert(id, tasks, "Task1", status);
	id++;

	tasks = insert(id, tasks, "Task2", status);
	id++;

	tasks = insert(id, tasks, "Task3", status);
	id++;

	tasks = insert(id, tasks, "Task4", status);
	id++;
	printf("%d", FindDiff(tasks));


	
	
}