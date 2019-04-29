#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int top = -1;
char stack[100];
void push(char);
void pop();
void find_top();
 
void main()
{
	int i;
	char a[100];
	printf("enter expression\n");
	scanf("%s", &a);
	for (i = 0; a[i] != '\0';i++)
	{
		if (a[i] == '(')
		{
			push(a[i]);
		}
		else if (a[i] == ')')
		{
			pop();
		}
	}
	find_top();
}
void push(char a)
{
	stack[top] = a;
	top++;
}
void pop()
{
	top--;
}
void find_top()
{
	FILE *ptr;
	ptr=fopen("expression.txt","w");
	if (top == -1)
	{
		printf("\nexpression is valid\n",top);
		fprintf(ptr,"expression is valid");
	}
	else
	{
		printf("\nexpression is invalid\n");
		fprintf(ptr,"expression is invalid");
	}
	fclose(ptr);
}
