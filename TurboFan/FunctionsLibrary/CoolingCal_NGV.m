function [Tt_out,Sfcn_out]= CoolingCal_NGV(Tt_in,W_in,Tt_Cool_in,Wcool_in,Wf)
%NGVǰȼ��������
f=Wf/(W_in-Wf);

%NGV��ȴ���ֵ�������
Wcool_NGV=Wcool_in;

%NGVǰȼ����NGV��ȴ����Ϻ�������
f_Mix=Wf/(W_in+Wcool_NGV-Wf);

%NGVǰȼ����NGV��ȴ����Ϻ���
h_Mix=(W_in*gashi(Tt_in,f)+Wcool_NGV*gashi(Tt_Cool_in,0))/(W_in+Wcool_NGV);

%NGVǰȼ����NGV��ȴ����Ϻ�����
Tt_out=Tt_h(h_Mix,f_Mix);

%NGVǰȼ����NGV��ȴ����Ϻ���
Sfcn_out=Sfcn_Ts(f_Mix,Tt_out);