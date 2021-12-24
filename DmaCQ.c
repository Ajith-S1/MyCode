#include <stdio.h>
#include <stdlib.h>

#define M 3
int m=M;
struct empl
{
	char nm[40],id[25];
	float sal;
};

typedef struct empl emp;

struct Q
{
	emp *p;
	int r,f,cnt;	
};

typedef struct Q q;

void insert(q* p)
{
	if(p->cnt == M)
	{
		printf("Overflow\n"); 
		printf("ReSizing Memory\n");
		m*=2;
		p->p=(emp*)realloc(p->p,sizeof(emp)*M);
		
	}
	(p->cnt)++;
	(p->r)=((p->r)+1)%m;
	int i=p->r;
	printf("Enter name , id ,salary\n");
	scanf("%s%s%f",p->p[i].nm,p->p[i].id,&(p->p[i].sal));
}

void del(q* p)
{
	if(p->cnt==0)
	{
		printf("Queue Empty\n"); return;
	}
	int i=p->f;
	printf("Element %s %s %f Deleted\n",p->p[i].nm,p->p[i].id,(p->p[i].sal));
	p->f=((p->f)+1)%m;
	(p->cnt)--;
		
}

void dis(q* p)
{
	if(p->cnt==0)
	{
		printf("Queue Empty\n"); return;
	}
	int i=p->f,k,j;
	printf("Elements\n");
	for(k=i,j=0;j<(p->cnt);j++)
	{
	printf(" %s %s %f \n",p->p[k].nm,p->p[k].id,(p->p[k].sal));
	k=(k+1)%m;
	}
}

int main()
{
	q p={ .r=-1, .f=0 , .cnt=0}; 
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
