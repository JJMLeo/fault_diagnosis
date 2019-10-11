Detah=-0.002; %临时加的
h=[1,1,1,1,1,1,1,1]*Detah;%%Detah=-0.002
   Deta=[0,0,0,0,0,0,0,0];
  
	S=30;%%迭代次数限制
	t = 0.5;%
	l = S;
	eps =3.0e-3;
   if traditional==0
    nn =8;
   else
   nn =7;
   end
    time=0;
	%%am = 1.0+eps;
	Teps = 100.0;
    
     offdesign;
     enginepath;
     cai=XI;
  
     %%
      b=Z;%%残差
		am = 0.0;
        am=max(abs(Z));
% 		for i=1:7%%这是找残差最大的哪一个赋给am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
     %%  后加的
  if traditional==0   
  fid = fopen('jieliu1.txt','at+');
  else
      fid = fopen('traditionjieliu1.txt','at+'); 
  end
   fprintf(fid,'MECHN1=%8.2f\r\n',MECHN1);
 fprintf(fid,'初始猜值=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7),XI(8));
 fclose(fid);    
 
 %%
 steps=0;
while am>=eps%%这个am还是第k次的

       steps=steps+1;   
%           if steps>30
%              
%               break; 
%           end	
%%
%         b=Z;%%残差
% 		am = 0.0;
% 		for i=1:7%%这是找残差最大的哪一个赋给am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
%%
		
		if am>=eps
		
		       l = l-1;
			if Teps>am	%%而Teps是临时保存最小的残差值
              if f_controlN1
				 Temp= XI;  %%这个是运行过程中临时保存最优的那个解
                 time=steps;
                optimalz=Z;
              else
                 Temp= XII;
               end
				Teps = am;
            else 
                h=h*t; %%这个表示如果第K+1次的残差更大的化 就减小步长    
            end
            %%
            
% 			if l==0	
%                 
% 				if Teps<0.01
%                     if f_controlN1
% 					   XI= Temp;
%                    else
%                        XII=Temp;
%                     end
% 					 jinsijie=1;
%                     shoulian=false;
%                     break;
%                 end
%                 jie=0;
%                 shoulian=false;
%               break;
%             end
            %% 以上改成如下
            if l==0	
                
				
                    if f_controlN1
					   XI= Temp;
                       Z=optimalz;
                   else
                       XII=Temp;
                    end
                    if Teps<0.01
					 jinsijie=1;
                    else
                    jie=0;
                   shoulian=false;
 
                   end
             break;
        end
   
        end
        if f_controlN1
            for j=1:nn%%这是求雅克比矩阵
		      c = XI(j); 
              XI(j) = XI(j)+h(j)*c;
			  offdesign;
              enginepath;
			   for m=1:nn
                  Jac(m,j) = (Z(m)-b(m))/(h(j)*c);
               end
			  XI(j) = c;%%这里是表示XI(j)还是初始值
            end
% 			 offdesign;%%是不是应该加上啊
%             enginepath;
             y=Jac\b';%%\Z'反斜杠是Z'是Z的矩阵转置%%前面的Z是不是应该重新计算呢，因为Z应该是第k步的值
             y=y';
             
             %%
			for q=1:nn				
				r=abs(y(q)/XI(q));
			    if y(q)~=0
                    s=y(q)/abs(y(q));
                else
                    s=0;
                end
				if r>0.10 
                    r=0.10;
                end                    
				y(q)=XI(q)*r*s;
                y(q);
				d = Deta(q)+y(q);%%
                Deta(q);
                
				if (abs(Deta(q)>1.0e-4) & (abs(d)<=1.0e-5))%% 说明第k次和第k+1次的deta x正负是相反的。
                    w=rand(1)*(10.0-0.0)+0.0;%%0到10之间随即数
                    XI(q) = XI(q)-w/20.0*y(q);%%这是减小变动量的过程
				else
                    XI(q) = XI(q)-y(q);
                end
				Deta(q) = y(q);
            end
        end

            offdesign;
            enginepath;
           
            XI;
            Z;
            %% 后加的
             b=Z;%%残差
		am = 0.0;
        am=max(abs(Z));
% 		for i=1:7%%这是找残差最大的哪一个赋给am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
        %%
            
%            	p = S-l;
	jingquejie=1;
% 	Teps=am;%%把这一循环第k次初始值算得到的最大残差赋给Teps作为新的标准，应该可以移到前面去

end