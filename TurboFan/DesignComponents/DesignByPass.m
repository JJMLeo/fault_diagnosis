function [Pt_out,Tt_out,W_out,V,Ma,PR_Real,Ps_out,A_BP]= DesignByPass(Pt_in,Tt_in,W_in,Pamb,DesignData_ByPass)
d_Sigma_BP=DesignData_ByPass(1);
%������
f=0;

%�⺭��������ѹ����������
SigmaBP=d_Sigma_BP;
Pt_out=Pt_in*SigmaBP;
Tt_out=Tt_in;
h_out=gashi(Tt_in,f);

%ȼ�����Բ���
[Cpg,kg,Rg]=gasstate(Tt_out,f,1,1);

%�⺭���ٽ���ѹ��
PR_cr=((kg+1)/2)^(kg/(kg-1));

%�⺭��������ѹ��
PR_use=Pt_in/Pamb;

%�⺭�������б�
if PR_use<PR_cr
    Ps_out=Pamb;
    %�⺭��ʵ����ѹ��
    PR_Real=Pt_in/Ps_out;
    V=sqrt(2*Cpg*Tt_out*(1-PR_Real^((1-kg)/kg)));
    hs_outCal=h_out-0.5*V*V*1e-3;
    error=1;
    a=0;
    b=3000;
    while error>=1e-9
        hs_outGuess=gashi((a+b)/2,f);
        Z=hs_outGuess-hs_outCal;
        error=abs((hs_outGuess-hs_outCal)/hs_outCal);
        if Z>0
            b=(a+b)/2;
        else
            a=(a+b)/2;
        end
    end
    Ts_out=(a+b)/2;
    Ma=V/sqrt(kg*Rg*Ts_out);
else
    Ps_out=Pt_in/PR_cr;
    %�⺭��ʵ����ѹ��
    PR_Real=Pt_in/Ps_out;
    V=sqrt(2*Cpg*Tt_out*(1-PR_Real^((1-kg)/kg)));
    Ma=1;
    Ts_out=(V^2)/(kg*Rg);
end

%�������Բ���
K_BP=sqrt((kg/Rg)*(2/(kg+1))^((kg+1)/(kg-1)));

%��������
q=Ma*((2/(kg+1))*(1+0.5*(kg-1)*Ma^2))^((kg+1)/(2*(1-kg)));

%�⺭�����ڿ�������
W_out=W_in;
%���ɵ��⺭���������(m^2)
A_BP=W_out/(K_BP*q*Pt_out/sqrt(Tt_out));


