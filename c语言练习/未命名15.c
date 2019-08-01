#include <stdio.h> 
int main()
{
	int n,m,sum=0;
	scanf("%d",&n);
	m=abs(n);
	while(m)
	{
		sum=sum*10+m%10;
		m=m/10;
	}
	if(n<0)
		printf("-%d",sum);
	else
		printf("%d",sum);
	return 0;
}
