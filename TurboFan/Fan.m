function [Pt_out_OutFan,Tt_out_OutFan,W_out_OutFan,Pt_out_InFan,Tt_out_InFan,W_out_InFan,FanWork]=Fan(Pt_in,Tt_in,GTR,NL,Z_Fan,BPR,DesignResult_Fan,Fault)
%��Ƶ��ڷ��Ƚ�����ѹ����������������
Tt_ind=DesignResult_Fan(6);

%������
f=0;

%��������
Theta =(Tt_in/Tt_ind)^0.5;

%����ת��
NLcor=GTR*NL/Theta;
[OutFan_PR,OutFan_Eff,InFan_PR,InFan_Eff,Fan_Wcor]=FanMap_Interp(NLcor,Z_Fan,DesignResult_Fan,Fault);

%���Ƚ��ڵ�λ������
h_in=gashi(Tt_in,f);

%����ȳ�����ѹ
Pt_out_OutFan=Pt_in*OutFan_PR;

%����ȳ�������
Tt_out_OutFan=GasTt(Tt_in,f,OutFan_PR,OutFan_Eff);

%����ȳ��ڵ�λ����ʵ����
h_out_OutFan=gashi(Tt_out_OutFan,f);

%�ڷ��ȳ�����ѹ
Pt_out_InFan=Pt_in*InFan_PR;

%�ڷ��ȳ�������
Tt_out_InFan=GasTt(Tt_in,f,InFan_PR,InFan_Eff);

%�ڷ��ȳ��ڵ�λ����ʵ����
h_out_InFan=gashi(Tt_out_InFan,f);

%���ȳ�����������
W_out_Fan=Fan_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%����ȳ�����������
W_out_OutFan=W_out_Fan*(BPR/(1+BPR));

%�ڷ��ȳ�����������
W_out_InFan=W_out_Fan-W_out_OutFan;

%����ȹ�
OutFanWork=W_out_OutFan*(h_out_OutFan-h_in);

%�ڷ��ȹ�
InFanWork=W_out_InFan*(h_out_InFan-h_in);

%���ȹ�
FanWork=OutFanWork+InFanWork;


