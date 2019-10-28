#include "stdio.h"
#include "stdbool.h"
#define _CAR_SECURE_NO_WARNINGS

struct node
{
	int key;
	struct node* left;
	struct node* right;

};
struct node* tree;
int MinNodeInTree(struct node* key) {
	if (key == NULL)
		return;
	return MinNodeInTree(key->left);
	
}

void insert(int key, struct node& tree)
{
	if (tree == NULL)
	{
		tree = new node;
		tree->key= key;
		tree->left = NULL;
		tree->right = NULL;
	}
	else
	{
		if (key < tree->key)
		{
			insert(key, tree->left);
		}
		else if (key >= tree->key)
		{
			insert(key, tree->right);
		}
	}
}






void PrintTree(struct node* root) {
	
	if (root->left != NULL) 
		PrintTree(root->left);
	printf("%d", root->key);
	if (root->right != NULL)
		PrintTree(root->right);
	
	
}



int main() {
	tree = NULL;
		insert(1, tree);
		insert(7, tree);
		insert(9, tree);
		insert(4, tree);
		insert(4, tree);
		insert(4, tree);
	PrintTree(tree);
}