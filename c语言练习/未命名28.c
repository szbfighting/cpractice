#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n<10)
		printf("%d\nRight",n);
	else
	{
		int m=n,k=n;
		int count12=0,count10=0,count16=0;
		while(m)
		{
			count12+=m%12;
			m=m/12;
		}
		while(k)
		{
			count16+=k%16;
			k=k/16;
		}
		while(n)
		{
			count10+=n%10;
			n/=10;
		}
		if(count10==count12&&count10==count16)
			printf("%d\nRight",count16);
		else
			printf("%d\nWrong",count16);
	}
	return 0;
} 
