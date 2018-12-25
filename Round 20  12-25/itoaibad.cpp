//这份代码含分块打表，可能会导致编辑器卡顿（
//没有缩进是为了压码长删掉了 
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-funroll-all-loops","-fno-stack-protector")
#include <iostream>
#include <bits/stdc++.h>
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
string tb="A)@72>?b!%]N~u1`@fV`3cei#DGI%$rgef`I%GI!f2Q-&2Bqu#9#qP3Q,ej@v%i0*[9`Q#vHaq^,xI$#dv^n%FMe2`;{<.3:.<z*8[fW(QuhT%j#eu@s:2~^/1so#V<,x%hx>s43.xg$t]X%%zU<_*|bU>`!UD/`EJjL&`x3E*-UR;3h;cH!}[&?#xthh4oKI?4]4|/*ofyR49qE53th6a)=y1a4A@[c20p?r$G(I@*V3m[4(Rqa@F(5r`O9gM%mOA.&|kP:@zifp3&.|V$txor%v>V*3xma5^'`Fz!%J@A122'6(eQV.&3uva4m^4;*KN,N1#b2l2zcBt2p7H$5=$TE%j9[W!|N)9`@K/h4JR/<2sy2/&b:t<)Q}@x(F%>P$1)nl&=_vD11dkc!k=8N3K?c|*HPp))^]Wq*-9nq*Vy1U`vbvt*Iixi149B!((j-]#10V6#rj;X1R;6q1e{lt1]|IB(%[23@i27T@:H)7$u52J!zeH51.K6w(+3ll2i(Wu)},L`@EWMg4(D${!z{`#$-Cy?*j^Ux4a[jX$eVeK2Sc$L27E5U$wUQ`1wxs;#8Mri2v!dk%S[XG%T`rd#zA|i*uk[h(OH.6@q:g$&4--{1J'mh*Aa$=^[w.%^m{F2%B$o{)PIHq1CK%+^e-7e1Sk.6)#(>T!$#RH1gl=G*cv_y**S5S1Po|U`qN$p*c10C^t=rC&iT&)#9V&l)IfvL@7%g')yR!w!['bm4V%[t(!Ft%@3Ak65~j!)4qiTy!o8%{`>2u0*E>u@1ec|F1t7H4&l{GH4Ic#j^}n<:!(18+^FGJN@2O+H^/0$]2F1!?&_3lx$L0AH^8X/W4;8?d!8_+O@*VUd4wLGo!Sg`O@U=a6(0K@{!ON435r0X%!7.kz@;7j?$KaX@`@B6q*gS)8@5Ng!3?Lz|)JGBK#OdO4(w0;N#ge*e@H4c?2:`dQ`Tt}7$x7sL@3`]C(@g(t^BJ9h$JT-G2*GB73qP.i3uo#?**s}q1%ak+4+JHa^)}98$`,).3DD*J^1hva%*{']%JmD|!IXdL2;VV7#0zw6*i);T2F9pC2#l?^*|J4O)AC/o(w%[k3@u$<$6n0>&^G6p%y6L12}V;*4c.%s&R7e`%wE(,3gR3y`'^oB^mIJ{1L(5C3`iUH4GPOv#:n+F^efP}%*!}g!Lt]o&hn~k!tMW2$q22`(=Cz.(e(/J$TOOn)`Q-<)(h&K(x8|U`XTiu4Jzpm4N8vD*5nFP&'Ad^)a5OR$WLp%2J2&1!Pu3j2/|AL&6!c$^lj7o1L-eO4{d,b(R{o`&x*5A(sMAn)4uiF2'A%B#0i'|!MLLT3>cm43XldE1eD:1&5VP84|I%)^:eVv4{DV<28WWD^js7n(+^aD%]^}i$Sfbf$Un)m`*uUI1d>80^h%PI&+weS%H/Wi&Vn^6^?s,E(?s?|(0$C,*kILp(4}aL*m7w,1tJkH@su+g3-s_f$L`>H`^kN>`M/H>(o@k{)sn}=(Ce?e#1gI9*$Vur%4}JR$]jSQ#?S%c^'rF-`Ko<*#!4*m*V{.o&xEC_1QwfC`/,UK4}di|3=fAu*.g[U@_MvB%]0<71^*FN!Wl!S(kK2{`1c}N4@S~9`,J:=4-67'^Q-2w^-ddD%Fz*o(t5f2);tj#`m~aN3=<uT^[m#O4j{:y%!]u>12[q9(Vtei`~yf848M>A^&.;n#:t*M&h>wt3LyE(^6*D&%eE8/&IzB)@_E-S`/4|f!^$Jo!WK2h4Gs]A4<)pq@:Max$N)NW^tO=p^T@4o*dJu3%?<A!1Vy1g&~fqa^4x,+%D?j81cFSB(y*7|3__zT^^I`&5&F$F1>ERj(fw)&)T%C&(6bw3@D`jO%HKd>)/$I@^95c*)A~FX#La`m3c<#<&jV1j!B,:<4U2!L@f+/F@4P(*4iCuk1an#A(/b)4(z/$G!c,=J&>jJ_%7t&a%v[jw2T{(0%>9x*`{cCK!htKX%r?e21<#z<$=L_M#=-Q&${Kso$tH'^%'(6X!UX{r%X9Jz`RT~B&cW8a35N>)(K:uA$:kht`A?.~2Pe3g*^g@1(4$F[^n*!]`9z=^5s~m>2y:c)2;-JP!m_*(4g`G~$9_](^OlgB%lQ0e!Ej'Q$/BU,$t&9?*p&Uh2WSAr@[|732$`,#21wiW*x,pl)rKFq*Q?bF@4.H]3(e9Q1n07^@Lmp>*lUAG3GDUQ$9'CB`i@G|4`aEX4js]s#jE(w&R3_A2#@u+*mMS.)kEe)`Ol47$uk:!%0gmf*:(GE!ut,u^d7Ci*ze@r^Adjo#m#m##w*?e1:-l)#<]mw$[W}!@/)M{`tX{A@s;w:1;n8o2,Hje3H8:T)H`Dz&VXN.$NPp^3ke;O#r|K.^n:WA^N{!Q^<~X/27)dn@'34~5=4n@&Xj3R1gAu'`1@eN!`7Ow3LVxv`RT@1%l#d@5C.TS#B=/!$j`PV%DX+5@W<8e%6qnn#By=y2KG14)@0j-!'^Qj^Vy:.^dnXU%Q':z%>*yc!}9^l@W(KH!%nrr3`nEn*qrH^^mCdS$s>X]@D,,.@TX7}%hR3b#E0't3o{oe^$,KJ!?F6p^zL0V$EAC<3Ntzy1kLJA)`x50*TlFt`].%82R{Qj@krfq!q+2J&|%G<)@g]z(jX=!(n*h1%r8ym!sHe.(lIz?)OAB|*]`pv$..L&&O'!_*zpuw!'lF*%s$Qo@r<Ts2?&(9@)/}>2~a8720*kE1MsG93FTVO#HJe55K(@M#j(*$1WJ8R@h+pp)tb@I2(TCS2zm9O*ACXw#6%-K1CCf#@`?Bl@H5/H20OxK)+&E|*vk-q4,3o.(A-E$4ibJo2L6Gg!c,6W()5x5@*=O%)<v4z)(1O{#lpJ)%[)Rj%4#~Q@Ro.7*E^9-*Sj[C4U2!05}@[{)f!04@Wuv*^J/M_^94L|^q&@x%LGC%1.ys4(5~i|^^G6e`kwM[(9PiU1J$eC*J9|#4^M41`wmx9![jOh#:e3o([{$$@qmmD&%ND(4!k!|(+%P/(!&_.2#T(a$:=De`VeBL&57M$&C*4B2d7G2!6)h%&I.mC^r0?6(9mb`*ew,j)e$/J1fQXG$oycq%P1`!(y;~V4PrDO^0Cz0!]djl*x-^x#cXzu(k!pr^LeRp!49uf`Si.i@k>LM$?zze4GRJ&%.@75*QWAt$Bo/34y6(L$PQ<n@x(W4$,z~$#s_Vz1^*+O@{kwN4w@48`NS<=*[`Nd&Dx>()P35D%j#u8&d:H_3DJvD(%!DM3u<bN%'/EF*Of^H!!box$5S=s*l7o9`hP.1^4_@x4o3t3`0!{P4'8|W4Fg).3JnHr2=)*w@P4<&@)$4x1zGF'`Rbdn#=qPJ^X>p%*]I[}('Ec#*|P+x$[THQ1K)B=)&tKE#^a<!1M(R91!KE14Afu%&qC3^!-:1t(hKbf&o-/62x|-L&&OK23=;!B`Nz@/)Wo}91ej|L!FDo|%,,pT4R2sH2BTy;@$y@s@Vi)6$_rD%2gVN.2!Clx2J:Bc%uWf_$O#:R)E2M/);wFD%4*244X5P&^T?!=#FG]?!5.--&2+#((y=Sa4B5dh)/pb9)Ua]M2eejk1zml[&L;f3&[+8H@39EB4.^5,$1P&d#^w=7*{?n}`:]l-)K{C3$Ah:C@C$|E!)rf#28cum^;N9r@vnb&5Q?]d*S&Id1%PJ:1`!uO%T+g#!yJLJ#4&6E(Uq[g4{J;G*#N$)3lHXn4sr9e3#5(K@oL,$3bjFq`9]K!@X1uj^wm0*2HPuo`%d,T$.qb*4J-=5%'Cy](Rd70*+R-C@dRPX3g_Ke1!^&>2S+.g*W^d$)>7{o`m$|L%FBe_`{.zu2%AI=3|B~H&Qixd3;gC[(rxc9@E?J*%q$nt2MPI!!7RfW*o3BF@CL_71;.8S*'y4g1&]g)%Vl%`2F)ee@>7N}*W|:M&.L$7$M~1p1&d_+$+)bx$|(t2@_{Cq@4@8/%]sn@*Tk/95/O^.2r9z/^=w]5@|~084|5rK)>lLG&FCR#$VelV#=B5h^co79`4w#<@tz4'4IpR}%8iN8%!::45w.|X!.^P$$)P8=#NSMB40/ho#fGgb&S[]K@3%'K2p%l2)0Je;(4*I7%/[Eb@2v'c3uWgK*OS%/`@k(-1AbxL^VU|q)A1fd1nI4Q^4Eff%}zpx$sh?!@^@fH2x[y~3!]{}43=d8!d=Vd^[nhR#5#xi%bfrd!gsGE$5'>e$7mdp$XCni`Ep([!_*oT3<g({$Ra&C1-K9{1uU1h$OJ$K2E--$@u(p5^:B:f2]c^L1y],[!JWU(39sX;^qGl)`co::)Rt:P%_f.i(T&4X#E%=H1yDq~2nAvI)iK%p&-fI3*>.Kj10tN$37LSG!j0*h3(NJa!NEt#%i]sw%^<wI^yP8j2H2RU^9C{/&mB]3)SV053p!=w1N[_{439i]!m|GU3_/#p(fi[54G@02)3N}T^7?4[%a^f_(q]BF2nam2#]AMQ`j-DA1tUIh*s4:{!/jX9%]/w!@r1[m!vwzW(v[-{^z47b1qM?u)0g[O(9%O:2,#s.&4Dm%^@b*h*[l*V`6R;s`6J:I`ie4I#_(a/^%:4R1,@`z^#l$@1NIL15G#$8#CWhT1,JC?`@SEv2ppj;*/g$(^InPw(hju@(_4At)z^-{3sE_L(qC/6&KgAb`k!;O@cm%~@pz`m^z_D]*`cB84+J@C4EWt/^E&M)#.F2/#_#{4&f=4i#_3wo3e}]515|xN2|=%G1,-uO)f$,b)OG/P^~f6)&bp&q*OU#}&tDAU(Ul0s*b6ls(Bp=0*|QO_&l(8(1pGsW2+0E23upF@)T-,0)7;Ed^4OVj(];y;3bxk)`zh(?)CKkj%jMbQ`{E~K`VfEz@Cb|e(gf={1@0vt^;U^_1:o]z*5J2l@Lh*15a)rz$/cx/3k$Q-1<39W1`xjd3^TtX@GxGQ17G!2(63[o$X:]}(1kiO&=@1D&A?>P``#{U1<,pA@M1[/(<zIt`gs-64k[*D)$z!L)9[rw$*~!E&fTHS`K.m}^*TIi)vUPK&6B]23e!0(^m=ia^qqFq(]GTG#s>t>@.u#9(,+t-%2043)3Ugu&yb;12M7bM@rSlq)3@}Q4]^!A$Bi6G%@X3=!n.*w#;h0E`L|Bd(czDU$.xKG%E,-N4dWL$3(Ikq!izbU*0(fm$'hs'*ak{F)<e<b#[$-P(&WFc14#/t!aX7o17i0>1s#^,!qD^X3zto[3[rg,%)xbP*[22X&rQDm2i+*.)s'ss@43Om1O*)0(4Q?G@kQns$vqX63ebp1`#1q2!)5V44*k%^&MA1m!&Ox?%qV|R(B`3#2bNyU%'E/P*Ki#G^:T_-20}+%35;h?2ysnW$$Atj%w961$ehIQ*|J?-4'P+|%Vh7s&`C7=3A2z[#lKqp#CFm`1g#El#xAvl(3>#?!))e2).l=G^T@IX3u{J253*$~!@b;p!lR(7&Ut;!%6E`D@~D@[2!(9310?f1@F&.B^d'Q;(f]e!)Eg;5^*KIb44W'y)8~:s%W:{~`y)_l3FlXn1Kv:F4JBPX3`Wlz&I`$,*/7<B$5['%55MD]*dD1f@Jt8w1P_@z#8R!919OaU!HBy_#a3ui%2f(y@?`kh25[y23&Dn{(=%</2l:KW)ypSU1]KTH!mDU^&K0J?^Jo]b%dv+I2VFo%!%|J31&i+($dQBb19Up,#.$_7^2e^i(k'(o35[zi#A@jd!SGD?3V/Q2^r5x-!PzKE`tUpp#v&r(4bN@Q$I!~Q1`4E!)n]oK&{![v`;HC~*<kfw2xp4I4+/}h%Le}.(o:>m!eORF4'lA%*{^w+$H|m%^z%`c3ci37$6C]`3a[GU#a&U6%c=',^od$j1J[C+`Rkl$3saOd)g2U,4c#rj%Q;rn)i*@m22zS]#|+Hu%7x?C2[ss]%s}BE(BQ6=&h9|D&RQg/`(3W?^f?m`38L%Q4juG:1`!a$3Jo*q)N<Li$UQ_q#[WtK1,Eil*Ukhn$B3E(#m#h(1X7A%^*!j45L0R]*zj#q)w!%V2?`@|@3Pdt!l^aa*.5U&%zU_c)L|>B#1j/b27=M]^$Ta`56UE#^pRL'^,$t81vE<9#;U[p^*iqS`ey26)Ly/;#ygcQ*G]oz^JgQ?@z~dt(=]4R`ezQl%8%>`4KB|O!6(VW`k7;Q2AT|9`-8!^1@=zr%B/Pl@:/iB(L?8;2oqlX^_Ni?^U%;o1c:$D!NW$e$a;#)5>/d{@%&l'$is0K!$`IL@k[}A#bI:R2RtGQ%~{<q$JgrX@Vr(G^&M?m@-s7x`f,7a#SFy~*E0@$3*fX&)2CHy!2,)1`U=*`*}8#%@]-~q2Nzg`4`cew#S(^|`8#fu$r%:p^c9N}&PPH]^O2pm`)C3_)P)!@*Db{X%Bq:^1Kh(j@p;rF1w(`{&z>bB!EE{h1$&3}2t2)$&;_f?&xC$l)cFKc)OicQ(3^9d$$/AL`*iz<(E>OV&/'=^^Mno|`;uEO2Mxs8&.zP{#2m~#$uF]I`/@SP%[gCc*-O>S3mWG}@bO[h)9))z^zF,N*[lBC*h;=v%6o|M)B'^I1atUg1q%fx*dKCl455yr2+:S#@Mpab!e]o-)x4<V3(yxX1RgW04E$N029rxM36u5/!P'w~5OQ5l^mTvS@<[.h%F&Nc%3?I]^{MWf#4'}@2-1/w3i@DB^RQAD3^S?f(W;''`~2.s*[A1*%%8M0^M-1O&BtO_&jzw5^:0js`Bm=%$2ekn3O--.!BFNa!STR{@V&vO$v$0H#6z2b`:3~i^OX6@^QuhI(;,s7#l?Sz)DK1r4#G_W(@3ly%n@b[@2@F3`%&6m)Ox#j*Q1%W#)/m[%1[mx1AFMH$mj7N#j;A0`:x,`)y|27$1Xm52j>3i&/cjo4G{R(@[)lX!OK>_*dp`')%S!R)EOkx(qtxh!r?&&#jFDz2$cwP$cy5O$W$Dl`{m7[&Blp92~<6:#n!!}$:z];2dCB5!mNty(8HQt2M=XC*Jyxx$CN=2^;jmL!-Pv7%d{^w#GA6~3SLvw4MgfK4cWN)$r(nP2PnF@#bsmE^n+cF&rQU^!u9@6![HJ6!UK=b`$=(e$c+V:2Hie;3edOW@5O,l@j-Ro!:ue6&<1aB%{{o'^Nxz^*ypaS*E8cI$os3d({k(h*HM1U48UA4*qwO^*D&R9)~}r/!Vdxc^>aq`4{?D|$f;C`3/D!}*c[sw`h!>#%+S;+*vp1])wpj_*3fEQ#KRTA4~?S'&N$X^#WM+'3WfmP$~7qL^N>@r)uixh!WU0j4knn4&9wn0%SwJN%x?4{(K|l)4vuPA%m|e!%u/ig%Fj||2|fB|%{T.P1qGKS*qdX{@[.kP!9B9l@@'|f1>{=(43h+N4RQ-;^UU(W1|1m=&m@cO`60rs)QJi[&U|%/`-p<K!]3ur2KqOj*xtIV(E(An#u1kD#2%&]#cb3j#N[kg1u0f3*c+):2uj~T(`(M'@<(Rd)omF~$u4FX*t6L?2nju~&.7is#Jx*j34)M22Q[&_$u;km*;&;]%v%XW29|_?4sC,8^Rl.7#_mAj3S+Ca^q,?_&(m!w%3p0$`(|Qp*EouI@5u,L#l^i')hDh)%8QUS),rQL&EH!d!bw4=#tS[;$lRws!)*Jc@9g.'&p>5K4O.k[^VJ2H2j]L110)Wg&!8`B!1fuJ^v#!6)Df*F1N8gW)r<NB&S57T1|Q6U@:4w_)s;?=2y;K2#$}p`3,rq^^^D1c2S368)Jc-13=`XV*xOT*`/ik+*@$L`@!U~(2h&`m((-Go3St?41QaDc3<96.@E_|^2xlPR)H3bV&iv=I(uo.i4wjT*`'q{94${QL4b/nj4]3EJ*V)l)#f@Ee)Lese`tMqh`C.eE4Ku?g(aIOq(O@`((XLrT)o+(b45X.}3~y$s*K)xJ(Wbh|(u%h5#l%Ee(3mWW)xPf#%-f9r*N&,G3=Au-`jK]m2~6;@1khh1)|%(I14-~'!B)0r&^b],361TN3y?s/&u1y}4wtk`^WyvN$gNIg!knV,*?~}}$I-B)!,XqF*-z5K^Bb7_#/q@o#%}-8*(~@8%h`Ts2Swoy#I>28#q].w(<*u_#[+f*4gbcC$=.mr%Xra?3wdoU25mG]@e&h51r^xz*]&LX2L7c.4jz[(^HP,Q#@Rz`3p+}L1E!W'!*#5{42v+:2nC$4`37!A`eOw!^T/+p$,vlp(F2l2%+5|,)2-NH2#0x5(`R[S@~q:x$s|uQ!kiK54FktM`4yz>#R9o61yr2/%+Wdg!/Q435.Nd/#J_N#3n^(G!|IeI453iz*='XM24H@h&~Btw36&dq&JUBr^jf*`(sLh2`zqI]@Ks-w(7S+64RcP02Bdi?%`PW%26uCg!{{aC$akqh(9RB!2c}&>$:[|s^mG%k$wvfp&Qv'T*jP_]&euV^)#FzQ4u&,R&0g4*2|s.*@y}w``2dc#!{fMx#E?@[^W/`/4bRMi!a9h]^e'4(&z1Qe*t{~z`E9,54yId=)sl,S$S127*gvHo$(&~i2UG+?*AoC%*A3a;&dH2o(h~|j#h}aM3%mt1%cO_^(U0No2bg.r45Mc)4aBO237^V.)(eu&2A!n93,?pO)4r6j*un;A#_z3=^4#q+``+=f$S)aa#,V5l(6ptW)jxr.!))FD@:{k:@Fx0y3{V~L^y,RV&4%/I#z)ck^,FT?$[,XQ&0a;G3?Ig22)vPq1o7d&#mizT@o/}A3^sSO2ia}m#}Ct4(uR1k4-/U0!1P^D$$vv?$*X,d3LI9!&$pT=#vdH5@]M<[3_^<@#UgNx2.fA`%7Ov`!*h-8$ClqE$hUkJ@;6n65kT:x3GiBX)!C?T&%X9m2[)'#$JrCV1ECre4S04.41ae6@`Ofp&]O[C#nMEz!_P+0$JE]f1x^]w!$8f1!,~K&`si>)!#9_l!0N24*H#R:2zVD^)R~<I1`TE/1CW4U^U::u4pqu81b8Cm*pGKX)(A0;2d7}P#IOU,)w+6x3D46h!V9}U%FeN9`AUep15_!W1>.z^@ia&{1TCdb!MR>0%!Gdp14NsE!`_bg%yIn(1aSw:!$`5[(0bNS$nqwq(|#?$%&mG&)Gr)n$[/q:)5j2V`-hMx1f<JU*n}r`*>{`2#+TL2(TcOM$F1h]`{e[A#[3OU^@|i+^W%C}(f/[f@Na85&y!HQ@t~CW1}!l%5RJdr#:j>%$]hp-%8xh%^}#]8@d=3>`M*&:%qbJ4#<RAy%beOv$eAO/)#$0?$;8,>)~!0@@H}LQ#H-{g*F,7I@]LR45_Jy+2`+?p(r=~3)*l=z4P0@+&SPP9^^hwK1T/16^7Uvd`6VKo&3h!k(e}cU$l9Dn)&r^/(*+cT2~^Rc%ULs_@haho#.B'y#l2q;1o`QI3z+>v)/>Q$4DTjQ%~PX=@IO,z4L#GS%j3K7%%>Xm*F@;W@`0p11ic,b)mQJ*2}Sv>3-xkJ!8&g:`bP{u@g'(z!xpBr2k}&i1;@in`u5>M%k].~!6T5v%C2N,&@guQ`y9f]@}KVd3SKr<&~3(M42|O.^k;BC#]?s:@)bBo%X?W1%0(u#(Pl9*@!Jun&%i]+`vT:C!y*g64HN,;).=33$u|Hw@j2b|#nf91@kU$])]%EJ3[t>?2wS;X@}+c'^rD0f#0,Wh`>wi21>z#O)_kRA#}G2h)/Wqs^AL4B#D9r!1>;kr%jeaL!l0%G1%-{f(;sIL)@d`A2U&aM2#}La$0soQ!'C42&JH^x%1%;V^'d>F1dxt2(RmC?!u<,~1Fh^l$f8-~#oRt_*a8)q3t-4h`X.<g^E@%8#Is+~@=#!Q^-`=;(N0)u&7gMo^!uho%N5F<@~@NU%fVK%3HCz}^f2aW*6CzW&C=}W@Ag>V%K7@'@aDyT^&`Ef24jwu*`Nj](.NMu1zcjf2Sjqw#C+mC#{bt<#|70?(X#%7%wt<m#di84!uLSs)dB8N31}!N&c?}/(&d>~@9tk=#O.d^2{R?F2hW`,*{{'L%jy:`&j3$J*N<ef$tFvt2L0wP(,0)~)E78H!-0HG`2Lg#*&v^U*B%)B2B^$r2DX#9$@v.?`$zH@))W;n`#dtl^5ekr&OR;a#~1e9*=L(8%|r>)##$3X!0x$)46v;r@C<!i(M%b1$,+3/%h``m4?mC;!@v;G$T?`B$s?E4)`rA+$ls1#1pTUH*:mXQ#!SfH)Rx,}*|8fO%2Q8[$]^f8%-<mi)~(bK@S:v[&G^[e#|/o74F>Iu2/w!2#R:G^2/cV7&%qjJ4-u.}!E/:p%~JCn!mKpz&5X~31m9Qq^1?9~*T~,*`jc]f^+y:/$+S^}(U#GT&t.@n*nroT)/H4W1)-f&%qqSt^au6*)1BNb%fxq$$9JWL4@8U?)tNIG4k{:^$uv.E&VJv[)14uM$UfdL`SxQa)lChB@FM5z&Tm}#`4#u/2U!BT`,>c+&R,e&@M^SH*.G($!3Ir:*J-|g3iIJ+4-@t[`BJ<^&::ap*R-.~3eBHE%HER'%r!`]($G4U1+b>?%=g(2#rx*9)>x6m#XLw})BU<A@Dp}w^pV6$%R`3g3;@EB36$DM`,D2m^IDDg$w[9W!PoK!1(2i/4K!0&)/Ot:*NQr4&rK'_4!f9h`4hb#$87c#3MBvw4U.V:3^8>L#e+SX1Un&2#9u(G4>xDv@a-6U25S`g$wTj|*ia%O^xGPJ!i*-*(0U^)3~x|]%^p'`#:PV/@&[LE)BqH=%^z+9^vws|%t[d|%?O:*@eutc3ivpV@Q(cf2@Kk)4-jcy@9%>E)`%,=$oOVU@FwH?3*s1#@5!d>`dp<'!q)i`4I5@a`F}9)*lcDn*Ke&a^w'C^)R%jv47T?D^d:`E18v,Q3/=J!*G_3O`F=.w$k@z%1Q_1(3RbNy`wi~C`%*I04K4x%!omd_#r)i.@WUgy*|v#v!pF`j@3hT%2$(L'*m{U(1+FRR*&KDM4W>ho3Cuk3&x>m<#70s(&.#E05bW.C4Fa5w1z.8^%7cg>3xAB_^$@o/)ttj)&~&mt*y[gC`@G7l$Xx-z)i;_}!AQNG^MK{A`KIG14qonP%TxbQ$A;BX*o97W&iF6a4<6x_`?!fh#'?~)#|n~d*H7w**8,S,!)~([3;*D@$c,]6%&3RU@%g=g33pc^3O~eB#kU2g#Q,?_`4mW`3t2fn3wpMH3pD8}2~G84%v*&l`$k'T`)Uku3x*ji1vU}m!,0<i`{.O@4gtHA@V&;y3/Dmc#7)``2t&:O%Tb&@^M:;{)pdJO#O]fz*KdQ/!=9w0*b3K=(fWH~%}LXo@IR4F#as5,^=UOS^8`IF@1w[M^P[kE*iHXA#$EWU(`+Co^VG-~(KlPE^RFU$&I!W6)-K';%{|Xi387KN)tMOH1m8Ui$`v5H^.v2@#@>QD*r:n](Q2m[4!/Sr3s*4l`8z&8!cXQL3|}}C^}Jp^@5:On2<o9%!/n8X#/w/g@BE&i#-+>v@^7kI$JxvN^+9UC#2[3P1{gNN(S~4c$Q$.x#6jF95`B:$2<41`5'kSB*#CE61kxH}%W_`1%at1p39s^?1P]oz1NV=g3${f>3~gbE!C@!*!AScA`_M[#4kA&[`7pe02'`W;#*_J~`[GQm#j4B<@+))M){xtk#b}pW)KI_x%!oPz*pa;z!`T_e)N6xU@Vcm>4}u5e%@/*Q4~tKi1+:V`)o>97&.:4q^<?V/@|g2H*L.4N^'a9)4P`:05I_??^td-'3Q,G1`Q3V~*vyWE%V(SA![K=[@0~]}*#+('4^~Cv^e*wG$]R(f1X2j~#xhO:2kl>}&$DF633Wfm@wkW+^x!?f1teP?#hrPh4j5x=)Dtd{&szx!%M/^t2.;hE2,M1?4>2S*#id(&!_Xuj1Cgm+(w+O:2rS7G(5e)62^,62`;9[m3~tm^!*`[72qQ.l^7]Ek$q`^L&gFB!`=q+=^5:>u!J6$i1`w|O#HdlC4C@v9@KK!I3=8{S@t:`t!=)=$*.v*:@,L2]$fXi#&f$#J&Drx@*%u7{&p~67`o=_7&|FnS$kyk04vuj7^:!ks&jhso1y~^z)^7ko%hp>h&j'2c2t=U<^~&=|3,g:b`HRXE$N1Wf@SoRO@(z.E![KF<!sK]U*qW|.(HylF4^cjd%&=|>!{kc#5A)]j^juz-*n<LX!uL(7#0{2:^(c{?*zfm8%5]h32fN.d!`16?@oT>]4ycM1$TOwf&RC7o^|0+,@l!I|!CQ74`,={#4|S57`@il.#+cG<1b'6A&]oO$2&9z8&d-;$#WIH1&Wy{_*9G+.&$/<34W1tV3Kb.x2x^rM3Tfa:&;EaI#:kj/3#EH3(([|2&H]+83s`x(`TxX**Foe`&J9PN2OO;g@E&q]%e>lg&S>BM!nnkG&xl',@[`G^*>e[l*A8ub#MB%U*OLtW*t<|1*l@0.$E7pD1oQGk$J0d`!q2?H*[QPn`dHoB^KSkw%m:NC%?'V~2z$VD&491]1=^Wt&qpk'*%/$L&cSex!gn+0%Ekx^$>Ow=%9a+$3;$*~3hy-m3,Bc|3Lffo1cvD#)>8hy&c`IX1h@*%`a52B4=mO=`V9B822~DT`1(2G)cQ*m#<+%81-(]'`]79V%=M1o4$P8i#),x/`}g>(2k6*J`2$g~&S,[_1zy<7&,I8]).PBK*$_L*#MDSr`Wjt*#^.lX*0q`o2#&At&~{93#>.l+2>f||&7Ibl`K[{+^?p}h$p`~n)`5W^2,|.^*|i]i&p<el(sFx-%={H{1kw56#0G/J#`{g<2#,H|^@^[6&en;U@vfEL2~6k}*U)lt40tQ7#X+7B%|M-S!#<z5@(4r>*~*6+!&^}{&}^e{(*..{).|N!4el}h$h0<L^W0IG2l~r~1_k@9*gbc#)rX=,(st?v&#_i#4x2Ks@y+*d^MLW#5y#Lu2-5!w^5aNS1>tHM$.*/;36~hN#'23G(CG^-$*R&U*|~Lj1=ykg*Xr??&G$(05Q_Ao4-H&9&tiI+)R<<|()p]r2UE@H*p@<y21VHw!=tfT`,}Lx#&6e/`zJlS!B^H9%8s|N(mRqh%epu71}#e[*!Hi1!NQ?<*NN]O#,H5C&z|As2e!qg^C44J^D*zq4N;=M^U<MT3FAn&$./V&$#*8*(yK!t^8hn~*v|6|!;(:T*f.hW^IN,W&`NU#(GGoo`_kDA^rGVp2e}9I`kN]S^%ICx(E%gi(KB*)@hx.I*4roj%iM9W#roP.!9`jk2Op7m)6HB,35o^13X@gs!3-CV^7[cB&BHDX40}5t1VQ.)%_'#j*Rg%,1c$}-%r,=&*>Jy`2$+s#^[hux&gCL#&DwWo&/79O$+{^D$5p#C#7n9z@L{5t`t`iv()di(&u#8.(ma5o*n}?b1E&eU*%'+X2V%rc3w-_v!r3)1%hnHt&c?`@)J5][1<][h1i`/O&TjPF^a+An`zK/`(`]nw)aPLD#E)O;2m6IW!?@%y*;sqf`jW-W^LO]d46_==@cw@F4JR`b#j0;o(!7te&|L.2^vxo45}sM~@Gwr:22$a&!,P^25v*;B^viuJ2g7,'#hG1!&z6mE^m9|S$k4<a!sP$n&Cv;g&j{X~(*ko$(~x@L%=N4c`z~T7@4a]]&H7?(#I5MM@y6o`&e0<|#Lc;72Vk9o$kF-?(1}Uw357Fi462'^$xsiS!9=.-$WJbU&@mP<^C?7:@PbV`^D`t~2V_1[#s);a!_*fh@?`+6)Pm^R3QfAj#+h@M2k(s.&zMTc$3uts!hXT'3d;Kb^~`JI44uL[3H%,E1fw/n*,iA,2nb$J^le63`x?oC2s[4t41nTH@J/{{1OJ3F$dM0k`~jJ'^-8&<&;E~1`-qx*%JsiQ33X^21NwfT14X(-&N+?F3x6zw);s)6!s7C%`1Gdn%X{'8*ePb.)@5Ac(_6MK2?LA%!&mRH)%[=}!ooAC&*)wb(,UWA(z+`H^5HoA&CP'!4gRjE!+x*1%CW*m`eh%r&,Na$)bV6`)Bifh1`)3m@xK>6!?/3R!Vhy(@SD.9)XIIT$2):W1$j=H2-se>&N!Rq%*d|h*ONy/2~M!x343bW`,VE9&(1+&3yx$1&IOK*!6v$,3+x5j3-61D^5=m]^kH5j#|DDU1F`#d1+fp%5@ofd&E1jz(ak-z).k(0$6!CH@1GQ%^'Sy0$<*B0#xaO;4rI#?)8f2&10qT^`Da1t!mLNq$<5w$#u:^y$}<1R&NS6G#zUx,4c)`O&_,<E1N87y#tsNG(Q+_H1z?Hb4Ai0_%<es-@l]3-(J@]t29=Io$QJ>|1qk?D^2O`[&{L{n)e[v.3EpK`3l6&A1BQGe!&#u6(OU)^%]k>:4d/jK3R8i:&-p~r3d*#B@C'|/&9hPQ2FuTW4ckB8$));+`AM{!5gpe[@t#4j&hm^]@]X)X`_76t^kGO0^R&w_4o`K'@FhUQ^IO6P$:N391#z}#%$12f^!oF^4P9P|%+6)(36]!'4:@v!5m<}R!SeQW3)X0u@5Ira)s'o5)v1U8`=4eP!q${P#d21C`wRp*3rIKt@;1gk&*g=u(j{sl!5pgk@vpgX1B2p%&Ws3S^tv$e`eQ'{@|3LL!t;qc2t{ae&EiT4#eeV^2R^[24ajBO#!H!W@[!*E3,3e]^K.vx*O^<9!Fs[p)8gV<2xD*b)r07t1v&]<3#$/c*u'_+^]O|h2j8#N1bVRA#j~G%5Os=R`.1{y))Fwe^-$gd)Ir1S!^rg1('g?E(V}(z&>>h#^9Bvn2Q$]|*tbEt4i=AW@2'n'@*0?j*`(.N1e=Mk*EP._2cu$>!2pe@^P2mN@%,k##*aU:2nJSj$DKjl`6]yS$Bp'|($X.N`af^?(hOtQ$4T7i`rh5-^<:i{1:B'S3PF%S&P8lm)kF.H@NH=!4`k*X^=u8K*vM(4*W3C;`0i4F&9T(g`IQHX#Pt'n)J1BE&zp*))6N9#^iztG&*<<z30giV^@(>H*p&Fr1_k%c%zM)82(#h2(02}$@-z),(-:q=^Ny{.`CNp;1@2.23C|r@^{&@;3`hG~!JN`.3IH87(A<]|2!Ns2`&q'S2Mt6J$<<f6%2,p8)$j5@^4+LN!.bV9$*T<75cTc3)qxFa*lLb?315iO%vsP<(q_Pa&/j?s)qch_3~9Du48e;m*k{(&5dsPu(]/KL(x?b0^fM1o!'s}W2as-)$arlq3NgWr&u+5P@9OTQ)P41m!Bhc%(,En&3(}kb(CX2+!+*wV@U,(d)X[8M`gOof3aK874T_yO!{wt?1TQ{h*pd%S)de)D^@rl>#sz;[!pHFa%Qqn>2B'^|!qGNW*%+m/`+x/T`M7+Q10+Qz$H>hR)a_?5&!v&g^Bxv]@Fw551Hu`E%Cd@v^pU)~5dUn+%f!i4%zFHT1FBn&)E6Ba!l0VB3XBlN4#H/p$PUT'!Fw<s%C,3*)8`xh(^JzP)WM[j&vR9L(d_9)40pwA3y]Fn4(Ph!!i9k$2`4+y^=^!_310Qu#-yGr#;Ew9*BDH[*R$u|*(*H|(09mx*N3/!2t.q-4$VEn!en+-@'9m^)W:AW(FsD?^6Q5@`L-$X3VN+|@/)tI%1:PH*a(N}`>&ih(7_D:#ds>}`(n*/2cp[[!]1oj)bMGX&[eaV&Hq8C4'o92)fyKL(*CMI!{m`d$WE)^&TwUN@38@y$L.'g*]0kQ#lQ9E%ixj)3}qVL*S!6o@)U$x4!VWG$=z'=(A+ou23A0k)'(fh(;>TW!K!J1&6Lhu@fz7,$Xr4>!A0V5^&f5F#<^e#(jp4e3G('[#<&r1#|j.P2;+Eq(r*d!!`L6?&l1fz#`fHR4Nlzf(IEqj!k^3!$}m;]1BC^#3(H{.`wl,S);p*O*Q2:1(N{yI4tm6!3vr$?1<7{j(>/!6&LO<{(R}P6!K3tj4)~mF#hIj$%/xWe&T89/1Ej!7!8F|D)O8Jg^MX}`3?|083}7qU(Rxdk4<,kS#2|:^*%z3p@D/E94Kom|^$|=N4rgyo$jUn2!l)<l&S48()NnM4)!'g-3uUlw%i74u&>y8%#rHt9$vA=[^2P.F#6?2%@aty_@SA;B#l-{92[#uP`1zl+#~~Wt4n5a+$P],*1oSl4^o-)#4p;/%)7M@f3>8yy@vp?j^M!F2#iT>)!+`uP$3QJ;2o?>**.8fU!#zow!cCcV&z-.$&4R:x#:t]t*PGK9#Kaio22hQ5#/+Ct2K?TW(~S783Sfz52jHMg!rH]z&dnFz1bK7o%K@v^!<q16*C*BA3F_^^@x'rj$Hn}r^JBn.@_0-=1R1CR1Tu!/@A`.?3qf~F!_UrB^uJ)K&/f7Q`q0)-1oyND^WK77%7JWK^u?c(2k<zU`RqNJ*LfOu4U7`c@]3O94Lc0&!1{9x4nnDu1F/WV!<u:E@G!2~$uDjE^BP{h`4Qnh#v~Ub1!OU)`:IDb&=p&-@#UA;4QWp1`3-yp(l8x{^GCO(%2>v/1|N'K#Dm7G!T+f&23e/O()nm3(TrD71EW^@`P!0a&J^&o4%p4$`H#[R*0=p!`Dl^}(Qd5O)?h0@4hVm7@(x[G(P6,*%mlc'`jU$U&mevM$>-3c(njc*^pSkk(NwTb@mcP3(g1n|`aG|o@~c$m&_y$c%c9-}&_{bW4NIMU##Hf-)svj03K]u%`2rJc48+]T!7SFj&Kv#7`<~?D!{b2/(.a~=4'^2&3kBB43gk3P*=O-^@bWs'@M^pj@<KVH):Lh81;#n[4}>z/^,p6**3p04&q8-Q*u0Pa$eTg1(GJ/(*r{o74&D$8^nk=$*z84T%{8(2#>o4(!2B2c4U!lE&'rU!5aTLf@}6vJ14wR`$~$%l#W4WN^|{CS^HUPW^:w%|*gd;t@>z%|^L]7#&nd&f^/G]]14bTc(}p!w%+|::!_.j%)fU1y^Ui+N42%{H%#}eh*f*;E!)^lx%Fzy<#+B-34#2J/)]e281Py!s)!G~(5&A$W2~d023yL%w%v-}P&w*%0!|F;G$fLV%#}Wx($7[K')_ua-4I9K!)K`>m*%^>,!qo%_^,/yP)W}AA%<Qi&#]r/#(xxRa*K#5.%VBtJ4d!q+2hUj-(&pJQ2Cd%A!+$Qp3FF-t^cfN|273V}!t#r$^kvG#&ecq{$u0tr$KdHU$gdf=&G@IQ1gBU0#OQp)*%l4&#KiR@$U]2)1XV>^(I~l8([e8V*]:!c%?A}f$g1J(!.4Ji`C/,v%hRH72L81P2OQES3Bm413vf:|2Om>9^mQvD$T68A*)zz+@@'h,`tiBQ1xi.-#r,PA&q&D~)$*p9%t#>T!n)3x$KUT]!JB4:%Du/7#P~;@1wbI{!F4jN%<%'~$nEv>3n9^P1o;`&1Jw6*&_(&y&3eXo!Lo/`27mId&s[@#&4WJS@K,5p$J$u(`iMk~!E*}I1rcm7$@#R-1E[m84|@V5%dwn4`NiEz%WEGb#FTl>@l~?d^|%J:!A(C610zw~*E{wa*4<73%k:Qo^x=in%Mi$z1.C/.#Jb7J%nbl~!3Cq]!eWrI)g3kH(N~ze`SUP91W|OU@Fk3.@q{%{&p(?+3ILDM3]Eat2xWC7)dT~B)7LXe&H3104&MLE#ba/d2KiKH(b+J>*@VG:`u:7@3pf^!*H}h%*9_=w2P2qM@M<]}3rd8V@qda$&vm_-2J#${4o_ci4)L7y)^h![35]l-^}bK4)i:8Q!q=}{(*zb')'oFO(v.e/1}15d#>[N2#^Ct/1i*Uw@]eq<2^NM3)a=Me37|EA^)[G;^|5t)@EFzj`n.-'&F{L82Xe}<4P[vh)%*~82Xd6L4O<Mv`E++P#8nD^2qI4B1jwQB)3,j[1K~Ie)U<j[^HIIK28{Gx(dti716mug(aaS-@x!hX@3jGD1xUWX(`'Ew%^<-{%d:yb3#qh;1'jCK%:$W{24aVV!+b^,2nlfX$[NJV2f6b?*?K1o@]C03#1Ew6#a}XA%oCV:4=QeA1},'`)VXg<2*q!t!GQJ``~lHr14!5k`.Wuh1^o_F&n]h,3.jEp`=K#T#)I0G^F!gU*Ur9-`kKzB$%G3/#B1xd&u]!J#J&hv2rP&W$A8.Q^:FM,&(K[*4q79$%f4c#$[:qC(KsP)^C=h+49<a(!Lf=B)~3S.)jJ*E`[(u,(qs|X2A;&d*RgAv2p#=A$`V$S@NxB7`$?er2W(=2`'^*54odm]4Uq0y`BBR2%b0'7%OMw+*3@ks1~iW{)^v8K1PSj_#%q*b$!^)O*X.}J$3jEm^85Ad`{$N[#!dCB)#i`}1_Tw_3hH!y`6RK_1R&Lj2vpJ-%;}5+@e4O!3kB$G@*uRM3hkP8!3=AI4xXQ+$wAP&!:5V.(-ofL#qw!&2U7XH4^(nm%!JNQ&D]^)!pjOx20--|4j:<-!8vCh419LX#/QuJ@i`,9(yV<h(9<l2$kE>:48sQ=!ekN011w'z1=kQ.!dL*w#rp$=*2%<|&V9F*(,$=I!bE-U$`)p1$R*PQ$aQua&#6@F#.kJ|2uUV*!ptCq3i}w~@xBg[)t9h])ux(4(a.E233vpP*z@>w4(.4j)(TqT#oT(A$b)Kz)RR552f:95*1_GM!v/1%^cL7X@-l.#!$Vp$)t+ci1~`v-`:e={3t-tO$4nl+(Bb3s@~q3[)5Jm]4=]!5`Kwhr1E6+U$WsUP)_uIk$57w~#^Q[w)NC}B$*1p91O}=l&N&2I`>QF>1M>1z)>*f<`%RgN22zhQ3j3`O3?y|0#$q)U$^zpz$@-A`!a{5r%-a^v#=3AJ#^H4?$D3+/(qn-D^:!Gt(,uPN37eC4%_vhN%V6Q=&ajzh1U^T8$]]Ib1,?Uw!&.;O&v+yk*J7F)*%#*416{Kf4Fj{J@/2r:3)hA1)w2G+`INtM@qH0y(.>2f*Q^~]@HV't2AC}=)2~wW@u{c]^I_|0$,{cI#^;x((z]h])JM%{@8-5K(E:l8#<jhs@8L-=$rDOi)foC/2?NXv(l6$a)4(m;21jzO^}4pV)DHg.^+{|?@yVQd@K3X<%4m*H@;sPD38R4I#L%{g(b&v?@eanm1kHas&f/[d&h8[D)ap}:#2Oq_&d=Kq16}.`2qu3(%vK>$4}tn85DrQ;%aWz356hff20xOD&wjJ~40L)U%n%S43Q-|)`]p('!hiws%,pdi&p4X-%^#945#7D&%UOB65MeNf%#(FW!%.mf!rE_:)C,)75-X&m^nfL{)sLUU^T}{?*dHJQ$Gw60*i)O=1K3*%#}A+@2bp~S4+Rf!&J(U_4*Bv/)7EyF*_%Xu!}:zL&8+wc#)NPn!,9gB4623[#tDkN!6zn7(8q$5@`=]a$5O#P3tMnb&c9b^({F>g1B@j14jM5&!riRV$1C1@5.[`y``%=$1K7Qh*b01s!G/{U3EXfQ`r}@X&;@+a%j,),4R{cm4IJ~x$I^cm$b_3O1kK?D!=LlR3*c),^HB9?4I_Ci(%Eb5@f.S3$W~%#5&PzM4yLuu!:V0p^$/Oi)l{2$&Az'/$G~?f$-+;}$vk]-3c9OC``%d](C7L1!Utep*oti+`}ji{!w51[)6Cq6(x-:m3lo,v&*D}-2-Rov)[<Xv^(6-W)$N4p#+hyC^!O[m%/40W1,3_e^xKTX()58($W)q[``*kM(S(-#$>sL>`RNMS*PLqa&UB'u3Wx?3%?}%21(0x?4P1R;4fA'x(+?}/**B+13sVu}3ov!W%[bz-@oUW?2#wn(`T:J92IIQh^(*8c^G90T@VB)$^*y,%&uOh2!&^I6#_T6Q4_gdB(2cK8%#*Qj@@efV$_}Qy@JC?a@va!:3z-LD(ckR>2idr|$!mt/)D{un1w+-W^_)g~)/gk}*AQX:)z?]x@jr5X$H$.F^|3V/%m3fy3$:>+%biO533G)C`n/}4!]t44(G]vw4|g&;^.zi5!D$S8^E3|3!'C{w@3E>.&4Lu/`2e(S%x;/D)b.I0&wm,f*)tM;4AuN3&K~>L`O/)|3%g6.`R42I2yb=65?S@x&{{po!/xpL@m$4%!(q~-1=Rdl3{SyE({-b'*Ta.`*u/af15]%u(k#%)$H'd#4M<qk%.wcL)^F1B1qSu5^:om|3KK;'1&_Mo1[r;w%!Olr#xBdW`vB**1x;5()B[$u^J$g2@JEh920<.5@fG-F&i8AP*/l+q`~$N#$QiBa@WLXM2$f%I%:*Sn1A|J$1[w*75.|Ui2P33(1|u7F&KA[6`bllJ$QaVC^b@]:%B>)R(oJ}8%+Ra<&VaH4@crPD!7-wL@yU.&`x0V.3={9J#&m(o&CK%a@FG_8^(3v95IV[a`c>_C3asQ43D](~(/oJh&h.sw^3+I()P%8>!A./s&1)ha^Q&X)*MV3w)}ALH!Dklh`v*sQ3)acW`,i|($PME]`I27F)2Nr]#X])$5s!&p%v4.34n3EK$P/+B2q?GM$hu;:$(aGe*<y^[2!=Ej2RG5k1TT}3(-@^#$`N&<@AmR.^6-5%3Buvv(WA'u#K5yF^8&<I3P4m9$SP#W#P-p73wS()$Am=H2lX3y16&Oe@QcN=!P}Oh2e/E)(=~*%%B+yX*ulxj@}E,Q&fG'K)`{Ab%T4=-)mpsW2SfTf&:+~%)4F6:$w%aN@MB6#!:dgO*2V5I)z+)r$nA5i!#$tR2jzQn(&'-9`[r0($RHl&*8>1l^e?BO!)(Go(/oTN*~9zM(CQ]z)&<UO*fJ,y4CVLy^Dzma3uFGw1C9T9([Wi3*g9xo%f[i4`lGs5$%?Kh$7'(m^#ON{12)RF$g.Hw@OX[55z0_t%Ao)V#BN*1&v>392-/U4(vIxq`';4?@yjUa@:7`X4>f2M1^f)v27dA:*a=3V)]J@D!hhF_3JSk$&m?Lw$MPU]4UW`!@vAL5%pa`325@no`jg9+!(Jqu1q[bG#rIK)`0Wn4&5b</)J>79&Xw<:4ET4v&6#*;)E)KN%.hj3*Rf`o!BuO(5zIS=)#B-|@j9[u&0^Kf^`S(o)Ib#v!C97T%frwk)5Tnl1%&e6))<$*(>)tg^]+4k)#B-`%?(9%!pUph$c*S}4^t&~4Oxx+28xvD&oFf4*QA-b$vC1,1?Pb>$!XRU^[z!3#.kHl)#]'81bNX(1yPsj%Rc_)*9bB%&M`Wc21P}-3f%&u)dFxq#Pm-F$v*-~`TH$M#c+~}!tGja#^`S;!iRKl4O0Rd@AD(+27n`q@RG^9`474#(-Sh_@U-xF%^#5L%vnQO*9'T)1C3pr%0Sxn1^aGJ29xd,3(<&~@CgH2^6Kl~@~qam*;({%)(-[_^C:yE$nzk/2s,BK1z}P;2qlxV1weck$fxrc`F5^D`iuej4yR!@(t:^*@s,8!5Tou[^'^7I#j;.M1:W+T11p|M##QNQ@04-}!K^$L@-q4^^am+{^&d8U(T)H2*[?d)3D7FJ$>:$i%zJuo18%8P3&z4l(OwL|#'v{w*j>dd&Vs/&&KLNm@Bh<e&nvFQ$/^G~(h'4)1!~TR)C+S,`Gp4M@}!hN287>p$K>rI@H@<j(K4=4%![a{$uMSN`H)2d@@x1}1x+uQ%=))9@D.nr*n#qk1u1sE#BiN-30)y]^OS*U2#M}u^38#|`0vtj%vOA;#sOd{!6'%V`Bx0l)'?JN)|,fc3,e4[4(h{u(Paae*CKB.*F_*A2/5;Q$FIEl@yuE63e6<M&oJ.p2:^k0#zouX1([R%@-9p>#(E7F*9p.D$fx>h(djfV1b-.Q1M_c>3zn~94KE0K4:ET8#IO+h%Lnyc3%L0%4),S:@B5<1%gm.N#GM&s&#Wy04Oh*I4+kk%!0akK`gCb@&k5X0!8;g:&f0]M`<mb&1G8-15L$?=)=7Vi!yXr?)G4$M#FWrT2'nsU^hH8%&Re6^4.l95`[Ud^`Q~SH$v}K*$Qupk)ET,`#q~UI3+BS,4xT^o2(*za%1O8%!el1Q2Xqq)3bt<s4[T@V`F@k:(m8Kp3u~P45<jx$@;KJT!DjBq4R2#-^9_1g&wdyr*0U=%$THMw1,kXT^#0!#`8/Vh1'zNA2>1cb&g/xq`~%pw)j]Xe4!7,'`?nP<1en(+2gen$3Q.P9#1)Ed#a^{t2z:GN%;DFp47cdP&jDRz)~~%q#i'KE3'C$@!?Fxv%B-pE4AA?~)6+Fg(.:=R$2Na5!I{sh#-@I~&sR,,*W*>7)#R`j%~xG(*H[i35C5'.2}]iP#lV]@(X,#h2f)wb4+iNX*H1<74O.g35>{ea%TItN$,tC74x&{+^a*5L3biH;%I'8&)]!r(3dKf4$(]ki`UWL_#$Eju&@30)&]6/g*<jN^2UJP]4*MkJ@PbB_%R,2;%7tyO$;exx)1GrJ$>sz01}$?m^d|>E)E}w11%8).%7.rd%k/8P#k<3R(yMa/$l+yF&+!LL)A:.z1l52`%>$92^Jw]k*kE^%^..=i`3qU^^G2e)@l#@<!!dk@(Nx|J#c?^>)|'bz%Mt7!5C.MG`nv=J!;T4/%OW[p3h{*03:]|*3]T96%J}x<4gKHT$|CM%4R!mQ#wJ}t@2A1K%'iTz*bA6q`rr~@`s{u3#+xi6)K(l4^8&/Q4Uvul1xFj]1siS/(nN<_)<4sO&I@3%$!fs1*g%tz)XI:|$:NIA2kArV3oHxd23w+e2Px7r`.Lsw&_7yj!jP$/%yUal)g!TJ!QCst!nEM35X?Wy38PGT`M{Uq%M>H~@tw;H29s}6)HG>!(e;Ii^5Tz<%C'dj@y%kD)=&@l3fmE'&R#/t*/1ga$q[;,@g?DC2xnF:(p>yk1R5_F!&-z?1.:Xe&y^01#91RT)*u.[^@v&a)RuRb^?xkz2Aj:u^&3U$(&1NM*/ijU!F9vT^E'@9`pd(B&!1|u(fl?O(I{|3*E>i|*@*KI#0b:-$Pr^;%I#`q`@22U2?k}_^yzeS`R{k>!4Cc:3kUs[(sdXa(&,Ek4R:Lu&twA)*N8.v*aC=O*mVcz(W!uw(.T+t`8sJS**rXM$c1{R(m#ao2FH9U!Iint1}*q24beV.`<=zj(8|))((^9e(tTmz4rsjl@S|bu#zCej`ebjO4:c^V%|roV@NlBA^p>D^$O|2Q4jCqd@@s/?(!0%u@EN)>4yKC51P;/u#@2ba(IcA<2ImXk2-mC$$CLVu4m)Rh&T-RD)wc%r2M*X-42R;.4|w|+&>{B9!+aE9*~-lc(L~kz`r3u?)K?tM)@].f2]]A~!O4`7@5nw8!(8uz1o>i%!IA3T@J<&A(XC/E)2Iu7!#)E2$;P'35nVci^p%=d`o?sc$$K3X@01<F&sjPN),V4|%2rR*)&f:N&mKy>)=Q*24QHVM)`@'V2T(Sc!$tj@10@d_#N>R9^%%:F@II7-)M/*.@|y*a*0V4)@B+82`hlXq#Le<|#5xB)49e{;`U`6N*TPN>).3(#3%/!m`?(41^qdr?%|.}c(^hF5%J|DW%mb|f#Th&B@:960^C}:s!1tth#Jp?+)Tkzg!eSz])kCx7!wVcz@DJxO`P5,-^]^co1O)FV#K1K23l7v/@,g*[(jM0j3'zQp&8pCj1K#OV&&>]l)sTjl#r!PP2V+@$$q0I@`K77X)`Xr)!D&/I$pu9q1%U6~2?'K5$zCb!5#zR94>~oN^l?Vz&FPI4!ncrI!xex%)wbow$1VC^3}$+>4hS,9)tDL1&/x<J!o>WS26Nps4(,?-%JlG[`$)EU`!Sw@`e0qi2O.U/*QW6]!m@bg`H_Cm):?Cy$>&jA(tQ;`@H5Qh!tbhC)bBP32-Mx]4X={o2/7;o@%d(71-IlF@An:I2HMAj`Dvwe^-:v&#`%?;@+{}1^-N00)ba).^!+}m1<U;N$cIGv2Ut;#%P>>#1NRwN$0%Sa3kQza@#pV,2tTG!@P>EE@]TC*&I!Ew*wO&+1,]s#^F8Bg3?pfR4[wI(2Vo<N%S~uH#z>4b(,2;!*Qysk4/`ch%}yIi4z*4``6<5]%x}qW!9[%e1r^~B({&NG!oao&!2[v.`GX,^@N.=P*AgTC%-l`L#giDJ`-yoF*cH@R^sj[D25M2}#`G`@@g}M}`$k8O$.WA%4L4eP)noNc$f!GM`9XQ{@c|<6%yPw-(<;fL),`k62'sd=(bw,55K2r+*Du(91kO0K@&QJx3V-{u^}3ur%g/2,3(S/w`a=2+2CG9{%t/MA$OwQI29'~s)}3,y`_l6`3|C/<@OA!g41@QC&A[>:*HAU6$}(aT#B>qA!m9:(5(7b>&1C#a(BPEg@O9q>20F<}(>9Ov4(Be`)%2fC#dd^C19l/O@WbWn2Gox13PBKk%[JSW#oKD_1^5!<${*HC(W&!p%jzR((Fxa[`,JU]!eyFa^=&$U!6I1[2JpAG4N6<h)[^k,&c6w?3dK}g`)%_K%}9:q&Tg`B1_w9+3i#6t^#%yu$O#rq^!!-8&)5wV1.(]c*R.Uz)b%Kk4MQzm*B-PU(GiS{*;f!1&|sX%4,Q8X%,4G7&=O/|3=FN&@+[A,4G]Q'4hl{r17?eI^zm{$3mdBn2m;_H!yj/*!5^[(*be^i*4.=L@GF<*1}rO(#d|ha$,ny=$*ts3^g#mw!`++H(i5z]&I2[C3.x7a#NRc~&rJ=D^1MC35V;BI(C[G3)^R}:$d[R6$g1*^&t51A*uRW(`^t]G`XdrV&;U0l2<FEL#h5-t*5DJ=1Vme5)Q]$;&jRR;*Ezq8*~N+x*DJ-x14l,?1MCQJ^6jcu@l_Cb^C:!v*2*#n@(GDQ2sIua`sB}t1MX0p%%bfT2|f1U`<Es6(PXiE36PaN#4jA72x&)|@SvIW4Fn(N$2mqs`UU9f$y{;W!|j%.(In{S`]k5k`Jtv4`ihh75B{<s1[L')#6zrD#U(NI(H^mc(M_kt*(U;43/h)/!T^xO`vk%[1|I=w^{:)m#oeMG&(b693yh2<^p#,0$}6s*2e1if2.4I{)n,~%`q>}n#7I#6%jP@]`F[]F)6ti1)^#~,!t%RK%c)WR*F1<L(>ybT&B8N9*#rwp#Ainq#(T$Q3@3OC)qz+4$,q2t(Ixi{@{~P@^eW~d&4p;P@Oni$`/d@T%1f)4@%4{V2+(p%%CCpF):R]r&NLLj*hqN,$E|zF*Lrlh!)R|P1m.1$`sr)54rw~v!i4+b(lMwi)h~vS%7VFJ$8F+)!Qe;H1lP(^3w9?E4b?(H$qo#h&fbQw$pF/{^kx?b#p~s'1gR]g&12Fj!;khc@K9#=^yP)=$_xpk312o]`)}<T*`oy<`QBaU4/W4Q1,y.m%,{d<%h)[3&hT4:#@G-V1)aa:@O@T'&X[h6(>xk-^2_75#7#:=1f`TG)owUQ%hr1e^T0RI%6`8V#+.|v^{r!J@B0|%%Mhp^$J:Vb$aj{f`C5>-^Pp0e2#f311U'T!2ox!5&1WK}1Sdk5`mbt:4_JH}*nv.w`C>.g3InJ.#(Nk'^p62k3_3M5@d_Xa)Ce8?(BbR[3,.Mn!hwRH$3s2!20T_p!5~4r2Dfoa2Ct6z$=OUy#/wfQ`N@iw$sI1C*j0-?#&RR|*9ppv#vCWi&uju^`@TxO(y.Ca&b,s3%.bG%2N!7n3cb_G!O8}V3=o5E4x/0!)rQsq*]z)1(,uW*(7JgW%N0E7*^{En%y5*()E^6{4]OQd^@3*E(WOD13>83^$LbhU#G#<7%nc}A((9_k1pm#C^,#u+4I7tL(aLPx^`}S@!iyP04//eR`f8~B`M@EK3fjeW(XxyI%`Uv~`j0r'#=9O!!mT,i#kJ@I)nAgz1K24h3/;Tp!d+j%*@U|P$w46y1awcC3;bnH@s-]L2kh;r)}lp#1z&A6*@:<$(t*:M)im/R$E+,W4Fp.>2@9v;%/.-:(p='.`sdcb$:~DL%=5nb)n7`C!4jyD1r2ep%d([O!%#Jb!@Hy{@c}7-&Qz{)&L1[d4674](Xf1$`W#I]1r?&R!J+cP(GWvw*N-!{%mOCD1'(9k^r,*=2+2v7^FI=X%e}tP!447)(QK=p2Ryf)#gms/@w'M!`~D&M(9GAB^5PI95+()65R[.](j&*w%{{nm3|2EJ3AqJT%IG{A!r;3,@'iOV!_V1V^ExgP@GHr:3h=9b2D$vB1-5o7!E-|w)e]E{2{FW#(1^kC&A($P#FMy9!n`Ne%{~[O%3hE9*qv!%5`Fd#(=x=5*KewI*s4<T2,w9s&'=e[(m_<r1;G:+%:'sE^`NLP@Tt:a)=9yS(!|LO!6BG$(9;QG)z;'5(@SNg('t183T/^.!PaS@`M)#c@at'*).^H!5#o&4)Vyqr(vD#-^PA9z`0!d]%a&,&1y8be*'&7R10^Ih)|kvT`>%X45/!;!#oA6E!,Lr05Q5+P#-C-}%eycI@mL`h)y(18`6$|W&--JH1+q~E&(OT5*('K7!Lsc7`l?LG`ut)#)<o[$(HG:}4RVa&&['Gz@9j]I$41JT4G2gx4}XG:2hmDM3cb#9#Nf7F$&>J[)m(`x`0?Eo^,X?(5)nH52`0X61P%RG4n4X<)d)QJ^>pT,(cT,:%<8J+18N&o@+-S15/^C^(]b)(3r2Ce$lcs9&wS6G)OX0U$C%*+22qt_!o$U~%&UF]4I$[0&5E4e`G/~z)Un)j@d#[>3)B`}@ru!~$S7W:@/Cgc^P1Xh(NnB~3J[#^$UeC)*9'[U@fBh)(ug5;`i0N4)]p18`W9,;)*4$U1e?K4)zQE7`3hfH2+p6*)r}ky^nv3a1/,q^^afEH)*.[!4i_yO@~)0_!/HJL&x20o`i?jO^80A)3/TF$^j)Na@.p8G3j9!41$eqP(F$$85Ov0Q1m9)I!L$^]#ms6h)m=Je!qmRD)>^y:&4Qe~`)uLT%#foR(bct&%z<5u#Vu.w&rkkH*kP'Q1xEj8`f:Ro(URi[2qmon&.qIx%Q+/G1[=_&$PGc-%&q1{%E3/0^NLe>$U!CE2%=@a3X?j_4^kf,!$jlj)1BPR@?aH0`=/N/&wog7&e<'R(_fy;!uSXR&AHSf4mcq^!7px^`&#<+*NtV'3ws+n@4GJq`vbVQ&y,A0*P=KG%Q,D0*b>TL!ey}J4t(@U@kKXy3G=Lb${q.q`9i3M3([iR$)OE(@3p0+#z1w8*-JfK@qq))&A21#2LGs'20U99@GWj'4v|mN`EaD_%{>ea3mVV42zrcD4|:#p#*_}v&!4lT1IkW}`%g5g#yM5u!kn[x@tW-r2lLp32/;Rg!-~Lz@>Qux#?]W-4K?>P@]930`sK^!2Nh:n@@Pn?^E[F+1gR=j$@*;/(UCOk(tGR65@+j[(dRzD*1U&r43144%W4xX)ms$'(n>:U2,BJ<2]6B'1WoNp^8/p?^j98N&l'qu$m9Ml1-/hX$moB+4`{0!5rLwA(ct&a#!:f_`h.qd&3W,!*,=Cs^GsLQ*K5NQ^&$Wp)S0G&$Kgmo%xN&%$`oLe^(D3L2sVn*#[O.z@yuTD!O[!@*B|=I!aJ{j(6.</2,zk^`XX~@&wQc92fcO5!5(es*z]Fb)1Lck3*9#!29D>$)Cg=s)ok-0#FB4D&+jnu&+f^}!*H-(!WsC1!5D6x*qe&_)yu$T^]@DW)W0Ma48/OG@x{}m&Ml4R4@M'4@62W0#eM,/)TPo{`[Evh4Mg/t1G@<W%uW6](#:-'2|x<>!-CI,3c.=T`s)O.3cd7[`g]y'&F4ik2#r3_`gC'>!,6i7^=Ft0^(.?J&4-cM`=;sA#0$k1@>,r[*`I=A^Oek{$H$$/4?4N^1fF$r%uI7^$odsT`?Jz(5%0oo1j<PE%Oc<K2GJ)>(8{ly@LX5_323;F3xVC})ta@J@=Qy{`0iB_!m(wf1~)O'#)Ch31m>,'2#A~d%OG4T2qu2X`NbxK@[QE:!raKS$[_(.^!8:I!l>zD4WHn25.Xqx*Bqi?3CBt;^_&#n&VK+p4Kmo.273E;`Lp-y!&rse4>nz%%G-8$1B#AV`N)e;1&:>!@LgWq)'@-,3;o?8$d;G%3$2:{@54!2!FuP.#P.&*@qHw/%Rgkk4MJvX#n-@G!=}3W(zb$)^A~nA&SFS5)L~ut2W)D|*d|!<29(Rk4@Goc&dG3]^E^WU#t2W-3i|Dw3~##p`t@z0$-yQk`21*M)N:OV2QXcu(L9p.@lJo|!M{&;&v0-75}Jg$)fju,`5GA~&!#T,4XcC1(BEqz%%FW%$eRU<!T]t!){8rP#uXL!`@tQb!pjJ8`0<Qe^]BL6)4n7E$li{e$tS*~4W78N&O&9*3;T$W1>2g?$7U&*1hMH_^#cFc@H>_j$Ci[U*x^5_1iVW~28r'@^vE]o$T_>(!*,>m)pl?r%VjRn$F^%q&?(f{32M?9`x3qL21pJ(%nR0k)}F1`(_SI5&[(!E4xf0G(f8wC1Eu[O`:T!K3`./f4`v{.*MNV!)SW_92VfwF@R38(`AG}M1zf6u@2$^^)=n{l)^Ect37#n$2ik[i@yEap#2_+:30`~N)5Udc^IhW_`jPbv4$kak@}5?A1niiu1BRR.`9k_b3?JHU$.c9g`VuwS!V:eQ@I@Rp3#F`H%5Bjz``'%y4nJ:c@LS3;(k]]@(qoju(V[Ls$|)OF!2}sH4_d'k2zrg71yWP[*>M'N&<XSB@{<:z(SiOg(m:]5&RRGz)2}q?!,5A|2^3;a*$>f[$*9T5#j3cf$c(>u4xIK6`UgRv#dSUN*[pzi$^{z52}~lv3xy[y1UGP:3/WN03lA^~!{bF9#!X8r)tFOJ%'^9y1J,dL@SAA')|29.%Gr=`3tMo%*(dk%#h7#f2sP<2*NtK`)ES>;!cL,g#)*GQ%&)==)y(cw*B8=?)'aD{&|4?U^xoA(*Shx&#zUhf$(-P8*!Ki53oQ#C19?=G3SV+e2D]Ob*4^*&$5U*@45yr|4<6'*&GUR8$2}Kk`D+J'@5QvF)1F?^%Pw/b$Nz=3!T#oc%Mj]i3L8(u`HxX^)2(>z(GX(i2//`=4lan036DAq@{byU4V7}a#Hsv4@$!VL3=Jcc4f:f92yKXU^7PfL^q?d3)735T*(]Cb&!ys)!OQ5:2kv4n%<J$0(kNrk!GF_A$(Ptn@t&%t2)V-W#;*T7#2@wN3uVJd3V]}t@'5oe2k3wH*;(S**6V.m*PS*S@J6]P(<5yA!`2Ig@$!/t^+`tt),g'n(Ihqu3rP1625kP8^{u<A&|bPR#>&4]127@O2bD@C)_,fd(D6$8*u<?q!}T`*#>k:')nI]%3(Sb&)]y!X#y0~G2%Gjd2/8IJ3fiq9&fUuG*o=7F#/KSR`FkBC#Vba1)r6tx`h7d<`i(D+@fTrM%,9h|&DVrK1ox@y`=nIm*CKxu&^Lc22zj`1$OrD3)R!C*^v2au&(vIm2;ND0#yaDD321xk@x<;94UlvV%8th~)ui!t2|(2c^}A]z^>%+H4^T4a@@<2J#V&;3`5Q*5@r+Ad)-n'#2-fkg4X[~a^{Njs!'VWa%Uor=%e)R1)&0,T(((Q=2FTx{@;Kh_$^z{72@[1%5pR`r!?<+/$7>yi@a`O41(Py2$HM36)r%~}@C;[s)5seH1h-`G@{&y/^=/DB!DE8)${kM^4IE,22D>+?1V`ty@}Ubz#-qpo1^u+E4X_cp1H8#h#e%C;#6R9>^i&gv1G4?15`qR7)U:ob)=]r<&-/~$`iJx#4D8bz(IgDo^>ws=^JwgH1:8@s%w./M1wntf2Al4_4A|=+&M3f>%~Ds,$>('x!'3!,1[icd^$WBe@{%@C*r9LG3)VNR%2.wW)vwF0#>x'L%}`>F('[BI^?]$H4og=:(R.Pd3LFcj&$&$$1WC{A(1E-1$<G[>1]h'p1OT2`1?[8^4IsOd(D0?7!_~J)%p5%:%7^&5$Kxxk*)k!L%{RsI4y(pL#^:P%@rz)d$a^TO2<'<)#)[(#%8?Pq3:NN.*'6tr$5Wjj4s7Oy)8gPk`5h}b&NQgX^PzG%2G6d_1/}&r@<'.k#/'9J!Cr6)&B3BE4gzxI^F&7%(O@O9^|z?l1eRI`5,JSC%9a.S@3P(3`r';8`%4W&)kihc`;y*<)Si@R2}'+5%+.V#!x~>.!I'`q`,^vj*+2eE@'aV]4{RgK3=(+$*8|w;`jxfq1L}--^Vy};`o:^m@7)22!%{t'@]r.X30RAJ3X'4@(4thf`20+F*GjI14nMMl*W+gr`'aGm!)zX9$d+'q3W>XC2O5yB(tV2)59@^H(OLrI@WOwg&tdI<@BRt(5cb`o$$2i`*}oEe2K:vU*)ws+`)*(h*eE0)^cQ@{43jEm#}$O>4#ge~*&aQ](1;2?2G&nU@vI9&`lM]34Uhe+)Bv[q3M8/h$60T4*o;g6$bF;)5:zm*4$U'I!d;W&$^pKS#vCd8!,z)O1vknV&y0*e(IQ7=@K~4e#D2mc$UE-{`CiBo3t(W!^G?il3=hl$@cl>n^?T3&`D,{94P5bv(~@K}!d$Qi2n`#_1Xx8y#<3`@5l?9Q3mOtF28Bwh((}]@#CI;~$wp/l4|9o:)~7el#&90v(j{-0%IP#7#Eg_i1Am=<(5T'r2y-n`@fAH~4V-$R)X<z!4)2|I)]TAw&!{F+%$hmB3gT{W)JbD?*-_*?`[b!s%jgRo)#]C031&B51,-/|%Q-)%)Nt&'%9`@12|f`>!^7U!@#iXk%X=W04kP/1%TO?S@09'U1gM4/*-U3,*&i;r%v]g,1#Kyj@A32}4HS+-3Gguq3|1&e$9>aC#=FxL*Q#rp%H.98%D;5!(:rJd%!nJb3-*rs#,K:%5,@=w$gND>(@clH@CqQM1`m)U&'73,1n|e:&`xA#54|-z&L?y-3#T'c#J;&8)RqHN*uNiD$xc%51{1{%^PnA=!H{4,4/[AM&)q>0$O^}{354if`5Ip0@Hn|I`AgT3*ixXp!;R~;$Bzck%CSqP&9@qC1%Jz=!kXPx26}zy$)CMI3#Ew/^)E51^cw|a!Eddh3vnD[1EwAi)ctnt!n|c.!tOgB%<F_&$-$F#!>7cV4~^t$3B?0:`y^T#2Dn>H)1m+v3GFD,%}g*.%a_H&44OH#@4{`A4ocF*4?i1.)^VEW!J~2I*R7R[^4%kt3s~%J30~H25+v]<&Gj'O(9(Gk)cD.y#GNc,3i]9O4BAu%(daok#On5a3GnQA@%u#e$}/m*4W,G~!^DT#47v0(^aFSx4&y3P%}72G3|Wed*^'ic1de+^(gCq04[<#7%=f]r&l@EV^IunU)Pg7<&2@NR^>$-k!0.8J@iR_{&2H'|4ISJL3cuFu!Ow`X2E?m&)]/]:!PV.<4o>3B#P]&E^?_uf)NXx{@_q}$^B~*u4Kt?g10wqF3C%k;`5@V}1!(NW*X^s4^#x[]$J{1m2&ys75`76``n>6H`EVsm!l=PA4rB7s&RaC$5cV3355j-D#$?cv`:+K_4M:rg*4=Et%gaa9$ltSo37!jC%wFm>#2tSP#ztC-2hp!V$!0y7*q}ml%m]<M$G=NI4*]j:%^{'@*<ky=^K1Mq%-=bR^#+_});t`I%kdJ&$a@R+&*4R|(BS|b11F>_$k8jG&EhR!4lnwG2cEL=!^Co`%(4r@)@}U=^jqwP$9iah`@40T3PX[P#UdT=(6Il;%u1X-*AC3(*RJ@i#z_3H4oaWt(ea!7#/'=83-5Nn^K3j^!^_TI)Dh>7@v7Kq(=!*T3C]#U^@?g<$qQ_@@P[a,$I{9^`-`P2`AoN%!Nl4E&`>%|3Wid`5K<;d3%%a#4NQX{&sOMp$]vyR1b!W|%*|?81^5KW`nL|V4Ck^<1<&^B4HrK]`7sOq#vIMI*v+0H!*~b5#AfE]%`A`F*)TPn)4{#d*Gpqe(wn_X*]-]55>1n%^U^ok%!<XG*Mci_(d)mX%Hnng4s]Nj!jBRD)Pywp^i&l{)a$[8*4,wn@I1+<*J`'E2NS5<4f`>[37LCP)UT#-1mfVv$!Ilc1WVeB1%?of&=H*r@6Mkn)G/=t$4}33`,9P+2bL9_(9E/z&5'Gs(BTG*`#Ut}16?:>)y:s?`8%[I)3Ab8*:zj{2b?I|&+j-4`}|kp(qd$n2{qM.^U{ne)-xi9(-BI=3pTe!4j-f}$C6FD%U5C3%?[Pn*<{0-^<0dC`0u'{)i{=P^JbR|%;.HF47[b,`Ht7C(p~@!^UyV5%GGQL(GO}5(~N)L1LyBl#lHtv2tQw5#&cs1#!:.1*HM0R17Xq9&(h/e#uGUm%ONzh(:*UB%Tp_A@)c[u^c36]%rm[w`Mp+e`@)3%)py?>&<^nL2rTr:*8J|'2Rw`I&pOI:`B,l|4XQde4<gdG^<xES#lRu_3xH9k${u<A^'JhO)lS{P&nK8L%!>KJ2R(cW4_H#1)kLEo2<Idg2R;>3`ID?C`D(x^2gEoV4c]U@2w_{X&J`$x%77'G`@Apc1OMjN$y@Sw#tX(|^O%,2(0iNA2~`E))f9>E(K1J}%^kaP`Qz-p1Nn?%!2Wh5&53Gg^(SBe`tECT)x$[f1<-KQ@gCeR&fo4r#(Lf*#fo*u%g<q^16r|&^lj7b!]]Sj&Lf2.@GnPE)i'jr(+XM`^/fs<#K1QP1#])x!?AaX$(+2f`{2@&#FD9u%Rr;q$I:to*-o-`^6u~/%%knU`2QvJ$/$%'^j)B4@Vy!K$<wM-`KKkt*.faz^M/Io%Iam*2)k8]%*l2g1>jtq&)h>B`AiM]$^Dbg`:G)g&E7!E(Q.~U)'nC@)zt335Kt4=`Up|H!ImP,44RL{@[v~[`fS?n!0j!c`b|$x!(W{0^/Txm4f@<c2[;XP^Q}N1(%W*2)wH]X!Nfr%2?Nss^o|0K4VUc01WBRK(K^?4`,SVe&K1NJ2@ix3@ir)+@kasm4~N}6(wri31=){r4O<G)#%dK<^!4'4^0hk9*(-7M^x0/>)AzS2*i*sb&/~}p3-xa+19cr]4*-r85%lv+)qrd#$=d{?@K?vm!8!6W)x~Uc*@XzR(H<m`13rTp$z3;z4ksP/$Je8`@:Ic_(p|JQ(u>*S%))lS`Bqdv#N&n11ORz'&K58t)h{U%(a1og(X!C-!]6`{$]j!S2#5/b#tgkT$vDk?#UG~w`0}6[^/X}z!V!G.2y-Hm&8vxO$,|JC!-Wmy!':+R@9wj2&kl(M2cO.W$ETn.21wbA1+Cpo*I_OE4%&c7`|Ga^*`|0;@[?&8&aIxB&e->i@;5!#2/KpP@j%A=3w,d&%1/9r1W)_M)DiJr*Mrm4!dbS>4B+uQ1GQ}j(`?HU&0<Qh#[v8d*4vMV`$qd42E{kH!kif(!.cN?*ii-K)(&qy(cb>3*)kb3(!KFi!McBV*drw)3.x7y*<N)*$H#?)#AM}w&Vp?O41$vF&-sR*2='[##m+_24{=(()0UDl&>sQk^R.TG1nPrL%Hrpq#w%}Q!!?g8#r4^z3Xr>25K=X[*DP!.$Q>Vi%M@S~`osy-$9BV2#)Wj$(>Bfj#V#Rp3_GyW`XG8T*f?Ls#}Lqs4m(;f2~g-02H/`l&Il>V#W=i#%)IeQ^J%4x2uyhE%f{e>(5gw'$sx[O*HvF`(C2C4)l)}/4;(9.$4(7.1hI=o)o;aX(`[Rp#i.p&$[7`t^+b882=n?i1l64X#^#vO@6Ecq4&D~D4W4Ts3Kvcf3IoiH&_.=!&'yHM@)&j*3Wo)3*ImVe(I:Q<#H>aT*ULKA1+)VP*2sE?(m0!b1kb;/#NXsM&h>9E$*Ow$&!547^/^zi#{Qq71v>Mm%XdG`@9Jkz#eu++!)BuT^pWnE2bI<s@dI<Q`^({,2s2y|1@#<b1;=(2404}D$sP5(@?.qD^vV4F&%^L+&,oQU&b!}6`.#B]2OIKs)8!<*5bBxe`Ltt-`3v/v(dqtr^e;<X%t=wk&P=F9$O|uH^zo7t2zH#{1+m]l&a5lI*rzIJ1gaN}2#]#^&C>S*4=K^~$Q8<4(VktX`M*Dd^LeTC1GKcS3~gUg47eRu%%W'W22|{F3rn7^5]|g~(%_4G^2<$H)?,$_4IMQ'`+>03(7[46@Ger_%BVj@#O3^9!,nAF3v2[n&^[(f`j(0f3W}P7@PtJ)3+?+n*Tcu&1FIu12E_7W%#q!u){m}15vc:p3c0h+42NC<2xneO#sv/^(Oak#*tqbD1Q}Km*jro8!4R_/(03Si^[XpA*WiFT@#W;V@r1tT^8t8s1^wx_36+$,!,nFE`}$({(EFF&`xLHP1+z4B&Bt((5be?S11.sD`[S=%4<Nr.*;X~;2LF7-!gdg^5X~!U@d.LM)cXv,2^)d65&m<B*iqcs^Qi)L4|VeF11%.,4;v::&#Sg?#%>(%*'?|Q3B`mN%|gX34tUzF1f)U?&9?qX)`e][`:i~C#gkh+4m;0j2UmjK3R]UF3Hq[1*<3K@2Io$x(,=+C$Vvq>(~93d1T5y<%7eGK&X*xb@l]!~5-d0d*Q9jk^_MJ0^|+d$#gtw$5u|a4$#?cO@=h5s`pKUX&Ijk.`8V>05JryK))0`})qAiw`)j:%@^xk)1>j#a1.'nm&D`m72LB4{4,h6W1$_wd1RC)a(GS#k#!E;d!J{s!$L26O$?P[g1n:W]%Ihyw(Aaj/&eSv=)^1*m4]m8I1>5^+(]>)v%a_m`&qS[|)|VyU4$Op)1j($L&#$J+@M^L02TC**`V+/4!&Gp:&`?)m#NF-d)g#5F#n.pP!mhgA`2B0h@L3%-)m}<D2wT+]`]rb/@8z{U4A%V)(q>:3$E6..@*5+|2h'K=33s@F*UWh/*R*PJ!P%1[@hfl11uWaG@.~Ur1KTH<4G)1N%.p!Q1T>x+#s|7x%t>]e3(>oF(}^O1`$lQJ3{f.p1#itn*vI+}$(i,+(<IVV*e.u&)!3W=@AE/i3{iV))[zUG&sIF>(>:$B@nf7x^rp+m`OD7>#<lDs*`x!2`8tyl`|4:&`5DG(5!jTR$>l3F!+N.W&~232@sr/9!/.WJ)?JFC$2t0t3G#Jl)2=hP%!0;X*{(v<#*hhn(G3ug12Q(N`py~#%t!Nd)HC(]`-sL|1EV0-)6$;T4h.qe(yqrU^3/t@)_!U$^]*7,14'h24b<48)P$'J3,1Su!d*g]#,&Ny*oWMm`w61v)Qq'.@*${}^_TLP$c;p[*.$-v*r|/f4t^x1@u6PF*`27h^y,^($!|*C^,PJR#whBL*e9m<4/6y!3f'rU#kh'P*Mg5X^p)Ab%to)O!>Az/$GD~N1Lm+K$SrsH)u)9m(_Cw.%s{EG3#2L+^tFF!)G_@{(yjsj%PbP@1Rj.j3O8S_*R_KU@zWmK@$1_m&t@0?*Jc,.2@5XN)~Ui%(VK`O*4/P959*I&*<=/x1o0-Q4F1/q^#4/I&,`]`#Rm3T!ct8*%0Qji2FBq5@HT4(^S>3]`;5|'!I|~/`0]>/4Gw2,%#b_g*{fG_#v0[$3M=u*%GkjM2nT}G*#Q*22q*Mq(_'eN`1Iv*1%HE)%<@_{^#r(q!H$H8(VceV(:t=N2WDa%`na/j#f-?*%hu~u`>}c}1iGm#!:Sp>`s3nK#r41e3:[GW%L~MB$m*So$33@b2aNRV(AF&#5Xm-y&6nt`#6#Gc3dj:j^[$Ea^idd+%z,0j*@>|$*Thj[&#N7]%Rl(x*WI;f3V}uG&fN]g^h=8y&'`WX(fWPI)5T.[!{o@w&HMDk@Am:C`;AIA!4bMr&})Of4Lf351(IW9$h*4o$*)Lz$<R+(^$2QK%70q-`$?U3&8D<N!XakL1u&*o%rf1=$Ix|r(s/H.4y)Ta$-<UP$p3!I)4Qv}%{cKP^Oy!L4j:Pt@]t./37vi$&IANI)'IgO!*IO85`!Ie3l'$D4E1jd$#47l!=Mt>4L,[K%b`4z@?t!<*2&W}$(PtC*v0h;@9X8*))g-X1/}7,1OG6q^E0c&1,s3W*C*U?(9B'+2yp2Q*qN<}`'D`=2Chdu^B3y[!5:g558)eB$~.^M$ttRz(Ef(43x@a[$>tC|(ro70*<%jN)2Mns$K~]D2wC]?#@Vi|4K`Q-!doz]@pO;C1jr#|#v||B@o}:#*vKf'^/bon)F5_i&M0pB%s^<!&,z#b3D8et*/Tu]%&nsE%xWk'@:vKO4]z%C*F4s3`XFH3&[^I-(4%rj)?,$]()JhO!D9}H`|{{!`ev+D%`{*n#yvGI%>-$3#w*ia(STuu%542i1%<4+#OCC>#Rh@N*Ulqz3708I!}Iji`(~FT4D0[g%Q/*;@VdSo%iRxq`0T.@)95LQ3KAF_%{GfA&co.|^_dD<^B`{`5Ks`+^I)N?@?:H/2$*6W2hXL*386=.4mwHM)PVnF#EeX&#%U1@3yU1Q1F!N=%tA<r#o`nk4jz'h`yJ+:#&q*;4{2./%4a&L2KcDK3CX_`3Dm8|!3-fO`uWwr!+XLP(8/?j2,oQw(AE4?2E<yH)>@.W@L<j{^td@/#(#nn%E7G>$=+&Q*3Wfb$6vc=(=z!1%5>fM*`b/J!1HwS4vc(t4`W?o(vImg&|[lp&=yI;1A>.a`nCGa3FVNT*As:L%J0_B*:dS}&f#E:^B+wL4J}*c&&:.o)3!H@*%=Gj19|IU$+fE3@{3Nr@HdO'$-5h0^u,$6![_k8#4TNI(>7_``!fI}1KXm41RQw_*IsJ}#<0`6^gX}p`d>?-$K_9|^n?l+`+{6C1dTG|*_<T2%[z.T`:T?821iSF)Qw4=4X?uh$8vEE^GK*q$eR6346b>E(c#f^@M}[d(R)C_)5Sd^1-'yE1qUh(2<!n:`OE|:*/CcV1vzj<&s/0N)/.+j24rzQ@y7j.109?*)Ho`q#tN%h*9Q@-)mTt1%Mpvi!XTW.4iA!=&?F!w)D47t&PBGO*NwzK#_|Hw%}>4X3m1bD1H95=*vBrG&(6|:$t.M=(/(aE$2K*_2wd@4#t?kO3d4v-1`nNX@xMr~4}tLr!1uzP$$VOk(*@L()-Q)l*+CkT1|jvp&c&q4%bArU!|vn<*y08P^)g7g@0ccV*SgH}^v^[:27sfp^Qc:!3vv&&(](H_)$tr(&u'~O(`}kS%.XJN&rh(h%^>t,@epXV3b`!q)8,8`#}97k1>TNt3sP!()Xn~$&?XrT1f9^u#F?Uy!f3Wu%6lJ)`S'*e$}~i9@$ujs!5B$^$jV`n1Pea%@LB4P*O'|4$qW@@$J1.@$bxn5&3E7'^4!6u1e49I1V0}@3h~<l2ACy0`?L?Q`L?L6)qh/}*!]R8(FTj=`SH.{$Uo*+^upjq(I}Pa342#4((vcd4DIQ+`>=My#uX+;)rpj|1'pxp3qu$O$e0cy*.RId%@`I!*d0Na#8mXt^$mh5)=`W0@Da+q(PeyT`BrF92eHlM*3q1H4%wDG3T3cR4#QLE1xmQ;#muO-`T]N;)l/-&(_}mM$:/:>*%/`%!w`'m1D?RX#,Jgo^+{)}1WRlX#^KLG1$5dX`n8*K2!xll1S6':$uHp/2Ab2j&Si/J`QqW,*2AgV`ilLy*o7r;*2bVS)O=kW3??#t!^5;:1as9U*l-FA$QP9N&3vyf!mdvH$<ijn*;vK_(=a;65:pzD(9:k4!<|!L$u4hX&m=;03kj_d332|h)ps)h%r[e3(Ub$]!t3Pb1!c$K)'%9})56sK!#bEg4k$~q(VA{.)wa`V`+Lcb2S+WU3%@p;^>QiX&4Nsx4O^J|(h0vh#u=%G^PoF.%MU0|4NE^K@S)v=&n*iJ^F!}.2?-Tn`V9%%26h_g^<:#?!}^Rs!f{,h!Apr@^([1K#Bnrd(}~8U$&{x5)`K1?)a;&{#@A*O3qcKr4%cC_$kl;L^}>)'`p5A8$]P;h&qnpP)sBBz@5Ngf#r{p@((k$q`'DfV&v3V*!;$S|4.mra$f_eB&I,mk^Juq}#>%zg&1bf8@=g_G!RPyz&G>Tu(H1oc&em%##{<My*tzc)@~9RH$gT}P2p>x1@?*Tf`6tr|^M-J)4:Erg$OpBk#b+i6(qcE$4W[/d2fP$J3..ln4h9D^`_6wg)K>L$`bAoM3j%6/^LF$b%e4@B$R%N'!R[K4*y67#$+a6]*%sD+)=Ox9!Q4<E(dFS<1':;|&@y8k$$H4g*v(OL%z2=>(Mg^s10N:d(wj^a`{3:%!cUno(,oc}@gysW#Gp}9@|_Sv%Fg>`1F$ux`z~/H46_VK4X40z!lb.73XjDO)oW9l@g[XS3WW8l3>`)R*KemO%J_?:%$aUA@},](&~TnD#Lp<t%,hJQ4'Kr!(/FDS@?wi=39K|C@oikF@G6/f&BKW]$}TN=!@'AK$Ql^m1)zR:2r&4N*IyTP&/UqJ2dPSl*d;ft4Vd2l2,)ve%.k}62#8]r#9+5,^ke[<)`dxu!*AOS1u]R.&/|_G2y$*c!V}L^!%^jA$}4L=*cHJ,`)7Qe`EF}6$#G.=)vMki^D}|F#=k}L#$[Rc#(*,;(%]K[^`Gn3^$BF3@VDWR#4Hw5$>WSm4w$Ob4Wyz-@b.0#4#&8X&1DSh3]`A3$On?V2x'}@5*/^?^RLg42%jDt44r*V$.&*d*RU262y'y``7Rs5^uT&r!htmH!5~OX*yXq?3]|A+3s9_R%e%#J22ddW3{L:k&Fa4&4Xn?-`(MO'`.pqD!3dTM`M+jA2EBt_2U!|q*ut4)#SpuT@n[If4*b{^^;Nfo3mUWJ*'/j$*Qai|#fzcb)8mT=2DV8p1MI|J(7,n(126w}!D2z]@(Cs#$pj&L^Heem#9_t[1~H#g#:B5}2v*f?43pT4)-}dC(}8n0(j`Pj#`WBm`U7-J(xMEf3Adx<`.Su3#pB?~%1$b)%c:UE$f'6h`,vr2(q_s24M^H`#7bh*3TJNq$aNz*1>;SO&3EGy$Ff+y`2ck(#Qe=1!Fyu&)Rd([&`FV$4zR':3aWt+(X$==&^P8u@z!ak1]do`%SbzG@^hTv*-~}@(gn&S(gQeK`{Me-!FHgC3S|584295r4<nuD^Qo@m#sEU@1znHC!M!|a4RKs&1$15i`l$vJ1I|632U'B63idSx!$*bb`Ak~L1$HC}&}M1E%X<ff2dfv#@Ld}q^+9t'&+jf-1p]H=&%<U!)+l,.&'{ww@eqy@4%j[?$SI=))mX(321m>d2mDOH2b8km(N9uU3C`1v4:t4j&Vca)$x`hH$#+-~1tS~R2=IhJ^oU@U2y8e;2i(bk1qD3,`^~Dj(3loE*eFmd^|G?{%0PUb19T-s%PuX{)4cU!`@m4<$eCjc(6B(G1gg)H!@mIH#@Szb*^J8Q%|,5l!.2Sf(mkND&F#v]#Ix,'2/T+V22u(Q(?=4L$8D>74N~Kr4L3(#$1>A&@*J<^`]cTq^ba:T2F[$x^i0iS&5Mu.3WW;m&$+pi4g.l<1aD9W^,i}a*8E*7@bpC(3@IdJ&]SqH%mw*O&/<9L)k:1u#aHzp`gWcb%JV'52*Sl)(J1:;2aGI?@e!v.@[e/$!N7yA)hbes)[)GI$r#HA4l,S9*|C<N%XA>j&~c>5$vQ2%2ud_}&.D}J*OlCD!`08+).6B/)tJvW4#FGB!_y-r!-m#b#]CDd^|tk0*IklG^Iy[s!ox{q$,[xJ*:wP[#8ho]``j521;REK^HLNC(@*%22Iu%,!xk0j)H|wz^i8]n&4_V-^!4^a&aFzg&lW$D1}OMh4&n_.$8:q)%o2ym3`V`'#)9^+&Fp8+1{x=]1zNpc*Pm?q!fOqs!Wpii2Ma$m@]u@q2)?65&U0}V34q*S)*4%`%#o1)3|67u`<jf+&P}3N`gO+d!H[{_`1G,91_{|5@QB?m(2yu9#?F0e@/rb3#z}nK#BPE|!+5]N!/$U9%<r,C@+s_f^ANjX352+k@^FdW*,hvP3a6vW(Bw:[3n)GC)FPLc%7WA)4_0]T`A|;<2cA_,){h'a1b6pm&db=~%=M27*D-FM(m.$7*xCW-*4eV655SKk$gW->^`2,{%;?H6`&]'A&}ef)(mfW@1lm-#)!#{[(lqbJ*ow!Q)v]9O2<Po%#L9n=`mUct3Uc:8#lw_4%Tv{L4TGI*(+]&G4Xs4-)A,M^$Sz~%%0;FK2gEF*%!6fq3ct7h^Ib|q1%VCL!*}0t19v9T$35XW3322.`2<Fg!/&fT$,u{-(AER<*CFmT(>eEH%(_;2`g-ki47~s`*:U/6&XJj8#/fl{@jigj(L7{!`5o[d)5V`V!XI%@^#P>3#|C*=)bar'#!9QM&bu7a&wJ'_(]Ep>*q6w=(#>OO1`asD$+,JI#EWKX$5}c#)m>q]2a{(L3RiaO%qUN)`33W<%W6RJ%|t|i#=iQo(,bFp&UBT'42uQ{%l.8E@H#9,$/uIH`DE_u@]'_D2DwF12)rt!`BS]&@e//s`y<}4&6|9F(47/q)Qfv0#x`I^!fz(!1@J5u!5Ac8(H&N`49vQ~(oe'S&vp1I#cN|r)G*e}%VQ#@3[b9x)Q=VG!KDhL((i4C&HMP%$67Lh!Gg#J#^mx7#T?hq@8E16(&zqV&6L>R^3I?q455=r4B0f8`Xr:4*lknQ3eP]b(g6z>(L4Lj4-CkM(a8k:(VO_03ff:-)fw;o@9{8[`Gt{{!>4h~3@c|q`j]OF%<MC0@t#%$%bvr_(|a2!^&sj=@}zP1`UxLj^Wf[h^xWeN2(Jvf4g(N15edmi!UqI1)A}tf!7uF11:4-22Uu.w@d#C:@1g=v)LK[}&P'%I*EK3}(]ya}![!|G(IT~a#DR6|2'?KH2%t/Q!|wh1(N,y=$0l/R$~mwx!uK@|`U+rt%VA{=*Ow:F@sp[$1c!dt2AnJ@`.B.^2QDl)5X*vT3yI/<2k0tT@?`i4)GSdx3efj{$tdzD^Ml&D(!&6i((}##4wy`s!$$Jx^_#l@@Pe;q%E9p/(VPQ))XO,O(./)x1F!ag!}DCb(V#*5`Od-#@)Dbh!;w14@+>I/!0?%-%{#>d#0R;^3.kX5$>W.!*Q&h'**cJ^2xP)~3*)W_^I,zg`bcp*%U:ht@cac-2z,To$iD~+1I-0$!wMQ(*zp~%!)A]$2<5l'!AjOV3Epq'^i!eu%,JPr^bpDh&6>Je(+dgx^pdK[!_=zw1-}d&2LSe.(96]k27k]G`cyE<&['!t%{T6b1=|G/#TNVy$ejB'3(?&c@+5J8)>,/8!LL#2^FW<~`G{,@*KAqa#mjh(4+:fL@ckp`)6We<`1NVA*FI?h2jB|U2GUF]1D58z(+*7~4>_p/2!%GV!s&]'483RO@4V`9*J3D`!?qLb*evV^3L'{_$W)l])(457$lDxA$X?MD`zmgt$q+NW(*E?M&}D[O&'nOo4&}3N!;qax%c/w~`4^F$`5P{m`XBCJ){U%c2^y:C@7?8f4q.0e@goOQ#9p}P(;isT2UfE]167&()1$=**<G1W)kI&q^`Q<c#J[A{&wme-(+f6+%EhMG@voFX1W[27%@G43&ync@2;%)w)eRBh%X+R'2hXU.3{I8u^`[[F#IRH~3uV$65Nuz,*WJq6^[Rkv#]9hc4P=*!1pg(/1%MEU#~'vs^,|qb2L,E*$`7+l2&B%$@@xK[@VHrr%D35_$c+2j(3)'m10;0t^(udg)U3t<4cEe=&QD%E).*IK4Aurn4x8m(^0zn-*8;T32i%3}1#i?;1Q06X!zAd<$xx%M%Q0C8*dk11*zQ03^jz++^muBa1E$ID)q<By(LQ{H`|3*L1Wm>F%@Krz3^[t)3%.|V23rbq(,})>*I-8t^G>Lv*p>l=&q[aN1z@4:4Bw~M(1A'N`qbWz3/5%_1g]#!3FvP'(j49Q1KGHj@Nk{9#aSrW3cV|<@3?*W4)Rc$&bf#E@PHF*4xbe@2V@)x$_$=!&+@[q%Nm$`@RvWI%h6{|$FoR/`3@`4*i~ng(yVll21-0u44Eqm&~nkv$JP[C*6i75*B`6/#6K>F4T-zT&E>]|14wus39MQ55?}Gw2RqAp&RW]A$bD*~1x>/J%[G(7(?g`i@Hr5k3,/Fd#;d:q`LI+_@}5A04|s^.)*u3`^J|XW^Dyys^FE5Q(]LVz3@a2v)hq/~*dUUk^l_0V(GeH{2^%.%34p?u(Hnt1@a`hA@zJXD3.8-<%=t`$^'vhr^p_{$$=KSd`ra9j4IRUg#MJ}q#Oy3/&`dWC$!-Q7&-ssq4Lf}@3Q~7}1@`!>$$#6=)7tRz#pjc:#H9^5&153q!h@R}2!%0+#l:%A#rpHQ*f[R9*[!ig*vKJ.2uVH-2Rq9}3`zX44e7Bp*F|EJ)fb-A@xM-S&V+%s`eQIy#)_WM(J6>*&`c!&#V.uB(r<Ul%#?TG#nUS~!E2Qb&uFUI`WCnB%Eb=V4',<m)[WuC&?l'j*W7X)*z1Hl^CDsE1E^xP^nVc>1L|*c2(?>l`i>p+&*m7^1Vfjg2PAJ,^#3Op%5<O-$BQBk1'&&<!&%c+*Qps(1:);941mhJ#@1Ps!|!L$*8VEO#ag:;`aD@j@n-Gk2e^XE&Sn_`5zSp0^.%)S)1|Dx*6p!D$t^bN*C.d_#m`|[*T$(z(mV#c!9JcO*zaz82h0T8%Q~|j%16'p*=6**$c}Bl%'j'31F$P[(w[w+3!}k?(]!Oi2U<n23d;dt&>_P2(?3l^!n{9d4NMOX^&f>s3tA`+!<mG=158Sc&B9`l`gkQv$S1#>(2=nc#04dN#>yCk#;;F0#_*{!2G}z``TG2y!fb=*@V7e,2N!Vb2y6_`^'it_*dfzj%:|E24|cfU4($U!27+DU`z8*[4>=s3$%bey^EP)(^IU5:`-Rbz%4./'*,Os12DpOu@dO~_^A6c%&l(vf@=KVm^Qu{v2Do[O(#;@G@v#3u(mD[R^MvS'@{o|?`w0@{3#Ruq`uS}A*|a|`2khMT1sm33#z;UC1';;b*{'I*1Bh<D(`T~d#e'_f3[9}g3ome?3pA+J^?[S*)HJTn`v2pg^WgO32:hPW4:(#(2#f>z@rwtj)z3c?*rm6h(1nHi2J.Ig(%-UV2!hJ0(*oq-)U$Iu&qFv`$0p%m(NF>b#|}%(&.@4f^1h8b138mO(H85A`X^;~!0e@p4sxg6!B_,,)-4mq%o?*c)0f$B$!qys%6yxM4f1Ku4:rIj^Bs?'!=S4C`HV##`2'$>#loK53,D@b@MQ:z2NVA,$zlKT`U'x4*uxyo#+VmK^4jR2@~#7h$J7xn3$;b!%a)%K!x91}1A!(`@=O5{2z9sx4a4B(2j1K/1xfSe4J_)01vcxr2*545&-|~|`:SyE)8^w@%B@.~#@t4k@[KlI)0PL:*8'^H^;gGe2F$;t301y`(r3Ey&WxJU%wUtp%K+641WJB;%n%x@@8]`M3uu[a*.qlm%tjAf`#P2[(I<}u2DAts&n9q2^ew&=12@/r#;hqr@u5'&`,}t4)iL9U*?Qs1`k`hJ`nv2z&cHt12Dv8>2%aE{)I;+()0o6c^&${`(e@m%&MHtr!,.Hk#]DBP4,%=[*R$39!(D!B^xz[>^Kj%@1B78g(5/:e17m`;2Qc@c$E.=j1*vz=(](H=1m]7F!LE7i3&j||!JB5e@Gjk])37Ki#w5!B4(V{42JUlp(s@-O$!E#i1hh7K%4NTS37J4^@I]'g^4#|S1EOzH2nirJ!sUi|`?T'f(*7T~!wU)8^[.n0@AW_S%MaWi`EC1<@!k}G4sr9c1o@%.^i~?:&|${*%rt,L(ty1g$:Gx?&IUE@#;@jP3>q}^2Qcat!]LUW^*~uD&q/k_37jU>*|,CP)R'<Q3p,S/#'59C3D8=m^@6BF)Fqh14vjc%&HM4?!>(3G*Dm#8)C.&D^9-1S#A>T!!MfG6^6J{g!hvW4*g8]!@qVJM*j5gp)%3_$*`x;7%Pt=F@-Utn@k@Da)>4^X2nScN4MOA^4z_0~2a(2h4n,Ul&3*]^!,xRP@9A9b^,D3g1hv~j)E&g}4=t'L44:&r3SOL2)3ovB*/TR]3f-ba%L]|i^I2rC)^&1*$pf.A@A,`J$@fv;^}pU_2??i3&[j`01'rcV!s)(I$3XwJ@{}@J^Xw~/!j9T~$ivkg$9Tr,4fB5q@1:(6&u9h#5Nyb2&ycOP*NUCh!$y[^`w(#](``[;$'/Fg4%MIk1e}<P$t&*q3qeCT(/vBl!<rV)&u5<-1q7G(2sgt11R8n]&{euG!#ar9)oSFn(=&N'$S;hy(PSV.@mnI?$hklO1+7#p@eE}8)9OX%2U[1E@>Kgc)Ltdl$c,3/#d&b#!UyO%!5%tU%5Hi{%QkDu$OQ3!&N]<;$AJUr4bt(s(li+K&:mP51EtD'44fQA&k6ay)Lxg7%V9E_#=gRA@jsmo#]_(l1y=N2)rX<7$7&rM@flEc@VA5i%wTPi@L{UR`3#ta&.l@#)K]gy%*eGl%opX~43k~`)bB`%@V0xw$j~9G4|wx~@t?M@$G.DE@=d1N)CiUh*r:En`/(CX&'nN.4CoBT#P2XQ#UHhm)OoxN4zMHj@Wg/m#{Hm(4R{I/^'fqM&53+K!p{&g`,^-S!wEH#@z8I1(3sAd`^.Dr3uC'r4.Ql])cp9B)l}`,^=E!p31axE#A$kB4*R<S$$)b^${^n3!nS+N$&no814U/X18F|-%R(>X^$~q(%{:uo*Q$)>$rurj#^7IF`0[/b(qJuy&!ubH)^B%;@=|N9(g|X82V[`C%ee:s$5LQE1T)F=!8D*3#(,BS!3edC1K5M4&lq&33l]M$%eInx`)GF)#&6|U$'x}A4;&m``~Xo/@jd{t*NQ]{2@y6-(%gMU1_)p9%kH?v$6Va(3S~w+)&Fk0^Kw_I(I|M%10,/=4t*Kc$-]~s`XPUQ`zn1~%<Kt?!q-To)eu}t%1;pe30<WW)yv3s^`mt%14P@<$X[Q/4{Som&t@]$@T*g?`sOx2&lIa+^/>ns(^W_6@}<~$*WH9!#dvCs3OuUT@:Wv'${^H'!cFLg@a@4q&x)WB(}mb3!q2a?*1pFk&rcUb3,qV'`lAyV$ros(3wbC;&/f}x1?kg8&.Ufx4+K-8^:8'#^i_`=!(k8,4IvmX4kV`}&`^/R$kU`[#<(?a#Od`s*4'L[@Sj$B1h@L2#p7.z2:BLT!*Px0*r+Gp2vR?'(@Dq338#aO#}G,~3$wX]&R49~*cfw9^b%=y!@vH_*h(uC$a4b~%VGu)3n;k}@10g/3u3Hp@2V<*)LlcG!NkdA#6j'v$f$Ml2)GxR%3Q5^^y{:R*xc?43E,lb$x}NR2&LI`!_.JR3LaH7`FI]I$v57-@q3R3`SO>:%A|?N!'nb&3F-bU4[Xyw)ARIL1*R^V`b@d>&O}V/(WOd:&~t$h#x4Gi%AOsf1VG^N$;5d63Myvn#uDkK`1xN?^`(`E2kA`B^}XRt2;D34#ivx1)6'IL#z![u$rytR3(]%P(;}Ds%]WQr)g)zN$ztFm$1_'F!3^L@#7q]2^FKwu3d@E:)K])@$+i*/`R2@1^/]BJ!?O#O(cQzs2K`^s!g@t`4@lO{!9O]z!d)Wo2go)^2)5n.%igCv&R)ph&'o?p*aS+e!#ss8#:9*'@@d3I^4;Fj2m`gM(u)j;!P4#C*%E,=(+Wn,%I]ja)uK7?3@r5?21e,)((XqX`W@K[4+<J}*t5h?)'R,&&;@_V457H73esD4&-?Hq#hl`L2Vg=+!w#Ui)9?6]&!_cB`I>~A1AhlM(3Gfa%VH4r(C[q_1[vq|$D<q&^^3_9#{6PD3+$t]&l'NS1^:'<!VKbO^mgeX!K8*w%hsI`)&qKH%mU.x(|z4*4+8dC1BF4h#T]14#~Q0'#9KFX@u@`4!xG$d4-Wj^2n#xu4Ly|k3{k6d&<;F')qX<<!E9$h1R.314>m_04,qu]$uEt{3]0.$*3,lB(:lUM`KadB)6558#g|le`g>Vm^p$?w12nb&%q(4o^!zq1`/sTT@7)ky)j2sJ4z5nv&;>!U48V#(%30wO1c'@i3Hr_h)Pq/=1JN$}^5)Ow4d5Xe`OLD2`|zMu@ga:H@xNJs`TL=G1TB([#;:.J!esKQ1<]MG1Nqd|@QCVU2[s>@$o`q6$NhGr`@jba&^~GN$vwRD3s<Is)l(2b2fUKQ@PF4K$jyml(7{rr&bD<}4{HP+&r'ol`Xzt#$/Ezn(j&,<4G<~:2SU{&^x5XH%j^C,&eWKy@Bhj'*,3PD@22K0#yohK#`q~E#,7z:^gx^^^)^s,!S)9.2?f$f%}[m7`z>6E&mVK9@f>|J4m4MK4t+q^&JCnr1'c102wgKC4OV[<3+<0Q14vU0&AM,:1{R#-%T<]z%UwLM1+z<S3#[ne@{KDS3F!^)5&7wQ!2Ej24/K@K%;4Wb&!<j[&&Wg`1Ez?V3z'C0)9Xv+$,Pm]^DA8k1cnu*@L`S^3+in8&{Ll0(SV;42bo8X&7!s)1Tv4327a&+$Hc!o)R+fl&72aN*,hA#3T|nw!5+c;(@K;2*@a{;2(mhh4?IPs^0u@o@4?F#^p'Rj2p7^N%QNs.&e-]m*{=n%$]$'B%hSL@(o%k6%;qpo3Vzb,#}.6S%wS#.^K6xn(t}rl@5jWK@l4dz%%W;j!#E+11J:zK((kJ9)kP3W&M{B#!-%$m#spvB`cPqv)Hfu9#lj2T1^:v+&X+?|4_vWo*2E{@10OwI&WLl7*E[*[!/V0j^9Jj+2V][o*>c6[$jC@J@]bqG#`76O3=dOg(@kdK&dK+R#39Iy1S:5U@7rK7@(4'k)#h[S*B4WX2%dfA*Ae'M^T78x*-DHN`d{H{3d6(B%w<<Q^z9%g&OV6`&|%Fz*jB.7&,Ul|(*+E}#j-&[#Opt}44dnj$AKWs)RFBR@WH}!#T<(J2y&qT^FW3o(]-lC3AFkM)?,xw1=[OM@Ownl1y7)E&wV*r(H);4&r=]55_X?G^|4B;26``72k0n>%@ec.)92<V4Vci{1ijFM$3l|)2XC?!*$2i^^whA.@kBG**NpTR([4_C`%R%d3`(8(@l*:^1VN$'^qNK8`|W&D&0Mb`3V5iB)8-[$5!yXq#rqim^toSr4rsqc(-m?3$ofkh((g26#8zvp$i!$W$y6+-*(*]P3~=@$!(b3,^nF;m`HEG@3.=aF`niK_`qLV>%~Ht:!PuQH*6H=O#:M^F$N_VC3ktxo)h/r*1=Cep@Fqd)1VlGX@_A}v%|r=M3Xr.{!T8Mi`zvq93M'C;#QHoF*T%nV)3q2x`Q|{J#b2ET^9AIp``,27&pp(3%U=G)2e^1,&?_oB`,jVA),e-!`itpC@HQ)X3eu*C45bs[1Xq+d3wllq@oPx]@fw=>(BX{65*70K%[R1;4.Fu95#m6~`G!f&)t+I=4?_-&#EUj[(P5yN^1nz{4F`pJ#{?H~17/.13_P1/#~Vq!#EVas#@?{8@SVV-%r)9P*Xe*M#5z02(Dl=l11th3(_-nw%/s*=%f7dM(&DMR2bDy;$GL_o!z:i04t3'*5]z&})rb~c$[,}r`m'x`!k,K(&.zr5%H~`C2<mxc@2q6`4.?=a(m]yT&;`*S#mgq<20gC>!%7].@Hrvc%3M/*2'yX,(GUpU$,cea4Nu6X1mSID`hnR0)Pb$U`)'1_%mnzp3eu$A4S#?u#Gm1+)ce}n2.N;o*a8y_%$A>&#o)23%6=6y`3})m%Ts~X(D>Nm2@4g|4&+Rt(aIqj!mD,K4m4Kx*EQL[1{fIr!>,GK%kiM/$h2#=`owuh%Dn^<3#KF(&UU|l2CH*c#9#gS3VkC2*X1g)`aXr')oNq}#Vz.`@>FRC1GPyu2I`oj$g0d>`L~*Q&U5q:^I0{B(CWG0@N<-9%b]Tl3X/_i`-M6#!9p}N$oiGF*}Uc54J=sV*7o<p&/PL7%x90q2AaCP#O+,q!+C[-!SS262`Og/$p(?K4G28c(Lk*l2L/L!%2p4s`/.V`%)Gm^^/$7_!j''a31=hc3&Gaa`;Xx[*-*#V!Xvk#@!-*?)iPp;^`xkL#qEr^1'u7]%=ru(45s+{&&fI!#l!Fw^GX%g`v08C(FWMi@so`Q1-hr_#MJ*.&l:o<@CcJG%J@yi1hua{3(5ml!N0.H*O7|M%~+l;267?+%n#'<**e(H^~bmK4eFpu1zV]+2WCy{%JIwC1,!44@d)zu$x?TA$OMU'3{hL>^=94#$zJ2m(w$~%^am(l)K,W!(yTn;$FU^M(e<S$468Ux(A,Cd#s3<1`,A&B)P%Cq);s;]3T9;X2n4qU`bED2^XU$S)aV:I2HAE_)4vQn^jzNl!(;p02<lH2&PmX12(.4x#9{:s!2t7?3z93e10i,)@&ED%3/1c-`h(?1%%R2,4ss%^@+xkO`4-QT!S>,v!7M7K@%tqc*e=2A3/<w@*qM}J@Hl<$)'aHU%!onK)hkDP`pv,y!hl4#`TzNK$a{uT$@-g9%9<>w$|ySd20qhr2@bE$!n}P)&IA=M3|8B#%Df(/(j%bk(c0/K@ur*u%qXrp2(+vV&vjSG&'|M~2a)=42;$+|#}%D~3F{*625'zx3`Vw1)?2=n^>@my&<4?.@*>V42|wIj@:>T_*a:|/$W9iD#C);&#%w+j!dKl:1&5oz^4}Pi^k_v$%k@:O`#IKe*B$~m!4k>t)d]a{*A;tl&V)fd4tHf.`%G@;(_^~F@BE)$*Wk8*1lb'8%BT|8`PPD`$V9xE%GB=>@-PB_`E17o@PB~))9FF+1#(pE``}7m#*M.S)?iXP!+KjQ&beWB$~[^?!s-Di(3bai1cl-'1mn,)$Be6*^v;aR(~9+(&]wto%#dAw#!r%K*AJ3(2sW8_*]p?:&d|J,4crn<$*~#o(/W(1%L|b>([~P?){5ct2rH!M2LuC{$Fc+04c*85`xHNQ#9}z'!aKf&!nX`~^E`-x1bFLC)D7xP^'=L]$fX8o$8=g^!|Bl,^WR.k!5U9>2F:}W26fJH(qXWJ(v@ip1B4?<^1^_g4ht^f&QCcx^.BeM%o>&{(68^4$dp'o3i|u5#wP1A2bLQ45#7X,%F!cI^[~bs#v=d=1ueM6%7B}E$(j5q%'$D,(]Gip&RS)|)JldP(o-uq$12{J(;5f!36bWR3(c@U@uJ?!5BUdu3!:#[@'BT,&s/#r(M1]L%,*Nn2L8$^)l?fL@;,%J`IC#_)]+n3#6z!>&q*b)#1+*2!V;fU#p6?H@?:W21Iu>g$},iq)jls~`lvk3!ntG*&(xRW$0C6E3PWPC@b1q<(7w4o3NB?6)~CwL*'pai^xkM45XQo^1,iSE%y)KL#U=0H3D.2w!#%_D(v`HM36|q$^u&dX1&u$(@QVMx^BbzB4t`hU@4/l'3Egk_`vGR[^+UR&^HNB~(%/.;^X-kJ20Eu,)NC%%$D<Cc2>3kz%043$#0nuw%(3<9(rU:)`_vHg3b)Oh*Gm7t*$~:7&x2mU`:5Uh#hy/H1`3c0#cIn9#`@}O#)qBx2~W>k%?PVp!a6%5#oNm#5>jnv*z;/H`6l|5`u'kH(a(1Q4v1*N&1$GK@|jK73406C#>dQN@eM8~%fJhr!I_`n!(77L&LUNi2vJnP%d,SW$@s>c2D(P83Ok')`^}%)(+>-23=~}C$),F[&+~p&#h6|23Rkl}*Uo<f$f#a!3E:g8*yd&C2wi[9`%7V84,+|,@u{@O)[N0{&/2=C*$a%d#amt=#k'RD^Os}2%u'^v*6*]}@hapl(NdGg1<Kl11>J}L1b]sG^o-=P1m*7M3L@]}%{QEE)9WAq*Gdt118U,V%Pd+8^DIz#)8GVQ1Sn1#)j0L=@.;ME3OQd;)A;/0&paE7*TTM4!3b:i*r:rv!-zqr!XaMQ$c;.X`@eAc`amcw#SM{B%&E/T4/_7l)Ra6#^3Doz1N6@3)%~>X(E==7^HMmF&9htX*x4:$4t;lS#J}d!!As9}`rK[=1KE]u#i2y5@po~t#)Qp)&)}]O2Q}p!(uV_d)xxT82pp3O1}WrC4@DA%5*,b_2kO)H(MX}4@gMU/%io{l*)/qS&3E5m2;<mI3}^LD`K,]#!/x~5$EKD>)#~2[(0e+P!1m1w#@S76)tB+g4QC795|da|)GjA7^IBgg4Pnqb$qNyn1+2:{#n!%}*yb1*5md*_)~OIm^a60t#)94l@zk3a%Vr)*$j=EM^EdU[^?PJd!zr!n26x{c4xwlk`#Fs,$~},{(}jd%2]R]^1j7<M)eBw8@'}l9`<hn.&[hM9^Ce!!$4CH^*55R|@q8)L)pT:,4#sLe#G@d]`'<y*!o'q2!55sa49Un,2Dm/V2-h8n$rXB1%gA_[$,QH/%jM.!5m:n##?[`R)>tB%^P[DW^U?s$^l|0H$r6u;#z{??!Ju|t^)/r|3sV8c2%D(B!WJ?2!wUEk^@KjH@q!nU![:~f4:`MC^stC0@/.~G#`SMR!8M(`(/pzU(fPLJ`aLn[2o~}03GOl}`NSfF!H37k4K-2K!N[*6*d*Gs`4Bse#Nl2i4NzJ&*'yt$(yi<e`2/<k#k@1V%/E5a4IIm@*'vv-)Sum>^x7Ax*Ac*#@&J[I*:bvU3xgK_3C-Lh&-[Sk@X+2s&;afW4qx*u@v9dP*.m3g)q6n{`Um*a`#Xe#%s'oq$#+;X)Bk`a&E_:|).1hX`vp^X^1+aU$u>O+(BnE}4F)xP#|IP@%{n/55j^hT`+`K!%N[b3()(wW2w9z[&}{NM`N<%9&;{)v*e$]n$tq|I`+&!t&]vdl13n5-&kdRS!;y%R)hO'T$4ppa&7n%G2P2T.*]^!k3L}/L4yo:K2UlCf`v03V*rs0t3T=eS1pxz-^;X0>*0>b|(fe3($}CW@5^M()%(3A)^~$vH!$~015WGtt^;kDS*QACt2'qVC)j[x?38M3q@u7Jf$><uF(L@9h39pre4](S[%3a1:@*M#L#CjK3&4`i}1R5O=!V8+j*|dll1!v`,^Bncw*?z{i!iQPC!wM(s@>b^T#Hmu*3z&O836jy'^aC~u@OOI=)[m%L2vq;S24Qme(AoOB#OAgN&m5o74o{[V%;R7I!G/3(*;QQQ#PrL54|c%V3oq%b!q8cs1.):^!<@4>^p;Ah3j$}r)hF]t4~,Jj#>U#x1KE`>)yA{a#pSxI`E<O+3]fz42&p67$b#3C&Ix(-)EAU((#>o(`5^lF^sTIE%m:ni!I[?]$+g)n1#J)N2?TA95:hT2`=|?j$nHCC&}'B^*ok9=!hodw&P]q+$#^/!&;P,t*qX8248+EA2CTg-3%,F{$xiv$^.={13QmjS`t4a'$*F;n&!.~&@>'p#3SnR>2~]d2%s!9'@E|7h$)M9T^W.Cp@S,Q$^mNAy#'#i*2OV-'*)`E+#tn@g#6zAW4$z7k)v4QS#ARdt#POd|)]2$`$;6Fb`XQ6y`SiCE4XO<[&)TS|(jXf-%%2ad*V39q`P.US^B8914jEX@@)0{m$9$?~%;*eM%os]n@z[s.@^d_A!J|hO&1&tQ`1/:t#Mn:~)dv<@^9R-1(m1J_%[.W<%$hCr#F4A<#dI7[3sl/J2{BPJ3E/H%5uH~9%)p;-&()VO*A+5*1&DbB%,y}M&ti.Q`0=GL(h).O&vCQk2[}6{(-Du*)VQ`}4?;6|4EE$.&wzM/2dz}{4W@nz()*EG$J^I/!|(vx*3Oa51e4oa*b-cn%Xlvj*hPfp`Tl-A&]p0)#I:Up!4,GS&Dy{f41);3@A$[A)AbSd19#SG%Jg6l^Dh1o2?BQ,34;q93ES;]@xQ+`1nM|f)5M>2`GQ>1)-@7C`JW%5!5zbF`?p)?#%=SO#COyP(tAFf`4E<u@#uIR`y3+@^2E3L`9d6X3>[rQ4p}O-(:@1O2>6OP$Kg@[#]!'w!@a6T&3zr@(+3#q@ML#V^tR#g@_s(;1bz.{1sdc0$~He=#,rMr1[V|l%Sv1L!Cwp>)`8i*@|O()3F{Ck2eDNd$By542+lWc(=6Ag@WidT^HhH((uB_S(*#6q%zJ5i)=)hE&8h^e1O~Q$!OxI65Ai^S`3n;G^2#5<*]V`a`l<6V&(92b@Q(ws%H_@'(PN(h%%?B@&(L4@5`,T3*JL.8$>e#i3WTWb#^|Qv`~,u,4b=wr&O5Ra)*W~N3Afd]3)}-1^30F-&Kc`?!I0S=!G8R:!TOc~3$||%*`W@;3gU?P2Mr-I@$$L9`FkO>!O]hN1:aJ9%}-~f2ejM$*8xA3(9n(F1_1IN)]&x'3KhgD@!N}t1bljN%C4IT&`eAA*V$Px^g}R(#RC;0!LS/#&;&Qx(z{Ku#9sc%(O@`F@G+}!){)Il24`O[)]LA'(:;Fn)W.6#(M[Tg4Q4}&3WiBP(*he-(uGWa41!!z!sfLU&+Enl`VmGA4eP:{*K&bT4jFa]3X2cl$%2v,@*O+l&j^-{3>gC6^2|P#!'6o[1rf<J2(oz^#}_TJ&Hs3y@uUgO@>8$4%nwUN%QK[A`A?rr128fc@4XqE%wXz#*ksbw29j5Q4kvR0%!^Re!EwH73@D#=*ck@C)e@W|!>'j&#-M+(!gMs|!qGdO3R7-F1/hy(3KUQ;!66=0!sivP4]8Vb4{4l'1qz?D^AV<,(=g~45i*fc&<)}6$D:kr2/Ps%&q.PO4<J$!@fpI0#gFKJ!54AX%@2qO%eP,<#FrE9`Uq&Q1i(NM&]J<-^,wD|1bM1.&%R<32u50I)]PVc%Chg,2AI3G15TFT^fQ4L$-{cy)LD4d`y>J{4U4,C#~=1z)3C%w&+L/d^A,*K$!5O1^qdV{%;fX`2zwbk$Js,:(!Gb1`x&[M*!`y]*%K}M&`L^$#E|d5^Kvlq%ru,'#>Fdb^aG-D3S-I]!${)H*ugEQ&UC?d&2M8W3qL!`*_-on@IVCL!AdAQ2xd[h4d*f/3JT.j!:z4y`9+hC3W|22#XSOn@V~u5*?+n$*r*uF`JcP#(-=5.$w#gd!shWD$gHPy2J~-02QaOs@1~R+1-;dc#K)du2;'P|3nb=.%<M,_^/|-'%1Lz$(;9LF(dUw!3>~IQ*{j5u2bDW4`Q5uR#r/<y2CE'&(mn$$4-E|`46[Ng%A+d01h2H>!4sGo4>'-e^*C|3#pw`21XVIy!-PxO^TBt23v1zV4}EO4(Kn'C2Ca_;*RIV'#EVq]30>pL26O1O1yVRr*ePNU^r:6b&U@!C3dB**3G)JO2,59W*pKa4@$kK,`{lQE$%<0Q3]vs}%}!(f@}z%p%4Jr.4RKT+@3[pF4dgSd3/i81)E$F;`2o~8(wH]9`6p]I@K4q'@t'$g&;sRg&Ot8s@,8]25gR&-@xM%W)6K~S*%{=!14z~E)_c,K@h)h-%'V3X%MU+1$qXAv(rwB5#BVun$7n-_%4v)34d:^j2U{^f($l}|(K7P'1dqHU&#y]`)bPV$1mLq|!4nA5%(tQ6)Qx;B$yHWP)9sdW2LpS8%B'*H&Sg3E&,AD)^]&So4@Q@X(q1Ow&mT&C&yf%e&M=d+!f`z@)hM@[^/wGl#N,>t&2GC[^`@o$38uIT)gLWr3phw;!|8bB@WMN922zom!Pz(>`%2Gv$a[+M1^GwR$trTB1yh/-%UAzC!2TC%)t:[;!7lqk2k*bA!1T.K!_[$()~#:r4okE6*%/)?#m_%u2Rc*d(J>+8(c8|($1fne2+(.Q#(v*G1Uyv%^6#gp$Qq^T@hARP$n;'@&pK(?$TQCV&4|Q'^,V7L^vduv^J!F^#`p&l14B<0(f;vt*XD-L1IhTw2(@^b4_~{,43qsL(C?r:!)l)A1.@C3#38Qk#~wXf(M_4d*QW^B^^T4i%=,/4^QJSA%O^KR@a?Vx)dC`,!{1,>1gzFF`_'q_((DL2#s@|v`b3.149Fh_&bb}P(1]qn1Rkn:#=d>@!Si?5$LGX>#^fy!*_RN95iBR*$<u|03m&(L%PqW{(n@#B42gut)b;JW3~Pl)#D=NI(Q>j2!-?y|#DWcB^G'Gm44y.02^:9!!uhgL&H|=s`*%<S%B_V5%r4:`%lJ!@$Qq3O%!EPJ(S#K8^9uV34L#wc`(N5g&]GH,@OVAR#5iOS2;5hh%n#w(5R)%V(fi8C$08EN3]D&]3eqQ?1B:n4$z#I.(HSzK&TN#G3OKHb1JKg.);|zz!8r3C^]8Xw^CE&W*k{8E4hRGr%;6(l`f,l7({NN^1SODh2nWbV@gM194/s7Q$:CQ01F.6v%<nVJ)&e4~#DD{w#R2kx^SQ%S!q:-z#9*@])V/X,%kyKA#6g3P!LGzR3[{;E1cK}Q(Cnqd*c1`S3:iSI(cg#z`Dm@l`AIV5$Drm?^#QHJ2$c#94qJSA3dCid*k@Kd4$0Q-1~P5c^Osu-1hRW2&,fm~(]giB(v09L)#Ch/&}_sR(-IiN40wAp^)^hJ3[=O^#C_;25hXe9%KOs6)8%%G&(PUb3DQ`A*r6M)&upG.(D@[C!$S]H3c(LU!5q'x!]kNJ#Fpvw4+eaz1h;iw#dviF`WN[$14M^E4C@Vg`DG(($b?RB!UF7*@8w`2`J.3{2|z*E*$>0S#W73y!~>->(Grwt1E}t0!vj^@3^q70$67I%(>>N!!NKSy*6+1<@QhtJ^A)>w1|&Rv3F[r8^{Cg$3aBWT4^:Uu$|85Q$QJIT3qbUA`=w|M!3'}F$o!zI)!],:(o@w315S7'`'Ln52&|^V@V4|K1*C4*`i|xR&~3#J4}?v657!'s!@hI3(:.p8&lX//#FfcF4AyG%^khNT4QO3.(}R'35Dc@B&n=wj3H|[[3~,G~4v$[c(v`ic)P&;W(@h:&@3q>(1D!=P47)+'^UGhE%O1k^%[v=O2(B_6@%ozN*=(|n1^69_`+|Xe){*[9`&K'.^*tR2*izD[1U7ys3Q99r%kmx:41]BR$6.Vv!QT;J^J3lL)O;3X^B#D]^Ja86@hk6o)QXQ@*5|#(205HV2b9TC4/DS?&9rdd(fR=U4^^]}^o[||^t$8758W862>v:s2IFF*4/;y^*ek7_&9/IR@z7tb1Ngow(@5.>3F}l#('D|5^dk-B2U(#2%(Q#S(B>(j2oD`@#mjj$5V,b`2*(i6(8BC&)><_t282-`&MNb>@>PUn%cfio$=$-y^~6oA1A<y}4O~W%*nF%A%_bIR@};RL*1~x*$*z):26L'y*W[4p@TvH%^#&8=%kRCf%_'k+$!4zl(wv+'@hg}&*fO?%&z;mn@S2OX#7KdJ^66,q@VvB`#hi77*nS~~)Didm#b+t)5zU+L3t<ct%n/4,)xxWo^$&f*3Ggm3@M~Nm*EbEE$[v,e#uJW2@iIe+2IM<81[1}(&zM_N(PK|4`g[L-#Nrfw$CJ:;1Ad5a!](`%*vw^!)Gz_~*k`U$)T)OK^20I{4##Wl@gU%^2CFj~5aruI);NI:2.+D]#y;oO2zn->1;:?W)EAL;3%$[/@A}tR4e'!W#@)/T^)M[;)q=pg$)!p~3hriN*Ush>)3t>))/~&z%.ngh1*yp14C~C?3vW|$&g[!:&OMzh24nGS%7j!,$a~A$)t(UE(2Ie@!{q;G%j{h%)xwx/3V(xL!B#[%@O(x($;7R33g,8r^+ht5$O%Ol2bIb]*RyPC&NAw<&{Bj?$PG4M&yxGp(jcj'`vFlP).(1J$lT8?`Ls$B`9_t]*`_3q@Khcn4-]#~&old~%bJK.$$i-H!lOm|*>hP8#A9qI`cb{&(Ew.g(nfh`3B@$91;|08!!~Cl!u,B^!t2Qu!)iLE2z)_#&Ju$!@vd3F4p1T=&}+P^5yc(m4PkPs)k&pi!%0_=3l@ew2OWpO%mn3>)!2gD@ET#-)=ja7&z8.X(mmc;2W^DU$Dh&,%[Eg8@me/M%P5&n%#;V`2K09D&::Mk*>#J`%v-U5^QqBw%x>+>)OQ58&X9$A$%:8>`>'$&^+q;O)Qu<9*>ov7^*Kzf&)mFB!<`=a$kR,1#4TV**-S^e$Gj[{`1d7Q*n&y44}J;<%e-{~(QyL-&&)3b`8s/0@D*384rgp9*hflq1m2tA!kdB)5r-Xt3xFsw!AGu+!|yC-&ymct^^qEc(iX,s*pd&H$%hLq^a+c^('n+M$G$W4%!S;+@FWuq(*j{S4f9o>47=~d1,GDL2y*m=2]}6u&S4>,@a=p~@9MPu*a0!5%wKw[1yF>^@a}NJ!E%Dl4&qog4#FF.(6a&a$bS)a@~JM>%etMw4_Kqc#$h-R!QPxc!60Fy2IAaS%,1uJ@=>j93*v$=)'!U'4A;Lu@n@-m)J.Tw!v2aV`S9s/)]']=2F%V`&mSXg^qQt;3Xj/L(#SD0@}#5u$Go[C$=(Pz3QCzP#B;d;@:Ks}3bMwJ&#}!S1yKEx4.jJM)C29%&0_v@5&2Ss*~NA^2(1!w$]*WU4zKEM&DNCO2:a*u^VA@y#WzL^^hOmA&SNi*^=rj/$7G._3j5B9&`qMa1So!C*/g0{*orq<%W|L,4t`>V%Es,85hrN,&@U>/2RSD`1u3_7^2<2+&5mS@!:i'L1Hr7n%Tw6O%>'dm$.q-y)MP[]2,`Xk4J=%:$)|i7$*F3K1TgU|!immw#5XRM#9/iJ&a)Lq^$N5/)RFz/&`k2N%eeXR%!-)L`&_T%%%<w2*n|_8(aI0'37?'E(5X(.!e*@?^E)R6@JxkL#D_VN#M[y/%d<o/@9u#k3_KD,`E~U(%k_Lh(Fql_*yIMo&N(1M%BwfW2Ai6b$CB@q!{/%T^,NU75=qjD4_^=35GOk&).'U^)^OnF`7z(v$j%@y`NOXG2s5,L*tdcd&4f855o{ux^xx@~()`jU$C5y7%zv&A2Lh!x2A2>k!X>p[#MW@,^-OQU^qa1_$@5>u%`$rR@CHo=`+(^~(Fa<B35o~N@:s]s@p7V7#5-=M3Hx-p$30`83sX7y3.pFf1{-5;4vkNl(@:<q4CvcW%FR,M%S@do2sK$G2~tcy*Kz,B)Evcd`;3$3`y2N*!`-0b4_)iC#.8O=*y^e;(jJeB@ms334RL&%%WLfV2z}-d&&qWP@9_@@3wur|%76~n#O,6q4x]!b1>z7H1#kJ-^Hw=M#$P'H!UsS'29fW5^1:F5#gSSF$=q/d)66*:!n$hC33bW*3A*6l3o6;j%H`ge^>%}Q3#TI+*_lH8&zqD2!'6Wh#<q}F4^3hP%c`u7*W`cW`8N=R!p;Ju3Ts4?405.l^?&i33I8$n#g8Ho((hu93zO+D`]+wi2S*np1!z1r&*=j;!0y/4(@$zN%}~643Ie$31ec>#('i1o^U2<B4w|Io(Jm#d^m_Aa$@_V=&a#L0@<B#G&gfP[4LP^32=nvc`o#(Q@{FF&4K.iI*#na[#Qd#q(vqKX&,NM#5Qc&$59}eN)rs.m$F6x5%Ch~&1@3zy3Maze4)2R>!mFmC)k]N-)QzFb)`.?>3VDT?2M%3&1FFnq(er/Q%odof1f6$c`:G@/@v:dG#})WJ(jTzQ(DEOP(t]OO&:CkB#R>8_`ykqS*jEXK(Q:`*^SiA1^l()1$)1r5%y<-+3na#K3L%hF1:HJ;1&f(g1FP6*#h,zs$zc%$&((d[@:q4>34/AG!5^#>2+9HF*)9!t*vU=l@A>qV)&=dg@v#n0^ty'9@(DED`(X8B4~;*3*V;k~`!Wz1$`~e^2g.U4`tt~!5A[X')]5Pf@S0Hh(QQ_S!_vJ_@U)9n2F![E(aQ~W(@Gy4&wre&!'psS3P;_e&OVQ<&fp%_#P(!'`sf<q1M%;o^BXG'`wH<5(78(]%H7VH`0dk_&-g57@hK1`5%2w92MX3f)X=$v^kI(M*G#D+4[L<K)rUuS%T|$R3>S3p19JuN&fE?C`U@!{2=E,3)B`eL(G[hx(0FAp^d^B&1cB]A&(!wG&bhz=3fU_j44e*n4a/[626OsH2`EpW&!hM92e@8$1#O[@#H]^u3LWPt&$W*m1q-p/(2wM`#DoQ44LF^r)8hg8!.176%W.BB$E5[F14x<($^vv&1[qL)2v|[21y,I9&,Lqg*[]T@3Kok|3Tw'H@i-:91}jba!,aei`WfA-(aF5_#X%/]1v-(E!RVmg2hm+_%-l)&!18TF1>S~82MSz:%~84M`sG,f)'CrO^P1/P*1CP#&@f6p#5x~)5SP~i%5!Ff3_l-F1=QD15T@&q@R8,B4:K]f^fc%x4JB3a&T8D[@=>N0@,u=+@/l9I&tX@o%HWrh4zXPn^C|l}2p^x>$}y.*(e_gQ*%<5u2b>m2^QH3D(~*']&coAS)4Eaw%cGQ9)LO$m2y1_((B/M4`]-1X2$J$}^kuU3@>):95z3.R1|$R&3!2O[!kHVj@hU03(+/^})v?WU#?$om(!]*X@iIQF!b@~f2r=g-10b2z(|;ij)UWE**sG6?#f@f)@WM^v!JuCp%Su#_`VqR11']$)#i!C~4;T|~!]G><1=Sa~&k9qI^wX*&3Q(@t2/BGL$B0h0#XR%U2qm`'1?uCU%HPIq@&/w')bq2127a/K&iC.%*_byH`6=&N`W[B%4a6x^3(@Si#/q4M`1$f~`d=_B`{))%${-RC*{i^k2gwK,#c`FW![o@k3W.6C@4$Wm`}naS(uEWj^Mk^A`/)56!aHbJ@pn&:3>;55`o_Gy1xk(}&iE/{%Ef%A4zUrC*w~Kk(iC*P!?;|P3[Ezx`HK~8^!]t+*&a>44ch:P4sXiR!iCQI^~)9M!pV%7528*7)-4@>(lC4F#NKW%50Wb^5:Ji25QNW!(S,IS)m8T'&0Ftj^1.G(*x/|!!KA<e)#AW,!{)1M`UdjV#Ien7(]b]8@z1U>*qNP&47LR22>#w[&[&@X@;jz,&jI6w*E@)%#WG&r1frp_`esD?3bkv~)3}RC)EMV]&||.x!__>t#P*f45J4t]*R[=u&T^EP^-c243!5mR@zstP4LfHn#L!_{!?#cp*yuW,(puU|4nRQ.%;xz04#w:23rHVF1XLc5!oR]04d]A62w1wo*./3w*fNNx!rTt1#Qume(,a1C*r-CD@t-89&o0@m$ubmg#%99h`F|p#`DBtl$=7^r3M?OG&l[Qr(ELSo3DoOP(&$pp!{^fM%c7b7^)P1[$d*4,&k)a2(56B#3;i]u&to[<^]R`A%1,}S2<%M,@}U;{@{d|6^-Vl'(+PAD@S~E($j(y)`GU[@5k.:d%B*:9*f]qH`s_9)!6tT?!W=2c@!J5<@GMq`3lOf(&5j0?&4z@W$7RfN%A>VC`$x0D2aSUP3yI<{1D3r3(n-9|)5hb$@V(n)*4f4n2M>?+%5qCO(xxAJ%@z>9(M-(83G5$}(#(M>)HtUS!c3H'^WLcH)&&sB!;d.U%S0E%@QaAu34fLs1.*FU4MuMy^|dV$$[kHS*'97@)LQX[`[BGv(gK=n!L:R(^#~KJ&af4X`y#e%@2opI(6hoQ1.Gm;&Q^@X&hb;~);MVs#}93_1{k&Q^JRE1$)jy.)40$'2^-)#2;AH<`3Ery%vRod`[PhV^3qS4!xfh83p'Wy*/l{R$O42N@4U~g$C#yW!I>4%*},D}$$(d/`+r:q1}y`p109EU@bLL+)Gh*g#]tHS2SbmC)y{T[(-BT@3Jzw;@hGb<(GVXk(`4Mi3!F&l)y(*656D-u(un(v2s*tV(f3U8)<jCs(5ArB(EU1=4>A2h1Fj~k$hA}n&9q,^)/3hT!G:]N*c&6c2U?{a4)c^D@`|Vw(_D{S4']!n4W(@E%+u2f@]Ayp$~R^;*L[5_%1N~0@-P>l4!24`%Ra,H2RK$&$`bxr@yh5A%[pl,#74<*`)Ach&a7SE)BHa82+5MT&(#c7(<B?%`F5bI2w)}t3t!6P$M9J-*vlaW`ag{u3*u'`&.Svp^/|_M#b=*y![Mt2(2{@n&MD-V2Q_VE#kjO43$nX!%(e)h(/~.P!_PrE*o;wC1p_BC&CTmB!}f?p!;2s9$&I3]$bJyH%3r{u^W3tL27~s5&.U+V1JGpi3!.Ab@Rh?r%,+W`1KygJ3!hrg2S>F15_pG`2aLu]1$%9b!h0de)oV8'`{~<421e#=@1iP[1`x.v4SyGO&.B:R)xw/T!p;2j40xa.*}53v(,Sx[`|4f1%$!,`4jh6.(_'jg&)<ys^wz>k^fAd-*gn1x^qL_+196u(#Q2Ng%#a/I%EG<n3x_g31U6O#%SSSQ*[dB413`l?^W8`?!S/pF4n9Mv(xdvv(5lW:(FCQ0^SyNd$8&a-4,5852sd<l%Q!0#4S@]844:2v4$lkn$xa^E1uwSv%aTh=1eg<X#!!!!!!!!!!";
#define S 320000
bool np[S]; int ps[S],pn;
const int MOD=1e9+7;
char mb[]="!@#$%^&*()`1234567890~-=_+{}[]|:;'.,/?><abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string enc(int x){
string s;
for(int i=0;i<5;++i)
s.pb(mb[x%90]),x/=90;
return s;
}
int dec(string s){
static int fyy[233];
if(!fyy['a'])
for(int i=0;i<90;++i)
fyy[mb[i]]=i;
int x=0;
for(int i=4;i>=0;--i)
x=x*90+fyy[s[i]];
return x;
}
inline ll qp(register int a,register ll b){
register int x=1;
while(1)
{
if(b&1) x=x*(ll)a%MOD;
b>>=1; if(!b) break;
a=a*(ll)a%MOD;
}
return x;
}
inline ll qp(register int a,register int b){
register int x=1;
while(1)
{
if(b&1) x=x*(ll)a%MOD;
b>>=1; if(!b) break;
a=a*(ll)a%MOD;
}
return x;
}
pii operator + (pii a,pii b){return pii(a.fi*(ll)b.fi%MOD,a.se*(ll)b.se%MOD);}
pii operator - (pii a,pii b){return pii(a.fi*qp(b.fi,MOD-2)%MOD,a.se*qp(b.se,MOD-2)%MOD);}
#define SZ 2333333
namespace Sieve_Small{
#define U 2500001
int ps[U],pn=0,eul[U],qzheul[U];
bool np[U]; pii q[U]; ll po[U];
void shai(){
np[1]=eul[1]=po[1]=1;
for(int i=2;i<U;i++)
{
if(!np[i]) {ps[++pn]=i; eul[i]=i-1; po[i]=qp(i,i-1);}
for(int j=1;j<=pn&&i*ps[j]<U;j++)
{
np[i*ps[j]]=1;
if(i%ps[j])
eul[i*ps[j]]=eul[i]*(ps[j]-1);
else
{
eul[i*ps[j]]=eul[i]*ps[j];
break;
}
}
}
for(int i=1;i<U;i++)
qzheul[i]=(qzheul[i-1]+eul[i])%(MOD-1);
pii c(1,1);
q[0]=q[1]=c;
for(int i=2;i<U;++i)
{
if(!np[i])
c.fi=c.fi*qp(i,i)%MOD;
c.se=c.se*qp(i,eul[i])%MOD; q[i]=c;
}
}
}
typedef unsigned us;
int g[SZ],h[SZ],p[SZ]; us ip[S];
pii shai(int l,int r){
register int*gl=g-l,*hl=h-l,*pl=p-l;
if(r<U) return Sieve_Small::q[r]-Sieve_Small::q[l-1];
for(int i=l;i<=r;++i) gl[i]=hl[i]=i;
for(int i=1;i<=pn;++i)
{
int p=ps[i]; register us gg=ip[i];
if(p*p>r) break;
if(p==2)
{
int j=l/p*p; if(j<l) j+=p;
for(;j<=r;j+=p) gl[j]>>=__builtin_ctz(gl[j]),hl[j]>>=1;
}
else
{
int j=l/p*p; if(j<l) j+=p;
for(;j<=r;j+=p)
{
while(us(gl[j])*gg<us(gl[j]))
gl[j]=us(gl[j])*gg;
hl[j]=us(hl[j])*gg*(p-1);
}
}
}
ll a0=1,a1=1;
for(int i=l;i<=r;++i)
{
if(gl[i]>1)
hl[i]=hl[i]/gl[i]*(gl[i]-1),gl[i]=1,
a1=a1*qp(i,hl[i])%MOD,pl[i]=0;
else pl[i]=hl[i];
if(hl[i]==i-1) a0=a0*qp(i,i)%MOD;
}
for(int i=l;i<=r;++i) gl[i]=i;
for(int i=1;i<=pn;++i)
{
int p=ps[i]; register us gg=ip[i];
if(p*p>r) break;
ll su=0;
if(p==2)
{
int j=l/p*p; if(j<l) j+=p;
for(;j<=r;j+=p)
{
while(!(gl[j]&1)) gl[j]>>=1,su+=pl[j];
}
}
else
{
int j=l/p*p; if(j<l) j+=p;
for(;j<=r;j+=p)
{
if(!gl[j]) throw 123;
while(us(gl[j])*gg<us(gl[j]))
gl[j]=us(gl[j])*gg,su+=pl[j];
}
}
if(su) a1=a1*qp(p,su)%MOD;
}
return pii(a0%MOD,a1%MOD);
}
int N=1e9,P=N/5900;
map<int,pii> rs;
int n,k,m;
pii calc(int p){
if(p<U) return Sieve_Small::q[p];
if(rs.count(p)) return rs[p];
auto R=rs.lower_bound(p);
auto L=R; --L;
if(p-L->fi<R->fi-p)
return rs[p]=L->se+shai(L->fi+1,p);
else return rs[p]=R->se-shai(p+1,R->fi); 
}
struct BetterMap{
ll a[SZ],b[SZ];
ll& operator[] (ll x){
if(x<SZ) return a[x];
return b[n/x];
}
};
namespace Min25_Sieve{
ll calc(ll);
void work();
}
namespace Eul_Sieve{
ll calc(ll);
void work();
}
namespace M1{
void work(){
auto w=calc(n);
ll ans=qp(qp(k,Min25_Sieve::calc(n))*w.fi%MOD,k);
ans=(ans%MOD+MOD)%MOD;
printf("%d\n",int(ans));
}
}
namespace M2{
void work(){
auto w=calc(n);
ll ans=qp(qp(k,Eul_Sieve::calc(n))*w.se%MOD,k);
ans=(ans%MOD+MOD)%MOD;
printf("%d\n",int(ans));
}
}
namespace M3{
BetterMap F;
void work(){
ll cm=1;
for(ll L=1;L<=n;)
{
ll w=n/L,R=n/w;
auto cw=calc(R)-calc(L-1);
ll sb=qp(k,Min25_Sieve::calc(R)+MOD-1-
Min25_Sieve::calc(L-1))*cw.fi%MOD;
cm=cm*qp(sb,w)%MOD; F[R]=cm; L=R+1;
}
ll ans=1;
for(ll L=1;L<=n;)
{
ll w=n/L,R=n/w;
ans=ans*qp(F[w],R-L+1)%MOD;
L=R+1;
}
ans=qp(ans,k);
ans=(ans%MOD+MOD)%MOD;
printf("%d\n",int(ans));
}
}
namespace M4{
BetterMap F;
void work(){
ll cm=1;
for(ll L=1;L<=n;)
{
ll w=n/L,R=n/w;
auto cw=calc(R)-calc(L-1);
ll sb=qp(k,Eul_Sieve::calc(R)+MOD-1-
Eul_Sieve::calc(L-1))*cw.se%MOD;
cm=cm*qp(sb,w)%MOD; F[R]=cm; L=R+1;
}
ll ans=1;
for(ll L=1;L<=n;)
{
ll w=n/L,R=n/w;
ans=ans*qp(F[w],R-L+1)%MOD;
L=R+1;
}
ans=qp(ans,k);
ans=(ans%MOD+MOD)%MOD;
printf("%d\n",int(ans));
}
}
int main(){
N=(N/P+1)*P;
for(int i=2;i<S;++i) if(!np[i])
{
ps[++pn]=i;
us s=i,t=1;
for(int j=1;j<=31;++j)
t*=s,s=s*s;
ip[pn]=t;
for(int j=i+i;j<S;j+=i) np[j]=1;
}
int c=0;
rs[0]=pii(1,1);
rs[2e9]=pii(0,0);
for(int x=P;x<N;x+=P)
rs[x]=mp(dec(tb.substr(c,5)),dec(tb.substr(c+5,5))),c+=10;
scanf("%d%d%d",&n,&k,&m);
Min25_Sieve::work(); Eul_Sieve::work();
Sieve_Small::shai();
if(m>=1) M1::work();
if(m>=2) M2::work();
if(m>=3) M3::work();
if(m>=4) M4::work();
}
#undef S
namespace Eul_Sieve{
const int MOD=1e9+6;
BetterMap F;
ll calc(ll x){
if(x<U) return Sieve_Small::qzheul[x];
auto&u=F[x];
if(u!=-1) return u;
ll ans=x*(x+1)/2%MOD,lst;
for(ll p=2;p<=x;p=lst+1)
{
lst=x/(x/p);
ans-=((lst-p+1)%MOD)*calc(x/p)%MOD;
ans%=MOD;
}
ans=(ans%MOD+MOD)%MOD;
return u=ans;
}
void work(){
memset(&F,-1,sizeof F);
}
}
namespace Min25_Sieve{
ll c1[SZ],b1[SZ],S; int ps[SZ],pn;
const int MOD=1e9+6;
ll calc(ll x){
if(x<=1) return 0;
if(x>S) return ((b1[n/x]-1)%MOD+MOD)%MOD;
return ((c1[x]-1)%MOD+MOD)%MOD;
}
void work(){
S=sqrtl(n);
for(int i=1;i<=S;++i)
{
ll t=(n/i);
b1[i]=t*(t+1)/2%MOD;
c1[i]=i*(ll)(i+1)/2%MOD;
}
for(int i=2;i<=S;++i)
{
if(c1[i]==c1[i-1]) continue;
ll x1=c1[i-1],r=(ll)i*i; ps[++pn]=i;
int u=min((ll)S,n/(i*(ll)i)),uu=min((ll)u,S/i);
for(int j=1;j<=uu;++j)
(b1[j]-=(b1[j*i]-x1)*i)%=MOD;
ll t=n/i;
for(int j=uu+1;j<=u;++j)
(b1[j]-=(c1[t/j]-x1)*i)%=MOD;
for(int j=S;j>=r;--j)
(c1[j]-=(c1[j/i]-x1)*i)%=MOD;
}
}
}

