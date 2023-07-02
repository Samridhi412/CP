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
	bool contains(int bit){
		return (links[bit] != NULL);
	}
	void puts(int bit, Node* newnode){
		links[bit] = newnode;
	}
	Node* getnext(int bit){
		return links[bit];
	}
	int getsize(){
		return (links[0]!=NULL) + (links[1]!=NULL);
	}
};
class Trie{
	
public:
	Node* root;
	Trie(){
		root = new Node();
	}
	void insert(int num){
		Node* temp = root;
		for(int i=63;i>=0;i--){
			
			int bit = (num >> i) & 1;
			if(!temp->contains(bit)){
				temp->puts(bit, new Node());
			}
			temp = temp->getnext(bit);
		}
	}
	
};
ll evil_score(int bit, Node* root){
	if(bit < 0){
		return 0;
	}
	bool p1 = root->contains(0);
	bool p2 = root->contains(1);
	if(!p2){
		return evil_score(bit-1, root->getnext(0));
	}
	else if(!p1){
		return evil_score(bit-1, root->getnext(1));
	}
	return (1<<bit) + min(evil_score(bit-1, root->getnext(0)),evil_score(bit-1, root->getnext(1)));
	
}
ll helper(vector<int>& arr,int n){
	Trie tt;
	for(int i=0;i<n;i++){
		tt.insert(arr[i]);
	}
	ll ans=0;
	return evil_score(63,tt.root);
}
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<helper(arr,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}