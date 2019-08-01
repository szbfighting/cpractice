#include <stdio.h>
int a[2223]= {6,2,5,5,4,5,6,3,7,6};
const int b[10]= {6,2,5,5,4,5,6,3,7,6};
int need(int n)
{
    int t, num;
    num=0;
    if(n==0) return 6;
    while(n>0)
    {
        t=n%10;
        num+=b[t];
        n/=10;
    }
    return num;
}
int main( )
{
    int n,i,j,A,B,C,D,sum;
    scanf("%d",&n);
    sum=0;
    for(i=10; i<2223; i++)
        a[i]=need(i);
    for(i=0; i<=1000; i++)
    {
        for(j=0; j<=1000; j++)
        {
            A=a[i];
            B=a[j];
            C=n-4-A-B;
            D=a[i+j];
            if(D==C) sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}
