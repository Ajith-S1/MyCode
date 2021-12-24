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

void insert(q* p,FILE *fp);
void del(q* p);
void dis(q* p);

int main()
{
	q p={ .r=-1, .f=0 }; 
	p.p=(emp*)malloc(sizeof(emp)*M);
	int ch;
	FILE *fp;
	fp=fopen("te.txt","r");
	if(fp== NULL)
	{
	    printf("File error \n"); exit(0);
	}
	while(1)
	{
		printf("1:insert\n2:Delete\n3:display\n4:exit\n");
		printf("Enter choice\n");
		fscanf(fp,"%d",&ch);
		switch(ch)
		{
			case 1:insert(&p,fp); break;
			case 2:del(&p); break;
			case 3: dis(&p); break;
			default: fclose(fp);
			        exit(0);
		}
	
	}	
	return 0;
}

void insert(q* p,FILE *fp)
{
	if(p->r == M-1)
	{
		printf("Overflow\n"); return;
	}
	(p->r)++;
	int i=p->r;
	printf("Enter name , id ,salary\n");
	fscanf(fp,"%s%s%f",p->p[i].nm,p->p[i].id,&(p->p[i].sal));
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

