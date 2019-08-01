#include <stdio.h>
void change(int a,int b);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	change(n,m);
	return 0;
}
void change(int a,int b)
{
	if(a==0)
		return;
	else
	{
		change(a/b,b);
		if(a%b<10)
			printf("%d",a%b);
		else
			printf("%c",65+(a%b-10));
	}
}
