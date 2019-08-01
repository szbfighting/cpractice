#include<stdio.h>
int main()
{
	int flag=1;
	int count=1;
	while(flag)
	{
		count=1;
		int i,sum=0;
		int a;
		for(i=1;i<7;i++)
		{
			scanf("%d",&a);
			sum+=a*i*i;
		}
		if(sum>36)
			count++;
		if(sum==0)
			break;
		printf("%d\n",count);
		
	}
	return 0;
}
