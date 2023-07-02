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
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<int>> grid(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	int oranges=0;
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==2){
				oranges+=1;
				q.push({i,j});
			}
			else if(grid[i][j]==1){
				oranges+=1;
			}
		}
	}
	int count=0;
	int time=0;
	while(!q.empty()){
		int size=q.size();
		count+=size;
		while(size--){
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
				grid[nx][ny]=2;
				q.push({nx,ny});
			}
		}
		
		}
		if(q.size())time++;
	}
	if(count==oranges)return time;
	else return -1;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}