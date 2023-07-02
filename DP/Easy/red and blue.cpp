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
int red_blue(int ind1,int ind2,int sum,vector<int>& red, vector<int>& blue,int n,int m){
	if(ind1==n && ind2==m)return 0;
	int op1=0, op2=0;
	int maxi=0;
	if(ind1<n){
		maxi=max(maxi,sum+red[ind1]);
		maxi=max(maxi,red_blue(ind1+1,ind2,sum+red[ind1],red,blue,n,m));
	}
	if(ind2<m){
		maxi=max(maxi,sum+blue[ind2]);
		maxi=max(maxi,red_blue(ind1,ind2+1,sum+blue[ind2],red,blue,n,m));
	}
	// maxi = max{maxi,op1,op2};
	// maxi=max(maxi,max(op1,op2));
	return maxi;
}
void solve(){
	int n,m;
	cin>>n;
	vector<int> red(n);
	for(int i=0;i<n;i++){
		cin>>red[i];
	}
	cin>>m;
	vector<int> blue(m);
	for(int i=0;i<m;i++){
		cin>>blue[i];
	}
	int maxi =0;
	const int total= 20010;
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1e9));
	for(int i=n;i>=0;i--){
		for(int j=m;j>=0;j--){
			if(i==n && j==m)continue;
				if(i<n){
					dp[i+1][j]=max(dp[i+1][j],dp[i][j]+red[i]);
				}
				if(j<m){
					dp[i][j+1]=max(dp[i][j+1],dp[i][j]+blue[j]);
				}
				maxi=max(maxi,dp[i][j]);
			}
	}
	cout<<maxi<<endl;
	// cout<<red_blue(0,0,0,red,blue,n,m)<<endl;
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