function [Pt_out,Tt_outCool,W_outCool,HPTWork]=HPTurbine(Pt_in,Tt_in,W_in,Wf,Z_HPT,Nh,DesignResult_HPT,HPT_CoolPlan,Fault)
%设计点高压涡轮进口温度
Tt_inCool_d=DesignResult_HPT(3);

%高压涡轮冷却计划
Tt_in_HPTCool=HPT_CoolPlan(1);
W_HPT_Cool=HPT_CoolPlan(2);
HPT_Cool_NGV_W=HPT_CoolPlan(3);
HPT_Cool_PT_W=HPT_CoolPlan(4);
%冷却气流
W_in_HPTCoolNGV=W_HPT_Cool*HPT_Cool_NGV_W;
W_in_HPTCoolPT=W_HPT_Cool*HPT_Cool_PT_W;
%NGV冷却计算
[Tt_inCool,Sfcn_Cool]=CoolingCal_NGV(Tt_in,W_in,Tt_in_HPTCool,W_in_HPTCoolNGV,Wf);

%换算因子
Theta =(Tt_inCool/Tt_inCool_d)^0.5;

%换算转速与特性插值
Nhcor=Nh/Theta;
[HPT_DHT,HPT_Wcor,HPT_Eff]=HPTMap_Interp(Nhcor,Z_HPT,DesignResult_HPT,Fault);

%涡轮进口物理流量插值结果
W_in_interp=HPT_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_inCool);

%油气比
f1=Wf/(W_in_interp-Wf);

%求解涡轮出口燃气流实际总温、焓
HPTWork=W_in_interp*HPT_DHT*Tt_inCool*1e-3;
hcalcu=gashi(Tt_inCool,f1)-HPT_DHT*Tt_inCool*1e-3;
Tt_out=Tt_h(hcalcu,f1);

%求解涡轮出口燃气流理想总温、焓与熵
HPT_DHTi=HPT_DHT/HPT_Eff;
hcalcui=gashi(Tt_inCool,f1)-HPT_DHTi*Tt_inCool*1e-3;
Tt_outi=Tt_h(hcalcui,f1);
Sfcn_outi=Sfcn_Ts(f1,Tt_outi);

%求解涡轮落压比
if Sfcn_Cool<=Sfcn_outi
    PR=1;
else
    PR=10^(Sfcn_Cool-Sfcn_outi);
end

%求解涡轮出口燃气总压
Pt_out=Pt_in/PR;

%PT冷却计算
[Tt_outCool,~,W_outCool]=CoolingCal_PT(Tt_out,W_in_interp,Tt_in_HPTCool,W_in_HPTCoolPT,Wf);

%油气比
f2=Wf/(W_outCool-Wf);

