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
bool func(int ind,string& ans,int n,string& s,string& res){
	if(ind==n){
		if(ans=="" || words[ans]!=0){
			res+=ans;
			return true;
		}
		return false;
	}
	ans=s[ind]+ans;
	cout<<ans<<endl;
	bool op1=false,op2=false;
	if(words[ans]!=0){
		string res1=res;
		string temp="";
		res+=ans + " ";
		words[ans]--;
		cout<<res<<" "<<ans<<endl;
		op1= func(ind+1,temp,n,s,res);
		words[ans]++;
		res=res1;
	}
	op2= func(ind+1,ans,n,s,res);
	return op1 || op2;
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
		words[s]++;
	}
	string ans="";
	string res="";
	bool result = func(0,ans,n,str,res);
	if(result){
		cout<<res;
	}
	
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}