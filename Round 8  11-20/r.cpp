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
typedef pair<int,int> pii;
typedef long long ll;
#define SZ 1234567
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
ll inv[SZ];
inline int getK_(int n)
{
	int K=2;
	while(K<n) K<<=1;
	return K; 
}
inline int getK(int n)
{return getK_(n+2);}
const int P=MOD;
inline int fpow(int a,int t){
	int r=1;
	for(;t;t>>=1,a=(ll)a*a%P)if(t&1)r=(ll)r*a%P;
	return r;
}
int pol[SZ],*ed=pol;
int *ww[SZ],*iww[SZ],*_w;
int *nint(int len){int*R=ed;ed+=len;return R;}
void init(int n){
	ed=pol;
	for(int i=1,j=1;j<=n;i++,j<<=1){
		ww[i]=nint(j);iww[i]=nint(j);ww[i][0]=iww[i][0]=1;
		int w=fpow(3,P-1>>i),iw=fpow(w,P-2);
		for(int k=1;k<j;++k)
			ww[i][k]=(ll)ww[i][k-1]*w%P,iww[i][k]=(ll)iww[i][k-1]*iw%P;
	}
}
void fft(int a[],int n,int dft){
	int i,j,k,l,c=0,u,v;
	for(i=1,j=n>>1;i<n-1;i++){
		if(i<j)swap(a[i],a[j]);
		for(k=n>>1;(j^=k)<k;k>>=1);
	}
	for(i=0;i<n;++i)
		a[i]=(a[i]%P+P)%P;
	for(l=2,c=1;l<=n;l<<=1,c++){
		if(dft==1)_w=iww[c];else _w=ww[c];
		for(i=l>>1,j=0;j<n;j+=l)for(k=0;k<i;k++){
			u=a[j+k]%P,v=(ll)a[j+k+i]*_w[k]%P;
			a[j+k]=u+v,a[j+k+i]=u-v;
		}
	}
	if(dft==1)for(i=0;i<n;i++)a[i]=(ll)a[i]*inv[n]%P;
	for(i=0;i<n;++i)
		a[i]=(a[i]%P+P)%P;
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
inline void gexp(const int*x,int*t,int K)
{
	static int ls[SZ],xr[SZ],dx[SZ];
	if(K==1) {t[0]=1; return;}
	gexp(x,t,K>>1); memset(ls,0,sizeof(int)*(K+K)); ginv(t,ls,K);
	for(int i=1;i<K;++i) dx[i-1]=(ll)i*t[i]%MOD;
	memset(dx+K-1,0,sizeof(int)*(K+1));
	memcpy(xr,x,sizeof(int)*K); memset(xr+K,0,sizeof(int)*K);
	fft(dx,K+K,0); fft(ls,K+K,0);
	for(int i=0;i<K+K;++i) ls[i]=ls[i]*(ll)dx[i]%MOD;
	fft(ls,K+K,1); fft(xr,K+K,0); fft(t,K+K,0);
	for(int i=K-1;i>=1;--i) ls[i]=ls[i-1]*inv[i]%MOD;
	ls[0]=0; for(int j=K;j<K+K;++j) ls[j]=0; fft(ls,K+K,0);
	for(int i=0;i<K+K;++i) t[i]=t[i]*(1LL+MOD-ls[i]+xr[i])%MOD;
	fft(t,K+K,1); memset(t+K,0,sizeof(int)*K);
}
inline void gln(const int*x,int*t,int K)
{
	static int as[SZ],bs[SZ]; ginv(x,bs,K);
	for(int i=0;i<K+K;++i) as[i]=0;
	for(int i=K;i<K+K;++i) bs[i]=0;
	for(int i=0;i+1<K;++i) as[i]=x[i+1]*(ll)(i+1)%MOD;
	fft(as,K+K,0); fft(bs,K+K,0);
	for(int i=0;i<K+K;++i) as[i]=(ll)as[i]*bs[i]%MOD;
	fft(as,K+K,1); t[0]=0;
	for(int i=1;i<K;++i)
		t[i]=as[i-1]*(ll)inv[i]%MOD;
}
int x[SZ],y[SZ],n,m,t[SZ],r[SZ];
ll rfac[SZ],fac[SZ];
vector<int> ginv(const vector<int>& v,int q)
{
	static int x[SZ],y[SZ];
	int K=getK_(max((int)v.size(),q));
	for(int i=0;i<K;++i) x[i]=y[i]=0;
	for(int i=0;i<int(v.size());++i) x[i]=v[i];
	ginv(x,y,K); vector<int> g;
	for(int i=0;i<q;++i) g.pb(y[i]); return g;
}
vector<int> conv(const vector<int>& a,const vector<int>& b)
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
vector<int> gexp(vector<int> v)
{
	int K=getK_(v.size());
	static int p[SZ],q[SZ];
	for(int i=0;i<K;++i) p[i]=q[i]=0;
	for(int i=0;i<int(v.size());++i) p[i]=v[i];
	gexp(p,q,K); v.resize(K);
	for(int i=0;i<K;++i) v[i]=q[i];
	return v;
}
vector<int> strip(const vector<int>&v,int n)
{
	vector<int> p; p.resize(n);
	for(int i=0;i<n&&i<(int)v.size();++i) p[i]=v[i];
	return p;
}
vector<int> jf(vector<int> t)
{
	t.insert(t.begin(),0);
	for(int i=1;i<t.size();++i)
		t[i]=t[i]*(ll)rfac[i]%MOD*fac[i-1]%MOD;
	return t;
}
vector<int> A,C;
vector<int> calc(int k)
{
	if(k==1)
	{
		vector<int> v;
		v.resize(1);
		return v;
	}
	vector<int> F=calc((k+1)>>1);
	F.resize(k); vector<int> E=gexp(F);
	vector<int> cA=strip(A,k),cC=strip(C,k);
	vector<int> H=conv(cA,E);
	H.resize(k); vector<int> dH=H;
	for(int i=0;i<k;++i)
		H[i]=(H[i]+cC[i])%MOD;
	vector<int> v=jf(dH);
	for(auto&p:v) p=(MOD-p)%MOD;
	v=gexp(v);
	dH=conv(dH,F); dH.resize(k);
	for(int i=0;i<k;++i)
		dH[i]=(H[i]-dH[i])%MOD;
	dH=conv(dH,v); dH.resize(k);
	vector<int> iv=ginv(v,k);
	dH=conv(jf(dH),iv);
	dH.resize(k); return dH;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i) rfac[i-1]=rfac[i]*i%MOD;
	for(int i=1;i<SZ;++i) inv[i]=rfac[i]*fac[i-1]%MOD;
	init(262144); int aa,bb;
//	n=114514^(time(0)&1); aa=bb=time(0)&0;
	scanf("%d%d%d",&n,&aa,&bb);
	if(n==1)
	{
		puts("1");
		return 0;
	}
	int kk=n+2;
	A.resize(kk); C.resize(kk);
	for(int i=1,x;i<=aa;++i)
		scanf("%d",&x),(A[x]+=rfac[x])%=MOD,(C[x]-=rfac[x])%=MOD;
	for(int i=1,x;i<=bb;++i)
	{
		scanf("%d",&x);
		if(x) (C[x]+=rfac[x])%=MOD;
	}
	auto w=calc(kk);
	ll ans=w[n]*fac[n]%MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}

