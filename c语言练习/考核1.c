#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int s[n+1];
	int l;
	for(l=0;l<n+1;l++)
		s[l]=0;
	int k;
	scanf("%d",&k);
	int i,j;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(j%i==0)
			{
				if(s[j]==0)
					s[j]=1;
				else
					s[j]=0;
			}
		}
	}
	for(i=1;i<n+1;i++)
		if(s[i]==1)
			printf("%d ",i);
 } 
