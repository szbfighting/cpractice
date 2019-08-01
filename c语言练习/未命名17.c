#include <stdio.h>
int a[301],b[301],c,d,e,g,i,j,k,n,l[301];//a表示总分，b表示语文成绩  l表示学号 
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
     scanf("%d%d%d",&b[i],&c,&d);
     a[i]=b[i]+c+d;
     l[i]=i;
    }

	for(i=1;i<n;i++)

	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
				k=b[j];
				b[j]=b[j+1];
				b[j+1]=k;
				k=l[j];
				l[j]=l[j+1];
				l[j+1]=k;
			}
			if(a[j]==a[j+1])
			{
				if(b[j]<b[j+1])
				{
					k=b[j];
					b[j]=b[j+1];
					b[j+1]=k;
					k=l[j];
					l[j]=l[j+1];
					l[j+1]=k;
				}
			}		
		}

	}
	for(i=1;i<=5;i++)
	{
		printf("%d %d\n",l[i],a[i]);
	}
	return 0;
}
