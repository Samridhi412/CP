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
	public:
	Node* links[26];
	bool flag = false;
	int countprefix=0;
	int countends=0;
	bool contains(char ch){
		return links[ch-'a']!=NULL;
	}
	void puts(char ch,Node* newnode){
		links[ch-'a']=newnode;
	}
	Node* getnext(char ch){
		return links[ch-'a'];
	}
	void setflag(){
		flag=true;
	}
	bool IsflagSet(){
		return flag;
	}
	void increaseprefix(){
		countprefix++;
	}
	void increaseEndWith(){
		countends++;
	}
	void decreaseprefix(){
		countprefix--;
	}
	void decreaseEndWith(){
		countends--;
	}
	int getPrefix(){
		return countprefix;
	}
	int getEndWith(){
		return countends;
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
				temp->puts(word[i],new Node());
			}
			temp=temp->getnext(word[i]);
			temp->increaseprefix();
		}
		temp->increaseprefix();
		temp->increaseEndWith();
		temp->setflag();
	}
	bool search(string word){
		Node* temp = root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				return false;
			}
			temp=temp->getnext(word[i]);
		}
		return temp->IsflagSet();
	}
	bool startwith(string word){
		Node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				return false;
			}
			temp=temp->getnext(word[i]);
		}
		return true;
	}
	int CountStartWith(string word){
		Node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				return 0;
			}
			temp=temp->getnext(word[i]);
		}
		return temp->getPrefix();
	}
	int CountEndWith(string word){
		Node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				return 0;
			}
			temp=temp->getnext(word[i]);
		}
		return temp->IsflagSet()==true?temp->getEndWith():0;
	}
	void Erase(string word){
		Node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				return;
			}
			temp=temp->getnext(word[i]);
			temp->decreaseprefix();
		}
		temp->decreaseEndWith();
	}
	bool CompleteString(string word){
		Node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				return false;
			}
			temp=temp->getnext(word[i]);
			if (temp->IsflagSet() == false){
				return false;
			}
		}
		return true;
	}
	//brute: space complexity
	int distinct_substring(string& s){
		Node* temp=root;
		int count=0;
		for(int i=0;i<s.size();i++){
			for(int j=i;j<s.size();j++)
			if(!temp->contains(s[j])){
				temp->puts(s[j],new Node());
				count++;
			}
			temp=temp->getnext(s[j]);
		}
		return count;
	}
};

void solve(){
	ll n;
	cin>>n;
	vector<string> str(n);
	cin.ignore();
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	Trie tt;
	for(int i=0;i<n;i++){
		tt.insert(str[i]);
	}
	sort(str.begin(),str.end());
	int maxlen=0;
	for(int i=0;i<n;i++){
		if(tt.CompleteString(str[i])){
			maxlen=max(maxlen,str[i].size());
		}
	}
	cout<<maxlen<<endl;
	string s;
	cin>>s;
	cout<<tt.distinct_substring(s);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}