#pragma GCC optimize("-O3","-funroll-all-loops")
#pragma GCC target("avx","sse","sse2","avx2","sse3")
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
int n,k,MOD,g1,g2,g3,N;
struct mat
{
int u[65][65];
}I;
bool ha[66],hb[66];
inline __attribute__((always_inline)) void operator *= (mat& a,mat&b)
{
	static mat c,d;
	for(int i=0;i<N;++i) ha[i]=hb[i]=0;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j) d.u[j][i]=b.u[i][j];
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			if(a.u[i][j]) ha[i]=1;
			if(b.u[i][j]) hb[i]=1;
		}
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j) if(ha[i]&&hb[j])
		{
			register ll x=0;
			register int k;
			register int *aa=a.u[i],*bb=d.u[j];
			#define po(t) (aa[t]*(ll)bb[t])
			for(k=0;k<N;k++)
			{
				x+=po(k);
				if((k&7)==0&&x) x%=MOD;
			}
			#undef po
			c.u[i][j]=x%MOD;
		}
		else c.u[i][j]=0;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			a.u[i][j]=c.u[i][j];
}
int id[23][23],mx=0;
int cm=0; mat ps[9];
void pp(mat x,ll t)
{
	while(cm<t)
	{
		++cm;
		if(cm==1) ps[cm]=x;
		else ps[cm]=ps[cm-1],ps[cm]*=x;
	}
}
mat po(mat x,ll t)
{
	if(t<=7)
	{
		pp(x,t); return ps[t];
	}
	mat q=po(x,t>>3);
	for(int i=1;i<=3;++i) q*=q;
	pp(x,t&7);
	if(t&7) q*=ps[t&7];
	return q;
}
ll calc(int p)
{
	N=0; mat T;
	memset(id,-1,sizeof id);
	for(int i=0;i<=g1;++i)
		for(int j=0;j<=g2;++j)
			if(i+j+p>=0&&i+j+p<=g3)
				id[i][j]=N++;
	memset(&T,0,sizeof T);
	memset(&I,0,sizeof I);
	for(int i=0;i<N;++i) I.u[i][i]=1;
	for(int i=0;i<=g1;++i)
		for(int j=0;j<=g2;++j) if(~id[i][j])
		{
			//a-b, b-c
			//1. ++i
			//2. --i,++j
			//3. --j
			int ii,jj;
			{
			ii=i+1,jj=j;
			if(ii>=0&&ii<=g1
			&&jj>=0&&jj<=g2
			&&ii+jj+p>=0&&ii+jj+p<=g3)
				++T.u[id[i][j]][id[ii][jj]];
			}
			{
			ii=i-1,jj=j+1;
			if(ii>=0&&ii<=g1
			&&jj>=0&&jj<=g2
			&&ii+jj+p>=0&&ii+jj+p<=g3)
				++T.u[id[i][j]][id[ii][jj]];
			}
			{
			ii=i,jj=j-1;
			if(ii>=0&&ii<=g1
			&&jj>=0&&jj<=g2
			&&ii+jj+p>=0&&ii+jj+p<=g3)
				++T.u[id[i][j]][id[ii][jj]];
			}
		}
	cm=0; ps[0]=I; mat S=po(T,n);
	ll aa=0;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			(aa+=S.u[i][j])%=MOD;
	return aa;
}
ll calc()
{
	ll aa=0;
	for(int x=-g1-g2;x<=g3;++x)
		aa+=calc(x),aa%=MOD;
	return aa;
}
int main()
{
//	n=1e9,k=8; MOD=998244322;
	scanf("%d%d%d",&n,&k,&MOD);
	ll ans=0;
	for(g1=k;g1>=k-1;--g1)
	{
		for(g2=k;g2>=k-1;--g2)
		{
			for(g3=k;g3>=k-1;--g3)
			{
				ll aa=calc();
				if(g1-k) aa*=-1;
				if(g2-k) aa*=-1;
				if(g3-k) aa*=-1;
				ans+=aa;
			}
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}
