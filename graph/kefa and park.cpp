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
int count_restaurants(int node, vector<int> adj[], vector<int>& cats,int m, vector<bool>& vis){
	queue<pair<int,int>> q;
	int res=0;
	q.push({node,cats[node]});
	vis[node]=true;
	while(!q.empty()){
		int top=q.front().first;
		int cat_count = q.front().second;
		q.pop();
		if(cat_count > m){
			continue;
		}
		bool flag=0;
		for(auto &x:adj[top]){
			if(vis[x]==false){
				flag=1;
			if(cats[x]==1){
				q.push({x,cat_count+1});
			}else{
			q.push({x,0});
	        }
	        vis[x]=true;
	    }
		}
		if(flag==0)res++;
	}
	return res;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<int> cats(n+1);
	for(int i=1;i<=n;i++){
		cin>>cats[i];
	}
	vector<int> adj[n+1];
	vector<bool> vis(n+1,false);
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout<<count_restaurants(1,adj,cats,m,vis);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}