kk=1,MECHN1=100,MECHN2=100,AREA=1,ALTITUDE=10668,MACH=0.82,RC=0.7,RF=0.4

   f_throttle=false;f_guess=0;f_trans =0;
   
   % A8ds =0; T1ds = 0; T2ds = 0;T3ds = 0;T4ds = 0;
   traditional=1;
    Wencha=[ ];
    XI=[0,0,0,0,0,0,0];
    XII=[0,0,0,0,0,0,0];
    Z=[0,0,0,0,0,0,0];
    initial;
    ondesign;
    %
    %%  ��������
%      XI=[0.19848,0.63160,86.76732,1270.95765,0.80077,291.57894,0.96782];
%     XI=[0.24599,0.55160,87.36732,1300.95765,0.80077,291.57894,0.5]; 
        XI=[0.09848,0.70408,90.38538,1433.99441,0.79837,290.36039,0.78649]; 
         MECHN1=82;
for i=1:8
    
    f_controlN1=true;
   
    N1=MECHN1;
    H=ALTITUDE;
    
 
    Ma=MACH;
    Areao=Areao*AREA;
     f_controlN2=0;%%������n2
   f_controlA=1;
%    f_guess=0;%%��ֵ
   
  fid = fopen('shiyan.txt','at+');
 fprintf(fid,'MECHN1=%8.2f\r\n',MECHN1);
 fprintf(fid,'��ʼ��ֵ=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7)); 
   fclose(fid);
 solve;
 f_guess=0;
 fid = fopen('shiyan.txt','at+');
 
 fprintf(fid,'�в�=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7));
 fprintf(fid,'����ȡֵ=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));%%��ӵ�
 fclose(fid);
  MECHN1=MECHN1-1;
end
  %%
  
%         fprintf(fid,'����         ������  ȼ������      ���⺭�����ٶȱ�  ������     N1     N2    SM1    SM2\r\n');  
%         fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f   %8.5f\r\n',Thrust,SFC,Wfb*3600.00,Von/Vo,BPR,N1,N2,SM1,SM2);  
%         fprintf(fid,'��������:\r\n');
%         fprintf(fid,'���ȣ���������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f\r\n',Wcorfan,PRfan,Efffan);
%         fprintf(fid,'��ѹ������������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f\r\n',Wcorboo,PRboo,Effboo);
%         fprintf(fid,'ѹ��������������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f\r\n',Wcorcomp,PRcomp,Effcomp);
%         fprintf(fid,'ȼ���ң�ȼ��Ч��=%5.5f  ��ѹ�ָ�ϵ��=%5.5f\r\n',Effb,DP);
%         fprintf(fid,'��ѹ���֣����ͱ�=%5.5f  Ч��=%5.5f  ���õ�λ��=%5.5f\r\n',PRKth,EffHT,THWork);
%         fprintf(fid,'��ѹ���֣����ͱ�=%5.5f  Ч��=%5.5f  ���õ�λ��=%5.5f\r\n',PRKtl,EffLT,TLWork);
%         fprintf(fid,'��ܣ��⺭���=%5.5f  �ں����=%5.5f\r\n',Aonoz, Areao);
%         fprintf(fid,'��������� ����       ��ѹ      ����\r\n');
%         fprintf(fid,'���������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tino,Pino,Wai);
%         fprintf(fid,'���ȳ��ڣ�%8.5f   %8.5f   %8.5f   %8.5f\r\n',Tfano,Pfano,Wbpo,Wcomp);
%         fprintf(fid,'��ѹ�����ڣ�%8.5f   %8.5f   %8.5f\r\n',Tboo,Pboo,Wboo);
%         fprintf(fid,'ѹ�������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomoi,Pcomo,Wcompout);
%         %fprintf(fid,'ѹ�������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomo,Pcomo,Wcompout);
%         fprintf(fid,'ȼ���ҳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tburno,Pburno,Wburno);
%         fprintf(fid,'��ѹ���ֳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Thto,Phto,Whto);
%         fprintf(fid,'��ѹ���ֳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tlto,Plto,Wlto);
%         fprintf(fid,'�⺭��ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tson,Pson,Von);
%         fprintf(fid,'�ں���ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tso,Pso,Vo);
%         fprintf(fid,'���ϵ����\r\n');
%         fprintf(fid,'���ȣ�����=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWfan,ScallEfffan,ScallPRfan);
%         fprintf(fid,'��ѹ��������=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWboo,ScallEffboo,ScallPRboo);
%         fprintf(fid,'ѹ����������=%5.5f   Ч��=%5.5f   ѹ��=%5.5f\r\n',ScallWcomp,ScallEffcomp,ScallPRcomp);
%         fprintf(fid,'������������\r\n');
%         fprintf(fid,'��������Ч��=%5.5f   �⺭ѹ��=%5.5f   �ں�ѹ��=%5.5f\r\n',ytz1,Deltp2,Deltp1);
%         fprintf(fid,'��=%5.5f   ��=%5.5f   ��=%5.5f      ����=%5.5f\r\n',L1,L2,L3,mcore1);
%         fprintf(fid,'��������Ч��=%5.5f   ѹ����ѹ��=%5.5f   ����ѹ��=%5.5f\r\n',ytz2,Deltp4,Deltp3);
%         fprintf(fid,'��=%5.5f   ��=%5.5f   ��=%5.5f      ����=%5.5f\r\n',L11,L22,L33,mcore2);
%         fprintf(fid,'����ѹ��=%5.5f\r\n',PRfan*PRboo*PRcomp);
%         fprintf(fid,'�⺭����=%5.5f  �ں�����=%5.5f\r\n',Thrust2/9.8,Thrust1/9.8);
%         fprintf(fid,'�⺭���ȳ����¶�=%5.5f   �⺭���ȳ�����ѹ=%5.5f   ��ѹ������ǰ��������=%5.5f    ��ѹ������ǰ������ѹ=%5.5f\r\n',Tfano,Pfano,Tboo1,Pboo1);
%         fprintf(fid,'����ǰ:ѹ���������¶�=%5.5f   ѹ����������ѹ=%5.5f   ��ѹ���ֳ�������=%5.5f    ��ѹ���ֳ�����ѹ=%5.5f\r\n',Tcomo1,Pcomo1,Tlto1,Plto1);
%         fprintf(fid,'�����������ѹ��=%5.5f    �Ȳ�ѹ��=%5.5f   �����������ѹ��=%5.5f    �Ȳ�ѹ��=%5.5f \r\n',Deltp2/Pfano,Deltp1/Pboo1,Deltp4/Pcomo1,Deltp3/Plto1);
%          fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f   %8.5f   %8.5f   %8.5f\r\n',Thrust2,Wonoz,Von,fai_m_dVo,W1,BPR,V,1+BPR,Pson,Pev,Aonoz);  
%         fclose(fid);

        
  