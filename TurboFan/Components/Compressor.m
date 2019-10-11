function [Pt_out,Tt_out,W_out,ComprWork,Tt_out_Z2,Tt_out_Z3,W_in_Interp]=Compressor(Pt_in,Tt_in,N2,Z_Compr,DesignResult_Compressor,AirPlan,Compr_Def_W,Fault)
%压气机设计点参数
d_Sigma_ComprIn=DesignResult_Compressor(1);
d_Compr_Z1=DesignResult_Compressor(4);
d_Compr_Z2=DesignResult_Compressor(5);
d_Compr_Z3=DesignResult_Compressor(6);
d_Compr_Z=DesignResult_Compressor(7);
%设计点压气机进口总温
Tt_ind=DesignResult_Compressor(9);
%放气与冷却引气计划
HPT_Cool_NGV_W=AirPlan(2);
HPT_Cool_PT_W=AirPlan(3);
LPT_Cool_NGV_W=AirPlan(4);
LPT_Cool_PT_W=AirPlan(5);

%油气比
f=0;

%增压级与压气机过渡段总压恢复系数
Sigma_ComprIn=d_Sigma_ComprIn;
Pt_in=Pt_in*Sigma_ComprIn;

%换算因子
Theta =(Tt_in/Tt_ind)^0.5;

%换算转速与特性插值
N2cor=N2/Theta;
[Compr_PR,Compr_Wcor,Compr_Eff]=ComprMap_Interp(N2cor,Z_Compr,DesignResult_Compressor,Fault);

% %相对物理转速
% N2_RMech=100.0*Theta*N2cor/Theta;

%压气机进口物理流量
W_in_Interp=Compr_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%压气机进口单位气流焓
h_in=gashi(Tt_in,f);

%第Z1级放气
Compr_PR_Z1=Compr_PR^(d_Compr_Z1/d_Compr_Z);
Tt_out_Z1=GasTt(Tt_in,0,Compr_PR_Z1,Compr_Eff);
h_Z1=gashi(Tt_out_Z1,0);
%第Z2级冷却引气
Compr_PR_Z2=Compr_PR^(d_Compr_Z2/d_Compr_Z);
Tt_out_Z2=GasTt(Tt_in,0,Compr_PR_Z2,Compr_Eff);
h_Z2=gashi(Tt_out_Z2,0);
%第Z3级冷却引气
Compr_PR_Z3=Compr_PR^(d_Compr_Z3/d_Compr_Z);
Tt_out_Z3=GasTt(Tt_in,0,Compr_PR_Z3,Compr_Eff);
h_Z3=gashi(Tt_out_Z3,0);
%压气机出口参数
Pt_out=Pt_in*Compr_PR;
Tt_out=GasTt(Tt_in,0,Compr_PR,Compr_Eff);
h_out=gashi(Tt_out,0);
W_out=W_in_Interp*(1-Compr_Def_W-HPT_Cool_NGV_W-HPT_Cool_PT_W-LPT_Cool_NGV_W-LPT_Cool_PT_W);
ComprWork=W_in_Interp*((h_Z1-h_in)+(h_Z2-h_Z1)*(1-Compr_Def_W)+(h_Z3-h_Z2)*(1-Compr_Def_W-LPT_Cool_PT_W)+(h_out-h_Z3)*(1-Compr_Def_W-LPT_Cool_PT_W-LPT_Cool_NGV_W));
