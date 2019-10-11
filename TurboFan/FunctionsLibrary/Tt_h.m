function Tt=Tt_h(h,f)
a=0;
b=3000;
error=1;
while error>1e-12
    hguess=gashi((a+b)/2,f);
    error=abs((hguess-h)/h);
    Z=hguess-h;
    if Z>=0
        b=(a+b)/2;
    else
        a=(a+b)/2;
    end
end
Tt=(a+b)/2;
