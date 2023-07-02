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
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	vector<int> dp(n+1,-1e9);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int op1=-1e9, op2=-1e9, op3=-1e9;
		if(i>=a){
			op1 = dp[i-a];
		}
		if(i>=b){
			op2 =dp[i-b];
		}
		if(i>=c){
			op3 =dp[i-c];
		}
		dp[i]= 1+max(op1,max(op2,op3));
	}
	cout<<dp[n];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}