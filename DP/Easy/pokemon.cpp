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
int max_strength(int ind,int n,vector<int>& v,int flag){
	if(ind==n){
		return 0;
	}
	int take=-1e9;
	if(flag){
		take = v[ind]+max_strength(ind+1,n,v,1-flag);
	}
	else{
		take = -v[ind]+max_strength(ind+1,n,v,1-flag);
	}
	int nontake = max_strength(ind+1,n,v,flag);
	return max(take,nontake);
}
void solve(){
	ll n,q;
	cin>>n>>q;
	vector<ll> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<pair<int,int>> queries(q);
	for(int i=0;i<q;i++){
		cin>>queries[i].first;
		cin>>queries[i].second;
	}
	// cout<<max_strength(0,n,vect,1)<<endl;
	vector<vector<ll>> dp(n+1,vector<ll>(2,-1e9));
	dp[n][0] = 0;
	dp[n][1] = 0;
	for(int i=n-1;i>=0;i--){
		for(int flag=0;flag<2;flag++){
			ll take=-1e9;
			if(flag){
				take = v[i]+dp[i+1][1-flag];
			}
			else{
				take = -v[i]+dp[i+1][1-flag];
			}
			ll nontake = dp[i+1][flag];
			dp[i][flag] = max(take,nontake);
			
		}
	}
	cout<<dp[0][1]<<endl;
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