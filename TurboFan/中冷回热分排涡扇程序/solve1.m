Detah=-0.002; %��ʱ�ӵ�
h=[1,1,1,1,1,1,1,1]*Detah;%%Detah=-0.002
   Deta=[0,0,0,0,0,0,0,0];
  
	S=30;%%������������
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
      b=Z;%%�в�
		am = 0.0;
        am=max(abs(Z));
% 		for i=1:7%%�����Ҳв�������һ������am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
     %%  ��ӵ�
  if traditional==0   
  fid = fopen('jieliu1.txt','at+');
  else
      fid = fopen('traditionjieliu1.txt','at+'); 
  end
   fprintf(fid,'MECHN1=%8.2f\r\n',MECHN1);
 fprintf(fid,'��ʼ��ֵ=%8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f   %8.5f\r\n',XI(1),XI(2),XI(3),XI(4),XI(5),XI(6),XI(7),XI(8));
 fclose(fid);    
 
 %%
 steps=0;
while am>=eps%%���am���ǵ�k�ε�

       steps=steps+1;   
%           if steps>30
%              
%               break; 
%           end	
%%
%         b=Z;%%�в�
% 		am = 0.0;
% 		for i=1:7%%�����Ҳв�������һ������am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
%%
		
		if am>=eps
		
		       l = l-1;
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
            %% ���ϸĳ�����
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
            for j=1:nn%%�������ſ˱Ⱦ���
		      c = XI(j); 
              XI(j) = XI(j)+h(j)*c;
			  offdesign;
              enginepath;
			   for m=1:nn
                  Jac(m,j) = (Z(m)-b(m))/(h(j)*c);
               end
			  XI(j) = c;%%�����Ǳ�ʾXI(j)���ǳ�ʼֵ
            end
% 			 offdesign;%%�ǲ���Ӧ�ü��ϰ�
%             enginepath;
             y=Jac\b';%%\Z'��б����Z'��Z�ľ���ת��%%ǰ���Z�ǲ���Ӧ�����¼����أ���ΪZӦ���ǵ�k����ֵ
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
                
				if (abs(Deta(q)>1.0e-4) & (abs(d)<=1.0e-5))%% ˵����k�κ͵�k+1�ε�deta x�������෴�ġ�
                    w=rand(1)*(10.0-0.0)+0.0;%%0��10֮���漴��
                    XI(q) = XI(q)-w/20.0*y(q);%%���Ǽ�С�䶯���Ĺ���
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
            %% ��ӵ�
             b=Z;%%�в�
		am = 0.0;
        am=max(abs(Z));
% 		for i=1:7%%�����Ҳв�������һ������am
%      		z = abs(b(i));
% 			if z>am
%                 am = z;
%             end
%         end
        %%
            
%            	p = S-l;
	jingquejie=1;
% 	Teps=am;%%����һѭ����k�γ�ʼֵ��õ������в��Teps��Ϊ�µı�׼��Ӧ�ÿ����Ƶ�ǰ��ȥ

end