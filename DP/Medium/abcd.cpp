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
unordered_map<string,int> words;
bool func(int ind,string& ans,int n,string& s,string& res,unordered_map<pair<int,string>,bool>& dp){
	if(ind==n){
		if(ans=="" || words[ans]!=0){
			res+=ans;
			return true;
		}
		return false;
	}
	else if(dp.find({ind,ans})!=dp.end())return dp[{ind,ans}];
	ans=s[ind]+ans;
	bool op1=false,op2=false;
	if(words[ans]!=0){
		string res1=res;
		string temp="";
		res= res + ans + " ";
		words[ans]--;
		op1= func(ind+1,temp,n,s,res,dp);
		if(op1)return true;
		words[ans]++;
		res=res1;
	}
	op2= func(ind+1,ans,n,s,res,dp);
	return dp[{ind,ans}] = op1 || op2;
}
void solve(){
	ll n,m;
	cin>>n;
	string str;
	cin.ignore();
	getline(cin,str);
	cin>>m;
	words.clear();
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		words[s]++;
	}
	string ans;
	string res;
	// unordered_map<pair<int,string>,bool> dp;
	// bool result = func(0,ans,n,str,res,dp);
	// if(result){
	// 	cout<<res;
	// }
	
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}