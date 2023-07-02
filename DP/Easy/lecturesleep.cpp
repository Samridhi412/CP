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
	int n,k;
	cin>>n>>k;
	vector<int> theorms(n), sleep(n);
	for(int i=0;i<n;i++){
		cin>>theorms[i];
	}
	for(int i=0;i<n;i++){
		cin>>sleep[i];
	}
	int i=0,j=0,sum=0;
	int maxi=0;
	while(j<n){
		if(sleep[j]==0){
			sum+=theorms[j];
		}
		if(j-i+1 < k){
			j++;
		}
		else if(j-i+1 == k){
			maxi=max(maxi,sum);
			if(sleep[i]==0){
				sum-=theorms[i];
			}
			i++;
			j++;
		}
	}
	for(int i=0;i<n;i++){
		if(sleep[i]==1){
			maxi+=theorms[i];
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