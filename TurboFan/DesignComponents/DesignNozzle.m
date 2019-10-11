%收敛喷管算法
function [Pt_out,Tt_out,W_out,V,Ma,PR_Real,Ps_out,A_Noz]=DesignNozzle(Pt_in,Tt_in,W_in,Pamb,Wf,DesignData_Nozzle)

d_Sigma_Noz=DesignData_Nozzle(1);

%油气比
f=Wf/(W_in-Wf);

%喷管出口总压、总温与焓
Pt_out=Pt_in*d_Sigma_Noz;
Tt_out=Tt_in;
h_out=gashi(Tt_in,f);

%燃气物性参数
[Cpg,kg,Rg]=gasstate(Tt_out,f,1,1);

%喷管临界落压比
PR_cr=((kg+1)/2)^(kg/(kg-1));

%喷管可用落压比
PR_use=Pt_in/Pamb;

%喷管流动判别
if PR_use<PR_cr
    Ps_out=Pamb;
    %喷管实际落压比
    PR_Real=Pt_in/Ps_out;
    V=sqrt(2*Cpg*Tt_out*(1-PR_Real^((1-kg)/kg)));
    hs_outCal=h_out-0.5*V*V*1e-3;
    error=1;
    a=0;
    b=3000;
    Step=0;
    while error>=1e-9
        hs_outGuess=gashi((a+b)/2,f);
        Z=hs_outGuess-hs_outCal;
        error=abs((hs_outGuess-hs_outCal)/hs_outCal);
        if Z>0
            b=(a+b)/2;
        else
            a=(a+b)/2;
        end
        Step=Step+1;
        if Step>=50
            break
        end
    end
    Ts_out=(a+b)/2;
    Ma=V/sqrt(kg*Rg*Ts_out);
else
    Ps_out=Pt_in/PR_cr;
    %喷管实际落压比
    PR_Real=Pt_in/Ps_out;
    V=sqrt(2*Cpg*Tt_out*(1-PR_Real^((1-kg)/kg)));
    Ma=1;
    Ts_out=(V^2)/(kg*Rg);
end

%燃气物性参数
K_Noz=sqrt((kg/Rg)*(2/(kg+1))^((kg+1)/(kg-1)));

%流量函数
q=Ma*((2/(kg+1))*(1+0.5*(kg-1)*Ma^2))^((kg+1)/(2*(1-kg)));

%喷管出口燃气流量
W_out=W_in;

%喷管出口面积(m^2)
A_Noz=W_out/(K_Noz*q*Pt_out/sqrt(Tt_out));
