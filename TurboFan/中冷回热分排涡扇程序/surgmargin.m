function result=surgmargin(  WAc,PR,CNC,PRscaller, WAscaller,filename1,filename2,rowsize,colsize,th,de)
%SURGMARGIN Summary of this function goes here
%  Detailed explanation goes here

  
    PointData=struct('X',0.0,'Y',CNC,'Z',1.0);
    
     WcMap =lookup(filename1,PointData.Y,PointData.Z,rowsize,colsize) ; 
	 PRMap =lookup(filename2,PointData.Y,PointData.Z,rowsize,colsize) ; 
	WcRatio = WAc/(WcMap*WAscaller*de/th);
	PrRatio = PR/(PRscaller*(PRMap-1.0)+1.0);
	SurgeMargin = 100.0*(WcRatio/PrRatio-1.0);
    
	result= SurgeMargin;	%压比流量综和裕度