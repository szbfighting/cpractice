#include <stdio.h> 
int main()
{
	int t,p,i,j,n,m;
	scanf("%d%d",&n,&m);
	int a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(b[j]<b[j+1])
			{
				t=b[j];b[j]=b[j+1];b[j+1]=t;
				p=a[j];a[j]=a[j+1];a[j+1]=p; 
			}
			if(b[j]==b[j+1])
				if(a[j]>a[j+1])
				{
					t=b[j];b[j]=b[j+1];b[j+1]=t;
					p=a[j];a[j]=a[j+1];a[j+1]=p;
				}
		}
	for(i=0;i<n;i++)
	{
		if(b[i]<b[(int)(m*1.5)-1])
			break;
	}
	printf("%d %d\n",b[(int)(m*1.5)-1],i);
	for(j=0;j<i;j++)
		printf("%d %d\n",a[j],b[j]);
	return 0;
} 
