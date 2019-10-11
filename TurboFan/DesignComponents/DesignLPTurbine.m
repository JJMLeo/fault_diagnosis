function [Pt_out,Tt_outCool,W_outCool,h_outCool,LPT_Character]=DesignLPTurbine(Pt_in,Tt_in,W_in,Wf,LPT_CoolPlan_d,Load_LPSpool_d,DesignData_LPT)
%低压涡轮冷却计划
Tt_in_LPTCool_NGV=LPT_CoolPlan_d(1);
Tt_in_LPTCool_PT=LPT_CoolPlan_d(2);
W_LPT_Cool=LPT_CoolPlan_d(3);
LPT_Cool_NGV_W=LPT_CoolPlan_d(4);
LPT_Cool_PT_W=LPT_CoolPlan_d(5);
%冷却气流
W_in_LPTCoolNGV=W_LPT_Cool*LPT_Cool_NGV_W;
W_in_LPTCoolPT=W_LPT_Cool*LPT_Cool_PT_W;

d_Sigma_LPTIn=DesignData_LPT(1);
d_LPT_Eff=DesignData_LPT(2);

%NGV冷却计算
[Tt_inCool,Sfcn_Cool]=CoolingCal_NGV(Tt_in,W_in,Tt_in_LPTCool_NGV,W_in_LPTCoolNGV,Wf);
W_in_Cool=W_in+W_in_LPTCoolNGV;

%高压涡轮特征参数
LPT_Character=[Tt_inCool,W_in_Cool];

%油气比
f1=Wf/(W_in_Cool-Wf);

%求解涡轮出口燃气流实际总温、焓
h_out=(W_in_Cool*gashi(Tt_inCool,f1)-Load_LPSpool_d)/W_in_Cool;
Tt_out=Tt_h(h_out,f1);

%求解涡轮出口燃气流理想总温、焓与熵
h_outi=(W_in_Cool*gashi(Tt_inCool,f1)-Load_LPSpool_d/d_LPT_Eff)/W_in_Cool;
Tt_outi=Tt_h(h_outi,f1);
Sfcn_outi=Sfcn_Ts(f1,Tt_outi);

%求解涡轮落压比
if Sfcn_Cool<=Sfcn_outi
    PR=1;
else
    PR=10^(Sfcn_Cool-Sfcn_outi);
end

%求解涡轮出口燃气总压
Pt_out=Pt_in*d_Sigma_LPTIn/PR;

%PT冷却计算
[Tt_outCool,~,W_outCool]=CoolingCal_PT(Tt_out,W_in_Cool,Tt_in_LPTCool_PT,W_in_LPTCoolPT,Wf);

%油气比
f2=Wf/(W_outCool-Wf);

%PT冷却后燃气焓
h_outCool=gashi(Tt_outCool,f2);

