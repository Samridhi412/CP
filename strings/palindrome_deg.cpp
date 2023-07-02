// LUOGU_RID: 111816292
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#include<vector>
#define int long long
using namespace std;
const long long INF=0x3f3f3f3f3f3f3f3f;
inline int read();
inline char readchar();
int n;
char s[5000005];
char a[10000005];
void init()
{
	n=1;
	while(true)
	{
		char c=getchar();
		if(c>='A'&&c<='Z'||c>='a'&&c<='z'||c>='0'&&c<='9')
		{
			s[n]=c;
			n++;
		}
		else break;
	}
	n--;
	int nn=n*2+1;
	for(int i=1;i<=nn;i++)
	{
		if(i&1) a[i]='#';
		else a[i]=s[i>>1];
	}
	n=nn;
	for(int i=0;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
//	cout<<a+1<<endl;
	return;
}
int range[10000005];
void manacher()
{
	int R=1;
	int last=1;
	range[1]=0;
	for(int i=2;i<=n;i++)
	{
//		cout<<"i="<<i<<" R="<<R<<endl;
		if(i<=last+R)
		{
			int l=last-(i-last);
			range[i]=min(range[l],R-i);
			l=i-range[i];
			int r=i+range[i];
			if(r!=R) continue;
			while(true)
			{
				if(l-1==0||r+1==n+1) break;
				if(a[l-1]==a[r+1]) l--,r++;
				else break;
			}
			range[i]=r-i;
			if(r>R)
			{
				R=r;
				last=i;
			}
		}
		else
		{
			int l=i,r=i;
			R=i;
			while(true)
			{
				if(l-1==0||r+1==n+1) break;
				if(a[l-1]==a[r+1]) l--,r++;
				else break;
			}
			range[i]=r-i;
			if(r>R)
			{
				R=r;
				last=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<range[i]<<" ";
	cout<<endl;
	return;
}
int f[10000005];
void dp()
{
	f[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(range[i]+1==i)
		{
			if(i&1)
			{
				f[i]=f[((i-1)>>1)+1]+1;
			}
			else
			{
				f[i]=f[i>>1]+1;
			}
		}
	}
	return;
}
signed main()
{
	init();
	manacher();
	dp();
	int ans=0;
	for(int i=1;i<=n;i++) ans+=f[i];
	printf("%lld\n",ans);
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
inline int read()
{
	int ans=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans*flag;
}
