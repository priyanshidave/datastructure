#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;

void insert_first()
{
	int n;
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter number:");
	scanf("%d",&n);
	new_node->data=n;
	new_node->next=NULL;
	new_node->prev=NULL;
	if(head!=NULL)
	{
		new_node->next=head;
		head->prev=new_node;
		head=new_node;
	}
	else
		head=new_node;
}
void insert_last()
{
	int n;
	struct node *new_node;
	struct node *temp;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter number:");
	scanf("%d",&n);
	new_node->data=n;
	new_node->next=NULL;
	new_node->prev=NULL;
	temp=head;
	if(head==NULL)
		printf("\nList is emtpty");
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new_node;
		new_node->prev=temp;
	}
}
void insert_specific()
{
	int n;
	struct node *new_node;
	struct node *temp;
	int p,cnt=1;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter number:");
	scanf("%d",&n);
	new_node->data=n;
	new_node->next=NULL;
	new_node->prev=NULL;
	printf("\nEnter position:");
	scanf("%d",&p);
	temp=head;
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(cnt!=p)
		{
			temp=temp->next;

			cnt++;
		}
		new_node->next=temp->next;
		temp->next=new_node;
		new_node->prev=temp;
	}
}
void insert()
{
	int ch,inch;
	printf("\n1.Insert First....");
	printf("\n2.Insert Last.....");
	printf("\n3.Insert Specific..");
	printf("\nEnter your choice...");
	scanf("%d",&ch);
	if(ch==1)
		insert_first();
	else if(ch==2)
		insert_last();
	else
		insert_specific();
}
void delete_first()
{
	struct node *temp;
	if(head==NULL)
		printf("\nList is empty");
	else
	{
		temp=head;
		head=head->next;
		head->next->prev=head;
		printf("\nDeleted element is %d",temp->data);
		free(temp);
	}

}
void delete_last()
{
	struct node *temp;
	struct node *prev;
	temp=head;
	if(head==NULL)
		printf("\nList is empty");
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		printf("\nDeleted element is %d",temp->data);
		prev->next=NULL;
		free(temp);
	}
}
void delete()
{
	int ch,inch;
	printf("\n1.Delete First....");
	printf("\n2.Delete Last.....");
	printf("\n3.Delete Specific..");
	printf("\nEnter your choice...");
	scanf("%d",&ch);
	if(ch==1)
		delete_first();
	else if(ch==2)
		delete_last();
	//else
	//	delete_specific();
}
void disp()
{
	struct node *new_node;
	struct node *temp;
	temp=head;
	while(temp)
	{
		printf("\ndata is %d",temp->data);
		temp=temp->next;
	}
}
void write()
{
	int data,i;
	FILE *ptr;
	ptr=fopen("doublylink.txt","w");
	struct node *temp;
	temp=head;
	while(temp)
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
	fptr=fopen("doublylink.txt","r");
	struct node *temp;
	temp=head;
	while(temp)
	{
		fscanf(fptr,"%d",&temp->data);
		temp=temp->next;
	}
	fclose(fptr);
	printf("\nRead successufully");
}
int main()
{
	read();
	int ch,n;
	do
	{
		printf("\n1.Insert..");
		printf("\n2.Delete..");
		printf("\n3:Display");
		printf("\n4:Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
					write();
					break;
			case 2:delete();
					write();
					break;
			case 3:disp();
					break;
			case 4:exit(1);
				   break;
			default:
					break;
		}
	}while(ch!=4);
	return 0;
}
