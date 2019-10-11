function [ CWL_w1_re,CWL_b1_re,CWL_w2_re,CWL_b2_re,at_re,W_re ] = MSTrAdaBoost_DTN(D1,L1,D2,L2,D3,L3,Dt,Lt,input_s,output_s)
% 深度迁移+多源数据融合
% [弱学习机模型参数，弱学习机权重，样本权重] = MSTrAdaBoost_DTN（源域数据，源域标签，目标域数据，目标域标签，每个数据源迁移比例，归一化参数）

% 子程序: DTN_unlabeled/MLP_test_quan

% 弱学习机数目
M = 10;

[~,ns1]=size(D1);
[~,ns2]=size(D2);
[~,ns3]=size(D3);
[~,nt]=size(Dt);

% 数据源数目
SN = 3;

k1 = rand(ns1,1);[~,n1] = sort(k1);
k2 = rand(ns2,1);[~,n2] = sort(k2);
k3 = rand(ns3,1);[~,n3] = sort(k3);

% 顺序打乱
D1_re = D1(:,n1); 
D2_re = D2(:,n2); 
D3_re = D3(:,n3); 
D_re = [D1_re,D2_re,D3_re];

L1_re = L1(:,n1); 
L2_re = L2(:,n2); 
L3_re = L3(:,n3); 
L_re=[L1_re,L2_re,L3_re];

% 迁移训练数据共有ns个样本
ns=ns1+ns2+ns3;

% 弱学习机权重——源域部分
as=0.5*log(1+sqrt(2*log(ns/M)));

% 预定义变量长度
W=ones(1,ns+nt); 
W_re = zeros(M,ns+nt);
e_t = zeros(1,SN);
at_re = zeros(1,M);

for t=1:M
    
    % W值归一化
    W = W/sum(W,'omitnan');
    W_re(t,:)=W;     %记录样本权重

    for k=1:SN

        eval(['Ds_train=D',num2str(k),'_re;'])
        eval(['Ls_train=L',num2str(k),'_re;'])
        Dt_train=Dt;
        Lt_train=Lt;

        %---------弱学习机模型------------
        %域迁移DAMLPs
        [w1,b1,w2,b2,~,~,~,~,~]=DTN_unlabeled(Ds_train,Ls_train,Dt_train,Lt_train,input_s,output_s);
        [~,e_i]=MLP_test_quan(Dt,Lt,w1,b1,w2,b2,input_s,output_s); %多层感知器预测

        %------------弱学习机模型误差--------------
		EwT=sum(e_i.*W(ns+1:ns+nt),'omitnan');
        e_t(k)=EwT/sum(W(ns+1:ns+nt));

        %记录弱学习机模型参数candidate weak learner(CWL)
        CWL_w1(:,:,k)=w1;
        CWL_b1(:,:,k)=b1;
        CWL_w2(:,:,k)=w2;
        CWL_b2(:,:,k)=b2;

    end

    %learner with the min error(k_best learner)/找最优的学习机
    k_bc=find(e_t==min(e_t));
    
    %出现错误的原因error('误差出现0值')  
    if length(k_bc)>=2
        k_bc=k_bc(1);
    end
    
    % 构成弱学习机
    CWL_w1_re(:,:,t)=CWL_w1(:,:,k_bc);
    CWL_b1_re(:,:,t)=CWL_b1(:,:,k_bc);
    CWL_w2_re(:,:,t)=CWL_w2(:,:,k_bc);
    CWL_b2_re(:,:,t)=CWL_b2(:,:,k_bc);

    %选取的弱学习机误差
    e_tu=e_t(k_bc);
    %弱学习机权重——目标域部分
    at=0.5*log((1-e_tu)/e_tu);

    [~,e_i]=MLP_test_quan([D_re,Dt],[L_re,Lt],CWL_w1_re(:,:,t),CWL_b1_re(:,:,t),CWL_w2_re(:,:,t),CWL_b2_re(:,:,t),input_s,output_s);

    %样本权重更新
    wSI=W(1:ns).*exp(-as*(1-e_i(1:ns)));
    wTI=W(ns+1:ns+nt).*exp(at*(1-e_i(ns+1:ns+nt)));

    W=[wSI,wTI];
    at_re(t)=at;
end

% 弱学习机权重归一化
at_re=at_re/norm(at_re,1)

end

