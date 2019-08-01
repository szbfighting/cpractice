#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	char name[20];
	char number[10];
	double chinese;
	double math;
	double english;
	double sum;
	struct student *next;
}STU;
typedef struct studentac{
	char name[20];
	char sex[10];
	char zh[20];
	char mm[20];
	struct studentac *next;
}STUAC;
typedef struct teacher{
	char name[20];
	char sex[10];
	char zh[20];
	char mm[20];
	char km[10];
	struct teacher *next;
}TEA;

void cstupwd(STUAC *head,char zh[],char mm[]);
STUAC * readac();
void creatstuac();
void saveac(STUAC *head);
void stulog(STUAC *head);
void student();
void creattea();
void tealog(TEA *head); 
void savetea(TEA *head);
void teacher();
TEA *readtea();
void add();
void change(STU *head);
void del(STU *head);
void jiaoshizi(char s[],char zh[],char mm[]);
void print(STU *head);
void printtea();
STU * readstu();
void savestu(STU *head);
void search(STU *head);
void sortstu(STU *head);
void stuzi(char s[],char zh[],char mm[]);
void changepwd(TEA *head,char zh[],char mm[]);


void student()
{
	while(1)
	{
	
		system("cls");
		STUAC *stuachead=NULL;
		char ch;
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t\t*\t  **ѧ����**            *\n");
		printf("\t\t\t\t\t*-------------------------------*\n");
		printf("\t\t\t\t\t*\t  1.ѧ��ע��            *\n");
		printf("\t\t\t\t\t*\t  2.ѧ����½            *\n");
		printf("\t\t\t\t\t*\t  3.����������          *\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t������ѡ��(1����2����3)��");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case '1':creatstuac();break; 
			case '2':stuachead=readac(); 
						if(stuachead!=NULL)
							stulog(stuachead);
						else
						{
							printf("\t�����û���Ϣ...\n\t��������......\n");
							Sleep(1000);
						}
					break;
			case '3':return;
			default:{
				printf("\t��������ȷѡ�����");
				Sleep(1000);
				break;
			}
		}
	}
}
void teacher()
{
	while(1)
	{
		system("cls");
		fflush(stdin);
		TEA *teahead=NULL;
		char ch;
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t\t*\t  **��ʦ��**            *\n");
		printf("\t\t\t\t\t*-------------------------------*\n");
		printf("\t\t\t\t\t*\t  1.��ʦע��            *\n");
		printf("\t\t\t\t\t*\t  2.��ʦ��½            *\n");
		printf("\t\t\t\t\t*\t  3.����������          *\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t������ѡ��(1����2����3)��");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case '1':creattea();break;
			case '2':teahead=readtea();
						if(teahead!=NULL)
							tealog(teahead);
						else
						{
							printf("\t�����û���Ϣ...\n\t��������......\n");
							Sleep(1000);
						}
							 
					break;
			case '3':return;
			default:{
				printf("\t��������ȷѡ�����");
				Sleep(1000);
				break;
			}
		}
	 } 
}
void creatstuac()
{
	system("cls");
	FILE *fp;
	if(fp=fopen("ѧ���˺�.txt","r")==NULL)
	{
		fp=fopen("ѧ���˺�.txt","w");
		STUAC *head,*p=NULL;
		head=(STUAC *)malloc(sizeof(STUAC));
		p=head;
		printf("\n\n\n\n\n"); 
		printf("\t*������ѧ������(������ע��ֱ��enter)��");
		gets(p->name);
		if(strcmp(p->name,"")==0)
		{
			fclose(fp);
			return;
		}
		printf("\t*�������Ա�");
		scanf("%s",p->sex);
		getchar();
		printf("\t*�������½�û�����");
		scanf("%s",p->zh);
		getchar();
		printf("\t*�������½����(19λ����)��");
		while(1)
		{
			
			int n=0;
			char ch;
			while((ch =getch()) != '\r')
			{
        		if(ch == '\b' && n > 0) 
				{
           	 		printf("\b \b");   // �ո�+\b ��Ϊ�˸��ǵ�ԭ�����ַ� 
            		n--;
        		}
        		else if(ch != '\b') 
				{
            		p->mm[n++] = ch;
            		printf("*");
        		}
    		} 
    		p->mm[n]='\0';
    		if(strlen(p->mm)>19)
    		{
    			int i;
    			for(i=0;i<n;i++)
    				printf("\b \b");
    			printf("\n\t*��������������(19λ����)��");	
			}
			else
				break;
    	}
    	p->next=NULL;
    	fclose(fp);
    	saveac(head);
    	printf("\n\t��ϲ����ע��ɹ���\n");
		printf("\t�����������......");
		getch();
		return ; 
	}
	else
	{
		STUAC *head;
		head=readac();
		STUAC *p,*q=NULL;
		p=head;
		while(p!=NULL)
		{
			q=p;
			p=p->next;
		}
		p=(STUAC *)malloc(sizeof(STUAC));
		printf("\n\n\n\n\n");
		printf("\t*������ѧ������(������ע��ֱ��enter)��");
		gets(p->name);
		if(strcmp(p->name,"")==0)
		{
			fclose(fp);
			return;
		} 
		printf("\t*�������Ա�");
		scanf("%s",p->sex);
		getchar();
		printf("\t*�������½�û�����");
		scanf("%s",p->zh);
		getchar();
		printf("\t*�������½����(19λ����)��");
		while(1)
		{
			int n=0;
			char ch;
			while((ch =getch()) != '\r')
			{
        		if(ch == '\b' && n > 0) 
				{
           	 		printf("\b \b");   // �ո�+\b ��Ϊ�˸��ǵ�ԭ�����ַ� 
            		n--;
        		}
        		else if(ch != '\b') 
				{
            		p->mm[n++] = ch;
            		printf("*");
        		}
    		} 
    		p->mm[n]='\0';
    		if(strlen(p->mm)>19)
    		{
    			int i;
    			for(i=0;i<n;i++)
    				printf("\b \b");
    			printf("\n\t*��������������(19λ����)��");	
			}
			else
				break;
		}
		q->next=p;
		p->next=NULL;
		saveac(head);
		printf("\n\t��ϲ����ע��ɹ���\n");
		printf("\t�����������......");
		getch();
		return; 
	} 	
}
void saveac(STUAC *head)
{
	FILE *fp;
	fp=fopen("ѧ���˺�.txt","w");
	STUAC *p,*q;
	p=head;
	while(p!=NULL)
	{
		fwrite(p,sizeof(STUAC),1,fp);
		p=p->next;
	}
	fclose(fp);	
}

STU * readstu()
{
	FILE *fp;
	char ch;
	fp=fopen("ѧ���ɼ�.txt","r");
	ch=fgetc(fp);
	if(fp==NULL||ch==EOF)
	{
		return NULL;
	}
	fp=fopen("ѧ���ɼ�.txt","r");
	rewind(fp);
	STU *head,*p,*q=NULL;
	head=(STU *)malloc(sizeof(STU));
	q=p=head;
	while(!feof(fp))
	{
		if(fread(p,sizeof(STU),1,fp)!=1)
			break;
		p->next=(STU *)malloc(sizeof(STU));
		q=p;
		p=q->next;
	}
	free(p);
	q->next=NULL;
	fclose(fp);
	return head; 
}


STUAC * readac()
{
	FILE *fp;
	fp=fopen("ѧ���˺�.txt","r");
	if(fp==NULL)
		return NULL; 
	rewind(fp);
	STUAC *head,*p,*q=NULL;
	head=(STUAC *)malloc(sizeof(STUAC));
	q=p=head;
	while(!feof(fp))
	{
		if(fread(p,sizeof(STUAC),1,fp)!=1) //fread�������ض���������ĸ���
           	break; 
        p->next=(STUAC *)malloc(sizeof(STUAC));
        q=p;
        p=q->next;
	}
	free(p);
	q->next=NULL;
	fclose(fp);
	return head;
}

void stulog(STUAC *head)
{
	system("cls");
	fflush(stdin);
	printf("\n\n\n\n\n");
	printf("\t\t\t****ѧ����½ҳ��****\n");
	char zh[20];
	char mm[20];
	printf("\t\t\t�������½�û���(�������½ֱ��enter)��");
	gets(zh);
	if(strcmp(zh,"")==0)
		return; 
	printf("\t\t\t���������룺");
	int n=0;
	char ch;
	while((ch =getch()) != '\r')
	{
        if(ch == '\b' && n > 0) 
		{
           	printf("\b \b");   
            n--;
        }
        else if(ch != '\b') 
		{
            mm[n++] = ch;
            printf("*");
        }
    }
    mm[n]='\0';
    STUAC *p;
    p=head;
    while(p!=NULL)
    {
    	if(strcmp(zh,p->zh)==0&&strcmp(mm,p->mm)==0)
    	{
    		printf("\n\t\t\t��½�ɹ�������\n");
			printf("\t\t\t���Ժ�......\n");
			Sleep(1000); 
			
			stuzi(p->name,p->zh,p->mm);
			break;
		}//-------------------------------------------------------------------
    	else
    		p=p->next;
	}
	if(p==NULL)
	{
		printf("\n\t\t\t��½ʧ�ܣ�\n"); 
		printf("\t\t\t�˺Ż�������󣬻�δע���˺�......\n");
		printf("\t\t\t�����������......\n");
		getch();
		return;
	}
	
}



void creattea()
{
	system("cls");
	FILE *fp;
	if(fp=fopen("��ʦ�˺�.txt","r")==NULL)
	{
		fp=fopen("��ʦ�˺�.txt","w");
		TEA *head,*p=NULL;
		head=(TEA *)malloc(sizeof(TEA));
		p=head;
		printf("\n\n\n\n\n");
		printf("\t*�������ʦ����(������ע��ֱ��enter)��");
		gets(p->name);
		if(strcmp(p->name,"")==0)
		{
			fclose(fp);
			return;
		 } 
		printf("\t*�������ʦ�Ա�");
		scanf("%s",p->sex);
		getchar();
		printf("\t*������ִ�̿�Ŀ��");
		scanf("%s",p->km);
		getchar();
		printf("\t*�������½�û�����");
		scanf("%s",p->zh);
		printf("\t*����������(19λ����)��");
		while(1)
		{
			int n=0;
			char ch;
			while((ch =getch()) != '\r')
			{
        		if(ch == '\b' && n > 0) 
				{
           	 		printf("\b \b");   // �ո�+\b ��Ϊ�˸��ǵ�ԭ�����ַ� 
            		n--;
        		}
        		else if(ch != '\b') 
				{
            		p->mm[n++] = ch;
            		printf("*");
        		}	
    		}
			p->mm[n]='\0';
			if(strlen(p->mm)>19)
    		{
    			int i;
    			for(i=0;i<n;i++)
    				printf("\b \b");
    			printf("\n\t*��������������(19λ����)��");	
			}
			else
				break;
			
		}
		p->next=NULL;
		fclose(fp);
		savetea(head);//savetea
		printf("\n\t��ϲ��ע��ɹ�������\n");
		printf("\t�����������......\n");
		getch();
		return;
	}
	else
	{
		TEA *head;
		head=readtea();//readtea
		TEA *p,*q=NULL;
		p=head;
		while(p!=NULL)
		{
			q=p;
			p=p->next;
		}
		p=(TEA *)malloc(sizeof(TEA));
		printf("\n\n\n\n\n");
		printf("\t*�������ʦ����(���������ֱ��enter)��");
		gets(p->name);
		if(strcmp(p->name,"")==0)
		{
			fclose(fp);
			return;
		 } 
		printf("\t*�������ʦ�Ա�");
		scanf("%s",p->sex);
		getchar();
		printf("\t*������ִ�̿�Ŀ��");
		scanf("%s",p->km);
		getchar();
		printf("\t*�������½�û�����");
		scanf("%s",p->zh);
		printf("\t*����������(19λ����)��");
		while(1)
		{
			int n=0;
			char ch;
			while((ch =getch()) != '\r')
			{
        		if(ch == '\b' && n > 0) 
				{
           	 		printf("\b \b");   
            		n--;
        		}
        		else if(ch != '\b') 
				{
            		p->mm[n++] = ch;
            		printf("*");
        		}
    		}
			p->mm[n]='\0';
			if(strlen(p->mm)>19)
    		{
    			int i;
    			for(i=0;i<n;i++)
    				printf("\b \b");
    			printf("\n\t*��������������(19λ����)��");
    			
			}
			else
				break;
		}
		q->next=p;
		p->next=NULL;
		savetea(head);
		printf("\n\t��ϲ��ע��ɹ�������\n");
		printf("\t�����������......\n");
		getch();
		return;
	}
 } 
 
void savestu(STU *head)
{
	FILE *fp;
	fp=fopen("ѧ���ɼ�.txt","w");
	STU *p;
	p=head;
	while(p!=NULL)
	{
		fwrite(p,sizeof(STU),1,fp);
		p=p->next;
	}
	fclose(fp);
}
 
 
void savetea(TEA *head)
{
	FILE *fp;
	fp=fopen("��ʦ�˺�.txt","w");
	TEA *p;
	p=head;
	while(p!=NULL)
	{
		fwrite(p,sizeof(TEA),1,fp);
		p=p->next;
	}
	fclose(fp);	
}

TEA *readtea()
{
	FILE *fp;
	fp=fopen("��ʦ�˺�.txt","r");
	if(fp==NULL)
		return NULL;
	rewind(fp);
	TEA *head,*p,*q=NULL;
	head=(TEA *)malloc(sizeof(TEA));
	q=p=head;
	while(!feof(fp))
	{
		if(fread(p,sizeof(TEA),1,fp)!=1) //fread�������ض���������ĸ���
           	break; 
        p->next=(TEA *)malloc(sizeof(TEA));
        q=p;
        p=q->next;
	}
	free(p);
	q->next=NULL;
	fclose(fp);
	return head;
}

void tealog(TEA *head)
{
	system("cls");
	fflush(stdin);
	printf("\n\n\n\n\n");
	printf("\t\t\t****��ʦ��½ҳ��****\n");
	char zh[20];
	char mm[20];
	printf("\t\t\t�������½�û���(�������½ֱ��enter)��");
	gets(zh);
	if(strcmp(zh,"")==0)
		return;
	printf("\t\t\t���������룺");
	int n=0;
	char ch;
	while((ch=getch())!='\r')
	{
		if(ch=='\b'&&n>0)
		{
			printf("\b \b");
			n--;
		}
		else if(ch!='\b')
		{
			mm[n++]=ch;
			printf("*");
		}
	}
	mm[n]='\0';
	TEA *p;
	p=head;
	while(p!=NULL)
	{
		if(strcmp(zh,p->zh)==0&&strcmp(mm,p->mm)==0)
		{
			printf("\n\t\t\t��½�ɹ�......\n");
			printf("\t\t\t���ڽ����ʦ������棬���Ե�......");
			Sleep(1000);
			jiaoshizi(p->name,p->zh,p->mm); 
			return;
		}
		else
			p=p->next;
	}
	if(p==NULL)
	{
		printf("\n\t\t\t��½ʧ�ܣ�\n");
		printf("\t\t\t�˺Ż�������󣬻�δע���˺�......\n");
		printf("\t\t\t�����������......\n");
		getch();
		return;
	}
	
}
void jiaoshizi(char s[],char zh[],char mm[])//������ 
{
	while(1)
	{
		system("cls");
		STU *head=NULL;
		char ch;
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t\t\t%s��ʦ��ӭ�㣡        \n",s); 
		printf("\t\t\t\t\t*-------------------------------*\n");
		printf("\t\t\t\t\t*\t1.���ѧ��              *\n");
		printf("\t\t\t\t\t*\t2.ɾ��ѧ��              *\n");
		printf("\t\t\t\t\t*\t3.�޸�ѧ����Ϣ          *\n");
		printf("\t\t\t\t\t*\t4.����ѧ��              *\n");
		printf("\t\t\t\t\t*\t5.�鿴ѧ����Ϣ          *\n");
		printf("\t\t\t\t\t*\t6.����ѧ��              *\n");
		printf("\t\t\t\t\t*\tע:(���ܳɼ��ɸߵ���)   *\n"); 
		printf("\t\t\t\t\t*\t7.�鿴��ʦ��Ϣ          *\n");
		printf("\t\t\t\t\t*\t8.�޸�����              *\n");
		printf("\t\t\t\t\t*\t9.�˳���¼              *\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t��ѡ��Ҫ���еĲ�����");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case '1':add();break;//�깤 
			case '2':head=readstu();
						if(head!=NULL)
							del(head);
						else
						{
							printf("��δ���ѧ����\n��������...");
							Sleep(1500);
						 } 
					break;
			case '3':head=readstu();
						if(head!=NULL)
							change(head);
						else
						{
							printf("��δ����ѧ���ɼ���\n��������...");
							Sleep(1500);
						}
					break;
			case '4':head=readstu();
						if(head!=NULL)
							search(head);
						else
						{
							printf("��δ����ѧ���ɼ���\n��������...");
							Sleep(1500);
						}
					break;
			case '5':head=readstu();
						if(head!=NULL)
							print(head);
						else
						{
							printf("��δ����ѧ���ɼ���\n��������...");
							Sleep(1500);
						} 
					break;
			case '6':head=readstu();
						if(head!=NULL)
							sortstu(head);
						else
						{
							printf("��δ����ѧ���ɼ���\n��������...");
							Sleep(1500);
						}
							break;					  
			case '7':printtea();break;
			case '8':head=readtea();
						if(head!=NULL)
							changepwd(head,zh,mm);
						break;
			case '9':return;
			default:{
				printf("\t��������ȷѡ�����");
				Sleep(1000);
				break;
			}
		}
	}	
}
void changepwd(TEA *head,char zh[],char mm[])
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\t��ʦ�޸�����\n");
	printf("\t\t************************\n");
	char s[20];
	printf("\t\t\t�����������룺");
	int n=0;
	char ch;
	while((ch =getch()) != '\r')
	{
        if(ch == '\b' && n > 0) 
		{
           	printf("\b \b");   
            n--;
        }
        else if(ch != '\b') 
		{
            s[n++] = ch;
            printf("*");
        }
    }
    s[n]='\0';
    TEA *p;
    p=head;
    while(p!=NULL)
    {
    	if(strcmp(zh,p->zh)==0&&strcmp(mm,p->mm)==0)
    	{
    		strcpy(p->mm,s);
    		break;
		}
		else
			p-p->next;
	}
	savetea(head);
	printf("\n\t\t\t�޸ĳɹ�����\n");
	printf("\t\t\t�����������...\n");
	getch();
	return;
}

void add()
{
	system("cls");
	FILE *fp;
	if(fp=fopen("ѧ���ɼ�.txt","r")==NULL)
	{
		fp=fopen("ѧ���ɼ�.txt","w");
		STU *head,*p;
		p=head=(STU *)malloc(sizeof(STU));
		printf("\n\n\n\n\n");
		printf("*������ѧ��������");
		scanf("%s",p->name);getchar();
		printf("*������ѧ��ѧ�ţ�");
		scanf("%s",p->number);getchar();
		printf("*������ѧ�����ĳɼ���");
		scanf("%lf",&p->chinese);getchar();
		printf("*������ѧ����ѧ�ɼ���");
		scanf("%lf",&p->math);getchar();
		printf("*������ѧ��Ӣ��ɼ���");
		scanf("%lf",&p->english);getchar();
		p->sum=p->chinese+p->english+p->math;
		p->next=NULL;
		fclose(fp);
		savestu(head);//================================================================== 
		printf("��ӳɹ�����\n");
		printf("�����������......\n");
		getch();
		return;
	}
	else
	{
		STU *head,*p,*q=NULL;
		head=readstu();//=================================================================== 
		p=head;
		while(p!=NULL)
		{
			q=p;
			p=p->next;
		}
		p=(STU *)malloc(sizeof(STU));
		printf("\n\n\n\n\n");
		printf("*������ѧ��������");
		scanf("%s",p->name);getchar();
		printf("*������ѧ��ѧ�ţ�");
		scanf("%s",p->number);getchar();
		printf("*������ѧ�����ĳɼ���");
		scanf("%lf",&p->chinese);getchar();
		printf("*������ѧ����ѧ�ɼ���");
		scanf("%lf",&p->math);getchar();
		printf("*������ѧ��Ӣ��ɼ���");
		scanf("%lf",&p->english);getchar();
		p->sum=p->chinese+p->english+p->math;
		q->next=p;
		p->next=NULL;
		savestu(head);//==================================================================== 
		printf("��ӳɹ�����\n");
		printf("�����������......\n");
		getch();
		return;
	}
}

void del(STU *head)
{
	system("cls");
	char name[20];
	char number[10];
	printf("\n\n\n\n\n");
	printf("*������Ҫɾ��ѧ��������");
	scanf("%s",name);getchar();
	printf("*������Ҫɾ��ѧ��ѧ�ţ�");
	scanf("%s",number);getchar();
	STU *p,*q=NULL;
	p=head;
	while(p!=NULL)
	{
		if(strcmp(name,p->name)==0&&strcmp(number,p->number)==0)
		{
			if(p==head)
			{
				head=p->next;
				free(p);
				savestu(head);
				printf("*ɾ���ɹ�������\n");
				printf("�����������......");
				getch();
				return;
			}
			else
			{
				q->next=p->next;
				free(p);
				savestu(head);
				printf("*ɾ���ɹ�������\n");
				printf("�����������......");
				getch();
				return;
			}
		}
		else
		{
			q=p;
			p=p->next;
		}
	} 
	if(p==NULL)
	{
		printf("*δ�ҵ���ѧ����\n");
		printf("�����������......");
		getch();
		return;
	}
}

void change(STU *head)
{
	system("cls");
	char name[20];
	char number[10];
	printf("\n\n\n\n\n");
	printf("*������Ҫ�޸�ѧ��������");
	scanf("%s",name);getchar();
	printf("*������Ҫ�޸�ѧ��ѧ�ţ�");
	scanf("%s",number);getchar();
	STU *p;
	p=head;
	while(p!=NULL)
	{
		if(strcmp(name,p->name)==0&&strcmp(number,p->number)==0)
		{
			printf("��ѧ����ϢΪ��\n");
			printf("ѧ��������%s  ",p->name);
			printf("ѧ��ѧ�ţ�%s  ",p->number);
			printf("\n���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ�  �ܳɼ�\n");
			printf("%.3lf  %.3lf  %.3lf  %.3lf\n",p->chinese,p->math,p->english,p->sum);
			char km[10];
			printf("������Ҫ�޸Ŀ�Ŀ��");
			scanf("%s",km);getchar();
			if(strcmp(km,"����")==0)
			{
				printf("�������޸ĺ�ĳɼ���");
				scanf("%lf",&p->chinese);getchar();
				p->sum=p->chinese+p->english+p->math;
				printf("\n�޸ĳɹ�!!!\n");
				savestu(head);
				printf("�����������......");
				getch();
				return;
			} 
			if(strcmp(km,"��ѧ")==0)
			{
				printf("�������޸ĺ�ĳɼ���");
				scanf("%lf",&p->math);getchar();
				p->sum=p->chinese+p->english+p->math;
				printf("\n�޸ĳɹ�!!!\n");
				savestu(head);
				printf("�����������......");
				getch();
				return;
			} 
			if(strcmp(km,"Ӣ��")==0)
			{
				printf("�������޸ĺ�ĳɼ���");
				scanf("%lf",&p->english);getchar();
				p->sum=p->chinese+p->english+p->math;
				printf("\n�޸ĳɹ�!!!\n");
				savestu(head);
				printf("�����������......");
				getch();
				return;
			}
			
		}
		else
			p=p->next;
	}
	if(p==NULL)
	{
		printf("\nδ�ҵ���ѧ����Ϣ......");
		printf("\n����������ء�");
		getch();
		return;
	}
	
}

void search(STU *head)
{
	system("cls");
	STU *p;
	p=head;
	char name[20];
	char number[10];
	printf("\n\n\n\n\n");
	printf("*������Ҫ����ѧ��������");
	scanf("%s",name);getchar();
	printf("*������Ҫ����ѧ��ѧ�ţ�");
	scanf("%s",number);getchar();
	while(p!=NULL)
	{
		if(strcmp(name,p->name)==0&&strcmp(number,p->number)==0)
		{
			printf("��ѧ����Ϣ��\n");
			printf("ѧ��������%s\n",p->name);
			printf("ѧ��ѧ�ţ�%s\n",p->number);
			printf("���ĳɼ���%.3lf\n",p->chinese);
			printf("��ѧ�ɼ���%.3lf\n",p->math);
			printf("Ӣ��ɼ���%.3lf\n",p->english);
			printf("�ܳɼ���%.3lf\n",p->sum);
			printf("�����������......");
			getch();
			return;
		}
		else
			p=p->next;
	}
	if(p==NULL)
	{
		printf("δ���ҵ���ѧ��......\n");
		printf("�����������...");
		getch();
		return;
	}
}

void print(STU *head)
{
	system("cls");
	STU *p;
	p=head;
	int count=0;
	printf("\t\tѧ������   ѧ��ѧ��  ���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ�  �ܳɼ�\n");
	while(p!=NULL)
	{
		printf("\t\t%-8s   %-8s  %-8.3lf  %-8.3lf  %-8.3lf  %-8.3lf\n",p->name,p->number,p->chinese,p->math,p->english,p->sum);
		count++;
		p=p->next;
	}
	printf("\t\t����%d��ͬѧ��\n",count);
	printf("\t\t�����������......");
	getch();
	return;
}
void sortstu(STU *head)
{
	int count=0;
	STU *p;
	p=head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	} 
	int i,j;
	STU *q;
	q=p=head;
	STU *l;
	double t;
	char s[20];
	for(i=0;i<count;i++)
	{
		l=p; 
		q=p;
		for(j=i+1;j<count;j++,q=q->next)
		{
			if(l->sum < q->next->sum)
				l=q->next;
		}
		if(l!=p)
		{
			t=l->chinese;l->chinese=p->chinese;p->chinese=t;
			t=l->english;l->english=p->english;p->english=t;
			t=l->math;l->math=p->math;p->math=t;
			t=l->sum;l->sum=p->sum;p->sum=t;
			strcpy(s,l->name);strcpy(l->name,p->name);strcpy(p->name,s);
			strcpy(s,l->number);strcpy(l->number,p->number);strcpy(p->number,s);
		}
		p=p->next;
	}
	savestu(head);
	printf("����ɹ�......\n");
	printf("�����������...\n");
	getch();
	return;
}


void printtea()
{
	system("cls");
	printf("*****��ʦ��Ϣ*****\n");
	printf("��ʦ����  �Ա�  ִ�̿�Ŀ\n");
	TEA *head;
	head=readtea();
	while(head!=NULL)
	{
		printf("%-8s  %-4s  %-s\n",head->name,head->sex,head->km);
		head=head->next;
	}
	printf("�����������......");
	getch();
	return;
	
}

void stuzi(char s[],char zh[],char mm[])
{
	while(1)
	{
		STUAC *head=NULL; 
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t%sͬѧ��ã�\n",s);
		printf("\t\t* * * * * * * * * * * * * * *\n");
		char ch;
		printf("\t\t\t1.�鿴�ɼ�\n");
		printf("\t\t\t2.�޸�����\n");
		printf("\t\t\t3.�˳���¼\n");
		printf("\t������ѡ��");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case '1':
			{
				system("cls");
				STU *head,*p;
				char number[10];
				printf("\t\t\t������ѧ�ţ�");
				scanf("%s",number);getchar();
				head=readstu();
				p=head;
				while(p!=NULL)
				{
					if(strcmp(s,p->name)==0&&strcmp(number,p->number)==0)
					{
						printf("\t\tѧ������   ѧ��ѧ��  ���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ�  �ܳɼ�\n");
						printf("\t\t%-8s   %-8s  %-8.3lf  %-8.3lf  %-8.3lf  %-8.3lf\n",p->name,p->number,p->chinese,p->math,p->english,p->sum);
						printf("�����������......");
						getch(); 
						break;
					}
					else
						p=p->next;
				}
				if(p==NULL)
				{
					printf("\t\t��ʦ��δ¼����ĳɼ���Ϣ......\n");
					printf("�����������......");
					getch();
				} 
				break;
			}
			case '2':head=readac();
						cstupwd(head,zh,mm);
					break;
			case '3':return;
			default:{
				printf("\t��������ȷѡ�����");
				Sleep(1000);
				break;
			}
		}
	}
	
 } 
void cstupwd(STUAC *head,char zh[],char mm[])
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t\tѧ���޸�����\n");
	printf("\t\t************************\n");
	char s[20];
	printf("\t\t\t�����������룺");
	int n=0;
	char ch;
	while((ch =getch()) != '\r')
	{
        if(ch == '\b' && n > 0) 
		{
           	printf("\b \b");   
            n--;
        }
        else if(ch != '\b') 
		{
            s[n++] = ch;
            printf("*");
        }
    }
    s[n]='\0';
    STUAC *p;
    p=head;
    while(p!=NULL)
    {
    	if(strcmp(zh,p->zh)==0&&strcmp(mm,p->mm)==0)
    	{
    		strcpy(p->mm,s);
    		break;
		}
		else
			p-p->next;
	}
	saveac(head);
	printf("\n\t\t\t�޸ĳɹ�����\n");
	printf("\t\t\t�����������...\n");
	getch();
	return;
}

int main()
{
	while(1)
	{
	
		system("cls");
		char ch;
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t\t*       **ѧ������ϵͳ**        *\n");
		printf("\t\t\t\t\t*-------------------------------*\n");
		printf("\t\t\t\t\t*\t    1.ѧ����            *\n");
		printf("\t\t\t\t\t*\t    2.��ʦ��            *\n");
		printf("\t\t\t\t\t*\t    3.�˳�ϵͳ          *\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t������ѡ��(1����2����3)��");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case '1':student();break;
			case '2':teacher();break;
			case '3':exit(0);
			default:{
				printf("\t��������ȷѡ�����");
				Sleep(1000);
				break;
			}	
		}
	}
} 
