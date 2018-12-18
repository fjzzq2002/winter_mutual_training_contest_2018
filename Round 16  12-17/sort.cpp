#include <bits/stdc++.h>
using namespace std;
#include "sort.h"
#define SZ 1234567
int K,c[SZ],d[SZ],ta[SZ],o[SZ];
typedef pair<int,int> pii;
#define fi first
#define se second
typedef long long ll;
vector<pii> v[SZ];
#define pb push_back
vector<pii> g[SZ]; int m=0;
void shu(int*a,int n)
{
	srand(123113+n);
	for(int s=1;(s==1)||rand()%3;++s)
		random_shuffle(a,a+n);
}
int e[SZ],T;
void go(int*a,int l,int r)
{
	if(r-l+1<=1) return;
	if(r-l+1<=K)
	{
		super_sort(a+l,r-l+1,c);
		for(int i=0;i<=r-l;++i) a[i+l]=c[i];
		return;
	}
	shu(a+l,r-l+1);
	int s=min((r-l+1)/K,K/2);
	++T;
	for(int i=0;i<s;++i) e[a[i+l]]=T;
	vector<int> h[18],o,p; o.clear();
	for(int i=l+s;i<=r;++i)
	{
		p.pb(a[i]);
		if(p.size()>=K-s||i==r)
		{
			for(int j=0;j<s;++j) p.pb(a[j+l]);
			super_sort(&p[0],p.size(),&p[0]);
			int q=0,f=o.empty();
			for(auto w:p)
			{
				if(e[w])
				{
					if(f) o.pb(w); ++q;
				}
				else h[q].pb(w);
			}
			p.clear();
		}
	}
	int u=l;
	for(int i=0;i<=s;++i)
	{
		int L=u;
		for(auto p:h[i]) a[u++]=p;
		go(a,L,u-1);
		if(i!=s) a[u++]=o[i];
	}
}
void sort(int id, int n, int k, int *a)
{
	K=k;
	for(int i=0;i<n;++i) a[i]=i;
	for(int i=0;i<n;++i) swap(a[i],a[i/2]);
	for(int i=0;i<n;++i) swap(a[i],a[i/3]);
	for(int i=0;i<n;++i) swap(a[i],a[i/2]);
	for(int i=0;i<n;++i)
		swap(a[i],a[((i*100LL+233)*
		(i*100LL+23)+1)%998244353%(i+1)]);
	go(a,0,n-1);
}
