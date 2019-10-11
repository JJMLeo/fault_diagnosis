function [E1,E2,E3,E4,E5,E6,E7,E8]=BalanceEquations(Wf,W13,W18,W21,W24,W3,W44,W5,W8,Load_LPSpool,Load_HPSpool,HPTWork,LPTWork,AirPlan)

%放气与冷却引气计划
HPT_Cool_NGV_W=AirPlan(2);
HPT_Cool_PT_W=AirPlan(3);
LPT_Cool_NGV_W=AirPlan(4);
LPT_Cool_PT_W=AirPlan(5);

%外风扇出口流量=外涵流量：
E1=(W13-W18)/W13;

%内风扇出口流量=压气机出口流量：
E2=(W21-W24)/W21;

%高压涡轮出口流量=压气机出口流量+高压涡轮冷却气流量+燃油流量：
E3=(W24*(1-LPT_Cool_NGV_W-LPT_Cool_PT_W)+Wf-W44)/W44;

%低压涡轮出口流量=压气机出口流量+冷却气总流量+燃油流量：
E4=(W24+Wf-W5)/W5;

%喷管出口流量=低压涡轮出口流量
E5=(W5-W8)/W5;

%低压转子功率平衡
E6=(Load_LPSpool-LPTWork)/LPTWork;

%高压转子功率平衡
E7=(Load_HPSpool-HPTWork)/HPTWork;