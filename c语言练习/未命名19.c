#include<stdio.h>
int main()
{
	char s[14];
	gets(s);
	int i=0,j=1,sum=0;
	for(i=0;i<12;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			sum+=(s[i]-48)*j;
			j++;
		}
	}
	char n;
	if(sum%11==10)
		n='x';
	else
		n='0'+sum%11;
	if(n==s[12])
		printf("Right");
	else
	{
		for(i=0;i<12;i++)
			printf("%c",s[i]);
		printf("%c",n);
	}	
	return 0;
}
