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
struct LS
{
vector<pair<int,int*> > vs;
void operator () (int&t){vs.pb(mp(t,&t));}
~LS()
{
	sort(vs.begin(),vs.end());
	for(auto r:vs)
		*r.se=lower_bound(vs.begin(),vs.end()
		,mp(r.fi,(int*)0))-vs.begin()+2;
}
};
struct LS2
{
vector<pair<int,int*> > vs;
void operator () (int&t){vs.pb(mp(t,&t));}
~LS2()
{
	sort(vs.begin(),vs.end());
	for(int i=0;i<vs.size();++i)
		*vs[i].se=i+1; 
}
};
int sx,sy,tx,ty,n,l[SZ],r[SZ],d[SZ],u[SZ];
vector<pair<int,pii> > vx,vy;
int SX,SY,TX,TY;
#define SS 30000005
int M=0,fst[SS],vb[SS+SS],nxt[SS+SS]; bool vc[SS+SS];
void ad_de(int a,int b,int c)
{++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}
void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
void scan1x()
{
	vector<pair<pii,pii> > v;
	for(int i=1;i<=n;++i)
	{
		if(l[i]+1<r[i])
			v.pb(mp(pii(l[i]+1,1),pii(u[i],d[i]))),
			v.pb(mp(pii(r[i],0),pii(u[i],d[i])));
		v.pb(mp(pii(l[i],2),pii(u[i],d[i]))),
		v.pb(mp(pii(r[i],2),pii(u[i],d[i])));
	}
	auto S=mp(pii(sx,2),pii(sy,sy)),
	T=mp(pii(tx,2),pii(ty,ty));
	v.pb(S); v.pb(T);
	sort(v.begin(),v.end());
	set<int> s; s.insert(1); s.insert(203333);
	for(auto t:v)
	{
		if(t.fi.se==0)
			s.erase(t.se.fi),s.erase(t.se.se);
		else if(t.fi.se==1)
			s.insert(t.se.fi),s.insert(t.se.se);
		else
		{
			auto g=s.lower_bound(t.se.fi);
			int r=*g,l=*(--g);
			if(t==S) SX=vx.size();
			else if(t==T) TX=vx.size();
			vx.pb(mp(t.fi.fi,pii(l,r)));
		}
	}
}
void scan1y()
{
	vector<pair<pii,pii> > v;
	for(int i=1;i<=n;++i)
	{
		if(d[i]+1<u[i])
			v.pb(mp(pii(d[i]+1,1),pii(l[i],r[i]))),
			v.pb(mp(pii(u[i],0),pii(l[i],r[i])));
		v.pb(mp(pii(d[i],2),pii(l[i],r[i]))),
		v.pb(mp(pii(u[i],2),pii(l[i],r[i])));
	}
	auto S=mp(pii(sy,2),pii(sx,sx)),
	T=mp(pii(ty,2),pii(tx,tx));
	v.pb(S); v.pb(T);
	sort(v.begin(),v.end());
	set<int> s; s.insert(1); s.insert(203333);
	for(auto t:v)
	{
		if(t.fi.se==0)
			s.erase(t.se.fi),s.erase(t.se.se);
		else if(t.fi.se==1)
			s.insert(t.se.fi),s.insert(t.se.se);
		else
		{
			auto g=s.lower_bound(t.se.fi);
			int r=*g,l=*(--g);
			if(t==S) SY=vy.size();
			else if(t==T) TY=vy.size();
			vy.pb(mp(t.fi.fi,pii(l,r)));
		}
	}
}
#define M M_
const int M=1048576;
int N,seg[2333333];
int qj(int l,int r)
{
	int t=N++;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) ad_de(t,seg[l^1],0);
		if(r&1) ad_de(t,seg[r^1],0);
	}
	return t;
}
void upd(int x,int y)
{
	seg[x+=M]=y;
	for(x>>=1;x;x>>=1)
		seg[x]=N++,
		ad_de(seg[x],seg[x+x],0),
		ad_de(seg[x],seg[x+x+1],0);
}
void cn(vector<pair<int,pii> > a,
vector<pair<int,pii> > b,int pa,int pb)
{
	{
	LS2 l;
	for(auto&g:a)
		g.se.fi=g.se.fi*2-1,g.se.se=g.se.se*2+1,
		l(g.se.fi),l(g.se.se);
	for(auto&g:b) g.fi*=2,l(g.fi);
	}
	vector<pair<pii,pii> > t;
	for(int i=0;i<a.size();++i)
	{
		auto g=a[i];
		t.pb(mp(pii(g.fi,i+pa),g.se));
//		cout<<g.fi<<":"<<g.se.fi<<"~"<<g.se.se<<" "<<i+pa<<"\n";
	}
	for(int i=0;i<b.size();++i)
	{
		auto g=b[i];
//		cout<<g.se.fi<<"~"<<g.se.se<<":"<<i+pb<<"\n";
		t.pb(mp(pii(g.se.fi,i+pb-SZ),pii(-g.fi,0))),
		t.pb(mp(pii(g.se.se+1,-1-SZ),pii(-g.fi,1)));
	}
//	cout<<"+++\n";
	sort(t.begin(),t.end());
	for(int i=1;i<=M+M;++i) seg[i]=N++;
	for(auto g:t)
	{
		if(g.se.fi>=0)
//			cout<<"GO"<<g.fi.se<<" "<<g.se.fi<<"~"<<g.se.se<<"\n",
			ad_de(g.fi.se,qj(g.se.fi,g.se.se),1);
		else
		{
			int s=g.fi.se+SZ;
//			cout<<"UPD"<<-g.se.fi<<":"<<s<<"\n";
			if(s==-1) s=N++;
			upd(-g.se.fi,s);
		}
	}
}
int qs[SS+SS],dis[SS];
void bfs(int s)
{
	int h=SS,t=SS;
	for(int i=0;i<N;++i) dis[i]=2e9;
	dis[s]=0; qs[t++]=s;
	while(h^t)
	{
		int x=qs[h++];
		for esb(x,e,b)
		{
			if(dis[b]<=dis[x]+vc[e]) continue;
//			cout<<x<<"->"<<b<<":"<<vc[e]<<"\n";
			dis[b]=dis[x]+vc[e];
			if(vc[e]) qs[t++]=b;
			else qs[--h]=b;
		}
	}
}
int main()
{
	//cerr<<sizeof(fst)*8/1024.0/1024.0<<"M\n";
	scanf("%d%d%d%d%d",&sx,&sy,&tx,&ty,&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d%d",l+i,r+i,d+i,u+i);
	//if(0)
	{
	LS x,y;
	x(sx); x(tx); y(sy); y(ty);
	for(int i=1;i<=n;++i)
		x(l[i]),x(r[i]),y(d[i]),y(u[i]);
	}
	//now coordinates are [2,2e5+1] x [2,2e5+1]
	scan1x(); scan1y(); N=vx.size()+vy.size();
	if(vx[SX]==vx[TX]||vy[SY]==vy[TY])
	{
		puts("1");
		return 0;
	}
//	for(auto p:vx)
//		cerr<<p.fi<<","<<p.se.fi<<"~"<<p.se.se<<"\n";
//	cout<<"++\n";
//	for(auto p:vy)
//		cerr<<p.fi<<","<<p.se.fi<<"~"<<p.se.se<<"\n";
//	cout<<"++\n"<<SX<<","<<SY<<" "<<TX<<","<<TY<<"\n";
	cn(vx,vy,0,vx.size());
	cn(vy,vx,vx.size(),0);
//	cerr<<N<<"??\n";
	bfs(SX); int ans=min(dis[TX],dis[TY+int(vx.size())]);
//	cout<<SX<<":"<<dis[TX]<<" "<<dis[TY+int(vx.size())]<<"\n";
	bfs(SY+int(vx.size()));
//	cout<<dis[TX]<<"??\n";
	ans=min(ans,min(dis[TX],dis[TY+int(vx.size())]));
	printf("%d\n",ans+1);
}

