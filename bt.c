#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*lchild;
	struct node*rchild;
};
struct node*temp,*new;
struct node*root=NULL;
void insert(int data)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->lchild=NULL;
	new->rchild=NULL;
	if(root==NULL)
	{
		root=new;
		return;
	}
	struct node*q[100];
	int f=0,r=0;
	q[r++]=root;
	while(f<r)
	{
		temp=q[f++];
		if(temp->lchild==NULL)
		{
			temp->lchild=new;
			return;
		}
		else
		{
			q[r++]=temp->lchild;
		}
		if(temp->rchild==NULL)
		{
			temp->rchild=new;
			return;
		}
		else
		{
			q[r++]=temp->rchild;
		}
	}
}

void inorder(struct node*root)
{
	if(root==NULL)return;
	inorder(root->lchild);
	printf("%d",root->data);
	inorder(root->rchild);
}
void preorder(struct node*root)
{
	if(root==NULL)return;
	printf("%d",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(struct node*root)
{
	if(root==NULL)return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d",root->data);
}
int main()
{
	int data,n;
	char choice='y';
	while(choice=='y'||choice=='Y')
	{
		printf("enter your choice\n1 insert\n2 inorder\n3 preorder\n4 postorder");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("enter data");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:inorder(root);
				break;
			case 3:preorder(root);
				break;
			case 4:postorder(root);
				break;
		}
		printf("do u want to continue(y/n)");
		scanf(" %c",&choice);
	}
}
