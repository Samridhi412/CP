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
	vector<int> arr;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int xorr=0;
	for(int i=0;i<n;i++){
		xorr^=arr[i];
	}
	int x=0, y=0;
	int rmst = xorr & -xorr;
	for(int i=0;i<n;i++){
		int bt=arr[i] & rmst;
			if(bt){
				y^=arr[i];
			}else{
				x^=arr[i];
		}
	}
	cout<<x<<" "<<y<<endl;
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}