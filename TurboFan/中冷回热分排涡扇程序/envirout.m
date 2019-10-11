%function [Ptenvo,Ttenvo] = envirout( H,Ma )
%ENVIROUT Summary of this function goes here
%  Detailed explanation goes here


   R=286.9;k=1.4;
  
if H<=11000
  T0=288.15-0.0065*H;
 
    P0=101325.0*(1-H/44308.)^5.2533;

else
   T0=216.5;
    P0=22615*exp((11000-H)/6318);
end
if f_design == false
    %T0=T0+15;
    T0=T0;
end
C0=sqrt(k*R*T0);
V0=C0*Ma;%�����ٶ�
Ptenvo=P0*(1+(k-1)/2*Ma^2)^(k/(k-1)),%������ѹ
       
Ttenvo=T0*(1+(k-1)/2*Ma^2),%��������
Pev=P0, %����ѹ��  ��ѹ
Tev=T0, %�����¶�  ����

