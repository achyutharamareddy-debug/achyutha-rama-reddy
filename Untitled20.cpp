// Binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct binarytree
{
	struct binarytree *left, *right;
	int data;
}bt;
bt *root;
int main()
{
	bt *nn=0,*c=0;
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
}
