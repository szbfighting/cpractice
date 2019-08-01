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
		printf("\t\t\t\t\t*\t  **学生端**            *\n");
		printf("\t\t\t\t\t*-------------------------------*\n");
		printf("\t\t\t\t\t*\t  1.学生注册            *\n");
		printf("\t\t\t\t\t*\t  2.学生登陆            *\n");
		printf("\t\t\t\t\t*\t  3.返回主界面          *\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t请输入选择(1或者2或者3)：");
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
							printf("\t暂无用户信息...\n\t即将返回......\n");
							Sleep(1000);
						}
					break;
			case '3':return;
			default:{
				printf("\t请输入正确选项！！！");
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
		printf("\t\t\t\t\t*\t  **教师端**            *\n");
		printf("\t\t\t\t\t*-------------------------------*\n");
		printf("\t\t\t\t\t*\t  1.教师注册            *\n");
		printf("\t\t\t\t\t*\t  2.教师登陆            *\n");
		printf("\t\t\t\t\t*\t  3.返回主界面          *\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t请输入选择(1或者2或者3)：");
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
							printf("\t暂无用户信息...\n\t即将返回......\n");
							Sleep(1000);
						}
							 
					break;
			case '3':return;
			default:{
				printf("\t请输入正确选项！！！");
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
	if(fp=fopen("学生账号.txt","r")==NULL)
	{
		fp=fopen("学生账号.txt","w");
		STUAC *head,*p=NULL;
		head=(STUAC *)malloc(sizeof(STUAC));
		p=head;
		printf("\n\n\n\n\n"); 
		printf("\t*请输入学生姓名(若不想注册直接enter)：");
		gets(p->name);
		if(strcmp(p->name,"")==0)
		{
			fclose(fp);
			return;
		}
		printf("\t*请输入性别：");
		scanf("%s",p->sex);
		getchar();
		printf("\t*请输入登陆用户名：");
		scanf("%s",p->zh);
		getchar();
		printf("\t*请输入登陆密码(19位以内)：");
		while(1)
		{
			
			int n=0;
			char ch;
			while((ch =getch()) != '\r')
			{
        		if(ch == '\b' && n > 0) 
				{
           	 		printf("\b \b");   // 空格+\b 是为了覆盖掉原来的字符 
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
    			printf("\n\t*请重新输入密码(19位以内)：");	
			}
			else
				break;
    	}
    	p->next=NULL;
    	fclose(fp);
    	saveac(head);
    	printf("\n\t恭喜您！注册成功！\n");
		printf("\t按任意键返回......");
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
		printf("\t*请输入学生姓名(若不想注册直接enter)：");
		gets(p->name);
		if(strcmp(p->name,"")==0)
		{
			fclose(fp);
			return;
		} 
		printf("\t*请输入性别：");
		scanf("%s",p->sex);
		getchar();
		printf("\t*请输入登陆用户名：");
		scanf("%s",p->zh);
		getchar();
		printf("\t*请输入登陆密码(19位以内)：");
		while(1)
		{
			int n=0;
			char ch;
			while((ch =getch()) != '\r')
			{
        		if(ch == '\b' && n > 0) 
				{
           	 		printf("\b \b");   // 空格+\b 是为了覆盖掉原来的字符 
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
    			printf("\n\t*请重新输入密码(19位以内)：");	
			}
			else
				break;
		}
		q->next=p;
		p->next=NULL;
		saveac(head);
		printf("\n\t恭喜您！注册成功！\n");
		printf("\t按任意键返回......");
		getch();
		return; 
	} 	
}
void saveac(STUAC *head)
{
	FILE *fp;
	fp=fopen("学生账号.txt","w");
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
	fp=fopen("学生成绩.txt","r");
	ch=fgetc(fp);
	if(fp==NULL||ch==EOF)
	{
		return NULL;
	}
	fp=fopen("学生成绩.txt","r");
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
	fp=fopen("学生账号.txt","r");
	if(fp==NULL)
		return NULL; 
	rewind(fp);
	STUAC *head,*p,*q=NULL;
	head=(STUAC *)malloc(sizeof(STUAC));
	q=p=head;
	while(!feof(fp))
	{
		if(fread(p,sizeof(STUAC),1,fp)!=1) //fread函数返回读出数据项的个数
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
	printf("\t\t\t****学生登陆页面****\n");
	char zh[20];
	char mm[20];
	printf("\t\t\t请输入登陆用户名(若不想登陆直接enter)：");
	gets(zh);
	if(strcmp(zh,"")==0)
		return; 
	printf("\t\t\t请输入密码：");
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
    		printf("\n\t\t\t登陆成功！！！\n");
			printf("\t\t\t请稍后......\n");
			Sleep(1000); 
			
			stuzi(p->name,p->zh,p->mm);
			break;
		}//-------------------------------------------------------------------
    	else
    		p=p->next;
	}
	if(p==NULL)
	{
		printf("\n\t\t\t登陆失败！\n"); 
		printf("\t\t\t账号或密码错误，或未注册账号......\n");
		printf("\t\t\t按任意键返回......\n");
		getch();
		return;
	}
	
}



void creattea()
{
	system("cls");
	FILE *fp;
	if(fp=fopen("教师账号.txt","r")==NULL)
	{
		fp=fopen("教师账号.txt","w");
		TEA *head,*p=NULL;
		head=(TEA *)malloc(sizeof(TEA));
		p=head;
		printf("\n\n\n\n\n");
		printf("\t*请输入教师姓名(若不想注册直接enter)：");
		gets(p->name);
		if(strcmp(p->name,"")==0)
		{
			fclose(fp);
			return;
		 } 
		printf("\t*请输入教师性别：");
		scanf("%s",p->sex);
		getchar();
		printf("\t*请输入执教科目：");
		scanf("%s",p->km);
		getchar();
		printf("\t*请输入登陆用户名：");
		scanf("%s",p->zh);
		printf("\t*请输入密码(19位以内)：");
		while(1)
		{
			int n=0;
			char ch;
			while((ch =getch()) != '\r')
			{
        		if(ch == '\b' && n > 0) 
				{
           	 		printf("\b \b");   // 空格+\b 是为了覆盖掉原来的字符 
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
    			printf("\n\t*请重新输入密码(19位以内)：");	
			}
			else
				break;
			
		}
		p->next=NULL;
		fclose(fp);
		savetea(head);//savetea
		printf("\n\t恭喜您注册成功！！！\n");
		printf("\t按任意键返回......\n");
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
		printf("\t*请输入教师姓名(若不想继续直接enter)：");
		gets(p->name);
		if(strcmp(p->name,"")==0)
		{
			fclose(fp);
			return;
		 } 
		printf("\t*请输入教师性别：");
		scanf("%s",p->sex);
		getchar();
		printf("\t*请输入执教科目：");
		scanf("%s",p->km);
		getchar();
		printf("\t*请输入登陆用户名：");
		scanf("%s",p->zh);
		printf("\t*请输入密码(19位以内)：");
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
    			printf("\n\t*请重新输入密码(19位以内)：");
    			
			}
			else
				break;
		}
		q->next=p;
		p->next=NULL;
		savetea(head);
		printf("\n\t恭喜您注册成功！！！\n");
		printf("\t按任意键返回......\n");
		getch();
		return;
	}
 } 
 
void savestu(STU *head)
{
	FILE *fp;
	fp=fopen("学生成绩.txt","w");
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
	fp=fopen("教师账号.txt","w");
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
	fp=fopen("教师账号.txt","r");
	if(fp==NULL)
		return NULL;
	rewind(fp);
	TEA *head,*p,*q=NULL;
	head=(TEA *)malloc(sizeof(TEA));
	q=p=head;
	while(!feof(fp))
	{
		if(fread(p,sizeof(TEA),1,fp)!=1) //fread函数返回读出数据项的个数
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
	printf("\t\t\t****教师登陆页面****\n");
	char zh[20];
	char mm[20];
	printf("\t\t\t请输入登陆用户名(若不想登陆直接enter)：");
	gets(zh);
	if(strcmp(zh,"")==0)
		return;
	printf("\t\t\t请输入密码：");
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
			printf("\n\t\t\t登陆成功......\n");
			printf("\t\t\t正在进入教师管理界面，请稍等......");
			Sleep(1000);
			jiaoshizi(p->name,p->zh,p->mm); 
			return;
		}
		else
			p=p->next;
	}
	if(p==NULL)
	{
		printf("\n\t\t\t登陆失败！\n");
		printf("\t\t\t账号或密码错误，或未注册账号......\n");
		printf("\t\t\t按任意键返回......\n");
		getch();
		return;
	}
	
}
void jiaoshizi(char s[],char zh[],char mm[])//待测试 
{
	while(1)
	{
		system("cls");
		STU *head=NULL;
		char ch;
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t\t\t\t%s老师欢迎你！        \n",s); 
		printf("\t\t\t\t\t*-------------------------------*\n");
		printf("\t\t\t\t\t*\t1.添加学生              *\n");
		printf("\t\t\t\t\t*\t2.删除学生              *\n");
		printf("\t\t\t\t\t*\t3.修改学生信息          *\n");
		printf("\t\t\t\t\t*\t4.查找学生              *\n");
		printf("\t\t\t\t\t*\t5.查看学生信息          *\n");
		printf("\t\t\t\t\t*\t6.排序学生              *\n");
		printf("\t\t\t\t\t*\t注:(按总成绩由高到低)   *\n"); 
		printf("\t\t\t\t\t*\t7.查看教师信息          *\n");
		printf("\t\t\t\t\t*\t8.修改密码              *\n");
		printf("\t\t\t\t\t*\t9.退出登录              *\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t请选择要进行的操作：");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case '1':add();break;//完工 
			case '2':head=readstu();
						if(head!=NULL)
							del(head);
						else
						{
							printf("尚未添加学生！\n即将返回...");
							Sleep(1500);
						 } 
					break;
			case '3':head=readstu();
						if(head!=NULL)
							change(head);
						else
						{
							printf("尚未储存学生成绩！\n即将返回...");
							Sleep(1500);
						}
					break;
			case '4':head=readstu();
						if(head!=NULL)
							search(head);
						else
						{
							printf("尚未储存学生成绩！\n即将返回...");
							Sleep(1500);
						}
					break;
			case '5':head=readstu();
						if(head!=NULL)
							print(head);
						else
						{
							printf("尚未储存学生成绩！\n即将返回...");
							Sleep(1500);
						} 
					break;
			case '6':head=readstu();
						if(head!=NULL)
							sortstu(head);
						else
						{
							printf("尚未储存学生成绩！\n即将返回...");
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
				printf("\t请输入正确选项！！！");
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
	printf("\t\t\t教师修改密码\n");
	printf("\t\t************************\n");
	char s[20];
	printf("\t\t\t请输入新密码：");
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
	printf("\n\t\t\t修改成功！！\n");
	printf("\t\t\t按任意键返回...\n");
	getch();
	return;
}

void add()
{
	system("cls");
	FILE *fp;
	if(fp=fopen("学生成绩.txt","r")==NULL)
	{
		fp=fopen("学生成绩.txt","w");
		STU *head,*p;
		p=head=(STU *)malloc(sizeof(STU));
		printf("\n\n\n\n\n");
		printf("*请输入学生姓名：");
		scanf("%s",p->name);getchar();
		printf("*请输入学生学号：");
		scanf("%s",p->number);getchar();
		printf("*请输入学生语文成绩：");
		scanf("%lf",&p->chinese);getchar();
		printf("*请输入学生数学成绩：");
		scanf("%lf",&p->math);getchar();
		printf("*请输入学生英语成绩：");
		scanf("%lf",&p->english);getchar();
		p->sum=p->chinese+p->english+p->math;
		p->next=NULL;
		fclose(fp);
		savestu(head);//================================================================== 
		printf("添加成功！！\n");
		printf("按任意键返回......\n");
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
		printf("*请输入学生姓名：");
		scanf("%s",p->name);getchar();
		printf("*请输入学生学号：");
		scanf("%s",p->number);getchar();
		printf("*请输入学生语文成绩：");
		scanf("%lf",&p->chinese);getchar();
		printf("*请输入学生数学成绩：");
		scanf("%lf",&p->math);getchar();
		printf("*请输入学生英语成绩：");
		scanf("%lf",&p->english);getchar();
		p->sum=p->chinese+p->english+p->math;
		q->next=p;
		p->next=NULL;
		savestu(head);//==================================================================== 
		printf("添加成功！！\n");
		printf("按任意键返回......\n");
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
	printf("*请输入要删除学生姓名：");
	scanf("%s",name);getchar();
	printf("*请输入要删除学生学号：");
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
				printf("*删除成功！！！\n");
				printf("按任意键返回......");
				getch();
				return;
			}
			else
			{
				q->next=p->next;
				free(p);
				savestu(head);
				printf("*删除成功！！！\n");
				printf("按任意键返回......");
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
		printf("*未找到该学生。\n");
		printf("按任意键返回......");
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
	printf("*请输入要修改学生姓名：");
	scanf("%s",name);getchar();
	printf("*请输入要修改学生学号：");
	scanf("%s",number);getchar();
	STU *p;
	p=head;
	while(p!=NULL)
	{
		if(strcmp(name,p->name)==0&&strcmp(number,p->number)==0)
		{
			printf("该学生信息为：\n");
			printf("学生姓名：%s  ",p->name);
			printf("学生学号：%s  ",p->number);
			printf("\n语文成绩  数学成绩  英语成绩  总成绩\n");
			printf("%.3lf  %.3lf  %.3lf  %.3lf\n",p->chinese,p->math,p->english,p->sum);
			char km[10];
			printf("请输入要修改科目：");
			scanf("%s",km);getchar();
			if(strcmp(km,"语文")==0)
			{
				printf("请输入修改后的成绩：");
				scanf("%lf",&p->chinese);getchar();
				p->sum=p->chinese+p->english+p->math;
				printf("\n修改成功!!!\n");
				savestu(head);
				printf("按任意键返回......");
				getch();
				return;
			} 
			if(strcmp(km,"数学")==0)
			{
				printf("请输入修改后的成绩：");
				scanf("%lf",&p->math);getchar();
				p->sum=p->chinese+p->english+p->math;
				printf("\n修改成功!!!\n");
				savestu(head);
				printf("按任意键返回......");
				getch();
				return;
			} 
			if(strcmp(km,"英语")==0)
			{
				printf("请输入修改后的成绩：");
				scanf("%lf",&p->english);getchar();
				p->sum=p->chinese+p->english+p->math;
				printf("\n修改成功!!!\n");
				savestu(head);
				printf("按任意键返回......");
				getch();
				return;
			}
			
		}
		else
			p=p->next;
	}
	if(p==NULL)
	{
		printf("\n未找到该学生信息......");
		printf("\n按任意键返回。");
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
	printf("*请输入要查找学生姓名：");
	scanf("%s",name);getchar();
	printf("*请输入要查找学生学号：");
	scanf("%s",number);getchar();
	while(p!=NULL)
	{
		if(strcmp(name,p->name)==0&&strcmp(number,p->number)==0)
		{
			printf("该学生信息：\n");
			printf("学生姓名：%s\n",p->name);
			printf("学生学号：%s\n",p->number);
			printf("语文成绩：%.3lf\n",p->chinese);
			printf("数学成绩：%.3lf\n",p->math);
			printf("英语成绩：%.3lf\n",p->english);
			printf("总成绩：%.3lf\n",p->sum);
			printf("按任意键返回......");
			getch();
			return;
		}
		else
			p=p->next;
	}
	if(p==NULL)
	{
		printf("未查找到该学生......\n");
		printf("按任意键返回...");
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
	printf("\t\t学生姓名   学生学号  语文成绩  数学成绩  英语成绩  总成绩\n");
	while(p!=NULL)
	{
		printf("\t\t%-8s   %-8s  %-8.3lf  %-8.3lf  %-8.3lf  %-8.3lf\n",p->name,p->number,p->chinese,p->math,p->english,p->sum);
		count++;
		p=p->next;
	}
	printf("\t\t共计%d名同学。\n",count);
	printf("\t\t按任意键返回......");
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
	printf("排序成功......\n");
	printf("按任意键返回...\n");
	getch();
	return;
}


void printtea()
{
	system("cls");
	printf("*****教师信息*****\n");
	printf("教师姓名  性别  执教科目\n");
	TEA *head;
	head=readtea();
	while(head!=NULL)
	{
		printf("%-8s  %-4s  %-s\n",head->name,head->sex,head->km);
		head=head->next;
	}
	printf("按任意键返回......");
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
		printf("\t\t\t%s同学你好！\n",s);
		printf("\t\t* * * * * * * * * * * * * * *\n");
		char ch;
		printf("\t\t\t1.查看成绩\n");
		printf("\t\t\t2.修改密码\n");
		printf("\t\t\t3.退出登录\n");
		printf("\t请输入选择：");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case '1':
			{
				system("cls");
				STU *head,*p;
				char number[10];
				printf("\t\t\t请输入学号：");
				scanf("%s",number);getchar();
				head=readstu();
				p=head;
				while(p!=NULL)
				{
					if(strcmp(s,p->name)==0&&strcmp(number,p->number)==0)
					{
						printf("\t\t学生姓名   学生学号  语文成绩  数学成绩  英语成绩  总成绩\n");
						printf("\t\t%-8s   %-8s  %-8.3lf  %-8.3lf  %-8.3lf  %-8.3lf\n",p->name,p->number,p->chinese,p->math,p->english,p->sum);
						printf("按任意键返回......");
						getch(); 
						break;
					}
					else
						p=p->next;
				}
				if(p==NULL)
				{
					printf("\t\t教师尚未录入你的成绩信息......\n");
					printf("按任意键返回......");
					getch();
				} 
				break;
			}
			case '2':head=readac();
						cstupwd(head,zh,mm);
					break;
			case '3':return;
			default:{
				printf("\t请输入正确选项！！！");
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
	printf("\t\t\t学生修改密码\n");
	printf("\t\t************************\n");
	char s[20];
	printf("\t\t\t请输入新密码：");
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
	printf("\n\t\t\t修改成功！！\n");
	printf("\t\t\t按任意键返回...\n");
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
		printf("\t\t\t\t\t*       **学生管理系统**        *\n");
		printf("\t\t\t\t\t*-------------------------------*\n");
		printf("\t\t\t\t\t*\t    1.学生端            *\n");
		printf("\t\t\t\t\t*\t    2.教师端            *\n");
		printf("\t\t\t\t\t*\t    3.退出系统          *\n");
		printf("\t\t\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t请输入选择(1或者2或者3)：");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case '1':student();break;
			case '2':teacher();break;
			case '3':exit(0);
			default:{
				printf("\t请输入正确选项！！！");
				Sleep(1000);
				break;
			}	
		}
	}
} 
