%function [Tbpo,Tbpos,Pbpos,Pbpo ] = Bypass(BypassDPds,Abpo,Mabpo,BPR,lamdagussbp)
%BYPASS Summary of this function goes here
%  Detailed explanation goes here



 %[ Tfano,Pfano,Hfano,Nfan,Wfano,KFanWork ] = fan( 0.75,0.15 );
   
 
%   BypassBDPds=0.03;
    
	if Wfano<=0.0  
        Wfano = 1.0e-4;
    end
    WbpBo =  icper*Wbpoo;
	TbpBo = Tbpoi;
    PbpBo=Pfano-Deltp1;
%     if f_design 
%         WbpBocords=WbpBo*sqrt(Tfano)/Pfano;	%ondesign huansuan liuliang
%     end
%     DP = BypassBDPds*(WbpBo*sqrt(Tfano)/Pfano/WbpBocords);%press loss
% 	if DP>1.0 
%         DP = 1.0;
%     end
%    PbpBo= PbpBo*(1.0-DP);
    HbpBo=gashi(TbpBo,0);
    FARbpB=0;
    
%     %out Tt
% 	%Hbpo = Hfano;
% 	%%Wbpo = Wfano*BPR/(1+BPR);
%     
%     
% 	if f_design 
%         Wbpocords=Wbpo*sqrt(Tfano)/Pfano;	%ondesign huansuan liuliang
%     end
% 
% 	  DP = BypassDPds*(Wbpo*sqrt(Tfano)/Pfano/Wbpocords);%press loss
% 	if DP>1.0 
%         DP = 1.0;
%     end
% 	Pbpo= Pfano*(1.0-DP); %out Pt
%   Hbpo=gashi(Tfano,0);%没有参与换热的空气温度的焓  
% if traditional==0%% 宋兴超添加 用做计算中冷回热
%     
%     Pbpo=((Pbpo-Deltp2)*Wbpo*icper+Pbpo*Wbpo*(1-icper))/Wbpo;%混合后的压力  质量平均 icper为引气系数
%     
%     Hbpi=gashi(Tbpoi,0);%参与换热后空气温度的焓
%     Hbpj=(Hbpi*Wbpo*icper+Hbpo*Wbpo*(1-icper))/Wbpo;%平均的焓
%     ibp=0;%计算迭代步数
%     while abs(Hbpo-Hbpj)>1
%            ibp=ibp+1;
%            Tbpo=Tbpo+0.001;
%            Hbpo=gashi(Tbpo,0);
%            if ibp>=100000
%                error('外涵温度迭代步收敛');
%                break;
%            end
%     end
%     
% end%%
%     
%     FARbp=0;