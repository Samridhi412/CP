#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a[3000000];
char s[1520],v[30];
int k,c;
int main()
{
	cin>>s>>v>>k;
	for(int i=0;s[i];i++){
		for(ll j=i,kk=k,h=0;s[j];j++){
			if(v[s[j]-'a']=='0'&&!kk--)
				break;
			else
				a[c++]=h=(h*131)^s[j];
		}
	}
	sort(a,a+c);
	cout<<unique(a,a+c)-a;
}