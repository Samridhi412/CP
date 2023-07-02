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
void dfs2(int node,vector<bool>& vis, vector<int> adj[],vector<vector<int>>& res,vector<int>& temp){
	vis[node]=true;
	temp.push_back(node);
	for(auto &y:adj[node]){
		if(vis[y]==false){
			dfs2(y,vis,adj,res,temp);
		}
	}
}
void dfs1(int node,vector<bool>& vis,stack<int>& st,vector<int>& adj[]){
	vis[node]=1;
	for(auto &x:adj[node]){
		if(vis[x]==false){
			dfs1(x,vis,st,adj);
		}
	}
	st.push(node);
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		adj[u].push_back(v);
	}
	stack<int> finish_time;
	vector<bool> vis(n,false);
	for(int i=0;i<n;i++){
		if(vis[i]==false){
	   dfs1(0,vis,finish_time,adj);
		}
    }
    vector<int> transpose[n];
    for(int i=0;i<n;i++){
    	vis[i]=false;
    	for(auto &y:adj[i]){
    		transpose[y].push_back(i);
    	}
    }
    vector<vector<int>> res;
    while(!finish_time.empty()){
    	int top = finish_time.top();
    	finish_time.pop();
    	if(vis[top]==false){
    		vector<int> temp;
    		dfs2(top,vis,transpose,res,temp);
    		res.push_back(temp);
    	}
    }
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}