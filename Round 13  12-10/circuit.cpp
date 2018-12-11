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
ll n,x[SZ]; int m;
ll L,R,T;
bool d[SZ];
ll f[SZ];
bool chk(vector<ll> v)
{
	for(int i=0;i<v.size()+1;++i) f[i]=-4e18;
	f[0]=L;
	for(int i=0;i<v.size();++i)
	{
		if(f[i]>R) return 1;
		if(v[i]<=f[i]) f[i+1]=max(f[i+1],v[i]+T+1);
		int j=(int)(upper_bound(v.begin(),v.end(),f[i]+T)-v.begin())-1;
		for(int s=j;s>=i&&s>=j-2;--s)
			f[s+1]=max(f[s+1],max(v[s]+1,(s==i)?(-1):(v[s-1]+T+1)));
	}
	return f[v.size()]>R;
}
bool ok(ll t)
{
	vector<ll> vs;
	L=t+1; R=n-1; T=t;
	int cp=0;
	for(int i=2;i<=m;++i)
		if(x[i]<=t) ++cp;
		else vs.pb(x[i]);
	if(cp==0)
		return chk(vs);
	if(cp==1)
	{
		//x[2]
		vs.insert(vs.begin(),x[2]);
		if(chk(vs)) return 1;
		vs.erase(vs.begin()); vs.pb(x[2]+n);
		return chk(vs);
	}
	else
	{
		vs.insert(vs.begin(),x[cp+1]);
		vs.pb(x[2]+n); return chk(vs);
	}
}
ll work()
{
	sort(x+1,x+1+m);
	ll l=0,r=n-1;
	while(l<r)
	{
		ll t=(l+r)>>1;
		if(ok(t)) r=t; else l=t+1;
	}
	return l;
}
int main()
{
	scanf("%lld%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%lld",x+i),--x[i];
	if(m==1)
	{
		printf("%lld\n",n-1);
		return 0;
	}
	ll u=x[1];
	for(int i=1;i<=m;++i)
		x[i]=(x[i]-u+n)%n;
	ll ans=work();
	for(int i=1;i<=m;++i)
		x[i]=(n-x[i])%n;
	ans=min(ans,work());
	printf("%lld\n",ans);
}
