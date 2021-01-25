#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//�ṹ�� 
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


//��ɾ�Ĳ麯�� 
void create();
void del();
void modity();
void find_name(); 
void find_data(struct student *temp);
void print();
void print1();


//��¼����
void yemian1();
void denglu();
void zhuce(); 
void leave();

//ѡ����
void yemian2();
void choose(struct student *temp);
void choose1(struct student *temp); 
void choose2();
//�ļ���д����
void read();
void read1();
void write1();
void write(); 

//��½ҳ��
void yemian1()
{
	int n;
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\tѧ��֤����ϵͳ\n");
	printf("\t\t\t\t\t\t**************");
	printf("\n\n\n");
	printf("\t\t\t\t   ======================================\n");
	printf("\n"); 
	printf("\t\t\t\t\t\t  1����¼                \n");
	printf("\n");
	printf("\t\t\t\t\t\t  2��ע��                \n");
	printf("\n");
	printf("\t\t\t\t\t\t  0���˳�                \n");
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
			printf("\t\t\t\t\t\t\tѧ��֤����ϵͳ\n");
			printf("\t\t\t\t\t\t\t**************");
			printf("\n\n\n");
		    printf("\t\t\t\t          ******************************************\n"); 
		    printf("\n");
			printf("\t\t\t                                ��ӭ�´�ʹ�ã�\n");
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
	printf("�������˺ţ�          \n");
	scanf("%s",zhanghao); 
	
	printf("���������룺          \n");
	scanf("%s",mima);
	temp1=head1->next1;

	while(temp1!=NULL)
	{
		if((strcmp(zhanghao,temp1->username)==0)&&(strcmp(mima,temp1->password)==0))
		{
			printf("��¼�ɹ�!\n");
			system("pause");
			system("cls");
			yemian2();
			break;
		}
		temp1=temp1->next1;
		if(temp1==NULL)
		{
			printf("��¼ʧ��!\n");
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
	printf("������Ҫע����˺ţ�");
	scanf("%s",zhanghao);

	do
	{ 
		printf("�������������룺");
		scanf("%s",mima1);
		
		printf("���ٴ������������룺");
		scanf("%s",mima2); 	
	 
		if(strcmp(mima1,mima2)==0)
		{
			printf("ע��ɹ���"); 
			system("pause");
			system("cls");
			strcpy(add->username,zhanghao);	
			strcpy(add->password,mima1);
			break;
		}
		else
		{
			printf("�������벻һ�£��Ƿ��������룿");
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
	printf("\t\t\t\t\t\t\tѧ��֤����ϵͳ\n");
	printf("\t\t\t\t\t\t\t**************");
	printf("\n\n\n");	
	printf("\t\t\t\t\t   ======================================\n");
	printf("\n"); 
	printf("\t\t\t\t   \t\t         1������ѧ�Ų���                \n");
	printf("\n");
	printf("\t\t\t\t   \t\t         2��������������                \n");
	printf("\n");
	printf("\t\t\t\t\t   ======================================\n");
	printf("��ѡ��") ;
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
	printf("\t\t\t\t\t\tѧ��֤����ϵͳ\n");
	printf("\t\t\t\t\t\t**************");
	printf("\n");	
	printf("\t\t\t\t   ======================================\n");
	printf("\t\t\t\t  ||\t\t1������ \t||\n");
	printf("\n");                          
	printf("\t\t\t\t  ||\t\t2��רҵ�༶ \t||\n");
	printf("\n");	
	printf("\t\t\t\t  ||\t\t3��ѧ�� \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t4������ \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t5���������� \t||\n");
	printf("\n");
	printf("\t\t\t\t   ======================================\n");
	printf("��ѡ��");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("�������޸ĺ��������"); 
			scanf("%s",temp->name);
			break;
		case 2:
			printf("�������޸ĺ��רҵ�༶��"); 
			scanf("%s",temp->cla);
			break;
		case 3:
			printf("�������޸ĺ��ѧ�ţ�"); 
			scanf("%s",temp->data);
			break;
		case 4:
			printf("�������޸ĺ�����䣺"); 
			scanf("%d",&temp->age);
			break;
		case 5:
			printf("�������޸ĺ�ĳ������ڣ�"); 
			scanf("%d",&temp->birth);
			break;
	 } 
	 printf("%s\n%s\n%s\n%d\n%d\n",temp->name,temp->cla,temp->data,temp->age,temp->birth);
	 printf("�Ƿ�����޸ģ�(y/n)"); 
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
	printf("\t\t\t\t\t\t\tѧ��֤����ϵͳ\n");
	printf("\t\t\t\t\t\t\t**************");
	printf("\n\n\n");	
	printf("\t\t\t\t\t   ======================================\n");
	printf("\n"); 
	printf("\t\t\t\t   \t\t         1������ѧ�Ų���                \n");
	printf("\n");
	printf("\t\t\t\t   \t\t         2��������������                \n");
	printf("\n");
	printf("\t\t\t\t\t   ======================================\n");
	printf("��ѡ��") ;
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

//��ʼҳ�� 
void yemian2()
{
	int n,k,i;
	char c;
	
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\tѧ��֤����ϵͳ\n");
	printf("\t\t\t\t\t\t**************");
	printf("\n\n\n");	
	printf("\t\t\t\t   ======================================\n");
	printf("\t\t\t\t  ||\t\t1��ѧ����Ϣ¼�� \t||\n");
	printf("\n");                          
	printf("\t\t\t\t  ||\t\t2��ѧ����Ϣɾ�� \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t3��ѧ����Ϣ�Ķ� \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t4��ѧ����Ϣ��ѯ \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t5��ѧ����Ϣ��� \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t6���˳���¼     \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t0������ʹ��     \t||\n");
	printf("\t\t\t\t  ======================================\n");
	printf("��ѡ���ܣ�");
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
			printf("\t\t\t\t\t\t\tѧ��֤����ϵͳ\n");
			printf("\t\t\t\t\t\t\t**************");
			printf("\n\n\n");
		    printf("\t\t\t\t          ******************************************\n"); 
		    printf("\n");
			printf("\t\t\t                                ��ӭ�´�ʹ�ã�\n");
			printf("\n");
		    printf("\t\t\t\t          ******************************************\n");
			break;	
	 } 
} 

//���� 
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
	printf("������������"); 
	scanf("%s",name);
	printf("������רҵ�༶��"); 
	scanf("%s",cla);
	printf("������ѧ�ţ�"); 
	scanf("%s",data);		
	printf("���������䣺"); 
	scanf("%d",&age);
	printf("������������ڣ�"); 
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
			printf("��ѧ���Ѵ��ڣ�\n"); 
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

//ɾ�� 
void del()
{
	struct student *temp,*pre;
	pre=head;	
	temp=head->next;
	struct student *p;
	char c;

	printf("��ѡ�����Ҫɾ�����˵ķ�����");
	
	int k;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\t\tѧ��֤����ϵͳ\n");
	printf("\t\t\t\t\t\t\t**************");
	printf("\n\n\n");	
	printf("\t\t\t\t\t   ======================================\n");
	printf("\n"); 
	printf("\t\t\t\t   \t\t         1������ѧ�Ų���                \n");
	printf("\n");
	printf("\t\t\t\t   \t\t         2��������������                \n");
	printf("\n");
	printf("\t\t\t\t\t   ======================================\n");
	printf("��ѡ��") ;
	scanf("%d",&k);
	system("cls");
	switch(k)
	{
		case 1:
			char data[20];
			temp=head->next;
			printf("��������Ҫ���ҵ��˵�ѧ�ţ�");
			scanf("%s",data); 
			do{
				if(strcmp(data,temp->data)==0) 
				{
					printf("������%s\n",temp->name); 
					printf("רҵ�༶��%s\n",temp->cla);
					printf("ѧ�ţ�%s\n",temp->data);
					printf("���䣺%d\n",temp->age);
					printf("�������ڣ�%d\n",temp->birth);
					printf("ȷ��ɾ��������Ϣ��(y/n)"); 
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
			printf("��������Ҫ���ҵ��˵�������");
			scanf("%s",name);
			do{
				if(strcmp(name,temp->name)==0) 
				{
					printf("������%s\n",temp->name); 
					printf("רҵ�༶��%s\n",temp->cla);
					printf("ѧ�ţ�%s\n",temp->data);
					printf("���䣺%d\n",temp->age);
					printf("�������ڣ�%d\n",temp->birth);
					printf("ȷ��ɾ��������Ϣ��(y/n)"); 
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
//�޸� 
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
	printf("��ѡ����Ҫ�޸ĵ���Ϣ��");
	
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t**************\n");
	printf("\t\t\t\t\t\tѧ��֤����ϵͳ\n");
	printf("\t\t\t\t\t\t**************");
	printf("\n");	
	printf("\t\t\t\t   ======================================\n");
	printf("\t\t\t\t  ||\t\t1������ \t||\n");
	printf("\n");                          
	printf("\t\t\t\t  ||\t\t2��רҵ�༶ \t||\n");
	printf("\n");	
	printf("\t\t\t\t  ||\t\t3��ѧ�� \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t4������ \t||\n");
	printf("\n");
	printf("\t\t\t\t  ||\t\t5���������� \t||\n");
	printf("\n");
	printf("\t\t\t\t   ======================================\n");
	printf("��ѡ��");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("������������"); 
			scanf("%s",name);
			while(temp!=NULL)
			{
				if((strcmp(temp->name,name)==0))
				{
					printf("�������޸ĺ������:"); 
					scanf("%s",name1);
					strcpy(temp->name,name1);
				}
				temp=temp->next;	
			}
			break;
		case 2:
			printf("������רҵ�༶��"); 
			scanf("%s",cla);
			while(temp!=NULL)
			{
				if((strcmp(temp->cla,cla)==0))
				{
					printf("�������޸ĺ��רҵ�༶:"); 
					scanf("%s",cla1);
					strcpy(temp->cla,cla1);
				}
				temp=temp->next;	
			} 
			break;
		case 3:
			printf("������ѧ�ţ�"); 
			scanf("%s",data);
			while(temp!=NULL)
			{
				if((strcmp(temp->data,data)==0))
				{
					printf("�������޸ĺ��ѧ��:"); 
					scanf("%s",data1);
					strcpy(temp->data,data1);
				}
				temp=temp->next;	
			}
			break;
		case 4:
			printf("���������䣺"); 
			scanf("%d",age);
			while(temp!=NULL)
			{
				if(temp->age==age)
				{
					printf("�������޸ĺ������:"); 
					scanf("%d",age1);
					temp->age=age1; 
				}
				temp=temp->next;	
			}
			break;
		case 5:
			printf("������������ڣ�"); 
			scanf("%d",&birth);
			while(temp!=NULL)
			{
				if(temp->birth==birth)
				{
					printf("�������޸ĺ�ĳ�������:"); 
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
//���� 
void find_data(struct student *temp)
{

	int i=0;
	char data[20];
	printf("��������Ҫ���ҵ��˵�ѧ�ţ�");
	scanf("%s",data); 
	while(temp!=NULL){
		
		if(strcmp(data,temp->data)==0) 
		{
			printf("������%s\n",temp->name); 
			printf("רҵ�༶��%s\n",temp->cla);
			printf("ѧ�ţ�%s\n",temp->data);
			printf("���䣺%d\n",temp->age);
			printf("�������ڣ�%d\n",temp->birth);	
		}
		temp=temp->next;
	}
}

void find_name()
{
	struct student *temp;
	char name[20];
	temp=head->next;
	printf("��������Ҫ���ҵ��˵�������");
	scanf("%s",name);
	do{
		if(strcmp(name,temp->name)==0) 
		{
			printf("������%s\n",temp->name); 
			printf("רҵ�༶��%s\n",temp->cla);
			printf("ѧ�ţ�%s\n",temp->data);
			printf("���䣺%d\n",temp->age);
			printf("�������ڣ�%d\n",temp->birth);	
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
	printf("ѧ����Ϣ����:\n");
	while(temp!=NULL)
	{
		printf("%d.",i);
		printf("����:%s ",temp->name); 
		printf("רҵ�༶:%s ",temp->cla);
		printf("ѧ��:%s ",temp->data);
		printf("����:%d ",temp->age);
		printf("��������:%d\n",temp->birth);
		temp=temp->next;
		i++;
	}
	system("pause");
	system("cls");
	yemian2();
}


//������ 
int main()
{
	head->next=NULL;
	head1->next1=NULL;
	read1();
	read();
	yemian1();
	
	//yemian2();
}
