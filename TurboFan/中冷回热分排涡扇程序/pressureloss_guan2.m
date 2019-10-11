function [Deltp3,Deltp4]=pressureloss_guan2(Pcomo,L2,bx1,t2j,t2cc,gm2,gm5,de2,Plto,L5,bx2,t3j,t3cc,gm3,gm6,de3)
j=1000;
for i=1:1:5000
v2=(t3j+273)*287/Plto
v22=287*(273+t3cc)/(Plto-j)
vm2=0.5*(v2+v22)
%kc2=0.24;
%ke2=0.04;
wkc=[0.47,0.46,0.45,0.43,0.4,0.37,0.32,0.28,0.21,0.14,0.07;];%2015.03.30代替excel读取
wke=[1,0.8,0.63,0.48,0.34,0.22,0.12,0.05,0,-0.04,-0.06;];%2015.03.30代替excel读取
xx=0:0.1:1;
%wkc=xlsread('kc.xlsx');
%wke=xlsread('ke.xlsx');
kc2=interp1(xx,wkc,bx2)
ke2=interp1(xx,wke,bx2)
%dp2=0.5*v2*gm6^2*(2*(v22/v2-1)+0.0065*4*L5*vm2/(de3*v2))+gm3^2*0.5*v2*((1-bx2^2+kc2)-(1-bx2^2-ke2)*(v22/v2))
%dp4=0.5*v2*gm3^2*(2*(v22/v2-1)+0.008*4*L5*vm2/(de3*v2))+gm6^2*0.5*v2*((1-bx2^2+kc2)-(1-bx2^2-ke2)*(v22/v2))
dp4=0.5*v2*gm3^2*(2*(v22/v2-1)+0.008*4*L5*vm2/(de3*v2))+gm6^2*0.5*v2*((1-bx2^2+kc2)-(1-bx2^2-ke2)*(v22/v2))
if abs(j-dp4)<3
    break;
else 
    j=dp4;
end
if j>Plto
    error('低压涡轮压力损失计算不收敛');
end
end
Deltp4=dp4;

jj=1000
for i=1:1:11000
v1=(t2j+273)*287/Pcomo
v11=287*(273+t2cc)/(Pcomo-jj)
vm1=0.5*(v1+v11)
%kc=0.24;
xx=0:0.1:1;
%wkc=xlsread('kc.xlsx');
%wke=xlsread('ke.xlsx');
kc=interp1(xx,wkc,bx1)
ke=interp1(xx,wke,bx1)
%ke=0.04;
%dp1=0.5*v1*gm5^2*(2*(v11/v1-1)+0.0065*4*L2*vm1/(de2*v1))+gm2^2*0.5*v1*((1-bx1^2+kc)-(1-bx1^2-ke)*(v11/v1))
dp3=0.5*v1*gm2^2*(2*(v11/v1-1)+0.008*4*L2*vm1/(de2*v1))+gm5^2*0.5*v1*((1-bx1^2+kc)-(1-bx1^2-ke)*(v11/v1))
if abs(jj-dp3)<3
   break;
else 
    jj=dp3;
end
if jj>Pcomo
    error('高压压气机压力损失计算不收敛');
end
end
Deltp3=dp3;