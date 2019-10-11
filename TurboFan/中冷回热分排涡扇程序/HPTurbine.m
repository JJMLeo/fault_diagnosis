%function [Thto,Hhto,Phto,Whto,FARht] = HPTurbine( N2cords,CRHP2,CAR,Whtcormapds,MI2 )
%HPTUBINE Summary of this function goes here
%  Detailed explanation goes here
      

        Wbbt=0;CRHP1=0;CRHPV1=0; Hbbto=0;Pbbto=0;
        WAcgiv = Wbbt*CRHP1*CRHPV1;%进入导向器的一股冷气        
		WAbgiv = (Wcomp*CAR-Wbbt)*CRHP2*CRHPV2; %进入导向器的二股冷气       
		WAcr = Wbbt*CRHP1*(1.0-CRHPV1);  %进入动叶的一股冷气      
		WAbr = (Wcomp*CAR-Wbbt)*CRHP2*(1.0-CRHPV2); %进入动叶的二股冷气      
		WAcrT = WAcr+WAbr;	%进入动叶的总冷气
		HcrT = (WAcr*Hbbto+WAbr*Hcomo)/WAcrT;%进入动叶的总冷气焓	
		P31 = (WAcgiv*Pbbto+WAbgiv*Pcomo+Wburno*Pburno)/(WAcgiv+WAbgiv+Wburno);%导向器出口总压
		if P31>Pburno 
            P31 = Pburno;	
        end
		W31 = WAcgiv+WAbgiv+Wburno;	%导向器出口流量
		FAR31 = FARb*Wburno/(Wburno+(WAcgiv+WAbgiv)*(FARb+1.0));%导向器出口油气比	
		H31 = (WAcgiv*Hbbto+Wburno*Hburno+WAbgiv*Hcomo)/W31;%导向器出口总焓	
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
              T31=To+(Hi-Ho/4188.9)/ENTD;%导向器出口总温 
              

  
	if f_design
		ScallN2cor = N2cords*T31^0.5/N2;%设计点耦合系数
		Whtcormap = Whtcormapds;
    end

	CNTH = ScallN2cor*N2/T31^0.5,%换算转速
    
 
    Alpha=0;
    PointData=struct('X',Alpha,'Y',CNTH,'Z',Whtcormap),
    rowSize=8; colSize=10;
	EffHT = lookup('mfGHPTEff.txt',PointData.Y,PointData.Z,rowSize,colSize);   %查高压涡轮效率
    DHT =lookup('mfGHPTDHT.txt',PointData.Y,PointData.Z,rowSize,colSize);   %查高压涡轮功函数
    WGccal = W31*T31^0.5/P31,	%计算换算流量
    THWork = KCWork/EffHS;%转子需用功
    DHTcc = THWork/(W31*T31), %需用单位功 
    
	if f_design %设计点耦合系数
	 
		ScallDHT = DHTcc/DHT;
		ScallEffHT = EffHTds/EffHT;
		ScallWTHc = Whtcormap/WGccal;
    end
        

	DHT = ScallDHT*DHT;	%修正功函数 
	EffHT = ScallEffHT*EffHT,%修正效率	 
	WGccal = ScallWTHc*WGccal,	%修正折合流量 
	DHTc = DHTcc*T31,%计算单位功	 
	 
	XI(5)=Whtcormap;
    XII(5)=Whtcormap;
	Z(1)=(Whtcormap-WGccal)/WGccal;%计算折合流量和图表折合流量的误差
	Z(2)=(DHTcc-DHT)/DHTcc;%查表所得功函数与实际需要功函数的误差
       
           Hhto = H31-DHTc,	    %涡轮实际出口焓	
           
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
               Thto=To+(Hi-Ho/4188.9)/ENTD;%高压涡轮出口总温
            
              Cpth=DHTc/(T31-Thto);
              amw = 28.97-.946186*FAR31;
              R_eng = 1.986375/amw;		%英制单位
	          Rth = R_eng*4185.7666;
              
              PRKth=(1-(1-Thto/T31)/EffHT)^(-(Cpth/Rth));%计算膨胀比
              
              Phto=P31/PRKth;%高压涡轮出口总压    
              
              
       if WAcrT~=0.0%计算冷气掺混后的各参数  ~=不等于的意思
    
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




