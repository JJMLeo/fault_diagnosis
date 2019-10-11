function [ EngineFC ] = SFCperform( thrust,x,y )
%SFCperform 根据发动机所需推力计算发动机的耗油率
%   输入：发动机推力Thrust，飞行Ma，高度H，输出：发动机耗油量

% x=Thruststr3;
% y=SFCstr3;
% N=100:-1:81;
% Thrusti=thrust;
% Ni=interp1(x,N,Thrusti,'cubic');
% sfc=interp1(N,y,Ni,'cubic');
sfc=interp1(x,y,thrust,'cubic');
EngineFC=thrust*sfc/3600;

end

