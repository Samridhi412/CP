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
	ll n,m;
	cin>>n>>m;
	int animals[n+m];
	for(int i=0;i<n;i++){
		cin>>animals[i+m];
	}
	for(int i=0;i<m;i++){
		cin>>animals[i];
	}
	int b[n+m];
	int lps[n+m];
	int tt=n+m;
	for(int i=0;i<tt-1;i++){
		b[i]=animals[i+1]-animals[i];
	}
	b[m-1]=INT_MAX;
	int ans=0;
	memset(lps,0,sizeof(lps));
	
	for(int i=1;i<n+m;i++){
		int l=lps[i-1];
		while(l>0 && b[i]!=b[l])l=lps[l-1];
		if(b[i]==b[l])l++;
		lps[i]=l;
		if(lps[i]==m-1)ans++;
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