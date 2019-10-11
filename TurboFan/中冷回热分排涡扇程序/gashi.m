function [ Hi ] = gashi(  T, FuelAirRatio )
%GASHI Summary of this function goes here
%  Detailed explanation goes here


	
	if FuelAirRatio < 0 
        FuelAirRatio = 0.0;
    end 
    
	if FuelAirRatio > 0.067623 
        FuelAirRatio = 0.067623;
    end

	b_FuelAirRatio = 0;
    
	if FuelAirRatio == 0.0 
        b_FuelAirRatio = 1;
    end

	%将国际单位换算成英制单位(开氏--华氏)
    TE = T*9.0/5.0;
    if TE < 300.0 
        TE = 300.0;
    end
    
	if  TE > 4000.0 
        TE = 4000.0;
    end

	%计算空气的焓值
    Hia = (((((((1.2644425e-26*TE-2.0752522e-22)*TE+1.270263e-18)*TE-3.0256518e-15)*TE-1.6794594e-12)*TE+2.1839826e-08)*TE-2.576844e-05)*TE+2.5020051e-01)*TE-1.7558886;

	switch b_FuelAirRatio

		case 1 
	
			% 将英制单位换算成国际单位 (2325.4259=4185.7666*5.0/9.0)
			Hi = Hia*2325.4259;
		 otherwise
             
		  %计算燃气的焓值
			Hif = (((((((9.0848388e-26*TE-1.9050949e-21)*TE+1.7021525e-17)*TE-8.4102208e-14)*TE+2.4921698e-10)*TE-4.5906332e-07)*TE+6.129315e-04)*TE+7.3816638e-02)*TE+3.058153e+01;
            Hif = (Hia+FuelAirRatio*Hif)/(1.0+FuelAirRatio);

			% 将英制单位换算成国际单位
            Hi = Hif*2325.4259;
    end
	
	T = TE*5.0/9.0;
	