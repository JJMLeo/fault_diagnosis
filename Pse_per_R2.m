% ����α��ǩR2����

clc
clear all

%% ����������
tic
data = load('Data\Database5.mat'); 

[~,n2,n3] = size(data.performance_history);
for j = 1:1:n3-2999
    yn = data.Pseudo_performance(:,:,j);
    output_test = data.performance_history(:,:,j+2999);
    
for i=1:1:n2    
    % �������������
    MSE_i(:,i) = (yn(:,i)-output_test(:,i)).^2;
    R2_i(i) = mean((mean(yn(:,i))-output_test(:,i)).^2);
end

%׼ȷ��
MSE(j) = mean(mean(MSE_i,2)); %����ÿһ�о�ֵ��������

R2(j) = mean(1-MSE(j)./R2_i);
end
toc

%% ��������
% tic
% data = load('Data\Database3.mat'); 
% 
% [~,n2,n3] = size(data.performance);
% for j = 1:1:n3-2999
%     yn = data.Pseudo_performance(:,:,j);
%     output_test = data.performance(:,:,j+2999);
%     
% for i=1:1:n2    
%     % �������������
%     MSE_i(:,i) = (yn(:,i)-output_test(:,i)).^2;
%     R2_i(i) = mean((mean(yn(:,i))-output_test(:,i)).^2);
% end
% 
% %׼ȷ��
% MSE(j) = mean(mean(MSE_i,2)); %����ÿһ�о�ֵ��������
% 
% R2(j) = mean(1-MSE(j)./R2_i);
% end
% toc