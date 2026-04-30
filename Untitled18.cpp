# include<stdio.h>
# include<stdlib.h>
struct Trees
{struct Trees *left;
		int data;
 struct Trees *right;
};
void create()
{
	struct Trees *newnode=0;
	int a;
	printf("\n enter data(-1 for no nodes):");
	scanf("%d",&a);
	if(a==-1)
	{
		return ;
	}
newnode= (struct Tress*)malloc(sizeof(struct Trees));
newnode->data=a;
printf("\n enter left child of %d",a);
newnode->left=create();
printf("\n enter child of %d",a);
newnode->right=create();
printf("\n enter right child of %d",a);
newnode->right = create();
return newnode;
}
int main()
{
	struct trees *root;
	root = create;
	printf("\n preorder traversed of tree:");
	printf(preorder);
	
	
}
void preorder(struct trees *root)
{
	if(root==NULL)
	{
		return ;
	}
	printf("\t %d",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct trees *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("\t %d",root->data);
	inorder(root->right);
}
void postorder(struct trees *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("\t %d",root->data);
}


