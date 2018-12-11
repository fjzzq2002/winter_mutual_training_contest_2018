#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <immintrin.h>
#include <emmintrin.h>
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
//根号是不可能写的，这辈子都不可能写的 
//avx2
//_mm256_set_epi16
//_mm256_add_epi16
//_mm256_sub_epi16
//_mm256_cmpeq_epi16
int n,m,T,g[SZ]; Edg
short a[SZ],b[SZ];
__m256i s[SZ/16],v[SZ/16];
static __m256i o,lm;
void ou(int t)
{
	memcpy(a,(short*)(s+t),sizeof(short)*16);
	memcpy(b,(short*)(v+t),sizeof(short)*16);
}
void in(int t)
{
	memcpy((short*)(s+t),a,sizeof(short)*16);
	memcpy((short*)(v+t),b,sizeof(short)*16);
}
void edt1(int l,int r)
{
	int bl=l/16,br=r/16;
	ou(bl);
	for(int j=0;j<16;++j)
		if(bl*16+j>=l&&bl*16+j<=r)
			++a[j],b[j]=(a[j]>0);
	in(bl);
	if(bl!=br)
	{
		ou(br);
		for(int j=0;j<16;++j)
			if(br*16+j>=l&&br*16+j<=r)
				++a[j],b[j]=(a[j]>0);
		in(br);
	}
	if(bl<br-1)
		for(int x=bl+1;x!=br;++x)
			v[x]=_mm256_sub_epi16(v[x],_mm256_cmpeq_epi16(s[x],o)),
			s[x]=_mm256_add_epi16(s[x],lm);
}
void edtm1(int l,int r)
{
	int bl=l/16,br=r/16;
	ou(bl);
	for(int j=0;j<16;++j)
		if(bl*16+j>=l&&bl*16+j<=r)
			--a[j],b[j]=(a[j]>0);
	in(bl);
	if(bl!=br)
	{
		ou(br);
		for(int j=0;j<16;++j)
			if(br*16+j>=l&&br*16+j<=r)
				--a[j],b[j]=(a[j]>0);
		in(br);
	}
	if(bl<br-1)
		for(int x=bl+1;x!=br;++x)
			s[x]=_mm256_sub_epi16(s[x],lm),
			v[x]=_mm256_add_epi16(v[x],_mm256_cmpeq_epi16(s[x],o));
}
int qry(int l,int r)
{
	int bl=l/16,br=r/16,su=0;
	__m256i t=o;
	ou(bl);
	for(int j=0;j<16;++j)
		if(bl*16+j>=l&&bl*16+j<=r) su+=b[j];
	if(bl!=br)
	{
		ou(br);
		for(int j=0;j<16;++j)
			if(br*16+j>=l&&br*16+j<=r) su+=b[j];
	}
	if(bl<br-1)
	{
		for(int x=bl+1;x!=br;++x)
			t=_mm256_add_epi16(v[x],t);
		short*w=(short*)(&t);
		for(int j=0;j<16;++j) su+=w[j];
	}
	return su;
}
int sz[SZ],son[SZ],dep[SZ];
void dfs(int x,int f=0)
{
	sz[x]=1; dep[x]=dep[f]+1;
	for esb(x,e,b) if(b!=f)
	{
		dfs(b,x); sz[x]+=sz[b];
		if(sz[b]>sz[son[x]]) son[x]=b;
	}
}
int dfn[SZ],ed[SZ],top[SZ],D=0,fa[SZ];
void dfs2(int x,int t,int f=0)
{
	dfn[x]=++D; top[x]=t; fa[x]=f;
	if(son[x]) dfs2(son[x],t,x);
	for esb(x,e,b) if(b!=son[x]&&b!=f) dfs2(b,b,x);
	ed[x]=D;
}
vector<pii> lk(int a,int b)
{
	vector<pii> v;
	while(top[a]!=top[b])
	{
		if(dep[top[a]]>dep[top[b]]) swap(a,b);
		v.pb(pii(dfn[top[b]],dfn[b])),b=fa[top[b]];
	}
	if(dep[a]>dep[b]) swap(a,b);
	v.pb(pii(dfn[a],dfn[b]));
	return v;
}
int bs[SZ];
void reset()
{
	for(int i=0,j=0;j<=n;++i,j+=16)
	{
		ou(i);
		for(int k=0;k<16;++k)
		{
			int v=bs[j+k]+a[k];
			a[k]=min(max(v,-16000),16000);
			bs[j+k]=v-a[k];
		}
		in(i);
	}
}
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
#define BUFSIZE 500000
namespace fob {char b[BUFSIZE]={},*f=b,*g=b+BUFSIZE-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce {~foce() {pob; fflush(stdout);}} _foce;
namespace ib {char b[100];}
inline void pint(int x)
{
    if(x==0) {pc(48); return;}
    //if(x<0) {pc('-'); x=-x;} //如果有负数就加上 
    char *s=ib::b;
    while(x) *(++s)=x%10, x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}
int main()
{
	memset(&o,0,sizeof o);
	{
	short*p=(short*)(&lm);
	for(int j=0;j<16;++j) p[j]=1;
	}
	n=gi,m=gi,T=gi;
	for(int i=1;i<n;++i) adde(gi,gi);
	dfs(1); dfs2(1,1);
	for(int i=1;i<=n;++i) g[dfn[i]]=gi;
	for(int i=0,j=0;j<=n;++i,j+=16)
	{
		for(int k=0;k<16;++k)
		{
			int v=g[j+k];
			a[k]=min(max(v,-16000),16000);
			bs[j+k]=v-a[k]; b[k]=v>0;
		}
		in(i);
	}
	int la=0;
	for(int i=1;i<=m;++i)
	{
		if(i%15800==0) reset();
		int o=gi,x[3];
		for(int i=0;i<4-o;++i) x[i]=gi;
		x[0]^=la*T; x[1]^=la*T;
		if(o==1)
		{
			auto w=lk(x[0],x[1]);
			if(x[2]==1)
			{
				for(auto g:w)
					edt1(g.fi,g.se);
			}
			else
			{
				for(auto g:w)
					edtm1(g.fi,g.se);
			}
		}
		else if(o==2)
		{
			la=0;
			auto w=lk(x[0],x[1]);
			for(auto g:w)
				la+=qry(g.fi,g.se);
			pint(la); pc(10);
		}
		else
			pint(la=qry(dfn[x[0]],ed[x[0]])), pc(10);
	}
}
