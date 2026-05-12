// Binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct binarytree
{
	struct binarytree *left, *right;
	int data;
}bt;
bt *root = NULL;
void preorder(bt *root)
{
	if(root==NULL)
	{
		return;
	}
	printf(" %d",root->data);
	preorder(root->left);
	preorder(root->right);
	return;
}
void inorder(bt *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf(" %d",root->data);
	inorder(root->right);
	return;
}
void postorder(bt *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf(" %d",root->data);
	return;
}
void create_bt()
{
	bt *nn=NULL,*c=NULL;
	int i,n;
	printf("\nEnter the number of nodes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		nn = (bt *)malloc(sizeof(bt));
		printf("\nEnter the data : ");
		scanf("%d",&nn->data);
		nn->left = NULL;
		nn->right = NULL;
		if(i==0)
		{
			root = nn;
		}
		else
		{
			c = root;
			while(1)
			{
				if(nn->data > c->data)
				{
					if(c->right == NULL)
					{
						c->right = nn;
						break;
					}
					else
					{
						c = c->right;
					}
				}
				else if(nn->data < c->data)
				{
					if(c->left == NULL)
					{
						c->left = nn;
						break;
					}
					else
					{
						c = c->left;
					}
				}
				else
				{
					printf("\nDuplicates not allowed.......!!!");
					free(nn);
					break;
				}
			}
		}
	}
	return;
}
int main()
{
	create_bt();
	printf("\nThe created Binary Search tree in Inorder : \n");
	inorder(root);
	printf("\nThe created Binary Search tree in Preorder : \n");
	preorder(root);
	printf("\nThe created Binary Search tree in Postorder : \n");
	postorder(root);
	return 0;
}
