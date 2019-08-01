#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	m=n;
	int s[n][n];
	int x=0,y=0;
	int i,j=1;
	while(m>0)
	{
		for(i=m;i>0;i--)
		{
			s[x][y]=j;
			y++;
			j++;
		}
		m--;y--;x++; 
		for(i=m;i>0;i--)
		{
			s[x][y]=j;
			x++;
			j++;
		}
		x--;y--;
		for(i=m;i>0;i--)
		{
			s[x][y]=j;
			j++;
			y--;	
		}
		y++;m--;x--;
		for(i=m;i>0;i--)
		{
			s[x][y]=j;
			j++;
			x--;
		}
		x++;y++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d",s[i][j]);
		printf("\n");
	}		
} 
