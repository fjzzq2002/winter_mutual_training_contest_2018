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
#define SZ 1055555
int n,q,x[SZ],l[SZ],r[SZ],ls[SZ],aa[SZ];
vector<int> rs[SZ];
map<int,int> ms;
int bs[SZ];
void edt(int x,int y)
{
	for(;x<=n;x+=x&-x) bs[x]^=y;
}
int qry(int x)
{
	int s=0;
	for(;x>=1;x-=x&-x) s^=bs[x];
	return s;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",x+i);
		int&u=ms[x[i]];
		ls[i]=u; u=i;
	}
	for(int i=1;i<=q;++i)
		scanf("%d%d",l+i,r+i),rs[r[i]].pb(i);
	int p=0;
	for(int i=1;i<=n;++i)
	{
		p^=x[i]; edt(ls[i]+1,x[i]);
		for(auto t:rs[i]) aa[t]=qry(l[t])^p;
	}
	for(int i=1;i<=q;++i)
		printf("%d\n",aa[i]);
}

