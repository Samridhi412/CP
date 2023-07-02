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
	ll n;
	cin>>n;
	string str;
	cin.ignore();
	getline(cin,str);
	unordered_map<int,char> mp;
	mp[1]=str[0];
	vector<int> ans;
	ans.push_back(1);
	for(int i=1;i<n;i++){
		int color=-1;
		char replace='a';
		for(auto &x:mp){
			int k=x.first;
			char ch=x.second;
			if(str[i]>=ch){
				if(replace<=ch){
					replace=ch;
					color=k;
				}
			}
		}
		if(color==-1){
			int k=mp.size()+1;
			mp[k]=str[i];
			ans.push_back(k);
		}else{
			mp[color]=str[i];
			ans.push_back(color);
		}
	}
	cout<<mp.size()<<endl;
	for(auto &x:ans){
		cout<<x<<" ";
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}