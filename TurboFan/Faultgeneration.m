function [measurement,performancement]=Faultgeneration(Error_lv,Num_Err)
%Faultgeneration
% Error_lv 故障矩阵 8*Num_Err
% Num_Err 故障样本数

%变量预定义
noise = zeros(8,Num_Err);
Error_source = zeros(8,Num_Err);
measurement = zeros(Num_Err,12);


%随机生成故障——标签
for i = 1:Num_Err
    Error_source(:,i) = ones(8,1)+Error_lv(:,i);
end

for j=1:Num_Err
%故障模式
%考虑8个故障性能参数 
% 1.Fan_Eff;2.Fan_W;3.Com_Eff;4.Com_W;5.HPT_Eff;6.HPT_W;7.LPT_Eff;8.LPT_W
Fault=Error_lv(:,j);

%设计点数据录入
DesignPointData;
%飞行高度与马赫数
H=0;Ma=0;
%高压转子功率提取（kw）
PWX=0;
%压气机中间级放气量（100%=1）
ComprDefW=0;
%控制低压转子相对物理转速（100%=1）
NL=1;

%飞行条件
AmbCondition=[H,Ma];
%[高压转子功率提取，中间级放气]
EngineData=[PWX,ComprDefW];
%初猜值
Z_Fan=0.65;Z_Compr=0.58;Z_HPT=0.63;Z_LPT=0.63;Wf=0.05;NH=0.9;BPR=3;
%初猜值向量
X=[Z_Fan,Z_Compr,Z_HPT,Z_LPT,Wf,NH,BPR];

%NR法进行非设计点迭代计算
[X,~,~,~]=OffDesign_NR(AmbCondition,EngineData,X,NL,Fault);
%用迭代结果进行GTF发动机热力计算
GTFEnginePeformance;
% 所有参数
%1风扇后总压，2风扇后总温，3压气机后总压，4压气机后总温，5高压涡轮后温度，
%6高压涡轮后压力，7低压涡轮后温度，7低压涡轮后压力，9高压转子转速,10总流量
%11燃油流量，12推力

measurement(j,:) = [Pt21,Tt21,Pt3,Tt3,Tt44,Pt44,Tt5,Pt5,NH,W13+W21,Wf,F./10];

end

%故障样本——选取需要的故障样本参数
%风扇后总温，压气机后总压，压气机后总温，高压涡轮后总压，低压涡轮后总温，高压转子转速，总流量，燃油流量
% [Tt21,Pt3,Tt3,Pt44,Tt5,NH,W13+W21,Wf]
DE=measurement(:,[10,2,4,3,6,7,9,11])';% 按照论文顺序的测量参数

% ref数据不加噪声
% 真值要加噪声
% 传感器噪声
% 对应的标准差：[0.5,0.2,0.2,0.3,0.3,0.3,0.1,0.3]%(单位百分比)
SD=0.01*[0.5,0.2,0.2,0.3,0.3,0.3,0.1,0.3];

for i=1:length(SD)
    noise(i,:)=normrnd(0,SD(i),1,Num_Err); %normrnd(MU，sigma) MU均值，sigma标准差
end

measurement = DE.*(noise+1);
% measurement = DE;
performancement = Error_source;

end