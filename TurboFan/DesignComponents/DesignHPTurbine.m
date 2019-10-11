function [Pt_out,Tt_outCool,W_outCool,h_outCool,HPT_Character]=DesignHPTurbine(Pt_in,Tt_in,W_in,Wf,HPT_CoolPlan_d,Load_HPSpool_d,DesignData_HPT)
%��Ƶ��ѹ������ȴ�ƻ�
Tt_in_HPTCool=HPT_CoolPlan_d(1);
W_HPT_Cool=HPT_CoolPlan_d(2);
HPT_Cool_NGV_W=HPT_CoolPlan_d(3);
HPT_Cool_PT_W=HPT_CoolPlan_d(4);
%��ȴ����
W_in_HPTCoolNGV=W_HPT_Cool*HPT_Cool_NGV_W;
W_in_HPTCoolPT=W_HPT_Cool*HPT_Cool_PT_W;

d_HPT_Eff=DesignData_HPT(1);

%NGV��ȴ����
[Tt_inCool,Sfcn_Cool]=CoolingCal_NGV(Tt_in,W_in,Tt_in_HPTCool,W_in_HPTCoolNGV,Wf);
W_in_Cool=W_in+W_in_HPTCoolNGV;

%��ѹ������������
HPT_Character=[Tt_inCool,W_in_Cool];

%������
f1=Wf/(W_in_Cool-Wf);

%������ֳ���ȼ����ʵ�����¡���
h_out=(W_in_Cool*gashi(Tt_inCool,f1)-Load_HPSpool_d)/W_in_Cool;
Tt_out=Tt_h(h_out,f1);

%������ֳ���ȼ�����������¡�������
h_outi=(W_in_Cool*gashi(Tt_inCool,f1)-(Load_HPSpool_d/d_HPT_Eff))/W_in_Cool;
Tt_outi=Tt_h(h_outi,f1);
Sfcn_outi=Sfcn_Ts(f1,Tt_outi);

%���������ѹ��
if Sfcn_Cool<=Sfcn_outi
    PR=1;
else
    PR=10^(Sfcn_Cool-Sfcn_outi);
end

%������ֳ���ȼ����ѹ
Pt_out=Pt_in/PR;

%PT��ȴ����
[Tt_outCool,~,W_outCool]=CoolingCal_PT(Tt_out,W_in_Cool,Tt_in_HPTCool,W_in_HPTCoolPT,Wf);

%������
f2=Wf/(W_outCool-Wf);

%PT��ȴ��ȼ����
h_outCool=gashi(Tt_outCool,f2);

