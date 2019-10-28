#include "stdio.h"
#include "stdbool.h"
#define _CAR_SECURE_NO_WARNINGS
#include "Math.h"
struct node
{
	int key;
	struct node* left;
	struct node* right;

};
struct node* tree;
struct node* creatNewNode(int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
//void destroy_tree(struct node* leaf)
//{
//	if (leaf != NULL)
//	{
//		destroy_tree(leaf->left);
//		destroy_tree(leaf->right);
//		delete(leaf);
//	}
//}

struct node* Search(int key, struct node* leaf)
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
int Length(struct node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + max(Length(root->left), Length(root->right));


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
struct node* insert(int key, struct node* node)
{
	if (node == NULL)
	{
		return(creatNewNode(key));
	}
	else
	{
		if (key < node->key)
		{
			node->left=insert(key, node->left);
		}
		else if (key >= node->key)
		{
			node->right=insert(key, node->right);
		}
		return node;
	}
}

struct node* getParent(int x, struct node* root) {
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
	if (root != NULL)
	{
		printInorder(root->left);
		printf("%d\t", root->key);
		printInorder(root->right);
	}

}
int maxDepth(struct node* root) {
	return Length(root)-1;
}


void printPostorder(struct node* root) {

	if (root->left != NULL)
		printPostorder(root->left);
	if (root->right != NULL)
		printPostorder(root->right);
	printf("%d", root->key);



}

bool isFullTree(struct node* root) {
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	if (root->left != NULL && root->right == NULL || root->left == NULL && root->right != NULL)
		return false;

	if (root->left != NULL&& root->right != NULL)
			return IsFullTree(root->left)&& IsFullTree(root->right);
	
		
}
//revers and complete for tree
bool isCompleteTree(struct node*root) {
	int leftCounter = 0,rightCounter =0;

	if (root->left!=NULL)
		leftCounter =+ isCompleteTree(root->left);
	if(root->right!=NULL)
		rightCounter=+ isCompleteTree(root->right);
	
	if (leftCounter+ rightCounter == pow(2, (Length(tree)- 1)))
		return true;
	else return false;
}

int main() {
	tree = (struct node*)malloc(sizeof(struct node));

	int min;
	int max;
	bool value;
	struct node* parent;
	tree = NULL;
	tree=insert(6, tree);
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
		printf("parent FOR NODE  5 IS-->%d\n", parent->key);
	printf("max depth FOR the tree IS-->%d\n",maxDepth(tree));
	
	if(isFullTree(tree) ==false )
		printf("Tree Is Full?  false\n" );
	else 
		printf("Tree Is Full?  true\n");
	value = isCompleteTree(tree);
	printInorder(tree);
}