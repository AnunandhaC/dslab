#include<stdio.h>
#define N 5
int item;
int top=-1;
int s[N];
void main()
{
	int n;
	char choice='y';
	while(choice=='y'||choice=='Y')
	{
		printf("enter your choice\n1 for push\n2 for pop\n3 for display");
		scanf("%d",&n);
		switch(n)
		{
			case 1:push(item);
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			default:printf("invalid choice");
		}
		printf("do you want to continue(y/n)");
		scanf(" %c",&choice);
	}
}

void push(int item)
{
	if(top==N-1)
	{
		printf("stack full");
	}
	else
	{
		printf("enter element");
		scanf("%d",&item);
		top++;
		s[top]=item;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("stack empty");
	}
	else
	{
		printf("deleted %d",s[top]);
		item=s[top];
		top--;
		return item;
	}
}

void display()
{
	if(top==-1)
	{
		printf("stack empty");
	}
	printf("stack is ");
	for(int i=top;i>=0;i--)
	{
		printf("%d\t",s[i]);
	}
}
