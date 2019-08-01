#include <stdio.h>
int gcd(int a,int b);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int min,max;
	min=n<m?n:m;
	max=n>m?n:m;
	int i,count=0;
	for(i=min;i<=max;i+=min)
	{
		if((max*min)%i==0)
			if((max*min/i)%min==0)
				if(gcd((max*min/i),i)==min)
					count++;
	}
	printf("%d",count);
	return 0;
 } 
int gcd(int a,int b)
{
	return a%b==0?b:gcd(b,a%b);
}
