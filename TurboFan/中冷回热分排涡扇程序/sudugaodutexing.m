% function [ output_args ] =
% main(kk,MECHN1,MECHN2,AREA,ALTITUDE,MACH,RC,RF)
%MAIN Summary of this function goes here
%  Detailed explanation goes here

kk=1,MECHN1=100,MECHN2=100,AREA=1,ALTITUDE=10668,MACH=0.82,RC=0.7,RF=0.4,icper=1.0/13.5;

   f_throttle=false;f_guess=0;f_trans =0;
   
   % A8ds =0; T1ds = 0; T2ds = 0;T3ds = 0;T4ds = 0;
   traditional=0;
   f_bleedgas=0;
   
    XI=[0,0,0,0,0,0,0,0];
    XII=[0,0,0,0,0,0,0,0];
    Z=[0,0,0,0,0,0,0,0];
    initial;
    ondesign;
    %%
    fid = fopen('tanglaoshi.txt','at+');
 
        fprintf(fid,'��������� ��������       ��������      ������ѹ               ������ѹ         ѹ����ʧ      ����\r\n');
        fprintf(fid,'�������Ȳࣺ  %8.5f  %8.5f   %8.5f    %8.5f   %8.5f  %8.5f\r\n',Tboo1,Tboo, Pboo1,Pboo,Deltp1/Pboo1,Wboo);
        fprintf(fid,'��������ࣺ%8.5f   %8.5f  %8.5f   %8.5f      %8.5f   %8.5f\r\n',Tfano,Tbpoi,Pfano,Pfano-Deltp2,Deltp2/Pfano,icper* Wbpoo);
        fprintf(fid,'�������Ȳࣺ%8.5f   %8.5f  %8.5f   %8.5f      %8.5f   %8.5f\r\n', Tlto2,Tltoi,Plto2,Plto,Deltp3/Plto2,Wcompout);
        fprintf(fid,'��������ࣺ%8.5f   %8.5f  %8.5f   %8.5f      %8.5f   %8.5f\r\n',  Tcomo1,Tcomo, Pcomo1,Pcomo,Deltp4/Pcomo1,Wcompout);
        fprintf(fid,'ѹ����������ѹ�� %8.5f\r\n',Pcomo1);
        fprintf(fid,'�ߵ�ѹ�������ͱȣ�  %8.5f   %8.5f\r\n',PRKth,PRKtl);
        fprintf(fid,'T4��   %8.5f\r\n',Tburno);

        fprintf(fid,'����         ������        ���⺭�����ٶȱ�  ������     \r\n');  
        fprintf(fid,'%8.5f   %8.5f  %8.5f   %8.5f\r\n',Thrust,SFC,Von/Vo,BPR);  
   fprintf(fid,'�������뻻����Ч�ʣ�  %8.5f   %8.5f\r\n',ytz1,ytz2);
   
   
   
   
   fclose(fid);  
    %%
       %%  ��������
    XI=[0.22322,0.60131,89.0266,1327,0.80199,292.567,0.876,0.07186]; 
     MECHN1=100;
%         MECHN2=100;
%    XI=[0.5652,0.7466,105.518,1872,0.7985,291.52,0.716,0.0667];
    jiedian=1;
   for  MACH=0.0;  %0:0.05:0.5;
     ALTITUDE=0;
%          T0=T0+15;
    f_controlN1=true;
   
    N1=MECHN1
    H=ALTITUDE;
%     N2=MECHN2
 
    Ma=MACH;
    Areao=Areao*AREA;
     f_controlN2=0;%%������n2
   f_controlA=1;
   f_guess=1;%%��ֵ
   solve;
   
   ThruststrVel(jiedian)=Thrust;%%������
   SFCstrVel(jiedian)=SFC;
   jiedian=jiedian+1;
   end
   
    fid = fopen('tanglaoshi.txt','at+');
 
        fprintf(fid,'��������� ��������       ��������      ������ѹ               ������ѹ         ѹ����ʧ      ����\r\n');
        fprintf(fid,'�������Ȳࣺ  %8.5f  %8.5f   %8.5f    %8.5f   %8.5f  %8.5f\r\n',Tboo1,Tboo, Pboo1,Pboo,Deltp1/Pboo1,Wboo);
        fprintf(fid,'��������ࣺ%8.5f   %8.5f  %8.5f   %8.5f      %8.5f   %8.5f\r\n',Tfano,Tbpoi,Pfano,Pfano-Deltp2,Deltp2/Pfano,icper* Wbpoo);
        fprintf(fid,'�������Ȳࣺ%8.5f   %8.5f  %8.5f   %8.5f      %8.5f   %8.5f\r\n', Tlto2,Tltoi,Plto2,Plto,Deltp3/Plto2,Wcompout);
        fprintf(fid,'��������ࣺ%8.5f   %8.5f  %8.5f   %8.5f      %8.5f   %8.5f\r\n',  Tcomo1,Tcomo, Pcomo1,Pcomo,Deltp4/Pcomo1,Wcompout);
        fprintf(fid,'ѹ����������ѹ�� %8.5f\r\n',Pcomo1);
        fprintf(fid,'�ߵ�ѹ�������ͱȣ�  %8.5f   %8.5f\r\n',PRKth,PRKtl);
        fprintf(fid,'T4��   %8.5f\r\n',Tburno);

        fprintf(fid,'����         ������        ���⺭�����ٶȱ�  ������     \r\n');  
        fprintf(fid,'%8.5f   %8.5f  %8.5f   %8.5f\r\n',Thrust,SFC,Von/Vo,BPR);  
   
        fprintf(fid,'�������뻻����Ч�ʣ�  %8.5f   %8.5f\r\n',ytz1,ytz2);
   
   
   
   fclose(fid);  
   
   
   
   
   
   
   
   
   
    