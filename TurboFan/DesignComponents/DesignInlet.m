function [Pt_out,Tt_out,OutFan_W_In,InFan_W_In,Fan_W_in] = DesignInlet(Ps_in,Ts_in,Ma,DesignData_Inlet)
d_Sigma_In=DesignData_Inlet(1);
d_W2Rstd=DesignData_Inlet(2);
d_BPR=DesignData_Inlet(3);
[~,ka,~]=gasstate(Ts_in,0,1,1);
if Ma<=1.0
        Sigma_Inl=d_Sigma_In;
    else
        Sigma_Inl=0.88722+0.1717*Ma-0.08986*Ma^2;
end
%环境总压
Pt_in=Ps_in*(1+(ka-1)/2*Ma^2)^(ka/(ka-1));
%环境总温
Tt_out=Ts_in*(1+(ka-1)/2*Ma^2);
%进气道出口总压
Pt_out=Pt_in*Sigma_Inl;
%进气道出口流量
Fan_W_in=d_W2Rstd*(Pt_out/101325)*sqrt(288.15/Tt_out);
%内风扇进口流量
InFan_W_In=Fan_W_in/(1+d_BPR);
%外风扇进口流量
OutFan_W_In=Fan_W_in-InFan_W_In;