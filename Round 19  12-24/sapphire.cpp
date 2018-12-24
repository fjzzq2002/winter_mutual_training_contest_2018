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
typedef long double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 888888
int ch[SZ][2],rnd[SZ],an=0;
ll tag[SZ],va[SZ],s1[SZ],s2[SZ],vv[SZ],sz[SZ];
const ld eps=1e-13;
ld gv(ll x,ll y)
{
	ll g=__gcd(x,y);
	if(g<0) g=-g;
	x/=g; y/=g;
	return atan2l(y,x);
}
ld val[SZ];
#ifdef WIN32
int Rand() {return (rand()<<16)|rand();}
#else
#define Rand rand
#endif
void addnode(int& ad)
{
    ad=++an; sz[ad]=1; rnd[ad]=Rand();
}
void puu(int x,ll t)
{
	s2[x]=s2[x]+2*s1[x]*t+sz[x]*t*t;
	s1[x]=s1[x]+sz[x]*t;
	tag[x]+=t; va[x]+=t;
}
void pd(int x)
{
    if(!x||!tag[x]) return;
    if(ch[x][0])
    	puu(ch[x][0],tag[x]);
    if(ch[x][1])
    	puu(ch[x][1],tag[x]);
    tag[x]=0;
}
void upd(int x)
{
    if(!x) return;
    sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]];
    s1[x]=va[x]+s1[ch[x][0]]+s1[ch[x][1]];
    s2[x]=va[x]*va[x]+s2[ch[x][0]]+s2[ch[x][1]];
}
//split出<=v的放在a 
void split(int x,int& a,int& b,ld v)
{
	if(!x) a=b=0;
	else
    {
        pd(x);
        if(val[x]>v)
        {
            b=x;
            split(ch[x][0],a,ch[x][0],v);
            upd(x);
        }
        else
        {
            a=x;
            split(ch[x][1],ch[x][1],b,v);
            upd(x);
        }
    }
}
void merge(int& ad,int a,int b)
{
    if(a==0) ad=b;
    else if(b==0) ad=a;
    else
    {
        if(rnd[a]>rnd[b])
        {
            pd(ad=a); merge(ch[a][1],ch[a][1],b);
        }
        else
        {
            pd(ad=b); merge(ch[b][0],a,ch[b][0]);
        }
        upd(ad);
    }
}
int root;
const ld pi=acosl(-1);
int se(ld t)
{
	int a,b,c;
	split(root,a,b,t-eps);
	split(b,b,c,t+eps);
	ll rs=sz[b];
	merge(b,b,c);
	merge(root,a,b);
	return rs;
}
ll aa=0;
void ins(ld t)
{
	int a,b=0,c,d;
	if(t>=pi)
	{
		ll F=se(t-pi),G=se(t);
		aa-=G*(G-1)/2*F+F*(F-1)/2*G;
		//add 1 for (t-pi,t)
		split(root,a,b,t-pi-eps);
		split(b,b,d,t);
		puu(b,1);
		addnode(c); val[c]=t;
		va[c]=sz[a]+sz[d]+F;
		upd(c);
		merge(c,c,d);
		merge(b,b,c);
		merge(root,a,b);
		++G; aa+=G*(G-1)/2*F+F*(F-1)/2*G;
	}
	else
	{
		ll F=se(t+pi),G=se(t);
		aa-=G*(G-1)/2*F+F*(F-1)/2*G;
		//count (t,t+pi)
		split(root,a,c,t);
		split(c,c,d,t+pi-eps);
		puu(a,1); puu(d,1);
		addnode(b); val[b]=t;
		va[b]=sz[c]+F; upd(b);
		merge(c,c,d);
		merge(b,b,c);
		merge(root,a,b);
		++G; aa+=G*(G-1)/2*F+F*(F-1)/2*G;
	}
}
ld gf(ld x)
{
	while(x<0) x+=pi+pi;
	while(x>=pi+pi) x-=pi+pi;
	return x; 
}
int main()
{
	int n,S,o,x,y,a,b; ll la=0;
	scanf("%d%d%d",&n,&S,&o);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if(o)
		{
			x=(x+la)%S, y=(y+la)%S;
		}
		if(a==1) x=-x;
		if(b==1) y=-y;
		if(x==0&&y==0)
		{
		    --i; --n;
		    printf("%lld\n",la);
		    continue;
		}
		ins(gf(gv(x,y)+0.3));
		la=i*(ll)(i-1)*(i-2)/6-(s2[root]-s1[root])/2+aa;
		printf("%lld\n",la);
	}
}
