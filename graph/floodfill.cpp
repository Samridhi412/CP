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
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int i,int j,int old,int newcolor,vector<vector<bool>>& vis,vector<vector<int>>& grid){
	vis[i][j]=true;
	for(int i=0;i<4;i++){
		int nx=i+dx[k];
		int ny=j+dy[k];
		if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==old && vis[nx][ny]==0){
			grid[nx][ny]=newcolor;
			vis[nx][ny]=1;
			dfs(nx,ny,old,newcolor,vis,grid);
		}
	}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<int>> grid(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	int sr,sc,newcolor;
	cin>>sr>>sc>>newcolor;
	vector<vector<bool>> vis(n,vector<bool>(m,0));
	int oldcolor=grid[sr][sc];
	dfs(sr,sc,oldcolor,newcolor,vis,grid);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}