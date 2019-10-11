function PR=PR_Tt(Tt_in,Tt_out,f,Eff)
a=0;
b=20;
Step=0;
error=1;
while error>1e-9
[~,kg,~]=gasstate(Tt_in,f,(a+b)/2,Eff);
Tt_outGuess=((((a+b)/2)^((kg-1)/kg)-1)/Eff+1)*Tt_in;
    Z=Tt_outGuess-Tt_out;
    if Z>=0
        b=(a+b)/2;
    else
        a=(a+b)/2;
    end
        Step=Step+1;
    if Step>=50
        break
    end
end
PR=(a+b)/2;
