#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void bfs(queue<pair<int,int>>& q,vector<vector<int>>& grid,vector<vector<bool>>& vis){
	int n=grid.size();
	int m=grid[0].size();
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int k=0;k<4;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false && grid[nx][ny]==1){
				q.push({nx,ny});
				vis[nx][ny]=true;
			}
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> grid(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	queue<pair<int,int>> q;
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	for(int i=0;i<m;i++){
		if(grid[0][i]==1){
			q.push({0,i});
			vis[0][i]=true;
		}
		if(grid[n-1][i]==1){
			q.push({n-1,i});
			vis[n-1][i]=true;
		}
	}
	for(int i=0;i<m;i++){
		if(grid[i][0]==1){
			q.push({i,0});
			vis[i][0]=true;
		}
		if(grid[i][m-1]==1){
			q.push({i,m-1});
			vis[i][m-1]=true;
		}
	}
	bfs(q,grid,vis);
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]=false && grid[i][j]==1){
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}