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
ll n,k;
vector<ll> req, has;
bool possible(ll mid){
	ll powder=k;
	for(int i=0;i<n;i++){
		if(mid*req[i]<=has[i]){
			continue;
		}
		powder -= mid*req[i] - has[i];
		if(powder < 0)return false;
	}
	return true;
}
void solve(){
	cin>>n>>k;
	req.resize(n);
	has.resize(n);
	for(int i=0;i<n;i++){
		cin>>req[i];
	}
	for(int i=0;i<n;i++){
		cin>>has[i];
	}
	ll l=0,r=1e10;
	ll ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(possible(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}