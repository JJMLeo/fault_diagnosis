[InFan_PR,InFan_Wcor,InFan_Eff,OutFan_PR,OutFan_Wcor,OutFan_Eff]=FanMap_Interp(1,0.68421)

W=      2.5748536675;
Pt_ind =2.832906120373616e5;
Tt_ind =1.137134644668549e3;
Wcor=W*(101325/Pt_ind)*sqrt(Tt_ind/288.15)


Wcor=54;
Pt_ind =Pt2_d;
Tt_ind =Tt2_d;
W=Wcor*(Pt_ind/101325)*sqrt(288.15/Tt_ind)

Load_Compr=1.190405921053097e4;
Tt_in=1.116749492676263e3;
W=2.751558691598692e1;
DHT=(Load_Compr)/(W*Tt_in*1e-3)

Tt_in=244.44;
f=0;
InFan_PR=1.3;
InFan_Eff=0.87;
kg=k(Tt_in,0);
%风扇进口单位气流焓与熵
h_in=gashi(Tt_in,f)
Sfcn_in=Sfcn_Ts(f,Tt_in)

%风扇出口单位气流理想焓与熵
Sfcn_out_i=log10(InFan_PR)+Sfcn_in
Tt_outi=Ts_Sfcn(Sfcn_out_i)
h_outi=gashi(Tt_outi,f)
Tt=((InFan_PR^((kg-1)/kg)-1)/InFan_Eff+1)*Tt_in;


%风扇出口单位气流实际焓
h_out=h_in+(h_outi-h_in)/InFan_Eff

[Booster_PR,Booster_Wcor,Booster_Eff]=BoosterMap_Interp(1,0.78947)

q=Ma*((2/(kg+1))*(1+0.5*(kg-1)*Ma^2))^((kg+1)/(2*(1-kg)));

a=Pt18/sqrt(Tt18);
b=48414/sqrt(290.18);
(a-b)/b;
Ma=1;
kg=k(290.18,0);
% q=Ma*((2/(kg+1))*(1+0.5*(kg-1)*Ma^2))^((kg+1)/(2*(1-kg)))
Rg=R(0);
% K_BP=sqrt((kg/Rg)*(2/(kg+1))^((kg+1)/(kg-1)))

W_out=K_BP*1.73513*1*48414/sqrt(290.18)

[Compr_PR,Compr_Wcor,Compr_Eff]=ComprMap_Interp(1,0.52632)

DHT=(ComprWork)/((W4+W_HPTCool*5/11)*1.559574603103101)

[LPT_DHT,LPT_Wcor,LPT_Eff]=LPTMap_Interp(1,0.65)




