#include<stdio.h>
#define N 25
struct pq
{
	int item,priority;
}pq[N];
int r=-1;
int f=-1;
void main()
{
	int item,priority;
        int n;
        char choice='y';
        while(choice=='y'||choice=='Y')
        {
                printf("1 for enqueue\n2 for dequeue\n3 for display");
                scanf("%d",&n);
                switch(n)
                {
                        case 1:printf("enter item and priority");
				scanf("%d%d",&item,&priority);
				enqueue(item,priority);
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

void enqueue(int ITEM,int PRIORITY)
{
	int i,loc;
	if(f==0&&r==N-1)
	printf("q full");
	else if(f==-1)
	{
		f=r=0;
		pq[r].item=ITEM;
		pq[r].priority=PRIORITY;
	}
	else
	{ 
		if(r==N-1)
		{
			for(i=f;i<=r;i++)
			{
				pq[i-1]=pq[i];
				f--;
				r--;
			}
		}
		for(i=r;i>=f;i--)
		{
			if(pq[i].priority<PRIORITY)
			{
				break;
			}
		}
		loc=i+1;
		for(i=r;i>=loc;i--)
		{
			pq[i+1]=pq[i];
		}
		pq[loc].item=ITEM;
		pq[loc].priority=PRIORITY;
		r++;
	}
}

void dequeue()
{
	if(f==-1)
	printf("q empty");
	else if(f==r)
	{
		printf("deleted %d",pq[f].item);
		f=r=-1;
	}
	else
	{
		printf("deleted %d",pq[f].item);
		f++;
	}
}

void display()
{
	if(f==-1)
	printf("q empty");
	else
	{
		for(int i=f;i<=r;i++)
		{
			printf("%d\t",pq[i].item);
		}
	}
}
 
