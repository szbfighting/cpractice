#include <stdio.h>
int fboni(int m);
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		printf("%d\n",fboni(m));
	}
}
int fboni(int m)
{
	if(m==1||m==2)
		return 1;
	else
		return fboni(m-1)+fboni(m-2);
}
