%function [ output_args ] = enginepath( input_args )
%MAIN Summary of this function goes here
%  Detailed explanation goes here



   f_enginepath=1;
  
    envirout;
    if f_design == false
       f_specifyEtar=false;  
    end
	inlet;
	if f_design==false
	      if f_guess 
%               if f_control 
%                 N1=100;
%                 N2=100;
%             end
		      if ~f_controlN1%%这里使用N2给n1赋初值，这表示：不控制n1就一定要控制N2
		
			     T1 =Tino;
 			     N1 = 100.0*((N2/100.0)^1.5)*((T1ds/T1)^0.33);%%用经验公式给n1赋初值
                 x = rand(1)*(50.0-10.0)+10.0;
			      if ~f_throttle%%如果不是进行节流猜值的话还要对N1有如下限制
		
				      if N1>N1max 
                        N1 = N1max*(1.0-0.3/x);
                       end
                  else
			 
				       if N1>N1max+7.0
                          N1 = (N1max+7.0)*(1.0-0.3/x);
                      end
                  end
                  XII(3)=N1;
			     
              end
          end
    end

	fan;
	Wai = Wfano;
	if f_design==false
    if f_guess 
	
		  if f_controlN1	%//控制N1%%这是当控制n1时，给定N2的猜值经验初值
		
			  T1 = Tino;
			  T2 = Tfano;
% 			  Tburno = T4ds*((N1/100.0)^0.62)*((T1/T1ds)^0.31);          
%           if  MECHN1==98|MECHN1==97
%               N2=XI(3)-0.5;
%           end
%           if  MECHN1==96
%               N2=XI(3)-0.3;
%           end
%           if  MECHN1==95
%               N2=XI(3)-0.3;
%           end
%           if  MECHN1==94|MECHN1==93
%               N2=XI(3)-0.5;
%           end
%           if  MECHN1==92
%               N2=XI(3)-0.5;
%           end
%           if  MECHN1==91
%               N2=XI(3)-0.3;
%           end
%           if  MECHN1==90|MECHN1==89
%               N2=XI(3)-0.5;
%           end
%           if  MECHN1==88
%               N2=XI(3)-0.3;
%           end
%           if  MECHN1==87|MECHN1==86
%               N2=XI(3)-0.5;
%           end
%            if  MECHN1==85|MECHN1==84
%               N2=XI(3)-0.5;
%            end
          if  MECHN1<=98&MECHN1>=77
              N2=XI(3)-0.5;
          end
	          XI(3)=N2;
              XI(8)=icper;
		 else	%//控制N2(等燃油流量控制通过调节N2获得)%%这是当控制N2时，给定涡轮前温度的猜值经验公式。
                   %%可见当控制N2时，同时得到N1和Tburno初值猜值经验公式
		
			 T2 = Tfano;
			 Tburno = T4ds*((N2/97.64)^1.0)*((T2/T2ds)^0.25);		
		
         end         
		f_guess = false;%%这时初值猜测完毕，下次进行流程计算时就不再进行猜值过程
    end
    end
   
    %%
	booster;
   %%
    if f_design==false
      fid = fopen('wolunpzb.txt','at+');    
%      %if MECHN1<=99
%       %fprintf(fid,'N2corBleed=%8.4f  Gasbleed=%8.4f\r\n',N2corBleed,Gasbleed);
%      %end
      fprintf(fid,'猜值=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));%%这是取初值时的残差
      fclose(fid);
     end
    %%
	compressor;
%   Wbpo = Wfano-Wcomp;%%
% 	BPR =Wbpo/Wcomp;  %%
	burner;
    HPTurbine;
    lsm=0;
	LPTurbine;
    %%
    
    
    Tcomo1=Tcomo;
    Tlto1=Tlto;
    Pcomo1=Pcomo;
    Plto1=Plto;
    Tm11=Tcomo;
    Pm11=Pcomo;
    Tm22=Tlto;
   if traditional==0
    
    [Tltoi,Tcomoi,Deltp3,Deltp4,ytz2,mcore2,L11,L22,L33]=repucator(Tcomo,Tlto,Pcomo,Plto,Wcompout,Wlto,BPR);%%温度判断在reputator函数中
    Tcomo=Tcomoi;
    Pm=Pcomo;
    Pcomo=Pcomo-Deltp4;
    %Pcomo=0.92*Pcomo;%%%%%%%%%%%%2014.6.5
    fid = fopen('design444.txt','wt+');
    fprintf(fid,'换热前：Tm11=%8.2f   Tm22=%8.2f\r\n',Tm11,Tm22);
    fprintf(fid,'Tcomo=%8.2f    Tltoi=%8.2f\r\n',Tcomo,Tltoi);
    fclose(fid);
    for i=1:1:1000
       if i>1000
        error('压气机涡轮出口温度迭代不收敛');
       end;
       lsm=lsm+1;
      Tm=Tltoi;
      Hcomo =gashi(Tcomo,0);%压气机换热后出口总焓
      burner;
      HPTurbine;
	  LPTurbine;
      Tlto2=Tlto;%%这是求出换热后涡轮出口温度时 换热前的涡轮出口温度
      Plto2=Plto;
      fid = fopen('design444.txt','wt+');
      fprintf(fid,'Tcomo=%8.2f   Tlto=%8.2f\r\n',Tcomo,Tlto);
      [Tltoi,Tcomoi,Deltp3,Deltp4,ytz2,mcore2,L11,L22,L33]=repucator(Tm11,Tlto,Pm11,Plto,Wcompout,Wlto,BPR);
      Tcomo=Tcomoi;
      Pcomo=Pm-Deltp4;
      %Pcomo=0.92*Pcomo;%%%%2014.6.5
      fprintf(fid,'Tcomo=%8.2f    Tltoi=%8.2f\r\n',Tcomo,Tltoi);
      fclose(fid);
      if abs(Tm-Tltoi)<0.5
          break;
      end
    end  
    

   
    Tlto=Tltoi;
    Plto=Plto-Deltp3;
    Hlto=gashi(Tlto,0);
    
    
end%%


    Bypass;
    if traditional==0
    BypassB;
    end
	outnoz;
     if traditional==0
    outnozB;
     end
    CNoz;
    if f_design==false
 fid = fopen('wolunpzb.txt','at+'); 
 fprintf(fid,'MECHN1=%8.2f   残差=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',MECHN1,Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7));
 fclose(fid);
    end