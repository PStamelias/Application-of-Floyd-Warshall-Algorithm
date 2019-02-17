#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "flowar.h"
int main()
{
	int i,j;
	int ch;
	int** graph;
	int num=0;
	int N;
	while((ch=getchar())!='\n')
		num=num*10+ch-'0';
	N=num;
	graph=malloc(N*sizeof(int*));
	for(i=0;i<N;i++)
		graph[i]=malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		for(j=0;j<=i;j++){
			if(i==j){
				graph[i][j]=0;
				break;
			}
			scanf("%d",&graph[i][j]);
			graph[j][i]=graph[i][j];
		}
	}
	solve(N,graph);
	for(i=0;i<N;i++)
			free(graph[i]);
	free(graph);
}
