%0.124485 秒

%设计点数据
DesignPointData;

%设计点外界环境
[Pamb_d,Tamb_d,C_d]=Environment(d_H);

%设计点进气道计算
[Pt2_d,Tt2_d,W13_d,W21_d,W2_d]=DesignInlet(Pamb_d,Tamb_d,d_Ma,DesignData_Inlet);

%设计点外风扇
[Pt13_d,Tt13_d,OutFanWork_d]=DesignOutFan(Pt2_d,Tt2_d,W13_d,DesignData_OutFan);

%设计点外涵道
[Pt18_d,Tt18_d,W18_d,V18_d,Ma18_d,PR18_d,P18_d,A_BP]=DesignByPass(Pt13_d,Tt13_d,W13_d,Pamb_d,DesignData_ByPass);

%设计点内风扇
[Pt21_d,Tt21_d,InFanWork_d]=DesignInFan(Pt2_d,Tt2_d,W21_d,DesignData_InFan);

%设计点增压级
[Pt24_d,Tt24_d,W24_d,BoosterWork_d]=DesignBooster(Pt21_d,Tt21_d,W21_d,DesignData_Booster);

%设计点压气机
[Pt3_d,Tt3_d,W3_d,ComprWork_d,Tt3Z1_d,Tt3Z2_d,Tt3Z3_d]=DesignCompressor(Pt24_d,Tt24_d,W24_d,DesignData_Compressor,AirPlan);
HPT_CoolPlan_d=[Tt3_d,W24_d,HPT_Cool_NGV_W,HPT_Cool_PT_W];
LPT_CoolPlan_d=[Tt3Z3_d,Tt3Z2_d,W24_d,LPT_Cool_NGV_W,LPT_Cool_PT_W];
Load_HPSpool_d=(ComprWork_d+d_PWX)/d_MechEff_HPSpool;
Load_LPSpool_d=(InFanWork_d+OutFanWork_d+BoosterWork_d)/d_MechEff_LPSpool;

%设计点燃烧室
[Pt4_d,Tt4_d,h4_d,W4_d,Wf_d]=DesignCombustor(Pt3_d,Tt3_d,W3_d,DesignData_Combustor);

%设计点高压涡轮
[Pt44_d,Tt44_d,W44_d,h44_d,HPT_Character]=DesignHPTurbine(Pt4_d,Tt4_d,W4_d,Wf_d,HPT_CoolPlan_d,Load_HPSpool_d,DesignData_HPT);

%设计点低压涡轮
[Pt5_d,Tt5_d,W5_d,h5_d,LPT_Character]=DesignLPTurbine(Pt44_d,Tt44_d,W44_d,Wf_d,LPT_CoolPlan_d,Load_LPSpool_d,DesignData_LPT);

%设计点喷管
[Pt8_d,Tt8_d,W8_d,V8_d,Ma8_d,PR8_d,P8_d,A_Noz]=DesignNozzle(Pt5_d,Tt5_d,W5_d,Pamb_d,Wf_d,DesignData_Nozzle);

%设计点总体性能
V0_d=d_Ma*C_d;
F_d=(V18_d-V0_d)*W18_d+(V8_d-V0_d)*W8_d+(P8_d-Pamb_d)*A_Noz+(P18_d-Pamb_d)*A_BP;
SFC_d=3600*Wf_d/F_d;

DesignResult_Inlet=DesignData_Inlet;
DesignResult_Fan=[DesignData_OutFan,DesignData_InFan,Pt2_d,Tt2_d,W2_d];
% DesignResult_OutFan=[DesignData_OutFan,Pt2_d,Tt2_d,W13_d];
DesignResult_ByPass=[DesignData_ByPass,A_BP];
% DesignResult_InFan=[DesignData_InFan,Pt2_d,Tt2_d,W21_d];
DesignResult_Booster=[DesignData_Booster,Pt21_d,Tt21_d,W21_d];
DesignResult_Compressor=[DesignData_Compressor,Pt24_d,Tt24_d,W24_d];
DesignResult_Combustor=DesignData_Combustor;
DesignResult_HPT=[DesignData_HPT,Pt4_d,HPT_Character,Load_HPSpool_d];
DesignResult_LPT=[DesignData_LPT,Pt44_d,LPT_Character,Load_LPSpool_d];
DesignResult_Nozzle=[DesignData_Nozzle,A_Noz];

