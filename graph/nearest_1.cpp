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
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<int>> grid(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	queue<pair<int,pair<int,int>>> q;
	bool vis[n][m];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==1){
				q.push({i,{j,0}});
				vis[i][j]=true;			}
			
		}
	}
	vector<vector<int>> res(n,vector<int>(m));
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second.first;
		int d=q.front().second.second;
		res[x][y]=d;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0 && vis[nx][ny]==false){
				vis[nx][ny]=true;
				q.push({nx,{ny,d+1}});
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