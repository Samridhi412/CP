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
	ll n,m,x;
	cin>>n>>m>>x;
	vector<int> heights(n);
	set<pair<int,int>> st;
	for(int i=0;i<m;i++){
		st.insert({0,i+1});
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		pair<int,int> t=*st.begin();
		cout<<t.second<<" ";
		st.erase(t);
		st.insert({t.first+x,t.second});
		
	}
	cout<<endl;
	
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