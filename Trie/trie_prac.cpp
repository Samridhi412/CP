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
public:
	Node* links[26];
	bool flag;
	int ce;
	int cp;
	Node(){
		flag=false;
		ce=0;
		cp=0;
		for(int i=0;i<26;i++){
			links[i]=NULL;
		}
	}
	bool contains(char ch){
		return links[ch-'a']!=NULL;
	}
	Node* getnext(char ch){
		return links[ch-'a'];
	}
	void puts(char ch, Node* newnode){
		links[ch-'a']=newnode;
	}
	bool isend(){
		return flag;
	}
	void setend(){
		flag=true;
	}
	void increaseprefix(){
		cp++;
	}
	void increaseend(){
		ce++;
	}
	void decreaseprefix(){
		cp--;
	}
	void decreaseend(){
		ce--;
	}
	int getprefix(){
		return cp;
	}
	int getend(){
		return ce;
	}
};
class Trie{
	Node* trienode;
public:
	Trie(){
		trienode=new Node();
	}
	void insert(string& str){
		Node* node=trienode;
		for(int i=0;i<str.size();i++){
			if(!node->contains(str[i])){
				node->puts(str[i],new Node());
			}
			node=node->getnext(str[i]);
			node->increaseprefix();
		}
		node->increaseend();
		node->setend();
	}
	bool search(string str){
		Node* node = trienode;
		for(int i=0;i<str.size();i++){
			if(!node->contains(str[i]))return false;
			node=node->getnext(str[i]);
		}
		return node->isend();
	}
	int startswith(string word){
		Node* node=trienode;
		for(int i=0;i<word.size();i++){
			if(!node->contains(word[i])){
				return 0;
			}
			node=node->getnext(word[i]);
		}
		return node->getprefix();
	}
	int countequalsto(string word){
		Node* node=trienode;
		for(int i=0;i<word.size();i++){
			if(!node->contains(word[i]))return 0;
			node=node->getnext(word[i]);
		}
		return (node->isend()?node->getend():0);
	}
	void erase(string word){
		Node* node=trienode;
		for(int i=0;i<word.size();i++){
			if(!node->contains(word[i]))return;
			node=node->getnext(word[i]);
			node->decreaseprefix();
			// if(node->getprefix()==0 && node->getend()==0){
			// 	delete(node);
			// }
		}
		node->decreaseend();
		// if(node->getprefix()==0 && node->getend()==0){
		// 	delete(node);
		// }
	}
	
};
void solve(){
	Trie tt;
	int n;
	cin>>n;
	vector<string> vect(n);
	for(int i=0;i<n;i++){
		getline(cin,vect[i]);
		tt.insert(vect[i]);
	}
	string word;
	cin>>word;
	cout<<tt.search(word);
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}