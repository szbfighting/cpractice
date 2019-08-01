#include <stdio.h>
#include <math.h>
int main()
{
  double a,b,c,t;
  scanf("%lf%lf%lf",&a,&b,&c);
  if(a==0&&b==0&&c==0)
    printf("Zero Equation");
  else if(a==0&&b==0&&c!=0)
    printf("Not An Equation");
  else if(a==0)
  {
  	printf("%.2lf\n",((-c)/b));
  }
  else
  {
    t=b*b-4*a*c;
    if(t>0)
    {
      printf("%.2lf\n%.2f\n",(-b+sqrt(t))/(2*a),(-b-sqrt(t))/(2*a));
    }
    else if(t==0)
    {
      printf("%.2lf\n",(-b)/(2*a));
    }
    else
    {
      printf("%.2lf+%.2lfi\n",((-b)/(2*a)),(sqrt(4*a*c-b*b)/(2*a)));
      printf("%.2lf-%.2lfi\n",((-b)/(2*a)),(sqrt(4*a*c-b*b)/(2*a)));
    }
  }
}

