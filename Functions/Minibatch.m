function [ ds,ls,dt,lt ] = Minibatch( Ds,Ls,Dt,Lt,N,batchsize )
% [源域数据，源域标签，目标域数据，目标域标签] = Minibatch(源域数据，源域标签，目标域数据，目标域标签，源域批量总数，目标域批量总数，批次大小)
% 批量提取

[dim_d,ns]=size(Ds);
[~,nt]=size(Dt);
[dim_l,~]=size(Ls);

% 判别:目标域样本必须少于源域样本才可以
if nt>ns
    error('数据集的大小不符合实际迁移情况')
end

Nnum=ns-nt;

% 补全Dt使Dtsize等于Ds

% 采用随机抽样
k=randi([1,nt],1,Nnum); % 返回1~nt之间的1行Nnum列的均匀离散分布的随机整数

Pse_Dt=Dt(:,k);
Pse_Lt=Lt(:,k);

% 合并数据集
Dtc=[Dt,Pse_Dt];
Ltc=[Lt,Pse_Lt];

% 预定义变量长度
ds = zeros(dim_d,batchsize,N);
dt = zeros(dim_d,batchsize,N);
ls = zeros(dim_l,batchsize,N);
lt = zeros(dim_l,batchsize,N);

ks = randperm(ns);

for i=1:4:N-3
    ds(:,:,i)=Ds(:,ks(i:i+3));
    ls(:,:,i)=Ls(:,ks(i:i+3));
    dt(:,:,i)=Dtc(:,ks(i:i+3));
    lt(:,:,i)=Ltc(:,ks(i:i+3));
end

end

