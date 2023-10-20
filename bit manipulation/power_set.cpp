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
	string str;
	int n=str.size();
	for(int i=0;i<(1<<n);i++){
		string res;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				int index = n-1-j;
				res.push_back(str[index]);
			}
		}
		cout<<res<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}