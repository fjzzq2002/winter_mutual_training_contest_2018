#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 1234567
int n,d,a[SZ];
ll f[SZ],g[SZ],x[SZ];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	int u=1;
	while(u<=d) u<<=1;
	for(int i=1;i+u<=n;++i)
		if(a[i]!=a[i+u])
		{
			puts("-1");
			return 0;
		}
	ll su=0,U=u;
	for(int i=1;i<=u;++i)
		su+=a[i];
	u>>=1;
	ll ans=0;
	while(u)
	{
		for(int i=1;i<=u;++i)
			f[i]=a[i]-a[i+u],x[i]=0,
			g[i]=f[i]-f[i-1];
		for(int i=2;i<=u;++i)
		{
			if(g[i]&1)
			{
				puts("-1");
				return 0;
			}
			ans+=abs(g[i]/2);
			x[i]+=g[i]/2;
			g[1]+=g[i]/2;
			g[i]=0;
		}
		ans+=abs(g[1]);
		for(int i=1;i<=u;++i)
			x[i]+=x[i-1],a[i]-=x[i];
		u>>=1;
	}
	su-=ans*(U/2);
	if(su<0)
	{
		puts("-1");
		return 0;
	}
	cout<<ans<<"\n";
}

