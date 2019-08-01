#include <stdio.h>
int main()
{
	int i=0;
	double n;
	scanf("%lf",&n);
	double sum=0;
	while(sum<=n)
	{
		i=i+1;
		sum=sum+1.0/i;
	}
	printf("%d",i);
	return 0;
}
