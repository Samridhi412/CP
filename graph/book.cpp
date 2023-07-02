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
int books(vector<int> adj[],int n,vector<int>& indeg){
	int mxlevel=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			pq.push({1,i});
		}
	}
	while(!pq.empty()){
		int node = pq.top().second;
		int level = pq.top().first;
		mxlevel=max(mxlevel,level);
		pq.pop();
		for(auto &y:adj[node]){
			indeg[y]--;
			if(indeg[y]==0){
				if(y>node){
					pq.push({level,y});
				}else{
					pq.push({level+1,y});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(indeg[i]!=0){
			return -1;
		}
	}	
	return mxlevel;
	
}
void solve(){
	ll n;
	cin>>n;
	vector<int> adj[n+1];
	vector<int> indeg(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int val;
			cin>>val;
			indeg[i]++;
			adj[val].push_back(i);
		}
	}
	cout<<books(adj,n,indeg)<<endl;
	// cout<<result<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;n
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}