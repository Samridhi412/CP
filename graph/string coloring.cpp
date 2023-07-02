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
vector<int> color;
void solve(){
	ll n;
	cin>>n;
	color.resize(n,-1);
	string str;
	cin.ignore();
	getline(cin,str);
	for(int i=0;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(str[j]>str[i]){
				if(color[i]==color[j]){
					cout<<"NO";
					return;
				}
				color[i]=!color[j];
			}
		}
		if(color[i]==-1)color[i]=0;
	}
	cout<<"YES"<<endl;
	for(auto &x:color){
		cout<<x;
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}