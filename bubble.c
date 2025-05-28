#include<stdio.h>
void main()
{
	int arr[10],i,j,n,temp;
	printf("enter size");
	scanf("%d",&n);
	printf("enter numbers");
	{
		for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("sorted array is");
	for(i=0;i<n;i++)
	printf("%d",arr[i]);
}
