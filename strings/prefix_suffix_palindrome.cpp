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
string lpp(string t){
	int size=t.size();
	string temp = t + '#';
	string rev=t;
	reverse(rev.begin(),rev.end());
	temp += rev;
	int sz=temp.size();
	ll lps[size];
	memset(lps,0,sizeof(lps));
	for(int i=1;i<size;i++){
		ll l = lps[i-1];
		while(l>0 && temp[l]!=temp[i]){
			l=lps[l-1];
		}
		if(temp[l]==temp[i]){
			l++;
		}
		lps[i]=l;
	}
	ll prev=0;
	for(int i=size+1;i<sz;i++){
		ll l=prev;
		while(l>0 && temp[l]!=temp[i]){
			l=lps[l-1];
		}		
		if(temp[l]==temp[i]){
			l++;
		}
		prev=l;
	}
	return t.substr(0,prev);
	
}
void solve(){
	string str;
	// cin.ignore();
	cin>>str;
	int n=str.size();
	int i=0,j=n-1;
	while(i<=j && str[i]==str[j]){
		i++;
		j--;
	}
	if(j<i){
		cout<<str<<endl;
		return;
	}
	string m=str.substr(i,j-i+1);
	string r=m;
	reverse(r.begin(),r.end());
	string x=lpp(m);
	string y=lpp(r);
	m=x;
	if(y.size() > x.size())m=y;
	string result="";
	for(int k=0;k<i;k++){
		result += str[k];
	}
	result += m;
	for(int k=j+1;k<n;k++){
		result += str[k];
	}
	cout<<result<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}