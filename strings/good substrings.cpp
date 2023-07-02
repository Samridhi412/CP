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
	string str, check;
	getline(cin,str);
	getline(cin,check);
	ll k;
	cin>>k;
	int n=str.size();
	set<pair<int,int>> st;
	for(int i=0;i<n;i++){
		int bad = 0;
		int hash1, hash2 = 0;
		int pow1 = 1, pow2 = 1;
		int p1=31, p2=29;
		for(int j=i;j<n;j++){
			bad += (check[str[j]-'a'] == '0' ? 1 : 0);
			if(bad <= k){
				hash1 = (hash1 + (str[j] - 'a' + 1)*p1)%mod;
				hash2 = (hash2 + (str[j] - 'a' + 1)*p2)%mod;
				cout<<hash1<<" "<<hash2<<endl;
				// pow1 = (pow1*p1)%mod;
				// pow2 = (pow2*p2)%mod;
				st.insert({hash1,hash2});
			}
			else{
				break;
			}		
		}
	}
	cout<<st.size();
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}