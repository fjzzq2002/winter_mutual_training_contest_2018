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
#include <assert.h>
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
#define Edg int M=0,fst[SZ],vb[5555555],nxt[5555555];\
void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}\
void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 1234567
pii p[SZ]; Edg
int n,a[SZ],N,X;
#define M M_
const int M=131072;
const int inf=1.01e9;
pii operator + (pii a,pii b)
{return pii(min(a.fi,b.fi),max(a.se,b.se));}
int seg[SZ];
vector<int> sbs[SZ];
int ss[SZ],sn,dfn[SZ],low[SZ],ins[SZ],bl[SZ],C=0;
void tj(int x)
{
	dfn[x]=low[x]=++C; ins[x]=1; ss[++sn]=x;
	for esb(x,e,b)
	{
		if(!dfn[b])
			tj(b),low[x]=min(low[x],low[b]);
		else if(ins[b])
			low[x]=min(low[x],dfn[b]);
	}
	if(low[x]!=dfn[x]) return;
	++X; p[X]=pii(inf,-inf);
	while(1)
	{
		int u=ss[sn--];
		bl[u]=X; ins[u]=0;
		sbs[X].pb(u);
		p[X]=p[X]+p[u];
		if(u==x) break;
	}
}
void work()
{
	X=N;
	for(int i=1;i<=N;++i)
		if(!dfn[i]) tj(i);
	for(int i=N+1;i<=X;++i)
		for(auto x:sbs[i])
			for esb(x,e,b)
			{
				assert(i>=bl[b]);
				p[i]=p[i]+p[bl[b]];
			}
}
int gen(int l,int r)
{
	int t=++N; p[t]=pii(inf,-inf);
	if(l>r) return t;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ad_de(t,seg[l^1]);
		if(r&1) ad_de(t,seg[r^1]);
	}
	return t;
}
int pos[SZ];
struct Seg
{
pii s[SZ];
pii qry(int l,int r)
{
	pii t(inf,-inf);
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) t=t+s[l^1];
		if(r&1) t=t+s[r^1];
	}
	return t;
}
void ini()
{
	for(int i=M-1;i>=1;--i)
		s[i]=s[i+i]+s[i+i+1];
}
}A;
int main()
{
	scanf("%d",&n); N=n;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),pos[a[i]]=i;
	for(int i=1;i<=n;++i)
		A.s[i+M]=pii(pos[i],pos[i]),
		p[i]=pii(i,i),seg[i+M]=i;
	for(int i=M-1;i>=1;--i)
	{
		seg[i]=++N; p[N]=pii(inf,-inf);
		if(seg[i+i]) ad_de(seg[i],seg[i+i]);
		if(seg[i+i+1]) ad_de(seg[i],seg[i+i+1]);
	}
	A.ini();
	for(int i=1;i<n;++i)
	{
		int l=a[i],r=a[i+1];
		if(l>r) swap(l,r);
		pii p=A.qry(l,r);
		ad_de(i,gen(p.fi,p.se-1));
	}
	work();
	for(int i=1;i<n;++i)
		A.s[i+M]=p[bl[i]];
	A.ini();
	int m,ty,la=0,lb=0;
	scanf("%d%d",&m,&ty);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l^=la*ty; r^=lb*ty;
		if(l!=r)
		{
			pii t=A.qry(l,r-1);
			l=t.fi; r=t.se+1;
		}
		printf("%d %d\n",la=l,lb=r);
	}
}

