function [Pt_out,Tt_out,W_out,BoosterWork]=DesignBooster(Pt_in,Tt_in,W_in,DesignData_Booster)
d_Booster_PR=DesignData_Booster(1);
d_Booster_Eff=DesignData_Booster(2);
Pt_out=Pt_in*d_Booster_PR;
Tt_out=GasTt(Tt_in,0,d_Booster_PR,d_Booster_Eff);
W_out=W_in;
BoosterWork=W_in*(gashi(Tt_out,0)-gashi(Tt_in,0));