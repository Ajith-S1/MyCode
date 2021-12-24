#include <stdio.h>
#include <stdlib.h>

#define M 3

struct empl
{
	char nm[40],id[25];
	float sal;
};

typedef struct empl emp;

struct Q
{
	emp *p;
	int r,f;	
};

typedef struct Q q;

void insert(q* p)
{
	if(p->r == M-1)
	{
		printf("Overflow\n"); return;
	}
	(p->r)++;
	int i=p->r;
	printf("Enter name , id ,salary\n");
	scanf("%s%s%f",p->p[i].nm,p->p[i].id,&(p->p[i].sal));
}

void del(q* p)
{
	if(p->f > p->r)
	{
		printf("Queue Empty\n"); return;
	}
	int i=p->f;
	printf("Element %s %s %f Deleted\n",p->p[i].nm,p->p[i].id,(p->p[i].sal));
	(p->f)++;
		
}

void dis(q* p)
{
	if(p->f > p->r)
	{
		printf("Queue Empty\n"); return;
	}
	int i=p->f;
	printf("Elements\n");
	for(;i<=(p->r);i++)
	printf(" %s %s %f \n",p->p[i].nm,p->p[i].id,(p->p[i].sal));
	
}

int main()
{
	q p={ .r=-1, .f=0 }; 
	p.p=(emp*)malloc(sizeof(emp)*M);
	int ch;
	while(1)
	{
		printf("1:insert\n2:Delete\n3:display\n4:exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert(&p); break;
			case 2:del(&p); break;
			case 3: dis(&p); break;
			default:exit(0);
		}
	
	}	
	return 0;
}
