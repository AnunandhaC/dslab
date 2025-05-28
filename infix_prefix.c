#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define N 50
char a[N],p[N],s[N];
int s1[N];
int top=-1,top1=-1;
char item;
int precedence(char c)
{
	switch(c)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3;
	}
}

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

void infix_prefix()
{
	int i=0,j=0;
	char x,y;
	strrev(a);
	while(a[i]!='\0')
	{
		if(isdigit(a[i]))
			p[j++]=a[i];
		else if(a[i]==')')
			push(a[i]);
		else if(a[i]=='(')
		{
			while(s[top]!=')')
			{
				p[j++]=pop();
			}
			top--;
		}
		else
		{
			x=a[i];
			y=s[top];
			if(top==-1||y==')'||precedence(y)<=precedence(x))
				push(a[i]);
			else
			{
				while(top!=-1&&y!=')'&&precedence(x)<precedence(y))
				{
					p[j++]=pop();
					y=s[top];
				}
				push(x);
			}
		}
		i++;
	}
	while(top!=-1)
	{
		p[j++]=pop();
	}
	p[j]='\0';
	strrev(p);
	printf("prefix expression is %s",p);
}

void prefixeval()
{
	int i,result,op1,op2;
	char str[50];
	for(i=strlen(p)-1;i>=0;i--)
	{
		if(isdigit(p[i]))
		{
			str[0]=p[i];
			str[1]='\0';
			s1[++top1]=atoi(str);
		}
		else
		{
			op1=s1[top1--];
			op2=s1[top1--];
			switch(p[i])
			{
				case '+':result=op1+op2;
					break;
				case '-':result=op1-op2;
					break;
				case '*':result=op1*op2;
					break;
				case '/':result=op1/op2;
					break;
				case '^':result=pow(op1,op2);
			}
			s1[++top1]=result;
		}
	}
	printf("result is %d",s1[0]);
}

void main()
{
	printf("enter expression");
	gets(a);
	infix_prefix();
	prefixeval();
}
