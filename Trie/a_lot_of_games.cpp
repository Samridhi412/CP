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
struct Node{
	Node* links[26];
	bool flag;
	bool contains(char ch){
		return (links[ch-'a']!=NULL);
	}
	void setflag(){
		flag=true;
	}
	bool getflag(){
		return flag;
	}
	void puts(char ch, Node* newnode){
		links[ch-'a']=newnode;
	}
	Node* getnext(char ch){
		return links[ch-'a'];
	}
};
class Trie{
	Node* root;
public:
	Trie(){
		root=new Node();
	}
	void insert(string word){
		Node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				temp->puts(word[i], new Node());
			}
			temp=temp->getnext(word[i]);
		}
		temp->setflag();
	}
	bool has_prefix(string word){
		Node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				return false;
			}
			temp=temp->getnext(word[i]);
		}
		return true;
	}
};
bool game(bool player,string& ans,Trie tt){
	for(char ch='a';ch<='z';ch++){
		ans.push_back(ch);
		if(tt.has_prefix(ans)){
			bool loser = game(!player,ans,tt);
			if(loser!=player){
				return loser;
			}
		}
		ans.pop_back();
	}
		return player;
}
bool helper(bool player, Trie& tt,int k){
	string ans="";
	bool loser = game(player,ans,tt);
	for(int kk=1;kk<k;kk++){
		loser = game(loser,ans,tt);
	}
	if (player!=loser){
			return true;
	}
	return false;
}
void solve(){
	ll n,k;
	cin>>n>>k;
	Trie tt;
	for(int i=0;i<n;i++){
		string input;
		getline(cin,input);
		tt.insert(input);
	}
	if(helper(0,tt,k)){
		cout<<"First"<<endl;
	}
	else{
		if(helper(1,tt,k)){
			cout<<"First"<<endl;
		}
		else{
			cout<<"Second"<<endl;
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