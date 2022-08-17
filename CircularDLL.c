#include <stdio.h>
#include<stdlib.h>

// Cicular Dll 
struct node{
    struct node* llink;
    int d;
    struct node* rlink;
};
typedef struct node dll;


struct ht
{
    dll* head,*tail;
}; typedef struct ht ptrs;

void insertfront(ptrs *p)
{
    dll* t;
    t=(dll*)malloc(sizeof(dll));
    printf("enter data\n");
    scanf("%d",&(t->d));
    if(p->head==0)
    {
        p->head=p->tail=t;
        p->tail->rlink=p->head;
        p->head->llink=p->tail;
        return;
    }
   
    p->head->llink=t;
    t->rlink=p->head;
    // t->llink=p->tail;
    p->tail->rlink=t;
    p->head=t;
   // p->head->llink=t;
    
}

void insertRear(ptrs *p)
{
    dll* t;
    t=(dll*)malloc(sizeof(dll));
    printf("enter data\n");
    scanf("%d",&(t->d));
    if(p->head==0)
    {
        p->head=p->tail=t;
        p->tail->rlink=p->head;
        p->head->llink=p->tail;
        return;
    }
   
   	t->llink=p->tail;
   	t->rlink=p->head;
   	p->tail->rlink=t;
   	p->tail=t;
    /*p->head->llink=t;
    t->rlink=p->head;
    // t->llink=p->tail;
    p->tail->rlink=t;
    p->head=t;
   // p->head->llink=t;
    */
}

void DeleteF(ptrs *p)
{
	if(p->head==0)
	{
		printf("Empty DLL\n");
		return ;
	}
	printf("First node contains: %d\n",p->head->d);
	dll *t= p->head;
	if(t->rlink==t)
	{
		p->head=0;
		p->tail=0;
		//empty condition
	}
	else
	{
		p->head=t->rlink;
		p->tail->rlink=t->rlink;
		p->head->llink=p->tail;
	}
	
	free(t);
}

void DeleteR(ptrs *p)
{
	if(p->head==0)
	{
		printf("Empty DLL\n");
		return ;
	}
	printf("Last node contains: %d\n",p->tail->d);
	dll *t= p->tail;
	if(t->llink==t)
	{
		p->head=0;
		p->tail=0;
		//empty condition
	}
	else
	{
		p->tail=t->llink;
		p->head->llink=t->llink;
		p->tail->rlink=p->head;
	}
	
	free(t);
}

void display(ptrs *p)
{
     if(p->head==0)
    {
        printf("Empty\n");
        return;
    }
    dll *t;
    //printf("%d\n",(p->head->d));
    for(t=p->head;t->rlink!=p->head;t=t->rlink)
        printf("%d\n",(t->d));
    printf("%d\n",(p->tail->d));
}

int main()
{
    ptrs p={0,0};
    int ch;
    while(1)
    {
        printf("1.I-F, 2.display,3:I-R,4:D-F 5:D-R Default exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insertfront(&p); break;
            case 2: display(&p); break;
            case 3: insertRear(&p);	break;
            case 4: DeleteF(&p);	break; 
            case 5: DeleteR(&p);	break; 
            default: exit(0);
        }
    }
    return 0;
}



