Ma1=0.14896;
Pt1=264.828e+3;
Tt1=1034.86;
Wf1=0.55362;
W1=25.180;
f1=Wf1/(W1-Wf1);

Ma2=0.40385;
Pt2=291.907e+3;
Tt2=408.39;
Wf2=0;
W2=24.750;
f2=Wf2/(W2-Wf2);

Ma=0.2;
Pt=268.130e+3;
Tt=739.67;
Wf=0.55362;
W=W1+W2;

f=Wf/(W-Wf);
% [Cp,k,R]=gasstate(Tt,f,1,1);
% Ps=Pt/((1+0.5*(k-1)*Ma^2)^(k/(k-1)));
% Ps64=Ps

Pt=0.99*(W1*Pt1+W2*Pt2)/W
PR=10^((Sfcn_Ts(f1,Tt1)*W1+Sfcn_Ts(f2,Tt2)*W2-Sfcn_Ts(f,Tt)*W)/W)
Pt_out=Pt*PR
