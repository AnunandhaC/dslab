#include<stdio.h>
struct poly
{
	int coeff;
	int exp;
}p[100],q[100],r[100];
int main()
{
	int m,n,i,j,k;
	printf("enter no of terms in 1st poly");
	scanf("%d",&m);
	printf("enter no of terms in 2nd poly");
	scanf("%d",&n);
	printf("enter terms in 1st poly");
	for(i=0;i<m;i++)
	{
		printf("\nenter %dth coeff",i+1);
		scanf("%d",&p[i].coeff);
		printf("\nenter %dth exp",i+1);
		scanf("%d",&p[i].exp);
	}
	printf("\nenter terms in 2nd poly");
        for(j=0;j<n;j++)
        {
                printf("\nenter %d coeff",j+1);
                scanf("%d",&q[j].coeff);
                printf("\nenter %d exp",j+1);
                scanf("%d",&q[j].exp);
        }
i=0,j=0,k=0;
while(i<m&&j<n)
{
	if(p[i].exp==q[j].exp)
	{
		r[k].exp=p[i].exp;
		r[k].coeff=p[i].coeff+q[j].coeff;
		i++,j++,k++;
	}
	else if(p[i].exp>q[j].exp)
	{
		r[k].exp=p[i].exp;
		r[k].coeff=p[i].coeff;
		i++,k++;
	}
	else
	{
		r[k].exp=q[j].exp;
                r[k].coeff=q[j].coeff;
                j++,k++;
	}
}
while(i<m)
{
	 r[k].exp=p[i].exp;
                r[k].coeff=p[i].coeff;
                i++,k++;
}
while(i<n)
{
	 r[k].exp=q[j].exp;
                r[k].coeff=q[j].coeff;
                j++,k++;
}
int x=k;
printf("1st polynomial is ");
for(i=0;i<m;i++)
{
	if(i!=m-1)
		printf("%dx^%d + ",p[i].coeff,p[i].exp);
	else
		 printf("%dx^%d  ",p[i].coeff,p[i].exp);
}
printf("\n2nd poly is ");
for(j=0;j<n;j++)
{
        if(j!=n-1)
                printf("%dx^%d + ",q[j].coeff,q[j].exp);
        else
                 printf("%dx^%d  ",q[j].coeff,q[j].exp);
}
printf("\nresultant poly is ");
for(k=0;k<x;k++)
{
        if(k!=x-1)
                printf("%dx^%d + ",r[k].coeff,r[k].exp);
        else
                 printf("%dx^%d  ",r[k].coeff,r[k].exp);
}
return 0;
}
