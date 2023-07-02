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
void preprocess(string str, int* arr){
	for(int i=1;i<str.size();i++){
		if(str[i]==str[i-1]){
			arr[i]=1+arr[i-1];
		}
		else{
			arr[i]=arr[i-1];
		}
	}
}
void solve(){
	string str;
	cin>>str;
	int m;
	cin>>m;
	vector<pair<int,int>> queries(m);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		queries[i] = {a,b};
	}
	int n=str.size();
	int arr[n];
	memset(arr,0,sizeof(arr));
	preprocess(str, arr);
	for(int i=0;i<m;i++){
		cout<<arr[queries[i].second-1]-arr[queries[i].first-1]<<endl;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}