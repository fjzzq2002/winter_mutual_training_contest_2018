#include <bits/stdc++.h>
#include "unnamable.h"
using namespace std;
typedef double ld;
typedef complex<ld> cp;
cp SOL(int t)
{
	int n=16; INI(n);
	auto go=[&](int w,int s=1){
		long double PI=acosl(-1);
		return cp(cosl(PI*2/(1<<w)*s),sinl(PI*2/(1<<w)*s));
	};
	cp H[2][2]; ld s=1/sqrtl(2);
	H[0][0]=H[1][0]=H[0][1]=s; H[1][1]=-s;
	for(int i=0;i<n;++i) CR(n-1-i,n-1-i,H);
	for(int i=0;i<n;++i) CU(n-1-i,1<<i);
	for(int i=n-1;i>=0;--i)
	{
		for(int j=n-1;j>i;--j)
		{
			int m=j-i+1; cp R[2][2];
			memset(&R,0,sizeof R);
			R[0][0]=1; R[1][1]=go(m,-1);
			CR(n-1-i,n-1-j,R);
		}
		CR(n-1-i,n-1-i,H);
	}
	return go(n,QR());
}
