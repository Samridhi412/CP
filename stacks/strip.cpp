#include <iostream>
#include <set>
using namespace std;
long long a[100006],dp[100006];;
int main(){
	multiset <long long> tp;
	long long n,s,l;
	cin>>n>>s>>l;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=0;
	int pntr=1;
	for(int i=1;i<=n;i++){
		tp.insert(a[i]);
		while(((*tp.rbegin())-(*tp.begin()))>s){
			tp.erase(tp.find(a[pntr]));
			pntr+=1;
		}
		while(dp[pntr-1]==-1){
			tp.erase(tp.find(a[pntr]));
			pntr+=1;
			if(pntr==i){
				break;
			}
		}
		if((i-pntr)<(l-1)){
			dp[i]=-1;
		}else{
			dp[i]=dp[pntr-1]+1;
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}