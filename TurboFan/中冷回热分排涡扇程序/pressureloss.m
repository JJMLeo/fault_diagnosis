function [Deltp1,Deltp2]=pressureloss(Pboo,Re1,de1,L1,gm1,sim1,t1j,t1cc,Pfano,Re2,de2,L2,gm2,sim2,t2j,t2cc)
j=1000;
for i=1:1:15000
v1=(t1j+273)*287/Pboo
v11=287*(273+t1cc)/(Pboo-j)
vm1=0.5*(v1+v11)
k1=0.53;
k11=0.44;
f1=0.021*((Re1/1000)^-0.25)
f2=4*0.021*((Re1/1000)^-0.25)*L1/de1*vm1/v1
f3=(1-sim1^2+k1)+2*(v11/v1-1)+4*0.021*((Re1/1000)^-0.25)*L1/de1*vm1/v1-(1-sim1^2-k11)*v11/v1
dp1=gm1^2*v1*0.5*((1-sim1^2+k1)+2*(v11/v1-1)+4*0.021*((Re1/1000)^-0.25)*L1/de1*vm1/v1-(1-sim1^2-k11)*v11/v1)
if abs(j-dp1)<3
    break;
else 
    j=dp1;
end
if j>Pboo
    error('增压级压力损失大于进口总压');
end
end
Deltp1=dp1;

% j=1000
% for i=1:1:6000
% v2=(t2j+273)*287/Pfano
% v22=287*(273+t2cc)/(Pfano-j)
% vm2=0.5*(v2+v2)
% k2=0.5;
% k22=0.18;
% f2=0.021*((Re2/1000)^-0.25)
% dp2=gm2^2*v2*0.5*((1-sim2^2+k2)+2*(v22/v2-1)+4*0.021*((Re2/1000)^-0.25)*L2/de2*vm2/v2-(1-sim2^2-k22)*v22/v2)%20146.5
% if abs(j-dp2)<3
%     break;
% else 
%     j=dp2;
% end
% if j>Pfano
%     error('外涵压力损失大于进口总压');
% end
% end
% Deltp2=dp2;
