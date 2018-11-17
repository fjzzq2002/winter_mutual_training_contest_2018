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
const int MOD=1e9+7;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
char s[SZ];
struct arr {int p[9];} u[SZ];
arr operator & (const arr& a,const arr& b)
{
	arr c;
	for(int i=0;i<9;++i)
		c.p[i]=a.p[i]&b.p[i];
	return c;
}
int n,ps=0,m,po[233]; pii t[SZ]; ll aa=0;
void dfs(int d,arr t,int c,int su)
{
	for(int p=0;p<ps;++p)
		if(!t.p[p]) return;
	if(d>=m)
	{
		ll ans=po[su];
		for(int p=0;p<ps;++p)
			ans=ans*__builtin_popcount(t.p[p]);
		aa+=ans*c; aa%=MOD;
		return;
	}
	if(s[d]=='1')
		dfs(d+1,t&u[d],c,su+1);
	else
		dfs(d+1,t&u[d],-c,su+1),
		dfs(d+1,t,c,su);
}
int main()
{
	scanf("%s%d",s,&n); m=strlen(s);
	for(int j=0;j<=m;++j) po[j]=1;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&t[i].fi,&t[i].se);
	sort(t+1,t+1+n);
	arr x;
	for(int i=1;i<=n;++i)
	{
		if(t[i].fi>=m)
		{
			for(int w=0;w<=m;++w)
				po[w]=po[w]*(ll)(t[i].fi-w)%MOD;
			continue;
		}
		for(int w=0;w<m;++w)
		{
			u[w].p[ps]=(1<<t[i].fi)-1;
			u[w].p[ps]^=1<<((t[i].fi-w%t[i].fi)%t[i].fi);
		}
		x.p[ps++]=(1<<t[i].fi)-1;
	}
	dfs(0,x,1,0); aa%=MOD;
	for(int i=1;i<=n;++i)
		aa=aa*qp(t[i].fi,t[i].se-1)%MOD;
	aa=(aa%MOD+MOD)%MOD;
	printf("%d\n",int(aa));
}

