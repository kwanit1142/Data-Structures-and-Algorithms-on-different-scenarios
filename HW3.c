#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define bool int

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
}INT_NODE;

typedef struct nod{
	struct node *t;
	struct nod *s;
}S_NODE;

int push(S_NODE **ref_top, INT_NODE *in)
{
	S_NODE *new= (S_NODE *) malloc(sizeof(S_NODE));
	new->t = in;
	new->s = *(ref_top);
	*(ref_top) = new;
	return 0;
}

bool Emp(S_NODE *to)
{
	return (to == NULL)?1:0 ;
}

INT_NODE *pop(S_NODE **r_t)
{
	INT_NODE *r;
	S_NODE *tt;
	if (!Emp(*r_t))
	{
		tt = *r_t;
		r=tt->t;
		*r_t = tt->s;
		free(tt);
		return r;
	}
	else
	{
		;
	}
}

INT_NODE *top(S_NODE *r_t)
{
	return r_t->t ;
}

INT_NODE *create (int data_node)
{
	INT_NODE *temp = (INT_NODE *) malloc(sizeof(INT_NODE));
	temp->value=data_node;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

INT_NODE *insert(INT_NODE *node, int data)
{
	if (node == NULL)
	{
		return create(data);
	}
	else if (data > node->value)
	{
		node->right=insert(node->right,data);
	}
	else if (data < node->value)
	{
		node->left=insert(node->left,data);
	}
	else
	{
		return node;
	}
}

int inorder(INT_NODE *NN)
{
	bool check=0;
	INT_NODE *curr= NN;
	S_NODE *st= NULL;
	printf("\nINORDER-TRAVERSAL\n\n");
	while (!check)
	{
		if (curr != NULL)
		{
			push(&st, curr);
			curr=curr->left;
		}
		else
		{
			if (!Emp(st))
			{
			curr = pop(&st);
			printf("%d ",curr->value);
			curr = curr->right;
			}
			else
			{
				check=1;
			}
		}
	}
	printf("\n");
	return 0;
}

int postorder(INT_NODE *NNN)
{
	S_NODE *sta = NULL;
	printf("\nPOSTORDER-TRAVERSAL\n\n");
	push(&sta,NNN);
	do
	{
		while (NNN)
		{
			if (NNN->right)
			{
				push(&sta, NNN->right);
			}
			push(&sta,NNN);
			NNN = NNN->left;
		}
		NNN = pop(&sta);
		if (NNN->right && top(sta) == NNN->right)
		{
			INT_NODE *temp = pop(&sta);
			push(&sta,NNN);
			NNN = NNN->right;
		}
		else
		{
			printf("%d ", NNN->value);
			NNN = NULL;
		}		
	}while (!Emp(sta));
	printf("\n");
	return 0;
}

int preorder(INT_NODE *NNNN)
{
	S_NODE *stac = NULL;
	printf("\nPREORDER-TRAVERSAL\n\n");
	push(&stac,NNNN);
	while (!Emp(stac))
	{
		INT_NODE *no = pop(&stac);
		printf("%d ",no->value);
		if (no->right)
		{
			push(&stac,no->right);
		}
		if (no->left)
		{
			push(&stac,no->left);	
		}
	}
	printf("\n");
	return 0;
}

int MENU()
{
	int c;
	printf("\n========== MENU ==========\n");
	printf("0.Exit\n");
	printf("1.Insert Data\n");
	printf("2.Delete Data\n");
	printf("3.Display Number of Leaves, Internal Nodes and Height of Tree\n");
	printf("4.Show InOrder Traversal\n");
	printf("5.Show PreOrder Traversal\n");
	printf("6.Show PostOrder Traversal\n");
	printf("==========================\n");
	printf("\nEnter case :- ");
	scanf("%d",&c);
	return c;
}

int main()
{
	const int MAX=100;
	INT_NODE *start = NULL;
	INT_NODE *post = NULL;
	INT_NODE *pre = NULL;
	INT_NODE *in = NULL;
	INT_NODE *inf = NULL;
	int *arr;
	arr=(int *) malloc(MAX*sizeof(int));
	int option;
	int count=0;
	option=MENU();
	do
	{
		if (option==1)
		{
			if (count==0)
			{
				char ch=0;
				int temp,i=0,j=1;
				while (scanf("%d%c",&temp,&ch)==2)
				{
					arr[i]=temp;
					if (ch=='\n')
					{
						break;
					}
					i++;
				}
				while (j<=i)
				{
					if (j==1)
					{
						start = insert(start,arr[j]);
						j++;
					}
					else
					{
						insert(start,arr[j]);
						j++;
					}
				}
				count++;
				option=MENU();
			}
			else
			{
				printf("\nFor Inserting New Tree, Exiting.....\n");
				break;
			}
		}
		else if (option==4)
		{
			in=start;
			inorder(in);
			option=MENU();
		}
		else if (option==5)
		{
			pre=start;
			preorder(pre);
			option=MENU();
		}
		else if (option==6)
		{
			post=start;
			postorder(post);
			option=MENU();
		}
		else
		{
			option=MENU();
		}
	}while (option !=0);
	free(post);
	free(pre);
	free(in);
	free(start);
	free(arr);
	return 0;
}
