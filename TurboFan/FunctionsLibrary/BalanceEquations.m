function [E1,E2,E3,E4,E5,E6,E7,E8]=BalanceEquations(Wf,W13,W18,W21,W24,W3,W44,W5,W8,Load_LPSpool,Load_HPSpool,HPTWork,LPTWork,AirPlan)

%��������ȴ�����ƻ�
HPT_Cool_NGV_W=AirPlan(2);
HPT_Cool_PT_W=AirPlan(3);
LPT_Cool_NGV_W=AirPlan(4);
LPT_Cool_PT_W=AirPlan(5);

%����ȳ�������=�⺭������
E1=(W13-W18)/W13;

%�ڷ��ȳ�������=ѹ��������������
E2=(W21-W24)/W21;

%��ѹ���ֳ�������=ѹ������������+��ѹ������ȴ������+ȼ��������
E3=(W24*(1-LPT_Cool_NGV_W-LPT_Cool_PT_W)+Wf-W44)/W44;

%��ѹ���ֳ�������=ѹ������������+��ȴ��������+ȼ��������
E4=(W24+Wf-W5)/W5;

%��ܳ�������=��ѹ���ֳ�������
E5=(W5-W8)/W5;

%��ѹת�ӹ���ƽ��
E6=(Load_LPSpool-LPTWork)/LPTWork;

%��ѹת�ӹ���ƽ��
E7=(Load_HPSpool-HPTWork)/HPTWork;