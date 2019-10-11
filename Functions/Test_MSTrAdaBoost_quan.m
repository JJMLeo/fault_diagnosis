function [MSE,R2] = Test_MSTrAdaBoost_quan( domain,label,w10,b10,w20,b20,at,inputs,outputs)
%MSTrAdaBoost测试文件
% [准确率，单个样本误差] = Test_MSTrAdaBoost_quan（数据，标签，网络参数，归一化参数）

[~,n2]=size(domain);
[~,~,M]=size(w10);
output_fore=0;

%网络结构 
global midnum
global outnum

%预先定义变量长度
I = zeros(n2,midnum);
Iout = zeros(1,midnum);
fore = zeros(outnum,n2);
e_i = zeros(1,n2);

inputn_test=mapminmax('apply',domain,inputs);
output_test = label;

for k=1:M
    w1=w10(:,:,k);
    b1=b10(:,:,k);
    w2=w20(:,:,k);
    b2=b20(:,:,k);

    for i=1:n2
        for j=1:1:midnum
            I(j)=inputn_test(:,i)'*w1(j,:)'+b1(j);
            Iout(j)=1/(1+exp(-I(j)));
        end
        %预测结果
        fore(:,i)=w2'*Iout'+b2;
    end
    yn = mapminmax('reverse',fore,outputs);
    output_fore=output_fore+at(k)*yn;
end

for i=1:n2
    % 单个样本的误差
    MSE_i(:,i) = (yn(:,i)-output_test(:,i)).^2;
    R2_i(:,i) = (mean(yn(:,i))-output_test(:,i)).^2;
end

%准确率——列向量8*1
MSE = mean(MSE_i,2) %包含每一行均值的列向量
R2 = mean(1-MSE./R2_i,2)
end

