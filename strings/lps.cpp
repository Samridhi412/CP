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
void manacher(string& s){
	int l=0,r=0;
	int maxi=0;
	int n=s.size();
	int lps[n];
	memset(lps,0,sizeof(lps));
	for(int i=0;i<n;i++){
		if(i<=r){
			int idash = r-i+l;
			lps[i]=min(r-i,lps[idash]);
		}
		while(i-lps[i]-1 >=0 && i+lps[i]+1 < n && s[i-lps[i]-1]==s[i+lps[i]+1]){
			lps[i]++;
		}
		if(s[i-lps[i]-1]!=s[i+lps[i]+1])lps[i]--;
		if(i+lps[i] > r){
			l=i-lps[i];
			r=i+lps[i];
		}
		maxi=max(maxi,2*lps[i]+1);
	}
	cout<<maxi<<endl;
}
void solve(){
	ll n;
	cin>>n;
	string str;
	cin>>str;
	manacher(str);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}