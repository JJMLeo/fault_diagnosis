function [Pt_out,Tt_out,h_out,W_out,FanWork]=OuterFan(Pt_in,Tt_in,GTR,N1,Z_Fan,DesignResult_OutFan)
%设计点外风扇进口总压、总温与物理流量
Tt_ind=DesignResult_OutFan(4);
%油气比
f=0;
%换算因子
Theta =(Tt_in/Tt_ind)^0.5;

%换算转速
N1cor=GTR*N1/Theta;
[OutFan_PR,OutFan_Wcor,OutFan_Eff]=FanMap_Interp(N1cor,Z_Fan,DesignResult_OutFan);

%外风扇进口单位气流焓与熵
h_in=gashi(Tt_in,f);

%外风扇出口总压
Pt_out=Pt_in*OutFan_PR;

%外风扇出口总温
Tt_out=GasTt(Tt_in,f,OutFan_PR,OutFan_Eff);

%外风扇出口单位气流实际焓
h_out=gashi(Tt_out,f);

%外风扇出口物理流量
W_out=OutFan_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%外风扇功
FanWork=W_out*(h_out-h_in);
