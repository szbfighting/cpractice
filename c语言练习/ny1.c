#include<stdio.h>
#include<stdlib.h>
int main() 
{
	int L, M;
	int a[100];
	int b[100];
	int tree=0;
	scanf("%d%d", &L, &M);
	int i;
	for(i=0;i<M;i++) 
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	int l[10010];
	int j;
	for(j=0;j<L+1;j++) 
	{
		l[j]=1;
	}
	int m,n;
	for(m=0;m<M;m++)
	{
		for(n=a[m];n<=b[m];n++) 
		{
			l[n]=0;
		}
	}
	int k;
	for(k=0;k<L+1;k++) 
	{
		tree = tree + l[k];
	}
	printf("\n%d", tree);
	return 0;
}
