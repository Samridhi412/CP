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
int findSubstr(int lps[],int longestlen, int n){
	int count=0;
	for(int i=1;i<n;i++){
		int start = (i-lps[i])/2;
		int end=start+lps[i]-1;
		int len=end-start+1;
		if(len==longestlen)count++;
	}
	return count;
}
void manacher(string& s){
	int n=s.size();
	n=2*n+1;
	int lps[n];
	memset(lps,0,sizeof(lps));
	lps[0]=0;
	lps[1]=1;
	int start=0;
	int end=0;
	int lonpallen=1;
	int totalpal=0;
	int imirror=-1;
	int fs=0;
	int fe=0;
	int c=1;
	int r=2;
	for(int i=2;i<n;i++){
		if(i<r){
			imirror = 2*c - i;
			lps[i]=min(lps[imirror],r-i);
		}
		while((i+lps[i])<n && (i-lps[i])>=0 && 
			(((i+lps[i]+1)%2==0) || (s[(i+lps[i]+1) / 2]==s[(i-lps[i]-1) / 2]))){
			lps[i]++;
	}
	if(i+lps[i] > r){
		c=i;
		r=i+lps[i];
	}
	int start=(i-lps[i])/2;
	int end=start+lps[i]-1;
	int len=end-start+1;
	if(len>lonpallen){
		lonpallen=len;
		fs=start;
		fe=end;
	}
  }
	cout<<lonpallen<<" ";
	cout<<findSubstr(lps,lonpallen,n)<<endl;
}
void solve(){
	string str;
	cin>>str;
	manacher(str);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test;
	cin>>test;
	for(int i=0;i<test;i++){
		solve();
	}
	return 0;
}