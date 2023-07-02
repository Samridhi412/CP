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
	ll n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int i=0,j=0;
	int sum=0;
	int start_index=-1;
	int min_sum = 1e9;
	while(j<n){
		sum+=arr[j];
		if(j-i+1 < k){
			j++;
		}
		else if(j-i+1 == k){
			if(sum<min_sum){
				start_index=i;
				min_sum=sum;
			}
			sum-=arr[i];
			i++;
			j++;
		}
	}
	// cout<<min_sum<<endl;
	cout<<start_index+1;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}