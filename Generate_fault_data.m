% �����������ɳ���
%�������� ���ܲ���8��*������

clc
clear all

%% %1.Database_ref������׼ ref
% 
% % ������
% num_err = 1000;
% % ����ѭ�������
% num_t = 10;
% 
% ref_measure = zeros(8,num_err,num_t);
% ref_performance = zeros(8,num_err,num_t);
% Error_lv = zeros(8,num_err);
% 
% tic     % ��ʼ��ʱ
% parfor k=1:1:num_t
%     ii = (k+6)*500;
%     disp(ii)
% 
%     [measurement,performancement]=Faultgeneration(Error_lv,num_err);
% 
%     ref_measure(:,:,k)=measurement;
%     ref_performance(:,:,k)=performancement;
% end
% toc    %������ʱ
% 
% save('Data/Database_ref.mat', 'ref_measure', 'ref_performance')

%% %2.Database_truth������ֵ
% 
% % ������
% num_err = 1000;
% % ����ѭ�������
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
% tic     % ��ʼ��ʱ
% 
% 10̨��ͬ�˻��̶ȵķ�����  CaseȨ��
% q = 1.1:0.1:2;
% 
% for u = 1:1:num_engine
%     parfor k=1:1:num_t
%         ii=(k+6)*500
%         for j = 1:8
%             ����1*num_err����̬�ֲ�����
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
% toc    %������ʱ
% 
% save('Data/Database_truth.mat', 'truth_measure', 'truth_performance')

%% %3.Database_delta����ƫ�����
% 
% ref = load('Data/Database_ref');
% truth = load('Data/Database_truth');
% 
% delta_measure = (truth.truth_measure - ref.ref_measure) ./ ref.ref_measure;
% delta_performance = (truth.truth_performance - ref.ref_performance) ./ ref.ref_performance;
% 
% save('Data/Database_delta.mat', 'delta_measure', 'delta_performance')

%% %4.Database_source����Դ������
%������
num_err = 1000;
%����ѭ�������
num_t = 3000;

%--------------------����Դ���׼����-------------------------
ref_measure = zeros(8,num_err,num_t);
ref_performance = zeros(8,num_err,num_t);
Error_lv = zeros(8,num_err);

tic     % ��ʼ��ʱ
parfor k=1:1:num_t
    disp(k)

    [measurement,performancement]=Faultgeneration(Error_lv,num_err);

    ref_measure(:,:,k)=measurement;
    ref_performance(:,:,k)=performancement;
end

%--------------------����Դ����ֵ����-------------------------
num_engine = 10;

truth_measure = zeros(8, num_err, num_t, num_engine);
truth_performance = zeros(8, num_err, num_t, num_engine);
Error_lv = zeros(8, num_err, num_t, num_engine);

load('Data\curve_fitting\curve_fitting.mat');

tic     % ��ʼ��ʱ

% 10̨��ͬ�˻��̶ȵķ�����  CaseȨ��
q = 1.1:0.1:2;

for u = 1:1:num_engine
    parfor k=1:1:num_t

        for j = 1:8
            % ����1*num_err����̬�ֲ�����
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

%--------------------����Դ��ƫ������-------------------------
delta_measure = (truth_measure - ref_measure) ./ ref_measure;
delta_performance = (truth_performance - ref_performance) ./ ref_performance;

save('Data/Database_source.mat', 'delta_measure', 'delta_performance')