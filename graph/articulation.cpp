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
vector<int> lint;
unordered_set<int> st;
int time=1;
void articulation(int node,int par,vector<bool>& vis,vector<vector<int>>& adj){
	vis[node]=true;
	tin[node]=time;
	lint[node]=time;
	time++;
	for(auto &x:adj[node]){
		if(x==par)continue;
		if(vis[x]==false){
			articulation(x,node,vis,adj);
			if(par!=-1 && lint[x] >= tin[node]){
				st.insert(node);
			}
		}
		else{
			lint[node] = min(lint[node], tin[x]);
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
	lint.resize(n,0);
	if(adj[0].size() > 1){
		st.insert(0);
	}
	articulation(0,-1,vis,adj);
	for(auto &y:st){
		cout<<y<<" ";
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}