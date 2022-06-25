#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	int count;
}POINT;

int hashfunc(int val,int n)
{
	int hash_index=val%n;
	return hash_index;
}

int pairs(POINT *array,int num,int lim)
{
	int c=0;
	for (int st=0;st<lim;st++)
	{
		int rem = num - array[st].value;
		if (array[hashfunc(rem,lim)].value==rem)
		{
			if ((array[st].count==0)&&(array[hashfunc(rem,lim)].count==0))
			{
				if ((array[st].value>0)&&(array[st].value!=rem))
				{
					printf("\n%d,%d",array[st].value,rem);
					array[hashfunc(rem,lim)].count++;
					array[st].count++;
					c++;
				}
			}
		}
		else
		{
			int tem=rem;
			int counter=0;
			while (array[hashfunc(tem,lim)].value!=rem)
			{
				if (counter==lim)
				{
					break;
				}
				else
				{
					tem++;
					counter++;
				}
			}
			if ((array[st].count==0)&&(array[hashfunc(tem,lim)].count==0)&&((tem%lim)!=rem))
			{
				if ((array[st].value>0)&&(array[st].value!=rem))
				{
					printf("\n%d,%d",array[st].value,rem);
					array[hashfunc(tem,lim)].count++;
					array[st].count++;
					c++;
				}
			}
		}
	}
	if (c==0)
	{
		printf("Not Found\n");
	}
	return 0;
}

int create(POINT *ar,int m)
{
	int r=0;
	while (r<m)
	{
		ar[r].value=-1;
		ar[r].count=0;
		r++;
	}
	return 0;
}

int main()
{
	const int MAX=5000;
	POINT *arr;
	char ch=44;
	int temp,tempo,k,i=0;
	arr=(POINT *) malloc(MAX*sizeof(POINT));
	create(arr,MAX);
	while (scanf("%d%c",&temp,&ch)==2)
	{
		if (i==0)
		{
			i=1;
		}
		else
		{
			if (arr[hashfunc(temp,MAX)].value!=-1)
			{
				tempo=temp;
				while(arr[hashfunc(tempo,MAX)].value!=-1)
				{
					tempo++;
				}
				arr[hashfunc(tempo,MAX)].value=temp;
			}
			else
			{
				arr[hashfunc(temp,MAX)].value=temp;
			}	
		}
		if (ch=='\n')
		{
			break;
		}
	}
	scanf("%d",&k);
	pairs(arr,k,MAX);
	free(arr);
	return 0;
}