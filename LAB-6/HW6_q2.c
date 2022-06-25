#include<stdio.h>
#include<stdlib.h>

int max(int x,int y)
{
	if (x>=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int min(int xx,int yy)
{
	if (xx>=yy)
	{
		return yy;
	}
	else
	{
		return xx;
	}
}

int optimal(int **look,int *ar, int star, int en)
{
	if (star==en)
	{
		return ar[star];
	}
	if (star+1==en)
	{
		return max(ar[star],ar[en]);
	}
	if (look[star][en]==0)
	{
		int s1=ar[star]+min(optimal(look,ar,star+2,en),optimal(look,ar,star+1,en-1));
		int s2=ar[en]+min(optimal(look,ar,star,en-2),optimal(look,ar,star+1,en-1));
		look[star][en]=max(s1,s2);
	}
	return look[star][en];
}

int savesteps(int **table,int *array,int *step,int number)
{
	int i=0,j=number-1,index=0;
	while ((i<number)&&(j>=0))
	{
		int c1a,c1b,c2a,c2b;
		if ((i+2)<number)
		{
			c1a=table[i+2][j];
		}
		else
		{
			c1a=0;
		}
		if (((i+1)<number) && (j-1)>=0)
		{
			c1b=table[i+1][j-1];
		}
		else
		{
			c1b=0;
		}
		if (((i+1)<number) && (j-1)>=0)
		{
			c2a=table[i+1][j-1];
		}
		else
		{
			c2a=0;
		}
		if ((j-2)>=0)
		{
			c2b=table[i][j-2];
		}
		else
		{
			c2b=0;
		}
		int c1 = array[i]+min(c1a,c1b);
		int c2 = array[j]+min(c2a,c2b);
		if (c1>c2)
		{
			step[index]=array[i];
			i++;
			index++;
		}
		else
		{
			step[index]=array[j];
			j--;
			index++;
		}
	}
	step[index]='\0';
	return 0;
}

int main()
{
	int result;
	int **f;
	int *arr,*steps;
	char ch=0;
	int temp,num=0,i=0;
	while (scanf("%d%c",&temp,&ch)==2)
	{
		if (i==0)
		{
			num=temp;
			i++;
			arr=(int *) malloc(num*sizeof(int));
		}
		else
		{
			arr[i-1]=temp;
			if (ch=='\n')
			{
				break;
			}
			i++;
		}
	}
	steps=(int *) malloc(num*sizeof(int));
	f= (int**) malloc(num*sizeof(int*));
	for (int j=0;j<num;j++)
	{
		f[j]= (int*) malloc(num*sizeof(int));
	}
	result=optimal(f,arr,0,num-1);
	savesteps(f,arr,steps,num);
	printf("%d\n",result);
	for (int ii=2;steps[ii]!='\0';ii+=2)
	{
		if ((steps[ii]!='\0')&&(steps[ii+2]=='\0'))
		{
			printf("%d",steps[ii]);
		}
		else
		{
			printf("%d,",steps[ii]);
		}
	}
	free(steps);
	free(arr);
	free(f);
	return 0;
}
