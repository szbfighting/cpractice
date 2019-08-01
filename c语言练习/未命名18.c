#include <stdio.h>
int main()
{
	int count=0,n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int t,i,j,a[m];
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m-1;i++)
		for(j=0;j<m-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
		}
	for(i=0,j=m-1;i<=j;count++,j--)
		if(a[i]+a[j]<=n)
			i++;
	printf("%d",count);
	return 0;
} 
