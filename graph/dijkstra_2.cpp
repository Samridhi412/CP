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
void find_path(int par[], int n){
	stack<int> st;
	int curr=n;
	while(curr!=-1){
		st.push(curr);
		curr=par[curr];
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n+1);
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	vector<ll> dist(n+1,1e11+10);
	int parent[n+1];
	memset(parent,-1,sizeof(parent));
	dist[1]=0;
	parent[1]=-1;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		ll dst=pq.top().first;
		int node=pq.top().second;
		pq.pop();
		if(node==n){
			find_path(parent,n);
			return;
		}
		for(auto &x:adj[node]){
			ll present_dist=dist[x.first];
			int weight=x.second;
			if(present_dist>dst+weight){
				dist[x.first]=dst+weight;
				parent[x.first]=node;
				pq.push({dist[x.first],x.first});
			}
		}
	}
	cout<<"-1";
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}