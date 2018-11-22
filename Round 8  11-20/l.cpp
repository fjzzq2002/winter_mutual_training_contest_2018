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
typedef unsigned us;
int n,k,low[SZ],dfn[SZ],Cc=0,ins[SZ],st[SZ],sn=0,
bl[SZ],N=0; Edg ll m;
void tarjan(int x)
{
	dfn[x]=low[x]=++Cc; st[++sn]=x; ins[x]=1;
	for esb(x,e,b)
	{
		if(!dfn[b])
			tarjan(b), low[x]=min(low[b],low[x]);
		else if(ins[b]) low[x]=min(low[x],dfn[b]);
	}
	if(low[x]!=dfn[x]) return;
	while(1)
	{
		int r=st[sn--];
		ins[r]=0; bl[r]=N; 
		if(r==x) break;
	}
	++N;
}
int edg[SZ];
us f[21][1<<20];
us qp(us a,ll b)
{
	us x=1;
	while(b)
	{
		if(b&1) x=x*a;
		a=a*a; b>>=1;
	}
	return x;
}
us C(ll a,int b)
{
	if(b>a) return 0;
	us A=1; ll B=0;
	for(int w=1;w<=b;++w)
	{
		ll x=a-w+1;
		while(x%2==0) x/=2,++B;
		A=A*(x&(-1u));
	}
	for(int w=1;w<=b;++w)
	{
		ll x=w;
		while(x%2==0) x/=2,--B;
		A=A*qp(x&(-1u),(1LL<<31)-1);
	}
	while(A&&(B--)) A*=2;
	return A;
}
#define SS 223456
ll c0[SS],c1[SS],b0[SS],b1[SS]; int S,ps[SS/10],pn=0;
inline us G(us t) {return 81u*t*t-27u*t+9u;}
const us G1=G(1);
#define L 1000000
us os[SS],rs[L+2][61],pp[L+2]; int rss[L+2];
inline us F(ll x,us g)
{
    if(x<=1||ps[g]>x) return 0u;
	if(x<=L&&g<=60) return rs[x][g];
    us ans=((x>S)?b0[m/x]:c0[x])-c0[ps[g-1]]; ans*=G1;
    for(us j=g;j<=pn&&ps[j]*(ll)ps[j]<=x;++j)
    {
        ll cn=x/ps[j],ce=ps[j]*(ll)ps[j];
        for(us e=1;cn>=ps[j];++e,cn/=ps[j],ce*=ps[j])
            ans=ans+F(cn,j+1)*G(e)+G(e+1);
    }
	return ans;
}
void work()
{
	for(int i=1;i<=L;++i)
		rss[i]=2e9,pp[i]=1u;
	for(int i=2;i<=L;++i) if(rss[i]>1e9)
		for(int j=i;j<=L;j+=i)
		{
			rss[j]=min(rss[j],i);
			int k=0,l=j;
			while(l%i==0) l/=i,++k;
			pp[j]=pp[j]*G(k);
		}
	S=sqrtl(m);
    for(int i=1;i<=S;++i)
    {
        ll t=m/i; b0[i]=(us)t; c0[i]=i;
    }
    for(int i=2;i<=S;++i)
    {
        if(c0[i]==c0[i-1]) continue; //not a prime
        ll x0=c0[i-1],x1=c1[i-1],r=(ll)i*i; ps[++pn]=i;
        int u=min((ll)S,m/(i*(ll)i)),uu=min(u,S/i);
        for(int j=1;j<=uu;++j)
            b0[j]-=b0[j*i]-x0;
        ll t=m/i;
        if(t<=2147483647)
        {
        int tt=t;
        for(int j=uu+1;j<=u;++j)
            b0[j]-=c0[tt/j]-x0;
        }
        else
        {
        for(int j=uu+1;j<=u;++j)
            b0[j]-=c0[t/j]-x0;
        }
        for(int j=S;j>=r;--j)
            c0[j]-=c0[j/i]-x0;
    }
    ps[0]=1; ps[pn+1]=S+1;
	for(int i=2;i<=L;++i)
		for(int j=1;j<=60;++j)
			if(rss[i]>=ps[j])
				rs[i][j]=rs[i-1][j]+pp[i];
			else rs[i][j]=rs[i-1][j];
}
us R(ll t)
{
	us ans=0;
	for(int i=1;i<=N;++i)
		ans+=C(t,i)*f[i][(1<<N)-1];
	return ans;
}
int main()
{
	scanf("%d%lld%d",&n,&m,&k);
	for(int i=0,a,b;i<k;++i)
		scanf("%d%d",&a,&b),ad_de(a-1,b-1);
	for(int i=0;i<n;++i)
		if(!dfn[i]) tarjan(i);
	for(int i=0;i<n;++i) bl[i]=N-bl[i]-1;
	for(int i=0;i<n;++i)
		for esb(i,e,b)
			if(bl[i]!=bl[b])
				edg[bl[b]]|=1<<bl[i];
	f[0][0]=1;
	for(int i=1;i<=N;++i)
		for(int w=0;w<N;++w)
			for(int s=(1<<N)-1;s>=0;--s)
				if(!(s&(1<<w))&&((edg[w]&s)==edg[w]))
					f[i][s|(1<<w)]+=f[i-1][s]+f[i][s];
	work();
	us ls=0,ans=0;
	for(ll x=1;x<=m;)
	{
		ll t=m/x,y=m/t;
		us cur=F(y,1)+1;
		ans+=(cur-ls)*R(t);
		ls=cur; x=y+1;
	}
	printf("%u\n",ans);
}

