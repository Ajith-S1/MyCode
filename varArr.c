#include <stdio.h>
#include <string.h>
/*
int boardAux[length][length];
memset( boardAux, 0, length*length*sizeof(int) );
*/

int main()
{
   int m=5,n=5;
   int a[m][n];
    memset(a,0,m*n*sizeof(int) );
    return 0;
}

/* Here we can't initialize variable sized array 
   initialization in C99 so we use memset() under 		  string.h
*/
