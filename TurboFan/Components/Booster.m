function [Pt_out,Tt_out,h_out,W_out,BoosterWork]=Booster(Pt_in,Tt_in,N1,Z_Booster,DesignResult_Booster)
%��Ƶ���ѹ��������ѹ����������������
Tt_ind=DesignResult_Booster(4);
%������
f=0;
%��������
Theta =(Tt_in/Tt_ind)^0.5;

%����ת��
N1cor=N1/Theta;
[Booster_PR,Booster_Wcor,Booster_Eff]=BoosterMap_Interp(N1cor,Z_Booster,DesignResult_Booster);

%��ѹ�����ڵ�λ����������
h_in=gashi(Tt_in,f);

%��ѹ��������ѹ
Pt_out=Pt_in

%��ѹ����������
Tt_out=GasTt(Tt_in,f,1,1);

%��ѹ�����ڵ�λ����ʵ����
h_out=gashi(Tt_out,f);

%��ѹ��������������
W_out=Booster_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%��ѹ����
BoosterWork=0
