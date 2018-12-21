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
const int MOD=998244353;
ll w[2][SZ];
inline ll qp(ll a,ll b)
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
inline void fftinit(int n)
{
    for(K=1;K<n;K<<=1);
    w[0][0]=w[0][K]=1;
    ll g=qp(3,(MOD-1)/K);
    for(int i=1;i<K;i++) w[0][i]=w[0][i-1]*g%MOD;
    for(int i=0;i<=K;i++) w[1][i]=w[0][K-i];
}
inline void fft(int* x,int v)
{
    for(int i=0;i<K;i++) x[i]=(x[i]%MOD+MOD)%MOD;
    for(int i=0,j=0;i<K;i++)
    {
        if(i>j) swap(x[i],x[j]);
        for(int l=K>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=K;i<<=1)
        for(int l=0;l<i>>1;l++)
        {
            register int W=w[v][K/i*l],*p=x+l+(i>>1),*q=x+l,t;
            for(register int j=0;j<K;j+=i)
            {
                p[j]=(q[j]-(t=(ll)p[j]*W%MOD)<0)?(q[j]-t+MOD):(q[j]-t);
                q[j]=(q[j]+t-MOD>=0)?(q[j]+t-MOD):(q[j]+t);
            }
        }
    if(!v) return;
    ll rv=qp(K,MOD-2);
    for(int i=0;i<K;i++) x[i]=x[i]*rv%MOD;
}
int n,m,k,a[SZ],b[SZ];
ll fac[SZ],rfac[SZ];
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i)
		fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i)
		rfac[i-1]=rfac[i]*i%MOD;
	cin>>n>>m>>k;
	if(k==0)
	{
		puts("1");
		return 0;
	}
	fftinit(m+m+1);
	for(int i=0;i<m;++i)
	{
		ll u=rfac[i]*rfac[m-i]%MOD;
		if(i&1) u=-u; a[i]=u;
	}
	for(int i=1;i<=m;++i)
		b[i]=qp(i,m);
	fft(a,0); fft(b,0);
	for(int i=0;i<K;++i) a[i]=(ll)a[i]*b[i]%MOD;
	fft(a,1);
	ll ans=0;
	for(int i=1;i<=m;++i)
	{
		ll p=qp(1-a[i],n);
		ans+=p*(qp(i,k)-qp(i-1,k));
		ans%=MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}

