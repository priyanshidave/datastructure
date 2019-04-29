#include <stdio.h>
#include<conio.h>
#include<process.h>
int len(char *s)
{
	int c=0;
	while(*s!='\0')
	{
		c++;
		s++;
	}
	return c;
}

int compare(char *s,char *s1)
{
	if(strlen(s)!=strlen(s1))
		return 1;
	while(*s!='\0'&& *s1!='\0')
	{
		if(*s!=*s1)
			return 1;
		s++;
		s1++;
	}
	return 0;
}

void copy(char *s,char *s1)
{
	while(*s!='\0')
	{
		*s1=*s;
		s1++;
		s++;
	}
}
void concate(char *s1,char *s)
{
	while(*s1!='\0')
		s1++;
	while(*s!='\0')
	{
		*s1=*s;
		s++;
		s1++;
	}
	*s1='\0';
}
void main()
{
    char *s1,*s2;
    char con[]="ABCDE" ;
    printf("enter string:");
    gets(s1);
    printf("length %d",len(s1));
    copy(s1,s2);
    printf("String after copy: %s",s2);
    if(compare(s1,s2)==0)
	printf("same");
    else
	printf("not same");
    concate("concated string :%s",con);
    getch();
}
