%function [ Tburno,Pburno,Hburno,Wburnout,FARB ] = burner( Tburno)
%BURNER Summary of this function goes here
%  Detailed explanation goes here
   
    
    
    
      
    Wbcor = Wcompout*(Tcomo^0.5)/Pcomo;%ȼ���һ�������
 	if f_design 
        Wbcords = Wbcor;   
    end        
    DP = BurnerDPds*(Wbcor/Wbcords);	%ѹ����ʧ   
	if DP>1.0 
        DP = 1.0;
    end     
   	Pburno = Pcomo*(1.0-DP);	%����ȼ���ҳ���ѹ��
    
    
    if f_design && f_specifyWF	%������Ƶ㹩����
		Tburno =(2222.0+555.5)/2.0;	%�Ը��¶�
    end
	if f_design && f_specifyT
		Tburno = Tburnods;	%������Ƶ��¶�
    end
        
        
    IGO = 0; 
    while IGO~=2	    
   
		if Tburno>2222.0
            Tburno = 2222.0;
        end
        
		if Tburno<555.5
            Tburno = 555.5;
        end
        
		 DT = Tburno-Tcomo;
		 P = Pcomo*1.4504E-4;	%���ʵ�λת��ΪӢ�Ƶ�λ
		 DT = DT*9.0/5.0;
         
         PDMap=struct('X',0.0,'Y',P,'Z',DT),	
         rowSize=15;  colSize=15;
		 Effb = lookup('mfGBurner.txt',PDMap.Y,PDMap.Z,rowSize,colSize);   %��ȼ��Ч��
        
		if f_design
            ScallEffb = Effbds/Effb;
        end        
		Effb = Effb*ScallEffb,
        %����ȼ�Ϳ��ͷ�����
		T = Tburno*9.0/5.0;
        HV = ((((((-.4594317e-19*T)-.2034116e-15)*T+.2783643e-11)*T+.2051501e-07)*T-.2453116e-03)*T-.9433296e-01)*T+.1845537e+05;        
        HV = HV*2325.4295;
        HA=gashi(  Tburno, 0 );
        FARb=(HA-Hcomo)/(HV*Effb);%���������� �޸�
        if FARb<0.005
           FARb=0.005;
       end
       WFx=FARb*Wcompout;
      
       if  f_specifyT|m_bGuessT	% �������Ը������¶�
	
			Wfb = WFx;
			if f_design
                Wfbds = Wfb;
            end
			IGO = 2;
        %�������Ը�ȼ������������¶�
		else
		
			FARb = Wfb/Wcompout;%����������    
            Tburnocal=Tburno+100;
			while abs(Tburnocal-Tburno)>0.00000001*Tburno
                Tburno=Tburnocal;
               [ Cp,k,R] = gasstate( Tburno,FARb,1,1);
               T = Tburno*9.0/5.0;
               HV = ((((((-.4594317e-19*T)-.2034116e-15)*T+.2783643e-11)*T+.2051501e-07)*T-.2453116e-03)*T-.9433296e-01)*T+.1845537e+05;        
               HV = HV*2325.4295;
               Tburnocal=(Wfb*HV+Cp*Wcompout*Tcomo)/(Cp*(Wcompout+Wfb)); 
            
             end
            m_bGuessT=1 ;
         end
     end
	   Wburno = Wcompout+Wfb;%ȼ���ҳ���ȼ��
	  [Hburno] = gashi(  Tburno, FARb );%ȼ���ҳ�������
       
        XI(4)=Tburno;
        XII(4)=Tburno;
       
       
       
	