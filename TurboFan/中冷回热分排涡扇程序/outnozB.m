%function [ output_args ] = outnoz( input_args )
%OUTNOZ Summary of this function goes here
%  Detailed explanation goes here

  WonozB = WbpBo;	 
	 FARonozB = FARbpB;	 
	      
	       Machso = 1.0;
	       Tsso = 0.833*TbpBo,
           DelHs=1;  
           Hscal=10;
	     while abs(DelHs)>0.000001*Hscal 

		   [ Cpso,kso,Rso] = gasstate( Tsso,FARonozB,1,1);
            Hs=Cpso*Tsso;
            Cs= kso*Rso*Tsso;
	        Cs= Cs^0.5;
		    Vs =Machso*Cs,
		    Hscal = HbpBo-0.5*Vs^2.0;
		    DelHs = Hscal-Hs;
		    Tsso = Tsso+DelHs/Cpso,
          end
	
    	if f_design 
 
		  Ps =Pev;
	      Ts = TbpBo*(Ps/PbpBo)^0.286+10,
          Tscal=TbpBo*(Ps/PbpBo)^0.286,
          
	     while  abs(Ts-Tscal)-0.000001*Tscal>0.0
                Ts = Tscal;
	 		    [ Cpd,kd,Rd] = gasstate( Ts,FARonozB,1,1);
		 		Tscal = TbpBo*(Ps/PbpBo)^((kd-1)/kd),
            end
            Ts=Tscal,
		    Hs=Cpd*Ts;
            VonB=(2*(HbpBo-Hs))^0.5,
            Von1B = VonB;
	      if (VonB-Cs)<0.0 
		
     	     Ps = Pev;
	         Cs= kd*Rd*Ts;
	         Cs= Cs^0.5;
	         RHO = Ps/(Rd*Ts);
	         AonozB= WonozB/(RHO*VonB);
	         MachonB = VonB/Cs;
	         PsonB = Ps,
	         TsonB = Ts,

         else
		    Ps = PbpBo* (Tsso/TbpBo)^(kd/(kd-1.0));
	         RHO = Ps/(Rd*Tsso);
	         AonozB = WonozB/(RHO*Cs);
	         Macho = 1.0;
	         VonB= Cs,
	         PsonB = Ps;
             TsonB=Tsso,
        end
		PirnB = PbpBo,
    end
    
 
	if ~f_trans && ~f_design	%offdesign&wentai
		V = Cs;
	    Ps = Pev;
	    RHO = Ps/(Rso*Tsso);
	    Aocritic = WonozB/(RHO*V);
	    Pir = Ps*(TbpBo/Tsso)^(kso/(kso-1.0));
	     if (AonozB-Aocritic)<=0.0
             MachonB = 1.0;
		     PsonB = Ps*Aocritic/AonozB;
		     PirnB = Pir*Aocritic/AonozB;
             TsonB=Tsso,

	     else
             Area = AonozB; 
		     Ts = 0.833*TbpBo;
                 DelHs=1;  
                 Hscal=10;
	     while abs(DelHs)>0.000001*Hscal 

		  [ Cp,k,R] = gasstate( Ts,FARonozB,1,1);
            Hs=Cp*Ts;
            Cs= k*R*Ts;
	        Cs= Cs^0.5;
            RHO = Ps/(R*Ts);
            V = WonozB/(RHO*Area);		   
		    Hscal = HbpBo-0.5*V^2.0;
		    DelHs = Hscal-Hs;
		    Ts = Ts+DelHs/Cp;
          end
	 	     Mach = V/Cs;
             MachonB = Mach;
		     PsonB = Ps,
             TsonB = Ts,
             PirnB = Ps*(TbpBo/Ts)^(k/(k-1.0)); 
         end
            VonB = V,
  end
   
   	
	Z(8) = (PirnB-PbpBo)/PirnB;	%check liuliang lianxu(error Pt liuchu from given AreaT  and 42P )




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%      Wonoz = Wbpo;	 
% 	 FARonoz = FARbp;	 
% 	      
% 	       Machso = 1.0;
% 	       Tsso = 0.833*Tbpo,
%            DelHs=1;  
%            Hscal=10;
% 	     while abs(DelHs)>0.000001*Hscal 
% 
% 		   [ Cpso,kso,Rso] = gasstate( Tsso,FARonoz,1,1);
%             Hs=Cpso*Tsso;
%             Cs= kso*Rso*Tsso;
% 	        Cs= Cs^0.5;
% 		    Vs =Machso*Cs,
% 		    Hscal = Hbpo-0.5*Vs^2.0;
% 		    DelHs = Hscal-Hs;
% 		    Tsso = Tsso+DelHs/Cpso,
%           end
% 	
%     	if f_design 
%  
% 		  Ps =Pev;
% 	      Ts = Tbpo*(Ps/Pbpo)^0.286+10,
%           Tscal=Tbpo*(Ps/Pbpo)^0.286,
%           
% 	     while  abs(Ts-Tscal)-0.000001*Tscal>0.0
%                 Ts = Tscal;
% 	 		    [ Cpd,kd,Rd] = gasstate( Ts,FARonoz,1,1);
% 		 		Tscal = Tbpo*(Ps/Pbpo)^((kd-1)/kd),
%             end
%             Ts=Tscal,
% 		    Hs=Cpd*Ts;
%             Von=(2*(Hbpo-Hs))^0.5,
%             Von1 = Von;
% 	      if (Von-Cs)<0.0 
% 		
%      	     Ps = Pev;
% 	         Cs= kd*Rd*Ts;
% 	         Cs= Cs^0.5;
% 	         RHO = Ps/(Rd*Ts);
% 	         Aonoz = Wonoz/(RHO*Von),
% 	         Machon = Von/Cs;
% 	         Pson = Ps,
% 	         Tson = Ts,
% 
%          else
% 		    Ps = Pbpo* (Tsso/Tbpo)^(kd/(kd-1.0));
% 	         RHO = Ps/(Rd*Tsso);
% 	         Aonoz = Wonoz/(RHO*Cs),
% 	         Macho = 1.0;
% 	         Von= Cs,
% 	         Pson = Ps;
%              Tson=Tsso,
%         end
% 		Pirn = Pbpo,
%     end
%     
%  
% 	if ~f_trans && ~f_design	%offdesign&wentai
% 		V = Cs;
% 	    Ps = Pev;
% 	    RHO = Ps/(Rso*Tsso);
% 	    Aocritic = Wonoz/(RHO*V);
% 	    Pir = Ps*(Tbpo/Tsso)^(kso/(kso-1.0));
% 	     if (Aonoz-Aocritic)<=0.0
%              Machon = 1.0;
% 		     Pson = Ps*Aocritic/Aonoz,
% 		     Pirn = Pir*Aocritic/Aonoz;
%              Tson=Tsso,
% 
% 	     else
%              Area = Aonoz; 
% 		     Ts = 0.833*Tbpo;
%                  DelHs=1;  
%                  Hscal=10;
% 	     while abs(DelHs)>0.000001*Hscal 
% 
% 		  [ Cp,k,R] = gasstate( Ts,FARonoz,1,1);
%             Hs=Cp*Ts;
%             Cs= k*R*Ts;
% 	        Cs= Cs^0.5;
%             RHO = Ps/(R*Ts);
%             V = Wonoz/(RHO*Area);		   
% 		    Hscal = Hbpo-0.5*V^2.0;
% 		    DelHs = Hscal-Hs;
% 		    Ts = Ts+DelHs/Cp;
%           end
% 	 	     Mach = V/Cs;
%              Machon = Mach;
% 		     Pson = Ps,
%              Tson = Ts,
%              Pirn = Ps*(Tbpo/Ts)^(k/(k-1.0)); 
%          end
%             Von = V,
%   end
%    
%    	
% 	Z(6) = (Pirn-Pbpo)/Pirn;	%check liuliang lianxu(error Pt liuchu from given AreaT  and 42P )

    