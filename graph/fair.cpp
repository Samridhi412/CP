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
int vis[100005];
void bfs(int g1,vector<int> goods[], vector<vector<int>>& dis, vector<int> adj[]){
	queue<pair<int,int>> q;
	for(int i=0;i<goods[g1].size();i++){
		q.push({0,goods[g1][i]});
		vis[goods[g1][i]]=true;
	}
	while(!q.empty()){
		int dist=q.front().first;
		int node=q.front().second;
		q.pop();
		dis[node][g1]=dist;
		for(auto &x:adj[node]){
			if(vis[x]==false){
				q.push({dist+1,x});
				vis[x]=true;
			}
		}
	}
}
void solve(){
	ll n,m,k,s;
	cin>>n>>m>>k>>s;
	vector<int> goods[k+1];
	vector<vector<int>> dis(n+1,vector<int>(k+1,0));
	for(int i=1;i<=n;i++){
		int good;
		cin>>good;
		goods[good].push_back(i);
	}
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		memset(vis,false,sizeof(vis));
		bfs(i,goods,dis,adj);
	}
	for(int i=1;i<=n;i++){
		vector<int> b(k+1);
		for(int j=1;j<=k;j++){
			b[j]=dis[i][j];
		}
		sort(b.begin(),b.end());
		int total=0;
		for(int l=1;l<=s;l++){
			total+=b[l];
		}
		cout<<total<<" ";
	}
	
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}