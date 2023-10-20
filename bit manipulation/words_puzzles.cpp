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
int getmask(string& str){
	int mask=0;
	for(int i=0;i<str.size();i++){
		int bit = str[i]-'a';
		mask = mask | (1<<bit);
	}
	return mask;
}
void solve(){
	// vector<string> words;
	// vector<string> puzzles;
	int w,p;
	cin>>w>>p;
	unordered_map<char,vector<int>> wmask;
	vector<vector<string>> res;
	for(int i=0;i<w;i++){
		string s;
		getline(cin,s);
		// words.push_back(s);
		wmask[s[0]].push_back(getmask(s));
	}
	for(int i=0;i<p;i++){
		string p;
		getline(cin,p);
		// puzzles.push_back(p);
		int pmask = getmask(p);
		vector<string> temp;
		int cnt++;
		for(int j=0;j<wmask[p[0]].size();j++){
			int maskk = wmask[p[0]][i];
			int bmask = pmask & maskk;
			if(bmask == maskk){
				cnt++;
			}
		}
		res.push_back(cnt);
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}