#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	while(a--)
	{
		int n,m,i;
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
		{
			if(i*2+(n-i)*4==m)
			{
				printf("%d %d\n",i,n-i);
				break;
			}
		}
		if(i==n+1)
			printf("No answer\n");
	}
}
