#include <stdio.h>
int main()
{
	int s[5][5];
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&s[i][j]);
	int sum=0,n=0;
	for(i=0;i<5;i++)
	{
		
		for(j=n++;j<5;j++)
			sum+=s[i][j];
	}
	printf("%d",sum);
}
