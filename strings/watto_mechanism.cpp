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
struct node{
	node* links[3];
	bool isend=false;
	bool contains(char ch){
		return links[ch]!=NULL;
	}
	void puts(char ch,node* nn){
		links[ch]=nn;
	}
	node* getnext(char ch){
		return links[ch];
	}
	void setend(){
		isend=true;
	}
	bool isEnd(){
		return isend;
	}
};
class Trie{
public:
	node* root;
	Trie(){
		root=new node();
	}
	void insert(string word){
		node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i] - 'a')){
				temp->puts(word[i] - 'a',new node());
			}
			temp=temp->getnext(word[i] - 'a');
		}
		temp->setend();
	}
	
};
bool dfs(int ind,string& s,int diff, node* temp){
		if(ind==s.size()){
			if(diff == 1 && temp->isEnd())return true;
			return false;
		}
		for(int i=0;i<3;i++){
			if(temp->contains(i)){
				if(diff == 0 || (s[ind] - 'a' == i))
				  if(dfs(ind+1,s,diff + (s[ind] - 'a')!=i,temp->getnext(i)))return true;
			}
		}
		return false;
	}
void solve(){
	ll n,m;
	cin>>n>>m;
	Trie tt;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		tt.insert(str);
	}
	for(int i=0;i<m;i++){
		string temp;
		cin>>temp;
		if(dfs(0,temp,0,tt.root)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}