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
	Node* links[2];
	int ce=0;
	int cp=0;
	bool contains(int bit){
		return (links[bit]!=NULL);
	}
	void puts(int bit, Node* newnode){
		links[bit] = newnode;
	}
	Node* getnext(int bit){
		return links[bit];
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
	Node* root;
public:
	Trie(){
		root=new Node();
	}
	void insert(int num){
		Node* temp=root;
		for(int i=31;i>=0;i--){
			int bit = (num>>i) & 1;
			if(!temp->contains(bit)){
				temp->puts(bit, new Node());
			}
			temp = temp->getnext(bit);
			temp->increaseprefix();
		}
		temp->increaseend();
	}
	void erase(int num){
		Node* temp=root;
		for(int i=31;i>=0;i--){
			int bit = (num>>i) & 1;
			if(!temp->contains(bit)){
				return;
			}
			temp = temp->getnext(bit);
			temp->decreaseprefix();
			
	}
			temp->decreaseend();
	}
	int maxprefix(int num){
		Node* temp=root;
		int ans = 0;
		for(int i=31;i>=0;i--){
			int bit = (num>>i) & 1;
			if(temp->contains(1-bit) && temp->getnext(1-bit)->getprefix() != 0){
				ans = ans | (1<<i);
				temp=temp->getnext(1-bit);
			}
			else if(temp->contains(bit)){
				temp=temp->getnext(bit);
			}
		}
		return ans;
	}
};
void solve(){
	ll queries;
	cin>>queries;
	vector<pair<char,int>> vect(queries);
	for(int i=0;i<queries;i++){
		cin>>vect[i].first;
		cin>>vect[i].second;
	}
	Trie tt;
	tt.insert(0);
	for(int i=0;i<queries;i++){
		if(vect[i].first == '+'){
			tt.insert(vect[i].second);
		}
		else if(vect[i].first == '-'){
			tt.erase(vect[i].second);
		}
		else{
			cout<<tt.maxprefix(vect[i].second)<<endl;
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