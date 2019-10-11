function [Tltoi,Tcomoi,Deltp3,Deltp4,mass3,mass4,youxd3,youxd4,zyxd2]=repucator_guannew(Tcomo,Tlto,Pcomo,Plto,Wcomp,Wlto,BPR)
if Tlto<Tcomo
     error('低压涡轮出口温度小于压气机出口温度,无法换热');
end;
%尺寸假设
n1=20;n2=45;n3=100;S1=0.015;S2=0.01;S3=0.004;
sk=0.0001;di=0.0071;do=0.008;
%插值需要
s1d=S1/do;s2d=S2/do;%注意大小
%长度
L1=S1*n1;
L2=S2*n2;
L3=S3*n3;
%管内总传热面积
An1=pi*di*n1*n2*L3;
%管内最小自由流动面积
An2=(pi*n1*n2*di^2)/4;
%管外总传热面积
Ap=pi*do*(L3-sk*n3)*n1*n2+2*(L1*L2-pi*do^2*n1*n2/4);
Af=2*(L1*L2-(pi*do^2/4)*n1*n2)*(n3-1)+2*L1*sk*n3;
Aw1=Ap+Af;
%管外最小流动面积
Aw2=((S1-do)*L3-(S1-do)*sk*n3)*n1;
%水力直径
de1=di;
de2=4*Aw2*L2/Aw1;  %有待检验
%比例系数
bx1=(L3-(n3*sk))*L1/(L3*L1);
DC2=[3.07050000000000e-05,3.14300000000000e-05,3.21470000000000e-05,3.28560000000000e-05,3.35580000000000e-05,3.42540000000000e-05,3.49430000000000e-05,3.56250000000000e-05,3.63010000000000e-05,3.69720000000000e-05,3.76370000000000e-05,3.82960000000000e-05,3.89500000000000e-05,3.95990000000000e-05,4.02430000000000e-05,4.08820000000000e-05,4.15160000000000e-05,4.21460000000000e-05,4.27720000000000e-05,4.33930000000000e-05,4.40100000000000e-05,4.46230000000000e-05,4.52320000000000e-05,4.58380000000000e-05,4.64390000000000e-05,4.70370000000000e-05;];
RC2=[0.240000000000000,0.245700000000000,0.251200000000000,0.256800000000000,0.262200000000000,0.267700000000000,0.273000000000000,0.278300000000000,0.283600000000000,0.288800000000000,0.294000000000000,0.299200000000000,0.304300000000000,0.309300000000000,0.314300000000000,0.319300000000000,0.324300000000000,0.329200000000000,0.334100000000000,0.338900000000000,0.343700000000000,0.348500000000000,0.353300000000000,0.358000000000000,0.362700000000000,0.367300000000000;];
%假设有效度
yia=0.6;
t1j=0.6*abs(Tlto-Tcomo);
for j=1:1:100
    if j>100
        error('无法收敛')
    end;
t2j=Tcomo-273;
qm1=80*An2;qm2=Wcomp/8; %需要更改
t1c=t1j-yia*(1.006*qm2)/(5.198*qm1)*(t1j-t2j);
t2c=t2j+yia*(t1j-t2j);
%冷侧算术平均温度
tm2=(t2j+t2c)/2;
Dtm=((t1j-t2c)-(t1c-t2j))/log((t1j-t2c)/(t1c-t2j));
%热侧算术平均温度
tm1=tm2+Dtm
for i=1:1:6
    if i>6
        error('中冷器效率计算不收敛');
    end;
%冷热空气物性参数
mu2=1.50619*0.000001*(273+tm2)^1.5/(tm2+395);  %粘性系数，动力粘度[pa.s]
nam2=2.456*0.001*0.1*(tm2+273)^0.823;  %热导率[w/(m.k)]
cp1=5198;cp2=1003+0.02*tm2+4*0.001*0.1*tm2^2; %定压热容[j/(kg.k)]
Pr1=0.6630;Pr2=0.6813;  %普朗特数
xo=300:20:800;
if tm1>=300&tm1<=800
%DC2=xlsread('wudong1.xlsx');%非设计点插值范围变大
%RC2=xlsread('wudao1.xlsx');
mu1=interp1(xo,DC2,tm1);
nam1=interp1(xo,RC2,tm1);
else if tm1<300
    mu1=3.071e-5;
    nam1=0.24;
else
    mu1=4.704e-5;
    nam1=0.3673;
    end
end
%质量流速
gm1=qm1/An2;
gm2=qm2/Aw2;
gm5=qm2/((L3-(n3*sk))*L1)
%雷诺数
Re1=gm1*de1/mu1;
Re2=gm2*de2/mu2
%传热系数
if Re1>2200
    Nu1=0.023*Re1^0.8*Pr1^0.3
else
    Nu1=1.86*(Re1*Pr1*(di/L3))^(1/3)
end
%xi1=[1.25 1.5 2 3];
%yi1=[1.25 1.5 2 3];
%ci1=xlsread('nuc.xlsx');
%cic=interp2(xi1,yi1,ci1,s1d,s2d)
%xi2=[1.25 1.5 2 3];
%yi2=[1.25 1.5 2 3];
%ci2=xlsread('nun.xlsx')
%cin=interp2(xi2,yi2,ci2,s1d,s2d)
cic=0.1595;
cin=0.68;
Nu2=cic*Re2^cin*Pr2^(1/3)
arf1=Nu1*nam1/de1
arf2=Nu2*nam2/de2
%翅片效率  翅片材料的热导率为190
m2=(2*arf2/(190*sk))^0.5;
r=(S1+S2)/(2*sqrt(pi));
le=r-do/2+sk/2;
R=2*r/do;  %????
if R>2
    b=0.9706+0.17125*log(R);
else
    b=0.9107+0.0893*R;
end
N=exp(0.13*m2*le-1.3863);
z=m2*le*R^N;
a=R^(-0.246);
A=0.6+2.257*R^(-0.445);
if z>A
    yf2=a*(m2*le)^(-b);
else
    yf2=tanh(z)/z;
end
%总体传热面效率
yz02=1-(1-yf2)*(Af/Aw1);
%传热壁热阻 总热导
Rw=log(do/di)/(2*pi*190*L3*n1*n2);
UA=1/(arf1*An1)+Rw+1/(yz02*Aw1*arf2);
KA=1/UA;
%传热单元数
W1=qm1*cp1;
W2=qm2*cp2;
Wmin=min(W1,W2);
Wmax=max(W1,W2);
C=Wmin/Wmax
NTU=KA/Wmin
%yib=1-exp(C*NTU^0.2*(exp(-C*NTU^0.78)-1))%有问题%%%
yib=1-exp((NTU^0.22/C)*(exp(-C*NTU^0.78)-1))
ytz=yib*0.998%有待改进
%换热量
Q1=ytz*Wmin*(t1j-t2j)
t1cc=t1j-Q1/W1;
t2cc=t2j+Q1/W2
if abs(t1cc-t1c)<0.5&abs(t2cc-t2c)<0.5;
    break;
else
    tm1=0.5*(t1cc+t1j);
    tm2=0.5*(t2cc+t2j);
end
t1c=t1cc;
t2c=t2cc;
end
%尺寸假设
n4=18;n5=35;n6=160;S4=0.024;S5=0.008;S6=0.0045;
sk1=0.0001;di=0.0071;do=0.008;
%插值需要
s4d=S4/do;s5d=S5/do;%注意大小
%长度
L4=S4*n4;
L5=S5*n5;
L6=S6*n6;
%管内总传热面积
ANZ=pi*di*n4*n5*L6;
%管内最小自由流动面积
AnL=(pi*n4*n5*di^2)/4;
%管外总传热面积
Ap2=pi*do*(L6-sk1*n6)*n4*n5+2*(L4*L5-pi*do^2*n4*n5/4);
Af2=2*(L4*L5-(pi*do^2/4)*n4*n5)*(n6-1)+2*L4*sk1*n6;
Awz=Ap2+Af2;
%管外最小流动面积
AwL=((S4-do)*L6-(S4-do)*sk1*n6)*n4;
%水力直径
de4=di;
de3=4*AwL*L5/Awz;  %有待检验
%比例系数
bx2=(L6-(n6*sk))*L4/(L6*L4)
%假设有效度
yia1=0.6;
t3j=Tlto-273;t4j=t1c;
qm4=qm1;qm3=Wlto/8; %需要更改
t3c=t3j-yia1*(1.006*qm3)/(5.198*qm4)*(t3j-t4j);
t4c=t4j+yia1*(t3j-t4j);
%冷侧算术平均温度
tm4=(t4j+t4c)/2;
Dtm1=((t3j-t4c)-(t3c-t4j))/log((t3j-t4c)/(t3c-t4j));
%热侧算术平均温度
tm3=tm4+Dtm1;
for i=1:1:6
    if i>6
        error('中冷器效率计算不收敛');
    end;
%冷热空气物性参数
mu3=1.50619*0.000001*(273+tm3)^1.5/(tm3+395);  %粘性系数，动力粘度[pa.s]
nam3=2.456*0.001*0.1*(tm3+273)^0.823;  %热导率[w/(m.k)]
cp4=5198;cp3=1003+0.02*tm3+4*0.001*0.1*tm3^2; %定压热容[j/(kg.k)]
Pr4=0.6630;Pr3=0.6813;  %普朗特数
xo=300:20:800;
if tm4>=300&tm4<=800
%DC2=xlsread('wudong1.xlsx');%非设计点插值范围变大
%RC2=xlsread('wudao1.xlsx');
mu4=interp1(xo,DC2,tm4);
nam4=interp1(xo,RC2,tm4);
else if tm4<300
    mu4=3.071e-5;
    nam4=0.24;
else
    mu4=4.704e-5;
    nam4=0.3673;
    end 
end
%质量流速
gm4=qm4/AnL;
gm3=qm3/AwL;
gm6=qm3/((L6-(n6*sk))*L4)
%雷诺数
Re4=gm4*de4/mu4;
Re3=gm3*de3/mu3
%传热系数
if Re4>2200
    Nu4=0.023*Re4^0.8*Pr4^0.4;
else
    Nu4=1.86*(Re4*Pr4*(di/L6))^(1/3);
end
%xi1=[1.25 1.5 2 3];
%yi1=[1.25 1.5 2 3];
%ci1=xlsread('nuc.xlsx');
%cpp=interp2(xi1,yi1,ci1,s4d,s5d)
%xi2=[1.25 1.5 2 3];
%yi2=[1.25 1.5 2 3];
%ci2=xlsread('nun.xlsx')
%cqq=interp2(xi2,yi2,ci2,s4d,s5d)\
cpp=0.0703;
cqq=0.7520;
Nu3=cpp*Re3^cqq*Pr3^(1/3)
arf4=Nu4*nam4/de4
arf3=Nu3*nam3/de3
%翅片效率  翅片材料的热导率为190
mm=(2*arf3/(190*sk1))^0.5;
rL=(S4+S5)/(2*sqrt(pi));
le2=rL-do/2+sk1/2;
DR=2*rL/do;  %????
if DR>2
    b2=0.9706+0.17125*log(DR);
else
    b2=0.9107+0.0893*DR;
end
DN=exp(0.13*mm*le2-1.3863);
Dz=mm*le2*DR^DN;
Da=DR^(-0.246);
A2=0.6+2.257*DR^(-0.445);
if Dz>A2
    Syf2=Da*(mm*le2)^(-b2);
else
    Syf2=tanh(Dz)/Dz;
end
%总体传热面效率
Syz02=1-(1-Syf2)*(Af2/Awz);
%传热壁热阻 总热导
Rw2=log(do/di)/(2*pi*190*L6*n4*n5);
UA2=1/(arf4*ANZ)+Rw2+1/(Syz02*Awz*arf3);
KA2=1/UA2;
%传热单元数
W4=qm4*cp4
W3=qm3*cp3
Wmin1=min(W4,W3);
Wmax1=max(W4,W3);
C2=Wmin1/Wmax1
NTU2=KA2/Wmin1
%yib2=1-exp(C2*NTU2^0.2*(exp(-C2*NTU2^0.78)-1))%有问题%%%
yib2=1-exp((NTU2^0.22/C2)*(exp(-C2*NTU2^0.78)-1))
ytz2=yib2*0.998 %有待改进
%换热量
Q2=ytz2*Wmin1*(t3j-t4j)
t3cc=t3j-Q2/W3;
t4cc=t4j+Q2/W4;
if abs(t3cc-t3c)<0.5&abs(t4cc-t4c)<0.5;
    break;
else
    tm3=0.5*(t3cc+t3j);
    tm4=0.5*(t4cc+t4j);
end
t3c=t3cc;
t4c=t4cc;
end
xx=abs(t1j-t4c);
if xx<=0.5
    break;
else
    t1j=t4c;
end
end
Tltoi=t3cc+273;
Tcomoi=t2cc+273;
zyxd2=(t2cc-t2j)/(t3j-t2j);
youxd3=ytz;
youxd4=ytz2;
[Deltp3,Deltp4]=pressureloss_guan2(Pcomo,L2,bx1,t2j,t2cc,gm2,gm5,de2,Plto,L5,bx2,t3j,t3cc,gm3,gm6,de3);
%重量计算  
volu3=((L1*L2-n1*n2*pi*(do/2)^2)*(n3-1)+L1*L2*2)*sk+n1*n2*L3*pi*((do/2)^2-(di/2)^2);
mass3=7750*volu3;
volu4=((L4*L5-n4*n5*pi*(do/2)^2)*(n6-1)+L4*L5*2)*sk1+n4*n5*L6*pi*((do/2)^2-(di/2)^2);
mass4=7750*volu4;




















