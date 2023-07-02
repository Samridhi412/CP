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
set<pair<ll,ll>> st;
bool vis[2e5];
void bfs(ll n1,ll n2,vector<ll> adj[]){
	queue<pair<ll,ll>> q;
	q.push({0,n1});
	while(!q.empty()){
		ll dst=q.front().first;
		ll nn=q.front().second;
		if(nn==n2){
			return;
		}
		for(auto &x:adj[nn]){
			if(vis[x]==false){
				q.push({dst+1,x});
				st.insert({nn,x});
				vis[x]=true;
			}		
		}
	}
}
void solve(){
	st.clear();
	memset(vis,false,sizeof(vis));
	ll n,m,a,b,c;
	cin>>n>>m>>a>>b>>c;
	vector<ll> prices(m);
	for(ll i=0;i<m;i++){
		cin>>prices[i];
	}
	vector<ll> adj[n+1];
	for(ll i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(a,b,adj);
	bfs(b,c,adj);
	ll total=0;
	sort(prices.begin(),prices.end());
	for(int i=0;i<st.size();i++){
		total+=prices[i];
	}
	cout<<total<<endl;
	
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