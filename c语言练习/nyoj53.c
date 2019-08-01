#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,s[8],i=0;
		for(i=1;i<8;i++)
		{
			scanf("%d%d",&a,&b);
			s[i]=a+b;
		}
		int j=1;
		for(i=2;i<8;i++)
		{
			if(s[i]>s[j])
				j=i;
			if(s[i]=s[j])
				j=i<j?i:j;
		}
		if(s[j]>8)
			printf("%d\n",j);	
		else
			printf("%d\n",0);	
	}
}
