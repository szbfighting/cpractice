#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int sum=0,n;
	scanf("%d",&n);
	while(n--)
	{
		char s[100];
		scanf("%s",s);
		int count=0,i,j;
		int len=strlen(s);
		for(i=0,j=len-1;i<len;i++,j--)
			count=count+(s[i]-48)*pow(2,j);
		sum+=count;
	}
	printf("%d",sum);
	return 0;
}
