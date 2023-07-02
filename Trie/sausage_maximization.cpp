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
		return links[bit]!=NULL;
	}
	void puts(int bit,Node* newnode){
		links[bit]=newnode;
	}
	Node* getnext(int bit){
		return links[bit];
	}
	
};
class Trie{
	Node* root;
public:
	Trie(){
		root = new Node();
	}
	void insert(int num){
		cout<<"insert"<<num<<endl;
		Node* temp = root;
		for(int i=31;i>=0;i--){
			int mask = (1<<i);
			int bit = num&mask;
			if(!temp->contains(bit)){
				temp->puts(bit,new Node());
			}
			temp=temp->getnext(bit);
		}
	}
	int maxxor(int num){
		Node* temp = root;
		int ans=0;
		for(int i=31;i>=0;i--){
			int mask = (1<<i);
			int bit = num&mask;
			if(temp->contains(1-bit)){
				ans = ans | mask;
				temp=temp->getnext(1-bit);
			}else{
				temp=temp->getnext(bit);
			}
		}
		return ans;
	}
};
void solve(){
	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> prefix_sum(n), suffix_sum(n);
	prefix_sum[0] = arr[0];
	for(int i=1;i<n;i++){
		prefix_sum[i] = prefix_sum[i-1] ^ arr[i];
	}
	suffix_sum[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--){
		suffix_sum[i] = suffix_sum[i+1] ^ arr[i];
	}
	Trie tt;
	int maxi=0;
	maxi=max(maxi,prefix_sum[n-1]);
	cout<<maxi<<endl;
	tt.insert(suffix_sum[n-1]);
	for(int i=n-2;i>=0;i--){
		maxi=max(maxi,prefix_sum[i]);
		// maxi=max(maxi,tt.maxxor(prefix_sum[i]));
		// tt.insert(suffix_sum[i]);
	}
	// Trie tt1;
	// tt1.insert(prefix_sum[0]);
	// for(int i=1;i<n;i++){
	// 	maxi=max(maxi,suffix_sum[i]);
	// 	maxi=max(maxi,tt1.maxxor(suffix_sum[i]));
	// 	tt1.insert(prefix_sum[i]);
	// }
	cout<<maxi<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}