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
int funct(int ind1,int ind2,int n,vector<int>& ht1,vector<int>& ht2, int prev){
	if(ind1>=n && ind2>=n){
		return 0;
	}
	int take1=0, take2=0, bothnottake=0, nontake=0;
	if(prev==2){
		if(ind1<n)take1 = funct(ind1+2,ind2+1,n,ht1,ht2,0) + ht1[ind1];
		if(ind2<n)take2 = funct(ind1+1,ind2+2,n,ht1,ht2,1) + ht2[ind2];
		bothnottake = funct(ind1+1,ind2+1,n,ht1,ht2,2);
	}
	else if(prev==0){
		if(ind1==ind2){
			if(ind2<n)take2 = funct(ind1+1,ind2+2,n,ht1,ht2,1) + ht2[ind2];
			nontake = funct(ind1+2,ind1+1,n,ht1,ht2,0);
		}
		else if(ind1-ind2 == 1){
			if(ind2<n)take2 = funct(ind1,ind2+2,n,ht1,ht2,1) + ht2[ind2];
			nontake = funct(ind1+1,ind2+1,n,ht1,ht2,0);
		}
		
	}
	else if(prev==1){
		if(ind1 == ind2){
			if(ind1<n)take1 = funct(ind1+2,ind2+1,n,ht1,ht2,0) + ht1[ind1];
			nontake = funct(ind1+1,ind2+2,n,ht1,ht2,1);
		}
		else if(ind1 - ind2 == -1){
			if(ind1<n)take1 = funct(ind1+2,ind2,n,ht1,ht2,0) + ht1[ind1];
			nontake = funct(ind1+1,ind2+1,n,ht1,ht2,1);
		}
	}
	return max(take1,max(take2,max(nontake,bothnottake)));
}
void solve(){
	ll n;
	cin>>n;
	vector<int> ht1(n), ht2(n);
	for(int i=0;i<n;i++){
		cin>>ht1[i];
	}
	for(int i=0;i<n;i++){
		cin>>ht2[i];
	}
	// cout<<funct(0,0,n,ht1,ht2,2);
	// vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(n+2,vector<int>(3,0)));
	vector<vector<int>> front1(n+2,vector<int>(3,0));
	vector<vector<int>> front2(n+2,vector<int>(3,0));
	
	for(int i=n;i>=0;i--){
		vector<vector<int>> curr(n+2,vector<int>(3,0));
		for(int j=n;j>=0;j--){
			if(i==n && j==n){
				continue;
			}
			for(int k=2;k>=0;k--){
				int take1=0, take2=0, bothnottake=0, nontake=0;
				if(k==2){
					if(i<n)take1 = front2[j+1][0] + ht1[i];
					if(j<n)take2 = front1[j+2][1] + ht2[j];
					bothnottake = front1[j+1][2];
				}
				else if(k==0){
					if(i==j){
						if(j<n){
							take2 = front1[j+2][1] + ht2[j];
						}
						nontake = front2[j+1][0];
					}
					else if(i-j == 1){
						if(j<n){
							take2 =  curr[j+2][1] + ht2[j];
						}
						nontake = front1[j+1][0];
					}
					
				}
				else if(k==1){
					if(i == j){
						if(i<n){
							take1 = front2[j+1][0] + ht1[i];
						}
						nontake = front1[j+2][1];
					}
					else if(i - j == -1){
						if(i<n){
							take1 = front2[j][0] + ht1[i];
						}
						nontake = front1[j+1][1];
					}
				}
				curr[j][k]= max(take1,max(take2,max(nontake,bothnottake)));
			}
		}
		front2=front1;
		front1=curr;
	}
	cout<<front1[0][2];
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}