#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int year,month,day;
        int m=0;
        scanf("%d%d%d",&year,&month,&day);
        switch(month-1)
        {
            case 11:m=m+30;
            case 10:m=m+31;
            case 9:m=m+30;
            case 8:m=m+31;
            case 7:m=m+31;
            case 6:m=m+30;
            case 5:m=m+31;
            case 4:m=m+30;
            case 3:m=m+31;
            case 2:m=m+28;
            case 1:m=m+31;break;
            default:break;
        }
        m=m+day;
        if(year%4==0&&year%100!=0||year%400==0)
            if(month>2)
                m=m+1;
        printf("%d\n",m);
    }
}
