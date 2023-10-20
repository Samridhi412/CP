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
void lbs(string & res){
	int i=0,j=0;
	int n=res.size();
	int open=0, close=0;
	int maxlen=0;
	int count=1;
	while(j<n){
		if(res[j]=='(')open++;
		else close++;
		if(open==close && i!=j){
			int len=j-i+1;
			if(len>maxlen){
				maxlen=len;
				count=1;
			}else if(maxlen==len){
				count++;
			}
			j++;
		}
		else if(close>open){
			while(close>open){
				if(res[i]==')'){
					close--;
				}else{
					open--;
				}
				i++;
			}
			if(open==close && i!=j){
			int len=j-i+1;
			if(len>maxlen){
				maxlen=len;
				count=1;
			}else if(maxlen==len){
				count++;
			}
			}
			j++;
		}else{
			j++;
		}
	}
	cout<<maxlen<<" "<<count;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	lbs(s);
	return 0;
}