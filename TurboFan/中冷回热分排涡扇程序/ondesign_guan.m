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
%     f_design = false;%%这是计算完了设计点以后，就接着是非设计点的计算，这实际上相当于一个指针
% 	f_specifyN2 = true;%%%%%%%%%%%%%%%%%%？
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
        fprintf(fid,'推力         耗油率  燃油流量      内外涵出口速度比  涵道比     N1     N2    SM1    SM2\r\n');  
        fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f   %8.5f\r\n',Thrust,SFC,Wfb*3600.00,Von/Vo,BPR,N1,N2,SM1,SM2);  
        fprintf(fid,'部件参数:\r\n');
        fprintf(fid,'风扇：换算流量=%8.5f  压比=%8.5f  效率=%8.5f\r\n',Wcorfan,PRfan,Efffan);
        fprintf(fid,'增压级：换算流量=%8.5f  压比=%8.5f  效率=%8.5f\r\n',Wcorboo,PRboo,Effboo);
        fprintf(fid,'压气机：换算流量=%8.5f  压比=%8.5f  效率=%8.5f\r\n',Wcorcomp,PRcomp,Effcomp);
        fprintf(fid,'燃烧室：燃烧效率=%5.5f  总压恢复系数=%5.5f\r\n',Effb,DP);
        fprintf(fid,'高压涡轮：膨胀比=%5.5f  效率=%5.5f  需用单位功=%5.5f\r\n',PRKth,EffHT,THWork);
        fprintf(fid,'低压涡轮：膨胀比=%5.5f  效率=%5.5f  需用单位功=%5.5f\r\n',PRKtl,EffLT,TLWork);
        fprintf(fid,'喷管：外涵面积=%5.5f  中冷外涵面积=%5.5f  内涵面积=%5.5f\r\n',Aonoz,AonozB, Areao);
        fprintf(fid,'截面参数： 总温       总压      流量\r\n');
        fprintf(fid,'进气道出口：%8.5f   %8.5f   %8.5f\r\n',Tino,Pino,Wai);
        fprintf(fid,'风扇出口：%8.5f   %8.5f   %8.5f   %8.5f\r\n',Tfano,Pfano,Wbpo,Wcomp);
        fprintf(fid,'增压级出口：%8.5f   %8.5f   %8.5f\r\n',Tboo1,Pboo1,Wboo);
%         fprintf(fid,'压气机出口：%8.5f   %8.5f   %8.5f\r\n',Tcomoi,Pcomo,Wcompout);
        fprintf(fid,'中冷器出口：%8.5f   %8.5f   %8.5f\r\n',Tboo,Pboo,Wboo);
        fprintf(fid,'压气机出口：%8.5f   %8.5f   %8.5f\r\n',Tcomo11,Pcomo11,Wcompout);
        fprintf(fid,'燃烧室进口：%8.5f   %8.5f   %8.5f\r\n',Tcomo,Pcomo,Wcompout);
        fprintf(fid,'燃烧室出口：%8.5f   %8.5f   %8.5f\r\n',Tburno,Pburno,Wburno);
        fprintf(fid,'高压涡轮出口：%8.5f   %8.5f   %8.5f\r\n',Thto,Phto,Whto);
        fprintf(fid,'低压涡轮出口：%8.5f   %8.5f   %8.5f\r\n',Tlto11,Plto11,Wlto);
        fprintf(fid,'外涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',Tson,Pson,Von);
         fprintf(fid,'中冷外涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',TsonB,PsonB,VonB);%%
        fprintf(fid,'内涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',Tso,Pso,Vo);
        fprintf(fid,'耦合系数：\r\n');
        fprintf(fid,'风扇：流量=%5.5f   效率=%5.5f   压比=%5.5f\r\n',ScallWfan,ScallEfffan,ScallPRfan);
        fprintf(fid,'增压级：流量=%5.5f   效率=%5.5f   压比=%5.5f\r\n',ScallWboo,ScallEffboo,ScallPRboo);
        fprintf(fid,'压气机：流量=%5.5f   效率=%5.5f   压比=%5.5f\r\n',ScallWcomp,ScallEffcomp,ScallPRcomp);
        fprintf(fid,'换热器参数：\r\n');
        if traditional==0
       fprintf(fid,'中冷器：  外涵压降=%5.5f   内涵压降=%5.5f\r\n',Deltp1,Deltp2);
     % fprintf(fid,'长=%5.5f   宽=%5.5f   高=%5.5f      重量=%5.5f\r\n',L1,L2,L3,mcore1);
        fprintf(fid,'回热器：  压气机压降=%5.5f   涡轮压降=%5.5f\r\n',Deltp3,Deltp4);
      %  fprintf(fid,'长=%5.5f   宽=%5.5f   高=%5.5f      重量=%5.5f\r\n',L11,L22,L33,mcore2);
      fprintf(fid,'中冷器：冷侧效率=%5.5f 总效率=%5.5f  热侧效率=%5.5f\r\n',youxd1,zyxd1,youxd2);
      fprintf(fid,'回热器：冷侧效率=%5.5f  总效率=%5.5f  热侧效率=%5.5f\r\n',youxd3,zyxd2,youxd4);
        end
        fprintf(fid,'换热器质量; %5.5f  %5.5f  %5.5f  %5.5f\r\n',mass1,mass2,mass3,mass4);
        fprintf(fid,'总增压比=%5.5f\r\n',PRfan*PRboo*PRcomp);
        fprintf(fid,'外涵推力=%5.5f  中冷外涵推力=%5.5f  内涵推力=%5.5f\r\n',Thrust2/9.8,Thrust3/9.8,Thrust1/9.8);
        fprintf(fid,'外涵流量=%8.5f 中冷外涵流量=%8.5f  内涵流量=%8.5f\r\n',Wbpo,WbpBo,Wcnoz);
        if traditional==0
        fprintf(fid,'外涵风扇出口温度=%5.5f   外涵风扇出口总压=%5.5f   增压级换热前出口总温=%5.5f    增压级换热前出口总压=%5.5f\r\n',Tfano,Pfano,Tboo1,Pboo1);
        fprintf(fid,'换热前:压气机出口温度=%5.5f   压气机出口总压=%5.5f   低压涡轮出口总温=%5.5f    低压涡轮出口总压=%5.5f\r\n',Tcomo1,Pcomo1,Tlto1,Plto1);
        fprintf(fid,'中冷器：冷侧压降=%5.5f    热侧压降=%5.5f   回热器：冷侧压降=%5.5f    热侧压降=%5.5f \r\n',Deltp1/Pfano,Deltp2/Pboo1,Deltp3/Pcomo11,Deltp4/Plto11);
         fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f   %8.5f   %8.5f   %8.5f\r\n',Thrust2,Wonoz,Von,fai_m_dVo,W1,BPR,V,1+BPR,Pson,Pev,Aonoz);  
        end
        fclose(fid);
        
        
   
	
	
  

