#include<stdio.h>
int main()
{
	int key,a[10],n,i;
	int l=0;
	int h;
	printf("enter size");
	scanf("%d",&n);
	h=n-1;
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter key");
	scanf("%d",&key);
	while(l<=h)
	{
		int m=(l+h)/2;
		if(a[m]==key)
		{
			printf("found at %d position",m+1);
			break;
		}
		else if(a[m]<key)
		{
			l=m+1;
		}
		else
		{
			h=m-1;
		}
	}
	if(l>h)
	printf("not found");
}
