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
string epalin(string& s){
	int n=s.size();
	string original = s;
	reverse(s.begin(),s.end());
	string temp = s + '#' + original;
	int N=temp.size();
	int lps[N];
	memset(lps,0,sizeof(lps));
	for(int i=1;i<n;i++){
		int l=lps[i-1];
		while(l>0 && temp[i]!=temp[l]){
			l=lps[l-1];
		}
		if(temp[i]==temp[l])l++;
		lps[i]=l;
	}
	int prev=0;
	for(int i=n+1;i<N;i++){
		int l=prev;
		while(l>0 && temp[i]!=temp[l]){
			l=lps[l-1];
		}
		if(temp[l]==temp[i])l++;
		prev=l;
	}
	int required=n-prev;
	string rev=original.substr(0,required);
	reverse(rev.begin(),rev.end());
	return original + rev;
}
void solve(){
	vector<string> inputs;
	string input;
	while (getline(cin, input) && !input.empty()) {
        inputs.push_back(input);
    }
    for(int i=0;i<inputs.size();i++){
    	cout<<epalin(inputs[i])<<endl;
    }
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}