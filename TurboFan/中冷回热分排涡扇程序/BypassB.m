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
%   Hbpo=gashi(Tfano,0);%û�в��뻻�ȵĿ����¶ȵ���  
% if traditional==0%% ���˳���� ���������������
%     
%     Pbpo=((Pbpo-Deltp2)*Wbpo*icper+Pbpo*Wbpo*(1-icper))/Wbpo;%��Ϻ��ѹ��  ����ƽ�� icperΪ����ϵ��
%     
%     Hbpi=gashi(Tbpoi,0);%���뻻�Ⱥ�����¶ȵ���
%     Hbpj=(Hbpi*Wbpo*icper+Hbpo*Wbpo*(1-icper))/Wbpo;%ƽ������
%     ibp=0;%�����������
%     while abs(Hbpo-Hbpj)>1
%            ibp=ibp+1;
%            Tbpo=Tbpo+0.001;
%            Hbpo=gashi(Tbpo,0);
%            if ibp>=100000
%                error('�⺭�¶ȵ���������');
%                break;
%            end
%     end
%     
% end%%
%     
%     FARbp=0;