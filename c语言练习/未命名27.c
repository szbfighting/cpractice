#include <stdio.h>
#include <string.h> 
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		char s[37];
		int i,m,len;
		scanf("%s",s);
		scanf("%d",&m);	
		len=strlen(s);
		m=m%len;
		for(i=len-m;i<len;i++)
			printf("%c",s[i]);
		for(i=0;i<len-m-1;i++)
			printf("%c",s[i]);
		if(n==1)
			printf("%c",s[len-m-1]);
		else
			printf("%c\n",s[len-m-1]);
		n=n-1;
	}	
	return 0;
} 
