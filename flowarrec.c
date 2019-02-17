#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "flowar.h"
int cost(int i,int j,int n,int** graph);
int min(int a,int b);
void solve(int n,int** graph){/*Recursive*/
	int i,j;
	int value;
	for(i=1;i<=n-1;i++){
		for(j=0;j<i;j++){
			value=cost(i,j,n-1,graph);
			if(value==INT_MAX)
				printf("From node %d to node %d:There is no path\n",i,j);
			else
				printf("From node %d to node %d:Length of shortest path is %d\n",i,j,value);
		}
		printf("\n");
	}
}

int cost(int i,int j,int k,int** graph){
	if(k<0){
		if(graph[i][j]==-1)
			return INT_MAX;
		return graph[i][j];
	}
	int a,b,c,g;
	a=cost(i,j,k-1,graph);
	b=cost(i,k,k-1,graph);
	c=cost(k,j,k-1,graph);
	if(b==INT_MAX)
		return min(a,b);
	if(c==INT_MAX)
		return min(a,c);
	return min(a,b+c);
}

int min(int a,int b){
	if (a>=b)
		return b;
	else 
		return a;
}
