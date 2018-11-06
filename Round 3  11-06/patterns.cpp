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
#define SZ
int main()
{
	int n;
	cin>>n;
	int t=0;
	while(t/2*3+t%2+1+t<=n) ++t;
	--t;
	cout<<t<<"\n";
	if(t%2==0)
	{
		for(int i=1;i<=t;++i)
		{
			int j;
			if(i>t/2) j=i-t/2+1;
			else if(i==1) j=1;
			else j=i+t/2;
			cout<<i<<" "<<j+t<<"\n";
		}
	}
	else
	{
		for(int i=1;i<=t;++i)
		{
			int j;
			if(i<=t/2+1) j=i+t/2;
			else j=i-t/2-1;
			cout<<i<<" "<<j+t<<"\n";
		}
	}
}

