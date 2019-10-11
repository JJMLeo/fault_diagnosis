function [Pt_out,Tt_out,InFanWork]=DesignInFan(Pt_in,Tt_in,W_in,DesignData_InFan)
d_InFan_PR=DesignData_InFan(1);
d_InFan_Eff=DesignData_InFan(2);
Pt_out=Pt_in*d_InFan_PR;
Tt_out=GasTt(Tt_in,0,d_InFan_PR,d_InFan_Eff);
InFanWork=W_in*(gashi(Tt_out,0)-gashi(Tt_in,0));