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
const ld PI=acos(-1);
int n;
struct cir
{
ld x,y,r;
ld f(ld a)
{return r*(r*a+x*sin(a)-y*cos(a));}
}p[SZ];
bool operator == (cir a,cir b)
{
	return a.x==b.x&&a.y==b.y&&a.r==b.r;
}
const ld eps=1e-10;
ld py(ld x)
{
	while(x<0) x+=PI+PI;
	while(x>=PI+PI) x-=PI+PI;
	return x;
}
map<pair<ld,ld>,bool> odt[SZ];
const pair<ld,ld> FULL(-4,-4),EMP(-2,-2);
ld sqr(ld x) {return x*x;}
pair<ld,ld> jc(cir a,cir b)
{
	ld d=sqrt(sqr(a.x-b.x)
	+sqr(a.y-b.y));
	if(a.r+d<=b.r+eps) return FULL;
	if(b.r+d<=a.r+eps||d>=a.r+b.r-eps) return EMP;
	ld u=acos((sqr(a.r)+sqr(d)-sqr(b.r))/(2*a.r*d));
	ld l=atan2(b.y-a.y,b.x-a.x),r=l+u; l-=u;
	return mp(py(l),py(r));
}
ld s[SZ];
void spl(int a,ld t)
{
	auto w=odt[a].lower_bound(mp(t,1e9)); --w;
	if(w->fi.fi==t) return;
	auto r=*w; odt[a].erase(w);
	odt[a][mp(r.fi.fi,t)]=r.se;
	odt[a][mp(t,r.fi.se)]=r.se;
}
void cov(int a,ld l,ld r)
{
	spl(a,l); spl(a,r);
//	cout<<a<<" "<<l<<","<<r<<"\n";
//	for(auto g:odt[a]) cout<<g.fi.fi<<"~"<<g.fi.se<<"w"<<g.se<<" ";cout<<"\n";
	for(auto w=odt[a].lower_bound(mp(l,-1));
	w->fi.fi<r;odt[a].erase(w++))
		if(w->se)
			s[a]+=p[a].f(w->fi.fi),
			s[a]-=p[a].f(w->fi.se);
	odt[a][mp(l,r)]=0;
//	for(auto g:odt[a]) cout<<g.fi.fi<<"~"<<g.fi.se<<"w"<<g.se<<" ";cout<<"\n";
}
void cons(int a,int b)
{
	//cout<<a<<"-"<<b<<"\n";
	if(s[a]==0) return;
	auto w=jc(p[a],p[b]);
	if(w==EMP) return;
	if(w==FULL) {s[a]=0; odt[a].clear();
	odt[a][pii(-1,8)]=0; return;}
	//cout<<a<<"<="<<b<<":"<<w.fi<<","<<w.se<<"\n";
	if(w.fi<=w.se) cov(a,w.fi,w.se);
	else cov(a,w.fi,PI+PI),cov(a,0,w.se);
}
bool ban[SZ];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].r),
		s[i]=PI*p[i].r*p[i].r*2,
		odt[i][pii(-1,8)]=1;
	//	cout<<s[i]<<" "<<p[i].f(PI+PI)-p[i].f(0)<<"?\n";
	}
	ld la=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)
			ban[i]|=p[i]==p[j];
		for(int j=1;j<i;++j)
			if(!ban[j]&&!ban[i]) cons(j,i),cons(i,j);
		la=0;
		for(int j=1;j<=i;++j)
			if(!ban[j]) la+=s[j];
		printf("%.10lf\n",la/2);
	}
}
int main()
{
	int _;scanf("%d",&_);sol();
}

