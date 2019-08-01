#include <stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("test.txt","r");
	fseek(fp,0,2);
	int n=ftell(fp);
	fseek(fp,0,0);
	char *s=(char*)malloc(1000);
	fgets(s,n,fp);
	printf("%s",s);
	fclose(fp);
	char l[100];
	gets(l);
	char s2[100];
	gets(s2);
	int i,j,k,p,o;
	int count=0;
	for(i=0;i<n;)
	{
		int start=i;
		for(j=start;s[j]!=' ';j++);
		if((j-start)==strlen(l))
		{
			for(k=start,p=0;k<j;k++,p++)
				if(s[k]!=l[p])
					break;
			if(k==j)
			{
				count++;
				if(strlen(l)<strlen(s2))
				{
					for(o=strlen(s);o>=j+1;o--)
						s[o+strlen(s2)-strlen(l)]=s[o];
					for(k=start,p=0;p<strlen(s2);k++,p++)
						s[k]=s2[p];
					s[k]=' ';
				}
				if(strlen(l)>strlen(s2))
				{
					for(o=j+1;o<=strlen(s);o++)
						s[o-(strlen(l)-strlen(s2))]=s[o];
					for(k=start,p=0;p<strlen(s2);k++,p++)
						s[k]=s2[p];
					s[k]=' ';
				}
			}
				
		}
		i=j+1;
	}
	printf("Ìæ»»ÁË%d´Î\n",count);
	puts(s);
	fp=fopen("test.txt","w");
	fprintf(fp,"%s",s);
	fclose(fp);
}

