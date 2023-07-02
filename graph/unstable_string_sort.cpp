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
string res;
void dfs(ll node,vector<ll> graph[],vector<bool>& v,char ch){
	res+=ch;
	v[node]=true;
	for(auto &x:graph[node]){
		if(!v[x]){
			dfs(x,graph,v,ch);
		}
	}
}
void dfs1(stack<ll>& st,ll node,vector<bool>& visited,vector<ll> adj[]){
	visited[node]=true;
	for(auto &x:adj[node]){
		if(visited[x]==false){
			dfs1(st,x,visited,adj);
		}
	}
	st.push(node);
}
void scc(vector<ll> adj[],ll n,ll k){
	vector<bool> visited(n+1,false);
	stack<ll> finish_time;
	for(ll i=1;i<=n;i++){
		if(!visited[i]){
			dfs1(finish_time,i,visited,adj);
		}
	}
	vector<ll> reverse[n+1];
	for(int i=1;i<=n;i++){
		for(auto &y:adj[i]){
			reverse[y].push_back(i);
		}
	}
	for(ll i=1;i<=n;i++){
		visited[i]=false;
	}
	ll count=0;
	char ch='#';
	while(!finish_time.empty()){
		ll element=finish_time.top();
		finish_time.pop();
		if(!visited[element]){
			count++;
			if(ch=='#'){
				ch='a';
			}else if(ch!='z'){
			    ch++;
		    }
			dfs(element,reverse,visited,ch);
		}
	}
	if(count<k){
		cout<<"NO";
		return;
	}
	cout<<"YES"<<endl;
	cout<<res;
	
}
void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll> p,q;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		p.push_back(x);
	}
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		q.push_back(x);
	}
	vector<ll> adj[n+1];
	for(ll i=0;i<n-1;i++){
		adj[p[i]].push_back(p[i+1]);
		adj[q[i]].push_back(q[i+1]);
	}
	scc(adj,n,k);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}