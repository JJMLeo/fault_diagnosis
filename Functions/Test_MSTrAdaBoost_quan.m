function [MSE,R2] = Test_MSTrAdaBoost_quan( domain,label,w10,b10,w20,b20,at,inputs,outputs)
%MSTrAdaBoost�����ļ�
% [׼ȷ�ʣ������������] = Test_MSTrAdaBoost_quan�����ݣ���ǩ�������������һ��������

[~,n2]=size(domain);
[~,~,M]=size(w10);
output_fore=0;

%����ṹ 
global midnum
global outnum

%Ԥ�ȶ����������
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
        %Ԥ����
        fore(:,i)=w2'*Iout'+b2;
    end
    yn = mapminmax('reverse',fore,outputs);
    output_fore=output_fore+at(k)*yn;
end

for i=1:n2
    % �������������
    MSE_i(:,i) = (yn(:,i)-output_test(:,i)).^2;
    R2_i(:,i) = (mean(yn(:,i))-output_test(:,i)).^2;
end

%׼ȷ�ʡ���������8*1
MSE = mean(MSE_i,2) %����ÿһ�о�ֵ��������
R2 = mean(1-MSE./R2_i,2)
end

