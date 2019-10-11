%function [ Tfano,Pfano,Hfano,N1,Wfano,KFanWork ] = fan( N1,RKF )
%FAN Summary of this function goes here
%  Detailed explanation goes here

    Pstd = 101325.0;%��׼���������´�����ѹ
	Tstd = 288.15;%��׼���������´�������
	Ra = 286.9;
    FARfan=0;%������
   
  
    Theta =(Tino/Tstd)^0.5;
	Delta = Pino/Pstd;
	if f_design
        ThetaKF = Theta;
   end 
    
    
	N1cor = N1*ThetaKF/(100.*Theta),	%����ת��
    
    PointData=struct('X',0.0,'Y',N1cor,'Z',RKF);

	rowSize=12;  colSize=10;
	Efffan =lookup('GFanEff.txt',PointData.Y,PointData.Z,rowSize,colSize) ;   %�����Ч��
	Wcorfan = lookup('GFanWAc.txt',PointData.Y,PointData.Z,rowSize,colSize);   %����Ȼ�������
    PRfan =lookup('GFanPr.txt',PointData.Y,PointData.Z,rowSize,colSize);   %�����ѹ��
	Wfano = Wcorfan*Delta/Theta;	%������������

	if f_design	%������Ƶ����ϵ��
		
        ScallPRfan =(PRfands-1.0)/(PRfan-1.0);
		ScallEfffan =Efffands/Efffan;
		ScallWfan =Wfands/Wfano;
  end
	
	PRfan = ScallPRfan*(PRfan-1.0)+1.0,	%����ѹ��
	Efffan= ScallEfffan*Efffan,	%����Ч��
	Wcorfan = ScallWfan*Wcorfan;	%������������
	N1 = 100.0*Theta*N1cor/ThetaKF,	%�������ת��
	Wfano = ScallWfan*Wfano;	%������������
    
    
    [ Cpfan,kfan,Rfan] = gasstate( Tino,0,PRfan,Efffan); 
    
    
    Tfano = Tino*(1.0+(PRfan^((kfan-1.0)/kfan)-1)/Efffan),%���ȳ�������
	Pfano = Pino*PRfan,%���ȳ�����ѹ
	Hfano =gashi(Tfano,0),%���ȳ�������
	
	
	SM1 = surgmargin(Wfano,PRfan,N1cor,ScallPRfan, ScallWfan,'GFanWAc.txt','GFanPr.txt',12,10,Theta,Delta);%����ԣ��
    
  
    
	KFanWork = Wfano*(Hfano-Hino);	%��������
    
    XI(1)=RKF;
    XII(1)=RKF;
    XII(3)=N1;
     