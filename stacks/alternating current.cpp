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
	string str;
	cin>>str;
	stack<char> st;
	for(int i=0;i<str.size();i++){
		if(st.empty() || str[i]!=st.top())st.push(str[i]);
		else st.pop();
	}
	string res = st.empty()? "Yes": "No";
	cout<<res<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}