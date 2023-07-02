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
	bool contains(int i){
		return links[i]!=NULL;
	}
	void puts(int i, Node* newnode){
		links[i]=newnode;
	}
	Node* next(int i){
		return links[i];
	}
};
struct query{
	int index;
	int ele;
	int num;
};
class Trie{
	Node* root;
public:
	Trie(){
		root=new Node();
	}
	void insert(int num){
		Node* temp = root;
		for(int i=31;i>=0;i--){
			int mask = (1<<i);
			int value = num&mask;
			if(!temp->contains(i)){
				temp->puts(i, new Node());
			}
			temp=temp->next(i);
		}
	}
	int maxxor(int num){
		Node* temp = root;
		int ans=0;
		for(int i=31;i>=0;i--){
			int mask = (1<<i);
			int value = num&mask;
			if(temp->contains(1-value)){
				ans = ans | mask;
				temp=temp->next(1-value);
			}
			else{
				temp=temp->next(value);
			}
		}
		return ans;
	}
};
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<int> a(n), b(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	Trie tt;
	int maxi = 0;
	for(int i=0;i<n;i++){
		tt.insert(a[i]);
	}
	for(int i=0;i<m;i++){
		maxi = max(maxi, tt.maxxor(b[i]));
	}
	cout<<maxi<<endl;
	
}
bool cmp(query& q1, query& q2){
	if(q1.ele == q2.ele){
		return q1.index < q2.index;
	}
	return q1.ele < q2.ele;
}

void solve2(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<query> vect;
	for(int i=0;i<m;i++){
		query q;
		q.index = i;
		cin>>q.num>>q.ele;
		vect.push_back(q);
	}
	sort(a.begin(),a.end());
	sort(vect.begin(), vect.end(), cmp);
	vector<int> res(m);
	int j=0;
	Trie tt;
	for(int i=0;i<m;i++){
		while(j<n && a[j]<=vect[i].ele){
			tt.insert(a[j]);
			j++;
		}
		int ans = tt.maxxor(vect[i].num);
		res[vect[i].index] = ans;
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	solve2();
	return 0;
}