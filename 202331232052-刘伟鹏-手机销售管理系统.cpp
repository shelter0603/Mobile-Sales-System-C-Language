#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct jiben *tail=NULL;//����β�ڵ�
struct xiaoshou *teil=NULL;//����β�ڵ�
struct jiben *creat();//����������
struct xiaoshou *creats();//����������
void jbcr(struct jiben *head);//�����ļ�ĩ�˲��벢���浽�ļ�
void xscr(struct xiaoshou *heed);//�����ļ�ĩ�˲��벢���浽�ļ� 
void sc(struct jiben *head);//�������ͽڵ�ɾ��
void xg(struct jiben *head);//�������������޸� 
void shuchus(struct xiaoshou *head);//�������ʹ�ӡ������̨ 
struct jiben *jbwj(struct jiben *head);//�����ļ����ݵ�������
struct xiaoshou *xswj(struct jiben *heed);//�����ļ����ݵ�������
void xsbc(struct xiaoshou *heed);//�������ʹ�ӡ���ļ� 
void jbbc(struct jiben *head);//�������ʹ�ӡ���ļ� 
void shuchu(struct jiben *head);//�������ʹ�ӡ������̨ 
void jbcx(struct jiben *heed);//������Ϣ��ѯ�����
void xsppcx(struct xiaoshou *heed);//����Ʒ�Ʋ�ѯ������Ϣ����� 
void xsrqcx(struct xiaoshou *heed);//�������ڲ�ѯ������Ϣ����� 
void ppje(struct xiaoshou *heed);//����Ʒ��ͳ���ͺ���������Ʒ�������������
void rqxs(struct xiaoshou *heed);//��������ͳ�������������۽������ 
void jjpx(struct jiben *heed);//���۶Ի�����Ϣ���� 
struct jiben{//�ṹ�壨������ 
	int ID;
	char a[10];//�ͺ� 
	char b[10];//Ʒ��
	int j;//���� 
	int n;//���� 
	struct jiben *next;
	struct jiben *up;
};
struct xiaoshou{//�ṹ�壨���ۣ�
	int ID;
	char a[10];//�ͺ� 
	char b[10];//Ʒ��
	int s;//�ۼ� 
	int n;//���� 
	char rq[20];//�������� 
	struct xiaoshou *next;
	struct xiaoshou *up;
};
struct xhsjsl{//�ͺ��ۼ�����
	char a[10];//�ͺ�
	int s;//�ۼ� 
	int n;//���� 
};
struct pxsn{
	char a[10];//�ͺ� 
	char b[10];//Ʒ��
	int s;//�ۼ� 
	int n;//���� 
	int sum;//�ܽ�� 
};
#define len sizeof(struct jiben)
#define Len sizeof(struct xiaoshou)
struct jiben *creat(){//���������� 
	struct jiben *head=NULL,*p1,*p2,*p3=NULL;
	p1=p2=(struct jiben *)malloc(len);
	p1->ID=0;
	int i=0; 
	while(i<50){
		if(head==NULL)
		head=p1;
		else
		p2->next=p1;
		p2->up=p3;
		p3=p2;
		p2=p1;
		p1=(struct jiben *)malloc(len);
		p1->ID=0;
		i++;
	}
	head->up=NULL;
	p2->next=NULL;
	p2->up=p3;
	tail=p2;
	free(p1);
	return head;
}
struct xiaoshou *creats(){//���������� 
	struct xiaoshou *head=NULL,*p1,*p2,*p3=NULL;
	int i=0;
	p1=p2=(struct xiaoshou *)malloc(Len);
	p1->ID=0;
	while(i<50){
		if(head==NULL)
		head=p1;
		else
		p2->next=p1;
		p2->up=p3;
		p3=p2;
		p2=p1;
		p1=(struct xiaoshou *)malloc(Len);
		p1->ID=0;
		i++;
	}
	head->up=NULL;
	p2->next=NULL;
	p2->up=p3;
	teil=p2;
	free(p1);
	return head;
}
void jbcr(struct jiben *head){//�����ļ�ĩ�˲��벢���浽�ļ� 
	struct jiben *p0;
	char c[1];
	p0=(struct jiben *)malloc(len);
	p0->next=NULL;
	p0->up=NULL;
	printf("�������ֻ�������Ϣ��\n");
	printf("�������ֻ�ID��"); 
	scanf("%d",&p0->ID);
	printf("�������ֻ��ͺţ�");
	gets(c); 
	gets(p0->a);
	printf("�������ֻ�Ʒ�ƣ�");
	gets(p0->b);
	printf("�������ֻ����ۺ�������");
	scanf("%d%d",&p0->j,&p0->n);
	tail->next=p0;
	p0->up=tail;
	tail=p0;
	jbbc(head);
	printf("��ӳɹ�");
	shuchu(head); 
} 
void xscr(struct xiaoshou *heed){//�����ļ�ĩ�˲��벢���浽�ļ� 
	struct xiaoshou *p0;
	char c[1];
	p0=(struct xiaoshou *)malloc(Len);
	p0->next=NULL;
	p0->up=NULL;
	printf("�������ֻ�������Ϣ��");
	printf("�������ֻ�ID��");
	scanf("%d",&p0->ID);
	printf("�������ֻ��ͺţ�");
	gets(c);
	gets(p0->a);
	printf("�������ֻ�Ʒ�ƣ�");
	gets(p0->b);
	printf("�������ֻ��ۼۺ�������");
	scanf("%d%d",&p0->s,&p0->n);
	printf("�������ֻ��������ڣ�");
	gets(c);
	gets(p0->rq);
	teil->next=p0;
	p0->up=teil;
	teil=p0;
	xsbc(heed);
	printf("��ӳɹ�");
	shuchus(heed); 
} 
void sc(struct jiben *head){//�������ͽڵ�ɾ��
	int ID;
	printf("��������Ҫɾ���ֻ���ID");
	scanf("%d",&ID);
	struct jiben *p1,*p2=NULL;
	if(head==NULL) printf("����Ϊ��\n");
	else{
		p1=head;
		while((ID!=p1->ID)&&(p1->next!=NULL)){
			p2=p1;
			p1=p1->next;
		}
		if(ID==p1->ID){
				if(p1==head) head=p1->next;
				else p2->next=p1->next;
				free(p1);
				printf("��ɾ��\n");
		}
		else printf("��ID������"); 
	}
	jbbc(head);
}
void xg(struct jiben *head){//�������������޸� 
	int x;
	struct jiben *p1=head;
	printf("��������Ҫ�޸��ͺŵ�ID\n");
	scanf("%d",&x);
	while(p1!=NULL){
		if(x==p1->ID){
			printf("��������Ҫ�޸��ͺŵĻ�����Ϣ\n");
			scanf("%d\n",&p1->ID);
			gets(p1->a);
			gets(p1->b);
			scanf("%d%d",&p1->j,&p1->n);
			break;
		}
		else{
			p1=p1->next;
		}
	}
	if(p1==NULL) printf("��ID������\n");
	else printf("�޸ĳɹ�");
	jbbc(head);
}
void shuchu(struct jiben *head){//�������ʹ�ӡ������̨
	struct jiben *p1;
	p1=head;
	while(p1!=NULL){
		printf("ID:%d\n�ͺţ�",p1->ID);
		puts(p1->a);
		printf("Ʒ�ƣ�"); 
		puts(p1->b);
		printf("���ۣ�%d\n������%d\n\n",p1->j,p1->n);
		p1=p1->next;
	}
}
void shuchus(struct xiaoshou *head){//�������ʹ�ӡ������̨ 
	struct xiaoshou *p1;
	p1=head;
	while(p1!=NULL){
		printf("ID��%d\n�ͺţ�",p1->ID);
		puts(p1->a);
		printf("Ʒ�ƣ�");
		puts(p1->b);
		printf("�ۼۣ�%d\n������%d\n���ڣ�",p1->s,p1->n);
		puts(p1->rq);
		printf("\n");
		p1=p1->next;
	}
}
struct jiben *jbwj(struct jiben *head){//�����ļ����ݵ�������
	struct jiben *p1,*p2;
	p2=head;
	p1=tail;
	int ID,j,n;
	char a[10],b[10];
	FILE *fp;
	fp=fopen("������Ϣ.txt","r");
	if(fp==NULL) printf("�ļ���ʧ��");
	while(fscanf(fp,"%d %s %s %d %d",&ID,a,b,&j,&n)!=EOF){
		p2->ID=ID;
		strcpy(p2->a,a);
		strcpy(p2->b,b);
		p2->j=j;
		p2->n=n;
		p2=p2->next;
	}
	while(p1->up!=NULL){
		if(p1->ID==0){
			p2=p1;
			p1=p1->up;
			free(p2);
		} 
		else {
			tail=p1;
			p1->next=NULL;
			break;
		}
	}
	fclose(fp);
	return head;
};
struct xiaoshou *xswj(struct xiaoshou *heed){//�����ļ����ݵ�������
	struct xiaoshou *p1,*p2;
	p2=heed;
	p1=teil;
	int ID,s,n;
	char a[10],b[10],rq[20];
	FILE *fp;
	fp=fopen("������Ϣ.txt","r");
	if(fp==NULL) printf("�ļ���ʧ��");
	while(fscanf(fp,"%d %s %s %d %d %s",&ID,a,b,&s,&n,rq)!=EOF){
		p2->ID=ID;
		strcpy(p2->a,a);
		strcpy(p2->b,b);
		p2->s=s;
		p2->n=n;
		strcpy(p2->rq,rq);
		p2=p2->next;
	}
	while(p1->up!=NULL){
		if(p1->ID==0){
			p2=p1;
			p1=p1->up;
			free(p2);
		} 
		else {
			teil=p1;
			p1->next=NULL;
			break;
		}
	}
	fclose(fp);
	return heed;
};
void jbbc(struct jiben *head){//�������ʹ�ӡ���ļ� 
	struct jiben *p1;
	p1=head;
	FILE *fb;
	fb=fopen("������Ϣ.txt","w");
	while(p1!=NULL){
		fprintf(fb,"%d\n",p1->ID);
		fputs(p1->a,fb);
		fprintf(fb,"\n");
		fputs(p1->b,fb);
		fprintf(fb,"\n");
		fprintf(fb,"%d\n%d\n",p1->j,p1->n);
		p1=p1->next;
	}
	fclose(fb);
}
void xsbc(struct xiaoshou *heed){//�������ʹ�ӡ���ļ� 
	struct xiaoshou *p1;
	p1=heed;
	FILE *fb;
	fb=fopen("������Ϣ.txt","w");
	while(p1!=NULL){
		fprintf(fb,"%d\n",p1->ID);
		fputs(p1->a,fb);
		fprintf(fb,"\n");
		fputs(p1->b,fb);
		fprintf(fb,"\n");
		fprintf(fb,"%d\n%d\n",p1->s,p1->n);
		fputs(p1->rq,fb);
		fprintf(fb,"\n");
		p1=p1->next;
	}
	fclose(fb);
}
void jbcx(struct jiben *heed){//������Ϣ��ѯ����� 
	struct jiben *p1;
	p1=heed;
	int ID;
	printf("��������Ҫ��ѯ�ֻ���ID:");
	scanf("%d",&ID);
	while(p1!=NULL){
	if(p1->ID==ID){
		printf("ID:%d\n�ͺţ�",p1->ID);
		puts(p1->a);
		printf("Ʒ�ƣ�"); 
		puts(p1->b);
		printf("���ۣ�%d\n������%d\n\n",p1->j,p1->n);
		break;
	}
		p1=p1->next;
	} 
	if(p1==NULL) printf("���ֻ�ID������");
}
void xscx(struct xiaoshou *heed){//����ID��ѯ������Ϣ����� 
	struct xiaoshou *p1;
	p1=heed;
	int ID;
	printf("��������Ҫ��ѯ�ֻ���ID:");
	scanf("%d",&ID);
	while(p1!=NULL){
	if(p1->ID==ID){
		printf("ID��%d\n�ͺţ�",p1->ID);
		puts(p1->a);
		printf("Ʒ�ƣ�");
		puts(p1->b);
		printf("�ۼۣ�%d\n������%d\n���ڣ�",p1->s,p1->n);
		puts(p1->rq);
		printf("\n");
		break;
	}
		p1=p1->next;
	} 
	if(p1==NULL) printf("���ֻ�ID������");
}
void xsppcx(struct xiaoshou *heed){//����Ʒ�Ʋ�ѯ������Ϣ����� 
	struct xiaoshou *p1;
	int i=0;
	char c[1],b[10];
	p1=heed;
	printf("��������Ҫ��ѯ��Ʒ��:");
	gets(c);
	gets(b);
	while(p1!=NULL){
		if(strcmp(p1->b,b)==0){
		printf("ID��%d\n�ͺţ�",p1->ID);
		puts(p1->a);
		printf("Ʒ�ƣ�");
		puts(p1->b);
		printf("�ۼۣ�%d\n������%d\n���ڣ�",p1->s,p1->n);
		puts(p1->rq);
		printf("\n");
		i++;	
		}
		p1=p1->next;
	}
	if(i==0) printf("��Ʒ��δ������"); 
}
void xsrqcx(struct xiaoshou *heed){//�������ڲ�ѯ������Ϣ����� 
	struct xiaoshou *p1;
	int i=0;
	char rq[20],c[1];
	p1=heed;
	printf("��������Ҫ��ѯ������:");
	gets(c);
	gets(rq);
	while(p1!=NULL){
		if(strcmp(p1->rq,rq)==0){
		printf("ID��%d\n�ͺţ�",p1->ID);
		puts(p1->a);
		printf("Ʒ�ƣ�");
		puts(p1->b);
		printf("�ۼۣ�%d\n������%d\n���ڣ�",p1->s,p1->n);
		puts(p1->rq);
		printf("\n");
		i++;
		}
		p1=p1->next;
	}
	if(i==0) printf("����δ������"); 
}
void ppje(struct xiaoshou *heed){//����Ʒ��ͳ���ͺ���������Ʒ������������� 
	FILE *f;
	f=fopen("ͳ���ͺ��������.txt","w+");
	struct xiaoshou *p1;
	int i=0,j=0,sum,k,n[20]={0},sun[20]={0},SUM,N;
	int a[20]={0};
	struct xhsjsl x[20];
	for(i=0;i<20;i++){
		x[i].n=0;
	}
	i=0;
	p1=heed;
	char b[10],c[1]; 
	printf("��������Ҫ��ѯ��Ʒ��:");
	gets(c);
	gets(b);
	while(p1!=NULL){
		if(strcmp(p1->b,b)==0){
		strcpy(x[i].a,p1->a);
		x[i].s=p1->s;
		x[i].n=p1->n;
		for(j=0;j<i;j++){
			if(strcmp(x[i].a,x[j].a)==0){
				x[i].n=x[i].n+x[j].n;
				x[j].n=0;
			}
		}
		}
		p1=p1->next;
		i++;
	}
	k=i;
	for(i=0;i<k;i++){
		if(x[i].n!=0){
			sum=x[i].s*x[i].n;
			puts(x[i].a);
			fputs(x[i].a,f);
			fprintf(f,"\n");
			printf("��������Ϊ%d\n�����ܽ��Ϊ%d\n\n",x[i].n,sum);
			a[i]=x[i].n;
			sun[i]=sum;
			fprintf(f,"%d\n%d\n\n",x[i].n,sum);
		}
	}
	fclose(f);
	if(i==0) printf("��Ʒ��δ������"); 
}
void rqxs(struct xiaoshou *heed){//��������ͳ�������������۽������ 
	FILE *f;
	f=fopen("ͳ��Ʒ������������.txt","w+");
	printf("��������Ҫ��ѯ�����ڣ�");
	struct xiaoshou *p1=heed;
	int i=0,j=0,k=0,max,t,jh;
	struct pxsn x[20];
	char c[1],rq[10],h[10];
	gets(c);
	gets(rq);
	while(p1!=NULL){
		if(strncmp(p1->rq,rq,7)==0){
			strcpy(x[i].a,p1->a);
			strcpy(x[i].b,p1->b);
			x[i].n=p1->n;
			x[i].s=p1->s;
			for(j=0;j<i;j++){
				if(strcmp(x[i].a,x[j].a)==0){
					x[i].n=x[i].n+x[j].n;
					x[j].n=0;
					x[j].sum=0;
					}
				}
		x[i].sum=x[i].s*x[i].n;
		i++;
		}
		p1=p1->next;
	}
	k=i;
	for(i=0;i<k;i++){
		for(j=0;j<i;j++){
			if(strcmp(x[i].b,x[j].b)==0&&x[i].n!=0){
				x[i].n=x[i].n+x[j].n;
				x[j].n=0;
				x[i].sum=x[j].sum+x[i].sum;
				x[j].sum=0;
			}
		}
	}
	for(i=0;i<k;i++){
		if(x[i].n!=0){
			puts(x[i].b);
			fputs(x[i].b,f);
			fprintf(f,"\n");
			printf("������%d\n�ܽ��%d\n\n",x[i].n,x[i].sum);
			fprintf(f,"������%d\n�ܽ��%d\n\n",x[i].n,x[i].sum);
		}
	}
	for(i=0;i<k;i++){
		t=i;
		for(j=i;j<k;j++){
			if(x[j].n>x[t].n){
				t=j;
			}
		}
		if(t!=i){
			strcpy(h,x[i].b);
			strcpy(x[i].b,x[t].b);
			strcpy(x[t].b,h);
			jh=x[i].n;
			x[i].n=x[t].n;
			x[t].n=jh;
		}
	}
	printf("�������������а�Ϊ��\n");
	fprintf(f,"�������������а�Ϊ��");
	for(i=0;i<k;i++){
		if(x[i].n!=0){
			puts(x[i].b);
			fputs(x[i].b,f);
			fprintf(f,"\n");
			printf("������%d\n\n",x[i].n);
			fprintf(f,"������%d\n\n",x[i].n);
		}
	}
	fclose(f);
	if(k==0) printf("���첻����������Ϣ"); 
}
void jjpx(struct jiben *heed){//���۶Ի�����Ϣ���� 
	FILE *f;
	f=fopen("������Ϣ��������.txt","w+");
	struct jiben *p1=heed;
	struct jiben x[20];
	int i=0,j,k,t,min,n,ID,q;
	char a[10],b[10];
	for(i=0;i<20;i++){
		x[20].ID=0;
	}
	i=0;
	while(p1!=NULL){
		x[i].ID=p1->ID;
		x[i].j=p1->j;
		x[i].n=p1->n;
		strcpy(x[i].a,p1->a);
		strcpy(x[i].b,p1->b);
		i++;
		p1=p1->next;
	}
	k=i;
	for(i=0;i<k;i++){
		t=i;
		for(q=i+1;q<k;q++){
			if(x[q].j<x[t].j){
				t=q;
			}
		}
		if(t!=i){
			strcpy(b,x[i].b);
			strcpy(x[i].b,x[t].b);
			strcpy(x[t].b,b);
			strcpy(a,x[i].a);
			strcpy(x[i].a,x[t].a);
			strcpy(x[t].a,a);
			ID=x[i].ID;
			x[i].ID=x[t].ID;
			x[t].ID=ID;
			n=x[i].n;
			x[i].n=x[t].n;
			x[t].n=n;
			j=x[i].j;
			x[i].j=x[t].j;
			x[t].j=j;
		}
	}
	for(i=0;i<k;i++){
		printf("%d\n",x[i].ID);
		fprintf(f,"%d\n",x[i].ID);
		puts(x[i].a);
		fputs(x[i].a,f);
		fprintf(f,"\n");
		puts(x[i].b);
		fputs(x[i].b,f);
		fprintf(f,"\n");
		printf("%d\n%d\n\n",x[i].j,x[i].n);
		fprintf(f,"%d\n%d\n\n",x[i].j,x[i].n);
	}
	fclose(f);
}
int main(){
	int x=100;
	struct jiben *head;
	head=creat();
	head=jbwj(head);
	struct xiaoshou *heed;
	heed=creats();
	heed=xswj(heed);
	while(x){
		printf("*************�ֻ�����ϵͳ����ѡ��****************\n"); 
		printf("*	��ѡ��������ķ���\n");
		printf("*	��ʾ������Ϣ�밴1\n");
		printf("*	��ӻ�����Ϣ�밴2\n");
		printf("*	ɾ��������Ϣ�밴3\n");
		printf("*	�޸Ļ�����Ϣ�밴4\n");
		printf("*	��ʾ������Ϣ�밴5\n");
		printf("*	ʹ��ID��ѯ������Ϣ�밴6\n");
		printf("*	ʹ��Ʒ�Ʋ�ѯ������Ϣ�밴7\n");
		printf("*	ʹ�����ڲ�ѯ������Ϣ��8\n");
		printf("*	�鿴Ʒ���ͺ����������۽���밴9\n");
		printf("*	�鿴�·����������۽���Լ�Ʒ�����������밴10\n");
		printf("*	��������Ϣ�����������밴11\n");
		printf("*	���������Ϣ�밴12\n");
		printf("*	���������밴0\n");
		scanf("%d",&x);
		if(x==1){
			shuchu(head);
		}
		if(x==2){
			jbcr(head);
		}
		if(x==3){
			sc(head);
		}
		if(x==4){
			xg(head);
		}
		if(x==5){
			shuchus(heed);
		}
		if(x==6){
			xscx(heed);
		}
		if(x==7){
			xsppcx(heed);
		}
		if(x==8){
			xsrqcx(heed);
		}
		if(x==9){
			ppje(heed);
		}
		if(x==10){
			rqxs(heed);
		}
		if(x==11){
			jjpx(head);
		}
		if(x==12){
			xscr(heed);
		}
		if(x!=0){
		printf("�Ƿ�������񣬼����밴1�������밴0"); 
		scanf("%d",&x);
		}
	}	
}
