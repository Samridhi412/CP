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
template<typename V>
// make private or use friend class
class MapNode{
public:
	string key;
	V value;
	MapNode* next;
	MapNode(string key, V value){
		this->key=key;
		this->value=value;
		next=NULL;
	}
	~MapNode(){
		delete next;
	}
};
template<typename V>
class ourmap{
	MapNode<V>** buckets;
	int count;
	int numbuckets;
public:
	ourmap(){
		count=0;
		numbuckets=5;
		buckets=new MapNode<V>*[numbuckets];
		for(int i=0;i<numbuckets;i++){
			buckets[i]=NULL;
		}
	}
	~ourmap(){
		for(int i=0;i<numbuckets;i++){
			delete buckets[i];
		}
		delete []buckets;
	}
	int size(){
		return count;
	}
private:
	int getBucketIndex(string key){
		int hashcode=0;
		int coeff=1;
		for(int i=key.size()-1;i>=0;i--){
			hashcode+=key[i]*coeff;
			hashcode%=numbuckets;
			coeff*=37;
			coeff=coeff%numbuckets;
		}
		return hashcode%numbuckets;
	}
	void rehash(){
		MapNode<V>** temp = buckets;
		buckets = new MapNode<V>*[2*numbuckets];
		for(int i=0;i<2*numbuckets;i++){
			buckets[i]=NULL;
		}
		int oldBucketCount = numbuckets;
		numbuckets*=2;
		count=0;
		for(int i=0;i<oldBucketCount;i++){
			MapNode<V>* head=temp[i];
			while(!head){
				string key=head->key;
				V value=head->value;
				insert(key,value);
				head=head->next;
			}
		}
		for(int i=0;i<oldBucketCount;i++){
			MapNode<V>* head=temp[i];
			delete head;
		}
		delete [] temp;
	}
public:
	double getLoadFactor(){
		return (1.0*count)/numbuckets;
	}
	void insert(string key, V value){
		int bucketIndex=getBucketIndex(key);
		MapNode<V>* head=buckets[bucketIndex];
		while(!head){
			if(head->key==key){
				head->value=value;
				return;
			}
			head=head->next;
		}
		head=buckets[bucketIndex];
		MapNode<V>* node=new MapNode<V>(key,value);
		node->next=head;
		buckets[bucketIndex]=node;
		count++;
		double loadfactor = (1.0*count)/numbuckets;
		if(loadfactor > 0.7){
			rehash();
		}
	}
	V getvalue(string key){
		int bucketIndex=getBucketIndex(key);
		MapNode<V>* head=buckets[bucketIndex];
		while(!head){
			if(head->key==key)return head->value;
			head=head->next;
		}
		return 0;
	}
	V remove(string key){
		int bucketIndex=getBucketIndex(key);
		MapNode<V>* head=buckets[bucketIndex];
		MapNode<V>* prev=NULL;
		while(!head){
			if(head->key==key){
				if(prev==NULL){
					buckets[bucketIndex]=head->next;
				}else{
					prev->next=head->next;
				}
				V value=head->value;
				head->next=NULL;
				delete(head);
				count--;
				return value;
			}
			prev=head;
			head=head->next;
		}
		return 0;
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