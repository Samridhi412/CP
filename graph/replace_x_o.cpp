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
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid){
	vis[i][j]=true;
	for(int k=0;k<4;k++){
			int nx=i+dx[k];
			int ny=j+dy[k];
			if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && vis[nx][ny]==false && grid[nx][ny]=='O'){
				dfs(nx,ny,vis,grid);
			}
	}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<char>> grid(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 || i==n-1){
				if(grid[i][j]=='O' && vis[i][j]==false){
					dfs(i,j,vis,grid);
				}
			}
			if(j==0 || j==m-1){
				if(grid[i][j]=='O' && vis[i][j]==false){
					dfs(i,j,vis,grid);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]=='O' && vis[i][j]==false){
				grid[i][j]='X';
			}
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}