function [Deltp1,Deltp2]=pressureloss_guan(Pfano,L2,bx1,t2j,t2cc,gm2,gm5,de2)
j=1000
for i=1:1:6000
v1=(t2j+273)*287/Pfano
v11=287*(273+t2cc)/(Pfano-j)
vm1=0.5*(v1+v11)
%kc=0.24;
wkc=[0.47,0.46,0.45,0.43,0.4,0.37,0.32,0.28,0.21,0.14,0.07;];%2015.03.30代替excel读取
wke=[1,0.8,0.63,0.48,0.34,0.22,0.12,0.05,0,-0.04,-0.06;];%2015.03.30代替excel读取
xx=0:0.1:1;
%wkc=xlsread('kc.xlsx');
%wke=xlsread('ke.xlsx');
kc=interp1(xx,wkc,bx1);
ke=interp1(xx,wke,bx1);
%ke=0.04;
%dp1=0.5*v1*gm5^2*(2*(v11/v1-1)+0.0065*4*L2*vm1/(de2*v1))+gm2^2*0.5*v1*((1-bx1^2+kc)-(1-bx1^2-ke)*(v11/v1))
dp1=0.5*v1*gm2^2*(2*(v11/v1-1)+0.0065*4*L2*vm1/(de2*v1))+gm5^2*0.5*v1*((1-bx1^2+kc)-(1-bx1^2-ke)*(v11/v1))
if abs(j-dp1)<3
   break;
else 
    j=dp1;
end
if j>Pfano
    error('外涵压力损失大于进口总压');
end
end
Deltp1=dp1;
