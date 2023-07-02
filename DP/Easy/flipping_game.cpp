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
	vector<int> num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int total_ones = accumulate(num.begin(), num.end(), 0);
	if(total_ones == n){
		cout<< total_ones-1 <<endl;
		return;
	}
	// cout<< total_ones;
	int i=-1,j=0;
	int maxi = total_ones;
	int count1s =total_ones;
	while(j<n){
		if(num[j]==0){
			count1s += 1;
			if(i==-1){
				i=j;
			}
			maxi=max(maxi,count1s);
			j++;
		}
		else if(num[j]==1){
			if(i==-1){
				j++;
				continue;
			}
			count1s -= 1;
			if(count1s < total_ones){
				i=-1;
				count1s = total_ones;
				
			}
			j++;
		}
	}
	cout<<maxi<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}