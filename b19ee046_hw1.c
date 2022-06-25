#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
	int pow,coeff;
	struct node *ptr;
}NODE;

int inp(NODE *P)
{
	int temp_pow,temp_coeff;
	NODE *node;
	scanf("%d %d ",&(P->pow),&(P->coeff));
	temp_pow=P->pow;
	temp_pow-=1;
	P->ptr=(NODE *) malloc(sizeof(NODE));
	node=P->ptr;
	for (int i=0;i<P->pow;i++,temp_pow--)
	{
		scanf("%d ",&temp_coeff);
		if (temp_coeff!=0)
		{
			node->coeff=temp_coeff;
			node->pow=temp_pow;
			if (temp_pow==0)
			{
				node->ptr = NULL;
			}
			else
			{
				node->ptr=(NODE *) malloc(sizeof(NODE));
				node=node->ptr;	
			}
		}
	}
	return 0;
}

int outp(NODE *OP)
{
	NODE *node;
	node=OP;
	printf("%dx^%d",node->coeff,node->pow);
	node=node->ptr;
	while (node->ptr != NULL)
	{
		if (node->coeff >0)
		{
			printf("+ %dx^%d ",node->coeff,node->pow);
		}
		else if((node->coeff==0)&&(node->ptr==NULL))
		{
			printf("0");
		}
		else
		{
			printf("- %dx^%d ",(-1)*(node->coeff),node->pow);
		}
		node=node->ptr;
	}
	printf("%d \n",node->coeff);
	return 0;
}

NODE* add(NODE* pi1, NODE* pi2)
{
    NODE* start = NULL;
    start = (NODE*) malloc(sizeof(NODE));
    NODE* a1 = pi1; NODE* a2 = pi2;
    NODE*  temp;
    if (pi2->pow > pi1->pow){
        start->pow = pi2->pow;
        start->coeff = pi2->coeff;
        a2 = a2->ptr;
        a1 = pi1;
    }
    else if (pi1->pow > pi2->pow){
        start->pow = pi1->pow;
        start->coeff = pi1->coeff;
        a1 = a1->ptr;
        a2 = pi2;
    }
    else{
        start->pow = pi1->pow;
        start->coeff = (pi1->coeff + pi2->coeff);
        a1 = pi1->ptr;
        a2 = pi2->ptr;
    }
    temp = start;
    while (a1!=NULL && a2!=NULL){

        if (a2->pow + a1->pow==0){
            a1 = a1->ptr;
            a2 = a2->ptr;
        }
        
        else if (a2->pow > a1->pow){
            NODE* upd;
            upd = (NODE*) malloc(sizeof(NODE));
            upd->pow = a2->pow;
            upd->coeff = a2->coeff;
            a2 = a2->ptr;
            temp->ptr = upd;
            temp = upd;
            upd->ptr= NULL;
        }
        else if (a1->pow > a2->pow){
            NODE* upd;
            upd = (NODE*) malloc(sizeof(NODE));
            upd->pow = a1->pow;
            upd->coeff = a1->coeff;
            a1 = a1->ptr;
            temp->ptr = upd;
            temp = upd;
            upd->ptr= NULL;
        }

        else{
            NODE* upd;
            upd = (NODE*) malloc(sizeof(NODE));
            upd->pow = a1->pow;
            upd->coeff = (a1->coeff + a2->coeff);
            a1 = a1->ptr;
            a2 = a2->ptr;
            temp->ptr = upd;
            temp = upd;
            upd->ptr= NULL;
        }
    }
    
    if (a1==NULL){
        while (a2 != NULL){
            NODE* upd;
            upd = (NODE*) malloc(sizeof(NODE));
            upd->pow = a2->pow;
            upd->coeff = a2->coeff;
            a2 = a2->ptr;
            temp->ptr = upd;
            temp = upd;
            upd->ptr= NULL;
        }
    }
    if (a2 == NULL){
        while (a1 != NULL){
            NODE* upd;
            upd = (NODE*) malloc(sizeof(NODE));
            upd->pow = a1->pow;
            upd->coeff = a1->coeff;
            a1 = a1->ptr;
            temp->ptr = upd;
            temp = upd;
            upd->ptr= NULL;
        }
    }
    if (start->coeff==0){
        start = start->ptr;
    }
    return start;
}

int eval(NODE *E,int val)
{
	NODE *pos;
	int value=0,inter;
	pos=E;
	while (pos->ptr != NULL)
	{
		inter=(pow(val,pos->pow));
		inter*=(pos->coeff);
		value+=inter;
		pos=pos->ptr;
	}
	inter=(pow(val,pos->pow));
	inter*=(pos->coeff);
	value+=inter;
	printf("%d \n",value);
	return 0;
}

NODE* sub(NODE* po1, NODE* po2)
{
    NODE* subt = NULL;
    subt = (NODE*) malloc(sizeof(NODE));
    NODE* s1 = po1; NODE* s2 = po2;
    NODE*  las;
    if (po2->pow > po1->pow){
        subt->pow = po2->pow;
        subt->coeff =(-1)*(po2->coeff);
        s2 = s2->ptr;
        s1 = po1;
    }
    else if (po1->pow > po2->pow){
        subt->pow = po1->pow;
        subt->coeff = po1->coeff;
        s1 = s1->ptr;
        s2 = po2;
    }
    else{
        subt->pow = po1->pow;
        subt->coeff = (po1->coeff - po2->coeff);
        s1 = po1->ptr;
        s2 = po2->ptr;
    }
    las = subt;
    while (s1!=NULL && s2!=NULL){

        if (s2->pow + s1->pow==0){
            s1 = s1->ptr;
            s2 = s2->ptr;
        }
        
        else if (s2->pow > s1->pow){
            NODE* updt;
            updt = (NODE*) malloc(sizeof(NODE));
            updt->pow = s2->pow;
            updt->coeff =(-1)*(s2->coeff);
            s2 = s2->ptr;
            las->ptr = updt;
            las = updt;
            updt->ptr= NULL;
        }
        else if (s1->pow > s2->pow){
            NODE* updt;
            updt = (NODE*) malloc(sizeof(NODE));
            updt->pow = s1->pow;
            updt->coeff = s1->coeff;
            s1 = s1->ptr;
            las->ptr = updt;
            las = updt;
            updt->ptr= NULL;
        }

        else{
            NODE* updt;
            updt = (NODE*) malloc(sizeof(NODE));
            updt->pow = s1->pow;
            updt->coeff = (s1->coeff - s2->coeff);
            s1 = s1->ptr;
            s2 = s2->ptr;
            las->ptr = updt;
            las = updt;
            updt->ptr= NULL;
        }
    }
    
    if (s1==NULL){
        while (s2 != NULL){
            NODE* updt;
            updt = (NODE*) malloc(sizeof(NODE));
            updt->pow = s2->pow;
            updt->coeff =(-1)*(s2->coeff);
            s2 = s2->ptr;
            las->ptr = updt;
            las = updt;
            updt->ptr= NULL;
        }
    }
    if (s2 == NULL){
        while (s1 != NULL){
            NODE* updt;
            updt = (NODE*) malloc(sizeof(NODE));
            updt->pow = s1->pow;
            updt->coeff = s1->coeff;
            s1 = s1->ptr;
            las->ptr = updt;
            las = updt;
            updt->ptr= NULL;
        }
    }
    if (subt->coeff==0){
        subt = subt->ptr;
    }
    return subt;
}

int main()
{
	int K,x;
	NODE *P1,*P2,*P3,*P4;
	scanf("%d",&K);
	for (int num=0;num<K;num++)
	{
		P1=(NODE *) malloc(sizeof(NODE));
		P2=(NODE *) malloc(sizeof(NODE));
		P3=(NODE *) malloc(sizeof(NODE));
		P4=(NODE *) malloc(sizeof(NODE));
		inp(P1);
		inp(P2);
		scanf("%d",&x);
		P3=add(P1,P2);
		P4=sub(P1,P2);
		printf("P1(X):");
		outp(P1);
		printf("P2(X):");
		outp(P2);
		printf("P3(X)=P1(X)+P2(X):");
		outp(P3);
		printf("P4(X)=P1(X)-P2(X):");
		outp(P4);
		printf("P1");
		printf("(%d)=",x);
		eval(P1,x);
		printf("P2");
		printf("(%d)=",x);
		eval(P2,x);
		printf("P3");
		printf("(%d)=",x);
		eval(P3,x);
		printf("P4");
		printf("(%d)=",x);
		eval(P4,x);
		free(P1);
		free(P2);
		free(P3);
		free(P4);
	}
	return 0;
}