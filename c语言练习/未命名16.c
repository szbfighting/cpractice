#include <stdio.h>
#include <string.h> 
void lower(char *a);
int main()
{
	char d[11];
	char w[10000001];
	gets(d);
	gets(w);
	int lend=strlen(d);
	int lenw=strlen(w);
	lower(d);
	lower(w);
	int i,j,k,l,n=lenw,count=0;
	for(i=0;i<lenw;i++)
	{
		for(j=0;j<lenw;j++)
		{
			if(w[j]==' ')
			{
				if(j-i==lend)
				{
					for(k=0,l=i;k<lend;k++,l++)
					{
						if(d[k]!=w[l])
							break;
					}
					if(k==lend)
					{
						count++;
						n=i<n?i:n;
					}	
					i=j;
				}
			}
		}
	}
	if(count==0)
		printf("%d",-1);
	else
		printf("%d %d",count,n);
	return 0;
	
}
void lower(char *a)
{
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]>=65&&a[i]<=90)
			a[i]=a[i]+32;
		i++;
	}
}
