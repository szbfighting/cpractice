#include <stdio.h>
int main()
{
  int n;
  char a;
  int m;
  scanf("%d",&n);
  scanf("%c",&a);
  scanf("%d",&m);
  while(a!='=')
  {
    if(a!='+'&&a!='-'&&a!='/'&&a!='*')
    {
    	printf("ERROR");
    	break;
    }
    if(a=='+')
      n=n+m;
    if(a=='-')
      n=n-m;
    if(a=='*')
      n=n*m;
    if(a=='/')
    {
      if(m==0)
      {
        printf("ERROR");
        break;
      }
      else
        n=n/m;
    }
    scanf("%c",&a);
    if(a=='=')
      break;
    scanf("%d",&m);
  }
  if(a=='=')
  	printf("%d",n);
}
