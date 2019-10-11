%��Ƶ����
%��Ƶ㹤��
d_H=12000;
d_Ma=0.8;
%ѹ��������ѹ��
d_OutFan_PR=1.78;
d_InFan_PR=1.78;
d_Booster_PR=1
d_Compr_PR=13;
%��ѹ�ָ�ϵ��
d_Sigma_In=0.99;
d_Sigma_ComprIn=1;
d_Sigma_BP=0.99;
d_Sigma_Noz=0.99;
d_Sigma_Combu=0.96;
d_Sigma_LPTIn=0.98;
%ȼ����ֵ(kJ/kg)��ȼ���ҳ����¶�
d_FHV=42900;
d_Tt4=1320;
%�������ں�ƽ���׼������ֹ״̬ʱ������������������(kg/s)
d_W2Rstd=47.5;
%��ƺ�����
d_BPR=3.74;
%��ƴ�����
d_GTR=1;
%ѹ���������������������ܼ���
d_Compr_Z1=2;
d_Compr_Z2=3;
d_Compr_Z3=4;
d_Compr_Z=6;
%ת�ӻ�еЧ��
d_MechEff_HPSpool=0.99;
d_MechEff_LPSpool=0.98;
%��ѹת�ӹ�����ȡ(kw)
d_PWX=0;

%��������Ч��
d_OutFan_Eff=0.89;%%%%
d_InFan_Eff=0.89;%%%%

d_Booster_Eff=1;
d_Compr_Eff=0.85;%%%%
d_Combu_Eff=0.995;
d_HPT_Eff=0.89;
d_LPT_Eff=0.9;
%ѹ������������ȴ�����ƻ�����(100%=1)
Compr_Def_W=0.01;
HPT_Cool_NGV_W=0;
HPT_Cool_PT_W=0;
LPT_Cool_NGV_W=0;
LPT_Cool_PT_W=0;

DesignData_Inlet=[d_Sigma_In,d_W2Rstd,d_BPR];
DesignData_OutFan=[d_OutFan_PR,d_OutFan_Eff];
DesignData_ByPass=[d_Sigma_BP];
DesignData_InFan=[d_InFan_PR,d_InFan_Eff];
DesignData_Booster=[d_Booster_PR,d_Booster_Eff];
DesignData_Compressor=[d_Sigma_ComprIn,d_Compr_PR,d_Compr_Eff,d_Compr_Z1,d_Compr_Z2,d_Compr_Z3,d_Compr_Z];
DesignData_Combustor=[d_FHV,d_Tt4,d_Combu_Eff,d_Sigma_Combu];
DesignData_HPT=[d_HPT_Eff];
DesignData_LPT=[d_Sigma_LPTIn,d_LPT_Eff];
DesignData_Nozzle=[d_Sigma_Noz];
AirPlan=[Compr_Def_W,HPT_Cool_NGV_W,HPT_Cool_PT_W,LPT_Cool_NGV_W,LPT_Cool_PT_W];

%
% %ԭʼ��Ƶ����
% %��Ƶ㹤��
% d_H=12000;
% d_Ma=0.8;
% %ѹ��������ѹ��
% d_OutFan_PR=1.70171;
% d_InFan_PR=1.3;
% d_Booster_PR=4;
% d_Compr_PR=7;
% %��ѹ�ָ�ϵ��
% d_Sigma_In=0.99;
% d_Sigma_ComprIn=0.98;
% d_Sigma_BP=0.975;
% d_Sigma_Noz=0.99;
% d_Sigma_Combu=0.95;
% d_Sigma_LPTIn=0.98;
% %ȼ����ֵ(kJ/kg)��ȼ���ҳ����¶�
% d_FHV=43124;
% d_Tt4=1600;
% %��ƽ���׼������ֹ״̬������������������(kg/s)
% d_W2Rstd=700;
% %��ƺ�����
% d_BPR=8;
% %��ƴ�����
% d_GTR=1;
% %ѹ���������������������ܼ���
% d_Compr_Z1=2;
% d_Compr_Z2=3;
% d_Compr_Z3=4;
% d_Compr_Z=6;
% %ת�ӻ�еЧ��
% d_MechEff_HPSpool=0.98;
% d_MechEff_LPSpool=0.98;
% %��ѹת�ӹ�����ȡ(kw)
% d_PWX=50;
% %�������(m^2)
% d_A_BP=1.73513;
% d_A_Noz=0.54226;
% %��������Ч��
% d_OutFan_Eff=0.878;
% d_InFan_Eff=0.87;
% d_Booster_Eff=0.84;
% d_Compr_Eff=0.85;
% d_Combu_Eff=0.9995;
% d_HPT_Eff=0.88;
% d_LPT_Eff=0.9;
% %ѹ������������ȴ�����ƻ�����(100%=1)
% Compr_Def_W=0;
% HPT_Cool_NGV_W=0.05;
% HPT_Cool_PT_W=0.06;
% LPT_Cool_NGV_W=0;
% LPT_Cool_PT_W=0.02;
% 
% DesignData_Inlet=[d_Sigma_In,d_W2Rstd,d_BPR];
% DesignData_OutFan=[d_OutFan_PR,d_OutFan_Eff];
% DesignData_ByPass=[d_Sigma_BP,d_A_BP];
% DesignData_InFan=[d_InFan_PR,d_InFan_Eff];
% DesignData_Booster=[d_Booster_PR,d_Booster_Eff];
% DesignData_Compressor=[d_Sigma_ComprIn,d_Compr_PR,d_Compr_Eff,d_Compr_Z1,d_Compr_Z2,d_Compr_Z3,d_Compr_Z];
% DesignData_Combustor=[d_FHV,d_Tt4,d_Combu_Eff,d_Sigma_Combu];
% DesignData_HPT=[d_HPT_Eff];
% DesignData_LPT=[d_Sigma_LPTIn,d_LPT_Eff];
% DesignData_Nozzle=[d_Sigma_Noz,d_A_Noz];
% AirPlan=[Compr_Def_W,HPT_Cool_NGV_W,HPT_Cool_PT_W,LPT_Cool_NGV_W,LPT_Cool_PT_W];