#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool dfs(int i,vector<vector<int>>& vis,vector<int>& adj[],int c){
	vis[i]=c;
	for(auto &node:adj[i]){
		if(vis[node]==-1){
			if(!dfs(node,vis,adj,1-c))return false;
		}
		else if(vis[node]==c){
			return false
		}
		
	}
	return true;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<int>> vis(n,vector<int>(m,-1));
	for(int i=0;i<n;i++){
			if(vis[i]==-1){
				if(!dfs(i,vis,adj,0)){
					cout<<"Not bipartite"<<endl;
					break;
				}
			}
	}
	return 0;
}