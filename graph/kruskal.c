#include<stdio.h>

#define MAX 1001

typedef struct _EdgeData{
	int start;
	int end;
	int weight;
}Edge;

Edge edge[MAX];
int edgenum = 0, vexnum = 0;

void get_graph(){
	printf("Please input the number of vertix and the number of edge:");
	scanf("%d,%d", &vexnum, &edgenum);
	printf("Please input the edges of this graph\n");
	for(int i = 0; i < edgenum; i++){
		int begin, end, weight;
		scanf("%d,%d,%d",&begin, &end, &weight);
		edge[i].start = begin;
		edge[i].end = end;
		edge[i].weight = weight;
	}
}

void sort_edge(){
	for(int i = 0; i < edgenum; i++){
		for(int j = i+1; j < edgenum; j++){
			if(edge[i].weight > edge[j].weight){
				Edge tmp = edge[i];
				edge[i] = edge[j];
				edge[j] = tmp;	
			}
		}
	}	
}

int get_parent(int v[], int x){
	while(v[x] !=x)
		x=v[x];
	return x;	
}

void kruskal(){
	int v[vexnum];
	int min_weight_sum = 0;
	int res[vexnum];

	for(int i=0; i<vexnum; i++)
		v[i] = i;

	for(int i=0; i<edgenum; i++){
		int m = get_parent(v, edge[i].start);
		int n = get_parent(v, edge[i].end);
		if(m!=n){
			v[m] = n;
			res[edge[i].start] = res[edge[i].end];
			printf("edge: (%d, %d,)  weight: %d\n",edge[i].start, edge[i].end, edge[i].weight);
			min_weight_sum += edge[i].weight;
		}
	}
	printf("The sum of weight is %d\n", min_weight_sum);
	
}

int main(){
	get_graph();
	sort_edge();
	kruskal();
	return 0;
}
