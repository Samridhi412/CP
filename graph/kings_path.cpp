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
#define pb push_back
#define endl "\n"
map<pair<int,int>,int> mp;
map<pair<int,int>,int> ans;
void bfs(int xi,int yi,int fx,int fy){
	queue<pair<int,int>> q;
	q.push({xi,yi});
	ans[{xi,yi}]=0;
	mp[{xi,yi}]=1;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int nx=-1;nx<=1;nx++){
			for(int ny=-1;ny<=1;ny++){
				int sx=x+nx;
				int sy=y+ny;
				if(mp[{sx,sy}]==2){
					q.push({sx,sy});
					mp[{sx,sy}]=1;
					ans[{sx,sy}]=ans[{x,y}]+1;
				}
			}
		}
	}
}
void solve(){
	int x0,y0,x1,y1;
	cin>>x0>>y0>>x1>>y1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int r,a,b;
		cin>>r>>a>>b;
		for(int j=a;j<=b;j++){
			mp[{r,j}]=2;
		}
		
	}
	bfs(x0,y0,x1,y1);
	if(ans.find({x1,y1})!=ans.end()){
		cout<<ans[{x1,y1}];
	}
	else{
		cout<<"-1"<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}