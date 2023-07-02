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
vector<ll> attacks;
bool possible(ll k,ll h){
	ll hits=k;
	ll n=attacks.size();
	for(int i=0;i<n-1;i++){
		hits += min(k,attacks[i+1]-attacks[i]);
	}
	return hits>=h;
}
void solve(){
	ll n,h;
	cin>>n>>h;
	ll ans=-1;
	attacks.resize(n);
	for(int i=0;i<n;i++){
		cin>>attacks[i];
	}
	ll l=1, r=1e18;
	while(l<=r){
		    ll m = (l + r) >> 1;
		if(possible(m,h)){
			r=m-1;
			ans=m;
		}
		else{
			l=m+1;
		}
	}
	cout<<ans<<endl;
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



// #include <bits/stdc++.h>

// using namespace std;

// using li = long long;

// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     int n;
//     li h;
//     cin >> n >> h;
//     vector<li> a(n);
//     for (li &x : a) cin >> x;
//     li l = 1, r = 1e18;
//     while (l <= r) {
      // li m = (l + r) / 2;
      // li sum = m;
      // for (int i = 0; i < n - 1; ++i) 
      //   sum += min(m, a[i + 1] - a[i]);
      // if (sum < h) l = m + 1;
      // else r = m - 1;
//     }
//     cout << r + 1 << '\n';
//   }
// }