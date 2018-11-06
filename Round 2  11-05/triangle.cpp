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
#include <assert.h> 
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pll;
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
int _,n,w[SZ]; Edg
int ff[SZ],fa[SZ];
pll v[SZ],V[SZ];
ll cmp(pll a,pll b)
{
	if((a.fi<=0)!=(b.fi<=0))
		return int(a.fi>0)-int(b.fi>0);
	if(a.fi<=0)
		return a.se-b.se;
	return (a.se-a.fi)-(b.se-b.fi);
}
pll operator + (pll a,pll b)
{return mp(a.fi+b.fi,max(a.se,a.fi+b.se));}
struct scmp
{
bool operator () (int a,int b)
{
	ll w=cmp(v[a],v[b]);
	if(w) return w<0;
	return a<b;
}
};
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
set<int,scmp> sb;
int fs[SZ],ns[SZ],ls[SZ];
bool cho[SZ];
int vs[SZ],vn,sz[SZ],son[SZ],ps[SZ];
void dfs(int x)
{
	sz[x]=1;
	for esb(x,e,b)
	{
		dfs(b); sz[x]+=sz[b];
		if(sz[b]>sz[son[x]]) son[x]=b;
	}
}
ll ans[SZ];
#define M M_
const int M=262144;
pll seg[SZ];
void upd(int x,pll u)
{
	x+=M; seg[x]=u;
	for(x>>=1;x;x>>=1)
		seg[x]=seg[x+x]+seg[x+x+1];
}
void add(int x) {upd(ps[x],V[x]);}
void add_tree(int x)
{
	add(x);
	for esb(x,e,b) add_tree(b);
}
void clr_tree(int x)
{
	upd(ps[x],pll(0,0));
	for esb(x,e,b) clr_tree(b);
}
void dsu(int x,int k)
{
	for esb(x,e,b)
		if(b!=son[x]) dsu(b,0);
	if(son[x]) dsu(son[x],1);
	add(x);
	for esb(x,e,b)
		if(b!=son[x]) add_tree(b);
	ans[x]=(pll(w[x],w[x])+seg[1]).se;
	if(!k) clr_tree(x);
}
int main()
{
	scanf("%d%d",&_,&n);
	for(int i=2,t;i<=n;++i)
		scanf("%d",&t),fa[i]=t,ad_de(t,i);
	for(int i=1;i<=n;++i)
		scanf("%d",w+i);
	for(int i=1;i<=n;++i)
	{
		fs[i]=i,ls[i]=i;
		ll sc=0;
		for esb(i,e,b) sc+=w[b];
		v[i]=V[i]=mp(-w[i]+sc,sc);
		sb.insert(i);
	}
	vector<int> vv;
	while(!sb.empty())
	{
		int f=*sb.begin();
		if(f==1||cho[gf(fa[f])])
		{
			vv.pb(fs[f]); cho[f]=1;
			sb.erase(sb.begin());
			continue;
		}
		int u=gf(fa[f]);
		sb.erase(sb.begin());
		sb.erase(u);
		ns[ls[u]]=fs[f];
		ls[u]=ls[f];
		ff[f]=u;
		v[u]=v[u]+v[f];
		sb.insert(u);
	}
	for(auto t:vv)
		for(int u=t;u;u=ns[u])
			vs[++vn]=u;
	assert(vn==n);
	for(int i=1;i<=n;++i) ps[vs[i]]=i;
	dfs(1); dsu(1,1);
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	puts("");
}

