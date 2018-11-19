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
ll n; int k;
struct Info
{
int r[155][155],s[155];
bool f[155]; ll l;
}p[153],I;
const int MOD=998244353;
Info operator << (Info a,int p)
{
	Info g; g.l=a.l;
	for(int i=0;i<k;++i)
		g.f[(i+p)%k]=a.f[i],
		g.s[(i+p)%k]=a.s[i];
	for(int i=0;i<k;++i)
		for(int j=0;j<k;++j)
			g.r[(i+p)%k][(j+p)%k]=a.r[i][j];
	return g;
}
Info operator * (const Info& a,const Info& b)
{
	Info g; g.l=a.l+b.l;
	for(int i=0;i<k;++i)
	{
		if(a.f[i])
		{
			g.f[i]=1; g.s[i]=a.s[i];
			for(int j=0;j<k;++j)
				g.r[i][j]=0;
			for(int j=0;j<k;++j)
				if(b.f[j])
				{
					register ll r=a.r[i][j];
					g.s[i]=(g.s[i]+r*b.s[j])%MOD;
					for(int p=0;p<k;++p)
						g.r[i][p]=(g.r[i][p]+r*b.r[j][p])%MOD;
				}
				else
					(g.r[i][j]+=a.r[i][j])%=MOD;
		}
		else if(b.f[i])
		{
			g.f[i]=1; g.s[i]=b.s[i];
			for(int j=0;j<k;++j)
				g.r[i][j]=b.r[i][j];
		}
		else g.f[i]=0;
	}
	return g;
}
Info go(Info&t,int g)
{
	if(g==1)
		return t;
	Info w=go(t,g>>1);
	w=w*(w<<(g>>1));
	if(g&1) w=w*(t<<(g-1));
	return w;
}
int sn,ss[SZ];
int main()
{
	cin>>n>>k;
	p[0].f[0]=1;
	p[0].s[0]=1;
	p[0].l=1;
	for(int i=0;i<k;++i)
		p[0].r[0][i]=1;
	for(ll w=n;w;w/=k)
		ss[++sn]=w%k;
	for(int i=1;i<sn;++i)
		p[i]=p[i]*go(p[i-1],k);
	for(int i=sn,su=0;i>=1;su+=ss[i--])
		if(ss[i]) p[sn]=p[sn]*(go(p[i-1],ss[i])<<su);
	ll ans=1;
	for(int i=0;i<k;++i)
		(ans+=p[sn].s[i])%=MOD;
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}
