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
char s[SZ]; int r,n;
ll f[44][44][44];
char u[]="xo";
ll a1()
{
	f[0][0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int a=0;a<=n;++a)
		for(int b=0;b<=n;++b) if(f[i-1][a][b])
		for(int j=0;j<2;++j)
		{
			if(s[i]==u[!j]) continue;
			if(j==0) //x
				f[i][a+1][b]+=f[i-1][a][b];
			else //o
			{
				if(a<=1)
					f[i][a][b+1]+=f[i-1][a][b];
				else
					f[i][a-1][b]+=f[i-1][a][b];
			}
		}
	}
	ll ans=0;
	for(int a=0;a<=n;++a)
		for(int b=max(r,a+1);b<=n;++b)
			if(f[n][a][b])//&&b>=r&&b-a>0)
				ans+=f[n][a][b];
	return ans;
}
ll g[44][44][44];
ll a2()
{
	if(n&1) return 0;
	for(int i=1;i<=n;++i)
	{
		g[i][i-1][0]=1;
		for(int j=i;j<=n;++j)
			for(int k=0;k<=n;++k) if(g[i][j-1][k])
			{
				if(s[j]!='x') //o
					g[i][j][k+1]+=g[i][j-1][k];
				if(s[j]!='o') //x
					g[i][j][k]+=g[i][j-1][k];
			}
	}
	ll ans=0;
	for(int a=1;a<=n;++a)
		for(int b=max(r-1,a);a+b+2<=n;++b)
		{
			if(g[1][a][a]&&g[n-b+1][n][0]
			&&s[a+1]!='o'&&s[n-b]!='x'
			&&n/2-a-1>=0);else continue; //&&b+1>=r
			//o-x=b-a,o+x=n-a-b-2
			ans+=g[a+2][n-b-1][n/2-a-1];
		}
	return ans;
}
int main()
{
	scanf("%s%d",s+1,&r);
	n=strlen(s+1);
	cout<<a1()+a2()<<'\n';
}

