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
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<pair<int,int>> undirected_edges;
	vector<int> adj[n+1];
	unordered_map<int,int> indeg;
	for(int i=0;i<m;i++){
		int t,u,v;
		cin>>t>>u>>v;
		if(indeg.find(u)==indeg.end()){
			indeg[u]=0;
		}
		if(indeg.find(v)==indeg.end()){
			indeg[v]=0;
		}
		if(t==1){
			adj[u].push_back(v);
			indeg[v]++;
		}
		else{
			undirected_edges.push_back({u,v});
		}
	}
	queue<int> q;
	for(auto &y:indeg){
		if(y.second==0){
			q.push(y.first);
		}
	}
	int cnt=0;
	unordered_map<int,int> ans;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		cnt++;
		ans[node]=cnt;
		for(auto &ele:adj[node]){
			indeg[ele]--;
			if(indeg[ele]==0){
				q.push(ele);
			}
		}
	}
	if(cnt!=indeg.size()){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++){
		if(adj[i].size()!=0){
			for(auto &y:adj[i]){
				cout<<i<<" "<<y<<endl;
			}
		}
	}
	for(auto &y:undirected_edges){
		int a1=ans[y.first];
		int a2=ans[y.second];
		if(a1>a2){
			cout<<y.second<<" "<<y.first<<endl;
		}
		else if(a1<a2){
			cout<<y.first<<" "<<y.second<<endl;
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