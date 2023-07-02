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
const int N=1e3+10;
const int M=1e3+10;
ll lps[N+M];
void kmp(string& s,string& t){
	string temp = t + '#' + s;
	int size=temp.size();
	ll l=0,r=0;
	for(int i=1;i<size;i++){
		if(i<=r){
			lps[i]=min(r-i+1,lps[i-l]);
		}
		while(temp[lps[i]]==temp[i+lps[i]]){
			lps[i]++;
		}
		if(i>r){
			l=i;
			r=i+lps[i]-1;
		}
	}
}
void solve(){
	ll n,m,q;
	cin>>n>>m>>q;
	string s,t;
	cin>>s>>t;
	memset(lps,0,sizeof(lps));
	kmp(s,t);
	int tsz=t.size();
	int tt=tsz+1+s.size();
	for(int i=0;i<q;i++){
		ll l,r;
		cin>>l>>r;
		int cnt=0;
		for(int i=l;i<=r;i++){
			if(lps[i+tsz]==tsz){
				if(i+tsz-1 <= r)cnt++;
				else break;
			}
		}
		cout<<cnt<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}