function [ ds,ls,dt,lt ] = Minibatch( Ds,Ls,Dt,Lt,N,batchsize )
% [Դ�����ݣ�Դ���ǩ��Ŀ�������ݣ�Ŀ�����ǩ] = Minibatch(Դ�����ݣ�Դ���ǩ��Ŀ�������ݣ�Ŀ�����ǩ��Դ������������Ŀ�����������������δ�С)
% ������ȡ

[dim_d,ns]=size(Ds);
[~,nt]=size(Dt);
[dim_l,~]=size(Ls);

% �б�:Ŀ����������������Դ�������ſ���
if nt>ns
    error('���ݼ��Ĵ�С������ʵ��Ǩ�����')
end

Nnum=ns-nt;

% ��ȫDtʹDtsize����Ds

% �����������
k=randi([1,nt],1,Nnum); % ����1~nt֮���1��Nnum�еľ�����ɢ�ֲ����������

Pse_Dt=Dt(:,k);
Pse_Lt=Lt(:,k);

% �ϲ����ݼ�
Dtc=[Dt,Pse_Dt];
Ltc=[Lt,Pse_Lt];

% Ԥ�����������
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

