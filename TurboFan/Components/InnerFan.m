function [Pt_out,Tt_out,h_out,W_out,FanWork]=InnerFan(Pt_in,Tt_in,GTR,N1,Z_Fan,DesignResult_InFan)
%设计点内风扇进口总压、总温与物理流量
Tt_ind=DesignResult_InFan(4);
%油气比
f=0;
%换算因子
Theta =(Tt_in/Tt_ind)^0.5;

%换算转速
N1cor=GTR*N1/Theta;
[InFan_PR,InFan_Wcor,InFan_Eff]=FanMap_Interp(N1cor,Z_Fan,DesignResult_InFan);

%内风扇进口单位气流焓与熵
h_in=gashi(Tt_in,f);

%内风扇出口总压
Pt_out=Pt_in*InFan_PR;

%内风扇出口总温
Tt_out=GasTt(Tt_in,f,InFan_PR,InFan_Eff);

%内风扇出口单位气流实际焓
h_out=gashi(Tt_out,f);

%内风扇出口物理流量
W_out=InFan_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%内风扇功
FanWork=W_out*(h_out-h_in);
