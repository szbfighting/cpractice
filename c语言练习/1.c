/*#include<stdio.h>
#include<math.h>
int su(int m);//判断素数 
void huan(int t);//回溯 
int n;//(全局变量) 
int a[100]={0};//存数 
int b[100]={0};//记录数是否被使用 
int main()
{
	scanf("%d",&n);
	a[0]=1;
	b[0]=1;
	huan(1);//求初值为1的环，故直接给函数复制为1 
	return 0;
	
}
void huan(int t) {
	int i;
	if(t==n&&su(a[n-1]+a[0]))//输出环的条件 
	{
		for(i=0;i<n;i++)
		{
			printf("%d",a[i]);
		}
		printf("\n");
	}
	else{
		for(i=2;i<=n;i++)
			{
				if(b[i-1]==0)//此数没有被使用过 
				{
					a[t]=i;
					b[i-1]=1;
					if(su(a[t]+a[t-1]))
					{
						huan(t+1);//开始递归 
					}
					b[i-1]=0;//还原初始状态 
				}
			}		
	}
}
int su(int m)
{
	int i;
	if(m<3) return 0;
	else{
		for(i=2;i<=sqrt(m);i++){
		if(m%i==0){
			return 0;
			break;
		}
		}		
	}
	return 1; 	
}
#include<stdio.h>
#include<string.h>
char* longestPalindrome(char* s);
int main()
{
	char s[100];
	gets(s);
	longestPalindrome(s);
	
	
	
} 
	char* longestPalindrome(char* s)
	{
		int len = strlen(s);
		if (len <= 1) { return s; }
		int start = 0;
		int maxlen = 0;
		//i表示中间元素下标
		int i;
		for ( i = 1; i < len; i++)
		{
			//偶数长度
			int low = i - 1;
			int high = i;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxlen)
			{
				maxlen = high - low - 1;
				start = low + 1;
			}
			//奇数长度
			low = i - 1; high = i + 1;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxlen)
			{
				maxlen = high - low - 1;
				start = low + 1;
			}
		}
		char *arr = (char *)malloc(sizeof(int) * (maxlen * 2));
		 i = 0;
		for (; i < maxlen; i++)
		{
			arr[i] = s[start++];
		}
		arr[i] = '\0';
		int j=0;
		while(arr[j])
		{
			printf("%c",arr[j]);
			j++;
		}
	}
*/
//#include <stdio.h>
/*typedef struct person
{
    int num;
    char name[20];
    int s[3];
    float aver;
}PER;
void input(PER *p)
{
    scanf("%d%s%d%d%d",&p->num,p->name,&p->s[0],&p->s[1],&p->s[2]);
    p->aver=(p->s[0]+p->s[1]+p->s[2])/3.0;
}
void main()
{
    PER s;
    printf("please input information:\n");
    input(&s);
    printf("\nthe information is:\n");
    printf("%d\t%s\t%d\t%d\t%d\t%5.2f\n",s.num,s.name,s.s[0],s.s[1],s.s[2],s.aver);
} */
/*int x=3;
void incre();
void main()
{
	int i;
	for(i=1;i<x;i++)
	{
		
		incre();
	}
}
void incre()
{
	static int x=1;
	printf("?%d",x);
	x*=x+1;
	printf("/%d",x);
}*/
/*#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );
	
int main()
{
    int i, m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}
int factorsum( int number )
{
	int i;
	int sum=0;
	if(number==1)
		return 1;
	for(i=1;i<number;i++)
	{
		if(i>number/i)
			break;
		if(i*(number/i)==number)
		{
			sum+=i+number/i;
		}
	}
	return sum-number;
}

void PrintPN( int m, int n )
{
	int i,count=0;
	for(i=m;i<=n;i++)
	{
		if(factorsum(i)==i&&i!=1)
		{
			if(count>=1)
				printf("\n");
			printf("%d = ",i);
			int j;
			count++;
			for(j=1;j<i;j++)
			{
				if(j>i/2)
					break;
				if(j*(i/j)==i)
				{
					if(j==i/2)
						printf("%d",j);
					else
						printf("%d + ",j); 
				 } 
			}
		}
		else if(i==1)
		{
			count++;
			printf("1 = 1");
		}
	}
	if(count==0)
		printf("No perfect number");
} */
/*#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );
	
int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}
int fib( int n ) {
	if (n <= 2) {
		return 1;
	}
	if (n > 2) {
		return fib(n - 1) + fib(n - 2);
	}
}
void PrintFN( int m, int n ) {
	int j,i = 0, count = 0;
	for ( j = 0;; j++) {
		i++;
		if (fib(i) >= m && fib(i) <= n) {
			count++;
			if (count == 1) {
			    printf("%d",fib(i));
		    }
		    else {
		    	printf(" %d",fib(i));
		    }
		}
		if (fib(i) > n) {
			break;
		}
	}
	if (count == 0) {
		printf("No Fibonacci number");
	}
}*/
/*#include <stdio.h>
#include <string.h>
void nizhuan(char* left,char* right);
int main()
{
	char s[100];
	gets(s);
	nizhuan(s,s+strlen(s)-1);
	puts(s);
	niword(s);
	puts(s);
} 
void nizhuan(char *left,char *right)
{
	char s;
	while(left<right)
	{
		s=*left;
		*left=*right;
		*right=s;
		left++;
		right--; 
	}
}

void niword(char *s)
{
	char *left=s,*right=s;
	while(*right=='\0')
	{
		
		if(*right==' ')
		{
			char *p=left,*q=right;
			nizhuan(p,q-1);
			right++;
			left=right;
		}
		else
			right++;
	}
	nizhuan(left,right-1);
}*/
//定义函数struct stud_node *Creat_Stu_Doc()完成创建链表

//定义函数struct stud_node DeleteDoc(struct stud_node head,int min_score)将分数低于min_score的结点删除

//定义函数void Ptrint_Stu_Doc(struct stud_node *head)打印链表
/*#include <stdio.h>
int main()
{
	int s[10];
	int *min,*max;
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d",s+i);
	}
	min=max=s;
	for(i=1;i<10;i++)
	{
		if(*(s+i)>*max)
			max=s+i;
		else if(*(s+i)<*min)
			min=s+i;
	}
	printf("%d",*max-*min);
}*/
/*2#include <stdio.h>
int main()
{
	char s[100];
	char s2[100];
	gets(s);
	gets(s2);
	fun(s,s2);
	puts(s);
 } 
void fun(char *s1,char *s2)
{
	int i=strlen(s1);
	int j=0;
	while(s1[i++]=s2[j++]);
}*/
/*4#include <stdio.h>
int main()
{
	char s[100];
	gets(s);
	int i=0,j=0;
	while(s[i])
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			s[i]=j%5+48;
			j++;
		}
		i++;
	}
	puts(s);
}*/
/*4#include <stdio.h>
int main()
{
	char s[100];
	gets(s);
	int i;
	for(i=0;*(s+i);i++)
	{
		printf("%c",*(s+i));
		if(i%4==3)
			printf("\n");
	}
}*/
/*#include<stdio.h>
#include<string.h>
char* longestPalindrome(char* s);
int main()
{
	char s[100];
	gets(s);
	longestPalindrome(s);
} 
char* longestPalindrome(char* s)
{
	int len = strlen(s);
	if (len <= 1) { return s; }
	int start = 0;
	int maxlen = 0;
	//i表示中间元素下标
	int i;
	for ( i = 1; i < len; i++)
	{
		//偶数长度
		int low = i - 1;
		int high = i;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			low--;
			high++;
		}
		if (high - low - 1 > maxlen)
		{
			maxlen = high - low - 1;
			start = low + 1;
		}
		//奇数长度
		low = i - 1; high = i + 1;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			low--;
			high++;
		}
		if (high - low - 1 > maxlen)
		{
			maxlen = high - low - 1;
			start = low + 1;
		}
	}
	char *arr = (char *)malloc(sizeof(char) * (maxlen * 2));
	 i = 0;
	for (; i < maxlen; i++)
	{
		arr[i] = s[start++];
	}
	arr[i] = '\0';
	int j=0;
	while(arr[j])
	{
		printf("%c",arr[j]);
		j++;
	}
}*/
/*#include <stdio.h>
int main()
{
	char s1[100],s2[100];
	gets(s1);
	gets(s2);
	func(s1,s2);
	
}
void func(char *s1,char *s2)
{
	int i;
	for(i=0;s1[i]==s2[i]&&s1[i]&&s2[i];i++);
	if(s1[i]-s2[i]==0)
	{
		puts(s1);
		puts(s2);
	}
	else if(s1[i]-s2[i]<0)
		puts(s2);
	else
		puts(s1);
}*/ 
/*#include <stdio.h>
int main()
{
	char s[100];
	gets(s);
	int j=strlen(s)-1;
	int i=0,count=0;
	while(s[i])
	{
		if(s[i]==' ')
			count++; 
			i++;
	}
	i=j+count*2;
	s[i+1]='\0';
	while(i!=j)
	{
		if(s[j]==' ')
		{
			s[i--]='y';
			s[i--]='z';
			s[i--]='x';
			j--;
		}
		else
		{
			s[i--]=s[j--];
		}
	}
	puts(s);
}*/

/*#include<stdio.h>
#include<string.h>
char* longestPalindrome(char* s);
int main()
{
	char s[100];
	gets(s);
	longestPalindrome(s);
} 
char* longestPalindrome(char* s)
{
	int len = strlen(s);
	if (len <= 1) { return s; }
	int start = 0;
	int maxlen = 0;
	//i表示中间元素下标
	int i;
	for ( i = 1; i < len; i++)
	{
		//偶数长度
		int low = i - 1;
		int high = i;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			low--;
			high++;
		}
		if (high - low - 1 > maxlen)
		{
			maxlen = high - low - 1;
			start = low + 1;
		}
		//奇数长度
		low = i - 1; high = i + 1;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			low--;
			high++;
		}
		if (high - low - 1 > maxlen)
		{
			maxlen = high - low - 1;
			start = low + 1;
		}
	}
	char *arr = (char *)malloc(sizeof(char) * (maxlen ));
	 i = 0;
	for (; i < maxlen; i++)
	{
		arr[i] = s[start++];
	}
	arr[i] = '\0';
	int j=0;
	while(arr[j])
	{
		printf("%c",arr[j]);
		j++;
	}
}*/
/*#include<stdio.h>
typedef struct yuangong{
	char name[20];
	int a,b,c;
	int e;
}YG;
int main()
{
	int n;
	scanf("%d",&n);
	YG s[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s %d %d %d",s[i].name,&s[i].a,&s[i].b,&s[i].c);
		s[i].e=s[i].a+s[i].b-s[i].c;
	}
	for(i=0;i<n;i++)
	{
		printf("%s %.2f",s[i].name,(float)s[i].e);
        if(i<n-1)
            printf("\n");
	}
	
}*/ 
/*#include <stdio.h>
int main()
{
	char s[100];
	gets(s);
	int start=0,end=strlen(s);
	fun(s,start,end-1);
	for(start=0,end=0;start<strlen(s);end++)
	{
		if(s[end]==' '||s[end]=='\0')
		{
			fun(s,start,end-1);
			start=end+1;
		}
		
	}
	puts(s);
	
	
} 
void fun(char *s,int i,int j)
{
	char c;
	while(i<j)
	{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
		i++;
		j--;
	}
}*/



