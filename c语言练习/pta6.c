#include <stdio.h>
int main()
{
	int n,m,a[20],b[20],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	n=quchong(a,n);
	m=quchong(b,m);
	int j,c[40],k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i]==b[j])
				break;
		}
		if(j==m)
		{
			c[k]=a[i];
			k++;
		}	
	}
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			if(b[j]==a[i])
				break;
		}
		if(i==n)
		{
			c[k]=b[j];
			k++;
		}
	}
	for(i=0;i<k-1;i++)
		printf("%d ",c[i]);
	printf("%d",c[k-1]);
}
int quchong(int s[],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;)
		{
			if(s[i]==s[j])
			{
				n--;
				for(k=j;k<n;k++)
					s[k]=s[k+1];
			}
			else 
				j++;
		}
	}
	return n;
}
