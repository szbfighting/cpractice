#include<stdio.h>
int main()
{
    int count=0,n;
    scanf("%d",&n);
    while(n--)
    {
        char s[7];
        scanf("%s",s);
        if(s[0]>='A'&&s[0]<='G'||s[0]>='R'&&s[0]<='T')
            ;
        else
            count++;
    }
    printf("%d\n",count);
    return 0;
}
