function [Tltoi,Tcomoi,Deltp3,Deltp4,ytz,mcore2,L1,L2,L3]=repucator(Tcomo,Tlto,Pcomo,Plto,Wcomp,Wlto,BPR)
if Tlto<Tcomo
     error('低压涡轮出口温度小于压气机出口温度,无法换热');
end;
%假设效率
yita=0.6;
k=0.001;
t1j=Tlto-273;t2j=Tcomo-273;
qm1=Wcomp/8;qm2=Wlto/8;
%预备计算
t1c=t1j-yita*(t1j-t2j)
t2c=t2j+(qm1/qm2)*(t1j-t1c)
C=(qm1/qm2);
%热侧平均温度
tm1=(t1j+t1c)/2;
%对数平均温差
%Dtm=((t1j-t2c)-(t1c-t2j))/log((t1j-t2c)/(t1c-t2j));
%Dtm=t1j-t2c;
%冷侧平均温度
tm2=(t2j+t2c)/2;
for i=1:1:500 
%冷热空气物性参数
    if i>500
        error('回热器效率计算不收敛');
    end;
mu1=1.50619*k*k*(273+tm1)^1.5/(tm1+395);mu2=1.50619*k*k*(273+tm2)^1.5/(tm2+395);
nam1=2.456*k*0.1*(tm1+273)^0.823;nam2=2.456*k*0.1*(tm2+273)^0.823;
cp1=1003+0.02*tm1+4*k*0.1*tm1^2;cp2=1003+0.02*tm2+4*k*0.1*tm2^2;
Pr1=0.6813;Pr2=0.6977;
%翅片层数
N1=70;N2=71;
%流体流动长度
k=0.001;
L1=100*k;L2=800*k;
%翅片间距
sf1=1.5*k;sf2=1.5*k;
%板间距 隔板厚度0.5 翅片厚度0.15 侧板厚度2 封条宽度6
s1=7.5*k;s2=7.5*k;
%非流动方向长度
L3=N1*(s1+1*k)+N2*s2+4*k;
%翅片高
h1=0.5*s1;
h2=0.5*s2;
%流道当量直径
de1=2*(sf1*s1-2*h1*0.15*k)/(sf1+2*h1);
de2=2*(sf2*s2-2*h2*0.15*k)/(sf2+2*h2);
%翅片面积比
fai1=2*h1/(sf1-0.15+2*h1);
fai2=2*h2/(sf2-0.15+2*h2);
%传热面积密度
beta1=(2*(sf1-0.15)+4*h1)/(s1*sf1);
beta2=(2*(sf2-0.15)+4*h2)/(s2*sf2);
%空气流通面积 
Ac1=N1*(L2-2*6*k)*(s1-2*h1*0.15*k/sf1);
Ac2=N2*(L1-2*6*k)*(s2-2*h2*0.15*k/sf2);
%空气迎风面积
Ay1=(L2-2*6*k)*(L3-2*2*k);
Ay2=(L1-2*6*k)*(L3-2*2*k);
%热侧孔度
sim1=Ac1/Ay1
sim2=Ac2/Ay2
%一次传热面积
Ap=2*N1*(L1-2*6*k)*(L2-2*6*k);
%二次传热面积
Af1=N1*((L2-2*6*k)/sf1)*2*h1*L1*2;
Af2=N2*((L2-2*6*k)/sf2)*2*h2*L2*2;
%质量流速
gm1=qm1/Ac1
gm2=qm2/Ac2
%雷诺数
Re1=gm1*de1/mu1
Re2=gm2*de2/mu2
%传热系数
if Re1>2200&Re1<10000
    Nu1=0.06*Re1^(2/3)
else
    Nu1=0.023*Re1^0.8*Pr1^0.3
end
if Re2>2200&Re2<10000
    Nu2=0.06*Re2^(2/3)
else
    Nu2=0.023*Re2^0.8*Pr2^0.4
end
arf1=Nu1*nam1/de1
arf2=Nu2*nam2/de2
%翅片参数 铝板 导热系数190
m1=(2*arf1/(190*0.15*k))^0.5;
m2=(2*arf2/(190*0.15*k))^0.5;
mh1=m1*h1;
mh2=m2*h2;
yf1=tanh(mh1)/mh1;
yf2=tanh(mh2)/mh2;
%有效传热面积
Aef1=Ap+yf1*Af1;
Aef2=Ap+yf2*Af2;
%两侧总传热面积
A1=Ap+Af1;
A2=Ap+Af2;
%两侧表面效率
y01=1-(Af1/A1)*(1-yf1);
y02=1-(Af2/A2)*(1-yf2);
%壁面热阻和总传热系数
Rw=0.0005/(190*Ap);
DKA=1/(y01*arf1*A1)+Rw+1/(y02*arf2*A2);
KA=1/DKA;
K1=KA/A1;
%传热单元数 换热器效率 出口流体温度
W1=qm1*cp1;
W2=qm2*cp2;
Wmin=min(W1,W2);
Wmax=max(W1,W2);
C=Wmin/Wmax
NTU=KA/W1
yi=1-exp((NTU^0.22/C)*(exp(-C*NTU^0.78)-1))
ytz=yi*0.998
Q=ytz*Wmin*(t1j-t2j);
t1cc=t1j-Q/W1
t2cc=t2j+Q/W2
i
if abs(t1cc-t1c)<1&abs(t2cc-t2c)<0.5
    zz1=t1cc-t1c
    zz2=t2cc-t2c
   break;
else
    tm1=0.5*(t1cc+t1j);
    tm2=0.5*(t2cc+t2j);
end
t1c=t1cc
t2c=t2cc
end
Tltoi=t1cc+273;
Tcomoi=t2cc+273;
[Deltp3,Deltp4]=pressureloss2(Plto,Re1,de1,L1,gm1,sim1,t1j,t1cc,Pcomo,Re2,de2,L2,gm2,sim2,t2j,t2cc);

mf1=N1*((L2-2*6*k)/sf1)*sqrt(s1^2+sf1^2)*L1*0.00015*7750;
mf2=N2*((L1-2*6*k)/sf2)*sqrt(s2^2+sf2^2)*L2*0.00015*7750;
mps=(N1*0.0005+2*0.002)*L1*L2*7750;
ms1=2*N1*L1*6*k*s1*7750;
ms2=2*N2*L2*6*k*s2*7750;
mcore2=mf1+mf2+mps+ms1+ms2;
%fid = fopen('shiyanshuju1.txt','at+');
%fprintf(fid,'回热器：效率=%5.2f   涡轮压降=%5.2f   压气机压降=%5.2f\r\n',ytz,Deltp3,Deltp4);
%fprintf(fid,'回热器：效率=%5.2f   长=%5.2f   宽=%5.2f   高=%5.2f N1=%5.2f   N2=%5.2f      重量=%5.2f\r\n',ytz,L1,L2,L3,N1,N2,mcore1);
%fprintf(fid,'长=%5.2f   宽=%5.2f   高=%5.2f N1=%5.2f   N2=%5.2f      重量=%5.2f\r\n',L1,L2,L3,N1,N2,mcore2);
%fclose(fid);