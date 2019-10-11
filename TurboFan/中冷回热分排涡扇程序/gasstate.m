function [ Cp,k,R] = gasstate( TI,FAR, PRK,Eff)
%GASSTATE Summary of this function goes here
%  Detailed explanation goes here
    amw = 28.97-.946186*FAR;
    R_eng = 1.986375/amw;		%england
	R = R_eng*4185.7666;
    
	if FAR < 0
       FAR = 0.0;
    end
	if FAR > 0.067623
        FAR = 0.067623;
    end

	b_FuelAirRatio = 0;
	if FAR == 0.0
        b_FuelAirRatio = 1;
    end
          
         Cp=1100;
         Cpcal=1100+100;
   
   while  abs(Cp-Cpcal)-0.0000001*Cpcal>0.0
          Cp=Cpcal;
          k = Cp/(Cp-R); 
          TO = TI*(1.0+(PRK^((k-1)/k)-1.0)/Eff);
          T=(TI+TO)/2;  
	      % K TURNS TO F    
	      TE = T*9.0/5.0;
	      if  TE < 300.0
              TE = 300.0;
          end
	      if TE > 4000.0
             TE = 4000.0;
          end
 
	       % AIR CP
	     Cpa = ((((((1.011554e-25*TE-1.452677e-21)*TE+7.6215767e-18)*TE-1.5128259e-14)*TE-6.7178376e-12)*TE+6.5519486e-08)*TE-5.1536879e-05)*TE+2.5020051e-01;

	      switch b_FuelAirRatio
                 case 1
			
		              %ENGLAND TURNS TO INTERNATIONAL
			          Cpcal = Cpa*4185.7666;
                 otherwise
		                %GASAIR
			          Cpf = ((((((7.267871e-25*TE-1.3335668e-20)*TE+1.0212913e-16)*TE-4.2051104e-13)*TE+9.9686793e-10)*TE-1.3771901e-06)*TE+1.225863e-03)*TE+7.3816638e-02;			
			          Cpf = (Cpa+FAR*Cpf)/(1.0+FAR);

			          % INTERNATIONAL
			         Cpcal= Cpf*4185.7666;
             end	

	            
         
      end
      
      Cp=Cpcal;
% if imag(Cp)>0
%     error('cuowu')
% end

    
    
    

	