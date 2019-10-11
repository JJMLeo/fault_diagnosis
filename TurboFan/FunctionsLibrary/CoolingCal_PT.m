function [Tt_out,Sfcn_out,W_out]= CoolingCal_PT(Tt_in,W_in,Tt_Cool_in,Wcool_in,Wf)
%PT前燃气油气比PT
f=Wf/(W_in-Wf);

%PT冷却气分得气流量
Wcool_PT=Wcool_in;

%PT前燃气与PT冷却气混合后油气比
f_Mix=Wf/(W_in+Wcool_PT-Wf);

%PT前燃气与PT冷却气混合后焓
h_Mix=(W_in*gashi(Tt_in,f)+Wcool_PT*gashi(Tt_Cool_in,0))/(W_in+Wcool_PT);

%PT前燃气与PT冷却气混合后总温
Tt_out=Tt_h(h_Mix,f_Mix);

%PT前燃气与PT冷却气混合后熵
Sfcn_out=Sfcn_Ts(f_Mix,Tt_out);

%PT前燃气与PT冷却气混合气流量
W_out=W_in+Wcool_PT;
