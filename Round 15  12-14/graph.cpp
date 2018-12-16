#include <bits/stdc++.h>
#include "graph.h"
using namespace std;
typedef pair<int,int> pii;
#define pb push_back
vector<int> dv[5555];
int d[5555],N,st[5555],sn,K;
int col[5555][22],bl[5555];
bool edg[55][55];
void Init(int n,int k,int Q)
{
	N=n,K=k;
	for(int i=1;i<=1600;++i) st[++sn]=i;
}
int fp(int x,bool g=1)
{
	for(auto t:dv[x])
		if(d[t]<K) return t;
	if(g)
	{
		int s=st[sn--];
		d[s]=0; dv[x].pb(s); bl[s]=x;
		memset(col[s],0,sizeof col[s]);
		return s;
	}
	else return -1;
}
void aug(int t,int l1,int l2)
{
	int x=col[t][l1];
	col[t][l1]=col[x][l1]=0;
	if(col[x][l2]) aug(x,l2,l1);
	col[x][l2]=t; col[t][l2]=x;
}
void add_real(int x,int y)
{
	int lx=1,ly=1;
	while(col[x][lx]) ++lx;
	while(col[y][ly]) ++ly;
	if(lx>ly)
		swap(x,y),swap(lx,ly);
	if(lx<ly)
		aug(y,lx,ly), ly=lx;
	++d[x],++d[y];
	col[x][lx]=y; col[y][lx]=x;
}
void add(int x,int y) {add_real(fp(x),fp(y));}
void go(int x,int A)
{
	if(!d[A])
		dv[x].erase(find(dv[x].begin(),dv[x].end(),A)),
		st[++sn]=A;
	else
	{
		int w=0;
		for(auto t:dv[x])
			if(t!=A&&d[t]<K) w=t;
		if(w)
		{
			for(int j=1;j<=K;++j) if(col[w][j])
			{
				int s=col[w][j];
				--d[s]; --d[w];
				col[w][j]=col[s][j]=0;
				add_real(A,s);
				if(!d[w])
					dv[x].erase(find(dv[x].begin(),dv[x].end(),w)),
					st[++sn]=w;
				break;
			}
		}
	}
}
void del(int x,int y)
{
	int A=0,B=0;
	for(auto t:dv[x])
		for(int j=1;j<=K&&!A;++j)
			if(bl[col[t][j]]==y)
				--d[t],A=t,col[t][j]=0;
	for(auto t:dv[y])
		for(int j=1;j<=K&&!B;++j)
			if(bl[col[t][j]]==x)
				--d[t],B=t,col[t][j]=0;
	go(x,A); go(y,B);
}
Division gen()
{
	Division t;
	memset(&t,0,sizeof t);
	for(int i=1;i<=N;++i)
		for(auto s:dv[i])
		{
			for(int j=1;j<=K;++j)
				if(col[s][j])
					t.color[i][bl[col[s][j]]-N]=j;
		}
	return t;
}
Division Modify(int x,int y)
{
	if(!edg[x][y]) add(x,y+N);
	else del(x,y+N);
	edg[x][y]=!edg[x][y];
	return gen();
}

