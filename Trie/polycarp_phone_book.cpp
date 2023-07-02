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
	Node* links[10];
	int ce=0;
	bool contains(char ch){
		return (links[ch-'0']!=NULL);
	}
	void increaseEnd(){
		ce++;
	}
	void puts(char ch,Node* newnode){
		links[ch-'0'] = newnode;
	}
	Node* getnext(char ch){
		return links[ch-'0'];
	}
	int get_ce(){
		return ce;
	}
};
class Trie {
	Node* root;
public:
	Trie(){
		root = new Node();
	}
	void insert(string word){
		Node* temp=root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				temp->puts(word[i],new Node());
			}
			temp = temp->getnext(word[i]);
		}
		temp->increaseEnd();
	}
	int countEnd(string word){
		Node* temp = root;
		for(int i=0;i<word.size();i++){
			if(!temp->contains(word[i])){
				return 0;
			}
			temp=temp->getnext(word[i]);
		}
		return temp->get_ce();
	}
	
};
string convert_string(int num){
    ostringstream str1;
    str1 << num;
    string s = str1.str();
    return s;
 
}
void solve(){
	ll n;
	cin>>n;
	vector<int> numbers(n);
	for(int i=0;i<n;i++){
		cin>>numbers[i];
	}
	vector<string> num_str(n);
	Trie tt;
	for(int i=0;i<n;i++){
		string str = convert_string(numbers[i]);
		num_str[i] = str;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<num_str[i].size();j++){
			string ans;
			for(int k=j;k<num_str[i].size();k++){
				ans+=num_str[i][k];
				tt.insert(ans);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<num_str[i].size();j++){
			string ans;
			bool flag = 0;
			for(int k=j;k<num_str[i].size();k++){
				ans+=num_str[i][k];
				if(tt.countEnd(ans)==1){
					cout<<ans<<endl;
					flag=1;
					break;
				}
			}
			if(flag){
				break;
			}
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