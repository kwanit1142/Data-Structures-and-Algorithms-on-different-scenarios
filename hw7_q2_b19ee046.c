#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int pick(int item,int *arr)
{
	while (arr[item] != item)
	{
		item = arr[item];
	}
	return item;
}

int change(int x,int y,int *array)
{
	int a = pick(x,array);
	int b = pick(y,array);
	array[a] = b;
	return 0;
}

int display(int **poi,int number)
{
	for (int i=0;i<number;i++)
	{
		for (int j=0;j<number;j++)
		{
			printf("%d ",poi[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int MST(int **matrix,int num,int *array)
{
	int total=0,count=0;
	while (count<num-1)
	{
		int limit=INT_MAX;
		int a=-1,b=-1;
		for (int row=0;row<num;row++)
		{
			for (int col=0;col<num;col++)
			{
				if ((pick(row,array) !=pick(col,array))&&(matrix[row][col]<limit))
				{
					limit=matrix[row][col];
					a=row;
					b=col;
				}
			}
		}
		count++;
		if ((a!=-1) && (b!=-1))
		{
			total+=matrix[a][b];
		}
		change(a,b,array);
	}
	return total;
}

int main()
{
	int i,j,result,**M,n,*track;
	FILE *fp; 
	fp = fopen("input.txt","r"); 
	fscanf(fp,"%ld",&n); 
	M= (int **) malloc(sizeof(int *)*n);
	track=(int *) malloc(n*sizeof(int));
	for(i=0; i<n; i++)
	{
		track[i]=i;
		M[i] = (int*) malloc(sizeof(int)*n);
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{ 
			fscanf(fp,"%d",&M[i][j]);
		}
	}
	result=MST(M,n,track);
	printf("%d",result);
	fclose(fp);
	free(fp);
	free(track);
	for (int em=0;em<n;em++)
	{
		free(M[em]);
	}
	return 0;
}