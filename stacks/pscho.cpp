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
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	cout<<vec[0]<<" ";
	for(int i=0;i<n;){
		int j=i+1;
		while(j<n && vec[j]<vec[i]){
			j++;
		}
		if(j<n)cout<<vec[j]<<" ";
		i=j;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}