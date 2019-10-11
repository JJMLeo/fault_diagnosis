%[����ȼ������,����ȼ����]=Combustor(���ڿ�����ѹ,���ڿ�����ѹ,ȼ����ֵ,ȼ������,ѹ��������������)
function [Pt_out,Tt_out,h_out,W_out,Wf]=DesignCombustor(Pt_in,Tt_in,W_in,DesignData_Combustor)
%ȼ������Ƶ����ܲ���
d_FHV=DesignData_Combustor(1);
d_Tt4=DesignData_Combustor(2);
d_Combu_Eff=DesignData_Combustor(3);
d_Sigma_Combu=DesignData_Combustor(4);

Tt_out=d_Tt4;

Hu=d_FHV;
a=0;b=1;

h_in=gashi(Tt_in,0);
Abs_Error=1;
Step=0;
while Abs_Error>1e-12
    Wf=(a+b)/2;
    f=Wf/W_in;
    h_out=gashi(Tt_out,f);
    f_Calcu=(h_out-h_in)/(d_Combu_Eff*Hu-h_out);
    Z=f_Calcu-f;
    Abs_Error=abs((f_Calcu-f)/f);
    if Z>0
        a=(a+b)/2;
    else
        b=(a+b)/2;
    end
    Step=Step+1;
    if Step>=50
        break
    end
end
f=Wf/W_in;
Pt_out=Pt_in*d_Sigma_Combu;

%ȼ���ҳ���ȼ����
h_out=gashi(Tt_out,f);

%ȼ���ҳ���ȼ������
W_out=W_in+Wf;