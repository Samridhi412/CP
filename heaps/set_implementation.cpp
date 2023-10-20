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
// class Node{
// public:
// 	int data;
// 	Node* prev;
// 	Node* next;
// 	Node(int data){
// 		this->data=data;
// 		prev=next=NULL;
// 	}
// };
class HashSet{
	int maxSize;
	vector<list<int>> hashset;
public:
	HashSet(int maxSize){
		this->maxSize=maxSize;
	}
	void remove(int data){
		if(!contains(data))return;
		int i=hash(data);
		hashset[i].erase(search(key));
	}
	void add(int data){
		if(contains(data))return;
		int i=hash(data);
		hashset[i].push_back(data);
	}
	list<int>::iterator search(int key){
		int i = hash(key);
		return find(hashset[i].begin(),hashset[i].end(),key);
	}
	int hash(int key){
		return key%maxSize;
	}
	bool contains(int key){
		int i=hash(key);
		if(search(key)!=hashset[i].end())return true;
		return false;	
	}
};
void solve(){
	ll n;
	cin>>n;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}