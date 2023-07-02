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
void bfs(vector<pair<int,int>> adj[],vector<unordered_set<int>>& times,int n){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	vector<ll> time_taken(n+1,2e9);
	pq.push({0,1});
	time_taken[1]=0;
	while(!pq.empty()){
		ll dist=pq.top().first;
		int node=pq.top().second;
		pq.pop();
		while(times[node].count(dist)){
			dist++;
		}
		for(auto &x:adj[node]){
			int adjnode=x.first;
			int adjtime=x.second;
			if(time_taken[adjnode]>dist+adjtime){
				time_taken[adjnode]=dist+adjtime;
				pq.push({time_taken[adjnode],adjnode});
			}
		}
	}
	if(time_taken[n]==2e9){
		cout<<-1<<endl;
		return;
	}
	cout<<time_taken[n];
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	vector<unordered_set<int>> times(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int tt;
			cin>>tt;
			times[i].insert(tt);
		}
	}
	bfs(adj,times,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}