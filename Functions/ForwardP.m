function [ yn,Iout ] = ForwardP( input,w1,b1,w2,b2,midnum,batchsize )
% 网络前向传播
% [输出层输出，隐含层输出] = ForwardP（输入数据，网络参数，批量大小）

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

