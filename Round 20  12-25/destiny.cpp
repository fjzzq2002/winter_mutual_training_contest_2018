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
int p,q,s,m,k,c[1005][1005];
bitset<2005> bb[1005];
int x[1005];
int rk()
{
	int aa=0;
	for(int i=0;i<s;++i)
		if(x[i]!=-1) ++aa;
	return aa;
}
void gauss()
{
	int c=0;
	for(int i=0;i<s;++i)
	{
		{
		int g=-1;
		for(int j=c;j<p;++j)
			if(bb[j][i]) {g=j; break;}
		if(g==-1) continue;
		swap(bb[g],bb[c]);
		}
		x[i]=c;
		for(int j=0;j<p;++j)
			if(j!=c&&bb[j][i]) bb[j]^=bb[c];
		++c;
	}
}
void init()
{
	for(int i=0;i<p;++i)
	{
		bb[i].reset();
		for(int j=0;j<s;++j)
			bb[i][j]=c[i][j];
		bb[i][i+s]=1;
	}
	for(int i=0;i<s;++i) x[i]=-1;
	gauss();
}
bool vv[5005];
void clr_col(int t)
{
	//清除第t列
	for(int i=0;i<p;++i) bb[i][t]=0;
	if(x[t]==-1) return;
	x[t]=-1;
	for(int i=0;i<p;++i) vv[i]=0;
	for(int i=0;i<s;++i)
		if(x[i]!=-1) vv[x[i]]=1;
	for(int i=0;i<p;++i) if(!vv[i])
	{
		int w=bb[i]._Find_first();
		if(w>=s) continue;
		if(x[w]!=-1) throw 123;
		x[w]=i;
		for(int j=0;j<p;++j)
			if(bb[j][w]&&j!=i) bb[j]^=bb[i];
		return;
	}
}
void ins_col(int t)
{
	//插入第t列
	if(x[t]!=-1) throw 123.456;
	bitset<2005> go; go.reset();
	for(int i=0;i<p;++i)
		go[i+s]=c[i][t];
	for(int i=0;i<p;++i)
		bb[i][t]=(bb[i]&go).count()&1;
	for(int i=0;i<p;++i) vv[i]=0;
	for(int i=0;i<s;++i)
		if(x[i]!=-1) vv[x[i]]=1;
	for(int i=0;i<p;++i) if(!vv[i]&&bb[i][t])
	{
		x[t]=i;
		for(int j=0;j<p;++j)
			if(bb[j][t]&&j!=i) bb[j]^=bb[i];
		return;
	}
}
const int MOD=1e9+7;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
ll Fq[1005][1005],Fp[1005][1005],p2[SZ],aa[1005];
template<class T>
void ww(int x,T& F)
{
	F[0][0]=1;
	for(int i=1;i<=1002;++i)
		for(int j=0;j<=i;++j)
		{
			F[i][j]=F[i-1][j]*p2[j];
			if(j) F[i][j]+=F[i-1][j-1]*(p2[x]-p2[j-1]);
			F[i][j]%=MOD;
		}
}
int calc()
{
	return (aa[rk()]%MOD+MOD)%MOD;
}
int main()
{
	p2[0]=1;
	for(int i=1;i<SZ;++i) p2[i]=p2[i-1]*2LL%MOD;
	scanf("%d%d%d%d%d",&p,&q,&s,&m,&k);
	for(int i=0;i<p;++i)
		for(int j=0;j<s;++j) scanf("%d",&c[j][i]);
	swap(p,s);
	//p行s列
	ww(q,Fq); ww(p,Fp);
	for(int i=0;i<=p;++i)
	{
		for(int j=i;j<=q;++j)
			aa[i]+=Fq[s][j]*(ll)Fp[j][i]%MOD*p2[(q-j)*p],
			aa[i]%=MOD;
		aa[i]=aa[i]*qp(Fp[s][i],MOD-2)%MOD;
	}
	init(); int la;
	printf("%d\n",la=calc());
	while(m--)
	{
		int i; scanf("%d",&i); i^=k*la; --i;
		for(int j=0;j<p;++j)
			scanf("%d",&c[j][i]);
		clr_col(i); ins_col(i);
		printf("%d\n",la=calc());
	}
}
