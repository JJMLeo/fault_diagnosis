%function [ Tfano,Pfano,Hfano,N1,Wfano,KFanWork ] = fan( N1,RKF )
%FAN Summary of this function goes here
%  Detailed explanation goes here

    Pstd = 101325.0;%标准大气条件下大气静压
	Tstd = 288.15;%标准大气条件下大气静温
	Ra = 286.9;
    FARfan=0;%油气比
   
  
    Theta =(Tino/Tstd)^0.5;
	Delta = Pino/Pstd;
	if f_design
        ThetaKF = Theta;
   end 
    
    
	N1cor = N1*ThetaKF/(100.*Theta),	%换算转速
    
    PointData=struct('X',0.0,'Y',N1cor,'Z',RKF);

	rowSize=12;  colSize=10;
	Efffan =lookup('GFanEff.txt',PointData.Y,PointData.Z,rowSize,colSize) ;   %查风扇效率
	Wcorfan = lookup('GFanWAc.txt',PointData.Y,PointData.Z,rowSize,colSize);   %查风扇换算流量
    PRfan =lookup('GFanPr.txt',PointData.Y,PointData.Z,rowSize,colSize);   %查风扇压比
	Wfano = Wcorfan*Delta/Theta;	%计算物理流量

	if f_design	%计算设计点耦合系数
		
        ScallPRfan =(PRfands-1.0)/(PRfan-1.0);
		ScallEfffan =Efffands/Efffan;
		ScallWfan =Wfands/Wfano;
  end
	
	PRfan = ScallPRfan*(PRfan-1.0)+1.0,	%修正压比
	Efffan= ScallEfffan*Efffan,	%修正效率
	Wcorfan = ScallWfan*Wcorfan;	%修正换算流量
	N1 = 100.0*Theta*N1cor/ThetaKF,	%相对物理转速
	Wfano = ScallWfan*Wfano;	%修正物理流量
    
    
    [ Cpfan,kfan,Rfan] = gasstate( Tino,0,PRfan,Efffan); 
    
    
    Tfano = Tino*(1.0+(PRfan^((kfan-1.0)/kfan)-1)/Efffan),%风扇出口总温
	Pfano = Pino*PRfan,%风扇出口总压
	Hfano =gashi(Tfano,0),%风扇出口总焓
	
	
	SM1 = surgmargin(Wfano,PRfan,N1cor,ScallPRfan, ScallWfan,'GFanWAc.txt','GFanPr.txt',12,10,Theta,Delta);%喘震裕度
    
  
    
	KFanWork = Wfano*(Hfano-Hino);	%风扇做功
    
    XI(1)=RKF;
    XII(1)=RKF;
    XII(3)=N1;
     