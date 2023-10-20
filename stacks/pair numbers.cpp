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
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int t=0;
	int l,r;
	int maxlen=0;
	int c=0;
	vector<int> res(n);
	while(t<n){
		l=r=t;
		while(l&&arr[l-1]%arr[t]==0)l--;
		while(r<n-1&&arr[r+1]%arr[t]==0)r++;
		t=r+1;
		r-=l;
		if(r>maxlen){
		maxlen=r;
		c=0;
		}
		if(maxlen==r){
			res[c++]=l+1;
		}
	}
	cout<<c<<" "<<maxlen<<endl;
	for(int i=0;i<c;i++){
		cout<<res[i]<<" ";
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}