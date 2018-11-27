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

char tmp__[2333333];
vector<string> cs;

#define pri(...) sprintf(tmp__,__VA_ARGS__),cs.back()+=tmp__
#define Q 1000000
string pred[Q+2];
map<ll,string> rs;
string cons(ll x)
{
	if(x==-1) return "01:";
	if(x<0)
		return cons(-x)+cons(-1)+"*";
	if(x<=Q)
		return pred[x];
	int b=9;
	for(int i=9;i>=5;--i)
		if(x%i==0) {b=i; break;}
	string w=cons(x/b);
	w.pb(b+48); w.pb('*');
	if(x%b) w.pb(x%b+48),w.pb('+');
	return w;
}
void pull(ll x)
{
	string t=cons(x);
	pri("%s",t.c_str());
}
int sn;
struct LL
{
int a;
void _alloc() {a=++sn;}
LL() {_alloc();}
void in()
{
	pull(a); pri(">");
}
void out() const
{
	pull(a); pri("<");
}
LL(ll x)
{
	_alloc(); pull(x); in();
}
LL(const LL& x)
{
	_alloc(); *this=x;
}
LL& operator = (ll b)
{
	pull(b); in(); return *this;
}
LL& operator = (const LL& b)
{
	b.out(); in(); return *this;
}
};
LL& genLL()
{
	LL*t=new LL();
	return *t;
}
#define gen_op2(_) \
LL& operator _ (const LL&a,const LL&b) \
{\
	LL& c=genLL(); c=a; \
	c _##=b; return c;\
}
#define gen_op(_) \
LL& operator _##= (LL&a,const LL&b) \
{\
	pull(a.a); pri("0^<");\
	b.out(); pri(#_ "1v>"); return a;\
}\
gen_op2(_)
gen_op(+)
gen_op(-)
gen_op(*)
gen_op(/)
LL& operator %= (LL&a,const LL&b)
{
	LL c=a; c/=b;
	c*=b; a-=c;
	return a;
}
gen_op2(%)
istream& operator >> (istream&t,LL& u)
{
	pri("r"); u.in(); return t;
}
ostream& operator << (ostream&t,const LL& u)
{
	u.out(); pri("p"); return t;
}
//dcmp(a-b)
LL& cmp(const LL&a,const LL&b)
{
	a.out(); b.out();
	LL& c=genLL();
	pri(":"); c.in();
	return c;
}
LL& abs(const LL&a)
{
	a.out(); pri("0^0:*");
	LL&c=genLL(); c.in();
	return c;
}
struct Initer{Initer(){
	//init start
	cs.pb("");
	//what about pred?
	for(int i=0;i<=9;++i) pred[i].pb(i+48);
	ld avr=0;
	for(int i=10;i<=Q;++i)
	{
		for(int j=-9;j<=9;++j)
			for(int t=1;t<=9;++t)
			{
				int w=i-j;
				if(w%t) continue;
				w/=t; if(w>=i) continue;
				if(pred[i].size()&&pred[w].size()>=pred[i].size())
					continue;
				string s=pred[w];
				if(t>1) s.pb(t+48),s.pb('*');
				if(j)
				{
					if(j>0) s.pb(j+48),s.pb('+');
					else s.pb(-j+48),s.pb('-');
				}
				if(!pred[i].size()||s.size()<pred[i].size())
					pred[i]=s;
			}
		if(!pred[i].size()) throw "GG";
	}
	for(int i=1;i<=Q;++i)
		avr+=pred[i].size();
	cerr<<"pred.avr="<<avr/Q<<"\n";
	//init end
}}_;
//do f; while(x>0);
void DoWhile(LL&x,string f)
{
	cs.pb("");
	for(int i=0;;++i)
	{
		cs.back().clear();
		pri("1");
		x.out();
		pri("0:-");
		pull(-(i+(ll)f.size()));
		pri("?"); 
		if((int)cs.back().size()<=i)
		{
			cs.back().insert(cs.back().begin(),i-int(cs.back().size()),' ');
			string g=f+cs.back();
			cs.pop_back();
			cs.back()+=g; return;
		}
	}
}
//if(x) f;
void If(LL&x,string f)
{
	cs.pb("");
	cs.back().clear();
	x.out();
	pull(f.size());
	pri("?");
	string g=cs.back()+f;
	cs.pop_back();
	cs.back()+=g;
}
#define CS cs.back()
#define Begin cs.pb("");
#define CONNECTION(text1,text2) text1##text2
#define CONNECT(text1,text2) CONNECTION(text1,text2)
#define End_Dowhile(x) \
string CONNECT(dowhiletmps_,__LINE__)=cs.back();cs.pop_back();DoWhile(x,CONNECT(dowhiletmps_,__LINE__));
#define End_If(x) \
string CONNECT(doiftmps_,__LINE__)=cs.back();cs.pop_back();If(x,CONNECT(doiftmps_,__LINE__));
struct Arr
{
int x;
Arr(int s)
{
	x=++sn; sn+=s;
}
Arr(int,int) {} //a hack, do not use it normally
LL& get(const LL&a)
{
	//return copy(Arr(a))
	pull(x); a.out();
	pri("+<"); LL& t=genLL();
	t.in(); return t;
}
void set(const LL&a,const LL&b)
{
	//Arr(a)=b
	b.out(); pull(x);
	a.out(); pri("+>");
}
};
LL& cmin(const LL&x,const LL&y)
{
	return (x+y-abs(x-y))/2;
}
LL& operator ++ (LL&a)
{
	a.out(); pri("1+"); a.in(); return a;
}
LL& operator -- (LL&a)
{
	a.out(); pri("1-"); a.in(); return a;
}
void work(int o)
{
	if(o==0) //testing
	{
		work(11);
		return;
	}
	else if(o==1)
	{
		LL a,b;
		cin>>a>>b;
		cout<<(a+b);
		cout<<CS<<"\n";
	}
	else if(o==2)
	{
		LL a,b;
		cin>>a>>b;
		cout<<(a%b);
		cout<<CS<<"\n";
	}
	else if(o==3)
	{
		LL a(1),b,c,x;
		cin>>x>>b>>c;
		Begin
			a=a*(1+(b%2)*(x-1))%c,
			x=x*x%c,b/=2;
		End_Dowhile(b);
		a%=c; cout<<a;
		cout<<CS<<"\n";
	}
	else if(o==4)
	{
		LL n,i,t,j; Arr a(103);
		cin>>n; i=n;
		Begin
			cin>>t;
			a.set(i,t);
			i-=1;
		End_Dowhile(i)
		i=n;
		Begin
			j=i;
			Begin
				LL x=a.get(i),
				y=a.get(j);
				LL s=x+y,d=x-y;
				LL O=cmp(d,0); d=d*O;
				a.set(i,(s-d)/2);
				a.set(j,(s+d)/2);
				j-=1;
			End_Dowhile(j)
			i-=1;
		End_Dowhile(i)
		cout<<a.get((n+1)/2);
		cout<<CS<<"\n";
	}
	else if(o==5) work(4);
	else if(o==6)
	{
		LL n,m,s=0,a,b,c,j;
		cin>>n>>m;
		Arr d(42),u(503),v(503),w(503);
		LL inf=4e18;
		LL i=n;
		Begin
			d.set(i,inf);
			i-=1;
		End_Dowhile(i)
		d.set(1,0);
		i=m;
		Begin
			cin>>a>>b>>c;
			u.set(i,a);
			v.set(i,b);
			w.set(i,c);
			i-=1;
		End_Dowhile(i)
		i=cmin(n,20);
		Begin
			j=m;
			Begin
			{
				a=u.get(j),b=v.get(j),c=w.get(j);
				auto A=d.get(a),B=d.get(b);
				d.set(a,cmin(A,B+c));
				d.set(b,cmin(B,A+c));
				j-=1;
			}
			End_Dowhile(j)
			i-=1;
		End_Dowhile(i)
		i=n;
		Begin
			s+=d.get(i);
			i-=1;
		End_Dowhile(i)
		cout<<s;
		cout<<CS<<"\n";
	}
	else if(o==7) work(6);
	else if(o==10)
	{
		Arr p(-1,-1);
		p.x=0; sn=1000;
		LL i=0,o=48;
		pull('0'); pri("P");
		{
		Begin
			i+=1;
			LL&t=p.get(i);
			LL _=9,pp=t/_,a=pp/_+o,b=pp%_+o,c=t%_+o;
			pull('1'); pri("P");
			pull('+'); pri("P");
			pull('0'); pri("P");
			pull('^'); pri("P");
			a.out(); pri("P");
			pull('9'); pri("P");
			pull('*'); pri("P");
			b.out(); pri("P");
			pull('+'); pri("P");
			pull('9'); pri("P");
			pull('*'); pri("P");
			c.out(); pri("P");
			pull('+'); pri("P");
			pull('1'); pri("P");
			pull('v'); pri("P");
			pull('>'); pri("P");
		End_Dowhile(t);
		}
		i=1; LL t=p.get(i);
		Begin
			t.out(); pri("P");
			i+=1; t=p.get(i);
		End_Dowhile(t);
		string u="";
		u.pb('0');
		vector<int> cc;
		for(auto c:CS) cc.pb(c); cc.pb(0);
		for(auto c:cc)
		{
			u+="1+0^";
			u.pb(c/81+48);
			u+="9*";
			u.pb(c/9%9+48);
			u+="+9*";
			u.pb(c%9+48);
			u+="+1v>";
		}
		cout<<u<<CS<<"\n";
	}
	else if(o==8)
	{
		LL n,m,u,v,w;
		cin>>n>>m;
		LL i=m,sn=0,pn=0;
		LL g=n,x,e,ne,t,b,fb,fg;
		Arr s1(102),s2(102),p(102),nv(102);
		#define Pg(Z) \
		Arr Z##fst(102),Z##nxt(3005),Z##vb(3005); LL Z##M=0;\
		auto Z##ad_de=[&](LL&u,LL&v)\
		{\
			Z##M+=1; Z##nxt.set(Z##M,Z##fst.get(u));\
			Z##fst.set(u,Z##M); Z##vb.set(Z##M,v);\
		};
		Pg(Z) Pg(F)
		Begin
			cin>>u>>v;
			Zad_de(u,v);
			Fad_de(v,u);
			i-=1;
		End_Dowhile(i);
	//	++sn; s1.set(sn,a); s2.set(sn,b);
		#define PUSH(a,b) \
		sn.out(); pri("1+0^0^"); sn.in();\
		a.out(); pri("1v"); pull(s1.x); pri("+>");\
		b.out(); pri("1v"); pull(s2.x); pri("+>");
		i=n;
		Begin
			nv.set(i,1);
			i-=1;
		End_Dowhile(i);
		pn=0;
		Begin
			Begin
				fg=Zfst.get(g);
				nv.set(g,0);
				PUSH(g,fg)
				Begin
					x=s1.get(sn),e=s2.get(sn); --sn;
					Begin
						ne=Znxt.get(e); PUSH(x,ne)
						b=Zvb.get(e),t=nv.get(b);
						Begin
							nv.set(b,0);
							fb=Zfst.get(b);
							PUSH(b,fb)
						End_If(t);
					End_If(e);
					Begin
						p.set(++pn,x);
					End_If(1-cmp(e,0));
				End_Dowhile(sn);
			End_If(nv.get(g));
			--g;
		End_Dowhile(g);
		i=n;
		Begin
			nv.set(i,1);
			i-=1;
		End_Dowhile(i);
		i=pn; LL ans=0;
		Begin
			g=p.get(i);
			Begin
				fg=Ffst.get(g);
				nv.set(g,0);
				PUSH(g,fg) ++ans;
				Begin
					x=s1.get(sn),e=s2.get(sn); --sn;
					Begin
						ne=Fnxt.get(e); PUSH(x,ne)
						b=Fvb.get(e),t=nv.get(b);
						Begin
							nv.set(b,0);
							fb=Ffst.get(b);
							PUSH(b,fb)
						End_If(t);
					End_If(e);
				End_Dowhile(sn);
			End_If(nv.get(g));
			i-=1;
		End_Dowhile(i);
		cout<<ans;
		cout<<CS<<"\n";
		#undef Pg
		#undef PUSH
	}
	else if(o==9) work(8);
	else if(o==11)
	{
		const int P=2117;
		LL ret=P,cp=0,tmp,cc_,good=1,sn=0,o,triggered=0; ::sn=127;
		Arr code(300),st(500),mem(65536);
		Begin
			pri("R"); tmp.in();
			code.set(cp,tmp);
			++cp; cc_=tmp+1;
		End_Dowhile(cc_);
		auto push=[&](LL&v)->void {v.out();};
		auto pop=[&]()->LL& {LL&t=genLL(); t.in(); return t;};
		auto DoPush=[&]()->void {push(o-48);};
		auto DoPrintInt=[&]()->void {cout<<pop();};
		auto DoAdd=[&]()->void {push(pop()+pop());};
		auto DoSub=[&]()->void {auto w=pop();push(pop()-w);};
		auto DoMul=[&]()->void {push(pop()*pop());};
		auto DoDiv=[&]()->void {auto w=pop();push(pop()/w);};
		auto DoCmp=[&]()->void
		{auto a=pop(); push(cmp(pop(),a));};
		auto DoGoto=[&]()->void {cp+=pop();};
		auto DoGotoIfZero=[&]()->void
		{
			auto w=pop(),s=pop();
			Begin
				w-=w;
			End_If(s); cp+=w;
		};
		auto DoCall=[&]()->void
		{st.set(sn,cp); ++sn; cp=pop();};
		auto DoReturn=[&]()->void
		{--sn; cp=st.get(sn);};
		auto DoPeek=[&]()->void
		{auto g=pop(); push(mem.get(g));};
		auto DoPoke=[&]()->void
		{auto g=pop(); mem.set(g,pop());};
		auto DoPick=[&]()->void {pri("^");};
		auto DoRoll=[&]()->void {pri("v");};
		auto DoDrop=[&]()->void {pop();};
		auto DoEnd=[&]()->void {good=0;};
		auto DoNothing=[&]()->void {};
		auto loadup=[&]()->void
		{
			map<char,int> ms;
			#define insert_ops(a,b) \
			{pri(" "); ms[a]=cs.back().size(); pri(" ");\
			Begin\
				b(); ret.out(); pri("c");\
			End_If(triggered);}
			insert_ops(' ', DoNothing);
			insert_ops('p', DoPrintInt);
			insert_ops('0', DoPush);
			for(int i='1';i<='9';++i)
				ms[i]=ms['0'];
			insert_ops('+', DoAdd);
			insert_ops('-', DoSub);
			insert_ops('*', DoMul);
			insert_ops('/', DoDiv);
			insert_ops(':', DoCmp);
			insert_ops('g', DoGoto);
			insert_ops('?', DoGotoIfZero);
			insert_ops('c', DoCall);
			insert_ops('$', DoReturn);
			insert_ops('<', DoPeek);
			insert_ops('>', DoPoke);
			insert_ops('^', DoPick);
			insert_ops('v', DoRoll);
			insert_ops('d', DoDrop);
			insert_ops('!', DoEnd);
			for(auto w:ms)
			{pull(w.se); pull(w.fi); pri(">");}
		};
		loadup(); cp=0;
		triggered=1;
//		int w=P-(int)cs.back().size();
//		cerr<<cs.back().size()<<"??\n";
//		cout<<LL(0)<<code.get(0)<<LL(0);
		for(int _=0;;++_)
		{
			string ww=cs.back();
			Begin
				o=code.get(cp); ++cp;
				o.out(); pri("<c");
				for(int i=1;i<=_;++i) pri(" ");
				pri("`  ");
	//			w-=int(cs.back().size());
	//			if(w<50) throw "GG";
	//			for(int i=1;i<=w+50;++i)
	//				cs.back().pb(' ');
			End_Dowhile(good);
			string S=CS;
			cs.back()=ww;
			int p=S.find('`');
			cerr<<S.size()<<" "<<P<<" "<<p<<"\n";
			if(P>=p-_+1&&P<=p+1)
			{
				S[p]=' ';
				cout<<S<<"\n";
				break;
			}
		}
	}
}
int main(int argc,char**argv)
{
	if(argc==1) work(0);
	else work(atoi(argv[1]));
}

