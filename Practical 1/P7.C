#include<stdio.h>
void sum(int[3][3]);
void main()
{
    int i=0,j=0,a[3][3];
    clrscr();
    for(i=0;i<3;i++)
    {
	for(j=0;j<3;j++)
	{
	    printf(" a[%d][%d] = ",i,j);
	    scanf("%d",&a[i][j]);
	}
    }
    sum(a);
	getch();
}
void sum(int a[3][3])
{
    int i,j,ans=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            ans=ans+a[i][j];
        }
    }
    printf("Sum of Two Dimentional Array : %d",ans);
}
