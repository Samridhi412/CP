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
ll nb,nc,ns,cb,cs,cc,rb,rc,rs,rubles;
bool possible(ll n){
	ll b=max(0ll,n*cb-nb);
	ll c=max(0ll,n*cc-nc);
	ll s=max(0ll,n*cs-ns);
	ll fx = rb*b + rc*c + rs*s;
	return fx<=rubles;
}
void solve(){
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='B'){
			cb++;
		}
		else if(str[i]=='C'){
			cc++;
		}
		else{
			cs++;
		}
	}
	cin>>nb>>ns>>nc;
	cin>>rb>>rs>>rc;
	cin>>rubles;
	ll l=1, r=1e12+110;
	ll ans=0;
	while(l<=r){
		ll mid = (l+r) >> 1;
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