%function [ output_args ] = offdesign( input_args )
%OFFDESIGN Summary of this function goes here
%  Detailed explanation goes here




       x=rand(1)*(50.0-10.0)+10.0;
  	if f_controlN1 	%//¿ØÖÆN1
      
				RKF = XI(1);
			if RKF>=1.0
                RKF = 1.0-1.0/x;
            end
			if RKF<=0.0
                RKF = 0.0+8.0/x;
            end
	
		
		    RKC = XI(2);
            if RKC>=1.0
                RKC= 1.0-1.0/x;
            end
			if RKC<=0.0
                RKC = 0.0+8.0/x;
            end
        
		
		N2= XI(3);
		Tburno = XI(4);

		Whtcormap = XI(5);
        Xlp(5)=0;
		if Whtcormap >=1.012 
            Xlp(5)=Whtcormap;
            Whtcormap = 1.012*(1.0-1.0/x);
        end
		if Whtcormap<=0.756  
            Whtcormap = 0.756*(1.0+1.0/x);
        end

		Wltcormap= XI(6);
        Xlp(6)=0;
		if Wltcormap>=297.101
            Xlp(6)=Wltcormap;
            Wltcormap=297.101*(1.0-1.0/x);
        end
		if Wltcormap<=246.568 
            Wltcormap = 246.568*(1.0+1.0/x);
        end
        if traditional==0
    icper=XI(8);
        end
    end
    
            RKB = XI(7);
            Xlp(7)=0;
			if RKB>=1.0
                Xlp(7)=RKB;
                RKB = 1.0-1.0/x;
            end
			if RKB<=0.0
                RKB = 0.0+8.0/x;
            end
            
            %%
	if f_controlN2 %//¿ØÖÆN2
 
    
            RKF = X(1);
			if RKF>=1.0
                RKF = 1.0-1.0/x;
            end
			if RKF<=0.0
                RKF = 0.0+8.0/x;
            end
	
		    N1 = X(3);
			if  N1>=105.0 
                N1 = 105.0*(1.0-0.5/x);
            end
			if  N1<=15.0  
                N1= 15.0*(1.0+0.5/x);
            end
			
		    RKC = X(2);
            if RKC>=1.0
                RKC= 1.0-1.0/x;
            end
			if RKC<=0.0
                RKC = 0.0+8.0/x;
            end
			Tburno = X(4);
            
            Whtcormap = X(5);
		if Whtcormap>=1.012 
            Whtcormap = 1.012*(1.0-1.0/x);
        end
		if Whtcormap<=0.756  
            Whtcormap = 0.756*(1.0+1.0/x);
        end

		Wltcormap= X(6);
		if Wltcormap>=297.101 
            Wltcormap=297.101*(1.0-1.0/x);
        end
		if Wlcortmap<=246.568 
            Wltcormap = 246.568*(1.0+1.0/x);
        end
    
            RKB = XI(7);
			if RKB>=1.0
                RKB = 1.0-1.0/x;
            end
			if RKB<=0.0
                RKB = 0.0+8.0/x;
            end
   end