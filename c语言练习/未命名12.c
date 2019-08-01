#include <stdio.h>
int main()
{
	int a[8],i,j;
	for(i=1;i<8;i++)
	{
		int c,b;
		scanf("%d%d",&c,&b);
		a[i]=c+b;
	}
	j=1;
	for(i=2;i<8;i++)
	{
		if(a[i]>a[j])
			j=i;
		if(a[i]==a[j])
			j=j<i?j:i;
	}
	if(a[j]<=8)
		printf("%d",0);
	else
		printf("%d",j);
	return 0;
} 
