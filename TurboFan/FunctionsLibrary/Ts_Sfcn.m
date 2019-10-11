function Ts=Ts_Sfcn(Sfcn)
f=0;
a=0;
b=3000;
error=1;
while error>=1e-9
    SfcnGuess=Sfcn_Ts(f,(a+b)/2);
    Z=SfcnGuess-Sfcn;
    error=abs((SfcnGuess-Sfcn)/Sfcn);
    if Z>0
        b=(a+b)/2;
    else
        a=(a+b)/2;
    end
end
Ts=(a+b)/2;