// Maze
#include <stdio.h>

#define sz 80

typedef struct
{
	short int vert,hrz;
}offset;

offset move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};


typedef struct
{
	short int r,c,d;
}ele;

ele st[sz];

int top,m,n;

// initializing size of maze
/*
#define EXIT_R m
#define EXIT_C n
*/

int maze[20][20]={0}; 
int mark[20][20]={0};

/* check for variable sized array initilaizetion 
memset() */

#define FALSE 0
#define TRUE 1

void getfile()
{
	FILE *fp=0;
	int i,j;
	fp=fopen("maze.txt","r");
	if(fp== NULL)
	{
		printf("FILE error \n");return;
	}
	fscanf(fp,"%d%d",&m,&n);
	for(i=0;i< (m + 2 ) ;i++)
		for(j=0;j< (n + 2 );j++)
			fscanf(fp,"%d",&maze[i][j]);
	printf("Maze input success\n");
	fclose(fp);
	
}


ele pop()
{
	if(top>-1)
		return st[top--];
	//return NULL;
}

void push(ele e)
{
	st[++top]=e;
}

void path()
{
	int i,r,c,nr,nc,dir,found=FALSE;
	ele pos;
	mark[1][1]=1;
	top=0;
	st[0].r = 1;
	st[0].c = 1;
	st[0].d = 0;
	while(top>-1 && !found)
	{
		pos =pop();
		r = pos.r;
		c = pos.c;
		dir = pos.d;
		while(dir<8 && !found)
		{
			nr = r + move[dir].vert;
			nc = c + move[dir].hrz;
			if(nr== m && nc == n && maze[nr][nc]!=1)
			found = TRUE;
			else
				if(!maze[nr][nc] && !mark[nr][nc]) 
				{
					mark[nr][nc]=1;
					pos.r = r;
					pos.c = c;
					pos.d = ++dir;
					push(pos);
					r=nr;
					c=nc;
					dir=0;
				}
				else
					++dir;
		}
		
	}
	
	if(found)
	{
		int i,j;
		printf("Path is\n row col \n");
		for(i=0;i<=top;i++)
			printf("%2d %5d \n",st[i].r,st[i].c);
		printf("%2d %5d \n",r,c );
		printf("%2d %5d \n",m,n );
		
		printf("\n mark [][] \n\n");
		for(i=0;i< (m + 2 ) ;i++)
		{
			for(j=0;j< (n + 2 );j++)
				printf("%d ",mark[i][j]);
			printf("\n");
		}
	}
	else
		printf("The maze does not have a path\n");
}

int main()
{
    //size();
	getfile();
	path();
	return 0;
}

