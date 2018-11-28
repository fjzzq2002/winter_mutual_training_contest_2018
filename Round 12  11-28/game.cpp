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
int sta(string s,int p=0)
{
	bool hw=0,hb=0;
	for(int i=0;i<s.size();++i)
		hw|=s[i]=='W',hb|=s[i]=='B';
	if(!hb) return 1;
	if(!hw) return 0;
	while(s.back()=='.') s.pop_back();
	reverse(s.begin(),s.end());
	while(s.back()=='.') s.pop_back();
	reverse(s.begin(),s.end());
	s=".."+s+"..";
	int B=s.find('B'),W=B;
	while(s[W]!='W') --W;
	int ga=0,gb=0,pa=W,pb=B;
	int gm=B-W-1;
	if(gm%2==0&&gm) ++pa;
	int ans=0;
	if(s.find("WWBB")!=string::npos);
	else if(s.find("WB")!=string::npos)
	{
		string g=s;
		g[W+1]='W'; g[W]='.';
		reverse(g.begin(),g.end());
		for(auto& c:g)
			if(isupper(c)) c^='W'^'B';
		ans|=!sta(g);
		if(s.find(".WBB")!=string::npos)
		{
		int p=W-1;
		while(p>=0&&s[p]!='W') --p;
		if(p>=0&&s[p]=='W'&&s[p+1]=='.')
		{
		g=s; g[p+1]='W'; g[p]='.';
		reverse(g.begin(),g.end());
		for(auto& c:g)
			if(isupper(c)) c^='W'^'B';
		ans|=!sta(g);
		}
		}
		return ans;
	}
	while(pa+1<pb-1) ++pa,--pb;
	for(int i=W,ss=0;i>=0;--i)
		if(s[i]=='W') ga+=pa-i-(ss++);
	for(int i=B,ss=0;i<s.size();++i)
		if(s[i]=='B') gb+=i-pb-(ss++);
	return ga>gb+p;
}
int main()
{
	int T; string s;
	cin>>T;
	while(T--)
	{
		cin>>s;
		if(sta(s)) puts("W");
		else puts("B");
	}
}
