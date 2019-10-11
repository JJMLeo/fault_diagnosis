function Tt_out=GasTt(Tt_in,f,ComprPR,ComprEff)
[~,kg,~]=gasstate(Tt_in,f,ComprPR,ComprEff);
Tt_out=((ComprPR^((kg-1)/kg)-1)/ComprEff+1)*Tt_in;