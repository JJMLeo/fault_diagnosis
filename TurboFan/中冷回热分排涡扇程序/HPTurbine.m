%function [Thto,Hhto,Phto,Whto,FARht] = HPTurbine( N2cords,CRHP2,CAR,Whtcormapds,MI2 )
%HPTUBINE Summary of this function goes here
%  Detailed explanation goes here
      

        Wbbt=0;CRHP1=0;CRHPV1=0; Hbbto=0;Pbbto=0;
        WAcgiv = Wbbt*CRHP1*CRHPV1;%���뵼������һ������        
		WAbgiv = (Wcomp*CAR-Wbbt)*CRHP2*CRHPV2; %���뵼�����Ķ�������       
		WAcr = Wbbt*CRHP1*(1.0-CRHPV1);  %���붯Ҷ��һ������      
		WAbr = (Wcomp*CAR-Wbbt)*CRHP2*(1.0-CRHPV2); %���붯Ҷ�Ķ�������      
		WAcrT = WAcr+WAbr;	%���붯Ҷ��������
		HcrT = (WAcr*Hbbto+WAbr*Hcomo)/WAcrT;%���붯Ҷ����������	
		P31 = (WAcgiv*Pbbto+WAbgiv*Pcomo+Wburno*Pburno)/(WAcgiv+WAbgiv+Wburno);%������������ѹ
		if P31>Pburno 
            P31 = Pburno;	
        end
		W31 = WAcgiv+WAbgiv+Wburno;	%��������������
		FAR31 = FARb*Wburno/(Wburno+(WAcgiv+WAbgiv)*(FARb+1.0));%����������������	
		H31 = (WAcgiv*Hbbto+Wburno*Hburno+WAbgiv*Hcomo)/W31;%��������������	
	    ENTD = 0.0;
	     Hi = H31/4188.9;
	     BI = Hi*(1.0+FAR31);
	     AIB = (BI+160.0*FAR31)/(1.0+3.0*FAR31);
	     To=4.078516*AIB+13.619482-sqrt(0.012357074*AIB^2.0-2.8422896*AIB+177.36742); 
	     PN=0.65109078+(2.*0.16569798*To-231.714176)/(2.*sqrt(0.16569798*To^2.0-231.714176*To+301153.631));
          if To<=600. 
              P=0.2453695+(2.*0.000044725209*To-0.043175541)/(2.*sqrt(0.000044725209*To^2.0-0.043175541*To+11.2577253));
          end
          if To>600. 
              P=0.2220757+(2.*0.008729571*To-3.4619954)/(2.*sqrt(0.008729571*To^2.0-3.4619954*To+14144.5963));  
          end
              ENTD=(P+FAR31*PN)/(1.+FAR31); 
              [ Ho ] = gashi(  To, FAR31 );
              T31=To+(Hi-Ho/4188.9)/ENTD;%�������������� 
              

  
	if f_design
		ScallN2cor = N2cords*T31^0.5/N2;%��Ƶ����ϵ��
		Whtcormap = Whtcormapds;
    end

	CNTH = ScallN2cor*N2/T31^0.5,%����ת��
    
 
    Alpha=0;
    PointData=struct('X',Alpha,'Y',CNTH,'Z',Whtcormap),
    rowSize=8; colSize=10;
	EffHT = lookup('mfGHPTEff.txt',PointData.Y,PointData.Z,rowSize,colSize);   %���ѹ����Ч��
    DHT =lookup('mfGHPTDHT.txt',PointData.Y,PointData.Z,rowSize,colSize);   %���ѹ���ֹ�����
    WGccal = W31*T31^0.5/P31,	%���㻻������
    THWork = KCWork/EffHS;%ת�����ù�
    DHTcc = THWork/(W31*T31), %���õ�λ�� 
    
	if f_design %��Ƶ����ϵ��
	 
		ScallDHT = DHTcc/DHT;
		ScallEffHT = EffHTds/EffHT;
		ScallWTHc = Whtcormap/WGccal;
    end
        

	DHT = ScallDHT*DHT;	%���������� 
	EffHT = ScallEffHT*EffHT,%����Ч��	 
	WGccal = ScallWTHc*WGccal,	%�����ۺ����� 
	DHTc = DHTcc*T31,%���㵥λ��	 
	 
	XI(5)=Whtcormap;
    XII(5)=Whtcormap;
	Z(1)=(Whtcormap-WGccal)/WGccal;%�����ۺ�������ͼ���ۺ����������
	Z(2)=(DHTcc-DHT)/DHTcc;%������ù�������ʵ����Ҫ�����������
       
           Hhto = H31-DHTc,	    %����ʵ�ʳ�����	
           
           ENTD = 0.0;
	       Hi = Hhto/4188.9;
	       BI = Hi*(1.0+FAR31);
	       AIB = (BI+160.0*FAR31)/(1.0+3.0*FAR31);
	       To=4.078516*AIB+13.619482-sqrt(0.012357074*AIB^2.0-2.8422896*AIB+177.36742); 
	       PN=0.65109078+(2.*0.16569798*To-231.714176)/(2.*sqrt(0.16569798*To^2.0-231.714176*To+301153.631));
          if To<=600. 
              P=0.2453695+(2.*0.000044725209*To-0.043175541)/(2.*sqrt(0.000044725209*To^2.0-0.043175541*To+11.2577253));
          end
          if To>600. 
              P=0.2220757+(2.*0.008729571*To-3.4619954)/(2.*sqrt(0.008729571*To^2.0-3.4619954*To+14144.5963));  
          end
              ENTD=(P+FAR31*PN)/(1.+FAR31); 
              [ Ho ] = gashi(  To, FAR31 );
               Thto=To+(Hi-Ho/4188.9)/ENTD;%��ѹ���ֳ�������
            
              Cpth=DHTc/(T31-Thto);
              amw = 28.97-.946186*FAR31;
              R_eng = 1.986375/amw;		%Ӣ�Ƶ�λ
	          Rth = R_eng*4185.7666;
              
              PRKth=(1-(1-Thto/T31)/EffHT)^(-(Cpth/Rth));%�������ͱ�
              
              Phto=P31/PRKth;%��ѹ���ֳ�����ѹ    
              
              
       if WAcrT~=0.0%�������������ĸ�����  ~=�����ڵ���˼
    
		  FARht = FAR31*W31/(W31+WAcrT*(FAR31+1.0));
	      Whto = W31+WAcrT;
          Hhto = (WAcrT*HcrT+W31*Hhto)/Whto;
        
		      
           ENTD = 0.0;
	       Hi = Hhto/4188.9;
	       BI = Hi*(1.0+FARht);
	       AIB = (BI+160.0*FARht)/(1.0+3.0*FARht);
	       To=4.078516*AIB+13.619482-sqrt(0.012357074*AIB^2.0-2.8422896*AIB+177.36742); 
	       PN=0.65109078+(2.*0.16569798*To-231.714176)/(2.*sqrt(0.16569798*To^2.0-231.714176*To+301153.631));
          if To<=600. 
              P=0.2453695+(2.*0.000044725209*To-0.043175541)/(2.*sqrt(0.000044725209*To^2.0-0.043175541*To+11.2577253));
          end
          if To>600. 
              P=0.2220757+(2.*0.008729571*To-3.4619954)/(2.*sqrt(0.008729571*To^2.0-3.4619954*To+14144.5963));  
          end
              ENTD=(P+FARht*PN)/(1.+FARht); 
              [ Ho ] = gashi(  To, FARht );
              Thto=To+(Hi-Ho/4188.9)/ENTD;   
              
              Cpth=DHTc/(T31-Thto);
              amw = 28.97-.946186*FARht;
              R_eng = 1.986375/amw;		
              Rth = R_eng*4185.7666;
              
              PRKth=(1-(1-Thto/T31)/EffHT)^(-(Cpth/Rth));
              Phto=P31/PRKth;
        
    end
	
	if WAcrT==0 
	
		FARht = FAR31;
		Whto = W31;
    end




