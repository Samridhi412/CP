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
	ll n,m;
	cin>>n>>m;
	vector<char> h(n);
	vector<char> v(m);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	for(int i=0;i<m;i++){
		cin>>v[i];
	}
	vector<
	queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(i+1<n){
			
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