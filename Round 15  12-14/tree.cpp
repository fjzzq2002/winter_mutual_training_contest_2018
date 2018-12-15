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
#define SZ 4444444
int k;
//old and trustworthy template
namespace ng
{
int n,s,t;
int M=0,fst[SZ],vb[SZ],nxt[SZ]; ll vc[SZ];
void ad_de(int a,int b,ll c){
++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}
ll dist[SZ];
ll gd(int x)
{
    if(dist[x]!=dist[0]) return dist[x];
    ll minn=1e18;
    for esb(x,e,b) minn=min(minn,gd(b)+vc[e]);
    return dist[x]=minn;
}
void spfa(int S)
{
    memset(dist,127/3,sizeof(dist)); dist[S]=0;
    for(int i=1;i<=n;i++) gd(i);
}
struct node {node *l,*r;ll v;int t,d;node(){d=0;l=r=0;}}
pool[SZ*4],*P=pool,*rs[SZ];
node* alc(ll v,int t)
{
    node* g=P++;
    g->v=v; g->t=t;
    return g;
}
inline int gd(node* s) {return s?s->d:0;}
node* mg(node* a,node* b)
{
    if(!a&&!b) return 0;
    node *tg=P++;
    if(!a||!b)
    {
        if(!a) *tg=*b;
        else *tg=*a;
        return tg;
    }
    if(a->v>b->v) swap(a,b);
    *tg=*a; tg->r=mg(tg->r,b);
    if(gd(tg->l)<gd(tg->r)) swap(tg->l,tg->r);
    tg->d=gd(tg->r)+1;
    return tg;
}
int fa[SZ];
vector<int> ch[SZ];
bool te[SZ];
int qs[SZ];
typedef pair<ll,node*> rec;
priority_queue<rec,vector<rec>,greater<rec> >pq;
void pushq()
{
    int h=0,t=0; qs[t++]=ng::t;
    while(h^t)
    {
        int x=qs[h++];
        rs[x]=mg(0,rs[fa[x]]);
        for esb(x,e,b) if(!te[e])
        {
            ll cb=vc[e]-(dist[x]-dist[b]);
            rs[x]=mg(rs[x],alc(cb,b));
        }
        for(int i=ch[x].size()-1;i>=0;i--)
        qs[t++]=ch[x][i];
    }
}
void pre()
{
//	cout<<s<<" "<<t<<"??\n";
//    for(int i=1;i<=n;i++)
//    	for esb(i,e,b)
//    		cout<<i<<" "<<b<<"  "<<vc[e]<<"\n"; 
    spfa(t);
//    cerr<<"++"<<dist[1]<<"\n";
    for(int i=1;i<=n;i++)
        for esb(i,e,b)
        {
            ll c=vc[e];
            if(dist[i]==dist[b]+c)
            {
                fa[i]=b; te[e]=1;
                ch[b].pb(i); break;
            }
        }
    pushq();
//    cerr<<"++\n";
    vector<ll> anss;
    anss.pb(dist[s]);
    pq.push(rec(dist[s]+rs[s]->v,rs[s]));
    for(int i=1;i<k&&!pq.empty();i++)
    {
        rec g=pq.top(); pq.pop(); anss.pb(g.fi);
        if(rs[g.se->t]) pq.push(rec(g.fi+rs[g.se->t]->v,rs[g.se->t]));
        if(g.se->l) pq.push(rec(g.fi-g.se->v+g.se->l->v,g.se->l));
        if(g.se->r) pq.push(rec(g.fi-g.se->v+g.se->r->v,g.se->r));
    }
    printf("%lld\n",anss[k-1]);
}
}
#undef SZ
#define SZ 555555
Edg
int dfa[SZ],sz[SZ],ms[SZ],v[SZ];
bool vis[SZ];
vi tmp;
int root=0,sum;
void gr(int x,int f=0)
{
    tmp.pb(x); sz[x]=1; ms[x]=0;
    for esb(x,e,b)
    {
        if(b==f||vis[b]) continue;
        gr(b,x); sz[x]+=sz[b];
        ms[x]=max(ms[x],sz[b]);
    }
    ms[x]=max(ms[x],sum-sz[x]);
    if(ms[x]<ms[root]||!root) root=x;
}
int st[SZ],ed[SZ],bb[SZ],C=0;
void d1(int x,int f=0)
{
	st[x]=++C;
	for esb(x,e,b)
		if(b!=f&&!vis[b]) d1(b,x);
	ed[x]=C;
}
void d2(int x,int f=0)
{
	for esb(x,e,b)
		if(b!=f&&!vis[b]) d2(b,x);
	ng::ad_de(bb[st[x]],bb[st[x]+1],v[x]);
	if(f) ng::ad_de(bb[st[x]],bb[ed[x]+1],0);
}
int n;
int dfz(int s=n,int bk=1,int df=0)
{
    sum=s;root=0;tmp.clear();gr(bk);
    int x=root;dfa[x]=df;
    C=0; d1(x);
	bb[1]=ng::s; bb[C+1]=ng::t;
	for(int i=2;i<=C;++i) bb[i]=++ng::n;
	d2(x); vis[x]=1;
    for esb(x,e,g)
    {
        if(vis[g]) continue;
		dfz(sz[g],g,x);
    }
    return x;
}
int main()
{
	ng::n=2; ng::s=1; ng::t=2;
	scanf("%d%d",&n,&k);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	for(int i=1;i<=n;++i)
		scanf("%d",v+i);
	dfz();
	ng::pre();
}
