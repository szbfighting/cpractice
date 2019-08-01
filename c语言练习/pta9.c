#include<stdio.h>
int digui(int n);
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	i=digui(n);
	printf("%d",i);
	
} 
int digui(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n>2)
		return digui(n-1)+digui(n-2);
}
