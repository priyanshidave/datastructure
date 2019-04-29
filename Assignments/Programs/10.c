#include<stdio.h>
#include<conio.h>
#define size 5
int stack[size];
int top=-1;
void push();
void display();
void isEmpty();
void pop();

void update();
int main()
{
	read();
    int ch;
    printf("\n1) push operation");
    printf("\n2) pop operation");
    printf("\n3) peep operation");
    printf("\n4) update operation");
    printf("\n5) isEmpty operation");
    printf("\n6) exit");
    do
    {


    printf("\n enter your choice=");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            push();
            write();
            break;
        case 2:
            pop();
            write();
            break;
        case 3:
            peep();
            break;
        case 4:
            update();
            write();
            break;
        case 5:
            isEmpty();
            break;
        default:
            return 0;
            break;

    }
    }while(ch!=5);
}
void write()
{
	int data,i;
	FILE *ptr;
	ptr=fopen("stack.txt","w");
	for(i=top;i>=0;i--)
		fprintf(ptr,"%d\t",stack[i]);
	fclose(ptr);
}
void read()
{
	int i;
	FILE *fptr;
	fptr=fopen("stack.txt","r");
	for(i=top;i>=0;i--)
		fscanf(fptr,"%d\t",&stack[i]);
	fclose(fptr);
	
}
void push()
{
    int data;
    if(top>=size-1)
    {
        printf("\n stack is overflow");
    }
    else
    {
       	printf("\Enter an element=");
		scanf("%d",&data);
        top++;
        stack[top]=data;

    }
}


void peep()
{
    int i;
    if(top==-1)
    {
        printf("\n stack is underflow");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n %d",stack[i]);

        }
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\n stack is underflow");

    }
    else
    {
        printf("\n popped element is=%d",stack[top]);
        stack[top--];
    }
}


void update()
{
    int u,n;
    if(top==-1)
    {
        printf("\n stack is underflow");
    }
    else
    {
        printf("\n enter position  at you want to change=");
        scanf("%d",&u);
        printf("\n enter new element= ");
        scanf("%d",&n);
        stack[u]=n;

    }
}

void isEmpty()
{
    if(top==-1)
    {
        printf("\n stack is empty");
    }
    else
    {
        printf("\n stack is not empty");
    }
}
