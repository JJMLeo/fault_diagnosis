function [Pt_out,Tt_outCool,W_outCool,LPTWork]=LPTurbine(Pt_in,Tt_in,W_in,Wf,Z_LPT,Nl,DesignResult_LPT,LPT_CoolPlan,Fault)
d_Sigma_LPTIn=DesignResult_LPT(1);
%设计点低压涡轮进口温度
Tt_inCool_d=DesignResult_LPT(4);

%低压涡轮冷却计划
Tt_in_LPTCool_NGV=LPT_CoolPlan(1);
Tt_in_LPTCool_PT=LPT_CoolPlan(2);
W_LPT_Cool=LPT_CoolPlan(3);
LPT_Cool_NGV_W=LPT_CoolPlan(4);
LPT_Cool_PT_W=LPT_CoolPlan(5);
%冷却气流
W_in_LPTCoolNGV=W_LPT_Cool*LPT_Cool_NGV_W;
W_in_LPTCoolPT=W_LPT_Cool*LPT_Cool_PT_W;
%NGV冷却计算
[Tt_inCool,Sfcn_Cool]=CoolingCal_NGV(Tt_in,W_in,Tt_in_LPTCool_NGV,W_in_LPTCoolNGV,Wf);

%换算因子
Theta =(Tt_inCool/Tt_inCool_d)^0.5;

%换算转速与特性插值
Nlcor=Nl/Theta;
[LPT_DHT,LPT_Wcor,LPT_Eff]=LPTMap_Interp(Nlcor,Z_LPT,DesignResult_LPT,Fault);

%低压涡轮进口物理流量插值结果
W_in_interp=LPT_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_inCool);

%油气比
f1=Wf/(W_in_interp-Wf);

%求解低压涡轮出口燃气流实际总温、焓
LPTWork=W_in_interp*LPT_DHT*Tt_inCool*1e-3;
hcalcu=gashi(Tt_inCool,f1)-LPT_DHT*Tt_inCool*1e-3;
Tt_out=Tt_h(hcalcu,f1);

%求解低压涡轮出口燃气流理想总温、焓与熵
LPT_DHTi=LPT_DHT/LPT_Eff;
hcalcui=gashi(Tt_inCool,f1)-LPT_DHTi*Tt_inCool*1e-3;
Tt_outi=Tt_h(hcalcui,f1);
Sfcn_outi=Sfcn_Ts(f1,Tt_outi);

%求解低压涡轮落压比
if Sfcn_Cool<=Sfcn_outi
    PR=1;
else
    PR=10^(Sfcn_Cool-Sfcn_outi);
end

%求解低压涡轮出口燃气总压
Pt_out=Pt_in*d_Sigma_LPTIn/PR;

%PT冷却计算
[Tt_outCool,~,W_outCool]=CoolingCal_PT(Tt_out,W_in_interp,Tt_in_LPTCool_PT,W_in_LPTCoolPT,Wf);

%油气比
f2=Wf/(W_outCool-Wf);

