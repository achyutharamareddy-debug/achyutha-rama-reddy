#include<stdio.h>
#include<stdlib.h>
struct trees{
	struct trees *left,*right;
	int data;
};
struct trees* create()
	
	{
	struct trees *newnode=0;
	int a;
	printf("\n enter data value(-1 for no nodes):");
	scanf("%d",&a);
	if(a==-1){
		return NULL;
	}
	newnode=(struct trees*)malloc(sizeof(struct trees));
	newnode->data=a;
	printf("\n enter left child of %d:",a);
	newnode->left=create();
	printf("\n enter right child of %d:",a);
	newnode->right=create();
	return newnode;
}

void preorder(struct trees *root){
	if (root == NULL){
		return ;
	}
	printf("\n%d",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct trees *root){
	if (root == NULL){
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	printf("\n%d",root->data);
}

void inorder(struct trees *root){
	if (root == NULL){
		return ;
	}
	
	inorder(root->left);
	printf("\n%d",root->data);
	inorder(root->right);
}
int main(){
	struct trees *root;
	root = create();
	preorder(root);
	postorder(root);
	inorder(root);
	
}
