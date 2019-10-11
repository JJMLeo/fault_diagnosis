function [ yn,Iout ] = ForwardP( input,w1,b1,w2,b2,midnum,batchsize )
% ����ǰ�򴫲�
% [�������������������] = ForwardP���������ݣ����������������С��

for j=1:batchsize
    %Hidden layer
    for u=1:midnum
        I(u)=input(:,j)'*w1(u,:)'+b1(u);
        Iout(u,j)=1/(1+exp(-I(u)));
    end
end

%Output layer
for j=1:batchsize
    yn(:,j)=w2'*Iout(:,j)+b2;
end

end

