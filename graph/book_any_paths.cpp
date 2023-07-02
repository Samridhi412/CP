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
vector<ll> dist;
vector<bool> vis;
vector<ll> infinte;
vector<ll> cycle;
vector<ll> morethanone;
vector<bool> pathvis;
vector<ll> ans;
vector<bool> vis1;
void dfs(int node,vector<int> adj[]){
	vis[node]=1;
	pathvis[node]=1;
	for(auto &x:adj[node]){
		if(!vis[x]){
			dfs(x,adj);
		}else if(pathvis[x]){
			cycle.push_back(x);
		}else{
			morethanone.push_back(x);
		}
	}
	pathvis[node]=0;
}
void infiniteset(int node,vector<int> adj[]){
	vis1[node]=1;
	ans[node]=-1;
	for(auto &x:adj[node]){
		if(!vis1[x]){
			infiniteset(x,adj);
		}
	}
}
void cyclic(int node,vector<int> adj[]){
	vis1[node]=1;
	ans[node]=-1;
	for(auto &x:adj[node]){
		if(!vis1[x]){
			cyclic(x,adj);
		}
	}
}
void morethanset(int node,vector<int> adj[]){
	vis1[node]=1;
	if(ans[node]!=-1)ans[node]=2;
	for(auto &x:adj[node]){
		if(!vis1[x]){
			morethanset(x,adj);
		}
	}
}
void solve(){
dist.clear();
vis.clear();
infinte.clear();
cycle.clear();
morethanone.clear();
pathvis.clear();
ans.clear();
vis1.clear();
	ll n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		if(u==v){
			infinte.push_back(u);
		}
	}
	ans.resize(n+1);
	vis.resize(n+1,false);
	pathvis.resize(n+1,false);
    dfs(1,adj);	
	vis1.resize(n+1,false);
	for(auto &y:cycle){
		if(!vis1[y]){
			cyclic(y,adj);
		}
	}
	for(int i=1;i<=n;i++){
		vis1[i]=false;
	}
	for(auto &x:morethanone){
		if(!vis1[x]){
			morethanset(x,adj);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans[i]=0;
		}else if(ans[i]!=2 && ans[i]!=-1){
			ans[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}