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
int n,q,a,b;
char s[105][35];
#define U 15
typedef bitset<(1<<U)> bb;
#define S 10
bb ma[105],mb[13][1<<S],ts;
int main()
{
	cin>>n>>q;
	b=min(n,U); a=n-b;
	for(int i=0;i<q;++i)
		cin>>s[i];
	for(int i=0;i<(1<<b);++i)
	{
		//[a,n)
		for(int j=0;j<q;++j)
		{
			bool ok=1;
			for(int p=0;p<b;++p)
				ok&=(s[j][p+a]-'0')!=(1-((i>>p)&1));
			if(ok) ma[j][i]=1;
		}
	}
	for(int i=0;i<q;i+=S)
	{
		int j=min(q,i+S),l=j-i;
		for(int t=0;t<(1<<l);++t)
			for(int w=0;w<l;++w)
				if(t&(1<<w)) mb[i/S][t]|=ma[w+i];
	}
	int sb=0;
	for(int e=0;e<(1<<a);++e)
	{
		memset(&ts,0,sizeof ts);
		for(int i=0;i<q;i+=S)
		{
			int j=min(q,i+S),l=j-i,u=0;
			for(int w=0;w<l;++w)
			{
				bool ok=1;
				for(int p=0;p<a&&ok;++p)
					ok&=(s[w+i][p]-'0')!=(1-((e>>p)&1));
				if(ok) u|=1<<w;
			}
			ts|=mb[i/S][u];
		}
		sb+=ts.count();
	}
	printf("%d\n",sb);
}

