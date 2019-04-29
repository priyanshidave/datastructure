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
void level_order(struct tree* info)
{ 
    int h = height(info); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(info, i);
} 
void printGivenLevel(struct tree* info, int level) 
{ 
    if (info == NULL) 
        return;
    if (level == 1) 
        printf("%d ", info->data); 
    else if (level > 1) 
    { 
        printGivenLevel(info->left, level-1); 
        printGivenLevel(info->right, level-1); 
    } 
}
int height(struct tree* info) 
{ 
    if (info==NULL) 
        return 0; 
    else
    { 
        int lheight = height(info->left); 
        int rheight = height(info->right); 
        if (lheight > rheight) 
            return(lheight+1); 
        else 
		return(rheight+1); 
    } 
} 
int main()
{
	int ch,n;
	do
	{
		printf("\n1.Create_tree");
		printf("\n2.Preorder");
		printf("\n3.Levelorder");
		printf("\n0.Exit");
		printf("\nEnter Your Choce");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :printf("\nEnter Value :");
				scanf("%d",&n);
				root=create_tree(root,n);
				break;
			case 2 :pre_order(root);
				break;
			case 3 :level_order(root);
				break;
			case 0 :exit(0);
				break;
			default:printf("\nInvalid Choice");
				break;
		}
	}while(ch!=0);
	return 0;
}
