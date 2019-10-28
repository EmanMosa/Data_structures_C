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

void destroy_tree(node*& leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

node* Search(int key, node* leaf)
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
int max(int a, int b) {
	if (a >= b) 
		return a;

	else return b;
}
int Length(node* root) {
	if (root == NULL) {
		return 0;
	}
	else{ 
			return 1 +max( Length(root->left), Length(root->right));
	
	
	}
}
int minValue(struct node* key) {
	if (key->left == NULL)
		return key->key;
	return minValue(key->left);
	
}
int maxValue(struct node* key) {
	if (key->right == NULL)
		return key->key;
	return maxValue(key->right);

}
void insert(int key, struct node*& tree)
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

node* getParent(int x,node*root) {
	if (root->key == x)
		return NULL;
	if (root->right != NULL && root->right->key == x)
		return root;
	if (root->left != NULL && root->left->key == x)
		return root;
	if (root->left != NULL && root->key > x)
		return getParent(x, root->left);
	if (root->right != NULL && root->key < x)
		return getParent(x, root->right);
}


void printPreorder(struct node* root) {
	
	printf("%d", root->key);

	if (root->left != NULL)
		printPreorder(root->left);
	if (root->right != NULL)
		printPreorder(root->right);


}
void printInorder(struct node* root) {

	if (root->left != NULL)
		printInorder(root->left);
	printf("%d", root->key);
	if (root->right != NULL)
		printInorder(root->right);


}


void printPostorder(struct node* root) {
	
	if (root->left != NULL) 
		printPostorder(root->left);
	if (root->right != NULL)
		printPostorder(root->right);
	printf("%d", root->key);
	
	
	
}



int main() {
	int min;
	int max;
	node* parent;
	tree = NULL;
		insert(6, tree);
		insert(2, tree);
		insert(3, tree);
		insert(5, tree);
		insert(8, tree);
		insert(1, tree);
		min = minValue(tree);
		max = maxValue(tree);
		parent = getParent(5, tree);
		if (parent == NULL)
			printf("the number is root");
		else 
			printf("%d\n", parent->key);
	printInorder(tree);
}