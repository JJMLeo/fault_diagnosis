function [Pt_out,Tt_out,Q0] = Inlet(Ps_in,Ts_in,Ma)
[~,ka,~]=gasstate(Ts_in,0,1,1);
if Ma<=1.0
        Sigma_Inl=0.99;
    else
        Sigma_Inl=0.88722+0.1717*Ma-0.08986*Ma^2;
end
%������ѹ
Pt_in=Ps_in*(1+(ka-1)/2*Ma^2)^(ka/(ka-1));
%��������
Tt_out=Ts_in*(1+(ka-1)/2*Ma^2);
%������������ѹ
Pt_out=Pt_in*Sigma_Inl;%������������ѹ
%��������ѹͷ
Q0=0.5*ka*Pt_in*(Ma^2);