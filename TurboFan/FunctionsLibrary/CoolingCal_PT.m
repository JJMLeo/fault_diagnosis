function [Tt_out,Sfcn_out,W_out]= CoolingCal_PT(Tt_in,W_in,Tt_Cool_in,Wcool_in,Wf)
%PTǰȼ��������PT
f=Wf/(W_in-Wf);

%PT��ȴ���ֵ�������
Wcool_PT=Wcool_in;

%PTǰȼ����PT��ȴ����Ϻ�������
f_Mix=Wf/(W_in+Wcool_PT-Wf);

%PTǰȼ����PT��ȴ����Ϻ���
h_Mix=(W_in*gashi(Tt_in,f)+Wcool_PT*gashi(Tt_Cool_in,0))/(W_in+Wcool_PT);

%PTǰȼ����PT��ȴ����Ϻ�����
Tt_out=Tt_h(h_Mix,f_Mix);

%PTǰȼ����PT��ȴ����Ϻ���
Sfcn_out=Sfcn_Ts(f_Mix,Tt_out);

%PTǰȼ����PT��ȴ�����������
W_out=W_in+Wcool_PT;
