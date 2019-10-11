filename='designparadata.txt';
fid=fopen(filename,'r');%读取打开文件
for i=1:4;
    f=fgetl(fid);
end
BPR = str2num(f);
f=fgetl(fid);
f=fgetl(fid);
SIGMAds = str2num(f);
f=fgetl(fid);
f=fgetl(fid);
RKF=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Efffands=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
PRfands=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Wfands=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
N1=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
RKB=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Effboods=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
PRboods=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
RKC=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Effcompds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
PRcompds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
N2=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
CAR=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Effbds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
BurnerDPds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
TorW=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
 if TorW    
    Tburnods=str2num(f);
    f_specifyWF = false;
    f_specifyT=true;
else
   
    Wfb=str2num(f);
    f_specifyWF = true;
	f_specifyT=false;	%//计算温度
end
f=fgetl(fid);
f=fgetl(fid);
Whtcormapds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
N2cords=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
EffHTds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
CRHP2=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
CRHPV2=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
EffHS=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Wltcormapds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
N1cords=str2num(f);    
f=fgetl(fid);
f=fgetl(fid);
EffLTds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
CRLP2=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
CRLPV2=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
EffLS=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
BypassDPds=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Ma=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
H=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
N1max=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
N2max=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Pcomomax=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
WFmin=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
FaiVelo8=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Tburnomax=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
Tburnoc=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
sigfc=str2num(f);
f=fgetl(fid);
f=fgetl(fid);
sigtn=str2num(f);













