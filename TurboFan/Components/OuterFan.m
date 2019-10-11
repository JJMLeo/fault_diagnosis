function [Pt_out,Tt_out,h_out,W_out,FanWork]=OuterFan(Pt_in,Tt_in,GTR,N1,Z_Fan,DesignResult_OutFan)
%��Ƶ�����Ƚ�����ѹ����������������
Tt_ind=DesignResult_OutFan(4);
%������
f=0;
%��������
Theta =(Tt_in/Tt_ind)^0.5;

%����ת��
N1cor=GTR*N1/Theta;
[OutFan_PR,OutFan_Wcor,OutFan_Eff]=FanMap_Interp(N1cor,Z_Fan,DesignResult_OutFan);

%����Ƚ��ڵ�λ����������
h_in=gashi(Tt_in,f);

%����ȳ�����ѹ
Pt_out=Pt_in*OutFan_PR;

%����ȳ�������
Tt_out=GasTt(Tt_in,f,OutFan_PR,OutFan_Eff);

%����ȳ��ڵ�λ����ʵ����
h_out=gashi(Tt_out,f);

%����ȳ�����������
W_out=OutFan_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%����ȹ�
FanWork=W_out*(h_out-h_in);
