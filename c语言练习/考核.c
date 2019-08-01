#include <stdio.h>
int main()
{
	char s1[200];
	char s2[200];
	char s3[202];
	s3[201]='\0';
	scanf("%s",s1);
	scanf("%s",s2);
	int n,m;
	int l=200;
	n=strlen(s1);
	m=strlen(s2);
	n--;
	m--;
	int forward=0;
	while(n>=0&&m>=0)
	{
		s3[l]=(s1[n]-48+s2[m]-48+forward)%10+48;
		forward=(s1[n]-48+s2[m]-48+forward)/10;
		n--;m--;
		l--;
	}
	if(n==m)
	{
		if(forward!=0)
		{
			s3[l]=forward+48;
			l--;
		}
	} 
	else if(n<0)
	{
		while(m>=0)
		{
			s3[l]=(s2[m]-48+forward)%10+48;
			forward=(s2[m]-48+forward)/10;
			l--;
			m--;
		}
		if(forward!=0)
		{
			s3[l]=forward+48;
			l--;
		}
	}
	else if(m<0)
	{
		while(n>=0)
		{
			s3[l]=(s1[n]-48+forward)%10+48;
			forward=(s1[n]-48+forward)/10;
			l--;
			n--;
		}
		if(forward!=0)
		{
			s3[l]=forward+48;
			l--;
		}
		
	}
	int i=l+1;
	for(;i<201;i++)
		printf("%c",s3[i]);
}
