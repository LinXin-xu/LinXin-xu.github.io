#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//结构体 
struct student 
{
	char name[20];
	char cla[20];
	char data[20];
	int age;
	int birth;	
	struct student *next; 
};

struct denglu
{
	char username[20];
	char password[20];
	struct denglu *next1;
};


struct student *head=(struct student *)malloc(sizeof(struct student)); 
struct denglu *head1=(struct  denglu*)malloc(sizeof(struct denglu));


//增删改查函数 
void create();
void del();
void modity();
void find_name(); 
void find_data(struct student *temp);
void print();
void print1();


//登录函数
void yemian1();
void denglu();
void zhuce(); 
void leave();

//选择函数
void yemian2();
void choose(struct student *temp);
void choose1(struct student *temp); 
void choose2();
//文件读写函数
void read();
void read1();
void write1();
void write(); 

//登陆页面
void yemian1()
{
	int n;
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\t学生证管理系统\n");
	printf("\t\t\t\t\t\t**************");
	printf("\n\n\n");
	printf("\t\t\t\t   ======================================\n");
	printf("\n"); 
	printf("\t\t\t\t\t\t  1、登录                \n");
	printf("\n");
	printf("\t\t\t\t\t\t  2、注册                \n");
	printf("\n");
	printf("\t\t\t\t\t\t  0、退出                \n");
	printf("\n");
	printf("\t\t\t\t   ======================================\n");
	scanf("%d",&n);
	system("cls");
	switch(n)
	{
		case 1:
			denglu();
			break;
		case 2:
			zhuce();
			break;
		case 0:
			printf("\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t\t**************\n");
			printf("\t\t\t\t\t\t\t学生证管理系统\n");
			printf("\t\t\t\t\t\t\t**************");
			printf("\n\n\n");
		    printf("\t\t\t\t          ******************************************\n"); 
		    printf("\n");
			printf("\t\t\t                                欢迎下次使用！\n");
			printf("\n");
		    printf("\t\t\t\t          ******************************************\n");
			break;
	}
} 

 
void denglu()
{
	struct denglu *temp1; 
	char zhanghao[20];
	char mima[20];
	printf("请输入账号：          \n");
	scanf("%s",zhanghao); 
	
	printf("请输入密码：          \n");
	scanf("%s",mima);
	temp1=head1->next1;

	while(temp1!=NULL)
	{
		if((strcmp(zhanghao,temp1->username)==0)&&(strcmp(mima,temp1->password)==0))
		{
			printf("登录成功!\n");
			system("pause");
			system("cls");
			yemian2();
			break;
		}
		temp1=temp1->next1;
		if(temp1==NULL)
		{
			printf("登录失败!\n");
			system("pause");
			system("cls");
			yemian1();
			break; 
		}
	
	}
}

void zhuce()
{
	char zhanghao[20];
	char mima1[20];
	char mima2[20];
	char ch,c;
	struct denglu *add,*temp1;
	add=(struct denglu *)malloc(sizeof(struct denglu));
	temp1=head1; 
	while(temp1->next1!=NULL)
	{
		temp1=temp1->next1;
	}
	printf("请输入要注册的账号：");
	scanf("%s",zhanghao);

	do
	{ 
		printf("请输入您的密码：");
		scanf("%s",mima1);
		
		printf("请再次输入您的密码：");
		scanf("%s",mima2); 	
	 
		if(strcmp(mima1,mima2)==0)
		{
			printf("注册成功！"); 
			system("pause");
			system("cls");
			strcpy(add->username,zhanghao);	
			strcpy(add->password,mima1);
			break;
		}
		else
		{
			printf("两次输入不一致，是否重新输入？");
			fflush(stdin);
			ch = getchar();
		}
	}while(ch=='y');

	temp1->next1=add;
	add->next1=NULL;
	write1();
                      
	system("pause");
	system("cls");
	yemian1(); 
}

void write()
{
	struct student *temp;
	FILE *fp=fopen("xueshengxinxi.txt","w");
	temp=head->next;
	while(temp!=NULL)
	{
		fprintf(fp,"%s %s %s %d %d\n",temp->name,temp->cla,temp->data,temp->age,temp->birth);
		temp=temp->next;
	}
	fclose(fp);
} 

void write1()
{
	struct denglu *temp1;
	FILE *fp=fopen("denglu.txt","w");
	temp1=head1->next1;
	while(temp1!=NULL)
	{
		fprintf(fp,"%s %s\n",temp1->username,temp1->password);
		temp1=temp1->next1;
	}
	fclose(fp);
	system("cls");
} 

void read1()
{
	struct denglu *temp1,*add;
	char t;
	FILE *fp=fopen("denglu.txt","r"); 
	temp1=head1; 
	while(!feof(fp))
	{
		add=(struct  denglu*)malloc(sizeof(struct denglu));
		fscanf(fp,"%s %s\n",add->username,add->password);
		temp1->next1=add;
		temp1=add;
	}
	temp1->next1=NULL;
	fclose(fp);
} 

void read()
{
	struct student *temp,*add;
	FILE *fp=fopen("xueshengxinxi.txt","r"); 
	temp=head; 
	while(!feof(fp))
	{
		add=(struct  student*)malloc(sizeof(struct student));
		fscanf(fp,"%s %s %s %d %d\n",add->name,add->cla,&add->data,&add->age,&add->birth);
		temp->next=add;
		temp=add;
	}
	temp->next=NULL;
	fclose(fp);
} 

void choose(struct student *temp)
{
	int k;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\t\t学生证管理系统\n");
	printf("\t\t\t\t\t\t\t**************");
	printf("\n\n\n");	
	printf("\t\t\t\t\t   ======================================\n");
	printf("\n"); 
	printf("\t\t\t\t   \t\t         1、输入学号查找                \n");
	printf("\n");
	printf("\t\t\t\t   \t\t         2、输入姓名查找                \n");
	printf("\n");
	printf("\t\t\t\t\t   ======================================\n");
	printf("请选择：") ;
	scanf("%d",&k);
	system("cls");
	switch(k)
	{
		case 1:
			find_data(temp);
			break;
		case 2:
			find_name();
			break;
	}			
} 
void choose1(struct student *temp)
{
	int n;
	char c;
	do
	{
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\t学生证管理系统\n");
	printf("\t\t\t\t\t\t**************");
	printf("\n");	
	printf("\t\t\t\t   ======================================\n");
	printf("\t\t\t\t  ||\t\t1、姓名 \t||\n");
	printf("\n");                          
	printf("\t\t\t\t  ||\t\t2、专业班级 \t||\n");
	printf("\n");	
	printf("\t\t\t\t  ||\t\t3、学号 \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t4、年龄 \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t5、出生日期 \t||\n");
	printf("\n");
	printf("\t\t\t\t   ======================================\n");
	printf("请选择：");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("请输入修改后的姓名："); 
			scanf("%s",temp->name);
			break;
		case 2:
			printf("请输入修改后的专业班级："); 
			scanf("%s",temp->cla);
			break;
		case 3:
			printf("请输入修改后的学号："); 
			scanf("%s",temp->data);
			break;
		case 4:
			printf("请输入修改后的年龄："); 
			scanf("%d",&temp->age);
			break;
		case 5:
			printf("请输入修改后的出生日期："); 
			scanf("%d",&temp->birth);
			break;
	 } 
	 printf("%s\n%s\n%s\n%d\n%d\n",temp->name,temp->cla,temp->data,temp->age,temp->birth);
	 printf("是否继续修改？(y/n)"); 
	 fflush(stdin);
	 scanf("%c",&c);
	}while(c=='y');	
}
void choose2()
{
	struct student *temp;
	int k;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\t\t学生证管理系统\n");
	printf("\t\t\t\t\t\t\t**************");
	printf("\n\n\n");	
	printf("\t\t\t\t\t   ======================================\n");
	printf("\n"); 
	printf("\t\t\t\t   \t\t         1、输入学号查找                \n");
	printf("\n");
	printf("\t\t\t\t   \t\t         2、输入姓名查找                \n");
	printf("\n");
	printf("\t\t\t\t\t   ======================================\n");
	printf("请选择：") ;
	scanf("%d",&k);
	system("cls");
	switch(k)
	{
		case 1:
			find_data(temp);
			break;
		case 2:
			find_name();
			break;
	}			
} 

//开始页面 
void yemian2()
{
	int n,k,i;
	char c;
	
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\t学生证管理系统\n");
	printf("\t\t\t\t\t\t**************");
	printf("\n\n\n");	
	printf("\t\t\t\t   ======================================\n");
	printf("\t\t\t\t  ||\t\t1、学生信息录入 \t||\n");
	printf("\n");                          
	printf("\t\t\t\t  ||\t\t2、学生信息删除 \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t3、学生信息改动 \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t4、学生信息查询 \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t5、学生信息浏览 \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t6、退出登录     \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t0、结束使用     \t||\n");
	printf("\t\t\t\t  ======================================\n");
	printf("请选择功能：");
	scanf("%d", &n);
	system("cls");
	switch(n)
	{
		case 1:
			create();
			system("pause");
			system("cls");
			yemian2();
			break;
		case 2:
			del();
			yemian2();
			break;
		case 3:
			modity();
			system("pause");
			system("cls");	
			yemian2();
			break;
		case 4:
			choose2();
			system("pause");
			system("cls");
			yemian2();
			break;
		case 5:
			print();
			system("pause");
			system("cls");
			yemian2();
			break;
		case 6: 
			yemian1(); 
			break;
		case 0:
			write();
			printf("\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t\t**************\n");
			printf("\t\t\t\t\t\t\t学生证管理系统\n");
			printf("\t\t\t\t\t\t\t**************");
			printf("\n\n\n");
		    printf("\t\t\t\t          ******************************************\n"); 
		    printf("\n");
			printf("\t\t\t                                欢迎下次使用！\n");
			printf("\n");
		    printf("\t\t\t\t          ******************************************\n");
			break;	
	 } 
} 

//创建 
void create()
{
	char name[20],cla[20],data[20];
	int age,birth;
	struct student *add;
	struct student *temp,*p;	
	int n,i=0,j=0;
	temp=head->next;
	p=head->next;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	add=(struct student *)malloc(sizeof(struct student));
	printf("请输入姓名："); 
	scanf("%s",name);
	printf("请输入专业班级："); 
	scanf("%s",cla);
	printf("请输入学号："); 
	scanf("%s",data);		
	printf("请输入年龄："); 
	scanf("%d",&age);
	printf("请输入出生日期："); 
	scanf("%d",&birth); 
	while(p!=NULL)
	{
		if(strcmp(data,p->data)!=0)
		{
			p=p->next;
				
		}
		else
		{
			j++;
			printf("该学生已存在！\n"); 
			break;
		}
	}
	if(j==0)
	{	
		strcpy(add->name,name);
		strcpy(add->cla,cla);
		strcpy(add->data,data);
		add->age=age;
		add->birth=birth;
		temp->next=add;
		temp=add;	
	}
	temp->next=NULL;
}

//删除 
void del()
{
	struct student *temp,*pre;
	pre=head;	
	temp=head->next;
	struct student *p;
	char c;

	printf("请选择查找要删除的人的方法：");
	
	int k;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\t\t学生证管理系统\n");
	printf("\t\t\t\t\t\t\t**************");
	printf("\n\n\n");	
	printf("\t\t\t\t\t   ======================================\n");
	printf("\n"); 
	printf("\t\t\t\t   \t\t         1、输入学号查找                \n");
	printf("\n");
	printf("\t\t\t\t   \t\t         2、输入姓名查找                \n");
	printf("\n");
	printf("\t\t\t\t\t   ======================================\n");
	printf("请选择：") ;
	scanf("%d",&k);
	system("cls");
	switch(k)
	{
		case 1:
			char data[20];
			temp=head->next;
			printf("请输入你要查找的人的学号：");
			scanf("%s",data); 
			do{
				if(strcmp(data,temp->data)==0) 
				{
					printf("姓名：%s\n",temp->name); 
					printf("专业班级：%s\n",temp->cla);
					printf("学号：%s\n",temp->data);
					printf("年龄：%d\n",temp->age);
					printf("出生日期：%d\n",temp->birth);
					printf("确定删除该人信息吗？(y/n)"); 
					fflush(stdin);
					scanf("%c",&c);
					if(c=='y')
					{
						do{
							if(strcmp(pre->next->data,data)==0)
							{
								p=pre->next;
								pre->next=p->next;
								free(p);
								break;
							}
							pre=pre->next;
						}while(pre!=NULL);				
					}							
				}
				temp=temp->next;
			}while(temp!=NULL);
			break;
		case 2:
			char name[20];
			temp=head->next;
			printf("请输入你要查找的人的姓名：");
			scanf("%s",name);
			do{
				if(strcmp(name,temp->name)==0) 
				{
					printf("姓名：%s\n",temp->name); 
					printf("专业班级：%s\n",temp->cla);
					printf("学号：%s\n",temp->data);
					printf("年龄：%d\n",temp->age);
					printf("出生日期：%d\n",temp->birth);
					printf("确定删除该人信息吗？(y/n)"); 
					fflush(stdin);
					scanf("%c",&c);
					if(c=='y')
					{
						do{
							if(strcmp(pre->next->name,name)==0)
							{
								p=pre->next;
								pre->next=p->next;
								free(p);
								break;
							}
							pre=pre->next;
						}while(pre!=NULL);				
					}		
				}	
				temp=temp->next;
			}while(temp!=NULL);
			break;
	}
	system("pause");
	system("cls");
 } 
//修改 
void modity()
{
	struct student *temp,*p;
	int n,k;	
	char c;
	char name[20],name1[20];
	char cla[20],cla1[20];
	char data[20],data1[20];
	int age,age1;
	int birth,birth1; 
	temp=head->next;
	printf("请选择你要修改的信息：");
	
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\t学生证管理系统\n");
	printf("\t\t\t\t\t\t**************");
	printf("\n");	
	printf("\t\t\t\t   ======================================\n");
	printf("\t\t\t\t  ||\t\t1、姓名 \t||\n");
	printf("\n");                          
	printf("\t\t\t\t  ||\t\t2、专业班级 \t||\n");
	printf("\n");	
	printf("\t\t\t\t  ||\t\t3、学号 \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t4、年龄 \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t5、出生日期 \t||\n");
	printf("\n");
	printf("\t\t\t\t   ======================================\n");
	printf("请选择：");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("请输入姓名："); 
			scanf("%s",name);
			while(temp!=NULL)
			{
				if((strcmp(temp->name,name)==0))
				{
					printf("请输入修改后的姓名:"); 
					scanf("%s",name1);
					strcpy(temp->name,name1);
				}
				temp=temp->next;	
			}
			break;
		case 2:
			printf("请输入专业班级："); 
			scanf("%s",cla);
			while(temp!=NULL)
			{
				if((strcmp(temp->cla,cla)==0))
				{
					printf("请输入修改后的专业班级:"); 
					scanf("%s",cla1);
					strcpy(temp->cla,cla1);
				}
				temp=temp->next;	
			} 
			break;
		case 3:
			printf("请输入学号："); 
			scanf("%s",data);
			while(temp!=NULL)
			{
				if((strcmp(temp->data,data)==0))
				{
					printf("请输入修改后的学号:"); 
					scanf("%s",data1);
					strcpy(temp->data,data1);
				}
				temp=temp->next;	
			}
			break;
		case 4:
			printf("请输入年龄："); 
			scanf("%d",age);
			while(temp!=NULL)
			{
				if(temp->age==age)
				{
					printf("请输入修改后的年龄:"); 
					scanf("%d",age1);
					temp->age=age1; 
				}
				temp=temp->next;	
			}
			break;
		case 5:
			printf("请输入出生日期："); 
			scanf("%d",&birth);
			while(temp!=NULL)
			{
				if(temp->birth==birth)
				{
					printf("请输入修改后的出生日期:"); 
					scanf("%d",&birth1);
					temp->birth=birth1; 
				}
				temp=temp->next;	
			}
			break;
	} 
	system("cls");
	system("pause");
	yemian2();
}
//查找 
void find_data(struct student *temp)
{

	int i=0;
	char data[20];
	printf("请输入你要查找的人的学号：");
	scanf("%s",data); 
	while(temp!=NULL){
		
		if(strcmp(data,temp->data)==0) 
		{
			printf("姓名：%s\n",temp->name); 
			printf("专业班级：%s\n",temp->cla);
			printf("学号：%s\n",temp->data);
			printf("年龄：%d\n",temp->age);
			printf("出生日期：%d\n",temp->birth);	
		}
		temp=temp->next;
	}
}

void find_name()
{
	struct student *temp;
	char name[20];
	temp=head->next;
	printf("请输入你要查找的人的姓名：");
	scanf("%s",name);
	do{
		if(strcmp(name,temp->name)==0) 
		{
			printf("姓名：%s\n",temp->name); 
			printf("专业班级：%s\n",temp->cla);
			printf("学号：%s\n",temp->data);
			printf("年龄：%d\n",temp->age);
			printf("出生日期：%d\n",temp->birth);	
		}
		temp=temp->next;
	}while(temp!=NULL);
 } 


void print()
{
	struct student *temp; 
	int i=1;
	temp=head->next;
	printf("\n\n\n");
	printf("学生信息如下:\n");
	while(temp!=NULL)
	{
		printf("%d.",i);
		printf("姓名:%s ",temp->name); 
		printf("专业班级:%s ",temp->cla);
		printf("学号:%s ",temp->data);
		printf("年龄:%d ",temp->age);
		printf("出生日期:%d\n",temp->birth);
		temp=temp->next;
		i++;
	}
	system("pause");
	system("cls");
	yemian2();
}


//主函数 
int main()
{
	head->next=NULL;
	head1->next1=NULL;
	read1();
	read();
	yemian1();
	
	//yemian2();
}
