function [ EngineFC ] = SFCperform( thrust,x,y )
%SFCperform ���ݷ����������������㷢�����ĺ�����
%   ���룺����������Thrust������Ma���߶�H�������������������

% x=Thruststr3;
% y=SFCstr3;
% N=100:-1:81;
% Thrusti=thrust;
% Ni=interp1(x,N,Thrusti,'cubic');
% sfc=interp1(N,y,Ni,'cubic');
sfc=interp1(x,y,thrust,'cubic');
EngineFC=thrust*sfc/3600;

end

