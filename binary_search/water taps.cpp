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
vector<ll> water;
vector<ll> temp;
ll n;
double ans=-1.0;
bool check(ll amount, ll t){
	ll m=amount;
	ll sumx=0;
	ll sumxt=0;
	for(int i=0;i<n;i++){
		ll present=min(water[i], amount);
		sumx+=present;
		amount-=present;
		sumxt+=present*temp[i];
		if(amount<=0)break;
	}
	double total = sumx==0? 0: (double)sumxt/sumx;
	if(abs(total-(double)t) <= 1e6){
		ans=m;
	}
	return total<=t;
}
void solve(){
	ll t;
	cin>>n>>t;
	temp.resize(n);
	water.resize(n);
	for(int i=0;i<n;i++){
		cin>>water[i];
	}
	for(int i=0;i<n;i++){
		cin>>temp[i];
	}
	ll l=0,r=1e12;
	while(l<=r){
		double mid=(l+r)>>1;
		if(check(mid,t)){
			l=mid+1;
		}
		else{
			r=mid-1;
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