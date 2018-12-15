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
int r[SZ],n,m,t3[SZ],ed[SZ]; ll c,l[SZ];
pair<ll,int> g[SZ];
const int MOD=998244353;
bool good[SZ]; int sp[SZ];
ll coe[SZ],f[15000000];
ll qp(ll a,ll b)
{
	a%=MOD; ll x=1;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
ll calc(vector<ll> vv)
{
	if(!vv.size()) return c==0;
	ll u=c;
	for(auto x:vv) u^=x;
	ll ans=0;
	for(int i=61;i>=0;--i)
	{
		if(u>>(i+1)) continue;
		ll v[2]={1,0},v0=1;
		for(auto x:vv)
			if(x&(1LL<<i))
			{
				ll s[2]=
				{v[1]*((1LL<<i)%MOD)+v[0]*((x&((1LL<<i)-1))%MOD),
				v[0]*((1LL<<i)%MOD)+v[1]*((x&((1LL<<i)-1))%MOD)};
				v0=v0*((x&((1LL<<i)-1))%MOD)%MOD;
				v[0]=s[0]%MOD; v[1]=s[1]%MOD;
			}
			else
			{
				v[0]=v[0]*((x&((1LL<<i)-1))%MOD)%MOD;
				v[1]=v[1]*((x&((1LL<<i)-1))%MOD)%MOD;
				v0=v0    *((x&((1LL<<i)-1))%MOD)%MOD;
			}
		(v[0]-=v0)%=MOD;
		ans+=v[(u>>i)&1]*qp(1LL<<i,MOD-2)%MOD;
//		if(v[(u>>i)&1])
//			cerr<<v[0]<<","<<v[1]<<" "<<v0<<"?\n",
//			cout<<i<<":"<<v[(u>>i)&1]<<" "<<(u>>i)<<"\n";
		ans%=MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
//	for(auto x:vv) cout<<x<<",";cout<<" "<<c<<":"<<ans<<"\n";
	return ans;
}
int main()
{
	cin>>n>>m>>c;
	for(int i=0;i<n;++i)
		cin>>g[i].fi,++g[i].fi,g[i].se=i;
	sort(g,g+n);
	for(int i=0;i<n;++i)
		r[g[i].se]=i,l[i]=g[i].fi;
	for(int i=1;i<=m;++i)
	{
		int a,b;
		cin>>a>>b;
		a=r[a-1],b=r[b-1];
		ed[a]|=1<<b;
		ed[b]|=1<<a;
	}
	for(int i=0;i<(1<<n);++i)
		for(int j=n-1;j>=0;--j)
			t3[i]=t3[i]*3+((i>>j)&1);
	for(int i=1;i<(1<<n);++i)
	{
		good[i]=1;
		for(int j=0;j<n;++j)
			if((i&(1<<j))&&(i&ed[j])) good[i]=0;
		coe[i]=good[i];
		int s=i^(i&-i);
		for(int j=s;j;j=(j-1)&s)
			if(good[j]) (coe[i]-=coe[i^j])%=MOD;
	}
	for(int i=1;i<(1<<n);++i)
	{
		if(__builtin_popcount(i)&1) continue;
		for(int j=0;j<n;++j) if(i&(1<<j))
			{sp[i]=1; coe[i]=coe[i]*(l[j]%MOD)%MOD; break;}
	}
	f[0]=1;
	for(int i=0;i<(1<<n)-1;++i)
	{
		ll F;
		for(int j=i;;j=(j-1)&i)
		{
		if(F=f[t3[i]+t3[j]])
		{
			int s=0;
			while(i&(1<<s)) ++s;
			int g=((1<<n)-1)^i^(1<<s);
			for(int k=g;;k=(k-1)&g)
			{
				int u=k^(1<<s);
				if(sp[u])
					(f[t3[i|u]+t3[j]]+=F*coe[u])%=MOD;
				else
					(f[t3[i|u]+t3[j|(1<<s)]]+=F*coe[u])%=MOD;
				if(!k) break;
			}
		}
		if(!j) break;
		}
	}
	ll ans=0;
	for(int i=0;i<(1<<n);++i)
	{
		ll F;
		if(F=f[t3[(1<<n)-1]+t3[i]])
		{
			vector<ll> v;
			for(int j=0;j<n;++j)
				if(i&(1<<j)) v.pb(l[j]);
			ans+=F*calc(v); ans%=MOD;
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}
