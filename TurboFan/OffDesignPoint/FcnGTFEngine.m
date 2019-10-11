function [E,Norm_E]=FcnGTFEngine(AmbCondition,EngineData,NL,X,Fault)

DesignGTREngine;

PWX=EngineData(1);
Compr_Def_W=EngineData(2);

H=AmbCondition(1);Ma=AmbCondition(2);

Z_Fan=X(1);Z_Compr=X(2);Z_HPT=X(3);Z_LPT=X(4);Wf=X(5);NH=X(6);BPR=X(7);

% [Pamb,Tamb,C]=Environment(H);
[Pamb,Tamb,~]=Environment(H);

[Pt2,Tt2]=Inlet(Pamb,Tamb,Ma);

[Pt13,Tt13,W13,Pt21,Tt21,W21,FanWork]=Fan(Pt2,Tt2,d_GTR,NL,Z_Fan,BPR,DesignResult_Fan,Fault);

%[Pt18,Tt18,W18,V18,Ma18,PR18]=ByPass(Pt13,Tt13,Pamb,DesignResult_ByPass);
[~,~,W18,~,~,~]=ByPass(Pt13,Tt13,Pamb,DesignResult_ByPass);
% [Pt24,Tt24,h24,W24,BoosterWork]=Booster(Pt21,Tt21,NL,Z_Booster,DesignResult_Booster);

[Pt3,Tt3,W3,ComprWork,Tt3Z2,Tt3Z3,W24]=Compressor(Pt21,Tt21,NH,Z_Compr,DesignResult_Compressor,AirPlan,Compr_Def_W,Fault);

HPT_CoolPlan=[Tt3,W24,HPT_Cool_NGV_W,HPT_Cool_PT_W];
LPT_CoolPlan=[Tt3Z3,Tt3Z2,W24,LPT_Cool_NGV_W,LPT_Cool_PT_W];
Load_HPSpool=(ComprWork+PWX)/d_MechEff_HPSpool;
Load_LPSpool=(FanWork)/d_MechEff_LPSpool;

[Pt4,Tt4,h4,W4,Sfcn4]=Combustor(Pt3,Tt3,Wf,W3,DesignData_Combustor);

[Pt44,Tt44,W44,HPTWork]=HPTurbine(Pt4,Tt4,W4,Wf,Z_HPT,NH,DesignResult_HPT,HPT_CoolPlan,Fault);

[Pt5,Tt5,W5,LPTWork]=LPTurbine(Pt44,Tt44,W44,Wf,Z_LPT,NL,DesignResult_LPT,LPT_CoolPlan,Fault);

[Pt8,Tt8,W8,V8,Ma8,PR8]=Nozzle(Pt5,Tt5,W5,Pamb,Wf,DesignResult_Nozzle);

[E1,E2,E3,E4,E5,E6,E7]=BalanceEquations(Wf,W13,W18,W21,W24,W3,W44,W5,W8,Load_LPSpool,Load_HPSpool,HPTWork,LPTWork,AirPlan);

E=[E1,E2,E3,E4,E5,E6,E7];

Norm_E=norm(E);
