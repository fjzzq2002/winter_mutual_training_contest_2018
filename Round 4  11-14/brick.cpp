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
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pll;
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
ll l[SZ],r[SZ];
int n;
ll s0[SZ],s1[SZ];
pll operator + (pll a,pll b)
{return pll(a.fi+b.fi,a.se+b.se);}
pll operator - (pll a,pll b)
{return pll(a.fi-b.fi,a.se-b.se);}
ll operator * (pll a,pll b)
{return a.fi*(ll)b.se-a.se*(ll)b.fi;}
bool mycmp(pll a,pll b)
{
	if(a.fi!=b.fi) return a.fi<b.fi;
	return a.se>b.se;
}
vector<pll> graham(vector<pll> v)
{
	sort(v.begin(),v.end(),mycmp);
	reverse(v.begin(),v.end());
	static pll st[SZ]; int sn=0;
	for(auto x:v)
	{
		while(sn>=2&&(x-st[sn-1])*(st[sn]-st[sn-1])>=0) --sn;
		st[++sn]=x;
	}
	vector<pll> s;
	for(int i=1;i<=sn;++i) s.pb(st[i]);
	reverse(s.begin(),s.end());
	return s;
}
ll c0[SZ],c1[SZ],r0[SZ],r1[SZ];
bool bad[SZ];
void go(int l,int r,ll*A,ll*B,ll*C,ll*D)
{
	if(l>=r) return;
	int m=(l+r)>>1;
	go(l,m,A,B,C,D);
	go(m+1,r,A,B,C,D);
	vector<pll> v;
	for(int i=m+1;i<=r;++i)
		v.pb(mp(A[i],B[i]));
	v=graham(v);
	vector<ld> ps;
	for(int i=0;i+1<v.size();++i)
		ps.pb(-(v[i+1].se-v[i].se)/ld(v[i+1].fi-v[i].fi));
//		cout<<v[i+1].fi-v[i].fi<<":"<<(v[i+1].se-v[i].se)/ld(v[i+1].fi-v[i].fi)<<",";cout<<"\n";
	for(int i=l;i<=m;++i) if(!bad[i])
	{
		int u=lower_bound(ps.begin(),ps.end(),-C[i])-ps.begin();
		u=max(u-2,0);
		int vv=min(u+4,int(v.size())-1);
		for(int _=u;_<=vv;++_)
		{
			auto t=v[_];
			if(C[i]*t.fi-D[i]<t.se) {bad[i]=1; break;}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",l+i,r+i);
		s0[i]=s0[i-1]+(r[i]-l[i])*2;
		s1[i]=s1[i-1]+(l[i]+r[i])*ll(r[i]-l[i]);
		r0[i]=-s0[i]; r1[i]=-s1[i];
	}
	for(int i=1;i<=n;++i)
		c0[i]=l[i+1]*s0[i]-s1[i],
		c1[i]=-(r[i+1]*s0[i]-s1[i]);
	int ans=0,ls=0;
	vector<pll> A,B;
	vector<int> v;
	go(1,n-1,l+1,c0,s0,s1);
	go(1,n-1,r+1,c1,r0,r1);
	for(int i=1;i<=n;++i)
		if(!bad[i]) v.pb(i);
	for(auto i:v)
		ans=max(ans,i-ls),ls=i;
	printf("%d\n",ans);
}
