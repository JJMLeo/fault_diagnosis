%function [ output_args ] = perform( input_args )
%PERFORM Summary of this function goes here
%  Detailed explanation goes here



	Mach = Ma;
	Ts = Tev;
   [ Cp,k,R] = gasstate( Ts,0.0,1,1);
    Cs= kso*Rso*Ts;
    Cs= Cs^0.5; 
    V = Mach*Cs;

    maxA9 = 0.6350;%//收扩喷管出口面积机械限位
	%//按俄计算速度系数的方法之一计算速度系数
	fai_m_dVo =FaiVelo8; 
	if f_design	
		fai_m_dVo = FaiVelo8;
    end
	
		W1 = Wfano,
		A9 = Areao; A19 =Aonoz;
		A8 = A9; m_dA18 = A19;
   if traditional==0    %新加的    
		Thrust=(Wcnoz*Vo*fai_m_dVo+Wonoz*Von*fai_m_dVo+WonozB*VonB*fai_m_dVo-W1*V)+(Pso-Pev)*Areao+(Pson-Pev)*Aonoz+(PsonB-Pev)*AonozB;
		Thrust1=Wcnoz*Vo*fai_m_dVo+(Pso-Pev)*Areao-W1*V/(1+BPR);%内涵
        Thrust2=Wonoz*Von*fai_m_dVo-W1*BPR*V/(1+BPR)*(1- icper)+(Pson-Pev)*Aonoz;%外涵道
        Thrust3=WonozB*VonB*fai_m_dVo-W1*BPR*V/(1+BPR)* icper+(PsonB-Pev)*AonozB;%中间涵道
   else  %新加的
       Thrust=(Wcnoz*Vo*fai_m_dVo+Wonoz*Von*fai_m_dVo-W1*V)+(Pso-Pev)*Areao+(Pson-Pev)*Aonoz;
       Thrust1=Wcnoz*Vo*fai_m_dVo+(Pso-Pev)*Areao-W1*V/(1+BPR);
       Thrust2=Wonoz*Von*fai_m_dVo-W1*BPR*V/(1+BPR)+(Pson-Pev)*Aonoz;
   end
	%//计算耗油率
	Thrust = Thrust/9.8%%推力的单位是daN  宋兴超2012.4.23
	SFC = Wfb*3600.0/Thrust
	BPR = (Wfano-Wboo)/Wboo
    Fs=Thrust/Wfano;%%单位推力的单位也是daN
	