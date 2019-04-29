#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree *root=NULL;
struct tree *create_tree(struct tree *info,int no)
{
	if(info==NULL)
	{
		info=(struct tree *)malloc(sizeof(struct tree));
		info->data=no;
		info->left=NULL;
		info->right=NULL;
	}
	else
	{
		if(no<=info->data)
		{
			info->left=create_tree(info->left,no);
		}
		else
		{
			info->right=create_tree(info->right,no);
		}
	}	
}
void pre_order(struct tree *info)
{
	if(info!=NULL)
	{
		printf(" %d ",info->data);
		pre_order(info->left);
		pre_order(info->right);
	}
}
void post_order(struct tree *info)
{
	if(info!=NULL)
	{
		post_order(info->left);
		post_order(info->right);
		printf(" %d ",info->data);
	}
}
void in_order(struct tree *info)
{
	if(info!=NULL)
	{
		in_order(info->left);
		printf(" %d ",info->data);
		in_order(info->right);
	}
}
int isfulltree(struct tree *info)
{
	if(info==NULL)
		return 1;
	if(info->left == NULL && info->right == NULL)
		return 1;
	if((info->left) && (info->right))
		return (isfulltree(info->left)&&isfulltree(info->right));
}
int main()
{
	int ch,n,l;
	do
	{
		printf("\n1.Create_tree");
		printf("\n2.Inorder");
		printf("\n3.Preorder");
		printf("\n4.Postorder");
		printf("\n5.Prefect Tree or not");
		printf("\n6.Exit");
		printf("\nEnter Your Choce");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :printf("\nEnter Value :");
				scanf("%d",&n);
				root=create_tree(root,n);
				break;
			case 2 :in_order(root);
				break;
			case 3 :pre_order(root);
				break;
			case 4 :post_order(root);
				break;
			case 5:if (isfulltree(root))
						printf("\nTree is perfect:");
					else
						printf("\nTree is not perfect");
					break;
			case 6 :exit(0);
				break;
			default:printf("\nInvalid Choice");
				break;
		}
	}while(ch!=6);
	return 0;
}
