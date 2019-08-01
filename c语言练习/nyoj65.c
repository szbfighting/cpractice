#include <stdio.h>
int main()
{
	int s,n;
	scanf("%d",&n);
	while(n--)
	{
		int i,m;
		int sum=0;
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			sum=sum+jiecheng(i);
		}
		printf("%d\n",sum);
	}

} 
int jiecheng(int a)
{
	int n=1,j;
	for(j=1;j<=a;j++)
	{
		if(j%2)
			n=n*j;	
	}
	return n;
}
