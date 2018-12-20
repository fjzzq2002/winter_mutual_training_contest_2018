#include "portals.h"
#include <bits/stdc++.h>
using namespace std;
int adjust(int N,int* a,int* b)
{
	bool aa=1,bb=1; int g;
	for(int i=0;i<N;++i)
	{
		if(a[i]!=i) bb=0,g=i;
		if(a[i]!=b[i]) aa=0;
	}
	if(aa) return 0;
	if(bb) return -1;
	int s1=0,s2=0;
	for(int i=0;i<N;++i) (s1+=a[i])%=N;
	for(int i=0;i<N;++i) (s2+=b[i])%=N;
	if(s1!=s2) return -1;
	static int c[1005],t[1005];
	for(int i=0;i<N;++i) c[i]=b[i],t[i]=a[i];
	for(int j=1;(g+j)%N!=b[g];++j)
		c[(g+j)%N]=(c[(g+j)%N]+1)%N;
	#define INC(g) \
		{Inc(g); int x=t[g];\
		t[x]=(t[x]+N-1)%N;\
		t[g]=(t[g]+1)%N;}
	#define DEC(g) \
		{Dec(g); int x=t[g];\
		t[x]=(t[x]+1)%N;\
		t[g]=(t[g]+N-1)%N;}
	while(t[g]!=(g+N-1)%N) INC(g)
	int u=(g+N-1)%N;
	while(u!=(g+1)%N)
	{
		DEC(g)
		while(t[u]!=c[u]) {INC(g) DEC(g)}
		u=(u+N-1)%N;
	}
	while(t[g]!=c[g]) INC(g)
	return 0;
}
