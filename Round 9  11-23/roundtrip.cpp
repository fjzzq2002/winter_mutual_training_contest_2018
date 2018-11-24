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
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
typedef long long ll;
int fst[SZ],nxt[SZ],vb[SZ],cap[SZ],ff[SZ],M=1,N=0;
#define ad_de ad_dl
void _ad_dl(int a,int b,int c) {++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;cap[M]=c;}
void ad_dl(int a,int b,int c)
{_ad_dl(a,b,c); _ad_dl(b,a,0);}
int S,T,q[SZ],d[SZ];
bool bfs()
{
    memset(d,-1,4*(N+1));
    d[T]=0; q[1]=T; int h=1,t=2;
    while(h!=t)
    {
        int cur=q[h++];
        for(int e=fst[cur];e;e=nxt[e])
        {
            int b=vb[e];
            if(d[b]==-1&&cap[e^1])
            {
                d[b]=d[cur]+1, q[t++]=b;
                if(b==S) return 1;
            }
        }
    }
    return d[S]!=-1;
}
int dfs(int x,int f)
{
    if(f<=0) return 0;
    if(x==T) return f;
    int ca=0;
    for(int& e=fst[x];e;e=nxt[e])
    {
        int b=vb[e];
        if(d[b]+1!=d[x]) continue;
        int w=dfs(b,(cap[e]<f-ca)?cap[e]:(f-ca));
        cap[e]-=w; cap[e^1]+=w; ca+=w;
        if(ca==f) break;
    }
    if(!ca) d[x]=-1;
    return ca;
}
#define inf 2e9+3
int dinic()
{
    int ans=0;
    memcpy(ff,fst,4*(N+1));
    while(bfs())
    {
        ans+=dfs(S,inf);
        memcpy(fst,ff,4*(N+1));
    }
    return ans;
}
int n,m,a,b,c,x[SZ],y[SZ];
vector<int> s,r[4]; int rn;
void dfs(int x)
{
	if(x==b*2-1)
	{
		r[++rn]=s;
		return;
	}
	if(x%2) s.pb((x+1)/2);
	for esb(x,e,b)
		if(cap[e^1]&&e%2==0) dfs(b);
	if(x%2) s.pop_back();
}
vector<int> op[SZ];
void dfs2(int x)
{
	if(x==a*2-1||x==b*2-1)
	{
		op[(x+1)/2]=s;
		return;
	}
	if(x%2) s.pb((x+1)/2);
	for esb(x,e,b)
		if(cap[e^1]&&e%2==0) dfs2(b);
	if(x%2) s.pop_back();
}
void work(vector<int> u)
{
	set<int> s;
	for(auto x:u) s.insert(x);
	if(s.count(c)) return;
	N=n*2+1; M=1;
	for(int i=1;i<=N;++i) fst[i]=0;
	for(int i=1;i<=m;++i)
		if(s.count(x[i])||s.count(y[i]));
		else
			ad_de(x[i]*2,y[i]*2-1,1),
			ad_de(y[i]*2,x[i]*2-1,1);
	for(int i=1;i<=n;++i)
		if(!s.count(i)) ad_de(i*2-1,i*2,1);
	S=c*2; T=N;
	ad_de(a*2,T,1); ad_de(b*2,T,1);
	int g=dinic();
	if(g!=2) return;
	dfs2(S);
	vector<int> v;
	v.pb(a);
	reverse(op[a].begin(),op[a].end());
	for(auto t:op[a])
		v.pb(t);
	v.pb(c);
	for(auto t:op[b])
		v.pb(t);
	v.pb(b);
	reverse(u.begin(),u.end());
	for(auto t:u) v.pb(t);
	printf("%d\n",int(v.size()));
	for(auto r:v) printf("%d ",r);
	printf("%d\n",v[0]);
	exit(0);
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	N=n*2;
	for(int i=1;i<=m;++i)
		scanf("%d%d",x+i,y+i),
		ad_de(x[i]*2,y[i]*2-1,1),
		ad_de(y[i]*2,x[i]*2-1,1);
	for(int i=1;i<=n;++i)
		ad_de(i*2-1,i*2,(i==a||i==b)?3:1);
	S=a*2-1,T=b*2;
	int g=dinic();
	assert(g==3);
	dfs(a*2);
	for(int i=1;i<=rn;++i)
		work(r[i]);
	puts("-1");
}

