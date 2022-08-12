#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node*llink;
	int info;
	struct node*rlink;
};
typedef struct node nd;

void inorder(nd*r)
{
	if(r){
		inorder(r->llink);
		printf("%d\n",r->info);
		inorder (r->rlink);
		}
}	

nd* insert(nd*root,int key)
{
	nd *cur=root,*prev=0;
	nd *t=(nd*)malloc(sizeof(nd));
	t->info=key;
	t->llink=t->rlink=0;
	if(!cur)
		return t;
	while(cur)
	{
		if(t->info==cur->info)
		{
			printf("redundancy\n");
			free(t);return root;
		}
		prev=cur;
		if((t->info) < (cur->info))
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if((t->info)<(prev->info))
		prev->llink=t;
	else
		prev->rlink=t;
	return root;						
}
void recursearch(nd*root,int key)
{
	if(!root)
	{
		printf("unsuccessful search\n");
		return;
	}
	if(key==(root->info))
	{
		printf("successful search\n");
		return;
	}
	if(key < (root->info))
		return recursearch(root->llink,key);
	return recursearch(root->rlink,key);	
}
nd* deletenode(nd*root,int key)
{
	nd *cur=root,*parent,*q,*suc;
	if(!root)
	{
		printf("bst empty\n");
		return root;
	}
	parent=0;//cur=root;
	printf("cur : %x\n",cur);
	while(cur)
	{
			if(key==(cur->info))
		  {
			printf("successful search\n");
			break;
		  }
			parent =cur;
			if(key < (cur->info))
			   cur	=cur->llink;
			else
			    cur=cur->rlink;
			printf("%x : %d\n",cur,cur->info);	
	}	
	if(!cur)
	{
		printf("key not found\n");
		return root;
	}
	if(!(cur->llink))
		q=cur->rlink;
	else if(!(cur->rlink))
	    q= cur->llink;
	else
	{
		suc=cur->rlink;
		while(suc->llink)
			suc=suc->llink;
		suc->llink=cur->llink;
		q=cur->rlink;
	}
	if(!parent)return q;
	if(cur==parent->llink)
	{
	    parent->llink=q;
	}
	else
	{
	    parent->rlink=q;
	}
	free(cur);
	return root;
}						
			
			
			
			
		
int main()
{
	nd*root=0;
	int ch,i,key;
	FILE*fp;
	fp=fopen("data1.txt","r");
	if(fp==NULL)
	{
	    printf("File open error\n");
	    exit(1);
	}
	for(;;)
	{
	    printf("1:insert\n2:itSearch\n3:/rSearch\n4:Inorder\n5:Delete\n::exit\n");
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:fscanf(fp,"%d",&ch);
			for(i=0;i<ch;i++)
			{
				fscanf(fp,"%d",&key);
				root=insert(root,key);
			}
			break;				
			
		case 5: printf("enter info to be deleted\n");
				scanf("%d",&key);
				root=deletenode(root,ch);
				break;
		case 3: printf("enter info to be searched\n");
				scanf("%d",&key);
				recursearch(root,key);
				break;
		case 4:	inorder(root);
				break;
		//case 5:
		default : return 0; 		
		}
								
	}	
}			
