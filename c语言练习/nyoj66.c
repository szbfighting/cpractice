#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int j,i,m;
		scanf("%d",&m);
		for(i=m+1;i<=2*m;i++)
			for(j=2*m;j<=m*(m+1);j++)
				if(i*j==m*i+m*j)
					printf("1/%d=1/%d+1/%d\n",m,j,i);
	}
}
