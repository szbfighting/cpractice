#include <stdio.h>
struct zhipai{
	int s[200];
	int head;
	int tail;
};
int main()
{
	struct zhipai a;
	a.head=1;
	a.tail=1;
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		a.s[a.tail]=i;
		a.tail++;
	}
	while(a.head!=a.tail)
	{
		printf("%d ",a.s[a.head]);
		a.head++;
		a.s[a.tail]=a.s[a.head];
		a.head++;
		a.tail++;
		
	}	
	return 0;
}
