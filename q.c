#include<stdio.h>
#define N 5
int q[N];
int r=-1;
int f=-1;
int item;
void main()
{
	int n;
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
	if(r==N-1)
	printf("q full");
	else
	{
		printf("enter element");
		scanf("%d",&item);
		if(f==-1)
		{
			f=0;	
		}
		r=r+1;
		q[r]=item;
	}
}

int dequeue()
{
	if(f==r==-1)
	printf("q empty");
	else
	{
		q[f]=item;
		 f=f+1;
		 if(f==r+1)
                {
                        f=r=-1;
                }
		return item;
	}
}

void display()
{
	if(f==-1)
	printf("q empty");
	else
	{
		printf("q is");
		for(int i=f;i<=r;i++)
		printf("%d\t",q[i]);
	}
}
