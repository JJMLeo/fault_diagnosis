
% function [ output_args ] =
% main(kk,MECHN1,MECHN2,AREA,ALTITUDE,MACH,RC,RF)
%MAIN Summary of this function goes here
%  Detailed explanation goes here

kk=1,MECHN1=100,MECHN2=100,AREA=1,ALTITUDE=10668,MACH=0.8,RC=0.7,RF=0.4,icper=1.0/13.5;
% kk=1,MECHN1=100,MECHN2=100,AREA=1,ALTITUDE=0,MACH=0,RC=0.7,RF=0.4,icper=1.0/13.5;
   f_throttle=false;f_guess=0;f_trans =0;
   
   % A8ds =0; T1ds = 0; T2ds = 0;T3ds = 0;T4ds = 0;
   traditional=0;
   f_bleedgas=0;
   
    XI=[0,0,0,0,0,0,0,0];
    XII=[0,0,0,0,0,0,0,0];
    Z=[0,0,0,0,0,0,0,0];
  
    initial;
    ondesign_guan;
    
     f_design = 0;%%%新加的
     MACH=0.82;
     ALTITUDE=10668;
     MECHN1=100;
jiedian=1;
%  for i=1:19
     for i=1:14  
if MECHN1==0
     
    f_controlN1=false;
    N2=MECHN2;
    H=ALTITUDE;
    if RF|RC==1
      RKF=RF;
      XII(1)=RKF;
      RKC=RC;
      XII(2)=RKC;
   end
    Ma=MACH;
    Areao=Areao*AREA;
else
    
    f_controlN1=true;
    N1=MECHN1;
    H=ALTITUDE;
    %%
%     if RF|RC==1%%这时逻辑非零
%       RKF=RF;
%       XI(1)=RKF;
%      RKC=RC;
%       XI(2)=RKC;
%     end
    %%
    Ma=MACH;
    Areao=Areao*AREA;
end
 if traditional==1;%%这是用于设置82这个特殊点的猜值
     if MECHN1==82
         RKF=0.17;
         XI(1)=RKF;
     end
 end
   f_controlN2=0;%%不控制n2
   f_controlA=1;
   f_guess=1;%%猜值
   solve_guan;
   %% 增加
   Tdealt=Tlto2-Tcomo1; %涡轮后温度与高压压气机出口温度温差
%    Wencha(MECHN1)=Tdealt;
%      fid = fopen('wencha.txt','at');
%     fprintf(fid,'%d   %8.2f\r\n',MECHN1,Tdealt);
%     fclose(fid);
    %%
  if traditional==0
SM1str3(jiedian) =SM1;
 SM2str3(jiedian) =SM2;
 SM3str3(jiedian) =SM3;
 SFCstr3(jiedian)=SFC;
 BPRstr3(jiedian)=BPR;
 Thruststr3(jiedian)=Thrust;%推力
 Fsstr3(jiedian)=Fs;%单位推力
Deltp1str3(jiedian)=Deltp1/Pboo1;%中冷器内侧压降
Deltp2str3(jiedian)=Deltp2/Pfano;%中冷器外涵压降
Deltp1Absstr3(jiedian)=Deltp1;%中冷器内侧压降绝对值

Deltp2Absstr3(jiedian)=Deltp2;%中冷器外涵压降


 Tdealtstr3(jiedian)=Tdealt;
 
Deltp4str3(jiedian)=Deltp4/Pcomo1;%回热器冷侧压降
Deltp3str3(jiedian)=Deltp3/Plto;%回热器热侧压降
Deltp4Absstr3(jiedian)=Deltp4;
Deltp3Absstr3(jiedian)=Deltp3;

Wboostr3(jiedian)=Wboo;%增压级物理流量
PRboostr3(jiedian)=PRboo;%增压级压比
Effboostr3(jiedian)=Effboo;

N2corstr3(jiedian)=N2cor;
N1corstr3(jiedian)=N1cor;
N2str3(jiedian)=N2;
NBcorstr3(jiedian)=NBcor;%增压级换算转速
Tburnostr3(jiedian)=Tburno;


Wcorfanstr3(jiedian)=Wcorfan;%风扇相对流量
PRfanstr3(jiedian)=PRfan%压比
Wcorboostr3(jiedian)=Wcorboo;
PRboostr3(jiedian)=PRboo;
Wcorcompstr3(jiedian)=Wcorcomp;
PRcompstr3(jiedian)=PRcomp;

Tboostr3(jiedian)=Tboo;
Tbi3(jiedian)=Tburno/Thto;%高压涡轮进口与出口总温之比

icperstr(jiedian)=icper;

  else
 SM1str2(jiedian) =SM1;
 SM2str2(jiedian) =SM2;
 SM3str2(jiedian) =SM3;
 SFCstr2(jiedian)=SFC;
 BPRstr2(jiedian)=BPR;
 Thruststr2(jiedian)=Thrust;%推力
 Fsstr2(jiedian)=Fs;%单位推力   
 Wboostr2(jiedian)=Wboo;
PRboostr2(jiedian)=PRboo;
Effboostr2(jiedian)=Effboo;

N2corstr2(jiedian)=N2cor
N1corstr2(jiedian)=N1cor;
N2str2(jiedian)=N2;
NBcorstr2(jiedian)=NBcor;
Tburnostr2(jiedian)=Tburno;
  
Wcorfanstr2(jiedian)=Wcorfan;%风扇相对流量
PRfanstr2(jiedian)=PRfan%压比
Wcorboostr2(jiedian)=Wcorboo;
PRboostr2(jiedian)=PRboo;
Wcorcompstr2(jiedian)=Wcorcomp;
PRcompstr2(jiedian)=PRcomp;

Tboostr2(jiedian)=Tboo;
Tbi2(jiedian)=Tburno/Thto;%高压涡轮进口与出口总温之比
 end
 %%
 jiedian=jiedian+1;
   MECHN1=MECHN1-1;
end 
  