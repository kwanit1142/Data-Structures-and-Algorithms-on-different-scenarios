#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct stack{
	char *arr;
	int top;
}STACK;

int push(STACK *s,char element)
{
	(s->top)++;
	s->arr[s->top]=element;
	return 0;
}

char pop(STACK *s)
{
	char tempo;
	tempo=s->arr[(s->top)--];
	return tempo;
}

char top(STACK *s)
{
	return s->arr[s->top];
}

int precedence(char ch[],int ind,STACK *s1,STACK *s2)
{
	if ((s1->top) ==-1)
	{
		push(s1,ch[ind]);
	}
	else
	{
		if (ch[ind]=='(')
		{
			while (ch[ind]!='\0')
			{
				ind++;
				if (ch[ind]==')')
				{
					push(s1,'(');
					break;
				}
			}
		}
		else if (ch[ind]==')')
		{
			while (top(s1)!='(')
			{
				push(s2,pop(s1));
				push(s2,',');
			}
			push(s1,ch[ind]);
			(s1->top)-=2;
		}
		else if((ch[ind]=='<' && ch[ind+1]=='<') || (ch[ind]=='>' && ch[ind+1]=='>') || (ch[ind]=='^'))
		{
			if((ch[ind]=='<' && ch[ind+1]=='<') || (ch[ind]=='>' && ch[ind+1]=='>'))
			{
				if ((top(s1)=='<' && s1->arr[(s1->top)-1]=='<') || (top(s1)=='>' && s1->arr[(s1->top)-1]=='>'))
				{
					do
					{
					push(s2,pop(s1));
					}while ((top(s1)=='<') || (top(s1)=='>'));

					push(s2,',');
					push(s1,ch[ind]);
					push(s1,ch[ind+1]);
				} 
				else if(top(s1)=='^')
				{
					do
					{
					push(s2,pop(s1));
					push(s2,',');
					}while (top(s1)=='^');

					push(s1,ch[ind]);
					push(s1,ch[ind+1]);
				}
				else
				{
				push(s1,ch[ind]);
				push(s1,ch[ind+1]);
				}
			}
			else
			{
				push(s1,ch[ind]);
			}
		}
		else if((ch[ind]=='/') || (ch[ind]=='*'))
		{
			if((top(s1)=='<' && s1->arr[(s1->top)-1]=='<') || (top(s1)=='>' && s1->arr[(s1->top)-1]=='>'))
			{
				do
				{
				push(s2,pop(s1));
				}while ((top(s1)=='<') || (top(s1)=='>'));

				push(s2,',');
				push(s1,ch[ind]);
			}
			else if((top(s1)=='^') || (top(s1)=='/') || (top(s1)=='*'))
			{
				do
				{
				push(s2,pop(s1));
				push(s2,',');
				}while ((top(s1)=='^') || (top(s1)=='/') || (top(s1)=='*'));
				
				push(s1,ch[ind]);
			}
			else
			{
				push(s1,ch[ind]);
			}
		}
		else if((ch[ind]=='+') || (ch[ind]=='-'))
		{
			if((top(s1)=='<' && s1->arr[(s1->top)-1]=='<') || (top(s1)=='>' && s1->arr[(s1->top)-1]=='>'))
			{
				do
				{
				push(s2,pop(s1));
				}while ((top(s1)=='<') || (top(s1)=='>'));

				push(s2,',');
				push(s1,ch[ind]);
			}
			else if((top(s1)=='^') || (top(s1)=='/') || (top(s1)=='*') || (top(s1)=='+') || (top(s1)=='-'))
			{
				do
				{
				push(s2,pop(s1));
				push(s2,',');
				}while ((top(s1)=='^') || (top(s1)=='/') || (top(s1)=='*') || (top(s1)=='+') || (top(s1)=='-'));

				push(s1,ch[ind]);
			}
			else
			{
				push(s1,ch[ind]);
			}
		}
		else
		{
			;
		}
	}
	return 0;
	}

int insert(char interm[],int in,STACK *S1,STACK *S2)
{
	int count=0;
	if ((interm[in] =='0') || (interm[in] =='1') || (interm[in] =='2') || (interm[in] =='3') || (interm[in] =='4') || (interm[in] =='5') || (interm[in] =='6') || (interm[in] =='7') || (interm[in] =='8') || (interm[in] =='9'))
	{
		while ((interm[in] =='0') || (interm[in] =='1') || (interm[in] =='2') || (interm[in] =='3') || (interm[in] =='4') || (interm[in] =='5') || (interm[in] =='6') || (interm[in] =='7') || (interm[in] =='8') || (interm[in] =='9'))
		{
			push(S2,interm[in]);
			in++;
			++count;
		} 
		push(S2,',');
		return count;
	}
	else
	{
		precedence(interm,in,S1,S2);
		if ((interm[in]=='<') && (interm[in+1]=='<') || (interm[in]=='>') && (interm[in+1]=='>'))
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
}

int output(STACK *OP)
{
	for (int h=0;OP->arr[h]!='\0';h++)
	{
		printf("%c",OP->arr[h]);
	}
	return 0;
}

int main()
{
	const int MAX=100;
	int i=0,step;
	STACK *symbol,*result;
	char *input;
	input=(char *)malloc(MAX*sizeof(char));
	gets(input);
	result=(STACK *)malloc(sizeof(STACK));
	symbol=(STACK *)malloc(sizeof(STACK));
	result->top=-1;
	symbol->top=-1;
	result->arr=(char *)malloc(MAX*sizeof(char));
	symbol->arr=(char *)malloc(MAX*sizeof(char));
	while (input[i] != '\0')
	{
		step=insert(input,i,symbol,result);
		i+=step;
	}
	if ((symbol->top) !=-1)
	{
		while (symbol->top !=-1)
		{
			if ((top(symbol)=='<' && symbol->arr[(symbol->top)-1]=='<') || (top(symbol)=='>' && symbol->arr[(symbol->top)-1]=='>'))
			{
				push(result,pop(symbol));
				push(result,pop(symbol));
				push(result,',');
			}
			else
			{
				push(result,pop(symbol));
			}
		}
	}
	push(result,'\0');
	output(result);
	free(symbol);
	free(result);
	free(input);
	return 0;
}
