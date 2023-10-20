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
void lbs(string& res){
	stack<int> s;
	s.push(-1);
	int cnt=0;
	int len=1;
	int n=res.size();
	for(int i=0;i<n;i++){
		if(res[i]=='('){
			s.push(i);
		}else{
			s.pop();
			if(s.empty()){
				s.push(i);
			}else{
				int ans = i-s.top();
				if(ans>cnt){
					cnt=ans;
					len=1;		
				}else if(ans==cnt){
					len++;
				}
			}
		}
	}
	cout<<cnt<<" "<<len<<endl;
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