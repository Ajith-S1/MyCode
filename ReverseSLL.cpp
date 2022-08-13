#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MX 1e6

struct node
{
	int data;
	struct node* link;
};

typedef struct node nd;

nd* insert(nd * f,int a)
{
	nd *t= (nd *)malloc(sizeof(nd));
	t->data = a;
	t->link=0;
	if(!f)
	{
		return t;
	}
	
	t->link= f;
	return t;
}

nd* reverseL(nd * f)
{
	if(!f || !(f->link))
		return f;
	
	nd *p=f,*t=f->link,*n;
	f->link=0;
	for(; t->link !=0; )
	{
		n = t->link;
		t->link = p;
		p=t;
		t = n;
	}
	t->link = p ;
	return t;
		
}

void display(nd *f)
{
	nd *t=f;
	printf("Elements are :\n");
	for(;t!=0;t=t->link)
		printf("%d ",t->data);
	printf("\n");
}
int main()
{
	nd *first=0;
	int ar[]={1,2,3,4,5};
	int i;
	for(i=4;i>=0;i--)
	{
		first = insert(first,ar[i]);
	}
	display(first);
	first = reverseL(first);
	display(first);
	
	return 0;
}

// 2 3 2

