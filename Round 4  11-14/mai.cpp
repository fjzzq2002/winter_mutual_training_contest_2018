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
#define SZ 2333333
const int MOD=998244353;
ll w[2][SZ];
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
int K;
void fftinit(int n)
{
    for(K=1;K<n;K<<=1);
    w[0][0]=w[0][K]=1;
    ll g=qp(3,(MOD-1)/K); //3ÊÇÔ­¸ù
    for(int i=1;i<K;i++) w[0][i]=w[0][i-1]*g%MOD;
    for(int i=0;i<=K;i++) w[1][i]=w[0][K-i];
}
void fft(int* x,int v)
{
    for(int i=0,j=0;i<K;i++)
    {
        if(i>j) swap(x[i],x[j]);
        for(int l=K>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=K;i<<=1)
    {
        for(int j=0;j<K;j+=i)
        {
            for(int l=0;l<i>>1;l++)
            {
                ll t=(ll)x[j+l+(i>>1)]*w[v][K/i*l]%MOD;
                x[j+l+(i>>1)]=(x[j+l]-t+MOD)%MOD;
                x[j+l]=(x[j+l]+t)%MOD;
            }
        }
    }
    if(!v) return;
    ll rv=qp(K,MOD-2);
    for(int i=0;i<K;i++) x[i]=x[i]*rv%MOD;
}
vector<int> conv(vector<int> a,vector<int> b)
{
	fftinit(a.size()+b.size()+2);
	static int aa[SZ],bb[SZ];
	for(int i=0;i<K;++i) aa[i]=bb[i]=0;
	for(int i=0;i<a.size();++i) aa[i]=a[i];
	for(int i=0;i<b.size();++i) bb[i]=b[i];
	fft(aa,0); fft(bb,0);
	for(int i=0;i<K;++i) aa[i]=(ll)aa[i]*bb[i]%MOD;
	fft(aa,1); vector<int> v;
	for(int i=0;i<a.size()+b.size()-1;++i)
		v.pb(aa[i]); return v;
}
int n,a[SZ]; ll fac[SZ],rfac[SZ];
ll C(int a,int b)
{return fac[a]*rfac[a-b]%MOD*rfac[b]%MOD;}
ll f(int a,int b) {return C(a+b-1,a-b);}
vector<int> go(vector<int> h)
{
	//G-t+t-i=G-i
	int G=h.size();
	vector<int> A,B;
	A.resize(G+1); B.resize(G+1);
	for(int i=0;i<G;++i)
		A[i]=rfac[i]*((i&1)?(-1):1);
	for(int i=1;i<G;++i)
		B[G-i]=fac[i-1]*h[i]%MOD;
	A=conv(A,B); B[0]=0;
	for(int i=1;i<=G;++i)
		B[i]=A[G-i]*rfac[i-1]%MOD;
	B.pop_back();
	return B;
}
vector<int> x[SZ],y[SZ];
vector<int> calc(int l,int r)
{
	if(l>r)
	{
		vector<int> v;
		v.pb(1); return v;
	}
	if(l==r) return y[l];
	int m=(l+r)>>1;
	return conv(calc(l,m),calc(m+1,r));
}
vector<int> u;
ll gans(int uu)
{
	y[1]=x[1];
	for(int j=1;j<y[1].size();++j)
		y[1][j]=y[1][j]*rfac[j]%MOD*fac[j-1]%MOD;
	y[1]=go(y[1]);
	while((uu--)&&y[1].size())
		y[1].erase(y[1].begin());
	for(int j=0;j<y[1].size();++j)
		y[1][j]=y[1][j]*rfac[j]%MOD; 
	auto t=conv(y[1],u);
	ll ans=0;
	for(int i=0;i<t.size();++i)
		ans+=t[i]*fac[i],ans%=MOD;
	return ans;
}
int main()
{
	scanf("%d",&n);
	int su=0;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),
		su+=a[i];
	fac[0]=1;
	for(int i=1;i<SZ;++i)
		fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i)
		rfac[i-1]=rfac[i]*i%MOD;
	for(int i=1;i<=n;++i)
	{
		x[i].pb(0);
		for(int j=1;j<=a[i];++j)
			x[i].pb(f(a[i],j));
	}
	for(int i=2;i<=n;++i)
	{
		y[i]=go(x[i]);
		for(int j=0;j<y[i].size();++j)
			y[i][j]=y[i][j]*rfac[j]%MOD;
	}
	u=calc(2,n);
	ll ans=gans(1);
	ans-=gans(2);
	ans=ans*su;
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}

