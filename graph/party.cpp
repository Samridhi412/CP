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
int bfs(int node,vector<int> adj[]){
	queue<pair<int,int>> q;
	q.push({node,1});
	int maxlvl=1;
	while(!q.empty()){
		int topnode=q.front().first;
		int lvl=q.front().second;
		maxlvl=max(maxlvl,lvl);
		q.pop();
		for(auto &x:adj[topnode]){
			q.push({x,lvl+1});
		}
	}
	return maxlvl;
}
void solve(){
	ll n;
	cin>>n;
	vector<int> vis(n,0);
	vector<int> adj[n];
	for(int i=0;i<n;i++){
		int node;
		cin>>node;
		if(node!=-1){
			adj[node-1].push_back(i);
		}else{
			vis[i]=-1;
		}
	}
	
	int result=1;
	for(int i=0;i<n;i++){
		if(vis[i]==-1){
			result = max(result,bfs(i,adj));
		}
	}
	cout<<result<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}