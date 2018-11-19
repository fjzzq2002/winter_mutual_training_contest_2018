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
int n,l,s,a[SZ];
ll gans()
{
    if(!l)
    {
        if(s==1) return a[n]-a[1];
        return 8e18;
    }
    if(l==n-1)
    {
        if(s==n) return a[n]-a[1];
        return 8e18;
    }
    if(l<s)
        return (ll)a[s]-a[1]+a[n]-a[1];
    int w=l-(s-1);
    ll ans=5e18,sw=0,su=0;
    for(int i=s+2;i<=n;++i)
        sw+=a[i]-a[i-1];
    priority_queue<ll,vector<ll>,greater<ll> > A,B;
    for(int i=s+1;i<=n;++i)
    {
        if(i>s+1)
            sw-=a[i]-a[i-1];
        int t=w+i-n;
        if(t>=0)
        {
            while(A.size()<t&&B.size())
            {
                ll w=B.top(); A.push(w);
                B.pop(); su+=w;
            }
            if(A.size()==t) ans=min(ans,su*2+sw);
        }
        if(i>s+1)
            B.push(a[i]-a[i-1]);
    }
    ans+=(ll)a[s]-a[1]+a[n]-a[1];
    return ans;
}
int main()
{
    scanf("%d%d%d",&n,&l,&s);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    ll ans=gans();
    reverse(a+1,a+1+n);
    l=n-1-l; s=n+1-s;
    for(int i=1;i<=n;++i)
        a[i]=-a[i];
    ans=min(ans,gans());
    if(ans>4e18) ans=-1;
    printf("%lld\n",ans);
}
