function [Pt_out,Tt_out,h_out,W_out,FanWork]=InnerFan(Pt_in,Tt_in,GTR,N1,Z_Fan,DesignResult_InFan)
%��Ƶ��ڷ��Ƚ�����ѹ����������������
Tt_ind=DesignResult_InFan(4);
%������
f=0;
%��������
Theta =(Tt_in/Tt_ind)^0.5;

%����ת��
N1cor=GTR*N1/Theta;
[InFan_PR,InFan_Wcor,InFan_Eff]=FanMap_Interp(N1cor,Z_Fan,DesignResult_InFan);

%�ڷ��Ƚ��ڵ�λ����������
h_in=gashi(Tt_in,f);

%�ڷ��ȳ�����ѹ
Pt_out=Pt_in*InFan_PR;

%�ڷ��ȳ�������
Tt_out=GasTt(Tt_in,f,InFan_PR,InFan_Eff);

%�ڷ��ȳ��ڵ�λ����ʵ����
h_out=gashi(Tt_out,f);

%�ڷ��ȳ�����������
W_out=InFan_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%�ڷ��ȹ�
FanWork=W_out*(h_out-h_in);
