%function [ output_args ] = ondesign( input_args )
%ONDESIGN Summary of this function goes here
%  Detailed explanation goes here

   
    f_guess=false;
    f_controlA=0;
	enginepath_guan;

	perform;
    
    
%     A8ds =Areao;
%     T1ds = Tino;
%     T2ds = Tfano;
% 	T3ds = Tcomo;
% 	T4ds = Tburno;
%    
%     f_design = false;%%���Ǽ���������Ƶ��Ժ󣬾ͽ����Ƿ���Ƶ�ļ��㣬��ʵ�����൱��һ��ָ��
% 	f_specifyN2 = true;%%%%%%%%%%%%%%%%%%��
% 	
%  
% 			
% 	Detah = -0.002;
	
	
    
    %cunru mubiaowenjian
    if traditional==0
        fid = fopen('design_guan.txt','wt+');
    else
        fid = fopen('traditiondesign1.txt','wt+'); 
    end
        fprintf(fid,'����         ������  ȼ������      ���⺭�����ٶȱ�  ������     N1     N2    SM1    SM2\r\n');  
        fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f   %8.5f\r\n',Thrust,SFC,Wfb*3600.00,Von/Vo,BPR,N1,N2,SM1,SM2);  
        fprintf(fid,'��������:\r\n');
        fprintf(fid,'���ȣ���������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f\r\n',Wcorfan,PRfan,Efffan);
        fprintf(fid,'��ѹ������������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f\r\n',Wcorboo,PRboo,Effboo);
        fprintf(fid,'ѹ��������������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f\r\n',Wcorcomp,PRcomp,Effcomp);
        fprintf(fid,'ȼ���ң�ȼ��Ч��=%5.5f  ��ѹ�ָ�ϵ��=%5.5f\r\n',Effb,DP);
        fprintf(fid,'��ѹ���֣����ͱ�=%5.5f  Ч��=%5.5f  ���õ�λ��=%5.5f\r\n',PRKth,EffHT,THWork);
        fprintf(fid,'��ѹ���֣����ͱ�=%5.5f  Ч��=%5.5f  ���õ�λ��=%5.5f\r\n',PRKtl,EffLT,TLWork);
        fprintf(fid,'��ܣ��⺭���=%5.5f  �����⺭���=%5.5f  �ں����=%5.5f\r\n',Aonoz,AonozB, Areao);
        fprintf(fid,'��������� ����       ��ѹ      ����\r\n');
        fprintf(fid,'���������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tino,Pino,Wai);
        fprintf(fid,'���ȳ��ڣ�%8.5f   %8.5f   %8.5f   %8.5f\r\n',Tfano,Pfano,Wbpo,Wcomp);
        fprintf(fid,'��ѹ�����ڣ�%8.5f   %8.5f   %8.5f\r\n',Tboo1,Pboo1,Wboo);
%         fprintf(fid,'ѹ�������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomoi,Pcomo,Wcompout);
        fprintf(fid,'���������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tboo,Pboo,Wboo);
        fprintf(fid,'ѹ�������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomo11,Pcomo11,Wcompout);
        fprintf(fid,'ȼ���ҽ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomo,Pcomo,Wcompout);
        fprintf(fid,'ȼ���ҳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tburno,Pburno,Wburno);
        fprintf(fid,'��ѹ���ֳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Thto,Phto,Whto);
        fprintf(fid,'��ѹ���ֳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tlto11,Plto11,Wlto);
        fprintf(fid,'�⺭��ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tson,Pson,Von);
         fprintf(fid,'�����⺭��ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',TsonB,PsonB,VonB);%%
        fprintf(fid,'�ں���ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tso,Pso,Vo);
        fprintf(fid,'���ϵ����\r\n');
        fprintf(fid,'���ȣ�����=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWfan,ScallEfffan,ScallPRfan);
        fprintf(fid,'��ѹ��������=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWboo,ScallEffboo,ScallPRboo);
        fprintf(fid,'ѹ����������=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWcomp,ScallEffcomp,ScallPRcomp);
        fprintf(fid,'������������\r\n');
        if traditional==0
       fprintf(fid,'��������  �⺭ѹ��=%5.5f   �ں�ѹ��=%5.5f\r\n',Deltp1,Deltp2);
     % fprintf(fid,'��=%5.5f   ��=%5.5f   ��=%5.5f      ����=%5.5f\r\n',L1,L2,L3,mcore1);
        fprintf(fid,'��������  ѹ����ѹ��=%5.5f   ����ѹ��=%5.5f\r\n',Deltp3,Deltp4);
      %  fprintf(fid,'��=%5.5f   ��=%5.5f   ��=%5.5f      ����=%5.5f\r\n',L11,L22,L33,mcore2);
      fprintf(fid,'�����������Ч��=%5.5f ��Ч��=%5.5f  �Ȳ�Ч��=%5.5f\r\n',youxd1,zyxd1,youxd2);
      fprintf(fid,'�����������Ч��=%5.5f  ��Ч��=%5.5f  �Ȳ�Ч��=%5.5f\r\n',youxd3,zyxd2,youxd4);
        end
        fprintf(fid,'����������; %5.5f  %5.5f  %5.5f  %5.5f\r\n',mass1,mass2,mass3,mass4);
        fprintf(fid,'����ѹ��=%5.5f\r\n',PRfan*PRboo*PRcomp);
        fprintf(fid,'�⺭����=%5.5f  �����⺭����=%5.5f  �ں�����=%5.5f\r\n',Thrust2/9.8,Thrust3/9.8,Thrust1/9.8);
        fprintf(fid,'�⺭����=%8.5f �����⺭����=%8.5f  �ں�����=%8.5f\r\n',Wbpo,WbpBo,Wcnoz);
        if traditional==0
        fprintf(fid,'�⺭���ȳ����¶�=%5.5f   �⺭���ȳ�����ѹ=%5.5f   ��ѹ������ǰ��������=%5.5f    ��ѹ������ǰ������ѹ=%5.5f\r\n',Tfano,Pfano,Tboo1,Pboo1);
        fprintf(fid,'����ǰ:ѹ���������¶�=%5.5f   ѹ����������ѹ=%5.5f   ��ѹ���ֳ�������=%5.5f    ��ѹ���ֳ�����ѹ=%5.5f\r\n',Tcomo1,Pcomo1,Tlto1,Plto1);
        fprintf(fid,'�����������ѹ��=%5.5f    �Ȳ�ѹ��=%5.5f   �����������ѹ��=%5.5f    �Ȳ�ѹ��=%5.5f \r\n',Deltp1/Pfano,Deltp2/Pboo1,Deltp3/Pcomo11,Deltp4/Plto11);
         fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f   %8.5f   %8.5f   %8.5f\r\n',Thrust2,Wonoz,Von,fai_m_dVo,W1,BPR,V,1+BPR,Pson,Pev,Aonoz);  
        end
        fclose(fid);
        
        
   
	
	
  

