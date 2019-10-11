%function [ Wlto,Tlto,Hlto,Plto,FARlt] = LPTurbine( N1cords,Wltcormapds,CRLP2,CAR,MI1 )
%LPTURBINE Summary of this function goes here
%  Detailed explanation goes here
       
   
       
        Wbbt=0;CRLP1=0;CRLPV1=0; Hbbto=0;Pbbto=0;
        WAcgiv = Wbbt*CRLP1*CRLPV1; %���뵼������һ������
        WAbgiv = (Wcomp*CAR-Wbbt)*CRLP2*CRLPV2,        %���뵼�����Ķ�������
		WAcr = Wbbt*CRLP1*(1.0-CRLPV1);         %���붯Ҷ��һ������ 
		WAbr = (Wcomp*CAR-Wbbt)*CRLP2*(1.0-CRLPV2);       %���붯Ҷ�Ķ������� 
		WAcrT = WAcr+WAbr;%���붯Ҷ��������
        
        if WAcrT~=0 %���붯Ҷ����������	
		  HcrT = (WAcr*Hbbto+WAbr*Hcomo)/WAcrT;	
        else
           HcrT=0;
        end
		P411 = (WAcgiv*Pbbto+WAbgiv*Pcomo+Whto*Phto)/(WAcgiv+WAbgiv+Whto);%������������ѹ
		if P411>Phto
            P411 = Phto;	
        end
        W411 = WAcgiv+WAbgiv+Whto;	%��������������
		FAR411 = FARht*Whto/(Whto+(WAcgiv+WAbgiv)*(FARht+1.0));	%����������������
		H411 = (WAcgiv*Hbbto+Whto*Hhto+WAbgiv*Hcomo)/W411;%��������������
         ENTD = 0.0;
	     Hi = H411/4188.9;
	     BI = Hi*(1.0+FAR411);
	     AIB = (BI+160.0*FAR411)/(1.0+3.0*FAR411);
	     To=4.078516*AIB+13.619482-sqrt(0.012357074*AIB^2.0-2.8422896*AIB+177.36742); 
	     PN=0.65109078+(2.*0.16569798*To-231.714176)/(2.*sqrt(0.16569798*To^2.0-231.714176*To+301153.631));
          if To<=600. 
              P=0.2453695+(2.*0.000044725209*To-0.043175541)/(2.*sqrt(0.000044725209*To^2.0-0.043175541*To+11.2577253));
          end
          if To>600. 
              P=0.2220757+(2.*0.008729571*To-3.4619954)/(2.*sqrt(0.008729571*To^2.0-3.4619954*To+14144.5963));  
          end
              ENTD=(P+FAR411*PN)/(1.+FAR411); 
              [ Ho ] = gashi(  To, FAR411 );
              T411=To+(Hi-Ho/4188.9)/ENTD;%�������������� 
     if f_design  
 
		ScallN1cor = N1cords*T411^0.5/N1;
		Wltcormap = Wltcormapds;
    end
    
    CNTL = ScallN1cor*N1/T411^0.5;	%����ת��
    
    Alpha=0;
    PointData=struct('X',Alpha,'Y',CNTL,'Z',Wltcormap);
    rowSize=12; colSize=11;
	EffLT = lookup('myGLPTEff.txt',PointData.Y,PointData.Z,rowSize,colSize) ;   %���ѹ����Ч��
    DHTL =lookup('mfGLPTDht.txt',PointData.Y,PointData.Z,rowSize,colSize);   %���ѹ���ֹ�����
    
    WGccall = W411*T411^0.5/P411,	%���㻻������  
    
   
    
    TLWork = (KFanWork+KBWork)/EffLS;%ת�����ù�
    
    DHTccl = TLWork/(W411*T411); %���õ�λ��
    
  
	if f_design%������Ƶ����ϵ��
	 
		ScallDHTL = DHTccl/DHTL;
		ScallEffLT = EffLTds/EffLT;
		ScallWTLc = Wltcormap/WGccall;
    end
    
    DHTL = ScallDHTL*DHTL;	 
	EffLT = ScallEffLT*EffLT,	 
	WGccall = ScallWTLc*WGccall;	 
	DHTcl = DHTccl*T411,
    
    XI(6)=Wltcormap;
    XII(6)=Wltcormap;
	
	Z(3)=(Wltcormap-WGccall)/WGccall;	
	Z(4)=(DHTccl-DHTL)/DHTccl;
    
     Hlto = H411-DHTcl,		    %����ʵ�ʳ�����	
           
           ENTD = 0.0;
	       Hi = Hlto/4188.9;
	       BI = Hi*(1.0+FAR411);
	       AIB = (BI+160.0*FAR411)/(1.0+3.0*FAR411);
	       To=4.078516*AIB+13.619482-sqrt(0.012357074*AIB^2.0-2.8422896*AIB+177.36742); 
	       PN=0.65109078+(2.*0.16569798*To-231.714176)/(2.*sqrt(0.16569798*To^2.0-231.714176*To+301153.631));
          if To<=600. 
              P=0.2453695+(2.*0.000044725209*To-0.043175541)/(2.*sqrt(0.000044725209*To^2.0-0.043175541*To+11.2577253));
          end
          if To>600. 
              P=0.2220757+(2.*0.008729571*To-3.4619954)/(2.*sqrt(0.008729571*To^2.0-3.4619954*To+14144.5963));  
          end
              ENTD=(P+FAR411*PN)/(1.+FAR411); 
              [Ho] = gashi(To,FAR411);
               Tlto=To+(Hi-Ho/4188.9)/ENTD,
               Tlto11=Tlto;%�޸�
  
              
              Cptl=DHTcl/(T411-Tlto);
              amw = 28.97-.946186*FAR411;
              R_eng = 1.986375/amw;		%Ӣ��
	          Rtl = R_eng*4185.7666,
              
              PRKtl=(1-(1-Tlto/T411)/EffLT)^(-(Cptl/Rtl));%���ͱ�
              
              Plto=P411/PRKtl;%��ѹ���ֳ�����ѹ   
              Plto11=Plto;

	
    %�������
	if WAcrT~=0
	 
			
             FARlt = FAR411*W411/(Whto+WAcrT*(FAR411+1.0));
	         Wlto = W411+WAcrT,
	         Hlto = (WAcrT*HcrT+W411*Hlto)/Wlto;
        
           ENTD = 0.0;
	       Hi = Hlto/4188.9;
	       BI = Hi*(1.0+FARlt);
	       AIB = (BI+160.0*FARlt)/(1.0+3.0*FARlt);
	       To=4.078516*AIB+13.619482-sqrt(0.012357074*AIB^2.0-2.8422896*AIB+177.36742); 
	       PN=0.65109078+(2.*0.16569798*To-231.714176)/(2.*sqrt(0.16569798*To^2.0-231.714176*To+301153.631));
          if To<=600. 
              P=0.2453695+(2.*0.000044725209*To-0.043175541)/(2.*sqrt(0.000044725209*To^2.0-0.043175541*To+11.2577253));
          end
          if To>600. 
              P=0.2220757+(2.*0.008729571*To-3.4619954)/(2.*sqrt(0.008729571*To^2.0-3.4619954*To+14144.5963));  
          end
              ENTD=(P+FARlt*PN)/(1.+FARlt); 
              [ Ho ] = gashi(  To, FARlt );
              Tlto=To+(Hi-Ho/4188.9)/ENTD;   
              Tlto11 = Tlto;
              
              Cptl=DHTcl/(T411-Tlto);
              amw = 28.97-.946186*FARlt;
              R_eng = 1.986375/amw;		
	          Rtl = R_eng*4185.7666;
              
              PRKtl=(1-(1-Tlto/T411)/EffLT)^(-(Cptl/Rtl));
              
              Plto=P411/PRKtl;  
              Plto11=Plto;
              
    end
           
	if WAcrT==0 
 
		FARlt = FAR411;
		Wlto = W411;
    end
    %if f_design==false
             %fid=fopen('wolunpzb.txt','at+');
             %if lsm==0
             %fprintf(fid,'MECHN1=%5.1f Tboo=%5.1f PRKtl=%6.4f Wlto=%7.4f  PRKth=%6.4f Whto=%7.4f Wboo=%7.4f Wcomp=%7.4f N2=%7.4f N2cor=%6.4f\r\n',MECHN1,Tboo,PRKtl,Wlto,PRKth,Whto,Wboo,Wcomp,N2,N2cor);
             %else
             %fprintf(fid,'lsm=%d MECHN1=%5.1f Tboo=%5.1f PRKtl=%6.4f Wlto=%7.4f  PRKth=%6.4f Whto=%7.4f Wboo=%7.4f Wcomp=%7.4f N2=%7.4f N2cor=%6.4f\r\n',lsm,MECHN1,Tboo,PRKtl,Wlto,PRKth,Whto,Wboo,Wcomp,N2,N2cor);
             %end
             %fclose(fid);
    %end
    %Tlto=780;%�޸�
    %Plto=Plto-21000;%�޸�
    %Hltoo=gashi(Tlto,0);%�޸�    
	%if(m_bDesign) PRT1ds = P41/P42;
    
	
	
    
    
    
    
    