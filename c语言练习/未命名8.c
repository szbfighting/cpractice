#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,count=0;
	int a[2*n],b[2*n]; 
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0,j=n;j<2*n;j++,i++)
		a[j]=a[i];
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0,j=n;j<2*n;j++,i++)
		b[j]=b[i];
		int shengyu=0;
	for(i=0;i<n;i++)
	{
		shengyu=0;
		for(j=i;j<i+n;j++)
		{
			if(a[j]+shengyu-b[j]>=0)
				shengyu=a[j]+shengyu-b[j];
			else
				break;
		}
		if(j==i+n)
		{
			printf("%d ",i+1);
			count++;
		}
		
	}
	if(count==0)
			printf("No Result!");
	return 0;
 } 
