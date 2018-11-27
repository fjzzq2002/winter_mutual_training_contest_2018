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
typedef unsigned us;
struct tag: pair<us,us>
{
	tag() {}
	tag(pair<us,us> a) {*this=a;}
	tag(us a,us b) {fi=a; se=b;}
};
struct info: pair<us,us>
{
	info() {}
	info(pair<us,us> a) {*this=a;}
	info(us a,us b) {fi=a; se=b;}
	info operator () (tag t)
	{
		return info((fi&(~t.fi))|(se&(~t.se))|((~t.fi)&(~t.se)),
		(fi&t.fi)|(se&t.se)|(t.fi&t.se));
	}
};
tag operator + (tag a,tag b) //old+new
{
	return tag((a.fi&b.se)|((~a.fi)&b.fi),
		(a.se&b.se)|((~a.se)&b.fi));
}
info operator & (info a,info b)
{return info(a.fi&b.fi,a.se&b.se);}
tag tag_or(us t) {return tag(t,-1u);}
tag tag_xor(us t) {return tag(t,~t);}
tag tag_and(us t) {return tag(0u,t);}
tag ot(0,-1u);
info oi(-1u,-1u);
#define S 2200999
const int M=1048576;
int ls[S],rs[S];
info seg[S]; tag tg[S];
info num(us x) {return info(~x,x);}
void pd(int x)
{
	if(tg[x]==ot) return;
	seg[x]=seg[x](tg[x]);
	if(x<=M)
		tg[x+x]=tg[x+x]+tg[x],
		tg[x+x+1]=tg[x+x+1]+tg[x];
	tg[x]=ot;
}
void upd(int x)
{
	pd(x+x); pd(x+x+1);
	seg[x]=seg[x+x]&seg[x+x+1];
}
int ts[2333],tn;
void tq(int x,int l,int r)
{
	if(r<ls[x]||rs[x]<l) return;
	pd(x);
	if(l<=ls[x]&&rs[x]<=r)
	{ts[++tn]=x; return;}
	tq(x+x,l,r); tq(x+x+1,l,r);
}
void apt(int x,int l,int r,tag t)
{
	if(r<ls[x]||rs[x]<l) return;
	pd(x);
	if(l<=ls[x]&&rs[x]<=r)
	{tg[x]=tg[x]+t; return;}
	apt(x+x,l,r,t);
	apt(x+x+1,l,r,t);
	upd(x);
}
//remember to tq before calling these
int tracel(info g)
{
	info h=oi;
	for(int i=1;i<=tn;++i)
	{
		info nh=h&seg[ts[i]];
		if(nh!=g) {h=nh; continue;}
		int w=ts[i];
		while(ls[w]!=rs[w])
		{
			pd(w+w); if((h&seg[w+w])==g) w+=w;
			else h=h&seg[w+w],pd(w+w+1),w+=w+1;
		}
		return ls[w];
	}
}
int tracer(info g)
{
	info h=oi;
	for(int i=tn;i>=1;--i)
	{
		info nh=h&seg[ts[i]];
		if(nh!=g) {h=nh; continue;}
		int w=ts[i];
		while(ls[w]!=rs[w])
		{
			pd(w+w+1); if((h&seg[w+w+1])==g) w+=w+1;
			else h=h&seg[w+w+1],pd(w+w),w+=w;
		}
		return ls[w];
	}
}
int L[S],R[S],id[S],N=0,I=0,ch[S][2];
#define U 22
int c0[1000999][U],c1[1000999][U],n,q;
map<pii,int> ys;
#undef S
namespace FF{
char ch,B[1<<20],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
int aa,bb;int F(){
    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}
}
#define gi FF::F()
#define BUFSIZE 5000000
namespace fob {char b[BUFSIZE]={},*f=b,*g=b+BUFSIZE-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce {~foce() {pob; fflush(stdout);}} _foce;
namespace ib {char b[100];}
inline void pll(ll x)
{
    if(x==0) {pc(48); return;}
    char *s=ib::b;
    while(x) *(++s)=x%10, x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}
inline int build(int l,int r)
{
	int x=++N; L[x]=l; R[x]=r;
	ys[pii(l,r)]=x;
	if(l==r) return x;
	int m=gi; id[x]=++I;
	c0[id[x]][0]=ch[x][0]=build(l,m);
	c1[id[x]][0]=ch[x][1]=build(m+1,r);
	for(int i=0;i+1<U;++i)
		c0[id[x]][i+1]=c0[id[c0[id[x]][i]]][i],
		c1[id[x]][i+1]=c1[id[c1[id[x]][i]]][i];
	return x;
}
int main()
{
	for(int i=1;i<=M+M;++i) tg[i]=ot;
	for(int i=1;i<=M;++i)
		ls[i+M]=rs[i+M]=i;
	for(int i=M-1;i>=1;--i)
		ls[i]=ls[i+i],rs[i]=rs[i+i+1];
	n=gi,q=gi;
	for(int i=1;i<=n;++i)
		seg[i+M]=num((us)gi);
	build(1,n);
	for(int i=M-1;i>=1;--i)
		seg[i]=seg[i+i]&seg[i+i+1];
	L[0]=2e9;
	while(q--)
	{
		int o=gi,l=gi,r=gi,x;
		if(o<=3)
		{
			x=gi; tag t;
			if(o==1) t=tag_and(x);
			if(o==2) t=tag_or(x);
			if(o==3) t=tag_xor(x);
			apt(1,l,r,t);
		}
		else
		{
			x=ys[pii(l,r)];
			if(!x) throw 233;
			ll ans=0;
			while(x)
			{
				l=L[x]; r=R[x];
				tn=0; tq(1,l,r);
				info g=oi;
				for(int i=tn;i>=1;--i)
					g=g&seg[ts[i]];
				us v=g.se;
				if(__builtin_popcount(v)&1)
				{
					int rr=tracel(g); int st=0;
					for(int u=U-1;u>=0;--u)
						if(R[c0[id[x]][u]]>=rr)
							st+=1<<u,x=c0[id[x]][u];
					++st; ans+=ll(v)*st; x=ch[x][0];
				}
				else
				{
					int aa=tracer(g); int st=0;
					for(int u=U-1;u>=0;--u)
						if(L[c1[id[x]][u]]<=aa)
							st+=1<<u,x=c1[id[x]][u];
					++st; ans+=ll(v)*st; x=ch[x][1];
				}
			}
			pll(ans); pc(10);
		}
	}
}
