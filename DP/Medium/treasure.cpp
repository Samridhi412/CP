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
int func(unordered_map<int,int>& pos,int ind,int jump,int maxgem,vector<vector<int>>& dp){
	cout<<ind<<" "<<jump<<" "<<maxgem<<endl;
	if(jump==0 || ind > 30000 || ind>maxgem){
		return 0;
	}
	else if(dp[ind][jump]!=-1)return dp[ind][jump];
	int gems=0;
	if(pos.find(ind)!=pos.end()){
		gems += pos[ind];
	}
	int op1=0,op2=0,op3=0;
	op1=gems+func(pos,ind+jump,jump,maxgem,dp);
	op2=gems+func(pos,ind+jump+1,jump+1,maxgem,dp);
	op3=gems+func(pos,ind+jump-1,jump-1,maxgem,dp);
	return dp[ind][jump] = max(op1,max(op2,op3));
}
void solve(){
	ll n,d;
	cin>>n>>d;
	vector<int> pos(n);
	for(int i=0;i<n;i++){
		cin>>pos[i];
	}
	sort(pos.begin(),pos.end());
	int maxgem = pos[pos.size()-1];
	cout<<maxgem<<endl;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[pos[i]]++;
	}
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	cout<<func(mp,d,d,maxgem,dp);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}