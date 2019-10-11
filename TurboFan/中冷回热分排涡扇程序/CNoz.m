%function [ output_args ] = CNoz(Pev,lamdaguss )
%CNOZ Summary of this function goes here
%  Detailed explanation goes here



   %[ Wlto,Tlto,Hlto,Plto,FARlt]= LPTurbine( 0.75,250,0.5,0.2,100 );
     Plto=Plto*sigtn;
     Wcnoz = Wlto;	 
	 FARcnoz = FARlt;	
   
	  %void CNozzle::CalSonic(double Hi, double Ti, double &Ts, double &Cs, double &R, double &k)
 
 
	      
	       Machso = 1.0;
	       Tsso = 0.833*Tlto;
           DelHs=1;  
           Hscal=10;
	     while abs(DelHs)>0.000001*Hscal 

           [ Cpso,kso,Rso] = gasstate( Tsso,FARcnoz,1,1);
            Hs=gashi(Tsso,FARcnoz);
            Cs= kso*Rso*Tsso;
	        Cs= Cs^0.5,
		    Vs =Machso*Cs;
		    Hscal = Hlto-0.5*Vs^2.0;
		    DelHs = Hscal-Hs;
		    Tsso = Tsso+DelHs/Cpso;
         end
          
    	if f_design 
 
	      Ps =Pev;
	      Ts = Tlto*(Ps/Plto)^0.286+10;
          Tscal=Tlto*(Ps/Plto)^0.286;
          
	      while  abs(Ts-Tscal)-0.000001*Tscal>0.0
                Ts = Tscal;
	 		    [ Cpd,kd,Rd] = gasstate( Ts,FARcnoz,1,1);
		 		Tscal = Tlto*(Ps/Plto)^((kd-1)/kd);
            end
            Ts=Tscal;
			Hs=gashi(Ts,FARcnoz);
            Vo=(2*(Hlto-Hs))^0.5,
            Vo1 = Vo
	      if (Vo-Cs)<0.0 
            
     	     Ps = Pev;
	         Cs= kd*Rd*Ts;
	         Cs= Cs^0.5;
	         RHO = Ps/(Rd*Ts);
	         Areao = Wcnoz/(RHO*Vo),
	         Macho = Vo/Cs;
	         Pso = Ps,
	         Tso = Ts,

         else
             Ps = Plto* (Tsso/Tlto)^(kd/(kd-1.0)),
	         RHO = Ps/(Rd*Tsso);
	         Areao = Wlto/(RHO*Cs),
             Macho = 1.0;
	         Vo= Cs,
	         Pso = Ps,
             Tso=Tsso,
        end
		Pir = Plto,
        end
 
	if ~f_trans && ~f_design	%offdesign&wentai
		
     	V = Cs;
	    Ps = Pev;
	    RHO = Ps/(Rso*Tsso);
	    Aocritic = Wcnoz/(RHO*V);
	    Pir = Ps*(Tlto/Tsso)^(kso/(kso-1.0));
        
     
	     if (Areao-Aocritic)<=0.0
             Macho = 1.0;
		     Pso = Ps*Aocritic/Areao,
		     Pir = Pir*Aocritic/Areao;
             Tso=Tsso,
             
	     else
             Area = Areao; 
		         Ts = 0.833*Tlto;
                 DelHs=1;  
                 Hscal=10;
	     while abs(DelHs)>0.000001*Hscal 

		    [ Cp,k,R] = gasstate( Ts,FARcnoz,1,1);
            Hs=gashi(Ts,FARcnoz);
            
            if k<=0
                error('cuowu')
                k=1.3;
            end
            if R<=0
                R=287;
            end
            Cs= k*R*Ts;
            if Cs<=0
                error('cuowu')
            end
	        Cs= Cs^0.5;
            RHO = Ps/(R*Ts);
            V = Wlto/(RHO*Area);		   
		    Hscal = Hlto-0.5*V^2.0;
		    DelHs = Hscal-Hs;
		    Ts = Ts+DelHs/Cp;
%             Ts=abs(Ts);
            if Ts<=0
            error('cuowu')
            end
          end
	 	     Mach = V/Cs;
             Macho = Mach;
		     Pso = Ps;
             Tso=Ts;
             Pir = Ps*(Tlto/Ts)^(k/(k-1.0));
         end 
            Vo = V,            
  end
       
	
	
	  	
   
	  Z(5) = (Pir-Plto)/Pir;	%check liuliang lianxu(error Pt liuchu from given AreaT  and 42P )
  
    

    

  
    

    
