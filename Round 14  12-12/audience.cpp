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
string work(int n,char s)
{
	if(n==0)
	{
		string t;
		t.pb(s);
		return t;
	}
	string t[2];
	if(s=='R')
	{
		t[1]=work(n-1,'R'),
		t[0]=work(n-1,'S');
		if((n+1)%6<3) swap(t[0],t[1]);
	}
	if(s=='S')
	{
		t[1]=work(n-1,'S'),
		t[0]=work(n-1,'P');
		if((n+3)%6<3) swap(t[0],t[1]);
	}
	if(s=='P')
	{
		t[1]=work(n-1,'P'),
		t[0]=work(n-1,'R');
		if((n+5)%6<3) swap(t[0],t[1]);
	}
	if(t[0]>t[1]) cerr<<"??\n",swap(t[0],t[1]);
	return t[0]+t[1];
}
struct node
{
ll h; int c[2],g[5];
};
node ns[300055][5];
const int MOD=917384987;
int n,op,L;
ll po[300055];
char R[SZ],S[SZ],P[SZ],A[SZ],B[SZ];
string ts[6];
void dfs(int x,int d,int j,int k)
{
	if(!x)
	{
		putchar(ns[x][j].h);
		if(!(--L)) exit(0);
		return;
	}
	for(int s=0;s<2;++s)
	{
		if(k==0&&s+48<A[d]) continue;
		dfs(x-1,d+1,ns[x][j].c[s],k||(s+48>A[d]));
	}
}
int main()
{
	po[0]=233;
	for(int i=1;i<=300000;++i)
		po[i]=po[i-1]*po[i-1]%998244353;
	for(auto c:{'R','S','P'})
		ns[0][c-'P'].h=c, ns[0][c-'P'].g[c-'P']=1;
	for(int n=1;n<=300000;++n)
		for(int s:{'R','S','P'})
		{
			int t[2];
			if(s=='R')
			{
				t[1]='R'-'P';
				t[0]='S'-'P';
				if((n+1)%6<3) swap(t[0],t[1]);
			}
			if(s=='S')
			{
				t[1]='S'-'P';
				t[0]='P'-'P';
				if((n+3)%6<3) swap(t[0],t[1]);
			}
			if(s=='P')
			{
				t[1]='P'-'P';
				t[0]='R'-'P';
				if((n+5)%6<3) swap(t[0],t[1]);
			}
			ns[n][s-'P'].c[0]=t[0];
			ns[n][s-'P'].c[1]=t[1];
			ns[n][s-'P'].h=
			(ns[n-1][t[0]].h+ns[n-1][t[1]].h*po[n-1])
			%998244353;
			for(int j=0;j<5;++j)
				ns[n][s-'P'].g[j]=(ns[n-1][t[0]].g[j]
				+ns[n-1][t[1]].g[j])%MOD;
		}
	for(int i=0;i<=5;++i)
	{
		string r=work(i,'R'),s=work(i,'S'),p=work(i,'P');
		pair<string,char> g[]={mp(r,'R'),mp(s,'S'),mp(p,'P')};
		sort(g,g+3);
		for(int j=0;j<3;++j)
			ts[i].pb(g[j].se);
	}
	cin>>n>>op;
	scanf("%s%s%s",R,S,P);
	int r=0,s=0,p=0;
	for(int c=0;R[c];++c)
		r=(r*10LL+R[c]-48)%MOD;
	for(int c=0;S[c];++c)
		s=(s*10LL+S[c]-48)%MOD;
	for(int c=0;P[c];++c)
		p=(p*10LL+P[c]-48)%MOD;
	for(auto t:ts[n%6])
	{
		int j=t-'P';
		if(ns[n][j].g['R'-'P']!=r
		||ns[n][j].g['S'-'P']!=s
		||ns[n][j].g[0]!=p)
			continue;
		if(op!=2)
		{
			cout<<ns[n][j].h<<"\n";
		}
		if(op!=1)
		{
			scanf("%s%s",A,B);
			int a=0,b=0;
			for(int i=0;A[i];++i)
				a=(a*2LL+A[i])%MOD;
			for(int i=0;B[i];++i)
				b=(b*2LL+B[i])%MOD;
			L=b-a+1; if(L<0) L+=MOD;
			dfs(n,0,j,0);
		}
		return 0;
	}
	puts("-1");
}
