%% 最速下降法解非线性方程组
% INTRODUCTORY TEXT
%%
h=[1,1,1,1,1,1,1]*Detah;
t=0.5;
Teps=1.0;
eps=3.0e-3;
steps=0;
offdesign;
enginepath;
am=max(abs(Z))
b=Z;
zhongjian=zeros(31,7)
while am>eps
     steps=steps+1;
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
    
      if (steps>30)
             
        
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
    
    
    for j=1:7%%这是求雅克比矩阵
		      c = XI(j); 
              XI(j) = XI(j)+h(j)*c;
			  offdesign;
              enginepath;
			   for m=1:7
                  Jac(m,j) = (Z(m)-b(m))/(h(j)*c);
               end
			  XI(j) = c;%%这里是表示XI(j)还是初始值
    end

           lamd=b'/sum(diag(Jac'*Jac));
         
            XI=XI-(Jac*lamd)';
            
            zhongjian(steps,:)=(Jac*lamd)';
            offdesign;
            enginepath;
            b=Z;
           am=max(abs(Z));
           
           
      fid = fopen('xiajiang.txt','at+');
 fprintf(fid,'残差=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7));
  fprintf(fid,'最终取值=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));%%后加的
 fclose(fid);      
           
  agb=3;         
           
end

 fid = fopen('xiajiang.txt','at+');
%  fprintf(fid,'MECHN1=%8.2f   steps=%8f\r\n',MECHN1, steps);
 fprintf(fid,'steps=%8f  time=%8f\r\n', steps,time);%%后加
 fprintf(fid,'残差=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7));
  fprintf(fid,'最终取值=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));%%后加的
 fclose(fid);