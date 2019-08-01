#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        int count=0,i=1;
        while(m>i)
        {
            m=m-i;
            count++;
            i++;
        }
        if(count%2)
        {
            printf("%d/%d\n",m,count+2-m);
        }
        if(count%2==0)
        {
            printf("%d/%d\n",count+2-m,m);
        }
    }
}
