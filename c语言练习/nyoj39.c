#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	scanf("%d",&n);
	do
	{
		if(pow(n/100,3)+pow(n/10%10,3)+pow(n%10,3)==n)
			printf("Yes\n");
		else
			printf("No\n");
		scanf("%d",&n);
	}while(n);
} 
