#include <stdio.h> 
int main()
{
	int count=0,n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++)
	{
		j=i;
		while(j)
		{
			if(j%10==2)
				count++;
			j=j/10;
		}
	}
	printf("%d",count);
	return 0;
}
