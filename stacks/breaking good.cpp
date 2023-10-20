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
int shorttest_path(int startnode, int endnode, vector<pair<int,int>> adj[]){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq;push({0,1});
	vector<int> dist;
	dist[1]=0;
	while(!pq.empty()){
		int dist = pq.front().first;
		int nn = pq.front().second;
		pq.pop();
		for(auto &x:adj[nn]){
			int adjnode = x.first;
			int wt = x.second;
			if()
		}
	}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<pair<int,int>> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v,x;
		cin>>u>>v>>x;
		adj[u].push_back({v,x});
		adj[v].push_back({u,x});
	}
	shorttest_path(1,n,adj);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}