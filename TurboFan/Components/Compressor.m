function [Pt_out,Tt_out,W_out,ComprWork,Tt_out_Z2,Tt_out_Z3,W_in_Interp]=Compressor(Pt_in,Tt_in,N2,Z_Compr,DesignResult_Compressor,AirPlan,Compr_Def_W,Fault)
%ѹ������Ƶ����
d_Sigma_ComprIn=DesignResult_Compressor(1);
d_Compr_Z1=DesignResult_Compressor(4);
d_Compr_Z2=DesignResult_Compressor(5);
d_Compr_Z3=DesignResult_Compressor(6);
d_Compr_Z=DesignResult_Compressor(7);
%��Ƶ�ѹ������������
Tt_ind=DesignResult_Compressor(9);
%��������ȴ�����ƻ�
HPT_Cool_NGV_W=AirPlan(2);
HPT_Cool_PT_W=AirPlan(3);
LPT_Cool_NGV_W=AirPlan(4);
LPT_Cool_PT_W=AirPlan(5);

%������
f=0;

%��ѹ����ѹ�������ɶ���ѹ�ָ�ϵ��
Sigma_ComprIn=d_Sigma_ComprIn;
Pt_in=Pt_in*Sigma_ComprIn;

%��������
Theta =(Tt_in/Tt_ind)^0.5;

%����ת�������Բ�ֵ
N2cor=N2/Theta;
[Compr_PR,Compr_Wcor,Compr_Eff]=ComprMap_Interp(N2cor,Z_Compr,DesignResult_Compressor,Fault);

% %�������ת��
% N2_RMech=100.0*Theta*N2cor/Theta;

%ѹ����������������
W_in_Interp=Compr_Wcor*(Pt_in/101325)*sqrt(288.15/Tt_in);

%ѹ�������ڵ�λ������
h_in=gashi(Tt_in,f);

%��Z1������
Compr_PR_Z1=Compr_PR^(d_Compr_Z1/d_Compr_Z);
Tt_out_Z1=GasTt(Tt_in,0,Compr_PR_Z1,Compr_Eff);
h_Z1=gashi(Tt_out_Z1,0);
%��Z2����ȴ����
Compr_PR_Z2=Compr_PR^(d_Compr_Z2/d_Compr_Z);
Tt_out_Z2=GasTt(Tt_in,0,Compr_PR_Z2,Compr_Eff);
h_Z2=gashi(Tt_out_Z2,0);
%��Z3����ȴ����
Compr_PR_Z3=Compr_PR^(d_Compr_Z3/d_Compr_Z);
Tt_out_Z3=GasTt(Tt_in,0,Compr_PR_Z3,Compr_Eff);
h_Z3=gashi(Tt_out_Z3,0);
%ѹ�������ڲ���
Pt_out=Pt_in*Compr_PR;
Tt_out=GasTt(Tt_in,0,Compr_PR,Compr_Eff);
h_out=gashi(Tt_out,0);
W_out=W_in_Interp*(1-Compr_Def_W-HPT_Cool_NGV_W-HPT_Cool_PT_W-LPT_Cool_NGV_W-LPT_Cool_PT_W);
ComprWork=W_in_Interp*((h_Z1-h_in)+(h_Z2-h_Z1)*(1-Compr_Def_W)+(h_Z3-h_Z2)*(1-Compr_Def_W-LPT_Cool_PT_W)+(h_out-h_Z3)*(1-Compr_Def_W-LPT_Cool_PT_W-LPT_Cool_NGV_W));
