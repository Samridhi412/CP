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
pair<bool,int> cancontain(pair<int,string> juice, int vitamins){
	int juicemask=0;
	bool flag =0;
	for(auto &x:juice.second){
		int mask = 0, mask2 =0;
		if(x=='A'){
			mask ^= (1<<2);
			juicemask |= mask;
			mask2 = vitamins & mask;
			if (mask ^ mask2)flag=1;
		}else if(x == 'B'){
			mask ^= (1<<1);
			juicemask |= mask;
			mask2 = vitamins & mask;
			if (mask ^ mask2)flag=1;
		}else{
			mask ^= 1;
			juicemask |= mask;
			mask2 = vitamins & mask;
			if (mask ^ mask2)flag=1;
		}
	}
	if(flag)return {true,juicemask};
    return {false,juicemask};
	
}
int price(int vitamins, int ind, vector<pair<int,string>>& juices){
	if(ind==0){
		if(vitamins==7)return 0;
		else return -1;
	}
	int op1=0,op2=0;
	pair<bool,int> res=cancontain(juices[ind], vitamins);
	if(res.first){
		int vitamin = vitamins | res.second;
		op1= juices[ind].first + price(vitamin, ind-1, juices);
	}
	op2=price(vitamins, ind-1, juices);
	return min(op1,op2);
}
void solve(){
	ll n;
	cin>>n;
	vector<pair<int,string>> juices(n);
	for(int i=0;i<n;i++){
		cin>>juices[i].first;
		cin>>juices[i].second;
	}
	vector<vector<int>> dp(n+1,vector<int>(8,1e9));
	for(int i=0;i<n;i++){
		dp[i][7]=0;
	}
	// int count=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<7;j++){
			int op1=1e9,op2=1e9;
			pair<bool,int> res=cancontain(juices[i-1], j);
			// cout<<res.first<<" "<<res.second<<" "<<count<<endl;
			if(res.first){
				int vitamin = j | res.second;
				op1= juices[i-1].first + dp[i-1][vitamin];
			}
			op2=dp[i-1][j];
			dp[i][j]= min(op1,op2);
			// count++;
		}
	}
	int ans = dp[n][0]==1e9?-1:dp[n][0];
	cout<<ans;
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}