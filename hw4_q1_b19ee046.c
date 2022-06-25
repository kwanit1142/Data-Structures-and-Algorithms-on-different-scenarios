#include<stdio.h>
#include<stdlib.h>

int input_line(int *input_array)
{
	char ch=0,temp;
	int i=0;
	while (scanf("%c%c",&temp,&ch)==2)
	{
		if (i==1)
		{
			input_array[i]= (int) temp;
		}
		else
		{
			input_array[i]= (int) temp;
			input_array[i]-=48;
		}
		if (ch=='\n')
		{
			break;
		}
		i++;
	}
	return input_array[0];
}

int swap(int *ar,int x,int y)
{
	int c;
	c=ar[x];
	ar[x]=ar[y];
	ar[y]=c;
	return 0;
}

int max_heapify(int *m_h,int index)
{
	int large;
	int l=2*index,r=(2*index)+1;
	if ((l<=m_h[0]) && (m_h[l]>=m_h[index]))
	{
		large=l;
	}
	else
	{
		large=index;
	}
	if ((r<=m_h[0]) && (m_h[r]>=m_h[large]))
	{
		large=r;
	}
	if (large!=index)
	{
		swap(m_h,index,large);
		max_heapify(m_h,large);
	}
	return 0;
}

int min_heapify(int *mi_h,int indexx)
{
	int small;
	int ll=2*indexx,rr=(2*indexx)+1;
	if ((ll<=mi_h[0]) && (mi_h[ll]<=mi_h[indexx]))
	{
		small=ll;
	}
	else
	{
		small=indexx;
	}
	if ((rr<=mi_h[0]) && (mi_h[rr]<=mi_h[small]))
	{
		small=rr;
	}
	if (small !=indexx)
	{
		swap(mi_h,indexx,small);
		min_heapify(mi_h,small);
	}
	return 0;
}

int create_max(int *mah,int *inp)
{
	int half;
	for (int n=2;inp[n]!='\0';n++)
	{
		mah[n-2]=inp[n];
	}
	half=mah[0];
	half/=2;
	for (int ii=half;ii>0;ii--)
	{
		max_heapify(mah,ii);
	}
	for (int y=1;mah[y]!='\0';y++)
	{
		printf("%d ",mah[y]);
	}
	return 0;
}

int insert_max(int *mahi,int *inpi)
{
	int half;
	mahi[0]++;
	mahi[mahi[0]] = inpi[2];
	half= mahi[0]/2;
	for (int ii=half;ii>0;ii--)
	{
		max_heapify(mahi,ii);
	}
	for (int iy=1;mahi[iy]!='\0';iy++)
	{
		printf("%d ",mahi[iy]);
	}
	return 0;
}

int delete_max(int *mahd,int *inpd)
{
	int search=-1,indexd;
	for (int se=1;mahd[se]!='\0';se++)
	{
		if (mahd[se]==inpd[2])
		{
			search=se;
			break;
		}
	}
	if (search !=-1)
	{
		swap(mahd,search,mahd[0]);
		mahd[0]--;
	}
	indexd = mahd[0]/2;
	for (int id=indexd;id>0;id--)
	{
		max_heapify(mahd,id);
	}
	for (int dy=1;dy<=mahd[0];dy++)
	{
		printf("%d ",mahd[dy]);
	}
	return 0;
}

int sort_max(int *mahs)
{
	int numb=mahs[0];
	mahs[0]--;
	for (int ss=numb;ss>1;ss--)
	{
		swap(mahs,ss,1);
		mahs[0]--;
		max_heapify(mahs,1);
	}
	for (int s=1;s<=numb;s++)
	{
		printf("%d ",mahs[s]);
	}
	mahs[0]=numb;
	return 0;
}

int out_max(int *maho)
{
	int indexdo;
	swap(maho,1,maho[0]);
	maho[0]--;
	indexdo = maho[0]/2;
	for (int ido=indexdo;ido>0;ido--)
	{
		max_heapify(maho,ido);
	}
	for (int ddy=1;ddy<=maho[0];ddy++)
	{
		printf("%d ",maho[ddy]);
	}
	return 0;
}

int create_min(int *mih,int *inpc)
{
	int hal;
	for (int nn=2;inpc[nn]!='\0';nn++)
	{
		mih[nn-2]=inpc[nn];
	}
	hal = inpc[2];
	hal/=2;
	for (int iii=hal;iii>0;iii--)
	{
		min_heapify(mih,iii);
	}
	for (int yy=1;mih[yy]!='\0';yy++)
	{
		printf("%d ",mih[yy]);
	}
	return 0;
}

int insert_min(int *mihi,int *inpii)
{
	int half;
	mihi[0]++;
	mihi[mihi[0]] = inpii[2];
	half= mihi[0]/2;
	for (int ii=half;ii>0;ii--)
	{
		min_heapify(mihi,ii);
	}
	for (int iiy=1;mihi[iiy]!='\0';iiy++)
	{
		printf("%d ",mihi[iiy]);
	}
	return 0;
}

int delete_min(int *mihd,int *inpdd)
{
	int searchd=-1,indexdd;
	for (int sed=1;mihd[sed]!='\0';sed++)
	{
		if (mihd[sed]==inpdd[2])
		{
			searchd=sed;
			break;
		}
	}
	if (searchd !=-1)
	{
		swap(mihd,searchd,mihd[0]);
		mihd[0]--;
	}
	indexdd = mihd[0]/2;
	for (int idd=indexdd;idd>0;idd--)
	{
		min_heapify(mihd,idd);
	}
	for (int ddy=1;ddy<=mihd[0];ddy++)
	{
		printf("%d ",mihd[ddy]);
	}
	return 0;
}

int sort_min(int *mihs)
{
	int numb=mihs[0];
	mihs[0]--;
	for (int ss=numb;ss>1;ss--)
	{
		swap(mihs,ss,1);
		mihs[0]--;
		min_heapify(mihs,1);
	}
	for (int s=1;s<=numb;s++)
	{
		printf("%d ",mihs[s]);
	}
	mihs[0]=numb;
	return 0;
}

int out_min(int *miho)
{
	int indexddo;
	swap(miho,1,miho[0]);
	miho[0]--;
	indexddo = miho[0]/2;
	for (int iddo=indexddo;iddo>0;iddo--)
	{
		min_heapify(miho,iddo);
	}
	for (int ddy=1;ddy<=miho[0];ddy++)
	{
		printf("%d ",miho[ddy]);
	}
	return 0;
}

int main()
{
	const int MAX_SIZE = 100;
	int *inp_arr,*max_heap,*min_heap;
	int option;
	inp_arr = (int*) malloc(MAX_SIZE*sizeof(int));
	max_heap = (int*) malloc(MAX_SIZE*sizeof(int));
	min_heap = (int*) malloc(MAX_SIZE*sizeof(int));
	option= input_line(inp_arr);
	while ((option<=5) && (option>0))
	{
		if (option==1)
		{
			if ((inp_arr[1]==120) || (inp_arr[1]==88))
			{
				create_max(max_heap,inp_arr);
			}
			if ((inp_arr[1]==110) || (inp_arr[1]==78))
			{
				create_min(min_heap,inp_arr);
			}
		}
		else if(option==2)
		{
			if ((inp_arr[1]==120) || (inp_arr[1]==88))
			{
				insert_max(max_heap,inp_arr);
			}
			if ((inp_arr[1]==110) || (inp_arr[1]==78))
			{
				insert_min(min_heap,inp_arr);
			}	
		}
		else if(option==3)
		{
			if ((inp_arr[1]==120) || (inp_arr[1]==88))
			{
				delete_max(max_heap,inp_arr);
			}
			if ((inp_arr[1]==110) || (inp_arr[1]==78))
			{
				delete_min(min_heap,inp_arr);
			}	
		}
		else if(option==4)
		{
			if ((inp_arr[1]==120) || (inp_arr[1]==88))
			{
				out_max(max_heap);
			}
			if ((inp_arr[1]==110) || (inp_arr[1]==78))
			{
				out_min(min_heap);
			}	
		}
		else if(option==5)
		{
			if ((inp_arr[1]==120) || (inp_arr[1]==88))
			{
				sort_max(max_heap);
			}
			if ((inp_arr[1]==110) || (inp_arr[1]==78))
			{
				sort_min(min_heap);
			}	
		}
		else
		{
			;
		}
		free(inp_arr);
		inp_arr[0]=0;
		printf("\n");
		option = input_line(inp_arr);
	}
	free(inp_arr);
	free(max_heap);
	free(min_heap);
	return 0;
}