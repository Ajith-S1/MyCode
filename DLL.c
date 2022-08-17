// doubly linked list employe data set
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char ssn[20],nm[30],dpt[10],dst[20],ph[12];
    float sal;
}emp;

typedef struct node* nodeP;
typedef struct node node;
struct node
{
    nodeP llink;
    emp data;
    nodeP rlink;
};

void insert_F(nodeP h)
{
    node *t;
    t=(node*)malloc(sizeof(node));
    printf("Enter the ssn,nm,dpt,dst,ph,salary\n");
    scanf("%s%s%s%s%s%f",(t->data).ssn,(t->data).nm,(t->data).dpt,(t->data).dst,(t->data).ph,&((t->data).sal));
    t->llink=t->rlink=0;
    
    if(h->rlink == 0)
    {
        h->rlink=t;
        return;
    }
    t->rlink = h-> rlink;
    (h->rlink)->llink = t;
    h->rlink = t;
}

void Delete_F(nodeP h)
{
    if(h->rlink == 0)
    {
        printf("empty dll\n");
        return;
    }
    node *t;
    t=h->rlink ;
    
     printf("%s\n%s\n%s\n%s\n%s\n%f\n",(t->data).ssn,(t->data).nm,(t->data).dpt,(t->data).dst,(t->data).ph,((t->data).sal));
    h->rlink = t->rlink;
    (h->rlink)->llink=0;
    free(t);
}

void display(const nodeP h)
{
    nodeP t;
    if(h->rlink==0)
    {
        printf("DLL empty\n"); return;
    }
    printf("First to Last DLL\n");
    for(t=h->rlink;t!=0;t=t->rlink)
        printf("%s\n%s\n%s\n%s\n%s\n%f\n",(t->data).ssn,(t->data).nm,(t->data).dpt,(t->data).dst,(t->data).ph,((t->data).sal));
}

int main()
{
    node header = { .llink =0, .rlink=0 };
    int ch;
    while(1)
    {
        printf("1.I_F\n2.display\n3:D_F\n6.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert_F(&header);  break;
            case 2: display(&header);   break;
            case 3: Delete_F(&header);  break;
            default : exit(0);
        }
    }
    return 0;
}


