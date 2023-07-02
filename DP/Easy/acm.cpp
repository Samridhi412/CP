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
int funct(int n, int prev, int k){
	if(k==0)return 1;
	if(n==0){
		return 0;
	}
	ll take = 0;
	if(prev==0 || prev%n == 0){
		take = funct(n,n,k-1);
	}
	ll nontake = funct(n-1, prev, k);
	return (nontake + take)%mod;
}
void solve(){
	ll n,k;
	cin>>n>>k;
	cout<< funct(n,0,k)<<endl;
	vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(k+1,0)));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j][0] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=0;j--){
			for(int l=1;l<=k;l++){
				ll take = 0;
				if(j==0 || j%i == 0){
					take = dp[i][i][l-1];
				}
				ll nontake = dp[i-1][j][l];
				dp[i][j][l] = (nontake + take)%mod;
			}
		}
	}
	cout<<dp[n][0][k];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}