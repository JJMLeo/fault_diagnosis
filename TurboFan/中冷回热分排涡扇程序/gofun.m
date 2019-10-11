function fengine=gofun(x)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
kk=1,MECHN1=100,MECHN2=100,AREA=1,ALTITUDE=10668,MACH=0.82,RC=0.7,RF=0.4,icper=1.0/13.5;

   f_throttle=false;f_guess=0;f_trans =0;
   
   traditional=0;
   f_bleedgas=0;
  
    XI=[0,0,0,0,0,0,0,0];
    XII=[0,0,0,0,0,0,0,0];
    Z=[0,0,0,0,0,0,0,0];
    initial;
    
    PRboods=x(1);%自变量的定义
    PRcompds=x(2);
    Tburnods=x(3);
    
    
    ondesign;
    
    fclose('all')
    fengine(1) =(-1)* Thrust;
    fengine(2)= SFC;

end

