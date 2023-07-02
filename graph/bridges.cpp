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
vector<int> tin;
vector<int> ltin;
int time=1;
int cnt=0;
vector<pair<int,int>> temp;
int bridges(int node,vector<bool>& vis,vector<vector<int>>& adj[],int par){
	vis[node]=true;
	tin[node]=time;
	ltin[node]=time;
	time++;
	for(auto &u:adj[node]){
		if(u==par)continue;
		if(vis[u]==false){
			bridges(u,vis,adj,node);
			lint[node] = min(lint[node],lint[u]);
			if(tin[node] < lint[u]){
				cnt++;
				temp.push({node,u});
			}
			
		}
		else{
			lint[node] = min(lint[node],lint[u]);
		}
	}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<int>> adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> vis(n,false);
	tin.resize(n,0);
	ltin.resize(n,0);
	bridges(0,vis,adj,-1);
	cout<<cnt;
	for(auto &v:temp){
		cout<<v.first<<" "<<v.second<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}