#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
 
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
 
void main()
{
//	read();
	FILE *ptr;
    int i, ch;
    char s[MAX], b;
    do
    {
        printf("\n1-Enter string....");
        printf("\n2-Exit....");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        	case 1:
        		ptr=fopen("palindrome.txt","w");
            	printf("Enter the String\n");
            	scanf("%s", s);
            	for (i = 0;s[i] != '\0';i++)
            	{
                	b = s[i];
                	push(b);
            	}
            	for (i = 0;i < (strlen(s) / 2);i++)
            	{
                	if (stack[top] == stack[front])
                	{
                    	pop();
                    	front++;
                	}
                	else
                	{
                    	printf("%s is not a palindrome\n", s);
                    	fprintf(ptr,"%s is not palindrome",s);
                    	break; 
                	}
            	}		
            	
            	if ((strlen(s) / 2)  ==  front)
            	{
                	printf("%s is palindrome\n",  s);
                	fprintf(ptr,"%s is palindrome",s);
            	}
            	front  =  0;
            	top  =  -1;
            	fclose(ptr);
            	//write();
            	break;
        	case 2:
            	exit(0);
        	default:
            	printf("enter correct choice\n");
        }	
    }while(ch!=3);
}

void push(char a)
{
    top++;
    stack[top]  =  a;
}
void pop()
{
    top--;
}
