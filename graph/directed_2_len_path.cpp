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
vector<int> edges_dir;
vector<bool> vis;
bool dfs(int node, vector<int> adj[]){
	vis[node]=true;
	for(auto &y:adj[node]){
		if(edges_dir[y]==edges_dir[node]){
			return false;
		}
		else if(vis[y]==false){
			edges_dir[y]=1-edges_dir[node];
			if(!dfs(y,adj))return false;
		}
	}
	return true;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	vector<vector<int>> edges;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		edges.push_back({u,v});
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vis.resize(n+1,false);
	edges_dir.resize(n+1,-1);
	edges_dir[1]=0;
	if(!dfs(1,adj)){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		for(auto &ele:edges){
			if(edges_dir[ele[0]]==0){
				cout<<"0";
			}else{
				cout<<"1";
			}
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