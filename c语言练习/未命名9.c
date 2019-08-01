#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int count=0,t,j,i,a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
		}
	for(i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			a[i]=0;
			count++;
		}			
	}
	printf("%d\n",n-count);
	for(i=0;i<n;i++)
	{
		if(a[i]!=0)
			printf("%d ",a[i]);			
	}
	return 0;
} 
