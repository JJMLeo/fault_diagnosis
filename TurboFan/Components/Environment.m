function [Pamb,Tamb,C]=Environment(H)
%input:high
%output:[pressure£¬temperature£¬local speed of sound]
%ENVIROUT Summary of this function goes here
%Detailed explanation goes here
if H<=11000
    Tamb=288.15-0.0065*H;
    Pamb=101325.0*(1-H/44308.)^5.2533;
else
    Tamb=216.65;
    Pamb=22615*exp((11000-H)/6318);
end
[~,k,R]=gasstate(Tamb,0,1,1);
%µ±µØÒôËÙ
C=sqrt(k*R*Tamb);
