#include <stdio.h>
int gongyue(int a,int b);
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int i,j;
		scanf("%d%d",&i,&j);
		printf("%d ",gongyue(i,j));
		printf("%d\n",i*j/gongyue(i,j));
		
	}
}
int gongyue(int a,int b)
{
	if(a%b)
		gongyue(b,a%b);
	else
	return b;
}
