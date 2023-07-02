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
		return (links[bit]!=NULL);
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
	void insert(ll num){
		Node* temp = root;
		for(int i=39;i>=0;i--){
			ll bit = (num>>i) & 1;
			if(!temp->contains(bit)){
				temp->puts(bit,new Node());
			}
			temp=temp->getnext(bit);
		}
	}
	ll maxxor(ll num){
		Node* temp = root;
		ll ans=0;
		for(int i=39;i>=0;i--){
			ll bit = (num>>i) & 1;
			if(temp->contains(!bit)){
				ans  += (ll)((long long)(1) << (long long)i);
				temp=temp->getnext(!bit);
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
	vector<ll> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<ll> prefix_sum(n+1,0), suffix_sum(n+1,0);
	prefix_sum[1] = arr[0];
	for(int i=2;i<=n;i++){
		prefix_sum[i] = prefix_sum[i-1] ^ arr[i-1];
	}
	suffix_sum[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--){
		suffix_sum[i] = suffix_sum[i+1] ^ arr[i];
	}
	Trie tt;
	for(int i=0;i<=n;i++){
		tt.insert(prefix_sum[i]);
	}
	ll maxi=0;
	for(int i=n;i>=0;i--){
		maxi = max(maxi, tt.maxxor(suffix_sum[i]));
	}
	cout<<maxi<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}