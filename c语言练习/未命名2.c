#include <stdio.h>
int jishu(int a);
int main()
{
	int sum,n;
	scanf("%d",&n);
	sum=jishu(n);	
	printf("%d",sum);
	return 0;
} 
int jishu(int a)
{
	if(a==1)
		return 1;
	else
	{
		int sum=1,i;
		for(i=1;i<=a/2;i++)
			sum+=jishu(i);
		return sum;
	}
}
