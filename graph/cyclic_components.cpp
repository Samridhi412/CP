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
void dfs(int node,vector<bool>& vis, vector<int> adj[],vector<int>& temp){
	vis[node]=true;
	temp.push_back(node);
	for(auto &x:adj[node]){
		if(vis[x]==false){
			dfs(x,vis,adj,temp);
		}
	}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	int total=0;
	vector<int> adj[n+1];
	vector<int> deg(n+1,0);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> vis(n+1,false);
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			vector<int> temp;
			dfs(i,vis,adj,temp);
			bool ok=true;
			for(auto &x:temp){
				if(deg[x]!=2){
					ok=false;
				}
			}
			if(ok)total++;
		}
	}
	cout<<total<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}