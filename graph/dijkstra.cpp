/*
解决的是单源最短路径问题，不适用于存在负权边的图
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxv = 1000;
const int INF = 99999999;

int n,m,G[maxv][maxv];
int d[maxv],pre[maxv];
bool visit[maxv];

void DFS(int s,int v);

void Dijkstra_only_distance(int s){
	fill(d, d+maxv, INF);
	fill(visit, visit+maxv, false);
	for(int i=0; i<n; i++)
		pre[i] = i;
	d[s]=0;
	for(int i=0; i<n; i++){
		int u = -1, minD = INF;
		for(int j=0; j<n; j++)
			if(visit[j]==false && d[j]<minD){
				u = j;
				minD = d[j];
			}
		if(u == -1) //剩下的顶点和s不连通
			return;
		visit[u] = true;
		for(int v=0; v<n; v++)
			if(visit[v]==false && G[u][v]!=-1 && d[u]+G[u][v]<d[v]){
				d[v] = d[u] + G[u][v];
			}
		for(int i=0; i<n; i++)
			cout<<d[i]<<" ";
		cout<<endl;
	}
}

void Dijkstra_with_path(int s){
	fill(d, d+maxv, INF);
	fill(visit, visit+maxv, false);
	d[s]=0;
	for(int i=0; i<n; i++){
		int u = -1, minD = INF;
		for(int j=0; j<n; j++)
			if(visit[j]==false && d[j]<minD){
				u = j;
				minD = d[j];
			}
		if(u == -1) //剩下的顶点和s不连通
			return;
		visit[u] = true;
		for(int v=0; v<n; v++)
			if(visit[v]==false && G[u][v]!=-1 && d[u]+G[u][v]<d[v]){
				d[v] = d[u] + G[u][v];
				pre[v] = u;
		}
		/*
		for(int i=0; i<n; i++){
			cout<<"d[0] to d["<<n-1<<"]:";
			cout<<d[i]<<" ";
		}
		cout<<endl;
		*/
	}
}

void DFS(int s, int v){
	if(v==s){
		cout<<s<<" ";
		return;
	}
	DFS(s, pre[v]);
	cout<<v<<" ";
	return;
}

/*
int optValue;
vector<int> pre[maxv];
vector<int> path, tempPath;

void Dijkstra_two_factory(int s){
	fill(d, d+maxv, INF);
	fill(visit, visit+maxv, false);
	d[s]=0;
	for(int i=0; i<n; i++){
		int u = -1, minD = INF;
		for(int j=0; j<n; j++)
			if(visit[j]==false && d[j]<minD){
				u = j;
				minD = d[j];
			}
		if(u == -1) //剩下的顶点和s不连通
			return;
		visit[u] = true;
		for(int v=0; v<n; v++)
			if(visit[v]==false && G[u][v]!=-1){
				if(d[u]+G[u][v]<d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
	}
}

void DFS(int v){
	if(v == st){
		tempPath.push_back(v);
		int value = 0;
		//边权之和
		for(int i=tempPath.size()-1; i>0; i--){
			int id = tempPath[i], idNext=tempPath[i-1];
			value += V[id][idNext];
		}
		//点权之和
		for(int i=tempPath.size()-1; i>0; i--){
			int id = tempPath[i]
			value += w[id];
		}		
		if(value>optValue){
			optValue = value;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0; i<pre[v].size(); i++)
		DFS(pre[v][i]);
	tempPath.pop_back();
}
*/
int main(){
	int u,v,w,s;
	cout<<"Please input the number of vertix, the number of edge, and the start vertix:\n";
	cin>>n>>m>>s;
	fill(G[0],G[0]+maxv*maxv,-1);
	cout<<"Please input the edges:\n";
	while(m--){
		cin>>u>>v>>w;
		G[u][v]=w;
	}
	Dijkstra_with_path(s);

	for(int i=0; i<n; i++){
		cout<<"The shortest path from vertix "<<s<<" to vertix "<<i<<": ( ";
		cout<<"distance: "<<d[i]<<" , path:";
		DFS(s,i);
		cout<<")";
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
/*
6 8 0
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3
*/

