#include<stdio.h>
int main()
{
	int i;
	double s,h,n;
	scanf("%lf%lf",&h,&n);
	s=h;
    if(h==0||n==0)
        printf("0.0 0.0");
    else
	{
        for(i=1;i<=n;i++)
	    {
		    s+=h;
		    h/=2;
            if(h<1e-8)
        	    break;
	    }
	    s-=2*h;
	    printf("%.1lf %.1lf",s,h);
    }
	
}
