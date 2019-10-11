% MSTrAdaBoost & Domins 主程序

clc
clear all

% Database1
tic

% 导入数据样本
data = load('Data\Database1.mat'); 

history_measure = data.measure_history(:,:,1:2999);
history_performance = data.performance_history(:,:,1:2999);

% 源域1数据集
measure1 = reshape(history_measure,[8,100*2999]);
performance1 = reshape(history_performance,[8,100*2999]);

% 可以进行3000:500:7500循环数的诊断——历史数据库满足
for i = 1:1:10
TEFF = 2500+500*i;
j = 6;
disp(i)

% 源域2数据集
measure2 = data.measure_source(:,:,i,j);
performance2 = data.performance_source(:,:,i,j);

% 源域3数据集
measure3 = data.measure_source(:,:,i,20-j);
performance3 = data.performance_source(:,:,i,20-j);

% 目标域数据集
t_measure = data.measure_history(:,:,TEFF);
t_performance = data.Pseudo_performance(:,:,TEFF-2999);

% 测试数据集
testmeasure = data.measure_history(:,:,TEFF);
testperformance = data.performance_history(:,:,TEFF);

[~,n_test]=size(t_measure);

% 样本归一化
[~,input_s] = mapminmax(measure1);
[~,output_s] = mapminmax(performance1);

% 深度迁移+多源数据融合训练
[CWL_w1_re,CWL_b1_re,CWL_w2_re,CWL_b2_re,at_re,W_re] = MSTrAdaBoost_DTN(measure1,performance1,measure2,performance2,measure3,performance3,t_measure,t_performance,input_s,output_s);

% 测试
[MSE(:,i),R2(:,i)]=Test_MSTrAdaBoost_quan(testmeasure,testperformance,CWL_w1_re,CWL_b1_re,CWL_w2_re,CWL_b2_re,at_re,input_s,output_s);
end
toc


