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
ll ans=-1;
bool possible(ll n,ll m){
	ll count=0;
	ll k=2;
	while(1){
		ll val=k*k*k;
		if(n/val == 0)break;
		count+=n/val;
		k++;
	}
	if(count==m)ans=n;
	return count>=m;
}
void solve(){
	ll m;
	cin>>m;
	ll l=1,r=1e18;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(possible(mid,m)){
			r=mid-1;
		}
		else{
			l=mid+1;
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