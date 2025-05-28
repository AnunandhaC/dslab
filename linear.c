#include<stdio.h>
int main()
{
	int a[10];
	int key,n,i;
	printf("enter size");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter search key");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			printf("found at %d position",i+1);
			break;
		}
	}
	if(i==n)
	{
		printf("not found");
	}
}
