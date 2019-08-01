#include <stdio.h>
int main()
{
	int n,i,m,t=0;
	scanf("%d",&n);
	while(n--)
	{
		int a[10];
		for(i=0;i<10;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i=0;i<10;i++)
		{
			if(m+30>=a[i])
				t++;
		}
		printf("%d\n",t);
		t=0;
	}
}
