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
ll ans;
bool check(ll mid,ll k){
	for(int i=0;i<n;i++){
		
   }
}
void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll l=1, r=n*m;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid,k)){
			l=mid-1;
		}
		else{
			r=mid+1;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}