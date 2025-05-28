#include<stdio.h>
#define N 5
int dq[N];
int r=-1;
int f=-1;
int item;
void main()
{
	int n;
	char choice='y';
	while(choice=='y'||choice=='Y')
	{
		printf("1 for enqueue at front\n2 for enqueue at rear\n3 for dequeue at front\n4 for dequeue at rear\n5 for display");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("enter element");
        			scanf("%d",&item);
				enq_front(item);
				break;
			case 2: printf("enter element");
                                scanf("%d",&item);
                                enq_rear(item);
				break;
			case 3:deq_front();
				break;
	                case 4:deq_rear();
				break;
			case 5:display();
				break; 
			default:printf("invalid choice");
		
		}
		 printf("do you want to continue(y/n)");
                 scanf(" %c",&choice);
	}
}

void enq_front(int item)
{
	if((f==0&&r==N-1)||(f==r+1))
	{
	printf("q full");
	}
	else if(f==-1)
		{
			f=r=0;
			dq[f]=item;
		}
	else if(f>0)
	{
		f--;
		dq[f]=item;
	}
	else
	{
		for(int i=r;i>=f;i--)
		{
			dq[i+1]=dq[i];
		}
		dq[f]=item;
		r=r+1;
	}
}

void enq_rear(int item)
{
	 if(f==0&&r==N-1)
        {
        printf("q full");
        }
        else if(f==r==-1)
                {
                        f=r=0;
                        dq[r]=item;
                }
	else if(r<N-1)
	{
		r++;
		dq[r]=item;
	}
	else
	{
		for(int i=f;i<=r;i++)
		{
			dq[i-1]=dq[i];
		}
		f--;
		dq[r]=item;
	}
}		
	
int deq_front()
{
	if(f==r==-1)
	printf("q empty");
	else if(f==r)
	{
		printf("deleted %d",dq[f]);
		item=dq[f];
		f=r=-1;
		return item;
	}
	else
	{
		 printf("deleted %d",dq[f]);
		item=dq[f];
		f++;
		return item;
	}
}

int deq_rear()
{
	
        if(f==r==-1)
        printf("q empty");
        else if(f==r)
        {
                printf("deleted %d",dq[r]);
		item=dq[r];
                f=r=-1;
		return item;
        }
         else
        {
                 printf("deleted %d",dq[r]);
		item=dq[r];
                r--;
		return item;
        }
}

void display()
{
	if(f==r==-1)
	printf("q empty");
	else
	{
		for(int i=f;i<=r;i++)
		{
			printf("%d\t",dq[i]);
		}
	}
}

