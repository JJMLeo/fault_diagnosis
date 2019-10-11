%    h=[1,1,1,1,1,1,1]*Detah;%%Detah=-0.002
%    Deta=[0,0,0,0,0,0,0];
% 	S=30;%%迭代次数限制
% 	t = 0.5;
% 	l = S;
% 	eps =3.0e-3;
% 	n =7;
% 	%%am = 1.0+eps;
% 	Teps = 100.0;
%     
%      offdesign;
%      enginepath;
%      c=XI;
%      %%
%       b=Z;%%残差
% 		am = 0.0;
% 		for i=1:7%%这是找残差最大的哪一个赋给am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
%      %%  后加的
%      
%   fid = fopen('jieliu.txt','at+');
%    fprintf(fid,'MECHN1=%8.2f\r\n',MECHN1);
%  fprintf(fid,'初始猜值=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));
%  fclose(fid);    
%  %%
%  steps=0;
% while am>=eps%%这个am还是第k次的
% 
%        steps=steps+1;   
% %           if steps>30
% %              
% %               break; 
% %           end	
% %%
% %         b=Z;%%残差
% % 		am = 0.0;
% % 		for i=1:7%%这是找残差最大的哪一个赋给am
% %      		z = abs(b(i));
% % 			if z>am
% %                 am = z;
% %             end
% %         end
% %%
% 		
% 		if am>=eps
% 		
% 		       l = l-1;
% 			if Teps>am	%%而Teps是临时保存最小的残差值
%               if f_controlN1
% 				 Temp= XI;  %%这个是运行过程中临时保存最优的那个解
%                  time=steps;
%               else
%                  Temp= XII;
%                end
% 				Teps = am;
%             else 
%                 h=h*t; %%这个表示如果第K+1次的残差更大的化 就减小步长    
%             end
%             %%
%             
% % 			if l==0	
% %                 
% % 				if Teps<0.01
% %                     if f_controlN1
% % 					   XI= Temp;
% %                    else
% %                        XII=Temp;
% %                     end
% % 					 jinsijie=1;
% %                     shoulian=false;
% %                     break;
% %                 end
% %                 jie=0;
% %                 shoulian=false;
% %               break;
% %             end
%             %% 以上改成如下
%             if l==0	
%                 
% 				
%                     if f_controlN1
% 					   XI= Temp;
%                    else
%                        XII=Temp;
%                     end
%                     if Teps<0.01
% 					 jinsijie=1;
%                     else
%                     jie=0;
%                    shoulian=false;
%  
%                    end
%              break;
%         end
%    
%         end
%         if f_controlN1
%             for j=1:7%%这是求雅克比矩阵
% 		      c = XI(j); 
%               XI(j) = XI(j)+h(j)*c;
% 			  offdesign;
%               enginepath;
% 			   for m=1:7
%                   Jac(m,j) = (Z(m)-b(m))/(h(j)*c);
%                end
% 			  XI(j) = c;%%这里是表示XI(j)还是初始值
%             end
% % 			 offdesign;%%是不是应该加上啊
% %              enginepath;
%              y=Jac\b';%%\Z'反斜杠是Z'是Z的矩阵转置%%前面的Z是不是应该重新计算呢，因为Z应该是第k步的值
%              y=y';
% 
% 			for q=1:7				
% 				r=abs(y(q)/XI(q));
% 			    if y(q)~=0
%                     s=y(q)/abs(y(q));
%                 else
%                     s=0;
%                 end
% 				if r>0.10 
%                     r=0.10;
%                 end                    
% 				y(q)=XI(q)*r*s;
%                 y(q);
% 				d = Deta(q)+y(q);%%
%                 Deta(q);
%                 
% 				if (abs(Deta(q)>1.0e-4) & (abs(d)<=1.0e-5))
%                     w=rand(1)*(10.0-0.0)+0.0;%%0到10之间随即数
%                     XI(q) = XI(q)-w/20.0*y(q);
% 				else
%                     XI(q) = XI(q)-y(q);
%                 end
% 				Deta(q) = y(q);
%             end
%         end
% 
%             offdesign;
%             enginepath;
%            
%             XI;
%             Z;
%             %% 后加的
%              b=Z;%%残差
% 		am = 0.0;
% 		for i=1:7%%这是找残差最大的哪一个赋给am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
%         %%
%             
% %            	p = S-l;
% 	jingquejie=1;
% % 	Teps=am;%%把这一循环第k次初始值算得到的最大残差赋给Teps作为新的标准，应该可以移到前面去
% 
% end
%%  后加的
% solve1;
% if steps>=30
% end
%   xiajiang;
  solve1_guan;
% for i=1:2
%     if steps>=30&time~=1
%     XI=0.5*XI+0.5*cai;
%     solve1;
%     end
% end
   	
 %%
  offdesign;
  enginepath_guan;
  perform;
  Xd=XI;
  if traditional==0
       fid = fopen('jieliu_guan.txt','at+');
  else
      fid=fopen('traditionjieliu_guan.txt','at+');
  end  
%  fprintf(fid,'MECHN1=%8.2f   steps=%8f\r\n',MECHN1, steps);
 fprintf(fid,'steps=%8f  time=%8f\r\n', steps,time);%%后加
 fprintf(fid,'残差=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f    %8.5f   %8.5f\r\n',Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7),Z(8));
  fprintf(fid,'最终取值=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f    %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7),XI(8));%%后加的
 fclose(fid);	
  	
  
  if MECHN1~=0
      if traditional==0
           fid = fopen('offdesign1_guan.txt','at+');
      else
        fid = fopen('traditionoffdesign1_guan.txt','at+');
      end
        fprintf(fid,'飞行高度=%8.2f     马赫数=%f\r\n',ALTITUDE,MACH);
        fprintf(fid,'No  N1    N2     推力         耗油率  燃油流量    涵道比   SRF  SRC  风扇裕度  增压级裕度  压气机裕度\r\n');  
        fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f  %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7),XI(8));
        fclose(fid);
        
        
        
  end
  
   if traditional==0
        fid = fopen('offdesign1_guan.txt','at+');
   else
       fid = fopen('traditionoffdesign1_guan.txt','at+');
   end
        fprintf(fid,'%d %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f\r\n',kk,MECHN1,N2,Thrust,SFC,Wfb*3600.00,BPR,RKF,RKC,SM1,SM3,SM2);
        fprintf(fid,'推力=%8.5f   耗油率=%8.5f   燃油消耗=%8.5f   速度比=%8.5f   涵道比=%8.5f   N1=%8.5f   N2=%8.5f\r\n',Thrust,SFC,Wfb*3600.00,Von/Vo,BPR,N1,N2);  
        fprintf(fid,'风扇：换算流量=%8.5f  压比=%8.5f  效率=%8.5f  换算转速=%8.5f\r\n',Wcorfan,PRfan,Efffan,N1cor);
        fprintf(fid,'增压级：换算流量=%8.5f  压比=%8.5f  效率=%8.5f  换算转速=%8.5f\r\n',Wcorboo,PRboo,Effboo,NBcor);
        fprintf(fid,'压气机：换算流量=%8.5f  压比=%8.5f  效率=%8.5f  换算转速=%8.5f\r\n',Wcorcomp,PRcomp,Effcomp,N2cor);
        fprintf(fid,'燃烧室：燃烧效率=%5.5f  总压恢复系数=%5.5f\r\n',Effb,DP);
        fprintf(fid,'高压涡轮：膨胀比=%5.5f  效率=%5.5f  需用单位功=%5.5f\r\n',PRKth,EffHT,THWork);
        fprintf(fid,'低压涡轮：膨胀比=%5.5f  效率=%5.5f  需用单位功=%5.5f\r\n',PRKtl,EffLT,TLWork);
        %fprintf(fid,'喷管：外涵面积=%5.5f  内涵面积=%5.5f\r\n',Aonoz, Areao);
         fprintf(fid,'喷管：外涵面积=%5.5f  中冷外涵面积=%5.5f  内涵面积=%5.5f\r\n',Aonoz,AonozB, Areao);
        fprintf(fid,'截面参数： 总温       总压      流量\r\n');
        fprintf(fid,'进气道出口：%8.5f   %8.5f   %8.5f\r\n',Tino,Pino,Wai);
        fprintf(fid,'风扇出口：%8.5f   %8.5f   %8.5f   %8.5f\r\n',Tfano,Pfano,Wbpo,Wcomp);
        fprintf(fid,'增压级出口：%8.5f   %8.5f   %8.5f\r\n',Tboo1,Pboo1,Wboo);%%%改
        fprintf(fid,'中冷器出口：%8.5f   %8.5f   %8.5f\r\n',Tboo,Pboo,Wboo);
        fprintf(fid,'压气机出口：%8.5f   %8.5f   %8.5f\r\n',Tcomo1,Pcomo1,Wcompout);%%%%%
         fprintf(fid,'燃烧室进口：%8.5f   %8.5f   %8.5f\r\n',Tcomo,Pcomo,Wcompout);
        fprintf(fid,'燃烧室出口：%8.5f   %8.5f   %8.5f\r\n',Tburno,Pburno,Wburno);
        fprintf(fid,'高压涡轮出口：%8.5f   %8.5f   %8.5f\r\n',Thto,Phto,Whto);
        fprintf(fid,'低压涡轮出口：%8.5f   %8.5f   %8.5f\r\n',Tlto1,Plto1,Wlto);
        fprintf(fid,'外涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',Tson,Pson,Von);
        %fprintf(fid,'内涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',Tso,Pso,Vo);
        fprintf(fid,'中冷外涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',TsonB,PsonB,VonB);%%
        fprintf(fid,'内涵喷管出口：总温=%8.5f   总压=%8.5f   排气速度=%8.5f\r\n',Tso,Pso,Vo);
        fprintf(fid,'RKF=%8.5f   RKB=%8.5f   RKC=%8.5f\r\n',RKF,RKB,RKC);
        if traditional==0
             fprintf(fid,'换热器参数：\r\n');
         fprintf(fid,'中冷器：  外涵压降=%5.5f   内涵压降=%5.5f\r\n',Deltp1,Deltp2);
     % fprintf(fid,'长=%5.5f   宽=%5.5f   高=%5.5f      重量=%5.5f\r\n',L1,L2,L3,mcore1);
        fprintf(fid,'回热器：  压气机压降=%5.5f   涡轮压降=%5.5f\r\n',Deltp3,Deltp4);
      %  fprintf(fid,'长=%5.5f   宽=%5.5f   高=%5.5f      重量=%5.5f\r\n',L11,L22,L33,mcore2);
      fprintf(fid,'中冷器：冷侧效率=%5.5f 总效率=%5.5f  热侧效率=%5.5f\r\n',youxd1,zyxd1,youxd2);
      fprintf(fid,'回热器：冷侧效率=%5.5f  总效率=%5.5f  热侧效率=%5.5f\r\n',youxd3,zyxd2,youxd4);
      fprintf(fid,'换热器质量; %5.5f  %5.5f  %5.5f  %5.5f\r\n',mass1,mass2,mass3,mass4);
        fprintf(fid,'总增压比=%5.5f\r\n',PRfan*PRboo*PRcomp);
        fprintf(fid,'外涵推力=%5.5f  中冷外涵推力=%5.5f  内涵推力=%5.5f\r\n',Thrust2/9.8,Thrust3/9.8,Thrust1/9.8);
        fprintf(fid,'外涵流量=%8.5f 中冷外涵流量=%8.5f  内涵流量=%8.5f\r\n',Wbpo,WbpBo,Wcnoz);
        fprintf(fid,'中冷器：冷侧压降=%5.5f    热侧压降=%5.5f   回热器：冷侧压降=%5.5f    热侧压降=%5.5f \r\n',Deltp1/Pfano,Deltp2/Pboo1,Deltp3/Pcomo11,Deltp4/Plto11);
         %%%
        fprintf(fid,'外涵道推力=%8.5f   外涵道流量=%8.5f   外涵速度=%8.5f   %8.5f   %8.5f   涵道比=%8.5f   外涵速度=%8.5f  %8.5f   静压=%8.5f   环境压力=%8.5f   外涵喉道面积=%8.5f\r\n',Thrust2,Wonoz,Von,fai_m_dVo,W1,BPR,V,1+BPR,Pson,Pev,Aonoz);
        end
   fclose(fid);  
    
   
            