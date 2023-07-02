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
	vector<ll> cream(n);
	for(int i=0;i<n;i++){
		cin>>cream[i];
	}
	vector<int> result(n,1);
	stack<ll> st;
	for(int i=0;i<n;i++){
		if(cream[i]==0)st.push(i);
		else{
			ll j= cream[i]-1;
			while(!st.empty() && st.top()>=i-j){
				st.pop();
			}
		}
	}
	while(!st.empty()){
		result[st.top()]=0;
		st.pop();
	}
	// unordered_set<ll> st;
	// for(int i=1;i<=n;i++){
	// 	ll layer_till_now=i;
	// 	if(cream[i-1]==0){
	// 		st.insert(i);
	// 	}
	// 	else if(cream[i-1]>=layer_till_now){
	// 		st.clear();
	// 	}else{
	// 		for(int j=i-1;j>0&&(i-j)<cream[i-1];j--){
	// 			if(st.count(j))st.erase(j);
	// 		}
	// 	}
	// }
	
	// for(int i=0;i<n;i++){
	// 	if(st.count(i+1)){
	// 		result[i]=0;
	// 	}
	// }
	for(auto &x:result){
		cout<<x<<" ";
	}
	cout<<endl;
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