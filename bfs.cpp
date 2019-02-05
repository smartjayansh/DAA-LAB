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
struct node* insert(struct node* root,int data)
{
	if(root==NULL)
	{
		root = newNode(data);
		return root;
	}
	else if(data > root->data)
	{
		root->right = insert(root->right,data);
		return root;
	}
	else
	{
		root->left = insert(root->left,data);
		return root;
	}

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
	do{
        cout << "enter a number into the tree plz.. ";
        cin >> a;
        root = insert(root, a);
        i--;
    }
    while( i != 0);
	display(root);	
return 0;
}
