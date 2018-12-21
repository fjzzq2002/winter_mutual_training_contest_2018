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
inline ll qp(ll a,ll b)
{
    ll ans=1; a%=MOD;
    while(b)
    {
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return ans;
}
ll F(ll p,ll q,ll k)
{
	ll su=0,cw=0,aa=0,po=1,
	ip=qp(p,MOD-2),s=qp(p,q);
	for(int i=0;i<=q;++i)
	{
		ll u=s;
		if(q-i)
			s=s*ip%MOD,u-=s;
		(su+=u)%=MOD;
		ll cu=qp(su,k);
		(cu-=cw)%=MOD;
		aa=(aa+cu*po)%MOD;
		po=po*p%MOD;
		(cw+=cu)%=MOD;
	}
	return aa;
}
ll F(ll p,ll k)
{
	ll A=qp(p-1,k);
	return (A+qp(p,k+1)-p*A)%MOD;
}
ll n,k;
namespace Sol1
{
ll C[555][555];
#define SS 233333
struct info
{
ll f;
vector<ll> su;
void gf()
{
	ll A=0,B=su[k+1],C=0;
	for(int i=0;i<=k;++i)
	{
		ll p=su[i]*Sol1::C[k][i]%MOD,
		q=su[i+1]*Sol1::C[k][i]%MOD;
		if((k-i)&1) p=-p; else q=-q;
		(A+=p)%=MOD; (C+=q)%=MOD;
	}
	f=(A+B+C)%MOD;
}
}c[SS],b[SS];
info operator * (info a,const info& b)
{
	for(int i=0;i<=k+1;++i)
		a.su[i]=a.su[i]*b.su[i]%MOD;
	return a;
}
info operator - (info a,const info& b)
{
	for(int i=0;i<=k+1;++i)
		a.su[i]=(a.su[i]-b.su[i])%MOD;
	return a;
}
int S,ps[SS],pn=0;
inline ll ff(ll x,int g)
{
    if(x<=1||ps[g]>x) return 0;
    ll ans=((x>S)?b[n/x].f:c[x].f)-c[ps[g-1]].f;
    for(int j=g;j<=pn&&ps[j]*(ll)ps[j]<=x;++j)
    {
        ll cn=x/ps[j],ce=ps[j]*(ll)ps[j];
        for(int e=1;cn>=ps[j];++e,cn/=ps[j],ce*=ps[j])
            ans+=ff(cn,j+1)*F(ps[j],e,k)+F(ps[j],e+1,k),ans%=MOD;
    }
    return ans%MOD;
}
namespace Newton {
ll y[23333],g[23333]; int N;
void work()
{
	ll ii=1;
	for(int i=1;i<=N;++i) y[i]=(y[i]%MOD+MOD)%MOD;
	for(int i=1;i<=N;++i)
	{ 
		g[i]=y[1]*ii%MOD;
		ii=ii*qp(i,MOD-2)%MOD;
		for(int j=1;j<=N-i;++j)
		{
			y[j]=y[j+1]-y[j];
			if(y[j]<0) y[j]+=MOD;
		}
		y[N-i+1]=0;
	}
}
ll calc(ll x)
{
	ll w=1,a=0;
	for(int i=1;i<=N;++i)
		a=(a+w*g[i])%MOD,w=w*(x-i)%MOD;
	return a;
}
}
void work()
{
	for(int i=0;i<=k;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	S=sqrtl(n);
    for(int j=0;j<=k+1;++j)
    {
    	using Newton::N;
    	ll sb=0; N=j+2;
	    for(int i=1;i<=N;++i)
	    	(sb+=qp(i,j))%=MOD,Newton::y[i]=sb;
	    Newton::work();
	    for(int i=1;i<=S;++i)
	    	b[i].su.pb(Newton::calc(n/i%MOD)),
	    	c[i].su.pb(Newton::calc(i));
	}
    for(int i=2;i<=S;++i)
    {
        if(c[i].su[0]==c[i-1].su[0]) continue;
        info cc=c[i-1],ii;
		ii.su.resize(k+1); ii.su[0]=1;
        for(int j=1;j<=k;++j)
        	ii.su[j]=ii.su[j-1]*i%MOD;
		ps[++pn]=i; ll r=i*(ll)i;
        int u=min((ll)S,n/(i*(ll)i)),uu=min(u,S/i);
        for(int j=1;j<=uu;++j)
            b[j]=b[j]-(b[j*i]-cc)*ii;
        ll t=n/i;
        for(int j=uu+1;j<=u;++j)
            b[j]=b[j]-(c[t/j]-cc)*ii;
        for(int j=S;j>=r;--j)
            c[j]=c[j]-(c[j/i]-cc)*ii;
    }
    for(int i=1;i<=S;++i)
    	b[i].gf(),c[i].gf();
    ps[pn+1]=S+1;
    ll ans=ff(n,1);
    ans=(ans%MOD+MOD)%MOD;
    printf("%d\n",int(ans));
}
}
namespace Sol2
{
#define S 4000005
int sp[S];
ll f[S];
void work()
{
	f[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!sp[i])
		{
			f[i]=F(i,k);
			for(int j=1;i*j<S;++j)
				sp[i*j]=i;
			continue;
		}
		int g=0,h=i,w=1;
		while(h%sp[i]==0) h/=sp[i],++g,w*=sp[i];
		if(h==1)
			f[i]=F(sp[i],g,k);
		else
			f[i]=f[h]*f[w]%MOD;
	}
	ll su=0;
	for(int i=1;i<=n;++i)
		(su+=f[i])%=MOD;
	su=(su%MOD+MOD)%MOD;
	cout<<su<<"\n";
}
}
int main()
{
	cin>>n>>k;
	if(k<=300)
	{
		Sol1::work();
		return 0;
	}
	Sol2::work();
}

