#include <stdio.h>
int main()
{
	int t=0,n,k=0;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		if(m-k>0)
			t=t+(m-k)*6+5;
		else
			t=t+(k-m)*4+5;
		k=m;
	}
	printf("%d",t);
	return 0;
}
