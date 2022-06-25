#include<stdio.h>
#include<stdlib.h>

int swap(int *ar,int x,int y)
{
	int c;
	c=ar[x];
	ar[x]=ar[y];
	ar[y]=c;
	return 0;
}

int max_heapify(int *m_h1,int *m_h2,int *m_h3,int limit,int index)
{
	int large;
	int l=(2*index)+1,r=(2*index)+2;
	if ((l<=limit) && (m_h2[l]>=m_h2[index]))
	{
		large=l;
	}
	else
	{
		large=index;
	}
	if ((r<=limit) && (m_h2[r]>=m_h2[large]))
	{
		large=r;
	}
	if (large!=index)
	{
		swap(m_h1,index,large);
		swap(m_h2,index,large);
		swap(m_h3,index,large);
		max_heapify(m_h1,m_h2,m_h3,limit,large);
	}
	return 0;

}

int heap_sort(int *time,int *deadline,int *index_array,int number)
{
	int numb=number;
	numb--;
	for (int ii=(number/2)-1;ii>=0;ii--)
	{
		max_heapify(time,deadline,index_array,number,ii);
	}
	for (int ss=number-1;ss>0;ss--)
	{
		max_heapify(time,deadline,index_array,numb,0);
		swap(time,ss,0);
		swap(deadline,ss,0);
		swap(index_array,ss,0);
		numb--;
	}
	return 0;
}

int annoyance(int cumulative,int deadline)
{
	if ((cumulative-deadline)>0)
	{
		return cumulative-deadline;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int *t,*d,*in;
	int n,c=0,index=0,max=0,total=0;
	scanf("%d\n",&n);
	t=(int*) malloc(n*sizeof(int));
	d=(int*) malloc(n*sizeof(int));
	in=(int*) malloc(n*sizeof(int));
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&t[i],&d[i]);
		in[i]=i;
	}
	heap_sort(t,d,in,n);
	while (t[index]!='\0')
	{
		if ((t[index]!='\0')&&(t[index+1]=='\0'))
		{
			printf("%d",in[index]+1);	
		}
		else
		{
			printf("%d,",in[index]+1);	
		}
		c+=t[index];
		int temp=annoyance(c,d[index]);
		total+=temp;
		max=(temp>=max)?temp:max;
		index++;
	}
	printf("\nTotal Annoyance=%d",total);
	printf("\nMaximum Annoyance=%d",max);
	free(t);
	free(d);
	free(in);
	return 0;
}
