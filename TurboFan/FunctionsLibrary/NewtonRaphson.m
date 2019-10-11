function [norm_e0,Wf,ZC,ZGT,ZPT,N,NP]= NewtonRaphson(e0,e1,e2,e3,e4,Wfnew,ZCnew,ZGTnew,ZPTnew,Nnew,NPnew)
norm_e0=norm(e0);
if norm_e0<1e-7
    Wf=Wfnew;
    ZC=ZCnew;
    ZGT=ZGTnew;
    ZPT=ZPTnew;
    N=Nnew;
    NP=NPnew;
else
    E=[e1';e2';e3';e4']';
    A=zeros(4,4);
    Stream_in=[Wfnew,ZCnew,ZGTnew,ZPTnew];
    for j=1:4
        for i=1:4
            A(i,j)=(E(i,j)-e0(i))/(Stream_in(j)*(1e-3));
        end
    end
    Stream_out=[Wfnew,ZCnew,ZGTnew,ZPTnew]'-inv(A)*e0;
    Wf=Stream_out(1);
    ZC=Stream_out(2);
    ZGT=Stream_out(3);
    ZPT=Stream_out(4);
    N=Nnew;
    NP=NPnew;
end
