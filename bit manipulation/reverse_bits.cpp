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
	bool flag = false;
	int j=0;
	int rev=0;
	for(int i=31;i>=0;i--){
		int mask = (1<<i);
		if(flag){
			if(n & mask){
			   int smask = (1<<j);
				rev |= smask;
		     }
		     j++;
		}else{
			if(n&mask){
				flag=true;
				int smask = (1<<j);
				rev |= smask;
				j++;
			}
		}
		
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}