%function [ output_args ] = booster( input_args )
%BOOSTER Summary of this function goes here
%  Detailed explanation goes here
    Pstd = 101325.0;
	Tstd = 288.15;
	Ra = 286.9;
    FARboo=0;
    Alpha=0;
  
   
    Theta =(Tfano/Tstd)^0.5;
	Delta = Pfano/Pstd;
    
    %%Wboo=Wfano/(1+BPR);%进入booster流量%%这应该是计算设计点BPR已知的情况下，非设计点BPR未知，所以不能这样用
    
	if f_design
         Wboo=Wfano/(1+BPR);%进入booster流量%%这应该是计算设计点BPR已知的情况下，非设计点BPR未知，所以不能这样用
        ThetaKB = Theta;
        Wboods=Wboo;
        icper=1/BPR;%%
    end 
    
    
	NBcor = N1*ThetaKB/(100.*Theta);	%换算转速
    
    PointData=struct('X',Alpha,'Y',NBcor,'Z',RKB),
	rowSize=12; colSize=10;
	Effboo =lookup('GBoosterEff.txt',PointData.Y,PointData.Z,rowSize,colSize) ;   %查booster效率
	Wcorboo= lookup('GBoosterWAc.txt',PointData.Y,PointData.Z,rowSize,colSize);   %查换算流量
    PRboo =lookup('GBoosterPr.txt',PointData.Y,PointData.Z,rowSize,colSize);   %查压比
	Wboo = Wcorboo*Delta/Theta,	%计算物理流量

	if f_design	%计算设计点耦合系数
		
        ScallPRboo =(PRboods-1.0)/(PRboo-1.0);
		ScallEffboo =Effboods/Effboo;
		ScallWboo =Wboods/Wboo;
    end
    
	
	PRboo =ScallPRboo*(PRboo-1.0)+1.0,	%修正压比
	Effboo =ScallEffboo*Effboo,	%修正效率
	Wcorboo=ScallWboo*Wcorboo;	%修正换算流量
	NB=100.0*Theta*NBcor/ThetaKB;	%修正相对物理转速
	Wboo=ScallWboo*Wboo,	%修正后的物理流量

    [Cpboo,kboo,Rboo] = gasstate( Tfano,0,PRboo,Effboo);
    
    
    Tboo = Tfano*(1.0+(PRboo^((kboo-1.0)/kboo)-1)/Effboo);%booster出口总温
    Hboo =gashi(Tboo,0),%booster出口总焓
    Pboo = Pfano*PRboo*sigfc;
    Tboo1=Tboo;
    Pboo1=Pboo;
    Wbpoo=Wfano-Wboo;%%新加的
    BPR=Wbpoo/Wboo;%%新加的
   % icper=1/BPR;%%外涵引气系数
    %icper=0.074;
    if traditional==0%%
       [Tboo,Tbpoi,Deltp1,Deltp2,ytz1,mcore1,L1,L2,L3]=intercooler(Tfano,Tboo,Pboo,Pfano,Wfano,icper,BPR);
	  Pboo = Pfano*PRboo*sigfc-Deltp1;%booster出口总压
    end%%
       KBWork = Wboo*(Hboo-Hfano);	%booster做功
%放气代码    
%if  f_design==false & MECHN1<=99 
    %N2corBleed=N2/(100.*(Tboo/Tstd)^0.5);
    %NforBleed=[0.75848,0.85016,0.88318,0.90706,0.92537,0.964,0.969,0.99145];
    %Bleed=[35.7975,26.266,20.6928,15.986,5,4,1,0.0];
    %Gasbleed=interp1( NforBleed,Bleed,N2corBleed,'cubic');
    %Wboo=(1-Gasbleed/100)*Wboo;
%end
     SM3=surgmargin(Wboo,PRboo,NBcor,ScallPRboo, ScallWboo,'GBoosterWAc.txt','GBoosterPr.txt',12,10,Theta,Delta); %喘震裕度

     XI(7)=RKB;
     XII(7)=RKB;
     XI(8)=icper;
     XII(8)=icper;
   
    