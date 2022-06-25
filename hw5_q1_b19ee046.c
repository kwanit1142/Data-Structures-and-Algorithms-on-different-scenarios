#include <stdio.h>
#include <stdlib.h>

int intp(int *arr,int num)
{
    for (int it=0;it<num;it++)
    {
        if (it==num-1)
        {
            scanf("%d",&arr[it]);
        }
        else
        {
            scanf("%d,",&arr[it]);
        }
    }
    return 0;
}

int outp(int *ar)
{
    for (int ot=0;ar[ot]!='\0';ot++)
    {
        printf("%d ",ar[ot]);
    }
    printf("\n");
    return 0;
}

int hashfunc(int value, int size)
{
    if (size == 0)
    {
        return -1;
    }
    else
    {
        return (value % size);
    }
}

int min(int num1, int num2)
{
    if (num1 > num2)
    {
        return num2;
    }
    else 
    {
        return num1;
    }
}

int *table(int *a, int num1, int *b, int num2)
{
    int mint = min(num1, num2);
    int index=0,i,count;
    int *hash = malloc(mint * sizeof(int));
    for (int j = 0; j < mint; j++)
    {
        hash[j] = -1;
    }
    if (mint == num1)
    {
        for (i = 0; i < mint; i++)
        {
            index = hashfunc(a[i], mint);
            while (hash[index] != -1)
            {
                index = (index + 1) % mint;
            }
            hash[index] = a[i];
        }
    }
    else 
    {
        for (i = 0; i < mint; i++)
        {
            index = hashfunc(b[i], mint);
            while (hash[index] != -1)
            {
                index = (index + 1) % mint;
            }
            hash[index] = b[i];
        }
    }
    return hash;
}

int CD(int *array,int *C,int*D,int temp[],int min_temp,int num,int c_index,int d_index)
{
    for (int st = 0; st < num; st++)
        {
            int count = 1;
            int index = hashfunc(array[st], min_temp);
            while (temp[index] != array[st])
            {
                index = (index + 1) % min_temp;
                count++;
                if (count == min_temp + 1)
                {
                    C[c_index] = array[st];
                    c_index++;
                    break;
                }
            }
            if (count != min_temp + 1)
            {
                D[d_index] = array[st];
                d_index++;
                temp[index] = -1;
            }
        }
    for (int rem = 0; rem < min_temp; rem++)
    {
        if (temp[rem] != -1)
        {
            C[c_index] = temp[rem];
            c_index++;
        }
    }
    return 0;
}

int main()
{
    int num1,num2,index;
    scanf("%d,", &num1);
    int *A = malloc(num1*sizeof(int));
    intp(A,num1);
    scanf("%d,", &num2);
    int *B = malloc(num2*sizeof(int));
    intp(B,num2);
    int min_temp = min(num1, num2);
    int *c_hash = table(A, num1, B, num2);
    int temp[min_temp];
    int *C = malloc((num1 + num2) * sizeof(int));
    int *D = malloc((num1 + num2) * sizeof(int));
    int j = 0,k = 0;
    for (int i = 0; i < min_temp; i++)
    {
        temp[i] = c_hash[i];
    }
    if (min_temp == num1)
    {
        CD(B,C,D,temp,min_temp,num1,j,k);
    }
    else 
    {
        CD(A,C,D,temp,min_temp,num1,j,k);
    }
    printf("Symmetric Difference (C) ==> ");
    outp(C);
    printf("Intersection (D) ==> ");
    outp(D);
    free(A);
    free(B);
    free(C);
    free(D);
    free(c_hash);
    return 0;
}