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
    
    %%Wboo=Wfano/(1+BPR);%����booster����%%��Ӧ���Ǽ�����Ƶ�BPR��֪������£�����Ƶ�BPRδ֪�����Բ���������
    
	if f_design
         Wboo=Wfano/(1+BPR);%����booster����%%��Ӧ���Ǽ�����Ƶ�BPR��֪������£�����Ƶ�BPRδ֪�����Բ���������
        ThetaKB = Theta;
        Wboods=Wboo;
        icper=1/BPR;%%
    end 
    
    
	NBcor = N1*ThetaKB/(100.*Theta);	%����ת��
    
    PointData=struct('X',Alpha,'Y',NBcor,'Z',RKB),
	rowSize=12; colSize=10;
	Effboo =lookup('GBoosterEff.txt',PointData.Y,PointData.Z,rowSize,colSize) ;   %��boosterЧ��
	Wcorboo= lookup('GBoosterWAc.txt',PointData.Y,PointData.Z,rowSize,colSize);   %�黻������
    PRboo =lookup('GBoosterPr.txt',PointData.Y,PointData.Z,rowSize,colSize);   %��ѹ��
	Wboo = Wcorboo*Delta/Theta,	%������������

	if f_design	%������Ƶ����ϵ��
		
        ScallPRboo =(PRboods-1.0)/(PRboo-1.0);
		ScallEffboo =Effboods/Effboo;
		ScallWboo =Wboods/Wboo;
    end
    
	
	PRboo =ScallPRboo*(PRboo-1.0)+1.0,	%����ѹ��
	Effboo =ScallEffboo*Effboo,	%����Ч��
	Wcorboo=ScallWboo*Wcorboo;	%������������
	NB=100.0*Theta*NBcor/ThetaKB;	%�����������ת��
	Wboo=ScallWboo*Wboo,	%���������������

    [Cpboo,kboo,Rboo] = gasstate( Tfano,0,PRboo,Effboo);
    
    
    Tboo = Tfano*(1.0+(PRboo^((kboo-1.0)/kboo)-1)/Effboo);%booster��������
    Hboo =gashi(Tboo,0),%booster��������
    Pboo = Pfano*PRboo*sigfc;
    Tboo1=Tboo;
    Pboo1=Pboo;
    Wbpoo=Wfano-Wboo;%%�¼ӵ�
    BPR=Wbpoo/Wboo;%%�¼ӵ�
   % icper=1/BPR;%%�⺭����ϵ��
    %icper=0.074;
    if traditional==0%%
       [Tboo,Tbpoi,Deltp1,Deltp2,ytz1,mcore1,L1,L2,L3]=intercooler(Tfano,Tboo,Pboo,Pfano,Wfano,icper,BPR);
	  Pboo = Pfano*PRboo*sigfc-Deltp1;%booster������ѹ
    end%%
       KBWork = Wboo*(Hboo-Hfano);	%booster����
%��������    
%if  f_design==false & MECHN1<=99 
    %N2corBleed=N2/(100.*(Tboo/Tstd)^0.5);
    %NforBleed=[0.75848,0.85016,0.88318,0.90706,0.92537,0.964,0.969,0.99145];
    %Bleed=[35.7975,26.266,20.6928,15.986,5,4,1,0.0];
    %Gasbleed=interp1( NforBleed,Bleed,N2corBleed,'cubic');
    %Wboo=(1-Gasbleed/100)*Wboo;
%end
     SM3=surgmargin(Wboo,PRboo,NBcor,ScallPRboo, ScallWboo,'GBoosterWAc.txt','GBoosterPr.txt',12,10,Theta,Delta); %����ԣ��

     XI(7)=RKB;
     XII(7)=RKB;
     XI(8)=icper;
     XII(8)=icper;
   
    