#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>

int display(int *out,int num)
{
	for (int i=1;i<=num;i++)
	{
		printf("%d ",out[i]);
	}
	return 0;
}

int minimum(int *array,bool *set,int num)
{
	int lim=INT_MAX,index;
	for (int s=0;s<num;s++)
	{
		if ((set[s]==false)&&(array[s]<=lim))
		{
			lim=array[s];
			index=s;
		}
	}
	return index;
}

int dijkstra_algo(int **matrix,int source,int num)
{
	int *distance,*out_distance;
	bool *interm;
	distance=(int *) malloc(num*sizeof(int));
	out_distance=(int *) malloc((num+1)*sizeof(int));
	interm=(bool *) malloc(num*sizeof(bool));
	for (int inter=0;inter<num;inter++)
	{
		distance[inter]=INT_MAX;
		interm[inter]=false;
	}
	distance[source-1]=0;
	for (int nu=0;nu<num-1;nu++)
	{
		int min_dist=minimum(distance,interm,num);
		interm[min_dist]=true;
		for (int un=0;un<num;un++)
		{
			if ((!interm[un])&&(matrix[min_dist][un])&&(distance[min_dist]!=INT_MAX)&&(distance[min_dist]+matrix[min_dist][un]<distance[un]))
			{
				distance[un]=distance[min_dist]+matrix[min_dist][un];
			}
		}
	}
	for (int ii=0;ii<num;ii++)
	{
		out_distance[ii+1]=distance[ii];
	}
	display(out_distance,num);
	free(distance);
	free(out_distance);
	free(interm);
	return 0;
}

int main()
{
	int i,j,**M,n,s;
	FILE *fp; 
	fp = fopen("input.txt","r"); 
	fscanf(fp,"%d %d",&n,&s); 
	M= (int **) malloc(sizeof(int *)*n);
	for(i=0; i<n; i++)
	{
		M[i] = (int*) malloc(sizeof(int)*n);
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{ 
			fscanf(fp,"%d",&M[i][j]);
		}
	}
	dijkstra_algo(M,s,n);
	fclose(fp);
	free(fp);
	for (int em=0;em<n;em++)
	{
		free(M[em]);
	}
	return 0;
}
