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
string check;
ll k;
struct node{
	node* links[26];
	bool ismark;
	bool contains(char ch){
		return links[ch]!=NULL;
	}	
	node* getnext(char ch){
		return links[ch];
	}
	void puts(char ch,node* n){
		links[ch]=n;
	}
	void set(){
		ismark = true;
	}
};
class Trie{
	node* root;
public:
	Trie(){
		root=new node();
	}
	void insert(string word){
		node* temp=root;
		int count_bad=0;
		for(int i=0;i<word.size();i++){
			count_bad += check[word[i]-'a'] == '0';
			if(!temp->contains(word[i])){
				temp->puts(word[i], new node());
			}
			temp=temp->getnext(word[i]);
		}
		if(count_bad <= k){
			temp->set();
		}
	}
	
};
void solve(){
	string str;
	getline(cin,str);
	getline(cin,check);
	cin>>k;
	int n=str.size();
	Trie tt;
	for(int i=0;i<n;i++){
		string res="";
		for(int j=i;j<n;j++){
			res += str[j];
			tt.insert(res);
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