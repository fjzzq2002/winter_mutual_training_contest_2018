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
const int MOD=1e9+7;
int n,k; ll po[233333];
map<vector<int>,int> aa;
bool chk(const vector<int>&v,int p)
{return p<=0||binary_search(v.begin(),v.end(),p);}
vector<int> dfs(vector<int>& s,int f)
{
	aa[s]+=f;
	vector<int> aa(n);
	int t=s.back(),p=0;
	for(int w=t+1;w<n;++w) if(chk(s,t+t-w))
	{
		s.pb(w);
		ll u=(f*po[max(w-t-t,0)]-aa[w])%MOD;
		if(u)
		{
			vector<int> r=dfs(s,u);
			for(int i=0;i<n;++i) (aa[i]+=r[i])%=MOD;
		}
		s.pop_back();
	}
	(aa[t]+=f)%=MOD;
	return aa;
}
int sb[233333],m;
ll calc(vector<int> g)
{
	g.pop_back();
//	for(auto t:g) cout<<t<<",";
//	cout<<"\b =>\n";
	ll ans=0;
	for(int i=n;i<=m;++i)
	{
		sb[i]=po[i-n];
		for(int j=n;j<i;++j) if(sb[j]&&chk(g,n-i+j))
			sb[i]=(sb[i]-sb[j]*po[max(i-j-n,0)])%MOD;
		ans+=sb[i]*(ll)po[m-i]%MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
//	cout<<ans<<"\n";
	return ans;
}
int main()
{
	cin>>m>>n>>k; ++n;
	po[0]=1;
	for(int i=1;i<=m;++i)
		po[i]=po[i-1]*k%MOD;
	vector<int> t; t.pb(0); dfs(t,1);
	ll ans=0; --n;
	for(auto&t:aa) if(t.fi.back()==n)
		ans+=calc(t.fi)*(ll)t.se%MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}
