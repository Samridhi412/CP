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
	string s,t;
	cin>>s>>t;
	int cnt[2]={0};
	int n=s.size();
	int m=t.size();
	for(int i=0;i<n;i++){
		cnt[s[i]-48]++;
	}
	int lps[m];
	memset(lps,0,sizeof(lps));
	for(int i=1;i<m;i++){
		int l=lps[i-1];
		while(l>0 && t[l]!=t[i])l=lps[l-1];
		if(t[l]==t[i])l++;
		lps[i]=l;
	}
	for(int i=0,j=0;i<n;i++){
		char ch = (cnt[t[j]-48]!=0) ? t[j] : t[j]^1;
		cnt[ch-48]--;
		cout<<ch;
		j++;
		if(j==m){
			j=lps[j-1];
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