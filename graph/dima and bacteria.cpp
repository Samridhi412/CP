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
const ll N=1e5+!0;
ll dist[510][510];
ll c[510];
ll tmp[N];
ll p[N];
ll find(ll node){
	if(p[node]==node){
		return node;
	}
	return p[node]=find(p[node]);
}
void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)p[i]=i;
	memset(c,0,sizeof(c));
	memset(dist,mod,sizeof(dist));
	for(int i=1;i<=k;i++){
		cin>>c[i];
		c[i]+=c[i-1];
	}
	for(int i=1;i<=k;i++){
		for(int j=c[i-1]+1;j<=c[i];j++){
			tmp[j]=i;
		}
	}
	ll def=dist[0][0];
	for(int i=0;i<m;i++){
		ll a,b,x;
		cin>>a>>b>>x;
		ll u=tmp[a];
		ll v=tmp[b];
		dist[u][v]=dist[v][u]=min(dist[u][v],x);
		if(x==0){
			ll pa=find(a);
			ll pb=find(b);
			if(pa!=pb){
				p[a]=b;
			}
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=c[i-1]+1;j<c[i];j++){
			if(find(j)!=find(j+1)){
				cout<<"No"<<endl;
				return;
			}
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				dist[j][l]=min(dist[j][l],dist[j][i]+dist[i][l]);
			}
		}
	}
	for(int i=1;i<=k;i++)dist[i][i]=0;
	cout<<"Yes"<<endl;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(dist[i][j]==def){
				cout<<-1<<" ";
				continue;
			}
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}