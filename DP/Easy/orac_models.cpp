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
int func(int ind,int n,vector<ll>& models,int prev,vector<vector<ll>>& dp){
	if(ind == n){
		return 0;
	}
	else if(dp[ind][prev]!=-1)return dp[ind][prev];
	ll take=0, nontake=0;
	if(prev==n || (models[ind] > models[prev] && models[ind]%models[prev] == 0)){
		take = 1+func(ind+1,n,models,ind,dp);
	}
	nontake=func(ind+1,n,models,prev,dp);
	return dp[ind][prev]=max(take,nontake);
}
void solve(){
	ll n;
	cin>>n;
	vector<ll> models(n);
	for(int i=0;i<n;i++){
		cin>>models[i];
	}
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
	cout<<func(0,n,models,n,dp)<<endl;
	
	// for(int i=n-1;i>=0;i--){
	// 	for(int prev=0;prev<=n;prev++){
	// 		ll take=0, nontake=0;
	// 		if(prev==n || (models[i] > models[prev] && models[i]%models[prev] == 0)){
	// 			take = 1+dp[i+1][i];
	// 		}
	// 		nontake=dp[i+1][prev];
	// 		dp[i][prev]= max(take,nontake);
	// 	}
	// }
	// cout<<dp[0][n]<<endl;
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


