#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	gets(s);
	int n,i,len=strlen(s);
	char word;
	int x=0,y=0;
	for(i=0;i<len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
			word=s[i];
		else if(s[i]=='=')
			n=i;
	}
	int flag;
	for(i=0;i<len;)
	{
		flag=0;
		if((i==0||i==n+1)&&s[i]=='-')
		{
			i+=1;
			flag=1;
		}
		else if(s[i-1]=='-')
			flag=1;
		int sum=0,end=i;
		while(s[end]>='0'&&s[end]<='9')
		{
			sum=sum*10+(s[end]-48);
			end++;
		}
		if(flag)
			sum*=-1;
		if(i>n)
			sum*=-1;
		if(s[end]==word)
			x+=sum;
		else
			y+=sum;
		i=end+1;
	}
	if(((double)y/-x)!=0)
		printf("%c=%.3lf",word,(double)y/-x);
	else
		printf("%c=%.3lf",word,0);
	return 0;
 } 
