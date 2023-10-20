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
class Node{
	Node* links[26];
	bool flag;
public:
	Node(){
		for(int i=0;i<26;i++){
			links[i]=NULL;
		}
		flag=false;
	}
	bool contains(char ch){
		return links[ch-'a']!=NULL;
	}
	Node* getnext(char ch){
		return links[ch-'a'];
	}
	void setend(){
		flag=true;
	}
	void puts(char ch, Node* newnode){
		links[ch-'a']=newnode;
	}
	bool isend(){
		return flag;
	}
};
class Trie{
	Node* trienode;
public:
	Trie(){
		trienode=new Node();
	}
	void insert(string word){
		Node* node=trienode;
		for(int i=0;i<word.size();i++){
			if(!node->contains(word[i])){
				node->puts(word[i],new Node());
			}
			node=node->getnext(word[i]);
		}
		node->setend();
	}
	bool check(string word){
		Node* node=trienode;
		for(int i=0;i<word.size();i++){
			if(!node->contains(word[i]) || !node->isend()){
				return false;
			}
			node=node->getnext(word[i]);
		}
		return node->isend();
	}
	
	
};
void solve(){
	ll n;
	cin>>n;
	vector<string> input(n);
	for(int i=0;i<n;i++){
		getline(cin,input[i]);
	}
	Trie tt;
	for(int i=0;i<n;i++){
		tt.insert(input[i]);
	}
	string complete="";
	for(int i=0;i<n;i++){
		if(tt.check(input[i])){
			if(complete.size() < input[i].size() || complete < input[i]){
				complete=input[i];
			}
		}
	}
	cout<<complete<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}