#include<stdio.h>
#include<string.h>
int panduan(int a);
int main()
{
	int a[130]={0};
	char s[100];
	gets(s);
	int i;
	int len=strlen(s);
	for(i=0;i<len;i++)
	{
		a[s[i]]++;
	}
	int max=0,min=len;
	for(i=97;i<=122;i++)
	{
		if(a[i]==0)
			continue;
		else
		{
			max=max<a[i]?a[i]:max;
			min=min>a[i]?a[i]:min;
		}
	}
	if(panduan(max-min))
		printf("Lucky Word\n%d",max-min);
	else
		printf("No Answer\n0");	
    return 0;
}
int panduan(int a)
{
	int i;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
			break;
	}
	if(i==a)
		return 1;
	else
		return 0;
}
