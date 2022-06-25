#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int number;
	struct node *ptr;
}NODE;

int output(NODE *s)
{
	NODE *n;
	n=s;
	printf("%d ",n->number);
	n=n->ptr;
	while (n->ptr != NULL)
	{
		printf("%d ",n->number);
		n=n->ptr;
	}
	printf("%d",n->number);
	return 0;
}

int reverse(NODE *S)
{
	NODE *pre,*curr,*intermediate;
	intermediate=S;
	if (intermediate !=NULL)
	{
		pre=intermediate;
		intermediate= intermediate->ptr;
		pre->ptr=NULL;
		curr=intermediate;
		while (intermediate!=NULL)
		{
			intermediate= intermediate->ptr;
			curr->ptr=pre;
			pre=curr;
			curr=intermediate;
		}
		intermediate=pre;
		output(intermediate);
		free(pre);
		free(curr);
		free(intermediate);
	}
	return 0;
}

int input_check(NODE *start,int limit)
{
	if (limit!=0)
	{
		int tem;
		NODE *temp;
		scanf("%d",&(start->number));
		if ((limit-1)==0)
		{
			start->ptr= NULL;
		}
		else
		{
			start->ptr=(NODE *) malloc(sizeof(NODE));
			temp=start->ptr;
			for (int i=0;i<(limit-1);i++)
			{
				if (i!=(limit-2))
				{
					scanf("%d ",&(temp->number));
					temp->ptr = (NODE *) malloc(sizeof(NODE));
					temp=temp->ptr;
				}
				else
				{
					scanf("%d",&(temp->number));
					temp->ptr = NULL;
					break;
				}
			}
		}
		output(start);
		printf("\n");
		reverse(start);
		return 0;
	}
	else
	{
		printf("NULL \nNULL");
		return 0;
	}
}

int main()
{
	int num;
	NODE *n1;
	scanf("%d\n",&num);
	n1=(NODE *)malloc(sizeof(NODE));
	input_check(n1,num);
	free(n1);
	return 0;
}
