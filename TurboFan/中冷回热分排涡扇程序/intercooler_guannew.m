function [Tboo,Tbpoi,Deltp1,Deltp2,mass1,mass2,youxd1,youxd2,zyxd1]=intercooler_guannew(Tfano,Tboo,Pboo,Pfano,Wfano,icper,BPR)
%尺寸假设
n1=20;n2=80;n3=160;S1=0.024;S2=0.01;S3=0.0045;
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
de2=4*Aw2*L2/Aw1 %有待检验
%比例系数
%bx1=Aw2/(L3*L1)
bx1=(L3-(n3*sk))*L1/(L3*L1)
%bx1=Aw2/((L3-(n3*sk))*L1)
%DC=xlsread('wudong.xlsx');
%RC=xlsread('wudao.xlsx');
DC=[1.94600000000000e-05,1.99100000000000e-05,2.03600000000000e-05,2.08000000000000e-05,2.12300000000000e-05,2.16600000000000e-05,2.20900000000000e-05,2.25100000000000e-05,2.29300000000000e-05;];
RC=[0.152700000000000,0.156100000000000,0.156000000000000,0.163000000000000,0.166400000000000,0.169700000000000,0.173000000000000,0.176300000000000,0.178000000000000;];
%假设有效度
yia=0.6;
t1j=0.6*abs(Tboo-Tfano);
for j=1:1:100
    if j>100
        error('无法收敛')
    end;
t2j=Tfano-273;
qm1=80*An2;qm5=Wfano/(BPR+1);qm2=(Wfano-qm5)*icper/6; %需要更改
t1c=t1j-yia*(1.006*qm2)/(5.198*qm1)*(t1j-t2j);
t2c=t2j+yia*(t1j-t2j);
%冷侧算术平均温度
tm2=(t2j+t2c)/2;
Dtm=((t1j-t2c)-(t1c-t2j))/log((t1j-t2c)/(t1c-t2j));
%热侧算术平均温度
tm1=tm2+Dtm;
for i=1:1:6
    if i>6
        error('中冷器效率计算不收敛');
    end;
%冷热空气物性参数
mu2=1.50619*0.000001*(273+tm2)^1.5/(tm2+395);  %粘性系数，动力粘度[pa.s]
nam2=2.456*0.001*0.1*(tm2+273)^0.823;  %热导率[w/(m.k)]
cp1=5198;cp2=1003+0.02*tm2+4*0.001*0.1*tm2^2; %定压热容[j/(kg.k)]
Pr1=0.6630;Pr2=0.6813;  %普朗特数
xo=20:10:100;
%DC=xlsread('wudong.xlsx');
%RC=xlsread('wudao.xlsx');
if tm1<=100&tm1>=20
mu1=interp1(xo,DC,tm1);%粘性系数
nam1=interp1(xo,RC,tm1);%热导率
else if tm1<20
    mu1=1.946e-5;
    nam1=0.1527;
else
    mu1=2.293e-5;
    nam1=0.178;
    end
end
%质量流速
gm1=qm1/An2;
gm2=qm2/Aw2
gm5=qm2/((L3-(n3*sk))*L1)  %y压降需要
%雷诺数
Re1=gm1*de1/mu1;
Re2=gm2*de2/mu2;
%传热系数
if Re1>2200
    Nu1=0.023*Re1^0.8*Pr1^0.3;
else
    Nu1=1.86*(Re1*Pr1*(di/L3))^(1/3);
end
%xi1=[1.25 1.5 2 3];
%yi1=[1.25 1.5 2 3];
%ci1=xlsread('nuc.xlsx');
%cic=interp2(xi1,yi1,ci1,s1d,s2d);
%xi2=[1.25 1.5 2 3];
%yi2=[1.25 1.5 2 3];
%ci2=xlsread('nun.xlsx')
%cin=interp2(xi2,yi2,ci2,s1d,s2d);
cic=0.0703;
cin=0.7520;
Nu2=cic*Re2^cin*Pr2^(1/3);
arf1=Nu1*nam1/de1;
arf2=Nu2*nam2/de2;
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
C=Wmin/Wmax;
NTU=KA/Wmin;
%yib=1-exp(C*NTU^0.2*(exp(-C*NTU^0.78)-1))%有问题%%%
yib=1-exp((NTU^0.22/C)*(exp(-C*NTU^0.78)-1));
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

volu1=((L1*L2-n1*n2*pi*(do/2)^2)*(n3-1)+L1*L2*2)*sk+n1*n2*L3*pi*((do/2)^2-(di/2)^2);
mass1=2730*volu1;
volu2=((L4*L5-n4*n5*pi*(do/2)^2)*(n6-1)+L4*L5*2)*sk1+n4*n5*L6*pi*((do/2)^2-(di/2)^2);
mass2=2730*volu2;





















