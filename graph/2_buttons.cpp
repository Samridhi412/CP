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
	queue<pair<ll,ll>> q;
	q.push({0,n});
	set<ll> st;
	st.insert(n);
	int lvl=-1;
	while(!q.empty()){
		ll dist=q.front().first;
		ll node=q.front().second;
		q.pop();
		if(node<0){
			continue;
		}
		if(node==m){
			lvl=dist;
			break;
		}
		ll a1=node*2;
		ll a2=node-1;
		if(st.count(a1)==0){
			q.push({dist+1,a1});
			st.insert(a1);
		}
		if(st.count(a2)==0){
			q.push({dist+1,a2});
			st.insert(a2);
		}
		
	}
	cout<<lvl<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}