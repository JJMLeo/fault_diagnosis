function [ A,e_i ] = MLP_test_quan( data,Label,w1,b1,w2,b2,inputps,outputs )
%MLPs的测试文件
% [准确率，单个样本误差] = MLP_test_quan（数据，标签，网络参数，归一化参数）

%归一化化
inputn_test=mapminmax('apply',data,inputps);
output_test=Label;

[~,n2]=size(data);%样本个数n2

e_i = zeros(1,n2);

global midnum

for i=1:n2
    for j=1:1:midnum
        I(j)=inputn_test(:,i)'*w1(j,:)'+b1(j);
        Iout(j)=1/(1+exp(-I(j)));
    end
    %预测结果
    fore(:,i)=w2'*Iout'+b2;
end

yn = mapminmax('reverse',fore,outputs);

for i=1:n2
    % 单个样本的误差——（预测值-期望值）./期望值 向量的1-范数
    e_i(i)=mean( abs( (yn(:,i)-output_test(:,i))/norm(output_test(:,i),2) ) );   % norm(v，p)返回矩阵/向量v的p-范数
%     e_i(i)=norm(yn(:,i)-output_test(:,i),2)/norm(output_test(:,i),2);
end

%准确率  e_i中存在NaN值，sum求和会报错。omitnan 忽略NaN值求和
A=sum(1./(1+e_i),'omitnan')/n2;
end

