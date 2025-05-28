#include<string.h>
#include<stdio.h>
#define N 100
int s[N],i,count=0,top=-1;
char item;
void push(char item)
{
        top++;
        s[top]=item;
}
char pop()
{
        item=s[top];
        top--;
        return item;
}
int main()
{
	char str[100];
	printf("enter string");
	scanf("%[^\n]",&str);
	int l=strlen(str);
	for(i=0;str[i]!='\0';i++)
	{
		push(str[i]);
	}
	for(i=0;i<l;i++)
	{
		if(str[i]==pop())
		{
			count++;
		}
	}
	if(count==l)
	{
		printf("it is palindrome");
	}
	else
	{
		printf("not palindrome");
	}
}

