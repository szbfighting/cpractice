#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int count=0,m;
        scanf("%d",&m);
        int j=m;
        while(m)
        {
            if(m%2)
            {
                count++;
                m=m/2;
            }
            else
            {
                m=m/2;
            }
        }
        printf("%d\n",count);    
    }
}
