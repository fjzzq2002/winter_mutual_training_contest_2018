#pragma GCC optimize(3)
#pragma GCC optimize("-fno-stack-protector")
#pragma pack(1)
#include <stdio.h>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define SZ 200055
struct my_int
{
unsigned short a; unsigned char b;
my_int() {}
my_int(unsigned x) {*this=x;}
inline operator unsigned()
{
	return a|(b<<16);
}
inline my_int& operator = (unsigned x)
{
	a=x&((1u<<16)-1);
	b=x>>16; return *this;
}
};
bool operator < (my_int a,my_int b)
{
	return unsigned(a)<unsigned(b);
}
int n,ty,la;
my_int L[SZ],R[SZ],ff[SZ];
int ch[SZ][2],fa[SZ];
int gf(int x)
{
	int y=x,t;
	while(ff[y]) y=ff[y];
	while(ff[x])
		t=ff[x],ff[x]=y,x=t;
	return y;
}
int root;
void rot(int x)
{
    int y=fa[x],d=ch[y][0]==x;
    int f=fa[y]; fa[x]=f; fa[y]=x;
    if(f) ch[f][ch[f][1]==y]=x;
    int p=ch[x][d]; ch[x][d]=y; ch[y][!d]=p;
    if(p) fa[p]=y; if(y==root) root=x;
}
void splay(int x,int f)
{
    while(fa[x]!=f)
    {
        int y=fa[x];
        if(fa[y]!=f)
        {
            if(ch[fa[y]][1]==y^ch[y][0]==x) rot(x);
            else rot(y);
        }
        rot(x);
    }
    if(!f) root=x;
}
int CN=0;
bool cmp(int a,int b)
{
	if(a==b) return 0;
	++CN;
	splay(a,0); splay(b,a);
	return ch[a][1]==b;
}
my_int mi[SZ/3][17],mx[SZ/3][17];
char l2[SZ]; my_int rr[SZ];
namespace FF{
char ch,B[1<<10],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<10,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
int aa,bb;int F(){
    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}
}
#define gi FF::F()
#define BUFSIZE 5000
namespace fob {char b[BUFSIZE]={},*f=b,*g=b+BUFSIZE-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce {~foce() {pob; fflush(stdout);}} _foce;
namespace ib {char b[100];}
inline void pint(int x)
{
    if(x==0) {pc(48); return;}
    char *s=ib::b;
    while(x) *(++s)=x%10, x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}
int main()
{
	n=gi,ty=gi;
	l2[0]=-1;
	for(int i=1;i<=n;++i)
		l2[i]=l2[i>>1]+1;
	R[n+1]=n+2; L[n+2]=n+1; rr[n+2]=n+2; rr[n+1]=n+1;
	root=n+1; ch[n+1][1]=n+2; fa[n+2]=n+1;
	for(int i=1;i<=n;++i)
	{
		int s=gi;
		static pair<my_int,bool> g[200055]; int gn=0;
		g[++gn]=pair<my_int,bool>(1,0);
		g[++gn]=pair<my_int,bool>(i,0);
		while(s--)
		{
			int l=gi,r=gi;
			if(ty) l=(l+la-1)%i+1,r=(r+la-1)%i+1;
			g[++gn]=pair<my_int,bool>(l,1);
			g[++gn]=pair<my_int,bool>(r+1,1);
		}
		stable_sort(g+1,g+1+gn);
		int La=n+2,Ra=n+1,sb=0;
		for(int p=1;p<gn;++p)
		{
			if(g[p].fi==i) break;
			sb^=g[p].se;
			int L=g[p].fi,R=g[p+1].fi-1;
			if(L>R) continue;
			if(sb)
			{
				while(L<=R&&L%3!=1)
				{
					if(cmp(L,La)) La=L; ++L;
				}
				while(L<=R&&R%3!=0)
				{
					if(cmp(R,La)) La=R; --R;
				}
				if(L<=R)
				{
					int bl=(L+2)/3,br=R/3;
					if(bl<=br)
					{
						int u=l2[br-bl+1];
						int A=mi[br][u],B=mi[bl+(1<<u)-1][u];
						if(cmp(A,La)) La=A;
						if(cmp(B,La)) La=B;
					}
				}
			}
			else
			{
				while(L<=R&&L%3!=1)
				{
					if(!cmp(L,Ra)) Ra=L; ++L;
				}
				while(L<=R&&R%3!=0)
				{
					if(!cmp(R,Ra)) Ra=R; --R;
				}
				if(L<=R)
				{
					int bl=(L+2)/3,br=R/3;
					if(bl<=br)
					{
						int u=l2[br-bl+1];
						int A=mx[br][u],B=mx[bl+(1<<u)-1][u];
						if(!cmp(A,Ra)) Ra=A;
						if(!cmp(B,Ra)) Ra=B;
					}
				}
			}
		}
		int a=L[gf(La)],b=R[gf(Ra)],ri=i;
		for(int x=R[a];x!=b;x=R[x]) ff[x]=i,ri=rr[x],--la;
		R[a]=i; L[i]=a; R[i]=b; L[b]=i; ++la;
		a=rr[a]; splay(a,0); a=ch[a][1];
		while(ch[a][0]) a=ch[a][0];
		ch[a][0]=i; fa[i]=a; splay(i,0);
		rr[i]=ri; pint(la); pc(' ');
		if(i%3) continue;
		#define s s_
		int s=i/3;
		if(cmp(i-1,i))
			mx[s][0]=i,mi[s][0]=i-1;
		else
			mx[s][0]=i-1,mi[s][0]=i;
		if(cmp(i-2,mi[s][0]))
			mi[s][0]=i-2;
		else if(cmp(mx[s][0],i-2))
			mx[s][0]=i-2;
		for(int j=1;(1<<j)<=s;++j)
		{
			if(cmp(mi[s][j-1],mi[s-(1<<(j-1))][j-1]))
				mi[s][j]=mi[s][j-1];
			else mi[s][j]=mi[s-(1<<(j-1))][j-1];
			if(!cmp(mx[s][j-1],mx[s-(1<<(j-1))][j-1]))
				mx[s][j]=mx[s][j-1];
			else mx[s][j]=mx[s-(1<<(j-1))][j-1];
		}
		#undef s
	}
//	cerr<<clock()<<"ms  "<<CN<<"\n";
}
