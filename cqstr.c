#include <stdio.h>
#include <stdlib.h>

int MAX = 3;

struct employee{
	char *name; 
	char *eid; 
	float *salary; 
};

typedef struct employee emp;

emp *insert(emp *, int *, int *, int *); 
void delete(emp *, int *,int *, int *);
void display(emp *, int , int );

int main(){
	int r = -1, f= 0,ch,cnt= 0,i;
	emp *a = 0;
	a = (emp *)malloc(sizeof(emp)*MAX);
	while(1){
		printf("1.INSERT 2.DELETE 3.DISPLAY 4.EXIT\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
				a = insert(a,&r,&f,&cnt); break;
			case 2: 
				delete(a,&r,&f,&cnt); break;
			case 3: 
				display(a,f,cnt); break;
			case 4: 
				for( i = 0; i<cnt; i++){
					free(a[i].name);
					free(a[i].eid);
					free(a[i].salary); 
				}
				free(a); 
				exit(0);
		}
	} 
	return 0; 
}

emp *insert(emp *a, int *r, int *f, int *cnt){
	int i,j=0;
	emp *q = a; 
	if(*cnt == MAX){
		q = (emp *)realloc(q,sizeof(emp)*(*cnt)*2);
		if(*r > *f){
			for(i = (*f); i<= (*r); i++)
				q[i] = a[i];
		}
		else
		{ 
			for(i = (*f); i<MAX; i++)
				q[j++] = a[i]; 	
			for(i = 0; i<= (*f); i++)
				q[j++] = a[i]; 
		}
		free(a); 
		(*f) = 0; (*r) = MAX -1; 
		MAX*=2; 
	}
	
	/*emp emp1; 
	emp1.name = (char *)malloc(20); 
	emp1.eid = (char *)malloc(10); 
	emp1.salary = (float *)malloc(sizeof(float));

	scanf("%s",emp1.name);
	scanf(" %s",emp1.eid);
	scanf(" %f",emp1.salary);*/
	(*r) = ((*r)+1)%MAX; 
	//q[(*r)] = emp1; 
	q[(*r)].name = (char *)malloc(20); 
	q[(*r)].eid = (char *)malloc(10); 
	q[(*r)].salary = (float *)malloc(sizeof(float));	
	scanf("%s",q[(*r)].name);
	scanf(" %s",q[(*r)].eid);
	scanf(" %f",q[(*r)].salary);
	(*cnt)++; 
	return q;  	
}

void delete(emp *a,int *r, int *f,int *cnt){
	if((*cnt)== 0){
		printf("QUEUE EMPTY\n"); return; 
	}
	printf("Employee details deleted from the queue is: \n");
	printf("NAME: %s\n",a[(*f)].name);
	printf("EID: %s\n",a[(*f)].eid);
	printf("SALARY: %f\n",*(a[(*f)].salary));
	(*f) = ((*f) + 1)%MAX; 
	(*cnt)--; 
}

void display(emp *a,int f,int cnt){
	int i,j;
	for(i = f, j = 0; j<cnt; j++){
		printf("NAME: %s\n",a[i].name);
		printf("EID: %s\n",a[i].eid);
		printf("SALARY: %f\n",*(a[i].salary));
		i = (i+1)%MAX; 
	}	
}

