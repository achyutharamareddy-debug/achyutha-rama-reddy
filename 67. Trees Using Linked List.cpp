#include<stdio.h>
#include<stdlib.h>
struct trees
{
	struct trees *left;
	int data;
	struct trees *right;
};
struct trees *create()
{
	struct trees *newnode = 0;
	int a;
	printf("\nEnter the data ('-1' means no further child's') : ");
	scanf("%d",&a);
	if(a ==-1)
	{
		return 0;
	}
	newnode = (struct trees *)malloc(sizeof(struct trees));
	newnode->data = a;
	printf("\nEnter the left child of %d : ",a);
	newnode->left = create();
	printf("\nEnter the right child od %d : ",a);
	newnode->right = create();
	return newnode;
}
void preorder(struct trees *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("\t%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct trees *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("\t%d",root->data);
	inorder(root->right);
}
void postorder(struct trees *root)
{
	if(root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("\t%d",root->data);
}
int main()
{
	struct trees *root;
	root = create();
	printf("\nThe Preorder traversal of the Tree : ");
	preorder(root);
	printf("\nThe Inorder traversal of the Tree : ");
	inorder(root);
	printf("\nThe Postorder traversal of the Tree : ");
	postorder(root);
	return 0;
}
