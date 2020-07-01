#include<stdio.h>
#include<string.h>

#define MAX 1001
int matrix[MAX][MAX];
int edgenum = 0, vexnum = 0;
void get_graph(){
        printf("Please input the number of vertix and the number of edge:");
        scanf("%d,%d", &vexnum, &edgenum);
        printf("Please input the edges of this graph\n");
        for(int i = 0; i < edgenum; i++){
                int begin, end, weight;
                scanf("%d,%d,%d",&begin, &end, &weight);
				matrix[begin][end] = weight;
				matrix[end][begin] = weight;
        }
}
void prim(){
	int v_new[vexnum], v_count = 0, min_weight_sum = 0;
	memset(v_new, 0, sizeof(v_new));
	v_new[0] = 1;
	v_count++;
	
	while(v_count < vexnum){
		int min = MAX;
		int s = -1, e = -1;
		for(int i = 0; i < vexnum; i++){
			if(v_new[i] == 0) continue;
			for(int j = 0; j < vexnum; j++){
				if(matrix[i][j] > 0 && matrix[i][j] < min && v_new[j] == 0){
					min = matrix[i][j];
					s = i;
					e = j;
					//printf("%d, %d ,%d\n", i, j, min);
				}
			}
		}
		if(e!=-1){
			v_new[e] = 1;
			//printf("e = %d,	", e);
			printf("edge: (%d,%d), weight: %d\n", s, e, matrix[s][e]);
			v_count++;
			min_weight_sum += matrix[s][e];
		}
	}
	printf("the sum of weight is %d\n",min_weight_sum);
}

int main(){
	get_graph();
	prim();
	return 0;
}
