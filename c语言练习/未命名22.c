#include<stdio.h>
#include <math.h>
int fun(int a);
int main()
{
	int n,m;
	int count=0;
	scanf("%d%d",&n,&m);
	int i;
	for(i=2;i<n;i++)
	{
		if(fun(i)&&fun(i+m)&&i+m<=n)
		{
			printf("%d %d\n",i,i+m);
			count++;
		}
	}
	if(count)
		printf("Total Is:%d",count);
	else
		printf("Total Is:0");
	return 0;
} 
int fun(int a)
{
	int flag=1;
	int i;
	for(i=2;i<=(int)sqrt(a);i++)
		if(a%i==0)
		{
			flag=0;
			break;
		}
	if(flag)
		return 1;
	else
		return 0;
}
