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
int n,l[SZ],t[SZ],w[SZ];
ll f[SZ],s[SZ];
pair<pii,pair<int,ll> > g[SZ];
int gn=0;
typedef pair<ll,ll> pll;
ll seg[SZ];
const int M=131072;
vector<pll> mh(vector<pll> a,vector<pll> b)
{
	vector<pll> c,d;
	c.resize(a.size()+b.size()); d.reserve(c.size());
	merge(a.begin(),a.end(),b.begin(),b.end(),c.begin(),greater<pll>());
	for(int i=0;i<int(c.size());++i)
	{
		if(i+1<int(c.size())&&c[i].fi==c[i+1].fi) continue;
		auto z=c[i];
		while(d.size()>=2)
		{
			auto x=d[d.size()-2],y=d.back();
			if((y.se-x.se)*(z.fi-y.fi)>(z.se-y.se)*(y.fi-x.fi)) break;
			d.pop_back();
		}
		d.pb(z);
	}
	return d;
}
struct Hull
{
vector<pll> v; int r;
void pb(pll x) {v.pb(x);}
void ir() {r=int(v.size())-1;}
ll qry(ll x)
{
	if(r<0) return 8e18;
	while(r&&v[r].fi*x+v[r].se>v[r-1].fi*x+v[r-1].se) --r;
	return v[r].fi*x+v[r].se;
}
}hs[SZ];
ll qmin(int l,int r)
{
	ll t=4e18;
	if(l>r) return t;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) t=min(t,seg[l^1]);
		if(r&1) t=min(t,seg[r^1]);
	}
	return t;
}
void upd(int x,ll g)
{
	for(x+=M;x;x>>=1)
		seg[x]=min(seg[x],g);
}
int ls[SZ],rs[SZ],dep[SZ],tr[SZ];
void push(int x,pll t)
{
	x+=M; hs[x].pb(t); hs[x].ir();
}
void rebuild(int x)
{
	if(hs[x].v.size()) return;
	rebuild(x+x); rebuild(x+x+1);
	hs[x].v=mh(hs[x+x].v,hs[x+x+1].v);
	hs[x].ir();
}
void pop(int x)
{
	for(x+=M;x;x>>=1)
	{
		hs[x].v.clear();
		if(x<=M) tr[dep[x]]=x;
	}
}
void qry(int x,int l,int r,ll&t,ll v)
{
	if(rs[x]<l||r<ls[x]) return;
	if(l<=ls[x]&&rs[x]<=r&&x!=tr[dep[x]])
	{
		rebuild(x); t=min(t,hs[x].qry(v)); return;
	}
	qry(x+x,l,r,t,v); qry(x+x+1,l,r,t,v);
}
int main()
{
	for(int i=0;i<=M;++i)
		ls[i+M]=rs[i+M]=i,dep[i+M]=0;
	for(int i=M-1;i>=1;--i)
		ls[i]=ls[i+i],rs[i]=rs[i+i+1],dep[i]=dep[i+i]+1;
	memset(seg,127/3,sizeof seg);
	memset(f,127/3,sizeof f);
	scanf("%d",&n); f[0]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",l+i,t+i,w+i);
		s[i]=s[i-1]+w[i]; ++l[i];
	}
	upd(1,f[0]);
	for(int i=1;i<=n;++i)
	{
		int L=i; ll mi=f[i-1];
		while(gn&&g[gn].se.fi<t[i])
			L=g[gn].fi.fi,pop(gn),
			mi=min(mi,g[gn--].se.se);
		g[++gn]=mp(pii(L,i),mp(t[i],mi));
		push(gn,g[gn].se);
		int p=lower_bound(g+1,g+1+gn,
		mp(pii(l[i],2e9),mp(0,0LL)))-g;
		ll x=s[n]-s[i];
		if(p>1)
			f[i]=min(f[i],qmin(l[i],g[p-1].fi.se)+
			g[p-1].se.fi*x);
		if(p<=gn) qry(1,p,gn,f[i],x);
		upd(i+1,f[i]);
	}
	printf("%lld\n",f[n]);
}
