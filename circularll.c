#include<stdio.h>
int item;
struct node
{
	int data;
	struct node*link;
};
struct node*head,*temp,*new;
void main()
{
        int n;
	head=0;
        char choice='y';
        while(choice=='y'||choice=='Y')
        {
                printf("1 for enqueue\n2 for dequeue\n3 for display");
                scanf("%d",&n);
                switch(n)
                {
                        case 1:enqueue(item);
                                break;
                        case 2:dequeue();
                                break;
                        case 3:display();
                                break;
                        default:printf("invalid choice");
                }
                printf("do u want to continue(y/n)");
                scanf(" %c",&choice);
        }
}
void enqueue(int item)
{
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
		printf("memory underflow");
	else
	{
		printf("enter element");
		scanf("%d",&new->data);
		if(head==0)
		{
			head=new;
			new->link=head;
		}
		else
		{
        		temp=head;
        		while(temp->link!=head)
        		{
                		temp=temp->link;
        		}

			temp->link=new;
			new->link=head;
		}
	}
}

void dequeue()
{
	struct node*tail;
	if(head==0)
		printf("q empty");
	else
	{
		temp=head;
		if(head->link==head)
		{
			head=0;
			printf("deleted %d",&temp->data);
			free(temp);
		}
		else
		{
			tail=head;
			while(tail->link!=head)
			{
				tail=tail->link;
			}
			printf("deleted %d",temp->data);
			head=head->link;
			tail->link=head;
			free(temp);
		}
	}
}

void display()
{
	if(head==0)
	{
		printf("q empty");
	}
	else
	{
		temp=head;
		while(temp->link!=head)
		{
			printf("%d\t",temp->data);
			temp=temp->link;
		}
		printf("%d\t",temp->data);
	}
}
