function [Tt_out,Sfcn_out]= CoolingCal_NGV(Tt_in,W_in,Tt_Cool_in,Wcool_in,Wf)
%NGV前燃气油气比
f=Wf/(W_in-Wf);

%NGV冷却气分得气流量
Wcool_NGV=Wcool_in;

%NGV前燃气与NGV冷却气混合后油气比
f_Mix=Wf/(W_in+Wcool_NGV-Wf);

%NGV前燃气与NGV冷却气混合后焓
h_Mix=(W_in*gashi(Tt_in,f)+Wcool_NGV*gashi(Tt_Cool_in,0))/(W_in+Wcool_NGV);

%NGV前燃气与NGV冷却气混合后总温
Tt_out=Tt_h(h_Mix,f_Mix);

%NGV前燃气与NGV冷却气混合后熵
Sfcn_out=Sfcn_Ts(f_Mix,Tt_out);