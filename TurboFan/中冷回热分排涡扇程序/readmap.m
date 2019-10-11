function [ output_args ] = readmap(Wfands,BPR)
%REDMAP Summary of this function goes here
%  Detailed explanation goes here

colSizeF=10;rowSizeF=12;
fid=fopen('GFanWAc.txt','r');
for i=1:6;
    f=fgetl(fid);
end
A=fscanf(fid,'%f',[colSizeF,rowSizeF]);
A=A*Wfands/628;
a=A(10,:);
fclose(fid);

fid=fopen('GFanPr.txt','r');
for i=1:6;
    f=fgetl(fid);
end
B=fscanf(fid,'%f',[colSizeF,rowSizeF]);
b=B(10,:);
fclose(fid);

fid=fopen('GFanEff.txt','r');
for i=1:6;
    f=fgetl(fid);
end
C=fscanf(fid,'%f',[colSizeF,rowSizeF]);
c=C(10,:);
fclose(fid);

colSizeC=5;rowSizeC=10;
fid=fopen('GCprWAc.txt','r');
for i=1:6;
    f=fgetl(fid);
end
D=fscanf(fid,'%f',[colSizeC,rowSizeC]);
D=D*Wfands/((BPR+1)*27.82);
d=D(5,:);
fclose(fid);

fid=fopen('GCprPr.txt','r');
for i=1:6;
    f=fgetl(fid);
end
E=fscanf(fid,'%f',[colSizeC,rowSizeC]);
e=E(5,:);
fclose(fid);

fid=fopen('GCprEff.txt','r');
for i=1:6;
    f=fgetl(fid);
end
F=fscanf(fid,'%f',[colSizeC,rowSizeC]);
f=F(5,:);
fclose(fid);

subplot(2,2,1);
plot(A,C,'-');
title('风扇特性曲线');
subplot(2,2,3);
plot(A,B,'-');
hold;
plot(a,b,'-');

subplot(2,2,2);
plot(D,F,'-');
title('压气机特性曲线');
subplot(2,2,4);
plot(D,E,'-');
hold;
plot(d,e,'-');
hold off;










