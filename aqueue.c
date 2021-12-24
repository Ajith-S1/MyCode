#include <stdio.h>
#include <stdlib.h>
#define MaX 5


// A linear Queue program to accept integer values 
void insert(int *q,int *r)
{
	if((*r)==MaX-1) 
	{
		printf("Overflow\n");return;
	}
	(*r)++;
	int ele;
	printf("Enter element\n");
	scanf("%d",&ele);
	q[*r]=ele;
}

void del(int*q,int*r,int*f)
{
	if(*f>*r)
	{
		printf("Empty queue\n");	return;
	}
	printf("element %d deleted\n",q[*f]);
	(*f)++;
}

void dis(const int*q,int r,int f)
{
	int i;
	if(f>r)
	{
		printf("Empty queue\n"); return;
	}
	printf("QUEUE\n");
	for(i=f;i<=r;i++)
		printf("%d : %d\n",i,q[i]);
	printf("\n");
}

int main()
{
	int q[MaX];
	int ch,r=-1,f=0;
	while(1)
	{
		printf("1:insert\n2:delete\n3:display\n4:exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert(q,&r); break;
			case 2:del(q,&r,&f); break;
			case 3: dis(q,r,f); break;
			default:exit(0);
				
		}
	} // infinite loop  Ends
	return 0;
}
