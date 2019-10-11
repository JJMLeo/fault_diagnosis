function [Gasdens,Vsonic] = EnvirGas(H )
%�������������� һ���߶��´����ܶȺʹ�������
%��������߶ȣ���������ܶȺ͵�������
%   Detailed explanation goes here

R=286.9;k=1.4;
  
if H<=11000
   T0=288.15-0.0065*H;
    P0=101325.0*(1-H/44308.)^5.2533;
else
   T0=216.5;
    P0=22615*exp((11000-H)/6318);
end
Gasdens= P0/(R*T0)
C0=sqrt(k*R*T0);
Vsonic=C0;
end

