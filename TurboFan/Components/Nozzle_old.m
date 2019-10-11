function [Ps_out,Ts_out,V,Ma]= Nozzle(Pt_in,Tt_in,Wt_in,Ps_atm,Wf,SigmaNoz)
%油气比
f=Wf/(Wt_in-Wf);

%喷管出口总压计算
Pt_out=Pt_in*SigmaNoz;

%喷管出口总温与焓
Tt_out=Tt_in;
h_out=gashi(Tt_out,f);

%喷管出口面积(m^2)
A_Noz=0.06;

%膨胀至环境压力后，出口燃气静温迭代计算
error=1;
a=0;
b=3000;
while error>=1e-9
    Density=Ps_atm/(R(f)*((a+b)/2));
    V_out=Wt_in/(Density*A_Noz);
    h_outCal=(h_out*1e3-0.5*V_out*V_out)/1e3;
    h_outGuess=gashi((a+b)/2,f);
    Z=h_outGuess-h_outCal;
    error=abs((h_outGuess-h_outCal)/h_outCal);
    if Z>0
        b=(a+b)/2;
    else
        a=(a+b)/2;
    end
end
Ts_out=(a+b)/2;

%喷管出口燃气静压计算
Ps_out=Pt_out/((Tt_out/Ts_out)^(1/(1-1/k(Ts_out,f))));

%喷管出口燃气速度与马赫数
V=V_out;
Ma=V_out/sqrt(k(Ts_out,f)*R(f)*Ts_out);