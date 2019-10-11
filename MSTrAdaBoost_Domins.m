% MSTrAdaBoost & Domins ������

clc
clear all

% Database1
tic

% ������������
data = load('Data\Database1.mat'); 

history_measure = data.measure_history(:,:,1:2999);
history_performance = data.performance_history(:,:,1:2999);

% Դ��1���ݼ�
measure1 = reshape(history_measure,[8,100*2999]);
performance1 = reshape(history_performance,[8,100*2999]);

% ���Խ���3000:500:7500ѭ��������ϡ�����ʷ���ݿ�����
for i = 1:1:10
TEFF = 2500+500*i;
j = 6;
disp(i)

% Դ��2���ݼ�
measure2 = data.measure_source(:,:,i,j);
performance2 = data.performance_source(:,:,i,j);

% Դ��3���ݼ�
measure3 = data.measure_source(:,:,i,20-j);
performance3 = data.performance_source(:,:,i,20-j);

% Ŀ�������ݼ�
t_measure = data.measure_history(:,:,TEFF);
t_performance = data.Pseudo_performance(:,:,TEFF-2999);

% �������ݼ�
testmeasure = data.measure_history(:,:,TEFF);
testperformance = data.performance_history(:,:,TEFF);

[~,n_test]=size(t_measure);

% ������һ��
[~,input_s] = mapminmax(measure1);
[~,output_s] = mapminmax(performance1);

% ���Ǩ��+��Դ�����ں�ѵ��
[CWL_w1_re,CWL_b1_re,CWL_w2_re,CWL_b2_re,at_re,W_re] = MSTrAdaBoost_DTN(measure1,performance1,measure2,performance2,measure3,performance3,t_measure,t_performance,input_s,output_s);

% ����
[MSE(:,i),R2(:,i)]=Test_MSTrAdaBoost_quan(testmeasure,testperformance,CWL_w1_re,CWL_b1_re,CWL_w2_re,CWL_b2_re,at_re,input_s,output_s);
end
toc


