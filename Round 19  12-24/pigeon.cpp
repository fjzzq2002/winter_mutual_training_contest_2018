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
const int MOD=998244353;
#define SZ 666666
int *w0[2333],*w1[2333];
ll qp(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return ans;
}
int getK(int n)
{int s=1; while(s<n) s<<=1; return s;}
void prep(int K)
{
	static int pool[262144*4+3],*p=pool,i=1,j=1;
	for(;j<=K;++i,j<<=1)
	{
		w0[i]=p; w1[i]=(p+=j); p+=j;
		ll g=qp(3,(MOD-1)>>i),ig=qp(g,MOD-2);
		w0[i][0]=w1[i][0]=1;
		for(int k=1;k<j;++k)
			w0[i][k]=w0[i][k-1]*g%MOD,
			w1[i][k]=w1[i][k-1]*ig%MOD;
	}
}
void fft(int* x,int K,int v)
{
	prep(K);
	for(int i=0,j=0;i<K;i++)
	{
		if(i>j) swap(x[i],x[j]);
		for(int l=K>>1;(j^=l)<l;l>>=1);
	}
	for(int i=0;i<K;i++) x[i]=(x[i]%MOD+MOD)%MOD;
	for(int i=2,c=1;i<=K;i<<=1,++c)
		for(int *w=v?w1[c]:w0[c],j=0;j<K;j+=i)
			for(int h=i>>1,a,b,l=0;l<h;++l)
			{
				a=x[j+l]; if(a>=MOD) a-=MOD;
				b=(ll)x[j+h+l]*w[l]%MOD,
				x[j+h+l]=a-b+MOD,x[j+l]=a+b;
			}
	for(int i=0;i<K;i++) x[i]=(x[i]%MOD+MOD)%MOD;
	if(!v) return;
	ll rv=qp(K,MOD-2);
	for(int i=0;i<K;i++) x[i]=x[i]*rv%MOD;
}
int n,k;
vector<int> operator * (const vector<int>& a,
const vector<int>& b)
{
	if(a.size()&&b.size());
	else return vector<int>();
	static int x[SZ],y[SZ];
	int K=getK(a.size()+b.size()-1);
	for(int i=0;i<K;++i) x[i]=y[i]=0;
	for(int i=0;i<a.size();++i) x[i]=a[i];
	for(int i=0;i<b.size();++i) y[i]=b[i];
	fft(x,K,0); fft(y,K,0);
	for(int i=0;i<K;++i) x[i]=(ll)x[i]*y[i]%MOD;
	fft(x,K,1);
	vector<int> c(a.size()+b.size()-1);
	for(int i=0;i<c.size();++i) c[i]=x[i];
	return c;
}
vector<int> operator + (const vector<int>& a,
const vector<int>& b)
{
	vector<int> c(max(a.size(),b.size()));
	for(int i=0;i<a.size();++i) c[i]=a[i];
	for(int i=0;i<b.size();++i) (c[i]+=b[i])%=MOD;
	return c;
}
vector<int> po[52];
ll fac[SZ],rfac[SZ];
ll C(int a,int b)
{
	if(b>a||b<0) return 0;
	return fac[a]*rfac[a-b]%MOD*rfac[b]%MOD;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i) rfac[i-1]=rfac[i]*i%MOD;
	cin>>n>>k;
	for(int i=0;i<k;++i)
		po[1].pb(rfac[i]);
	for(int i=2;i<=n;++i)
		po[i]=po[i-1]*po[1];
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		vector<int>&v=po[i];
		ll x=1,ri=qp(i,MOD-2),su=0;
		for(int j=0;j<v.size();++j)
			su+=v[j]*fac[j]%MOD*x%MOD,x=x*ri%MOD;
		su%=MOD;
		su=su*n%MOD*ri%MOD*C(n,i)%MOD;
		if((i-1)&1) su=-su;
		ans+=su; ans%=MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}

