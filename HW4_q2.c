#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val,height;
	struct node *left;
	struct node *right;
}NODE;

int input_line(int *input_array)
{
	char ch=0;
	int i=0,temp;
	while (scanf("%d%c",&temp,&ch)==2)
	{
		input_array[i]=temp;
		if (ch=='\n')
		{
			break;
		}
		i++;
	}
	return input_array[0];
}

int height_find(NODE *input)
{
	if (input ==NULL)
	{
		return 0;
	}
	else
	{
		return input->height;
	}
}

int factor(NODE *nod)
{
	if (nod == NULL)
	{
		return 0;
	}
	else
	{
		return ((height_find(nod->left)) - (height_find(nod->right)));
	}
}

NODE *create(int val)
{
	NODE *nodule;
	nodule = (NODE *) malloc (sizeof(NODE));
	nodule->val = val;
	nodule->left = NULL;
	nodule->right = NULL;
	nodule->height = 1;
	return nodule;
}

int compare(int a,int b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

NODE *rr(NODE *root) 
{ 
    NODE *lef = root->left; 
    NODE *Tree = lef->right;  
    lef->right = root; 
    root->left = Tree; 
    root->height = compare(height_find(root->left),height_find(root->right))+1; 
    lef->height = compare(height_find(lef->left),height_find(lef->right))+1; 
    return lef; 
} 
  
NODE *ll(NODE *root) 
{ 
    NODE *righ = root->right; 
    NODE *Tree = righ->left; 
    righ->left = root; 
    root->right = Tree; 
    root->height = compare(height_find(root->left),height_find(root->right))+1; 
    righ->height = compare(height_find(righ->left),height_find(righ->right))+1; 
    return righ; 
} 

NODE *avl(NODE *root, int val)
{
	if (root == NULL)
	{
		return create(val);
	}
	if (val < root->val)
	{
		root->left = avl(root->left,val);
	}
	else if (val > root->val)
	{
		root->right = avl(root->right,val);
	}
	else
	{
		return root;
	}

	root->height = 1 + compare(height_find(root->left),height_find(root->right));
	int bal_fac = factor(root);
	if (bal_fac >1 && val < root->left->val)
	{
		return rr(root);
	}
	if (bal_fac <-1 && val > root->right->val)
	{
		return ll(root);
	}
	if (bal_fac >1 && val > root->left->val)
	{
		root->left = ll(root->left);
		return rr(root);
	}
	if (bal_fac <-1 && val < root->right->val)
	{
		root->right = rr(root->right);
		return ll(root);
	}

	return root;
}

NODE * min_Val(NODE* node) 
{ 
    NODE* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 
  
NODE* delete(NODE* root, int val) 
{ 
    if (root == NULL) 
        return root; 
  
    if ( val < root->val ) 
        root->left = delete(root->left, val); 
  
    else if( val > root->val ) 
        root->right = delete(root->right, val); 
  
    else
    { 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            NODE *temp = root->left ? root->left : root->right; 
  
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
             *root = *temp; 
            free(temp); 
        } 
        else
        { 
            NODE* temp = min_Val(root->right); 
            root->val = temp->val; 
            root->right = delete(root->right, temp->val); 
        } 
    } 
    if (root == NULL) 
      return root; 
  
    root->height = 1 + compare(height_find(root->left),height_find(root->right)); 
    int balance = factor(root); 
    if (balance > 1 && factor(root->left) >= 0) 
        return rr(root); 
    if (balance > 1 && factor(root->left) < 0) 
    { 
        root->left =  ll(root->left); 
        return rr(root); 
    } 
    if (balance < -1 && factor(root->right) <= 0) 
        return ll(root); 
    if (balance < -1 && factor(root->right) > 0) 
    { 
        root->right = rr(root->right); 
        return ll(root); 
    } 
    return root; 
}

int in_order(NODE* display) 
{ 
     if (display == NULL) 
          return 0; 
     in_order(display->left); 
     printf("(%d,%d,%d) ", display->val,display->height,factor(display));   
     in_order(display->right); 
} 

int main()
{
	const int MAX= 100;
	int *inp_arr;
	int option;
	NODE *start = NULL;
	inp_arr = (int *) malloc(MAX*sizeof(int));
	option = input_line(inp_arr);
	while ((option<=4) && (option>0))
	{
		if (option==1)
		{
			for (int star=2;star<=(inp_arr[1])+1;star+=1)
			{
				start = avl(start,inp_arr[star]);
			}
			printf("\n Created \n");
			inp_arr[0]=1;
			option = input_line(inp_arr);
		}
		if (option ==2)
		{
			start=avl(start,inp_arr[1]);
			printf("\n Inserted \n");
			inp_arr[0]=1;
		    option = input_line(inp_arr);
		}
		if (option ==3)
		{
			start = delete(start,inp_arr[1]);
			printf("\n Deleted \n");
			inp_arr[0]=1;
		    option = input_line(inp_arr);
		}
		if (option ==4)
		{
			in_order(start);
			inp_arr[0]=1;
		    option = input_line(inp_arr);
		}
		free(inp_arr);
		printf("\n");
	}
	free(inp_arr);
	return 0;
}
