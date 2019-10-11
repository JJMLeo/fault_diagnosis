function [ A,e_i ] = MLP_test_quan( data,Label,w1,b1,w2,b2,inputps,outputs )
%MLPs�Ĳ����ļ�
% [׼ȷ�ʣ������������] = MLP_test_quan�����ݣ���ǩ�������������һ��������

%��һ����
inputn_test=mapminmax('apply',data,inputps);
output_test=Label;

[~,n2]=size(data);%��������n2

e_i = zeros(1,n2);

global midnum

for i=1:n2
    for j=1:1:midnum
        I(j)=inputn_test(:,i)'*w1(j,:)'+b1(j);
        Iout(j)=1/(1+exp(-I(j)));
    end
    %Ԥ����
    fore(:,i)=w2'*Iout'+b2;
end

yn = mapminmax('reverse',fore,outputs);

for i=1:n2
    % ����������������Ԥ��ֵ-����ֵ��./����ֵ ������1-����
    e_i(i)=mean( abs( (yn(:,i)-output_test(:,i))/norm(output_test(:,i),2) ) );   % norm(v��p)���ؾ���/����v��p-����
%     e_i(i)=norm(yn(:,i)-output_test(:,i),2)/norm(output_test(:,i),2);
end

%׼ȷ��  e_i�д���NaNֵ��sum��ͻᱨ��omitnan ����NaNֵ���
A=sum(1./(1+e_i),'omitnan')/n2;
end

