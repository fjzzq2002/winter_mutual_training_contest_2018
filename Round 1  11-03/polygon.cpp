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
typedef long long ll;//__int128 ll;
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
const int MOD=1e9+9;
//orz min25 
template<class T>
T mod_inv(T a,T m)
{
	T b=m,s=1,t=0;
	while(b)
		swap(s-=t*(a/b),t),swap(a%=b,b);
	return (s+m)%m;
}
int N;
struct mat
{
int a[9][9];
void inp()
{
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			scanf("%d",&a[i][j]);
}
inline int* operator[] (int x) {return a[x];}
void initI()
{
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			a[i][j]=(i==j);
}
void initO()
{
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			a[i][j]=0;
}
void prt()
{
	for(int i=1;i<=N;++i,puts(""))
		for(int j=1;j<=N;++j)
			printf("%d ",(a[i][j]%MOD+MOD)%MOD);
}
}S;
inline mat operator * (const mat& a,const mat& b)
{
	mat x;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			#define pg(g) a.a[i][1+g]*(ll)b.a[1+g][j]
			x[i][j]=(pg(0)+pg(1)+pg(2)+pg(3)
			+pg(4)+pg(5)+pg(6)+pg(7))%MOD;
			#undef pg
		}
	return x;
}
inline mat operator + (mat a,const mat& b)
{
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			a[i][j]=(a[i][j]+b.a[i][j])%MOD;
	return a;
}
inline mat operator - (mat a,const mat& b)
{
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			a[i][j]=(a[i][j]-b.a[i][j])%MOD;
	return a;
}
mat qp(mat a,ll b)
{
	mat X; X.initI();
	while(b)
	{
		if(b&1) X=X*a;
		a=a*a; b>>=1;
	}
	return X;
}
namespace Euclid
{
mat I,O,Y;
ll A,B,C,L;
typedef __int128 bi;
bi s,t;
const ll inf=2.01e18;
struct cs
{
ll c0,c1;mat ans,sy;
cs() {c0=c1=0; ans=O; sy=I;}
cs(int t)
{
	c0=(t==0),c1=(t==1);
	if(t==0) ans=I,sy=I;
	else ans=O,sy=Y;
}
};
cs operator + (cs a,cs b)
{
	cs c;
	c.c0=min(a.c0+b.c0,inf);
	c.c1=min(a.c1+b.c1,inf);
	c.sy=a.sy*b.sy;
	c.ans=a.ans+b.ans*a.sy;
	return c;
}
cs operator * (cs a,bi x)
{
	cs g;
	while(x)
	{
		if(x&1) g=g+a;
		a=a+a; x>>=1;
	}
	return g;
}
vector<pair<int,ll> > ch[233];
cs ns[233]; int cn=0;
void prt(int x)
{
	if(!ch[x].size())
	{
		if(ns[x].c0) putchar('0');
		else putchar('1');
		return;
	}
	for(auto&t:ch[x])
		for(int g=0;g<t.se;++g) prt(t.fi);
}
int decomp(ll a,ll b)
{
	++cn; ns[cn]=cs(0);
	++cn; ns[cn]=cs(1);
	bool fl=0; pii t(cn-1,cn);
	while(a!=b)
	{
		if(a<b)
			swap(a,b),swap(t.fi,t.se),fl=!fl;
		else
		{
			ll d=(a-1)/b;
			++cn; ch[cn].pb(mp(t.se,d));
			ch[cn].pb(mp(t.fi,1));
			ns[cn]=ns[t.se]*d+ns[t.fi];
			t.fi=cn; a-=b*d;
		}
	}
	if(fl) swap(t.fi,t.se);
	++cn; ch[cn].pb(mp(t.se,1));
	ch[cn].pb(mp(t.fi,1));
	ns[cn]=ns[t.se]+ns[t.fi];
	return cn;
}
cs calc(int x,ll l,ll r,int de=0)
{
	if(l>=r) return cs();
	if(!ch[x].size())
		return (l==1)?cs():ns[x];
	if(r<=ns[ch[x][0].fi].c0*(bi)ch[x][0].se)
	{
		ll p0=ns[ch[x][0].fi].c0;
		if(l==0)
			return ns[ch[x][0].fi]*(r/p0)
			+calc(ch[x][0].fi,0,r%p0,de+1);
		if(l%p0==0)
			return calc(ch[x][0].fi,p0,p0+1,de+1)
			+ns[ch[x][0].fi]*(r/p0-l/p0)
			+calc(ch[x][0].fi,0,r%p0,de+1);
		if(l/p0==r/p0)
			return calc(ch[x][0].fi,l%p0,r%p0,de+1);
		return calc(ch[x][0].fi,l%p0,p0+1,de+1)
		+ns[ch[x][0].fi]*(r/p0-l/p0-1)
		+calc(ch[x][0].fi,0,r%p0,de+1);
	}
	ll L0=ns[ch[x][0].fi].c0*ch[x][0].se;
	if(l<=L0)
	{
		if(l==0) return ns[ch[x][0].fi]*ch[x][0].se
		+calc(ch[x][1].fi,0,r-L0,de+1);
		ll p0=ns[ch[x][0].fi].c0;
		return calc(ch[x][0].fi,(l%p0)?(l%p0):p0,p0+1,de+1)
			+ns[ch[x][0].fi]*(ch[x][0].se-l/p0-(l%p0!=0))
			+calc(ch[x][1].fi,0,r-L0,de+1);
	}
	return calc(ch[x][1].fi,l-L0,r-L0);
}
mat work()
{
	if(A<0||C<0||B<=0)throw "GG";
	if(A==0)
	{
		mat w=qp(Y,C/B);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				w.a[i][j]=w.a[i][j]*(L%MOD)%MOD;
		return w;
	}
	I.initI(); O.initO();
	if(L<=0) return O;
	ll g=__gcd(A,B); A/=g; B/=g; C/=g;
	s=C*(bi)mod_inv((bi)A,(bi)B)%B; t=(A*s-C)/B;
	cn=0; int tt=decomp(A,B),uu=++cn;
	ch[uu].pb(mp(tt,inf));
	ch[uu].pb(mp(tt,1));
	cs aa=calc(uu,s,s+L),u=cs(1)*(A*(bi)s/B-t); aa=u+aa;
	mat ans=aa.ans-u.ans;
	for(int i=1;i<=cn;++i)
		ch[i].clear(),ns[i]=cs();
	return ans;
}
}
ll dv(ll a,ll b)
{
	if(b<0) a=-a,b=-b;
	ll t=a/b-1;
	while((t+1)*b<=a) ++t;
	return t;
}
#define SZ 666666
int a,b,c,d,n,f[4]; pii t[SZ],x[SZ],y[SZ];
ll qzh(ll l,ll r,ll a,ll b,ll c,int k)
{
	if(l>r) return 0;
	a+=c; b+=a*(l-1)+c;
	if(a<0)
		b+=a*(r-l+2),a=-a;
	if(a+b<0) throw "GG";
	Euclid::A=a; Euclid::C=b; Euclid::B=c;
	Euclid::L=r-l+1; Euclid::Y=S;
	mat P; P.initO();
	//if(b<0)
	{
		ll w=dv(a+b,c);
		P=P+qp(S,w);
		Euclid::C+=Euclid::A;
		--Euclid::L;
	}
	P=P+Euclid::work(); ll ss=0;
	for(int j=1;j<=4;++j)
		ss+=f[j-1]*(ll)P.a[j][5],ss%=MOD;
	return ss;
}
//(A*x+B)/C
void gl(pii a,pii b,ll&A,ll&B,ll&C)
{
	A=a.se-b.se;
	C=a.fi-b.fi;
	B=a.se*C-A*a.fi;
}
void sol()
{
	scanf("%d%d%d%d%d%d%d%d%d",&n,&a,&b,&c,&d,f,f+1,f+2,f+3);
	N=8; S.initO();
	S.a[1][4]=d;
	S.a[2][4]=c;
	S.a[3][4]=b;
	S.a[4][4]=a;
	S.a[2][1]=S.a[3][2]=S.a[4][3]=1;
	for(int i=1;i<=4;++i)
		S.a[i][i+4]=S.a[i+4][i+4]=1;
	for(int i=0;i<n;++i)
		scanf("%d%d",&t[i].fi,&t[i].se);
	ll ans=0;
	for(int i=0;i<n;++i)
	{
		int up=0;
		for(int j=0;j<n;++j)
		{
			pii a=t[j],b=t[(j+1)%n];
			if(a==t[i]||b==t[i]) continue;
			if(a.fi<b.fi) swap(a,b);
			int x=t[i].fi,y=t[i].se;
			if(a.fi>x&&x>=b.fi&&(ll)(y-b.se)
			*(a.fi-b.fi)<=(ll)(a.se-b.se)*(x-b.fi))
				up^=1;
		}
		if(t[(i+n-1)%n].fi<t[i].fi&&t[(i+1)%n].fi<t[i].fi&&!up)
			ans+=qzh(t[i].fi,t[i].fi,0,t[i].se,1,1)
			-qzh(t[i].fi,t[i].fi,0,t[i].se-1,1,-1);
		if(t[(i+n-1)%n].fi>t[i].fi&&t[(i+1)%n].fi>t[i].fi&&up)
			ans+=-qzh(t[i].fi,t[i].fi,0,t[i].se,1,-1)
			+qzh(t[i].fi,t[i].fi,0,t[i].se-1,1,1);
	}
	for(int i=0;i<n;++i)
	{
		x[i]=t[i],y[i]=t[(i+1)%n];
		if(x[i].fi==y[i].fi)
		{
			if(x[i].se>y[i].se)
				continue;
			ans+=qzh(x[i].fi,x[i].fi,0,y[i].se-(t[(i+2)%n].fi>y[i].fi),1,1);
			ans-=qzh(x[i].fi,x[i].fi,0,x[i].se-(t[(i+n-1)%n].fi<y[i].fi),1,-1);
		}
		ll A,B,C;
		gl(x[i],y[i],A,B,C);
		if(C<0) A=-A,B=-B,C=-C;
		if(x[i].fi>y[i].fi)
			ans+=qzh(min(x[i].fi,y[i].fi),
			max(x[i].fi,y[i].fi)-1,A,B,C,1);
		else
		{
			A*=2; B*=2; C*=2; --B;
			ans-=qzh(min(x[i].fi,y[i].fi),
			max(x[i].fi,y[i].fi)-1,A,B,C,-1);
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) sol();
}

