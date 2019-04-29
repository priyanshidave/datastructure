#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;
void equeue(int);
void dqueue();
void disp();
void read();
void write();
int main()
{
	read();
	int ch,value;
	printf("\n1.Equeue");
	printf("\n2.Dqueue");
	printf("\n3.Display");
	printf("\n4.Exit");
	do
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter value:");
					scanf("%d",&value);
					equeue(value);
					write();
					break;
			case 2:dqueue();
					write();
					break;
			case 3:disp();
					break;
			default:
					break;
		}
	}while(ch!=4);
}
void equeue(int x)
{
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=x;
	new_node->next=NULL;
	if(rear==NULL)
		front=rear=new_node;
	else
	{
		rear->next=new_node;
		rear=new_node;	
	}
	printf("\nSuccessfull inserted");
}
void dqueue()
{
	if(front==NULL)
		printf("\nQueue is empty");
	else
	{
		struct node *temp;
		temp=front;
		printf("\nDeleted element is %d",temp->data);
		front=temp->next;
		free(temp);
	}
}
void disp()
{
	if(front==NULL)
		printf("\nQueue is empty");
	else
	{
		struct node *temp;
		temp=front;
		while(temp!=NULL)
		{
			printf("\nElements is %d",temp->data);
			temp=temp->next;
		}
	}	
}
void write()
{
	int data,i;
	FILE *ptr;
	ptr=fopen("queuelink.txt","w");
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		fprintf(ptr,"%d",temp->data);
		temp=temp->next;
	}
	fclose(ptr);
}
void read()
{
	int i;
	FILE *fptr;
	fptr=fopen("queuelink.txt","r");
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		fscanf(fptr,"%d",&temp->data);
		temp=temp->next;
	}
	fclose(fptr);
	printf("\nRead successufully");
}

