#include<stdio.h>
#include<stdlib.h>

/* �ṹ����� --------------------------------------------------------------------*/

int N1,N2,kk1,kk2,kk3;
struct couse * head1;
struct student * head2;
struct couse  //�γ���Ϣ�ṹ��
{
    int num1;
    char name1[20];
    int score;
    int nelepeo;  //�γ���ѡ����
    int Melepeo;  //�γ���������
    struct couse * next;
};
struct student//ѧ����Ϣ�ṹ��
{
    int num2;
    char name2[20];
    int nelenum[50];  //��ѡ�γ̱��
    int nelen;  //��ѡ�γ�����
    struct student * next;
};

void Ms()
{
    for(kk1=0;kk1<1100;kk1++)
                for(kk2=0;kk2<1200;kk2++)
                    for(kk3=0;kk3<1200;kk3++);
}

/* �ļ�����ģ�� ------------------------------------------------------------------------*/

void readfile_course()  //���ؿγ���Ϣ
{
    FILE * fp;
    char filepath[20];
    struct couse *p1,*p2;
    N1=0;
    fp=fopen("info-course.txt","r");
    if((fp=fopen("info-course.txt","r"))==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| �Ҳ���info-course.txt�ļ�!                               |\n");
        exit(0);
    }
    p1=p2=(struct couse*)malloc(sizeof(struct couse));
    fscanf(fp,"%d%s%d%d%d",&p1->num1,p1->name1,&p1->score,&p1->nelepeo,&p1->Melepeo);
    head1=NULL;
    while(!feof(fp))
    {
        N1=N1+1;
        if(N1==1)head1=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct couse * )malloc(sizeof(struct couse));
        fscanf(fp,"%d%s%d%d%d",&p1->num1,p1->name1,&p1->score,&p1->nelepeo,&p1->Melepeo);
    }
    p2->next=NULL;
}

void readfile_student()  //����ѧ����Ϣ
{
    int i=0;
    FILE * fp;
    char filepath[20];
    struct student *p1,*p2;
    N2=0;
    fp=fopen("info-student.txt","r");
    if((fp=fopen("info-student.txt","r"))==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("|�Ҳ���info-student.txt�ļ�!                               |\n");
        exit(0);
    }
    p1=p2=(struct student*)malloc(sizeof(struct student));
    fread(p1,sizeof(struct student),1,fp);
    head2=NULL;
    while(!feof(fp))
    {
        i=0;
        N2=N2+1;
        if(N2==1)head2=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct student * )malloc(sizeof(struct student));
        fread(p1,sizeof(struct student),1,fp);
    }
    p2->next=NULL;
}

/* �γ̹���ģ��----------------------------------------------------------------------------------------*/

void insert_course(struct couse *incouse) //�γ̹����Ӻ���(���ӿγ�)
{
    struct couse *p0,*p1,*p2;
    p1=head1;
    p0=incouse;
    if(head1==NULL)
    {
        head1=p0;
        p0->next=NULL;
    }
    else
    {
        while((p0->num1 > p1->num1) && (p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num1 <= p1->num1)
        {
            if(head1==p1) head1=p0;
            else p2->next=p0;
            p0->next=p1;
        }
        else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    N1=N1+1;
}
void delete_course(int num1)  //�γ̹����Ӻ���(ɾ���γ�)
{
    struct couse *p1,*p2;
    if(head1==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| û�пγ�,�޷�ɾ��!                                       |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        goto end;
    }
    p1=head1;
    while(num1!=p1->num1 && p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(num1==p1->num1)
    {
        if(p1==head1) head1=p1->next;
        else p2->next=p1->next;
        printf("+---------------------------------------------------------+\n");
        printf("|��ɾ���ñ�ſγ�!                                        |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        N1=N1-1;
    }
    else
    {
        printf("+---------------------------------------------------------+\n");
        printf("| �޸ñ�ŵĿγ�!                                         |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
    }
    end:;
}
void management_course()  //�γ̹���������
{
    struct couse * incouse;
    int i,num1;
    printf("+---------------------------------------------------------+\n");
    printf("|                        �γ̹���                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|1 | �����γ�                                             |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|2 | ɾ���γ�                                             |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|3 | �������˵�                                           |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("| ��ѡ��(1~3):                                            |\n");
    scanf("%d",&i);
    switch(i)
    {
    case(1):
        {
            system("cls");
            incouse=(struct couse *)malloc(sizeof(struct couse));
            printf("+--------+------------------------------+----+------------+\n");
            printf("|�γ̱��|�γ�����                      |ѧ��|�γ���������|\n");
            printf("+--------+------------------------------+----+------------+\n");
            scanf("%d%s%d%d",&incouse->num1,incouse->name1,&incouse->score,&incouse->Melepeo);
            incouse->nelepeo=0;
            insert_course(incouse);
            system("cls");
            printf("+---------------------------------------------------------+\n");
            printf("| ��ӳɹ�!                                               |\n" );
            break;
        }
    case(2):
        {
            system("cls");
            printf("+---------------------------------------------------------+\n");
            printf("|������Ҫɾ���γ̵ı��:                                  |\n");
            scanf("%d",&num1);
            delete_course(num1);
            system("cls");
            printf("+---------------------------------------------------------+\n");
            printf("| ɾ���ɹ�!                                               |\n");
            break;
        }
    case(3):system("cls");break;
    }
}



/* ѧ����Ϣ����ģ��--------------------------------------------------------------------------- */

void insert_student(struct student * incouse)  //ѧ����Ϣ�����Ӻ���(���ѧ����Ϣ)
{
    struct student *p0,*p1,*p2;
    p1=head2;
    p0=incouse;
    if(head2==NULL)
    {
        head2=p0;
        p0->next=NULL;
    }
    else
    {
        while((p0->num2 > p1->num2) && (p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num2 <= p1->num2)
        {
            if(head2==p1) head2=p0;
            else p2->next=p0;
            p0->next=p1;
        }
        else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    N2=N2+1;
}
void delete_student(int num2)  //ѧ����Ϣ�����Ӻ�����ɾ��ѧ����Ϣ)
{
    struct student *p1,*p2;
    if(head2==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| û�и�ѧ����Ϣ,�޷�ɾ��!                                   |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        goto end;
    }
    p1=head2;
    while(num2!=p1->num2 && p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(num2==p1->num2)
    {
        if(p1==head2) head2=p1->next;
        else p2->next=p1->next;
        printf("+---------------------------------------------------------+\n");
        printf("|��ɾ����ѧ����Ϣ!                                        |\n");
        N2=N2-1;
    }
    else
    {
      printf("+---------------------------------------------------------+\n");
      printf("|�޸�ѧ�ŵ�ѧ��!                                          |\n");
    }
    end:;
}
void management_student()  //ѧ����Ϣ����������
{
    struct student * incouse;
    int i,num2;
    printf("+---------------------------------------------------------+\n");
    printf("|                      ѧ����Ϣ����                       |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|1 | ����ѧ����Ϣ                                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|2 | ɾ��ѧ����Ϣ                                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|3 | �������˵�                                           |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|��ѡ��(1~3):                                             |\n");
    scanf("%d",&i);
    switch(i)
    {
    case(1):
        {
            system("cls");
            incouse=(struct student *)malloc(sizeof(struct student));
            incouse->nelen=0;
            incouse->nelenum[0]=0;
            printf("+--------+--------+---------------------------------------+\n");
            printf("|ѧ��ѧ��|ѧ������|                                       |\n");
            printf("+--------+--------+---------------------------------------+\n");
            scanf("%d %s",&incouse->num2,incouse->name2);
            insert_student(incouse);
            system("cls");
            printf("+---------------------------------------------------------+\n");
            printf("| �����ɹ�!                                               |\n" );
            break;
        }
    case(2):
        {
            system("cls");
            printf("+---------------------------------------------------------+\n");
            printf("|������Ҫɾ��ѧ����ѧ��:                                  |\n");
            scanf("%d",&num2);
            system("cls");
            delete_student(num2);
            break;
        }
    case(3):system("cls");break;
    }
}
void elect(struct student * s)//ѡ��
{
    struct couse * p;
    int num1,i;
    system("cls");
    printf("+---------------------------------------------------------+\n");
    printf("|������Ҫѡ�εı��:                                       |\n");
    scanf("%d",&num1);
    for(i=0;s->nelenum[i]!=0;i++);
    s->nelenum[i]=num1;
    (s->nelen)++;
    p=head1;
    while(p->num1!=num1) p=p->next;
    (p->nelepeo)++;
    system("cls");
    printf("+---------------------------------------------------------+\n");
    printf("| ѡ�γɹ�!                                               |\n");
    printf("+---------------------------------------------------------+\n");
}

/* ѡ��ϵͳ����-------------------------------------------------------------------------- */

void cheak() //ѧ��ѡ���Ӻ���(��ѯ��ѡ�γ�)
{
    char e;
    struct couse * c;
    struct student * s;
    int num2,i,j=0,t=0;
    printf("+---------------------------------------------------------+\n");
    printf("|���������ѧ��:                                          |\n");
    scanf("%d",&num2);
    s=head2;
    while(s->num2!=num2 && s->next!=NULL) s=s->next;
    if(s->num2!=num2)
    {
        printf("+---------------------------------------------------------+\n");
        printf("|�����������Ϣ,���ý�ʦ¼�������Ϣ!                     |\n");
        printf("+---------------------------------------------------------+\n");
        goto end;
    }
    c=head1;
    system("cls");
    printf("+---------------------------------------------------------+\n");
    printf("|��Ŀ�ѡ�γ̱��:                                        |\n");
    printf("+---------------------------------------------------------+\n");
    while(c!=NULL)
    {
        for(t=0,i=0;s->nelenum[i]!=0;i++)
        {
            if(c->num1==s->nelenum[i]) t=1;
        }
        if(t==0 && (c->nelepeo!=c->Melepeo))
        {
            printf("|%-4d|                                                    |\n",c->num1);
            printf("+---------------------------------------------------------+\n");
            j++;
        }
        c=c->next;
    }
    if(j==0)
    {
        printf("| ����ѡ�����пγ̣��޷��ٶ�ѡ!                              |\n");
        printf("+---------------------------------------------------------+\n");
        goto end;
    }
    printf("|ѡ��(y/n)?:                                              |\n");
    getchar();
    e=getchar();
    i=0;
    while(e=='y')
    {
        elect(s);

        printf("|����ѡ��(y/n)?:                                          |\n");
        getchar();
        e=getchar();
    }
    system("cls");
    end:;
}
void back(struct student * p)  //�˿�
{
    struct couse * p1;
    int num1,i,j;
    system("cls");
    printf("+---------------------------------------------------------+\n");
    printf("|��������Ҫ�˵��Ŀγ̱��:                                |\n");
    scanf("%d",&num1);
    p1=head1;
    while(p1->num1!=num1) p1=p1->next;
    for(i=0;p->nelenum[i]!=num1;i++);
    for(j=i;p->nelenum[j]!=0;j++) p->nelenum[j]=p->nelenum[j+1];
    p->nelenum[--j]=0;
    (p1->nelepeo)--;
    printf("+---------------------------------------------------------+\n");
    printf("| �˿γɹ�!                                               |\n");
    printf("+---------------------------------------------------------+\n");
}
void hcheak()  //ѧ��ѡ���Ӻ�������ѯ��ѡ�γ�)
{
    char c;
    struct couse * p0;
    struct student * p;
    int num2,i,f=0;
    system("cls");
    printf("+---------------------------------------------------------+\n");
    printf("| ������ѧ��:                                             |\n");
    scanf("%d",&num2);
    p=head2;
    system("cls");
    while(p->num2!=num2 && p!=NULL) p=p->next;
    if(p==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("|�����������Ϣ,������˵�¼����Ϣ:                          |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        goto end;
    }
    printf("+--------------+------------------------------------------+\n");
    printf("| ��ѡ�γ̱�� |                                          |\n");
    printf("+---------------------------------------------------------+\n");
    if(p->nelenum[0]==0)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| �㻹ûѡ��!                                              |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        goto end;
    }
    for(i=0;p->nelenum[i]!=0;i++)
    {
        printf("|%14d|                                          |\n",p->nelenum[i]);
        p0=head1;
        while(p0->num1!=p->nelenum[i]) p0=p0->next;
        f=f+p0->score;
    }
    printf("+---------------------------------------------------------+\n");
    printf("|��ѧ��: %d                                               |\n",f);
    printf("+---------------------------------------------------------+\n");
    printf("| �Ƿ�����˿�(y/n)?                                      |\n");
    getchar();
    c=getchar();
    while(c=='y')
    {
        system("cls");
        back(p);
        printf("| �����˿�(y/n)?                                          |\n");
        getchar();
        c=getchar();
        (p->nelen)--;
    }
    system("cls");
    end:;
}
void elective()//ѧ��ѡ��������
{
    int i;
    printf("+---------------------------------------------------------+\n");
    printf("|                         ѧ��ѡ��                        |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|1 | ��ѯ��ѡ�γ�                                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|2 | ��ѯ��ѡ�γ�                                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|3 | �������˵�                                           |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("������(1~3):                                              |\n");
    scanf("%d",&i);
    switch(i)
    {
    case(1):system("cls");cheak();break;
    case(2):system("cls");hcheak();break;
    case(3):system("cls");break;
    }
}
void list_course()//����γ���Ϣ
{
    struct couse * p;
    p=head1;
    printf("+--------+----------------+----+------------+-------------+\n");
    printf("|�γ̱��|        �γ�����|ѧ��|�γ���ѡ����| �γ���������|\n");
    printf("+--------+----------------+----+------------+-------------+\n");
    while(p!=NULL)
    {
        printf("|%8d|%16s|%4d|%12d|%13d|\n",p->num1,p->name1,p->score,p->nelepeo,p->Melepeo);
        p=p->next;
    }
    printf("+--------+----------------+----+------------+-------------+\n");
    printf("\n");
    printf("\n");
}

void list_student()//���ѧ����Ϣ
{
    struct student * p;
    p=head2;
    printf("+--------+-----------------------------------+------------+\n");
    printf("|ѧ��ѧ��|                           ѧ������|��ѡ�γ�����|\n");
    printf("+--------+-----------------------------------+------------+\n");
    while(p!=NULL)
    {
        printf("|%8d|%35s|%12d|\n",p->num2,p->name2,p->nelen);
        p=p->next;
    }
    printf("+--------+-----------------------------------+------------+\n");
    printf("\n");
    printf("\n");
}

/* ����ģ�麯��----------------------------------------------------------------------- */

void savefile_course()//�洢�γ���Ϣ
{
    FILE * fp;
    struct couse * p;
    char filepath[30];
    fp=fopen("info-course.txt","w");
    if((fp=fopen("info-course.txt","w"))==NULL)
    {
        printf("\n+---------------------------------------------------------+\n");
        printf("| ����ʧ��!                                               |\n");
        exit(0);
    }
    p=head1;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %d %d %d\n",p->num1,p->name1,p->score,p->nelepeo,p->Melepeo);
        p=p->next;
    }
    fclose(fp);
    printf("\n+---------------------------------------------------------+\n");
    printf("| �γ���Ϣ�ѱ�����info-course.txt��!                      |\n");
}
void savefile_student() //�洢ѧ����Ϣ
{
    FILE * fp;
    struct student * p;
    char filepath[30];
    fp=fopen("info-student.txt","w");
    if((fp=fopen("info-student.txt","w"))==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| ����ʧ��!                                               |\n");
        exit(0);
    }
    p=head2;
    while(p!=NULL)
    {
        fwrite(p,sizeof(struct student),1,fp);
        p=p->next;
    }
    fclose(fp);
    printf("+---------------------------------------------------------+\n");
    printf("| ѧ����Ϣ�ѱ�����info-student.txt��!                     |\n");
}
void save_all() //�洢��Ϣ
{
    savefile_course();
    savefile_student();
}


/* ������&&�˵����� ------------------------------------------------------------------------------ */

void index_info()//��Ϣ������
{
    int i;
    printf("+---------------------------------------------------------+\n");
    printf("| ѡ����Ϣ���洢                                          |\n");
    printf("|---------------------------------------------------------|\n");
    printf("|1 | �鿴�γ���Ϣ                                         |\n");
    printf("|--+------------------------------------------------------|\n");
    printf("|2 | �洢��Ϣ                                             |\n");
    printf("|--+------------------------------------------------------|\n");
    printf("|3 | �������˵�                                           |\n");
    printf("|---------------------------------------------------------|\n");
    printf("|������(1~3):                                             |\n");
    scanf("%d",&i);
    switch(i)
    {
    case(1):system("cls");list_course();break;
    case(2):system("cls");save_all();break;
    case(3):system("cls");break;
    }
}
void teacher_manage()
{
    int p,i;
    printf("+---------------------------------------------------------+\n");
    printf("| ��ʦ����ϵͳ                                            |\n" );
    printf("+---------------------------------------------------------|\n");
    printf("����������                                                |\n");
    scanf("%d",&p);
    if(p==12345678)
    {
        system("cls");
        printf("+---------------------------------------------------------+\n");
        printf("|                           �˵�                          |\n");
        printf("|---------------------------------------------------------|\n");
        printf("|1 | ����/ɾ���γ�                                        |\n");
        printf("|--+------------------------------------------------------|\n");
        printf("|2 | �鿴�γ���Ϣ                                         |\n");
        printf("|--+------------------------------------------------------|\n");
        printf("|3 | ����/ɾ��ѧ��                                        |\n");
        printf("|--+------------------------------------------------------|\n");
        printf("|4 | �鿴ѧ����Ϣ                                         |\n");
        printf("|--+------------------------------------------------------|\n");
        printf("|5 | �������˵�                                           |\n");
        printf("|---------------------------------------------------------|\n");
        printf("|������(1~5):                                             |\n");
        scanf("%d",&i);
        switch (i) {
            case (1):system("cls");management_course();break;
            case (2):system("cls");list_course();break;
            case (3):system("cls");management_student();break;
            case (4):system("cls");list_student();break;
            case(5):system("cls");break;
        }
    }
    else
    {
        printf("+---------------------------------------------------------+\n");
        printf("| �������                                                |\n");
    }
}

int main()  //������
{
    int i;
    system("cls");
    readfile_course();
    readfile_student();

    printf("+---------------------------------------------------------+\n");
    printf("|                   ��ӭʹ��ѧ��ѡ��ϵͳ!                 |\n");
    start:
    printf("+---------------------------------------------------------+\n");
    printf("|                           ���˵�                        |\n");
    printf("|---------------------------------------------------------|\n");
    printf("|1 | ѧ��ѡ��                                             |\n");
    printf("|--+------------------------------------------------------|\n");
    printf("|2 | ��ʦ����                                             |\n");
    printf("|--+------------------------------------------------------|\n");
    printf("|3 | ѡ����Ϣ���洢                                       |\n");
    printf("|--+------------------------------------------------------|\n");
    printf("|4 | ���沢�˳�ϵͳ                                       |\n");
    printf("|--+------------------------------------------------------|\n");
    printf("|5 | �˳�ϵͳ                                             |\n");
    printf("|---------------------------------------------------------|\n");
    printf("|������˵�ѡ��(1~5):                                     |\n");
    scanf("%d",&i);
    if(i<1 || i>5)
    {
        printf("\n");
        printf("+---------------------------------------------------------+\n");
        printf("| �������,������:                                        |\n");
        goto start;
    }
    switch(i)
    {
    case(1):
        {
            system("cls"); // windows cls
            elective();
            goto start;
            break;
        }
    case(2):
        {
            system("cls");
            teacher_manage();
            goto start;
            break;
        }
    case(3):
        {
            system("cls");
            index_info();
            goto start;
            break;
        }
    case(4):
        {
            system("cls");
            savefile_course();
            savefile_student();
            printf("+---------------------------------------------------------+\n");
            printf("|  ��лʹ�ñ�ϵͳ!�ټ�!                                   |\n");
            printf("+---------------------------------------------------------+\n");
        }
    case(5):
        {
            system("cls");
            printf("+---------------------------------------------------------+\n");
            printf("|  ��лʹ�ñ�ϵͳ!�ټ�!                                   |\n");
            printf("+---------------------------------------------------------+\n");
        }
    }
    return(0);
}