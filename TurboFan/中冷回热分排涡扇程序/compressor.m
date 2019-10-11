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
    
    Wcomp=Wboo;%����ѹ��������
    
	if f_design
        ThetaKC = Theta;
        Wcompds=Wcomp;
    end 
    
    
	N2cor = N2*ThetaKC/(100.*Theta);%����ת��
    
    PointData=struct('X',Alpha,'Y',N2cor,'Z',RKC);
	rowSize=10; colSize=5;
	Effcomp =lookup('GCprEff.txt',PointData.Y,PointData.Z,rowSize,colSize) ; %��ѹ����Ч��
	Wcorcomp= lookup('GCprWAc.txt',PointData.Y,PointData.Z,rowSize,colSize); %�黻������
    PRcomp =lookup('GCprPr.txt',PointData.Y,PointData.Z,rowSize,colSize);  %��ѹ��
	Wcomp = Wcorcomp*Delta/Theta;	%������������

	if f_design	%������Ƶ����ϵ��
		
        ScallPRcomp =(PRcompds-1.0)/(PRcomp-1.0);
		ScallEffcomp =Effcompds/Effcomp;
		ScallWcomp =Wcompds/Wcomp;
    end
    
	
	PRcomp = ScallPRcomp*(PRcomp-1.0)+1.0;	%����ѹ��
	Effcomp= ScallEffcomp*Effcomp;	%����Ч��
	Wcorcomp = ScallWcomp*Wcorcomp;%������������
	N2 = 100.0*Theta*N2cor/ThetaKC;	%�����������ת��
	Wcomp = ScallWcomp*Wcomp;	%���������������
    
    
    [ Cpcomp,kcomp,Rcomp] = gasstate( Tboo,0,PRcomp,Effcomp);
    
    Pcomo = Pboo*PRcomp%ѹ����������ѹ
    Tcomo = Tboo*(1.0+(PRcomp^((kcomp-1.0)/kcomp)-1)/Effcomp)%ѹ������������
    Tcomo11 = Tcomo;
    Pcomo11 = Pcomo;
    Hcomo =gashi(Tcomo,0);%ѹ������������
    KCWork = Wcomp*(Hcomo-Hboo)%ѹ��������
	%Hcomoo =gashi(Tcomoi,0);%���Ⱥ�ѹ������������
	SM2 = surgmargin(Wcomp,PRcomp,N2cor,ScallPRcomp, ScallWcomp,'GCprWAc.txt','GCprPr.txt',10,5,Theta,Delta); %����ԣ��
    
    
    
	%KCWork = Wcomp*(Hcomo-Hboo);%ѹ��������
    
    Wcompout=Wcomp*(1.0-CAR);%ѹ������������  CAR����ȴ������
    
     XI(2)=RKC;
     XII(2)=RKC;
     XI(3)=N2;
     Z(7)=(Wcomp-Wboo)/Wcomp;%%/Wcomp�Ǻ������ϵģ�ԭ��û�б�ֵ
     
	