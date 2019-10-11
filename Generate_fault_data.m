% 故障样本生成程序
%故障样本 性能参数8个*样本数

clc
clear all

%% %1.Database_ref——基准 ref
% 
% % 样本数
% num_err = 1000;
% % 计算循环点个数
% num_t = 10;
% 
% ref_measure = zeros(8,num_err,num_t);
% ref_performance = zeros(8,num_err,num_t);
% Error_lv = zeros(8,num_err);
% 
% tic     % 开始计时
% parfor k=1:1:num_t
%     ii = (k+6)*500;
%     disp(ii)
% 
%     [measurement,performancement]=Faultgeneration(Error_lv,num_err);
% 
%     ref_measure(:,:,k)=measurement;
%     ref_performance(:,:,k)=performancement;
% end
% toc    %结束计时
% 
% save('Data/Database_ref.mat', 'ref_measure', 'ref_performance')

%% %2.Database_truth——真值
% 
% % 样本数
% num_err = 1000;
% % 计算循环点个数
% num_t = 10;
% 
% num_engine = 10;
% 
% truth_measure = zeros(8, num_err, num_t, num_engine);
% truth_performance = zeros(8, num_err, num_t, num_engine);
% Error_lv = zeros(8, num_err, num_t, num_engine);
% 
% load('Data\curve_fitting\curve_fitting.mat');
% 
% tic     % 开始计时
% 
% 10台不同退化程度的发动机  Case权重
% q = 1.1:0.1:2;
% 
% for u = 1:1:num_engine
%     parfor k=1:1:num_t
%         ii=(k+6)*500
%         for j = 1:8
%             生成1*num_err的正态分布向量
%             Error_lv(j,:,k,u)=q(u).*normrnd(0.01*Case1(j,ii),0.0005,1,num_err);
%         end
%     end
% end
%     
% for u = 1:1:num_engine
%     disp(u)
%     
%     parfor k=1:1:num_t
%         ii=(k+6)*500
%         disp(ii)
% 
%         [measurement,performancement]=Faultgeneration(Error_lv(:,:,k,u),num_err);
%         truth_measure(:,:,k,u)=measurement;
%         truth_performance(:,:,k,u)=performancement;
% 
%     end
% end
% toc    %结束计时
% 
% save('Data/Database_truth.mat', 'truth_measure', 'truth_performance')

%% %3.Database_delta——偏差计算
% 
% ref = load('Data/Database_ref');
% truth = load('Data/Database_truth');
% 
% delta_measure = (truth.truth_measure - ref.ref_measure) ./ ref.ref_measure;
% delta_performance = (truth.truth_performance - ref.ref_performance) ./ ref.ref_performance;
% 
% save('Data/Database_delta.mat', 'delta_measure', 'delta_performance')

%% %4.Database_source——源域数据
%样本数
num_err = 1000;
%计算循环点个数
num_t = 3000;

%--------------------生成源域基准数据-------------------------
ref_measure = zeros(8,num_err,num_t);
ref_performance = zeros(8,num_err,num_t);
Error_lv = zeros(8,num_err);

tic     % 开始计时
parfor k=1:1:num_t
    disp(k)

    [measurement,performancement]=Faultgeneration(Error_lv,num_err);

    ref_measure(:,:,k)=measurement;
    ref_performance(:,:,k)=performancement;
end

%--------------------生成源域真值数据-------------------------
num_engine = 10;

truth_measure = zeros(8, num_err, num_t, num_engine);
truth_performance = zeros(8, num_err, num_t, num_engine);
Error_lv = zeros(8, num_err, num_t, num_engine);

load('Data\curve_fitting\curve_fitting.mat');

tic     % 开始计时

% 10台不同退化程度的发动机  Case权重
q = 1.1:0.1:2;

for u = 1:1:num_engine
    parfor k=1:1:num_t

        for j = 1:8
            % 生成1*num_err的正态分布向量
            Error_lv(j,:,k,u)=q(u).*normrnd(0.01*Case1(j,ii),0.0005,1,num_err);
        end
    end
end
    
for u = 1:1:num_engine
    disp(u)
    
    parfor k=1:1:num_t
        disp(k)

        [measurement,performancement]=Faultgeneration(Error_lv(:,:,k,u),num_err);
        truth_measure(:,:,k,u)=measurement;
        truth_performance(:,:,k,u)=performancement;

    end
end

%--------------------生成源域偏差数据-------------------------
delta_measure = (truth_measure - ref_measure) ./ ref_measure;
delta_performance = (truth_performance - ref_performance) ./ ref_performance;

save('Data/Database_source.mat', 'delta_measure', 'delta_performance')