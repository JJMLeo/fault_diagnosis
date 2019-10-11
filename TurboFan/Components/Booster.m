function [Pt_out,Tt_out,h_out,W_out,BoosterWork]=Booster(Pt_in,Tt_in,N1,Z_Booster,DesignResult_Booster)
%设计点增压级进口总压、总温与物理流量
Tt_ind=DesignResult_Booster(4);
%油气比
f=0;
%换算因子
Theta =(Tt_in/Tt_ind)^0.5;

%换算转速
N1cor=N1/Theta;
[Booster_PR,Booster_Wcor,Booster_Eff]=BoosterMap_Interp(N1cor,Z_Booster,DesignResult_Booster);

%增压级进口单位气流焓与熵
h_in=gashi(Tt_in,f);

%增压级出口总压
Pt_out=Pt_in

%增压级出口总温
Tt_out=GasTt(Tt_in,f,1,1);

%增压级出口单位气流实际焓
h_out=gashi(Tt_out,f);

%增压级出口物理流量
W_out=Booster_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%增压级功
BoosterWork=0
