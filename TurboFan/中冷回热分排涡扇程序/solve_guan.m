%    h=[1,1,1,1,1,1,1]*Detah;%%Detah=-0.002
%    Deta=[0,0,0,0,0,0,0];
% 	S=30;%%������������
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
%       b=Z;%%�в�
% 		am = 0.0;
% 		for i=1:7%%�����Ҳв�������һ������am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
%      %%  ��ӵ�
%      
%   fid = fopen('jieliu.txt','at+');
%    fprintf(fid,'MECHN1=%8.2f\r\n',MECHN1);
%  fprintf(fid,'��ʼ��ֵ=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));
%  fclose(fid);    
%  %%
%  steps=0;
% while am>=eps%%���am���ǵ�k�ε�
% 
%        steps=steps+1;   
% %           if steps>30
% %              
% %               break; 
% %           end	
% %%
% %         b=Z;%%�в�
% % 		am = 0.0;
% % 		for i=1:7%%�����Ҳв�������һ������am
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
% 			if Teps>am	%%��Teps����ʱ������С�Ĳв�ֵ
%               if f_controlN1
% 				 Temp= XI;  %%��������й�������ʱ�������ŵ��Ǹ���
%                  time=steps;
%               else
%                  Temp= XII;
%                end
% 				Teps = am;
%             else 
%                 h=h*t; %%�����ʾ�����K+1�εĲв����Ļ� �ͼ�С����    
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
%             %% ���ϸĳ�����
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
%             for j=1:7%%�������ſ˱Ⱦ���
% 		      c = XI(j); 
%               XI(j) = XI(j)+h(j)*c;
% 			  offdesign;
%               enginepath;
% 			   for m=1:7
%                   Jac(m,j) = (Z(m)-b(m))/(h(j)*c);
%                end
% 			  XI(j) = c;%%�����Ǳ�ʾXI(j)���ǳ�ʼֵ
%             end
% % 			 offdesign;%%�ǲ���Ӧ�ü��ϰ�
% %              enginepath;
%              y=Jac\b';%%\Z'��б����Z'��Z�ľ���ת��%%ǰ���Z�ǲ���Ӧ�����¼����أ���ΪZӦ���ǵ�k����ֵ
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
%                     w=rand(1)*(10.0-0.0)+0.0;%%0��10֮���漴��
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
%             %% ��ӵ�
%              b=Z;%%�в�
% 		am = 0.0;
% 		for i=1:7%%�����Ҳв�������һ������am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
%         %%
%             
% %            	p = S-l;
% 	jingquejie=1;
% % 	Teps=am;%%����һѭ����k�γ�ʼֵ��õ������в��Teps��Ϊ�µı�׼��Ӧ�ÿ����Ƶ�ǰ��ȥ
% 
% end
%%  ��ӵ�
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
 fprintf(fid,'steps=%8f  time=%8f\r\n', steps,time);%%���
 fprintf(fid,'�в�=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f    %8.5f   %8.5f\r\n',Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7),Z(8));
  fprintf(fid,'����ȡֵ=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f    %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7),XI(8));%%��ӵ�
 fclose(fid);	
  	
  
  if MECHN1~=0
      if traditional==0
           fid = fopen('offdesign1_guan.txt','at+');
      else
        fid = fopen('traditionoffdesign1_guan.txt','at+');
      end
        fprintf(fid,'���и߶�=%8.2f     �����=%f\r\n',ALTITUDE,MACH);
        fprintf(fid,'No  N1    N2     ����         ������  ȼ������    ������   SRF  SRC  ����ԣ��  ��ѹ��ԣ��  ѹ����ԣ��\r\n');  
        fprintf(fid,'%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f  %8.5f  %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7),XI(8));
        fclose(fid);
        
        
        
  end
  
   if traditional==0
        fid = fopen('offdesign1_guan.txt','at+');
   else
       fid = fopen('traditionoffdesign1_guan.txt','at+');
   end
        fprintf(fid,'%d %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f  %8.5f\r\n',kk,MECHN1,N2,Thrust,SFC,Wfb*3600.00,BPR,RKF,RKC,SM1,SM3,SM2);
        fprintf(fid,'����=%8.5f   ������=%8.5f   ȼ������=%8.5f   �ٶȱ�=%8.5f   ������=%8.5f   N1=%8.5f   N2=%8.5f\r\n',Thrust,SFC,Wfb*3600.00,Von/Vo,BPR,N1,N2);  
        fprintf(fid,'���ȣ���������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f  ����ת��=%8.5f\r\n',Wcorfan,PRfan,Efffan,N1cor);
        fprintf(fid,'��ѹ������������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f  ����ת��=%8.5f\r\n',Wcorboo,PRboo,Effboo,NBcor);
        fprintf(fid,'ѹ��������������=%8.5f  ѹ��=%8.5f  Ч��=%8.5f  ����ת��=%8.5f\r\n',Wcorcomp,PRcomp,Effcomp,N2cor);
        fprintf(fid,'ȼ���ң�ȼ��Ч��=%5.5f  ��ѹ�ָ�ϵ��=%5.5f\r\n',Effb,DP);
        fprintf(fid,'��ѹ���֣����ͱ�=%5.5f  Ч��=%5.5f  ���õ�λ��=%5.5f\r\n',PRKth,EffHT,THWork);
        fprintf(fid,'��ѹ���֣����ͱ�=%5.5f  Ч��=%5.5f  ���õ�λ��=%5.5f\r\n',PRKtl,EffLT,TLWork);
        %fprintf(fid,'��ܣ��⺭���=%5.5f  �ں����=%5.5f\r\n',Aonoz, Areao);
         fprintf(fid,'��ܣ��⺭���=%5.5f  �����⺭���=%5.5f  �ں����=%5.5f\r\n',Aonoz,AonozB, Areao);
        fprintf(fid,'��������� ����       ��ѹ      ����\r\n');
        fprintf(fid,'���������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tino,Pino,Wai);
        fprintf(fid,'���ȳ��ڣ�%8.5f   %8.5f   %8.5f   %8.5f\r\n',Tfano,Pfano,Wbpo,Wcomp);
        fprintf(fid,'��ѹ�����ڣ�%8.5f   %8.5f   %8.5f\r\n',Tboo1,Pboo1,Wboo);%%%��
        fprintf(fid,'���������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tboo,Pboo,Wboo);
        fprintf(fid,'ѹ�������ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomo1,Pcomo1,Wcompout);%%%%%
         fprintf(fid,'ȼ���ҽ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tcomo,Pcomo,Wcompout);
        fprintf(fid,'ȼ���ҳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tburno,Pburno,Wburno);
        fprintf(fid,'��ѹ���ֳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Thto,Phto,Whto);
        fprintf(fid,'��ѹ���ֳ��ڣ�%8.5f   %8.5f   %8.5f\r\n',Tlto1,Plto1,Wlto);
        fprintf(fid,'�⺭��ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tson,Pson,Von);
        %fprintf(fid,'�ں���ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tso,Pso,Vo);
        fprintf(fid,'�����⺭��ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',TsonB,PsonB,VonB);%%
        fprintf(fid,'�ں���ܳ��ڣ�����=%8.5f   ��ѹ=%8.5f   �����ٶ�=%8.5f\r\n',Tso,Pso,Vo);
        fprintf(fid,'RKF=%8.5f   RKB=%8.5f   RKC=%8.5f\r\n',RKF,RKB,RKC);
        if traditional==0
             fprintf(fid,'������������\r\n');
         fprintf(fid,'��������  �⺭ѹ��=%5.5f   �ں�ѹ��=%5.5f\r\n',Deltp1,Deltp2);
     % fprintf(fid,'��=%5.5f   ��=%5.5f   ��=%5.5f      ����=%5.5f\r\n',L1,L2,L3,mcore1);
        fprintf(fid,'��������  ѹ����ѹ��=%5.5f   ����ѹ��=%5.5f\r\n',Deltp3,Deltp4);
      %  fprintf(fid,'��=%5.5f   ��=%5.5f   ��=%5.5f      ����=%5.5f\r\n',L11,L22,L33,mcore2);
      fprintf(fid,'�����������Ч��=%5.5f ��Ч��=%5.5f  �Ȳ�Ч��=%5.5f\r\n',youxd1,zyxd1,youxd2);
      fprintf(fid,'�����������Ч��=%5.5f  ��Ч��=%5.5f  �Ȳ�Ч��=%5.5f\r\n',youxd3,zyxd2,youxd4);
      fprintf(fid,'����������; %5.5f  %5.5f  %5.5f  %5.5f\r\n',mass1,mass2,mass3,mass4);
        fprintf(fid,'����ѹ��=%5.5f\r\n',PRfan*PRboo*PRcomp);
        fprintf(fid,'�⺭����=%5.5f  �����⺭����=%5.5f  �ں�����=%5.5f\r\n',Thrust2/9.8,Thrust3/9.8,Thrust1/9.8);
        fprintf(fid,'�⺭����=%8.5f �����⺭����=%8.5f  �ں�����=%8.5f\r\n',Wbpo,WbpBo,Wcnoz);
        fprintf(fid,'�����������ѹ��=%5.5f    �Ȳ�ѹ��=%5.5f   �����������ѹ��=%5.5f    �Ȳ�ѹ��=%5.5f \r\n',Deltp1/Pfano,Deltp2/Pboo1,Deltp3/Pcomo11,Deltp4/Plto11);
         %%%
        fprintf(fid,'�⺭������=%8.5f   �⺭������=%8.5f   �⺭�ٶ�=%8.5f   %8.5f   %8.5f   ������=%8.5f   �⺭�ٶ�=%8.5f  %8.5f   ��ѹ=%8.5f   ����ѹ��=%8.5f   �⺭������=%8.5f\r\n',Thrust2,Wonoz,Von,fai_m_dVo,W1,BPR,V,1+BPR,Pson,Pev,Aonoz);
        end
   fclose(fid);  
    
   
            