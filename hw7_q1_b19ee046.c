#include<stdio.h>
#include<stdlib.h>

int index = 0;

int DFS(char **res,int start,int num,int *visit,int *traversal,int **AM,int *st,int *ft,int time)
{
	int tt=time+1;
	traversal[index++]=start+1;
	st[start]=tt;
	visit[start]=1;
	for (int i=0;i<num;i++)
	{
		if (AM[start][i] ==1 && (visit[i]==0))
		{
			res[start][i]='T';
			tt=DFS(res,i,num,visit,traversal,AM,st,ft,tt);
		}
	}
	tt++;
	ft[start]=tt;
	return tt;
}

int edge(char **res,int **inp,int *start,int *finish,int last)
{
	for (int x=0;x<last;x++)
	{
		for (int y=0;y<last;y++)
		{
			if (inp[x][y]==1)
			{
				if ((finish[y]>start[y]) && (finish[x]>start[x]) && (finish[y]<start[x]))
				{
					res[x][y]='C';
				}
				if ((start[x]<start[y]) && (finish[x]>finish[y]) && (start[y]<finish[y]))
				{
					if (res[x][y]!='T')
					{
						res[x][y]='F';
					}
				}
				if ((start[x]>start[y]) && (finish[x]<finish[y]) && (start[x]<finish[x]))
				{
					res[x][y]='B';
				}
			}
		}
	}
	return 0;
}

int main()
{
	int i,j, n,**M,*vis,*trav,*st,*ft,time=0,temp;
	char **res;
	FILE *fp; 
	fp = fopen("input.txt","r"); 
	fscanf(fp,"%d",&n); 
	M= (int **) malloc(sizeof(int *)*n);
	res= (char **) malloc(sizeof(char *)*n);
	vis=(int*) malloc(n*sizeof(int));
	trav=(int*) malloc(n*sizeof(int));
	st=(int*) malloc(n*sizeof(int));
	ft=(int*) malloc(n*sizeof(int));
	for(i=0; i<n; i++)
	{ 
		vis[i]=0;
		st[i]=0;
		ft[i]=0;
		M[i] = (int*) malloc(sizeof(int)*n);
		res[i] = (char*) malloc(sizeof(char)*n);
	}
	for(i=0; i<n; i++)
	{ 
		for(j=0; j<n; j++)
		{ 
			fscanf(fp,"%d",&M[i][j]);
			res[i][j]='0';
		}
	}
	temp=DFS(res,0,n,vis,trav,M,st,ft,time);
	edge(res,M,st,ft,n);
	for (int ii=0;ii<n;ii++)
	{
		printf("%d %d %d\n",trav[ii],st[trav[ii]-1],ft[trav[ii]-1]);
	}
	for (int x=0;x<n;x++)
	{
		for (int y=0;y<n;y++)
		{
			printf("%c ",res[x][y]);
		}
		printf("\n");
	}
	fclose(fp);
	free(fp); 
	free(vis);
	free(st);
	free(ft);
	free(trav);
	for (int em=0;em<n;em++)
	{
		free(res[em]);
		free(M[em]);
	}
	free(res);
	free(M);
	return 0;
} 