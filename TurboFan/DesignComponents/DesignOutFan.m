function [Pt_out,Tt_out,OutFanWork]=DesignOutFan(Pt_in,Tt_in,W_in,DesignData_OutFan)
d_OutFan_PR=DesignData_OutFan(1);
d_OutFan_Eff=DesignData_OutFan(2);
Pt_out=Pt_in*d_OutFan_PR;
Tt_out=GasTt(Tt_in,0,d_OutFan_PR,d_OutFan_Eff);
OutFanWork=W_in*(gashi(Tt_out,0)-gashi(Tt_in,0));