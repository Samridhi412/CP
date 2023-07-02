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
	ll n;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll max_len = 1;
	vector<ll> dp(n,1);
	for(int i=1;i<n;i++){
		if(arr[i]>arr[i-1]){
			dp[i]=dp[i-1]+1;
		}
		max_len=max(max_len,dp[i]);
	}
	cout<<max_len;
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}