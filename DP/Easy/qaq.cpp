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
ll distinct_subsequences(string& parent, string& child){
	int n=parent.size();
	int m=child.size();
	// vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
	// dp[0][0]=1;
	vector<int> dp(m,0);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		// dp[i][0]=1;
		for(int j=m;j>0;j--){
			if(parent[i-1]==child[j-1]){
				// dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
				dp[j]=dp[j]+dp[j-1];
			}
			else{
				// dp[i][j]=dp[i-1][j];
			}
		}
	}
	// return dp[n][m];
	return dp[m];
}
void solve(){
	string str;
	cin>>str;
	string crying = "QAQ";
	cout<<distinct_subsequences(str, crying);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}