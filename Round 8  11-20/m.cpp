#pragma GCC optimize("-Ofast","-funroll-all-loops")
#pragma GCC target("avx","sse","sse2")
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
int t,m,q,a[12],u[12],n,T;
int cb[3005][3005],wq[3005][13],hb[3005],gg[13][3005],
mi[3005][3005],mu[3005][3005];
struct linear
{
int w[12],g[12],t;
void clr()
{
	memset(w,0,sizeof w);
	memset(g,0,sizeof g);
	t=::t;
}
void ins(int x)
{
	for(int i=t-1;i>=0&&x;--i) if(wq[x][i])
	{
		if(w[i])
		{
			if(wq[x][i]%g[i])
				g[i]=gg[i][wq[x][i]],swap(w[i],x);
			x=cb[x][w[i]];
		}
		else
		{
			for(int p=0;p<i;++p)
				x=cb[x][w[p]];
			for(int p=i+1;p<t;++p)
				w[p]=cb[w[p]][x];
			w[i]=x; g[i]=gg[i][wq[x][i]];
			break;
		}
	}
}
};
int calc(linear x)
{
	int u=1;
	for(int i=t-1;i>=0;--i)
	{
		if(x.w[i])
		{
			u*=a[i]/x.g[i]; int w=0;
			for(int j=t-1;j>=0;--j)
				w=w*a[j]+(wq[x.w[i]][j]*(a[i]/x.g[i]))%a[j];
			x.t=i; x.ins(w);
		}
	}
	return u;
}
int cbi(linear a,linear b)
{
	for(int i=t-1;i>=0;--i)
		if(b.w[i]) a.ins(b.w[i]);
	return calc(a);
}
int v[SZ],L[SZ],R[SZ],aa[SZ];
linear as[SZ],bs[SZ];
void fz(int l,int r,vector<int>& s)
{
	if(l>=r) return;
	vector<int> a,b;
	int m=(l+r)>>1;
	as[m+1].clr();
	for(int i=m;i>=l;--i)
		as[i]=as[i+1],as[i].ins(v[i]);
	bs[m].clr();
	for(int i=m+1;i<=r;++i)
		bs[i]=bs[i-1],bs[i].ins(v[i]);
	a.reserve(s.size());
	b.reserve(s.size());
	for(auto t:s)
	{
		if(R[t]<=m) a.pb(t);
		else if(L[t]>m) b.pb(t);
		else aa[t]=cbi(as[L[t]],bs[R[t]]);
	}
	fz(l,m,a); fz(m+1,r,b);
}
vector<int> so[3333];
vector<vector<int> > sb[3333];
int ds[3333],mk[3333];
void dfs(int x,int g,int s)
{
	if(g>=so[x].size())
	{
		vector<int> v;
		for(int i=0;i<g;++i)
			v.pb(ds[i]);
		sb[x][s]=v; return;
	}
	for(int j=0;j<so[x][g];++j)
		ds[g]=j,dfs(x,g+1,(s+j*(u[x]/so[x][g]))%u[x]);
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
#define BUFSIZE 500000
namespace fob {char b[BUFSIZE]={},*f=b,*g=b+BUFSIZE-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce {~foce() {pob; fflush(stdout);}} _foce;
namespace ib {char b[100];}
inline void pint(int x)
{
    if(x==0) {pc(48); return;}
    char *s=ib::b;
    while(x) *(++s)=x%10, x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}
#define gi FF::F()
inline void dd(int d,int x,int y,int p)
{
	if(d<0)
	{
		mi[x][y]=p; return;
	}
	for(int A=0;A<a[d];++A)
		for(int B=0;B<a[d];++B)
			dd(d-1,x*a[d]+A,y*a[d]+B,
			p*a[d]+(A+a[d]-B)%a[d]);
}
int U;
inline void dd(int d,int x,int p)
{
	if(d<0)
	{
		mu[x][U]=p; return;
	}
	for(int A=0;A<a[d];++A)
		dd(d-1,x*a[d]+A,p*a[d]+A*U%a[d]);
}
int main()
{
	T=gi,m=gi,q=gi; n=1;
	for(int i=0;i<T;++i)
	{
		u[i]=gi,n*=u[i];
		int x=u[i];
		for(int j=2;j<=x;++j) if(x%j==0)
		{
			int c=0,k=1;
			while(x%j==0) ++c,k*=j,x/=j;
			so[i].pb(k); a[t++]=k;
		}
		sb[i].resize(u[i]);
		dfs(i,0,0);
	}
	for(int i=0;i<n;++i)
		U=i,dd(t-1,0,0);
	for(int i=0;i<n;++i)
	{
		int j=i;
		for(int k=0;k<t;++k)
		{
			wq[i][k]=j%a[k];
			gg[k][i]=__gcd(a[k],i);
			if(j%a[k]) hb[i]=k;
			j/=a[k];
		}
	}
	dd(t-1,0,0,0);
	for(int j=1;j<n;++j)
	{
		int w=hb[j],g=__gcd(a[w],wq[j][w]);
		for(int x=a[w]-1;x>=0;--x)
			mk[wq[j][w]*x%a[w]]=x;
		for(int i=1;i<n;++i)
			if(wq[i][w]%g) cb[i][j]=i;
			else cb[i][j]=mi[i][mu[j][mk[wq[i][w]]]];
	}
	for(int i=1;i<n;++i) cb[i][0]=i;
	for(int i=1;i<=m;++i)
	{
		v[i]=gi,--v[i];
		static int ts[30],os[30];
		int N=n,on=0;
		for(int j=0;j<T;++j)
			N/=u[j],ts[j]=v[i]/N,v[i]%=N;
		for(int j=0;j<T;++j)
			for(auto w:sb[j][ts[j]])
				os[on++]=w;
		for(int j=on-1;j>=0;--j)
			v[i]=v[i]*a[j]+os[j];
	}
	vector<int> ve;
	for(int i=1;i<=q;++i)
	{
		L[i]=gi,R[i]=gi;
		linear t; t.clr();
		if(L[i]==R[i])
			t.ins(v[L[i]]),aa[i]=calc(t);
		else ve.pb(i);
	}
	fz(1,m,ve);
	for(int i=1;i<=q;++i)
		pint(aa[i]),pc(10);
}
