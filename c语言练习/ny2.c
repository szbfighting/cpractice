#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(n!=0&&m!=0)
    {
        int count=0,jinwei=0;
        while(n)
        {
            if((jinwei+n%10+m%10)/10)
            {
                count++;
                jinwei=(jinwei+n%10+m%10)/10;
            }
            n=n/10;m=m/10;
        }
        printf("%d\n",count);
        scanf("%d%d",&n,&m);
    }
}
