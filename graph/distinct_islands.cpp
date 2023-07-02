#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
unordered_set<vector<pair<int,int>>> unique_islands;
void bfs(int x,int y,int bx,int by,vector<vector<int>>& grid,vector<vector<bool>>& vis){
	queue<pair<int,int>> q;
	vector<pair<int,int>> islands;
	q.push({x,y});
	islands.push_back({x-bx,y-by});
	vis[x][y]=true;
	int n=grid.size();
	int m=grid[0].size();
	while(!q.empty()){
		int i=q.front().first;
		int j=q.front().second;
		for(int k=0;k<4;k++){
			int nx=i+dx[k];
			int ny=j+dy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false && grid[nx][ny]==1){
				q.push({nx,ny});
				islands.push_back{nx-bx,ny-by};
				vis[nx][ny]=true;
			}
		}
	}
	unique_islands.push_back(islands);
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
	unique_islands.clear();
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==1 && vis[i][j]==false){
				bfs(i,j,i,j,grid,vis);
			}
		}
	}
	cout<<unique_islands.size();
	return 0;
}