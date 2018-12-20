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
#define SZ 666666
int n,t,k;
ll a[SZ],b[SZ],c[SZ],sa[SZ],sb[SZ];
ll d[235][235][235],g[235][235][235];
inline void cmin(ll&a,ll b)
{if(a>b) a=b;}
int main()
{
	cin>>n>>t>>k; ++n;
	const ll inf=1e18;
	for(int i=1;i<=n;++i)
	{
		if(i==n) a[i]=c[i]=inf;
		else cin>>a[i]>>b[i]>>c[i];
		sa[i]=sa[i-1]+a[i];
		sb[i]=sb[i-1]+b[i];
	}
	for(int p=1;p<=n;++p)
		for(int s=0;s<=t;++s)
			for(int z=0;z<2;++z)
			{
				d[p][s][z]=g[p][s][z]=inf;
				if(s*b[p]+z*a[p]<=c[p]
				&&d[p-1][s][z]<inf)
				{
					d[p][s][z]=d[p-1][s][z];
					ll v=(z*sa[p-1]+s*sb[p-1]+k-1)/k;
					if(v*k<=z*sa[p]+s*sb[p])
						g[p][s][z]=v;
				}
				for(int r=0;r<s;++r) if(g[p][r][z]<inf)
				{
					ll m=z*sa[p]+r*sb[p]-k*g[p][r][z];
					ll x=(max(m+(s-r)*b[p]-c[p],0LL)+k-1)/k;
					if(x*k<=m&&d[p-1][s-r][0]<inf)
					{
						cmin(d[p][s][z],g[p][r][z]+x+d[p-1][s-r][0]);
						ll v=((s-r)*sb[p-1]+k-1)/k;
						if(v*k<=(s-r)*sb[p]+m-x*k)
							cmin(g[p][s][z],g[p][r][z]+x+v);
					}
				}
			}
	cout<<d[n][t][1]<<"\n";
}

