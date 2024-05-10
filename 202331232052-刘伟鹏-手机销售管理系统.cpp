#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct jiben *tail=NULL;//基本尾节点
struct xiaoshou *teil=NULL;//基本尾节点
struct jiben *creat();//基本链表建立
struct xiaoshou *creats();//销售链表建立
void jbcr(struct jiben *head);//基本文件末端插入并保存到文件
void xscr(struct xiaoshou *heed);//销售文件末端插入并保存到文件 
void sc(struct jiben *head);//基本类型节点删除
void xg(struct jiben *head);//基本类型内容修改 
void shuchus(struct xiaoshou *head);//销售类型打印到控制台 
struct jiben *jbwj(struct jiben *head);//基本文件内容导入链表
struct xiaoshou *xswj(struct jiben *heed);//销售文件内容导入链表
void xsbc(struct xiaoshou *heed);//销售类型打印到文件 
void jbbc(struct jiben *head);//基本类型打印到文件 
void shuchu(struct jiben *head);//基本类型打印到控制台 
void jbcx(struct jiben *heed);//基本信息查询并输出
void xsppcx(struct xiaoshou *heed);//输入品牌查询销售信息并输出 
void xsrqcx(struct xiaoshou *heed);//输入日期查询销售信息并输出 
void ppje(struct xiaoshou *heed);//输入品牌统计型号销量金额，及品牌总销量及金额
void rqxs(struct xiaoshou *heed);//输入日期统计销售量及销售金额排序 
void jjpx(struct jiben *heed);//进价对基本信息排序 
struct jiben{//结构体（基本） 
	int ID;
	char a[10];//型号 
	char b[10];//品牌
	int j;//进价 
	int n;//数量 
	struct jiben *next;
	struct jiben *up;
};
struct xiaoshou{//结构体（销售）
	int ID;
	char a[10];//型号 
	char b[10];//品牌
	int s;//售价 
	int n;//数量 
	char rq[20];//销售日期 
	struct xiaoshou *next;
	struct xiaoshou *up;
};
struct xhsjsl{//型号售价销量
	char a[10];//型号
	int s;//售价 
	int n;//数量 
};
struct pxsn{
	char a[10];//型号 
	char b[10];//品牌
	int s;//售价 
	int n;//数量 
	int sum;//总金额 
};
#define len sizeof(struct jiben)
#define Len sizeof(struct xiaoshou)
struct jiben *creat(){//基本链表建立 
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
struct xiaoshou *creats(){//销售链表建立 
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
void jbcr(struct jiben *head){//基本文件末端插入并保存到文件 
	struct jiben *p0;
	char c[1];
	p0=(struct jiben *)malloc(len);
	p0->next=NULL;
	p0->up=NULL;
	printf("请输入手机基本信息：\n");
	printf("请输入手机ID："); 
	scanf("%d",&p0->ID);
	printf("请输入手机型号：");
	gets(c); 
	gets(p0->a);
	printf("请输入手机品牌：");
	gets(p0->b);
	printf("请输入手机进价和数量：");
	scanf("%d%d",&p0->j,&p0->n);
	tail->next=p0;
	p0->up=tail;
	tail=p0;
	jbbc(head);
	printf("添加成功");
	shuchu(head); 
} 
void xscr(struct xiaoshou *heed){//销售文件末端插入并保存到文件 
	struct xiaoshou *p0;
	char c[1];
	p0=(struct xiaoshou *)malloc(Len);
	p0->next=NULL;
	p0->up=NULL;
	printf("请输入手机销售信息：");
	printf("请输入手机ID：");
	scanf("%d",&p0->ID);
	printf("请输入手机型号：");
	gets(c);
	gets(p0->a);
	printf("请输入手机品牌：");
	gets(p0->b);
	printf("请输入手机售价和销量：");
	scanf("%d%d",&p0->s,&p0->n);
	printf("请输入手机销售日期：");
	gets(c);
	gets(p0->rq);
	teil->next=p0;
	p0->up=teil;
	teil=p0;
	xsbc(heed);
	printf("添加成功");
	shuchus(heed); 
} 
void sc(struct jiben *head){//基本类型节点删除
	int ID;
	printf("请输入需要删除手机的ID");
	scanf("%d",&ID);
	struct jiben *p1,*p2=NULL;
	if(head==NULL) printf("链表为空\n");
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
				printf("已删除\n");
		}
		else printf("该ID不存在"); 
	}
	jbbc(head);
}
void xg(struct jiben *head){//基本类型内容修改 
	int x;
	struct jiben *p1=head;
	printf("请输入需要修改型号的ID\n");
	scanf("%d",&x);
	while(p1!=NULL){
		if(x==p1->ID){
			printf("请输入需要修改型号的基本信息\n");
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
	if(p1==NULL) printf("该ID不存在\n");
	else printf("修改成功");
	jbbc(head);
}
void shuchu(struct jiben *head){//基本类型打印到控制台
	struct jiben *p1;
	p1=head;
	while(p1!=NULL){
		printf("ID:%d\n型号：",p1->ID);
		puts(p1->a);
		printf("品牌："); 
		puts(p1->b);
		printf("进价：%d\n数量：%d\n\n",p1->j,p1->n);
		p1=p1->next;
	}
}
void shuchus(struct xiaoshou *head){//销售类型打印到控制台 
	struct xiaoshou *p1;
	p1=head;
	while(p1!=NULL){
		printf("ID：%d\n型号：",p1->ID);
		puts(p1->a);
		printf("品牌：");
		puts(p1->b);
		printf("售价：%d\n销量：%d\n日期：",p1->s,p1->n);
		puts(p1->rq);
		printf("\n");
		p1=p1->next;
	}
}
struct jiben *jbwj(struct jiben *head){//基本文件内容导入链表
	struct jiben *p1,*p2;
	p2=head;
	p1=tail;
	int ID,j,n;
	char a[10],b[10];
	FILE *fp;
	fp=fopen("基本信息.txt","r");
	if(fp==NULL) printf("文件打开失败");
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
struct xiaoshou *xswj(struct xiaoshou *heed){//销售文件内容导入链表
	struct xiaoshou *p1,*p2;
	p2=heed;
	p1=teil;
	int ID,s,n;
	char a[10],b[10],rq[20];
	FILE *fp;
	fp=fopen("销售信息.txt","r");
	if(fp==NULL) printf("文件打开失败");
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
void jbbc(struct jiben *head){//基本类型打印到文件 
	struct jiben *p1;
	p1=head;
	FILE *fb;
	fb=fopen("基本信息.txt","w");
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
void xsbc(struct xiaoshou *heed){//销售类型打印到文件 
	struct xiaoshou *p1;
	p1=heed;
	FILE *fb;
	fb=fopen("销售信息.txt","w");
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
void jbcx(struct jiben *heed){//基本信息查询并输出 
	struct jiben *p1;
	p1=heed;
	int ID;
	printf("请输入需要查询手机的ID:");
	scanf("%d",&ID);
	while(p1!=NULL){
	if(p1->ID==ID){
		printf("ID:%d\n型号：",p1->ID);
		puts(p1->a);
		printf("品牌："); 
		puts(p1->b);
		printf("进价：%d\n数量：%d\n\n",p1->j,p1->n);
		break;
	}
		p1=p1->next;
	} 
	if(p1==NULL) printf("该手机ID不存在");
}
void xscx(struct xiaoshou *heed){//输入ID查询销售信息并输出 
	struct xiaoshou *p1;
	p1=heed;
	int ID;
	printf("请输入需要查询手机的ID:");
	scanf("%d",&ID);
	while(p1!=NULL){
	if(p1->ID==ID){
		printf("ID：%d\n型号：",p1->ID);
		puts(p1->a);
		printf("品牌：");
		puts(p1->b);
		printf("售价：%d\n销量：%d\n日期：",p1->s,p1->n);
		puts(p1->rq);
		printf("\n");
		break;
	}
		p1=p1->next;
	} 
	if(p1==NULL) printf("该手机ID不存在");
}
void xsppcx(struct xiaoshou *heed){//输入品牌查询销售信息并输出 
	struct xiaoshou *p1;
	int i=0;
	char c[1],b[10];
	p1=heed;
	printf("请输入需要查询的品牌:");
	gets(c);
	gets(b);
	while(p1!=NULL){
		if(strcmp(p1->b,b)==0){
		printf("ID：%d\n型号：",p1->ID);
		puts(p1->a);
		printf("品牌：");
		puts(p1->b);
		printf("售价：%d\n销量：%d\n日期：",p1->s,p1->n);
		puts(p1->rq);
		printf("\n");
		i++;	
		}
		p1=p1->next;
	}
	if(i==0) printf("该品牌未曾销售"); 
}
void xsrqcx(struct xiaoshou *heed){//输入日期查询销售信息并输出 
	struct xiaoshou *p1;
	int i=0;
	char rq[20],c[1];
	p1=heed;
	printf("请输入需要查询的日期:");
	gets(c);
	gets(rq);
	while(p1!=NULL){
		if(strcmp(p1->rq,rq)==0){
		printf("ID：%d\n型号：",p1->ID);
		puts(p1->a);
		printf("品牌：");
		puts(p1->b);
		printf("售价：%d\n销量：%d\n日期：",p1->s,p1->n);
		puts(p1->rq);
		printf("\n");
		i++;
		}
		p1=p1->next;
	}
	if(i==0) printf("当日未曾销售"); 
}
void ppje(struct xiaoshou *heed){//输入品牌统计型号销量金额，及品牌总销量及金额 
	FILE *f;
	f=fopen("统计型号销量金额.txt","w+");
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
	printf("请输入需要查询的品牌:");
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
			printf("销售数量为%d\n销售总金额为%d\n\n",x[i].n,sum);
			a[i]=x[i].n;
			sun[i]=sum;
			fprintf(f,"%d\n%d\n\n",x[i].n,sum);
		}
	}
	fclose(f);
	if(i==0) printf("该品牌未曾销售"); 
}
void rqxs(struct xiaoshou *heed){//输入日期统计销售量及销售金额排序 
	FILE *f;
	f=fopen("统计品牌销售量排行.txt","w+");
	printf("请输入您要查询的日期：");
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
			printf("销售量%d\n总金额%d\n\n",x[i].n,x[i].sum);
			fprintf(f,"销售量%d\n总金额%d\n\n",x[i].n,x[i].sum);
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
	printf("本月销售量排行榜为：\n");
	fprintf(f,"本月销售量排行榜为：");
	for(i=0;i<k;i++){
		if(x[i].n!=0){
			puts(x[i].b);
			fputs(x[i].b,f);
			fprintf(f,"\n");
			printf("销售量%d\n\n",x[i].n);
			fprintf(f,"销售量%d\n\n",x[i].n);
		}
	}
	fclose(f);
	if(k==0) printf("当天不存在销售信息"); 
}
void jjpx(struct jiben *heed){//进价对基本信息排序 
	FILE *f;
	f=fopen("基本信息进价排序.txt","w+");
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
		printf("*************手机销售系统服务选项****************\n"); 
		printf("*	请选择您所需的服务：\n");
		printf("*	显示基本信息请按1\n");
		printf("*	添加基本信息请按2\n");
		printf("*	删除基本信息请按3\n");
		printf("*	修改基本信息请按4\n");
		printf("*	显示销售信息请按5\n");
		printf("*	使用ID查询销售信息请按6\n");
		printf("*	使用品牌查询销售信息请按7\n");
		printf("*	使用日期查询销售信息按8\n");
		printf("*	查看品牌型号销量及销售金额请按9\n");
		printf("*	查看月份销量及销售金额以及品牌销量排行请按10\n");
		printf("*	将基本信息按进价排序请按11\n");
		printf("*	添加销售信息请按12\n");
		printf("*	结束服务请按0\n");
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
		printf("是否继续服务，继续请按1，结束请按0"); 
		scanf("%d",&x);
		}
	}	
}
