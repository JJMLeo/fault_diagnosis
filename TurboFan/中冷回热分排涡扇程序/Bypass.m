%function [Tbpo,Tbpos,Pbpos,Pbpo ] = Bypass(BypassDPds,Abpo,Mabpo,BPR,lamdagussbp)
%BYPASS Summary of this function goes here
%  Detailed explanation goes here



 %[ Tfano,Pfano,Hfano,Nfan,Wfano,KFanWork ] = fan( 0.75,0.15 );
   
  if traditional==0 
 Wbpo=Wbpoo*(1- icper);%%Wbpoo是两个外涵流量的总和，Wbpo是最外涵的流量，Wbpoo在booster.m里
  else
      Wbpo=Wbpoo;
  end
	if Wfano<=0.0  
        Wfano = 1.0e-4;
    end
    
	Tbpo = Tfano;	%out Tt
	%Hbpo = Hfano;
	%%Wbpo = Wfano*BPR/(1+BPR);
    
    
	if f_design 
        Wbpocords=Wbpo*sqrt(Tfano)/Pfano;	%ondesign huansuan liuliang
    end

	  DP = BypassDPds*(Wbpo*sqrt(Tfano)/Pfano/Wbpocords);%press loss
	if DP>1.0 
        DP = 1.0;
    end
	Pbpo= Pfano*(1.0-DP); %out Pt
  Hbpo=gashi(Tfano,0);%没有参与换热的空气温度的焓  
  %%
% % if traditional==0%% 宋兴超添加 用做计算中冷回热
% %     
% %     Pbpo=((Pbpo-Deltp2)*Wbpo*icper+Pbpo*Wbpo*(1-icper))/Wbpo;%混合后的压力  质量平均 icper为引气系数
% %     
% %     Hbpi=gashi(Tbpoi,0);%参与换热后空气温度的焓
% %     Hbpj=(Hbpi*Wbpo*icper+Hbpo*Wbpo*(1-icper))/Wbpo;%平均的焓
% %     ibp=0;%计算迭代步数
% %     while abs(Hbpo-Hbpj)>1
% %            ibp=ibp+1;
% %            Tbpo=Tbpo+0.001;
% %            Hbpo=gashi(Tbpo,0);
% %            if ibp>=100000
% %                error('外涵温度迭代步收敛');
% %                break;
% %            end
% %     end
% %     
% % end%%
 
    FARbp=0;
    
    %% 三喷管的中间放气
    if   f_bleedgas==1;
    Wbpo1=Wbpo;
    Wbpo2=Wboo*Gasbleed;
    Wbpo=Wbpo1+Wbpo2;
    Pbpo=(Pbpo*Wbpo1+Pboo*Wbpo2)/Wbpo;%混合后的压力  质量平均 icper为引气系数
    
    Hboo1 =gashi(Tboo1,0);
    Hbpav=(Hbpo*Wbpo1+Hboo1*Wbpo2)/Wbpo;%平均的焓
    ibp=0;%计算迭代步数
    while abs(Hbpo-Hbpav)>1
           ibp=ibp+1;
           Tbpo=Tbpo+0.001;
           Hbpo=gashi(Tbpo,0);
           if ibp>=100000
               error('外涵放气后温度迭代步收敛');
               break;
           end
    end
    
    end   
    
    
    
    
    
    
    
    
    
    
    