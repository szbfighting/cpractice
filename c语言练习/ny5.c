#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char m[1000000];
        scanf("%s",m);
        m[0]='0';
        int i;
        for(i=0;i<strlen(m);i++)
        {
            if(m[i]!='0')
            {
                printf("%s\n",m+i);
                break;
            }
        }
        if(i==strlen(m))
            printf("%c\n",'0');        
    }
}
