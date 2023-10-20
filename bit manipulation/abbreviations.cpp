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
void solve(){
	string str;
	getline(cin,str);
	vector<string> res;
	int strln = str.size();
	for(int i=0;i<(1<<strln);i++){
		int cnt=0;
		string temp;
		for(int j=str.size()-1;j>=0;j--){
			int mask = (1<<i);
			if(i&mask){
				cnt++;
			}
			else{
				if(cnt){
					temp+=to_string(cnt);
					temp+=str[str.size()-j];
					cnt=0;
				}
			}
		}
		if(cnt)temp+=to_string(cnt);
		res.push_back(temp);
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}