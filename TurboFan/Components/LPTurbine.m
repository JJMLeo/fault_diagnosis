function [Pt_out,Tt_outCool,W_outCool,LPTWork]=LPTurbine(Pt_in,Tt_in,W_in,Wf,Z_LPT,Nl,DesignResult_LPT,LPT_CoolPlan,Fault)
d_Sigma_LPTIn=DesignResult_LPT(1);
%��Ƶ��ѹ���ֽ����¶�
Tt_inCool_d=DesignResult_LPT(4);

%��ѹ������ȴ�ƻ�
Tt_in_LPTCool_NGV=LPT_CoolPlan(1);
Tt_in_LPTCool_PT=LPT_CoolPlan(2);
W_LPT_Cool=LPT_CoolPlan(3);
LPT_Cool_NGV_W=LPT_CoolPlan(4);
LPT_Cool_PT_W=LPT_CoolPlan(5);
%��ȴ����
W_in_LPTCoolNGV=W_LPT_Cool*LPT_Cool_NGV_W;
W_in_LPTCoolPT=W_LPT_Cool*LPT_Cool_PT_W;
%NGV��ȴ����
[Tt_inCool,Sfcn_Cool]=CoolingCal_NGV(Tt_in,W_in,Tt_in_LPTCool_NGV,W_in_LPTCoolNGV,Wf);

%��������
Theta =(Tt_inCool/Tt_inCool_d)^0.5;

%����ת�������Բ�ֵ
Nlcor=Nl/Theta;
[LPT_DHT,LPT_Wcor,LPT_Eff]=LPTMap_Interp(Nlcor,Z_LPT,DesignResult_LPT,Fault);

%��ѹ���ֽ�������������ֵ���
W_in_interp=LPT_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_inCool);

%������
f1=Wf/(W_in_interp-Wf);

%����ѹ���ֳ���ȼ����ʵ�����¡���
LPTWork=W_in_interp*LPT_DHT*Tt_inCool*1e-3;
hcalcu=gashi(Tt_inCool,f1)-LPT_DHT*Tt_inCool*1e-3;
Tt_out=Tt_h(hcalcu,f1);

%����ѹ���ֳ���ȼ�����������¡�������
LPT_DHTi=LPT_DHT/LPT_Eff;
hcalcui=gashi(Tt_inCool,f1)-LPT_DHTi*Tt_inCool*1e-3;
Tt_outi=Tt_h(hcalcui,f1);
Sfcn_outi=Sfcn_Ts(f1,Tt_outi);

%����ѹ������ѹ��
if Sfcn_Cool<=Sfcn_outi
    PR=1;
else
    PR=10^(Sfcn_Cool-Sfcn_outi);
end

%����ѹ���ֳ���ȼ����ѹ
Pt_out=Pt_in*d_Sigma_LPTIn/PR;

%PT��ȴ����
[Tt_outCool,~,W_outCool]=CoolingCal_PT(Tt_out,W_in_interp,Tt_in_LPTCool_PT,W_in_LPTCoolPT,Wf);

%������
f2=Wf/(W_outCool-Wf);

