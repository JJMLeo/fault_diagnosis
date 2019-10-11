function [Deltp3,Deltp4]=pressureloss2(Plto,Re1,de1,L1,gm1,sim1,t1j,t1cc,Pcomo,Re2,de2,L2,gm2,sim2,t2j,t2cc)

j=1000;
for i=1:1:5000
v1=(t1j+273)*287/Plto
v11=287*(273+t1cc)/(Plto-j)
vm1=0.5*(v1+v11)
k1=0.5;
k11=0.28;
f1=0.021*((Re1/1000)^-0.25)
f2=4*0.021*((Re1/1000)^-0.25)*L1/de1*vm1/v1
f3=(1-sim1^2+k1)+2*(v11/v1-1)+4*0.021*((Re1/1000)^-0.25)*L1/de1*vm1/v1-(1-sim1^2-k11)*v11/v1
dp3=gm1^2*v1*0.5*((1-sim1^2+k1)+2*(v11/v1-1)+4*0.021*((Re1/1000)^-0.25)*L1/de1*vm1/v1-(1-sim1^2-k11)*v11/v1)
if abs(j-dp3)<3
    break;
else 
    j=dp3;
 fid = fopen('design555.txt','wt+');
 fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',Pcomo,t2cc,Plto,t1cc,dp3);
 fclose(fid); 
end
if j>Plto
    error('低压涡轮压力损失计算不收敛');
end
end
Deltp3=dp3;

j=1000
for i=1:1:11000
v2=(t2j+273)*287/Pcomo
v22=287*(273+t2cc)/(Pcomo-j)
vm2=0.5*(v2+v22)
k2=0.5;
k22=0.28;
f2=0.021*((Re2/1000)^-0.25)
dp4=gm2^2*v2*0.5*((1-sim2^2+k2)+2*(v22/v2-1)+4*0.021*((Re2/1000)^-0.25)*L2/de2*vm2/v2-(1-sim2^2-k22)*v22/v2)
if abs(j-dp4)<3
    break;
else 
    j=dp4;
end
if j>Pcomo
    error('高压压气机压力损失计算不收敛');
end
end
Deltp4=dp4;
