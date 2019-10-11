%[出口燃气总温,出口燃气焓]=Combustor(进口空气总压,进口空气总压,燃油热值,燃油流量,压气机出口气流量)
function [Pt_out,Tt_out,h_out,W_out,Wf]=DesignCombustor(Pt_in,Tt_in,W_in,DesignData_Combustor)
%燃烧室设计点性能参数
d_FHV=DesignData_Combustor(1);
d_Tt4=DesignData_Combustor(2);
d_Combu_Eff=DesignData_Combustor(3);
d_Sigma_Combu=DesignData_Combustor(4);

Tt_out=d_Tt4;

Hu=d_FHV;
a=0;b=1;

h_in=gashi(Tt_in,0);
Abs_Error=1;
Step=0;
while Abs_Error>1e-12
    Wf=(a+b)/2;
    f=Wf/W_in;
    h_out=gashi(Tt_out,f);
    f_Calcu=(h_out-h_in)/(d_Combu_Eff*Hu-h_out);
    Z=f_Calcu-f;
    Abs_Error=abs((f_Calcu-f)/f);
    if Z>0
        a=(a+b)/2;
    else
        b=(a+b)/2;
    end
    Step=Step+1;
    if Step>=50
        break
    end
end
f=Wf/W_in;
Pt_out=Pt_in*d_Sigma_Combu;

%燃烧室出口燃气焓
h_out=gashi(Tt_out,f);

%燃烧室出口燃气流量
W_out=W_in+Wf;