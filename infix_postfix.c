#include<ctype.h>
#include<string.h>
#include<math.h>
#define N 50
#include<stdio.h>
char a[N],p[N],s[N];
int s1[N];
int top=-1,top1=-1;
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
void main()
{
	printf("enter expression");
	gets(a);
	infixtopostfix();
	postfixeval();
}

int precedence(char c)
{
	switch(c)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case'^':return 3;
	}
}

void infixtopostfix()
{
	char x,y;
	int i=0,j=0;
	while(a[i]!='\0')
	{
		if(isdigit(a[i]))
			p[j++]=a[i];
		else if(a[i]=='(')
			push(a[i]);
		else if(a[i]==')')
		{
			while(s[top]!='(')
			{
				p[j++]=pop();
			}
			top--;
		}
		else
		{
			x=a[i];
			y=s[top];
			if(top==-1||y=='('||precedence(y)<precedence(x))
				push(a[i]);
			else
			{
				while(top!=-1&&y!='('&&precedence(x)<=precedence(y))
				{
					p[j++]=pop();
					y=s[top];
				}
				s[++top]=x;
			}
		}
		i++;
	}
	while(top!=-1)
	{
		p[j++]=pop();
	}
	p[j]='\0';
	printf("postfix expression is %s",p);
	
}

void postfixeval()
{
	int i,op1,op2,result;
	char str[N];
	for(i=0;i<strlen(p);i++)
	{
		if(isdigit(p[i]))
		{
			str[0]=p[i];
			str[1]='\0';
			s1[++top1]=atoi(str);
		}
		else
		{
			op2=s1[top1--];
			op1=s1[top1--];
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
	printf("\nresult is %d",s1[0]);
}
