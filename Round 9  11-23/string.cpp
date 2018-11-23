#pragma GCC optimize("-O3","-funroll-all-loops","-fno-stack-protector")
#pragma GCC target("avx","sse","sse2","sse4","tune=native")
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
#define SZ 500099
#define S 21
int l2[SZ+SZ];
struct SA
{
int n,k,sa[SZ],t[SZ],rnk[SZ],qzh[SZ],
tmpsa[SZ],tmpr[SZ],h[SZ],mi[S][SZ]; char s[SZ];
bool same(int a,int b,int p) {return t[a]==t[b]&&t[a+p]==t[b+p];}
void pre(int m=500)
{
	n=strlen(s); s[++n]=0;
	for(int i=0;i<n;i++) rnk[i]=s[i], ++qzh[rnk[i]];
	for(int i=1;i<m;i++) qzh[i]+=qzh[i-1];
	for(int i=n-1;i>=0;i--) sa[--qzh[rnk[i]]]=i;
	for(int j=1;j<=n;j<<=1)
	{
		int cur=-1;
		for(int i=n-j;i<n;i++) tmpsa[++cur]=i;
		for(int i=0;i<n;i++) if(sa[i]>=j) tmpsa[++cur]=sa[i]-j;
		for(int i=0;i<n;i++) tmpr[i]=rnk[tmpsa[i]];
		for(int i=0;i<m;i++) qzh[i]=0;
		for(int i=0;i<n;i++) ++qzh[tmpr[i]];
		for(int i=1;i<m;i++) qzh[i]+=qzh[i-1];
		for(int i=n-1;i>=0;i--) t[i]=rnk[i], sa[--qzh[tmpr[i]]]=tmpsa[i];
		m=0;
		for(int i=0;i<n;i++)
			rnk[sa[i]]=(i>0&&same(sa[i],sa[i-1],j))?m:++m;
		++m;
	}
	for(int i=0;i<n;i++) rnk[sa[i]]=i;
	int p=0;
	for(int i=0;i<n;i++)
	{
		if(p) --p;
		int ls=sa[rnk[i]-1];
		while(s[ls+p]==s[i+p]) p++;
		h[rnk[i]]=p;
	}
	--n;
	for(int i=1;i<=n;i++) sa[i-1]=sa[i];
	for(int i=0;i<n;i++) rnk[sa[i]]=i;
	for(int i=2;i<=n;i++) h[i-1]=h[i];
	h[n]=sa[n]=0;
	for(int i=0;i<n;i++)
		mi[0][i]=h[i];
	for(int j=1;j<S;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
}
inline int gmin(int a,int b)
{
	int l=l2[b-a+1];
	return min(mi[l][a],mi[l][b-(1<<l)+1]);
}
int lcp(int a,int b)
{
	if(a==b) return n-a;
	if(rnk[a]>rnk[b]) swap(a,b);
	return gmin(rnk[a]+1,rnk[b]);
}
}A,B;
char s[SZ]; int n;
int si[SZ];
const int MOD=998244353;
int g[7000000][2],h[7000000],t=0,f[200005];
vector<int> rs[200005];
bool cov[6666666];
void chk(int l,int r,int p)
{
	++t; h[t]=r-l+1;
	for(int g=r,_=0;_<p;g+=r-l+1,++_)
		if(_) rs[g+1].pb(t);
//		cout<<l<<"~"<<r<<" "<<g<<"!\n";
//	cout<<l<<"~"<<r<<"x"<<p<<"\n";
}
int main()
{
	l2[0]=-1;
	for(int i=1;i<SZ+SZ;++i)
		l2[i]=l2[i>>1]+1;
	scanf("%s",s); n=strlen(s);
	for(int i=0;i<n;++i) A.s[i]=s[i];
	for(int i=n-1;i>=0;--i) B.s[n-1-i]=s[i];
	A.pre(); B.pre();
	for(int i=1;i<=n;++i)
		si[i]=si[i-1]+n/i-1;
	for(int len=1;len+len<=n;++len)
	{
		int l=-1,r=-1;
		for(int i=len-1;i+len<n;i+=len)
		{
			if(i<=r) continue;
			int L=B.lcp(n-i-1,n-i-len-1),R=A.lcp(i,i+len);
			if(L+R-1<len) continue;
			l=i-L+1; r=i+R-1;
			if(cov[si[len-1]+(i+1)/len])
				continue;
			for(int x=len+len;l+x+x-1<=r+len;x+=len)
				cov[si[x-1]+l/x+1]=1;
			for(int t=0;t<len&&l+t+len-1<=r;++t)
				chk(l+t,l+t+len-1,(r-l-t-len+1)/len+2);
		}
	}
	f[0]=1;
	int ans=1;
	for(int i=1;i<=n;++i)
	{
		f[i]=ans;
		for(auto t:rs[i])
		{
			(g[t][(i/h[t])&1]+=f[i-h[t]*2])%=MOD;
			(f[i]-=g[t][(i/h[t])&1]*2%MOD)%=MOD;
		}
		(ans+=f[i])%=MOD;
	}
	ans=(f[n]%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}
