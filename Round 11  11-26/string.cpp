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
#define SZ 500099
#define S 21
pii us[S][SZ+SZ];
int l2[SZ+SZ];
struct SA
{
int n,k,sa[SZ],t[SZ],rnk[SZ],qzh[SZ],
tmpsa[SZ],tmpr[SZ],h[SZ],mi[S][SZ]; char s[SZ];
bool same(int a,int b,int p) {return t[a]==t[b]&&t[a+p]==t[b+p];}
void pre(int m=500)
{
	n=strlen(s); s[++n]=0;
	for(int i=0;i<n;i++) rnk[i]=s[i], ++qzh[rnk[i]];
	for(int i=1;i<m;i++) qzh[i]+=qzh[i-1];
	for(int i=n-1;i>=0;i--) sa[--qzh[rnk[i]]]=i;
	for(int j=1;j<=n;j<<=1)
	{
		int cur=-1;
		for(int i=n-j;i<n;i++) tmpsa[++cur]=i;
		for(int i=0;i<n;i++) if(sa[i]>=j) tmpsa[++cur]=sa[i]-j;
		for(int i=0;i<n;i++) tmpr[i]=rnk[tmpsa[i]];
		for(int i=0;i<m;i++) qzh[i]=0;
		for(int i=0;i<n;i++) ++qzh[tmpr[i]];
		for(int i=1;i<m;i++) qzh[i]+=qzh[i-1];
		for(int i=n-1;i>=0;i--) t[i]=rnk[i], sa[--qzh[tmpr[i]]]=tmpsa[i];
		m=0;
		for(int i=0;i<n;i++)
			rnk[sa[i]]=(i>0&&same(sa[i],sa[i-1],j))?m:++m;
		++m;
	}
	for(int i=0;i<n;i++) rnk[sa[i]]=i;
	int p=0;
	for(int i=0;i<n;i++)
	{
		if(p) --p;
		int ls=sa[rnk[i]-1];
		while(s[ls+p]==s[i+p]) p++;
		h[rnk[i]]=p;
	}
	--n;
	for(int i=1;i<=n;i++) sa[i-1]=sa[i];
	for(int i=0;i<n;i++) rnk[sa[i]]=i;
	for(int i=2;i<=n;i++) h[i-1]=h[i];
	h[n]=sa[n]=0;
	for(int i=0;i<n;i++)
		mi[0][i]=h[i];
	for(int j=1;j<S;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
}
inline int gmin(int a,int b)
{
	int l=l2[b-a+1];
	return min(mi[l][a],mi[l][b-(1<<l)+1]);
}
int lcp(int a,int b)
{
	if(a==b) return n-a;
	if(rnk[a]>rnk[b]) swap(a,b);
	return gmin(rnk[a]+1,rnk[b]);
}
}A,B;
struct PTree
{
int ch[SZ][26],len[SZ],fail[SZ],
s[SZ],cl,an,lst,rp[SZ];
int addn(int l) {len[an]=l; return an++;}
PTree()
{
	cl=an=lst=0;
	memset(ch,0,sizeof(ch));
	addn(0); addn(-1);
	fail[0]=1; s[0]=-233;
}
int gfail(int x,int l)
{
	while(s[l-len[x]-1]!=s[l]) x=fail[x];
	return x;
}
void add(int c)
{
	s[++cl]=c;
	int cp=gfail(lst,cl);
	if(!ch[cp][c])
	{
		int nn=addn(len[cp]+2);
		fail[nn]=ch[gfail(fail[cp],cl)][c];
		ch[cp][c]=nn;
	}
	rp[cl]=lst=ch[cp][c];
}
vector<int> son[SZ];
int up[S][SZ];
void pre()
{
	for(int i=2;i<an;++i)
		son[fail[i]].pb(i);
	for(int i=0;i<an;++i) up[0][i]=fail[i];
	for(int i=1;i<S;++i)
		for(int j=0;j<an;++j)
			up[i][j]=up[i-1][up[i-1][j]];
}
int mpal(int l,int r)
{
	int t=rp[r];
	if(len[t]<=r-l+1) return len[t];
	for(int j=S-1;j>=0;--j)
		if(len[up[j][t]]>r-l+1)
			t=up[j][t];
	return len[fail[t]];
}
inline bool pal(int l,int r)
{return mpal(l,r)==r-l+1;}
int dep[SZ],fs[SZ],C=0;
void dfs(int x)
{
	us[0][C]=pii(dep[x],x); fs[x]=C++;
	for(auto b:son[x])
		dep[b]=dep[x]+1,dfs(b),
		us[0][C++]=pii(dep[x],x);
}
pii lca(int a,int b)
{
	a=fs[a],b=fs[b];
	if(a>b) swap(a,b);
	int g=l2[b-a+1];
	return min(us[g][a],us[g][b-(1<<g)+1]);
}
int plca(int a,int b)
{
	if(a>b) swap(a,b);
	int g=l2[b-a+1];
	return min(us[g][a],us[g][b-(1<<g)+1]).fi;
}
void glca()
{
	dep[0]=1; dfs(0);
	for(int i=0;i+1<S;++i)
		for(int j=0;j+(1<<(i+1))<=C;++j)
			us[i+1][j]=min(us[i][j],us[i][j+(1<<i)]);
}
}a,b;
char s[SZ]; int n;
vector<int> os[SZ];
#define G 10500005
int mi[G],mx[G],ch[G][2],segn=0;
int lt=-1,gn=0;
pii g[SZ*3];
int mg(int a,int b)
{
	if(!a&&!b) return 0;
	if(!b)
	{
		if(lt==0) g[gn].se=mx[a];
		else g[++gn]=pii(mi[a],mx[a]);
		lt=0; return a;
	}
	if(!a)
	{
		if(lt==1) g[gn].se=mx[b];
		else g[++gn]=pii(mi[b],mx[b]);
		lt=1; return b;
	}
	if(ch[a][0]||ch[a][1])
	{
		ch[a][0]=mg(ch[a][0],ch[b][0]);
		ch[a][1]=mg(ch[a][1],ch[b][1]);
		mi[a]=min(mi[ch[a][0]],mi[ch[a][1]]);
		mx[a]=max(mx[ch[a][0]],mx[ch[a][1]]);
		return a;
	}
	if(lt==0) g[gn].se=mx[a];
	else g[++gn]=pii(mi[a],mx[a]); lt=0;
	if(lt==1) g[gn].se=mx[b];
	else g[++gn]=pii(mi[b],mx[b]); lt=1;
	return a;
}
int gen(int p,int l,int r)
{
	int x=++segn; mi[x]=mx[x]=p;
	if(l==r) return x;
	int m=(l+r)>>1;
	if(p<=m) ch[x][0]=gen(p,l,m);
	else ch[x][1]=gen(p,m+1,r);
	return x;
}
int ro[SZ]; ll aa[SZ],ans=0;
void dfsa(int x)
{
	for(auto bb:a.son[x]) dfsa(bb);
	int &t=ro[x]; aa[x]=0;
	for(auto o:os[x])
	{
		int w=gen(b.fs[o],0,b.C-1);
		lt=-1; gn=0; t=mg(t,w);
		aa[x]+=b.dep[o];
		for(int i=1;i+2<=gn;++i)
			aa[x]+=b.plca(g[i].se,g[i+2].fi);
		for(int i=1;i+1<=gn;++i)
			aa[x]-=b.plca(g[i].se,g[i+1].fi);
	}
	for(auto bb:a.son[x])
	{
		lt=-1; gn=0; t=mg(t,ro[bb]);
		aa[x]+=aa[bb];
		for(int i=1;i+2<=gn;++i)
			aa[x]+=b.plca(g[i].se,g[i+2].fi);
		for(int i=1;i+1<=gn;++i)
			aa[x]-=b.plca(g[i].se,g[i+1].fi);
	}
	if(t&&x) ans+=aa[x]-1;
}
int si[SZ];
bool cov[6666666];
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
__gnu_pbds::gp_hash_table<ll,pii> ms;
const int ps[2]={999000011,864888601};
ll po[2][SZ],qz[2][SZ];
void build_hash(char*s,int N)
{
	for(int w=0;w<2;++w)
	{
		po[w][0]=1; qz[w][0]=0;
		for(int j=1;j<=N;++j)
			po[w][j]=po[w][j-1]*233LL%ps[w];
		for(int j=1;j<=N;++j)
			qz[w][j]=(qz[w][j-1]*233LL+s[j-1])%ps[w];
	}
}
ll ghash(int l,int r)
{
	ll a=r-l+1;
	for(int w=0;w<2;++w)
	{
		int u=(qz[w][r+1]-qz[w][l]*(ll)po[w][r-l+1])%ps[w];
		if(u<0) u+=ps[w]; a=a*1000000007LL+u;
	}
	return a;
}
void chk(int l,int r,int p)
{
	pii&u=ms[ghash(l,r)];
	++l, ++r; //convert to 1-based
	if(!u.se)
	{
		int pa=a.mpal(l,r);
		if(pa==r-l+1) u.fi=1;
		else if(a.pal(l,r-pa)||b.pal(n+1-r,
		n+1-l-b.mpal(n+1-r,n+1-l))) u.fi=2;
		else u.fi=0;
	}
	u.se=max(u.se,p);
}
ll s2(ll t) {return t*(t+1)/2;}
int main()
{
	l2[0]=-1;
	for(int i=1;i<SZ+SZ;++i)
		l2[i]=l2[i>>1]+1;
	memset(mi,127/3,sizeof mi);
	memset(mx,-127/3,sizeof mx);
	scanf("%s",s);
	n=strlen(s);
	build_hash(s,n);
	for(int i=0;i<n;++i)
		A.s[i]=s[i],a.add(s[i]-'a');
	for(int i=n-1;i>=0;--i)
		B.s[n-1-i]=s[i],b.add(s[i]-'a');
	for(int i=1;i<n;++i)
		os[a.rp[i]].pb(b.rp[n-i]);
	a.pre(); b.pre(); b.glca();
	dfsa(0);
	A.pre(); B.pre();
	for(int i=1;i<=n;++i)
		si[i]=si[i-1]+n/i-1;
	int ca=0,cb=0,cc=0;
	for(int len=1;len+len<=n;++len)
	{
		int l=-1,r=-1;
		for(int i=len-1;i+len<n;i+=len)
		{
			if(i<=r) continue;
			int L=B.lcp(n-i-1,n-i-len-1),R=A.lcp(i,i+len);
			if(L+R-1<len) continue;
			l=i-L+1; r=i+R-1;
			if(cov[si[len-1]+(i+1)/len])
				continue;
			++ca; cb+=len; cc+=r-l+2-len;
			for(int x=len+len;l+x+x-1<=r+len;x+=len)
				cov[si[x-1]+l/x+1]=1;
			for(int t=0;t<len&&l+t+len-1<=r;++t)
				chk(l+t,l+t+len-1,(r-l-t-len+1)/len+2);
		}
	}
	int cp=0,cq=0,ct=0;
	for(auto t:ms)
	{
		if(t.se.fi==1)
			ans-=s2(t.se.se-2),++cp;
		else if(t.se.fi==2)
			ans-=s2(t.se.se-1),++cq;
		else ++ct;
	}
	cout<<ans<<"\n";
}

