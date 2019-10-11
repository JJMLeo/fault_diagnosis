function result= lookup( filename,xi,yi,rowSize,colSize)
%LOOKUP Summary of this function goes here
%  Detailed explanation goes here

fid=fopen(filename,'r');
for i=1:5;
    f=fgetl(fid);%%读取5行并转换成数据
end
x = str2num(f);%%把字符串改成数值
if x(1)>xi
    error('overstep');
end
if x(rowSize)<xi
    error('overstep'); 
end

f=fgetl(fid);
y= str2num(f);
if y(1)>yi
    error('overstep');
end
if y(colSize)<yi
    error('overstep'); 
end

A=fscanf(fid,'%f',[colSize,rowSize]);

[X,Y]=meshgrid(x,y);%%x和y是向量
%[Xi,Yi]=meshgrid(xi,yi),

ai=interp2(X,Y,A,xi,yi,'cudic');

fclose(fid);
result=ai;


