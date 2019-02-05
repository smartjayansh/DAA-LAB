#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* newNode(int dat)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = dat;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void display(struct node* root)
{
	struct node* temp = root;
	if(root==NULL)
		return;
	cout<<(root->data)<<endl;
	display(root->left);
	display(root->right);
}
int main()
{
	struct node* root = NULL;
	int i=5,a;
	root = newNode(4);
	root = newNode(4);
	root = newNode(4);
	root = newNode(4);
	root = newNode(4);
	root = newNode(4);
	root = newNode(4);
	
	display(root);	
return 0;
}
