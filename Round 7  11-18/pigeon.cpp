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
#define S 4200
#define X 2100
int n,cn[S+1][S+1],a,b,co[SZ]; pii p[SZ];
void d1(int d,int s,int s2,int mi)
{
	if(d>=a)
	{
		++cn[-s-mi+X][-s-s2+X];
		return;
	}
	co[d]=0; d1(d+1,s+p[d].fi,s2,mi);
	co[d]=1; d1(d+1,s,s2+p[d].fi-p[d].se,
	min(mi,s2-p[d].se));
}
ll ans=0;
void d2(int d,int s,int s2,int mi)
{
	if(d>=n)
	{
		ans+=cn[s+X][s+mi+X];
		return;
	}
	d2(d+1,s+p[d].fi,s2,mi);
	d2(d+1,s,s2+p[d].fi-p[d].se,
	min(mi,s2-p[d].se));
}
ll work()
{
	a=n/2; b=n-a;
	memset(cn,0,sizeof cn);
	d1(0,0,0,1000); ans=0;
	for(int i=1;i<=S;++i)
		for(int j=1;j<=S;++j)
			cn[i][j]+=cn[i][j-1];
	for(int i=1;i<=S;++i)
		for(int j=1;j<=S;++j)
			cn[i][j]+=cn[i-1][j];
	d2(a,0,0,1000); return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i].fi);
	for(int i=0;i<n;++i)
		scanf("%d",&p[i].se);
	ll aa=work();
	for(int i=0;i<n;++i)
		swap(p[i].fi,p[i].se);
	aa+=work(); aa-=(1LL<<n);
	cout<<aa<<"\n";
}
