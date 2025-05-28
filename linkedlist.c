#include<stdio.h>
int pos,count=0,item;
struct node
{
	int data;
	struct node*link;
};
struct node*new,*temp,*head;
void main()
{
	head=0;
	int n;
	char choice='y';
	while(choice=='y'||choice=='Y')
	{
		printf("enter your choice\n1 insert at beg\n2 insert at end\n3 insert at specific\n4 delete at beg\n5 delete at end\n6 delete at specific\n7 display");
		scanf("%d",&n);
		switch(n)
		{
			case 1:insertbeg(item);
				break;
			case 2:insertend(item);
				break;
			case 3:insertspecific(item);
				break;
			case 4:deletebeg();
				break;
			case 5:deleteend();
				break;
			case 6:deletespecific();
				break;
			case 7:display();
				break;
			default:printf("invalid choice");
		}
		printf("do you want to continue(y/n)");
		scanf(" %c",&choice);

	}
}

void insertbeg(int item)
{
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
		printf("memory underflow");
	else
	{
		printf("enter item");
		scanf("%d",&new->data);
		new->link=head;
		head=new;
		count++;
	}
}

void insertend(int item)
{
	temp=head;
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
		printf("memory underflow");
	else
	{
		printf("enter item");
		scanf("%d",&new->data);
		new->link=0;
		if(head==0)
		{
			head=new;
		}
		else
		{
			while(temp->link!=0)
			{
				temp=temp->link;
			}
			temp->link=new;
		}
		count++;
	}
} 

void insertspecific(int item)
{
	int i=1;
	printf("enter position");
	scanf("%d",&pos);
	if(pos>count+1)
		printf("invalid");
	else
	{
		temp=head;
		while(i<pos-1)
		{
			temp=temp->link;
			i++;
		}
		new=(struct node*)malloc(sizeof(struct node));
		if(new==NULL)
			printf("memory underflow");
		else
		{
			printf("enter item");
			scanf("%d",&new->data);
			new->link=temp->link;
			temp->link=new;
		}
		count++;
	}
}

void deletebeg()
{
	if(head==NULL)
		printf("list empty");
	else
	{
		temp=head;
		head=temp->link;
		printf("deleted %d",temp->data);
		free(temp);
		count--;
	}
}

void deleteend()
{
	struct node*prev;
	if(head==NULL)
		printf("list empty");
	else
	{
		temp=head;
		while(temp->link!=0)
		{
			prev=temp;
			temp=temp->link;
		}
		if(head==temp)
		{
			head=0;
			printf("deleted %d",temp->data);
			free(temp);
		}
		else
		{
			prev->link=0;
			printf("deleted %d",temp->data);
			free(temp);
		}
		count--;
	}
}

void deletespecific()
{
	struct node*next;
	int i=1;
	if(head==0)
	{
		printf("list empty");
	}
	temp=head;	
	printf("enter position");
	scanf("%d",&pos);
	if(pos>count)
		printf("invalid");
	while(i<pos-1)
	{
		temp=temp->link;
		i++;
	}
	next=temp->link;
	temp->link=next->link;
	printf("deleted %d",next->data);
	free(next);
	count--;
}
void display()
{
	if(head==0)
	{
		printf("empty");
	}
		temp=head;
		while(temp!=0)
		{
			printf("%d\t",temp->data);
			temp=temp->link;
		}
		getch();
}
