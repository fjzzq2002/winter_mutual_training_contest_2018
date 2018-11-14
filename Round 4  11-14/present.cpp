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
int n,m,g[23333];
char s[7][155];
const int MOD=998244353;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return x;
}
int f[2][2][1222][1<<6];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%s",s[i]);
	int c=0,u=1;
	f[0][0][0][0]=1;
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			c^=1;
			for(int w=0;w<2;++w)
				for(int g=0;g<=u+2;++g)
					memset(f[c][w][g],0,sizeof f[0][0][0]);
			int t;
			for(int w=0;w<2;++w)
				for(int g=0;g<=u;++g)
					for(int h=0;h<(1<<n);++h) if(t=f[c^1][w][g][h])
					{
						(f[c][0][g+((h>>j)&1)+(j&&w)][h&(~(1<<j))]+=t)%=MOD;
						if(s[j][i]=='*')
							(f[c][1][g+(i!=0)+(j!=0)][h|(1<<j)]-=t)%=MOD;
					}
			u+=2;
		}
	}
	for(int w=0;w<2;++w)
		for(int g=0;g<=u;++g)
			for(int h=0;h<(1<<n);++h)
				(::g[g]-=f[c][w][g][h])%=MOD;
	++g[0];
	ll ans=0;
	for(int i=0;i<=n*m*2;++i) if(g[i])
		ans+=g[i]*qp(i,MOD-2),ans%=MOD;
	ans=ans*(n*(m-1)+m*(n-1))%MOD;
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}

