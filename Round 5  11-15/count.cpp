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
int n,k;
typedef pair<int,int> pii;
typedef long long ll;
#define SZ 666666
const int MOD=998244353;
inline ll qp(ll a,ll b)
{
	ll x=1;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
#define S 524288
ll w[2][S+2],inv[SZ];
void fftinit()
{
	ll g=qp(3,(MOD-1)/S);
	w[0][0]=1;
	for(int i=1;i<=S;++i)
		w[0][i]=w[0][i-1]*g%MOD;
	for(int i=0;i<=S;++i)
		w[1][i]=w[0][S-i];
}
inline int getK_(int n)
{
	int K=2;
	while(K<n) K<<=1;
	return K;
}
inline int getK(int n)
{return getK_(n+2);}
void fft(int*g,int K,int o)
{
	for(int i=0;i<K;++i) g[i]=(g[i]%MOD+MOD)%MOD;
	for(int i=0;i<K;++i)
	{
		int s=0,j=i;
		for(int r=1;r<K;r<<=1)
			s=(s<<1)|(j&1),j>>=1;
		if(i<s) swap(g[i],g[s]);
	}
	ll*s=w[o];
	for(int i=2;i<=K;i<<=1)
	{
		int t=S/i;
		for(int j=0;j<K;j+=i)
		{
			ll*R=s; int*A=g+j,*B=g+j+(i>>1);
			for(int r=0;r<(i>>1);++r,R+=t,++A,++B)
			{
				int t=(*B)*(*R)%MOD;
				*B=(*A-t<0)?(*A-t+MOD):(*A-t);
				*A=(*A+t>=MOD)?(*A+t-MOD):(*A+t);
			}
		}
	}
	if(!o) return;
	ll rv=qp(K,MOD-2);
	for(int i=0;i<K;++i) g[i]=g[i]*rv%MOD;
}
inline void ginv(const int*x,int*t,int K)
{
	static int tmp[SZ];
	if(K==1) {t[0]=qp(x[0],MOD-2);return;}
	ginv(x,t,K>>1); memcpy(tmp,x,sizeof(int)*K);
	memset(tmp+K,0,sizeof(int)*K);
	fft(tmp,K+K,0); fft(t,K+K,0);
	for(int i=0;i<K+K;++i)
		t[i]=(t[i]*((2LL-t[i]*(ll)tmp[i])%MOD)%MOD+MOD)%MOD;
	fft(t,K+K,1); memset(t+K,0,sizeof(int)*K);
}
vector<int> ginv(vector<int> v,int q)
{
	static int x[SZ],y[SZ];
	int K=getK_(max((int)v.size(),q));
	for(int i=0;i<K;++i) x[i]=y[i]=0;
	for(int i=0;i<int(v.size());++i) x[i]=v[i];
	ginv(x,y,K); vector<int> g;
	for(int i=0;i<q;++i) g.pb(y[i]); return g;
}
vector<int> conv(vector<int> a,vector<int> b)
{
	static int x[SZ],y[SZ];
	int K=getK_(a.size()+b.size());
	for(int i=0;i<K;++i) x[i]=y[i]=0;
	for(int i=0;i<int(a.size());++i) x[i]=a[i];
	for(int i=0;i<int(b.size());++i) y[i]=b[i];
	fft(x,K,0); fft(y,K,0);
	for(int i=0;i<K;++i) x[i]=(ll)x[i]*y[i]%MOD;
	fft(x,K,1); vector<int> g;
	for(int i=0;i<int(a.size())+int(b.size())-1;++i)
		g.pb(x[i]); return g;
}
struct mat
{
ll t[2][2];
};
mat operator * (mat a,mat b)
{
	mat c;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			c.t[i][j]=(a.t[i][0]*b.t[0][j]
			+a.t[i][1]*b.t[1][j])%MOD;
	return c;
}
pair<ll,ll> calc(int x,ll t)
{
	mat X,A;
	A.t[0][0]=0;
	A.t[0][1]=-1;
	A.t[1][0]=x;
	A.t[1][1]=1;
	X.t[0][0]=X.t[1][1]=1;
	X.t[1][0]=X.t[0][1]=0;
	while(t)
	{
		if(t&1) X=X*A;
		A=A*A; t>>=1;
	}
	return mp((X.t[1][0])%MOD,
	(X.t[1][1])%MOD);
}
int a[SZ],b[SZ];
int main()
{
	scanf("%d%d",&n,&k);
	if(n<k)
	{
		puts("0");
		return 0;
	}
	++n; ++k;
	fftinit();
	int p=getK(n);
	for(int i=0;i<S;i+=S/p)
	{
		ll g=qp(3,(MOD-1)/S*i);
		auto w=calc(g,k);
		a[i/(S/p)]=w.fi;
		b[i/(S/p)]=w.se;
//		cout<<i<<",";
	}
	fft(a,p,1);
	fft(b,p,1);
	vector<int> A,B;
	for(int i=0;i<p;++i) A.pb(a[i]);
	for(int i=0;i<p;++i) B.pb(b[i]);
	A.resize(n+1); B.resize(n+1);
	A=conv(A,ginv(B,B.size()));
	ll ans=A[n];
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",(int)ans);
}
