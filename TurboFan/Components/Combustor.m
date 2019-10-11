%[����ȼ������,����ȼ����,����ȼ����]=Combustor(���ڿ�����ѹ,���ڿ�����ѹ,ȼ����ֵ,ȼ������,ѹ��������������)
function [Pt_out,Tt_out,h_out,W_out,Sfcn_out]=Combustor(Pt_in,Tt_in,Wf,W_in,DesignData_Combustor)
%ȼ������Ƶ����ܲ���
d_FHV=DesignData_Combustor(1);
d_Combu_Eff=DesignData_Combustor(3);
d_Sigma_Combu=DesignData_Combustor(4);

%������
f_Real=Wf/W_in;

%ȼ���ҽ���ȼ������
W_out=Wf+W_in;

%ȼ����ֵ
Hu=d_FHV;

%ţ�ٵ��������T4s
Step=0;
Abs_Error=1;
Tt_out_ini=(0+3000)/2;
h_in=gashi(Tt_in,0);
%ȼ��Ч�����ϵ��
ScallEffb=d_Combu_Eff/0.99;
while Abs_Error>1e-12
    h_out=gashi(Tt_out_ini,f_Real);
    Effb=LookupEffb(Tt_out_ini,Tt_in,Pt_in);
    f_Cacul=(h_out-h_in)/(Effb*ScallEffb*Hu-h_out);
    h4_E=gashi(Tt_out_ini*(1-1e-5),f_Real);
    Effb_E=LookupEffb(Tt_out_ini*(1-1e-5),Tt_in,Pt_in);
    f_Cacul_E=(h4_E-h_in)/(Effb_E*ScallEffb*Hu-h4_E);
    error=f_Cacul-f_Real;
    D_error=(f_Cacul-f_Cacul_E)/(Tt_out_ini*1e-5);
    Tt_out_ini=Tt_out_ini-error/D_error;
    Abs_Error=abs(error);
    Step=Step+1;
    if Step>=50
        break
    end
end

%ȼ���ҳ���ȼ����ѹ����ѹ�ָ�ϵ������Ƶ���ͬ
Pt_out=Pt_in*d_Sigma_Combu;

%ȼ���ҳ���ȼ������������
Tt_out=Tt_out_ini;
if Tt_out<=288.15
    Tt_out=288.15;
end
if Tt_out>=2000
    Tt_out=2000;
end

%ȼ���ҳ���ȼ����
h_out=gashi(Tt_out,f_Real);

%ȼ���ҳ���ȼ����
Sfcn_out=Sfcn_Ts(f_Real,Tt_out);