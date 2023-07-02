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
void dfs(int node,vector<bool>& vis,vector<int>& adj[],stack<int>& st){
	vis[node]=1;
	for(auto& x:adj[node]){
		if(!vis[x]){
		dfs(x,vis,adj,st);
	}
	}
	st.push(node);
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
	stack<int> topo;
	vector<bool> vis(n,false);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(dfs(i,vis,adj,topo))return true;
		}
	}
	// vector<int> toposort(n);
	while(!topo.empty()){
		cout<<topo.top();
		topo.pop();
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}