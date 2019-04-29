
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void create(struct node **);
void dup_delete(struct node **);
void release(struct node **);
void display(struct node *);
void read(struct node *);
void write(struct node *);
int main()
{
    struct node *p = NULL;
    struct node_occur *head = NULL;
 	read(&p);
    int n;
    printf("Enter data into the list\n");
    create(&p);
    write(&p);
    printf("Displaying the nodes in the list:\n");
    display(p);
    printf("Deleting duplicate elements in the list...\n");
    dup_delete(&p);
    printf("Displaying non-deleted nodes in the list:\n");
    display(p);
    release(&p);

    return 0;
}

void dup_delete(struct node **head)
{
    struct node *p, *q, *prev, *temp;

    p = q = prev = *head;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->num != p->num)
        {
            prev = q;
            q = q->next;
        }
        if(q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        else if (q->num == p->num)
        {
            prev->next = q->next;
            temp = q;
            q = q->next;
            free(temp);
        }
    }
}

void create(struct node **head)
{
    int c, ch;
    struct node *temp, *rear;

    do
    {
        printf("Enter number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->num);
        p = p->next;
    }
    printf("\n");
}
void write(struct node *p)
{
	int data,i;
	FILE *ptr;
	ptr=fopen("sortlink.txt","w");
	while (p != NULL)
    {
        fprintf(ptr,"%d\t", p->num);
        p = p->next;
    }
	fclose(ptr);
}
void read(struct node *p)
{
	int i;
	FILE *fptr;
	fptr=fopen("sortlink.txt","r");
	while (p != NULL)
    {
        fscanf(fptr,"%d\t", &p->num);
        p = p->next;
    }
	fclose(fptr);
	printf("\nRead successufully");
}
void release(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}
