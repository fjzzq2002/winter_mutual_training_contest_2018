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
int n,m;
char s[3005][3005];
#define L 5 //1
#define R 6 //2
#define U 4 //0
#define D 7 //1|2
int ty[1505][1505];
#define GG {while(m--)puts("0");exit(0);}
int fa[1505][1505],fb[1505][1505],
fc[1505][1505],fd[1505][1505],
d1[1505][1505],d2[1505][1505];
const int MOD=998244353;
#define SZ 666666
int qa[SZ],qb[SZ],qc[SZ];
ll ans[SZ];
int cv(int t)
{
	if(t==L||t==U)
		return L^U^t;
	if(t==R||t==D)
		return R^D^t;
	return t;
}
void go()
{
	memset(fa,0,sizeof fa);
	memset(fb,0,sizeof fb);
	memset(fc,0,sizeof fc);
	memset(fd,0,sizeof fd);
	fa[0][n]=1;
	for(int i=1;i<=n;++i)
	{
		int up=0,down=n+1;
		for(int j=1;j<=n;++j)
			if(ty[j][i])
			{
				if(ty[j][i]&2) down=min(down,j);
				else up=max(up,j);
			}
		int su=0;
		for(int j=down;j<=n;++j)
			(su+=fa[i-1][j])%=MOD;
		for(int j=down-1;j>=up;--j)
			(su+=fa[i-1][j])%=MOD,fa[i][j]=su;
	}
	fb[n+1][n]=1;
	for(int i=n;i>=1;--i)
	{
		int up=0,down=n+1;
		for(int j=1;j<=n;++j)
			if(ty[j][i])
			{
				if(ty[j][i]&1) down=min(down,j);
				else up=max(up,j);
			}
		int su=0;
		for(int j=down;j<=n;++j)
			(su+=fb[i+1][j])%=MOD;
		for(int j=down-1;j>=up;--j)
			(su+=fb[i+1][j])%=MOD,fb[i][j]=su;
	}
	fc[n+1][0]=1;
	for(int i=n;i>=1;--i)
	{
		int up=0,down=n+1;
		for(int j=1;j<=n;++j)
			if(ty[j][i])
			{
				if(ty[j][i]&2) down=min(down,j);
				else up=max(up,j);
			}
		int su=0;
		for(int j=0;j<up;++j)
			(su+=fc[i+1][j])%=MOD;
		for(int j=up;j<down;++j)
			(su+=fc[i+1][j])%=MOD,fc[i][j]=su;
	}
	fd[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		int up=0,down=n+1;
		for(int j=1;j<=n;++j)
			if(ty[j][i])
			{
				if(ty[j][i]&1) down=min(down,j);
				else up=max(up,j);
			}
		int su=0;
		for(int j=0;j<up;++j)
			(su+=fd[i-1][j])%=MOD;
		for(int j=up;j<down;++j)
			(su+=fd[i-1][j])%=MOD,fd[i][j]=su;
	}
	for(int i=1;i<=n;++i)
		for(int j=n;j>=0;--j)
			d2[i][j]=(d2[i][j+1]+(ll)fa[i][j]*fc[i][j])%MOD,
			d1[i][j]=(d1[i][j+1]+(ll)fb[i][j]*fd[i][j])%MOD;
	for(int i=1;i<=m;++i)
	{
		if(qc[i]==R)
			ans[i]=(d2[qa[i]][0]-d2[qa[i]][qb[i]])*ll(d1[qa[i]][qb[i]]);
		else if(qc[i]==L)
			ans[i]=(d1[qa[i]][0]-d1[qa[i]][qb[i]])*ll(d2[qa[i]][qb[i]]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n+n;++i)
		scanf("%s",s[i]);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int g=(s[i*2][j*2]=='1')
			+(s[i*2][j*2+1]=='1')
			+(s[i*2+1][j*2]=='1')
			+(s[i*2+1][j*2+1]=='1');
			int&T=ty[i+1][j+1];
			if(g==0)
			{
				T=0;
				continue;
			}
			if(g!=2) GG
			if(g==2)
			{
				if(s[i*2][j*2]=='1'
				&&s[i*2][j*2+1]=='1')
					T=U;
				else if(s[i*2+1][j*2]=='1'
				&&s[i*2+1][j*2+1]=='1')
					T=D;
				else if(s[i*2][j*2]=='1'
				&&s[i*2+1][j*2]=='1')
					T=L;
				else if(s[i*2][j*2+1]=='1'
				&&s[i*2+1][j*2+1]=='1')
					T=R;
				else GG;
			}
		}
	}
	for(int i=1;i<=m;++i)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		--x1,--y1,--x2,--y2;
		int A=x1/2,B=y1/2;
		if(x2/2!=A||y2/2!=B)
			continue;
		++A,++B;
		int t;
		if(x1==x2)
		{
			if(x1&1) t=D;
			else t=U;
		}
		else
		{
			if(y1&1) t=R;
			else t=L;
		}
		qa[i]=B,qb[i]=A,qc[i]=t;
	}
	go();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			ty[i][j]=cv(ty[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i<j) swap(ty[i][j],ty[j][i]);
	for(int i=1;i<=m;++i)
		qc[i]=cv(qc[i]),swap(qa[i],qb[i]);
	go();
	for(int i=1;i<=m;++i)
		printf("%d\n",int(ans[i]%MOD+MOD)%MOD);
}
