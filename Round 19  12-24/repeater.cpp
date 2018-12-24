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
//BM没救了，还是直接算吧
const int MOD=19491001;
inline ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
ll fac[MOD],rfac[MOD];
ll C(int a,int b)
{
	if(b>a||b<0) return 0;
	if(a<MOD)
		return fac[a]*rfac[a-b]%MOD*rfac[b]%MOD;
	return C(a/MOD,b/MOD)*C(a%MOD,b%MOD)%MOD;
}
struct comp
{
ll a,b; //a+bi;
comp() {}
comp(ll x,ll y) :a(x),b(y) {}
}w[3];
inline comp operator + (comp a,comp b)
{return comp((a.a+b.a)%MOD,(a.b+b.b)%MOD);}
inline comp operator - (comp a,comp b)
{return comp((a.a-b.a)%MOD,(a.b-b.b)%MOD);}
inline comp operator * (comp a,comp b)
{return comp((a.a*b.a-a.b*b.b)%MOD,(a.a*b.b+a.b*b.a)%MOD);}
inline comp operator * (comp a,ll b)
{return comp(a.a*b%MOD,a.b*b%MOD);}
inline comp qp(comp a,ll b)
{
	comp x(1,0);
	while(b)
	{
		if(b&1) x=x*a;
		a=a*a; b>>=1;
	}
	return x;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<MOD;++i) fac[i]=fac[i-1]*i%MOD;
	rfac[MOD-1]=MOD-1;
	for(int i=MOD-1;i>=1;--i) rfac[i-1]=rfac[i]*i%MOD;
	w[1].a=-qp(2,MOD-2); w[1].b=38991/*sqrt(3)*/*qp(2,MOD-2)%MOD;
	w[0]=comp(1,0); w[2]=w[1]*w[1];
	int n,k,d;
	cin>>n>>k>>d;
	if(n%d)
	{
		puts("0");
		return 0;
	}
	if(d==1)
	{
		printf("%lld\n",qp(k,n));
		return 0;
	}
	if(d==2)
	{
		ll ans=0;
		for(int i=0;i<=k;++i)
			ans+=qp(i+i-k,n)*C(k,i),ans%=MOD;
		ans=ans*qp(qp(2,MOD-2),k)%MOD;
		ans=(ans%MOD+MOD)%MOD;
		cout<<ans<<"\n";
		return 0;
	}
	if(d==3)
	{
		ll ans=0;
		for(int i=0;i<=k;++i)
			for(int j=0;i+j<=k;++j)
				ans+=qp(w[0]*i+w[1]*j+w[2]*(k-i-j),n).a*C(k,i+j)%MOD*C(i+j,i),ans%=MOD;
		ans=ans*qp(qp(3,MOD-2),k)%MOD;
		ans=(ans%MOD+MOD)%MOD;
		cout<<ans<<"\n";
		return 0;
	}
}

