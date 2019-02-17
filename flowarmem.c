#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "flowar.h"
int min(int a,int b);
int cost(int i,int j,int k,int** graph,int*** memory_table);
void solve(int n,int** graph){/*Recursive with memoization*/
	int i,j,k;
  int value;
	int*** memory_table;
	memory_table=malloc(n*sizeof(int**));
	for(i=0;i<n;i++)
	  memory_table[i]=malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			memory_table[i][j]=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				memory_table[i][j][k]=-1;
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			value=cost(i,j,n-1,graph,memory_table);
			if(value==INT_MAX)
				printf("From node %d to node %d:There is no path\n",i,j);
			else
				printf("From node %d to node %d:Length of shortest path is %d\n",i,j,value);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		  free(memory_table[i][j]);
	for(i=0;i<n;i++)
		free(memory_table[i]);
	free(memory_table);
}
int cost(int i,int j,int k,int** graph,int*** memory_table){
	if(k<0){
		if(graph[i][j]==-1)
			return INT_MAX;
		return graph[i][j];
	}
	if(memory_table[i][j][k]!=-1)
		return memory_table[i][j][k];
	int a,b,c,g;
	a=cost(i,j,k-1,graph,memory_table);
	b=cost(i,k,k-1,graph,memory_table);
	c=cost(k,j,k-1,graph,memory_table);
	if(b==INT_MAX){
		memory_table[i][j][k]=min(a,b);
		return memory_table[i][j][k];
	}
	if(c==INT_MAX){
		memory_table[i][j][k]=min(a,c);
		return memory_table[i][j][k];
	}
	memory_table[i][j][k]=min(a,b+c);
	return memory_table[i][j][k];
}
int min(int a,int b){
	if(a>=b)
		return b;
	else
		return a;
}
