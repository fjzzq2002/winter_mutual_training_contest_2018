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
#define SZ 888888
int n,m,x[SZ],y[SZ]; ld l[SZ],q[SZ],C,D;
ld ts[SZ]; int tn=0;
pair<ld,ld> A[SZ],B[SZ];
pair<ld,ld> gf(pair<ld,ld> t)
{
	ld l=sqrtl(t.fi*t.fi+t.se*t.se);
	t.fi/=l; t.se/=l; return t;
}
pair<ld,ld> operator + (pair<ld,ld> a,pair<ld,ld> b)
{return mp(a.fi+b.fi,a.se+b.se);}
pair<ld,ld> operator - (pair<ld,ld> a,pair<ld,ld> b)
{return mp(a.fi-b.fi,a.se-b.se);}
pair<ld,ld> operator * (pair<ld,ld> a,ld b)
{return mp(a.fi*b,a.se*b);}
ld len(pair<ld,ld> t)
{return sqrtl(t.fi*t.fi+t.se*t.se);}
pair<ld,ld> ps[SZ]; int pn=0;
#define ws wss
ld ws[SZ]; int wn=0,f[SZ]; bool os[SZ];
bool ok(ld t)
{
	pn=wn=0;
	for(int i=1;i<tn;++i)
	{
		if(ts[i]==ts[i+1]) continue;
		pair<ld,ld> a=A[i],b=B[i];
		ld u=len(b);
		if(!u)
		{
			if(len(a)>t) continue;
			ps[++pn]=mp(ts[i],ts[i+1]);
			continue;
		}
		ld R=(ts[i+1]-ts[i])*u;
		b.fi/=u; b.se/=u;
		ld x=-(a.fi*b.fi+a.se*b.se);
		ld L=len(a+b*x);
		if(L>t) continue;
		ld S=sqrt(t*t-L*L);
		ld A=x-S,B=x+S;
		A=max(A,(ld)0); B=min(B,R);
		if(A<=B)
			ps[++pn]=mp(A/u+ts[i],B/u+ts[i]);
	}
	if(!pn) ps[++pn]=mp(0,0);
	ps[pn+1]=mp(ps[1].fi+C,ps[1].se+C);
	int B=0;
	vector<pair<ld,int> > ms;
	ms.pb(mp(0,0));
	ld G=0;
	for(int i=1;i<=pn;++i)
	{
		ld L=ps[i].se,R=ps[i+1].fi;
		if(L>=R) continue;
		if(R-L>=D) return 0;
		while(G+D<=L) G+=D;
		ld l=L-G;
		while(G+D<=R) G+=D;
		ld r=R-G;
		if(l<=r) ms.pb(mp(l,1)),ms.pb(mp(r,-1));
		else ms.pb(mp(l,1)),ms.pb(mp(r,-1)),++B;
	}
	sort(ms.begin(),ms.end());
	for(int i=0;i<ms.size();++i)
	{
		B+=ms[i].se;
		if(i+1!=ms.size()&&ms[i+1].fi==ms[i].fi) continue;
		if(!B) return 1;
	}
	return 0;
}
int sqr(int x) {return x*x;}
int g(int x)
{
	if(x<=n) return x;
	return x-n;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;++i)
		l[i]=sqrt(sqr(x[i]-x[i%n+1])
		+sqr(y[i]-y[i%n+1])),
		q[i]=q[i-1]+l[i];
	C=q[n]; D=C/m;
	for(int i=n+1;i<=n+n;++i)
		q[i]=q[i-1]+l[i-n];
	for(int i=0;i<n;++i)
		ts[++tn]=q[i];
	for(int i=1;i<=n;++i)
	{
		ld w=q[i]-D;
		if(w>=0) ts[++tn]=w;
		w=q[i]+C-D;
		if(w<C) ts[++tn]=w;
	}
	ts[++tn]=C;
	sort(ts+1,ts+1+tn);
	int S=0,T=0;
	for(int i=1;i<tn;++i)
	{
		if(ts[i]==ts[i+1]) continue;
		//q[S],q[S+1]
		while(q[S+1]<=(ts[i]+ts[i+1])/2) ++S;
		while(q[T+1]<=(ts[i]+ts[i+1])/2+D) ++T;
		pair<ld,ld> g1(x[g(S+2)]-x[g(S+1)],y[g(S+2)]-y[g(S+1)]),
		g2(x[g(T+2)]-x[g(T+1)],y[g(T+2)]-y[g(T+1)]);
		g1=gf(g1); g2=gf(g2);
		pair<ld,ld> s(x[g(S+1)]-x[g(T+1)],y[g(S+1)]-y[g(T+1)]);
		s=s+g1*(ts[i]-q[S]); s=s+g2*(q[T]-ts[i]-D);
		A[i]=s; B[i]=g1-g2;
	}
	ld l=0,r=1e4;
	while(r-l>1e-7)
	{
		ld m=(l+r)/2;
		if(ok(m)) r=m; else l=m;
	}
	printf("%.10lf\n",l);
}
