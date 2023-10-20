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
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long total = n*(n+1)/2;
	long long totalsq = n*(n+1)*(2*n+1)/6;
	for(int i=0;i<n;i++){
		total -= arr[i];
		totalsq -= arr[i]*arr[i];
	}
	long long totalsum = totalsq/total;
	int missing = (total+totalsum)/2;
	int repeating = totalsum-missing;
	cout<<missing<<" "<<repeating<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}