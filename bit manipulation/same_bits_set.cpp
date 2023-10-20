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
int count_bits(ll n){
	int rmsb = 0;
	while(n){
		n-=(n&-n);
		rmsb++;
	}
	return rmsb;
}
int ncr(int i,int k){
	if(i<k)return 0;
	ll res=1L;
	for(int r=1;r<=k;r++){
		res*=(i-k+r);
		res/=r;
	}
	return res;
}
int samebits(ll n, int i, int k){
	if(i==0)return 0;
	ll mask = 1L << i;
	long res=0;
	if((n&mask)==0){
		res=samebits(n,i-1,k);
	}else{
		int count1=samebits(n,i-1,k-1);
		int count2=ncr(i,k);
		res=count1+count2;
    }
	return res;
}
void solve(){
	ll n;
	cin>>n;
	int setbits=count_bits(n);
	samebits(n,setbits,63);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}