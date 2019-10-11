%function [ output_args ] = ondesign( input_args )
%ONDESIGN Summary of this function goes here
%  Detailed explanation goes here

   
    f_guess=false;
    f_controlA=0;
	enginepath;

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
        fid = fopen('design1.txt','wt+');
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
        if traditional==0
        fprintf(fid,'��ܣ��⺭���=%5.5f  �����⺭���=%5.5f  �ں����=%5.5f\r\n',Aonoz,AonozB, Areao);
        else
        fprintf(fid,'��ܣ��⺭���=%5.5f  �ں����=%5.5f\r\n',Aonoz,Areao);
        end
        fprintf(fid,'��������� ����       ��ѹ      ����\r\n');
        fprintf(fid,'���������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tino,Pino,Wai);
        fprintf(fid,'���ȳ��ڣ�%8.5f   %8.5f   %8.5f   %8.5f\r\n',Tfano,Pfano,Wbpo,Wcomp);
        fprintf(fid,'��ѹ�����ڣ�%8.5f   %8.5f   %8.5f\r\n',Tboo1,Pboo1,Wboo);
%         fprintf(fid,'ѹ�������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomoi,Pcomo,Wcompout);
         fprintf(fid,'���������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tboo,Pboo,Wboo);
        fprintf(fid,'ѹ�������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomo1,Pcomo1,Wcompout);
        fprintf(fid,'ȼ���ҽ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomo,Pcomo,Wcompout);
        fprintf(fid,'ȼ���ҳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tburno,Pburno,Wburno);
        fprintf(fid,'��ѹ���ֳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Thto,Phto,Whto);
        fprintf(fid,'��ѹ���ֳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tlto1,Plto1,Wlto);
        fprintf(fid,'�⺭��ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tson,Pson,Von);
        if traditional==0
         fprintf(fid,'�����⺭��ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',TsonB,PsonB,VonB);%%
        end
        fprintf(fid,'�ں���ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tso,Pso,Vo);
        fprintf(fid,'���ϵ����\r\n');
        fprintf(fid,'���ȣ�����=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWfan,ScallEfffan,ScallPRfan);
        fprintf(fid,'��ѹ��������=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWboo,ScallEffboo,ScallPRboo);
        fprintf(fid,'ѹ����������=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWcomp,ScallEffcomp,ScallPRcomp);
        fprintf(fid,'������������\r\n');
        if traditional==0
        fprintf(fid,'��������Ч��=%5.5f   �⺭ѹ��=%5.5f   �ں�ѹ��=%5.5f\r\n',ytz1,Deltp2,Deltp1);
        fprintf(fid,'��=%5.5f   ��=%5.5f   ��=%5.5f      ����=%5.5f\r\n',L1,L2,L3,mcore1);
        fprintf(fid,'��������Ч��=%5.5f   ѹ����ѹ��=%5.5f   ����ѹ��=%5.5f\r\n',ytz2,Deltp4,Deltp3);
        fprintf(fid,'��=%5.5f   ��=%5.5f   ��=%5.5f      ����=%5.5f\r\n',L11,L22,L33,mcore2);
      
        fprintf(fid,'����ѹ��=%5.5f\r\n',PRfan*PRboo*PRcomp);
        fprintf(fid,'�⺭����=%5.5f  �����⺭����=%5.5f  �ں�����=%5.5f\r\n',Thrust2/9.8,Thrust3/9.8,Thrust1/9.8);
        fprintf(fid,'�⺭����=%8.5f �����⺭����=%8.5f  �ں�����=%8.5f\r\n',Wbpo,WbpBo,Wcnoz);
        else
        fprintf(fid,'����ѹ��=%5.5f\r\n',PRfan*PRboo*PRcomp);
        fprintf(fid,'�⺭����=%5.5f  �ں�����=%5.5f\r\n',Thrust2/9.8,Thrust1/9.8);
        fprintf(fid,'�⺭����=%8.5f  �ں�����=%8.5f\r\n',Wbpo,Wcnoz);
        end
        if traditional==0
        fprintf(fid,'�⺭���ȳ����¶�=%5.5f   �⺭���ȳ�����ѹ=%5.5f   ��ѹ������ǰ��������=%5.5f    ��ѹ������ǰ������ѹ=%5.5f\r\n',Tfano,Pfano,Tboo1,Pboo1);
        fprintf(fid,'����ǰ:ѹ���������¶�=%5.5f   ѹ����������ѹ=%5.5f   ��ѹ���ֳ�������=%5.5f    ��ѹ���ֳ�����ѹ=%5.5f\r\n',Tcomo1,Pcomo1,Tlto1,Plto1);
        fprintf(fid,'�����������ѹ��=%5.5f    �Ȳ�ѹ��=%5.5f   �����������ѹ��=%5.5f    �Ȳ�ѹ��=%5.5f \r\n',Deltp2/Pfano,Deltp1/Pboo1,Deltp4/Pcomo1,Deltp3/Plto11);
         fprintf(fid,'�⺭������=%8.5f   �⺭������=%8.5f   �⺭�ٶ�=%8.5f   %8.5f   %8.5f   ������=%8.5f   �⺭�ٶ�=%8.5f  %8.5f   ��ѹ=%8.5f   ����ѹ��=%8.5f   �⺭������=%8.5f\r\n',Thrust2,Wonoz,Von,fai_m_dVo,W1,BPR,V,1+BPR,Pson,Pev,Aonoz);  
        end
        fclose(fid);
        
        
   
	
	
  

