#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int cost(int i,int j,int k,int** graph);
int min(int a,int b);
void solve(int n,int** graph){/*Dynamic Programming*/
	int i,j;
	int value;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++)
			value=cost(i,j,n-1,graph);
		printf("\n");
	}
}
int cost(int I,int J,int K,int** graph){
	int i,j,k;
	int n=K+1;
#ifdef PATH
	int next[n][n];
#endif	
	int value;
	int a,b,c;
	int Q[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(graph[i][j]==-1)
				Q[i][j]=INT_MAX;
			else
				Q[i][j]=graph[i][j];
#ifdef PATH
			if(i==j||Q[i][j]==INT_MAX) 
				next[i][j]=-1;
			else 
				next[i][j]=j;
#endif
		}
	}
	for(k=0;k<=K;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				a=Q[i][j];
				b=Q[i][k];
				c=Q[k][j];
				if(b==INT_MAX)
					Q[i][j]=min(a,b);
				else if(c==INT_MAX)
					Q[i][j]=min(a,c);
				else{
					Q[i][j]=min(a,b+c);
#ifdef PATH
					if(a>b+c)
						next[i][j]=k;
#endif
				}
			}
		}
	}
	value=Q[I][J];
	if(value==INT_MAX)
		printf("From node %d to node %d:There is no path\n",I,J);
	else
		printf("From node %d to node %d:Length of shortest path is %d\n",I,J,value);
#ifdef PATH
	int start=I;
	int end=J;
	if(next[end][start]==-1)
		return Q[I][J];
	printf("\tShortest path is: %d ->",start);
	while(1){
		if(next[start][end]==end){
			printf(" %d\n",end);
			break;
		}
		else{
			printf(" %d ->",next[start][end]);
			start=next[start][end];
		}
	}
#endif
	return 0;
}
int min(int a,int b){
	if(a>=b)
		return b;
	else
		return a;
}