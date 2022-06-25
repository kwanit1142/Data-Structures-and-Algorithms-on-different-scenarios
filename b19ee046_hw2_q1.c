#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	int *arr;
	int top;
}STACK;

int push(STACK *s,int element)
{
	(s->top)++;
	(s->arr)[s->top]=element;
	return 0;
}

int pop(STACK *s)
{
	(s->top)--;
	return 0;
}

int top(STACK *s)
{
	return (s->arr)[s->top];
}

int check(STACK *S1,STACK *SS, int *S2,int n)
{
	int initi=0,count=0,temp=1;
	push(SS,1);
	push(S1,temp);
	while (initi<n)
	{
		if ((S1->top) == -1)
		{
			temp++;
			push(SS,1);
			push(S1,temp);
		}
		if (top(S1)==S2[initi])
		{
			push(SS,2);
			pop(S1);
			count++;
			initi++;
		}
		else
		{
			while ((top(S1) < S2[initi]) && (temp < S2[initi]))
			{
				temp++;
				push(SS,1);
				push(S1,temp);
			}
			if (top(S1)!=S2[initi])
			{
				break;
			}
			else
			{
				push(SS,2);
				pop(S1);
				count++;
				initi++;
			}
		}
	}
	if (count==n)
	{
		int v=0,ii=0;
		printf("Yes \n");
		while (ii<(2*n)-1)
		{
			printf("push(%d),",++v);
			ii++;
			if (ii<(2*n)-1)
			{	
				if (SS->arr[ii] == 1)
				{
					v+=(SS->arr[ii]);
					printf("push(%d),",v);
					ii++;
				}
				if (SS->arr[ii] == 2)
				{
					printf("pop(),");
					ii++;
				}
			}
		}
		if (SS->arr[ii] == 1)
		{
			v+=(SS->arr[ii]);
			printf("push(%d)",v);
			ii++;
		}
		if (SS->arr[ii] == 2)
		{
			printf("pop()");
			ii++;
		}
	}
	else
	{
		printf("No");
	}
	return 0;
}

int main()
{
	STACK *s1,*state;
	int *s2,num;
	scanf("%d",&num);
	s2=(int *) malloc(num*sizeof(int));
	for (int i=0;i<num;i++)
	{
		scanf("%d",((s2)+i));
	}
	s1=(STACK *) malloc(sizeof(STACK));
	s1->arr=(int *) malloc(num*sizeof(int));
	s1->top = -1;
	state=(STACK *) malloc(sizeof(STACK));
	state->arr=(int *) malloc(2*num*sizeof(int));
	state->top = -1;
	check(s1,state,s2,num);
	free(s1);
	free(state);
	free(s2);
	return 0;
}