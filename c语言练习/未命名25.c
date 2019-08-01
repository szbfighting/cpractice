#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char s[100];
	int n;
	scanf("%s",s);
	scanf("%d",&n);
	int sum=0;
	int i,len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]>=48&&s[i]<=57)
			sum+=(s[i]-48)*pow(n,len-1-i);
		if(s[i]>=65&&s[i]<=90)
			sum+=(s[i]-55)*pow(n,len-i-1);
		else if(s[i]>=97&&s[i]<=122)
			sum+=(s[i]-87)*pow(n,len-i-1);
	}
	printf("%d",sum);
	return 0;
}
