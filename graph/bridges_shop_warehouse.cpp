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
vector<bool> vis;
vector<int> tin;
vector<int> ltin;
vector<int> edges;
int tt=1;
void bridges(int node,vector<int> adj[],int parent){
	vis[node]=true;
	tin[node]=tt;
	ltin[node]=tt;
	tt++;
	for(auto &x:adj[node]){
		if(x==parent)continue;
		else if(!vis[x]){
			bridges(x,adj,node);
			ltin[node]=min(ltin[node],ltin[x]);
			if(ltin[x]>tin[node]){
				cout<<node<<" "<<x<<endl;
				edges.push_back(min(tin[x],tin[node]));
			}
		}
		else{
			ltin[node]=min(ltin[node],ltin[x]);
		}
	}	
	
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int k;
	vector<pair<int,int>> queries;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		queries.push_back({x,y});
	}
	vis.resize(n+1,false);
	tin.resize(n+1,1e9);
	ltin.resize(n+1,1e9);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			bridges(i,adj,-1);
		}
	}
	for(int i=0;i<k;i++){
		int a=tin[queries[i].first];
		int b=ltin[queries[i].second];
		if(a>b){
			swap(a,b);
		}
		int count=0;
		for(int j=0;j<edges.size();j++){
			if(a<=edges[i] && b>=edges[i]){
				count++;
			}
		}
		cout<<count<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}