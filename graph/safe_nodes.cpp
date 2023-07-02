#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
bool dfs(int node,vector<int>& adj[],vector<bool>& vis,vcetor<bool>& pathvis,vector<bool>& safe_nodes){
	vis[node]=true;
	pathvis[node]=true;
	for(auto &x:adj[node]){
		if(!vis[x]){
			if(dfs(x,adj,vis,pathvis,safe_nodes))return true;
		}
		else if(pathvis[node]){
			return true
		}
	}
	pathvis[node]=false;
	safe_nodes[node]=true;
	return false;
	
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	vector<bool> vis(n,false);
	vector<bool> pathvis(n,false);
	vector<bool> safe_nodes(n,false);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,adj,vis,pathvis,safe_nodes);
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}