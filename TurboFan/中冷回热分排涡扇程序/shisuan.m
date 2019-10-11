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
    %%  单点试算
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
     f_controlN2=0;%%不控制n2
   f_controlA=1;
%    f_guess=0;%%猜值
   
  fid = fopen('shiyan.txt','at+');
 fprintf(fid,'MECHN1=%8.2f\r\n',MECHN1);
 fprintf(fid,'初始猜值=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7)); 
   fclose(fid);
 solve;
 f_guess=0;
 fid = fopen('shiyan.txt','at+');
 
 fprintf(fid,'残差=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7));
 fprintf(fid,'最终取值=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));%%后加的
 fclose(fid);
  MECHN1=MECHN1-1;
end
  %%
  
%         fprintf(fid,'推力         耗油率  燃油流量      内外涵出口速度比  涵道比     N1     N2    SM1    SM2\r\n');  
%         fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f   %8.5f\r\n',Thrust,SFC,Wfb*3600.00,Von/Vo,BPR,N1,N2,SM1,SM2);  
%         fprintf(fid,'部件参数:\r\n');
%         fprintf(fid,'风扇：换算流量=%8.5f  压比=%8.5f  效率=%8.5f\r\n',Wcorfan,PRfan,Efffan);
%         fprintf(fid,'增压级：换算流量=%8.5f  压比=%8.5f  效率=%8.5f\r\n',Wcorboo,PRboo,Effboo);
%         fprintf(fid,'压气机：换算流量=%8.5f  压比=%8.5f  效率=%8.5f\r\n',Wcorcomp,PRcomp,Effcomp);
%         fprintf(fid,'燃烧室：燃烧效率=%5.5f  总压恢复系数=%5.5f\r\n',Effb,DP);
%         fprintf(fid,'高压涡轮：膨胀比=%5.5f  效率=%5.5f  需用单位功=%5.5f\r\n',PRKth,EffHT,THWork);
%         fprintf(fid,'低压涡轮：膨胀比=%5.5f  效率=%5.5f  需用单位功=%5.5f\r\n',PRKtl,EffLT,TLWork);
%         fprintf(fid,'喷管：外涵面积=%5.5f  内涵面积=%5.5f\r\n',Aonoz, Areao);
%         fprintf(fid,'截面参数： 总温       总压      流量\r\n');
%         fprintf(fid,'进气道出口：%8.5f   %8.5f   %8.5f\r\n',Tino,Pino,Wai);
%         fprintf(fid,'风扇出口：%8.5f   %8.5f   %8.5f   %8.5f\r\n',Tfano,Pfano,Wbpo,Wcomp);
%         fprintf(fid,'增压级出口：%8.5f   %8.5f   %8.5f\r\n',Tboo,Pboo,Wboo);
%         fprintf(fid,'压气机出口：%8.5f   %8.5f   %8.5f\r\n',Tcomoi,Pcomo,Wcompout);
%         %fprintf(fid,'压气机出口：%8.5f   %8.5f   %8.5f\r\n',Tcomo,Pcomo,Wcompout);
%         fprintf(fid,'燃烧室出口：%8.5f   %8.5f   %8.5f\r\n',Tburno,Pburno,Wburno);
%         fprintf(fid,'高压涡轮出口：%8.5f   %8.5f   %8.5f\r\n',Thto,Phto,Whto);
%         fprintf(fid,'低压涡轮出口：%8.5f   %8.5f   %8.5f\r\n',Tlto,Plto,Wlto);
%         fprintf(fid,'外涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',Tson,Pson,Von);
%         fprintf(fid,'内涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',Tso,Pso,Vo);
%         fprintf(fid,'耦合系数：\r\n');
%         fprintf(fid,'风扇：流量=%5.5f   效率=%5.5f   压比=%5.5f\r\n',ScallWfan,ScallEfffan,ScallPRfan);
%         fprintf(fid,'增压级：流量=%5.5f   效率=%5.5f   压比=%5.5f\r\n',ScallWboo,ScallEffboo,ScallPRboo);
%         fprintf(fid,'压气机：流量=%5.5f   效率=%5.5f   压比=%5.5f\r\n',ScallWcomp,ScallEffcomp,ScallPRcomp);
%         fprintf(fid,'换热器参数：\r\n');
%         fprintf(fid,'中冷器：效率=%5.5f   外涵压降=%5.5f   内涵压降=%5.5f\r\n',ytz1,Deltp2,Deltp1);
%         fprintf(fid,'长=%5.5f   宽=%5.5f   高=%5.5f      重量=%5.5f\r\n',L1,L2,L3,mcore1);
%         fprintf(fid,'回热器：效率=%5.5f   压气机压降=%5.5f   涡轮压降=%5.5f\r\n',ytz2,Deltp4,Deltp3);
%         fprintf(fid,'长=%5.5f   宽=%5.5f   高=%5.5f      重量=%5.5f\r\n',L11,L22,L33,mcore2);
%         fprintf(fid,'总增压比=%5.5f\r\n',PRfan*PRboo*PRcomp);
%         fprintf(fid,'外涵推力=%5.5f  内涵推力=%5.5f\r\n',Thrust2/9.8,Thrust1/9.8);
%         fprintf(fid,'外涵风扇出口温度=%5.5f   外涵风扇出口总压=%5.5f   增压级换热前出口总温=%5.5f    增压级换热前出口总压=%5.5f\r\n',Tfano,Pfano,Tboo1,Pboo1);
%         fprintf(fid,'换热前:压气机出口温度=%5.5f   压气机出口总压=%5.5f   低压涡轮出口总温=%5.5f    低压涡轮出口总压=%5.5f\r\n',Tcomo1,Pcomo1,Tlto1,Plto1);
%         fprintf(fid,'中冷器：冷侧压降=%5.5f    热侧压降=%5.5f   回热器：冷侧压降=%5.5f    热侧压降=%5.5f \r\n',Deltp2/Pfano,Deltp1/Pboo1,Deltp4/Pcomo1,Deltp3/Plto1);
%          fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f   %8.5f   %8.5f   %8.5f\r\n',Thrust2,Wonoz,Von,fai_m_dVo,W1,BPR,V,1+BPR,Pson,Pev,Aonoz);  
%         fclose(fid);

        
  