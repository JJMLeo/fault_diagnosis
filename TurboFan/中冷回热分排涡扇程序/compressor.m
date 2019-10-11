%function [ Tcomo,Pcomo,Hcomo,Wcompout,Wcomp,N2, KCWork] = compressor( N2,RKC,BPR,CAR)
%COMPRESSOR Summary of this function goes here
%  Detailed explanation goes here

   
    Pstd = 101325.0;
	Tstd = 288.15;
	Ra = 286.9;
    FARcomp=0;
    Alpha=0;
  
   
    Theta =(Tboo/Tstd)^0.5;
	Delta = Pboo/Pstd;
    
    Wcomp=Wboo;%进入压气机流量
    
	if f_design
        ThetaKC = Theta;
        Wcompds=Wcomp;
    end 
    
    
	N2cor = N2*ThetaKC/(100.*Theta);%换算转速
    
    PointData=struct('X',Alpha,'Y',N2cor,'Z',RKC);
	rowSize=10; colSize=5;
	Effcomp =lookup('GCprEff.txt',PointData.Y,PointData.Z,rowSize,colSize) ; %查压气机效率
	Wcorcomp= lookup('GCprWAc.txt',PointData.Y,PointData.Z,rowSize,colSize); %查换算流量
    PRcomp =lookup('GCprPr.txt',PointData.Y,PointData.Z,rowSize,colSize);  %查压比
	Wcomp = Wcorcomp*Delta/Theta;	%计算物理流量

	if f_design	%计算设计点耦合系数
		
        ScallPRcomp =(PRcompds-1.0)/(PRcomp-1.0);
		ScallEffcomp =Effcompds/Effcomp;
		ScallWcomp =Wcompds/Wcomp;
    end
    
	
	PRcomp = ScallPRcomp*(PRcomp-1.0)+1.0;	%修正压比
	Effcomp= ScallEffcomp*Effcomp;	%修正效率
	Wcorcomp = ScallWcomp*Wcorcomp;%修正换算流量
	N2 = 100.0*Theta*N2cor/ThetaKC;	%修正相对物理转速
	Wcomp = ScallWcomp*Wcomp;	%修正后的物理流量
    
    
    [ Cpcomp,kcomp,Rcomp] = gasstate( Tboo,0,PRcomp,Effcomp);
    
    Pcomo = Pboo*PRcomp%压气机出口总压
    Tcomo = Tboo*(1.0+(PRcomp^((kcomp-1.0)/kcomp)-1)/Effcomp)%压气机出口总温
    Tcomo11 = Tcomo;
    Pcomo11 = Pcomo;
    Hcomo =gashi(Tcomo,0);%压气机出口总焓
    KCWork = Wcomp*(Hcomo-Hboo)%压气机做功
	%Hcomoo =gashi(Tcomoi,0);%换热后压气机出口总焓
	SM2 = surgmargin(Wcomp,PRcomp,N2cor,ScallPRcomp, ScallWcomp,'GCprWAc.txt','GCprPr.txt',10,5,Theta,Delta); %喘震裕度
    
    
    
	%KCWork = Wcomp*(Hcomo-Hboo);%压气机做功
    
    Wcompout=Wcomp*(1.0-CAR);%压气机出口流量  CAR是冷却引气量
    
     XI(2)=RKC;
     XII(2)=RKC;
     XI(3)=N2;
     Z(7)=(Wcomp-Wboo)/Wcomp;%%/Wcomp是后来加上的，原本没有比值
     
	