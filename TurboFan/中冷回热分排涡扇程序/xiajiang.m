%% �����½���������Է�����
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
    if Teps>am	%%��Teps����ʱ������С�Ĳв�ֵ
              if f_controlN1
				 Temp= XI;  %%��������й�������ʱ�������ŵ��Ǹ���
                 time=steps;
                optimalz=Z;
              else
                 Temp= XII;
              end
				Teps = am;
    else
                h=h*t; %%�����ʾ�����K+1�εĲв����Ļ� �ͼ�С����    
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
    
    
    for j=1:7%%�������ſ˱Ⱦ���
		      c = XI(j); 
              XI(j) = XI(j)+h(j)*c;
			  offdesign;
              enginepath;
			   for m=1:7
                  Jac(m,j) = (Z(m)-b(m))/(h(j)*c);
               end
			  XI(j) = c;%%�����Ǳ�ʾXI(j)���ǳ�ʼֵ
    end

           lamd=b'/sum(diag(Jac'*Jac));
         
            XI=XI-(Jac*lamd)';
            
            zhongjian(steps,:)=(Jac*lamd)';
            offdesign;
            enginepath;
            b=Z;
           am=max(abs(Z));
           
           
      fid = fopen('xiajiang.txt','at+');
 fprintf(fid,'�в�=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7));
  fprintf(fid,'����ȡֵ=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));%%��ӵ�
 fclose(fid);      
           
  agb=3;         
           
end

 fid = fopen('xiajiang.txt','at+');
%  fprintf(fid,'MECHN1=%8.2f   steps=%8f\r\n',MECHN1, steps);
 fprintf(fid,'steps=%8f  time=%8f\r\n', steps,time);%%���
 fprintf(fid,'�в�=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',Z(1),Z(2),Z(3),Z(4),Z(5),Z(6),Z(7));
  fprintf(fid,'����ȡֵ=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7));%%��ӵ�
 fclose(fid);