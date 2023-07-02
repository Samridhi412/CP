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
int dx[8]={0,0,1,1,-1,-1,-1,1};
int dy[8]={1,-1,0,1,0,1,-1,-1};
bool possible(int i,int j,vector<vector<bool>>& vis,int** islands,int n){
	if(i>=0 && i<n && j>=0 && j<n && islands[i][j]==1 && vis[i][j]==false){
		return true;
	}
	return false;
}
void dfs(int i,int j,vector<vector<bool>>& vis,int** islands,int n){
	vis[i][j]=1;
	for(int k=0;k<8;k++){
		int nx = i+dx[k];
		int ny= j+dy[k];
		if(possible(ny,nx,vis,islands,n)){
			dfs(nx,ny,vis,islands,n);
		}
	}
}
void solve(){
	ll n;
	cin>>n;
	// vector<int> adj[n];
	// for(int i=0;i<m;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	adj[u].push_back(v);
	// 	adj[v].push_back(u);
	// }
	int islands[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>islands[i][j];
		}
	}
	vector<vector<bool>> vis(n,vector<bool>(n,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(islands[i][j]==1 && vis[i][j]==false){
				count++;
				dfs(i,j,vis,islands,n);
			}
		}
	}
	cout<<count<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}