#include<stdio.h>
int a[100][100],b[100][100],s1[100][3],s2[100][3],t1[100][3],t2[100][3];
int s[100][3],t[100][3];
int i,j,k;
int main()
{
	int m1,n1,m2,n2;
	printf("enter rows and columns of 1st matrix");
	scanf("%d%d",&m1,&n1);
	printf("enter rows and columns of 2nd matrix");
	scanf("%d%d",&m2,&n2);
	printf("enter elements of first matrix");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
		{
			printf("enter element of %dth row and %dth column",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	 printf("enter elements of second matrix");
        for(i=0;i<m2;i++)
        {
                for(j=0;j<n2;j++)
                {
                        printf("enter element of %dth row and %dth column",i+1,j+1);
                        scanf("%d",&b[i][j]);
                }
        }
	printf("tuple form of 1st matrix\n");
	tuple(a,m1,n1,s1);
	printf("transpose of 1st matrix\n");
	transpose(s1,t1);
	printf("tuple form of 2nd matrix\n");
	tuple(b,m2,n2,s2);
	//printf("transpose of 2nd matrix\n");
	//transpose(s1);
}

void tuple(int c[100][100],int m,int n,int s[][3])
{
	//int s[100][100];
	s[0][0]=m;
	s[0][1]=n;
	k=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(c[i][j]!=0)
			{
				s[k][0]=i;
				s[k][1]=j;
				s[k][2]=c[i][j];
				k++;
			}
		}
	}
	s[0][2]=k-1;
	for(i=0;i<k;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",s[i][j]);
		}
		printf("\n");
	}
}

void transpose(int s[100][3],t[100][3])
{
	int m,n,i,j;
	//int t[100][100];
	t[0][0]=s[0][1];
	t[0][1]=s[0][0];
	t[0][2]=s[0][2];
	k=1;
	m=s[0][1];
	n=s[0][2];
	for(i=0;i<=s[0][1];i++)
	{
		for(j=1;j<=s[0][2];j++)
		{
			if(s[j][1]==i)
			{
				t[k][0]=s[j][1];
				t[k][1]=s[j][0];
				t[0][2]=s[0][2];
				k++;
			}
		}
	}
	for(i=0;i<=k;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}
