#include <iostream>
#include <stdio.h>
#include <assert.h>
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
typedef long long ll;
typedef pair<ll,ll> pii;
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
int _,n,q,a[SZ],N,ys[SZ],ch[SZ][2],mi[SZ],ls[SZ],rs[SZ],le[SZ];
map<pii,int> yy;
int build(int l,int r)
{
	int t=++N;
	ls[t]=l,rs[t]=r;
	yy[pii(l,r)]=t;
	if(l==r)
	{
		le[l]=t;
		return t;
	}
	scanf("%d",mi+t);
	assert(l<=mi[t]&&mi[t]<r);
	ys[mi[t]]=t;
	ch[t][0]=build(l,mi[t]);
	ch[t][1]=build(mi[t]+1,r);
	return t;
}
int sz[SZ],son[SZ],dep[SZ],fa[SZ];
bool imp[SZ];
void dfs(int x)
{
	sz[x]=1;
	for(auto c:ch[x]) if(c)
	{
		dep[c]=dep[x]+1; fa[c]=x;
		dfs(c); sz[x]+=sz[c];
		if(sz[c]>sz[son[x]]) son[x]=c;
	}
}
int top[SZ],dfn[SZ],C=0,rv[SZ];
void dd(int x,int t)
{
	top[x]=t; dfn[x]=++C; rv[C]=x;
	if(son[x]) imp[son[x]]=1,dd(son[x],t);
	for(auto c:ch[x])
		if(c&&c!=son[x]) dd(c,c);
}
int lca(int a,int b)
{
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]])
			b=fa[top[b]];
		else a=fa[top[a]];
	}
	if(dep[a]<dep[b]) return a;
	return b;
}
pii mg(pii ol,pii ne)
{
	if(ne.fi==0) return ne;
	return pii(ol.fi,ol.se+ne.se);
}
const pii emp(1,0);
pii tg[SZ];
set<int> ti; //imp nodes (dfns) with tag in tg[]
//warning: never edit tag of imp nodes in seg trees
const int M=524288;
struct Seg
{
int ls[SZ],rs[SZ];
pii vs[SZ];
Seg()
{
	for(int i=1;i<=M;++i)
		ls[i+M]=rs[i+M]=i;
	for(int i=M-1;i>=1;--i)
		ls[i]=ls[i+i],
		rs[i]=rs[i+i+1];
	for(int i=1;i<=M+M;++i)
		vs[i]=emp;
}
void pd(int x)
{
	if(x>=M||vs[x]==emp) return;
	vs[x+x]=mg(vs[x+x],vs[x]);
	vs[x+x+1]=mg(vs[x+x+1],vs[x]);
	vs[x]=emp;
}
void put(int x,int l,int r,pii t)
{
	if(l>r||rs[x]<l||r<ls[x]) return;
	pd(x);
	if(l<=ls[x]&&rs[x]<=r)
	{vs[x]=mg(vs[x],t); return;}
	put(x+x,l,r,t);
	put(x+x+1,l,r,t);
}
pii qry(int x,int l)
{
	pd(x);
	if(ls[x]==rs[x]) return vs[x];
	if(l<=rs[x+x])
		return qry(x+x,l);
	return qry(x+x+1,l);
}
void edt(int x,int l,int o,pii t)
{
	pd(x);
	if(ls[x]==rs[x])
	{
		if(o==0) vs[x]=t;
		else vs[x]=mg(vs[x],t);
		return;
	}
	if(l<=rs[x+x])
		edt(x+x,l,o,t);
	else edt(x+x+1,l,o,t);
}
}seg[2];
pii qtg(int g)
{
	//cerr<<"QTG!"<<g<<" "<<imp[g]<<"\n";
	if(imp[g]) return tg[g];
	int f=fa[g],c=ch[f][1]==g;
	return seg[c].qry(1,dfn[f]);
}
vector<pii> get_chain(int a,int x)
{
	//cerr<<"HI?\n";
	vector<pii> w;
	while(dep[a]<dep[top[x]])
		w.pb(pii(dfn[top[x]],dfn[x])),
		x=fa[top[x]];
	w.pb(pii(dfn[a],dfn[x]));
	reverse(w.begin(),w.end());
	//cerr<<"HEY!!\n";
	return w;
}
void pdc(int t)
{
//	cout<<"PULLDOWN"<<t<<"\n";
	auto w=get_chain(1,t);
	for(auto t:w)
	{
//		cout<<t.fi<<"~"<<t.se<<"~\n";
		int L=t.fi,u=0; pii o=emp;
		while(1)
		{
			int w=(u==0)?(u=1,t.fi):(*ti.upper_bound(L));
//			cerr<<L<<"~"<<t.se<<" "<<w<<"\n";
			if(w<=t.se)
			{
				seg[0].put(1,L,w-1,o);
				seg[1].put(1,L,w-1,o);
				w=rv[w];
//				cout<<w<<"GOGO"<<ls[w]<<"~"<<rs[w]<<"\n";
				//cerr<<"++\n";
				o=mg(qtg(w),o);
				//cerr<<"--\n";
				if(imp[w])
					ti.erase(dfn[w]), tg[w]=emp;
				else
					//cerr<<"GOO\n",
					seg[ch[fa[w]][1]==w].edt(1,dfn[fa[w]],0,emp);
					//cerr<<"NOO\n";
				L=dfn[w];
			}
			else
			{
				seg[0].put(1,L,t.se,o);
				seg[1].put(1,L,t.se,o);
				int g=rv[t.se];
				if(son[g])
					tg[son[g]]=mg(tg[son[g]],o),
					ti.insert(dfn[son[g]]);
				break;
			}
		}
	}
//	cout<<"\n";
}
void pu(int u,int a,int b,pii v)
{
	auto w=get_chain(a,b);
	for(int i=0;i<w.size();++i)
	{
		pii t=w[i];
		seg[u].put(1,t.fi,t.se-1,v);
		int g=rv[t.se];
		if(g==b)
		{
			int d=ch[g][u];
			if(imp[d])
				ti.insert(dfn[d]),
				tg[d]=mg(tg[d],v);
			else
				seg[u].edt(1,dfn[g],1,v);
		}
		else
		{
			int d=ch[g][u];
			assert(imp[d]==(rv[w[i+1].fi]!=d));
			if(imp[d])
				ti.insert(dfn[d]),
				tg[d]=mg(tg[d],v);
		}
	}
}
void deal(int l,int r,pii t)
{
	int a=ys[l-1],b=ys[r],c=lca(a,b);
//	cerr<<a<<"--"<<c<<"--"<<b<<"  "<<N<<" "<<dep[a]<<","<<dep[b]<<","<<dep[c]<<"?\n";
	pdc(a); pdc(b);
	//cerr<<"GG\n";
	//we need to put tags to right/left childs NOT in this chain
	if(b!=c)
		pu(0,ch[c][1],b,t);
	if(a!=c)
		pu(1,ch[c][0],a,t);
}
namespace BaoLi
{
typedef pair<int,int> pii;
#define SZ 666666
int _,n,q,a[SZ],N,ro,ys[SZ],ch[SZ][2],mi[SZ],ls[SZ],rs[SZ],le[SZ];
map<pii,int> yy;
int aa[SZ],bb[SZ];
void upd(int t)
{
	aa[t]=min(aa[ch[t][1]],aa[ch[t][0]]);
	bb[t]=max(bb[ch[t][1]],bb[ch[t][0]]);
}
int build(int l,int r)
{
	int t=++N;
	ls[t]=l,rs[t]=r;
	yy[pii(l,r)]=t;
	if(l==r) {le[l]=t;
	aa[t]=bb[t]=a[l];
	return t;}
	scanf("%d",mi+t);
	ys[mi[t]]=t;
	ch[t][0]=build(l,mi[t]);
	ch[t][1]=build(mi[t]+1,r);
	upd(t);
	return t;
}
pii mg(pii ol,pii ne)
{
	if(ne.fi==0) return ne;
	return pii(ol.fi,ol.se+ne.se);
}
const pii emp(1,0);
pii tg[SZ];
void ap(int x,pii t)
{
	aa[x]=aa[x]*t.fi+t.se;
	bb[x]=bb[x]*t.fi+t.se;
}
void pd(int x)
{
	for(auto c:ch[x])
		tg[c]=mg(tg[c],tg[x]),ap(c,tg[x]);
	tg[x]=emp;
}
void edt(int x,int l,int r,pii t)
{
	if(l>r||rs[x]<l||r<ls[x]) return;
	if(l<=ls[x]&&rs[x]<=r)
	{
		tg[x]=mg(tg[x],t);
		ap(x,t); return;
	}
	pd(x);
	edt(ch[x][0],l,r,t);
	edt(ch[x][1],l,r,t);
	upd(x);
}
int sq(int x)
{
	int w=sqrt(x)-1;
	while(w<=0||w*w<=x) ++w;
	return w-1;
}
void edt(int x,int l,int r)
{
	if(l>r||rs[x]<l||r<ls[x]) return;
	if(l<=ls[x]&&rs[x]<=r&&bb[x]-aa[x]<=1)
	{
		int A=sq(aa[x]),B=sq(bb[x]);
		pii t=(A==B)?pii(0,A):pii(1,A-aa[x]);
		tg[x]=mg(tg[x],t);
		ap(x,t); return;
	}
	pd(x);
	edt(ch[x][0],l,r);
	edt(ch[x][1],l,r);
	upd(x);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	ro=build(1,n);
	for(int i=1;i<=n+n;++i) tg[i]=emp;
	for(int i=1;i<=n;++i) tg[le[i]]=pii(0,a[i]);
	while(q--)
	{
		int o,l,r,k;
		scanf("%d%d%d",&o,&l,&r);
		if(o<=2)
		{
			scanf("%d",&k);
			edt(ro,l,r,pii(2-o,k));
		}
		else if(o==3)
			edt(ro,l,r);
		else if(o==4)
		{
			auto w=tg[yy[pii(l,r)]];
			printf("%d %d\n",w.fi,w.se);
		}
	}
	return 0;
}
}
int main()
{
	scanf("%d",&_);
	if(_<=2)
		return BaoLi::main();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	ys[0]=++N; ch[1][1]=N+1;
	ys[n]=++N; ch[2][0]=build(1,n);
	dep[1]=1; dfs(1); dd(1,1);
	for(int i=1;i<=N;++i) tg[i]=emp;
	ti.insert(1e9);
	for(int i=1;i<=n;++i)
	{
		int g=le[i]; pii t(0,a[i]);
		if(imp[g]) tg[g]=t,ti.insert(g);
		else
		{
			int f=fa[g],c=ch[f][1]==g;
			seg[c].edt(1,dfn[f],0,t);
		}
	}
	for(int i=1;i<=q;++i)
	{
		int o,l,r,k;
		scanf("%d%d%d",&o,&l,&r);
		if(l>r) throw "GG";
		if(o==3) continue; //ื฿มห
		if(o<=2) scanf("%d",&k);
		pii tg;
		if(o<=2)
			deal(l,r,pii(2-o,k));
		else
		{
			int ww=yy[pii(l,r)];
			if(!ww) throw "??";
			auto w=qtg(ww);
			printf("%lld %lld\n",w.fi,w.se);
		}
//		for(int i=1;i<=N;++i)
//		{
//			auto u=qtg(i);
//			cout<<i<<":"<<ls[i]<<","<<mi[i]<<","<<rs[i]<<"  "<<u.fi<<","<<u.se<<"  "<<dfn[i]<<","<<imp[i]<<"\n";
//		}
	}
}

