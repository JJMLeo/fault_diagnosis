function [Pt_out_OutFan,Tt_out_OutFan,W_out_OutFan,Pt_out_InFan,Tt_out_InFan,W_out_InFan,FanWork]=Fan(Pt_in,Tt_in,GTR,NL,Z_Fan,BPR,DesignResult_Fan,Fault)
%设计点内风扇进口总压、总温与物理流量
Tt_ind=DesignResult_Fan(6);

%油气比
f=0;

%换算因子
Theta =(Tt_in/Tt_ind)^0.5;

%换算转速
NLcor=GTR*NL/Theta;
[OutFan_PR,OutFan_Eff,InFan_PR,InFan_Eff,Fan_Wcor]=FanMap_Interp(NLcor,Z_Fan,DesignResult_Fan,Fault);

%风扇进口单位气流焓
h_in=gashi(Tt_in,f);

%外风扇出口总压
Pt_out_OutFan=Pt_in*OutFan_PR;

%外风扇出口总温
Tt_out_OutFan=GasTt(Tt_in,f,OutFan_PR,OutFan_Eff);

%外风扇出口单位气流实际焓
h_out_OutFan=gashi(Tt_out_OutFan,f);

%内风扇出口总压
Pt_out_InFan=Pt_in*InFan_PR;

%内风扇出口总温
Tt_out_InFan=GasTt(Tt_in,f,InFan_PR,InFan_Eff);

%内风扇出口单位气流实际焓
h_out_InFan=gashi(Tt_out_InFan,f);

%风扇出口物理流量
W_out_Fan=Fan_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%外风扇出口物理流量
W_out_OutFan=W_out_Fan*(BPR/(1+BPR));

%内风扇出口物理流量
W_out_InFan=W_out_Fan-W_out_OutFan;

%外风扇功
OutFanWork=W_out_OutFan*(h_out_OutFan-h_in);

%内风扇功
InFanWork=W_out_InFan*(h_out_InFan-h_in);

%风扇功
FanWork=OutFanWork+InFanWork;


