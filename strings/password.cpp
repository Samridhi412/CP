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
#define pb push_back
#define endl "\n"
const int N=1e6+10;
ll lps[N];
map<ll,bool> mp;
void kmp(string& s){
	int n=s.size();
	for(int i=1;i<n;i++){
		ll l=lps[i-1];
		while(l>0 && s[i]!=s[l]){
			l=lps[l-1];
		}
		if(s[i]==s[l]){
			l++;
		}
		lps[i]=l;
		if(i!=n-1)mp[lps[i]]++;
	}
}
void solve(){
	string str;
	cin>>str;
	kmp(str);
	int n=str.size();
	int len=lps[n-1];
	while(len>0){
		if(mp.find(len)!=mp.end()){
			for(int k=0;k<len;k++){
				cout<<str[k];
			}
			return;
		}
		len=lps[len-1];
	}
	cout<<"Just a legend"<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}