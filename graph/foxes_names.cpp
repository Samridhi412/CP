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
#define pb push_back
#define endl "\n"
unordered_set<int> letter;
unordered_map<char,vector<char>> mp;
unordered_map<char,int> indeg;
bool compare(string& s,string& t){
	int i=0,j=0;
	while(i<s.size() && j<t.size()){
		if(s[i]!=t[j]){
			mp[s[i]].push_back(t[j]);
			letter.insert(s[i]);
			letter.insert(t[j]);
			if(indeg.find(s[i])==indeg.end()){
				indeg[s[i]]=0;
			}
			indeg[t[j]]++;
			return true;
			
		}
		i++;
		j++;
	}
	return s.size()<=t.size();
}
vector<char> topo(){
	vector<char> res;
	queue<char> q;
	for(auto &val:indeg){
		if(val.second==0){
			q.push(val.first);
		}
	}
	while(!q.empty()){
		char ele=q.front();
		res.push_back(ele);
		q.pop();
		for(auto &u:mp[ele]){
			indeg[u]--;
			if(indeg[u]==0){
				q.push(u);
			}
		}
		
	}
	return res;
}
void solve(){
	ll n;
	cin>>n;
	vector<string> names(n);
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin,names[i]);
	}
	mp.clear();
	indeg.clear();
	letter.clear();
	for(int i=0;i<n-1;i++){
		string s1=names[i];
		string s2=names[i+1];
		if(!compare(s1,s2)){
		   cout<<"Impossible";
		   return;	
		}
	}
	vector<char> result=topo();
	if(result.size()!=letter.size()){
		cout<<"Impossible"<<endl;
		return;
	}
	string res;
	letter.clear();
	for(auto &ch:result){
		res+=ch;
		letter.insert(ch);
	}
	for(char ch='a';ch<='z';ch++){
		if(letter.count(ch)==0){
			res+=ch;
		}
	}
	cout<<res<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}