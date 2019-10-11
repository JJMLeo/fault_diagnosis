function [ w1,b1,w2,b2,w1_trend,b1_trend,w2_trend,b2_trend,A_trend ] = DTN_unlabeled( Ds,Ls,Dt,Pse_label,input_s,output_s )
%DAMLPs������Ǩ�Ƴ���
% [������������������¼��׼ȷ��] = DTN_unlabeled(Դ�����ݣ�Դ���ǩ��Ŀ�������ݣ�α��ǩ����һ������);

% �Ӻ���Minibatch\MLP_test_quan\ForwardP\

% ƽ��Ȳ���
lambda=1;

% ��������
iterN=200;

% batchsize ����ѵ����һ��4������
batchsize = 4;
[~,ns2]=size(Ds);
N = fix(ns2/batchsize);    %fix ��0��������

% ���ݹ�һ��
Ds=mapminmax('apply',Ds,input_s);
Dt=mapminmax('apply',Dt,input_s);
Ls=mapminmax('apply',Ls,output_s);
Lt=mapminmax('apply',Pse_label,output_s);

% minibatch�������
% �����ȡ
[ds,ls,dt,lt]=Minibatch(Ds,Ls,Dt,Lt,N,batchsize);

% ����ṹ����ȫ�ֱ���
global innum
global midnum
global outnum

innum=8;
midnum=6;
outnum=8;

% Ȩֵ��ֵ��ʼ��
w1=rands(midnum,innum);%6*9
b1=rands(midnum,1);%6*1
w2=rands(midnum,outnum);%6*8
b2=rands(outnum,1);%8*1

% ��ʼ��ѧϰ����
xitemax=1;
xitemin=0.4;
deltaxite=(1/iterN)*(xitemax-xitemin);
xite=1;

% ��ʼ������
mo_w1=0;
mo_b1=0;
mo_w2=0;
mo_b2=0;

% Ԥ�����������
w1_trend = zeros(midnum,innum,iterN);
w2_trend = zeros(midnum,outnum,iterN);
b1_trend = zeros(midnum,1,iterN);
b2_trend = zeros(outnum,1,iterN);
A_trend = zeros(iterN/20);
la = 1;


for i=1:1:iterN
    
    %Early stopping ѡ�� (ÿ20��ѭ������һ��)    
    if i/20==fix(i/20)
        
        [A_1,~]=MLP_test_quan(Dt,Lt,w1,b1,w2,b2,input_s,output_s);
        
        %��¼����
        w1_trend(:,:,la)=w1;
        w2_trend(:,:,la)=w2;
        b1_trend(:,:,la)=b1;
        b2_trend(:,:,la)=b2;
        A_trend(la)=A_1;
        
        la=la+1;
        
        if la>=3
            if A_trend(la-2)>max(A_trend(la-2:la))
                w1=w1_trend(:,:,la-2);
                w2=w2_trend(:,:,la-2);
                b1=b1_trend(:,:,la-2);
                b2=b2_trend(:,:,la-2);
                break
            end
        end
        
    end
    
    %�����е�minibatch������ѡһ��
    minibatch_k=randi([1,N]);

    ds_train=ds(:,:,minibatch_k);
    dt_train=dt(:,:,minibatch_k);
    ls_train=ls(:,:,minibatch_k);
    lt_train=lt(:,:,minibatch_k);
    
    Input=[ds_train,dt_train];
    
    %����ǰ�򴫲�
    [yn_ds,Iout_ds]=ForwardP(ds_train,w1,b1,w2,b2,midnum,batchsize);
    [yn_dt,Iout_dt]=ForwardP(dt_train,w1,b1,w2,b2,midnum,batchsize);
    
    Iout=[Iout_ds,Iout_dt];
    yn=[yn_ds,yn_dt];
    
    % ���error
    e_total=[ls_train,lt_train]-yn;
    
    %db2
    db2=0.5/batchsize*sum(e_total,2);%�Ծ���������
    
    %dw2
    dw2_s=0;
    for ii=1:2*batchsize
        dw2_s=dw2_s+Iout(:,ii)*e_total(:,ii)';
    end
    dw2=0.5*dw2_s/batchsize;
    
    %db1
    for ib=1:2*batchsize
        S=Iout(:,ib);
        FI(:,ib)=S.*(1-S);
    end
    
    for j=1:1:midnum
        for ij=1:2*batchsize
            db1_b(j,ij)=FI(j,ij)*(w2(j,:)*e_total(:,ij));
        end
    end
    
    db1=0.5/batchsize*sum(db1_b,2);
    
    %dw1�ĸ��¿��Էֳ��������֣���������+MMDmar����+MMDp���֣�
    
    %part-1
    for ix=1:2*batchsize
        x=Input(:,ix);
        e_w1=e_total(:,ix);
        for k=1:1:innum
            for j=1:1:midnum
                dw1_1(j,k,ix)=x(k)*FI(j,ix)*(w2(j,:)*e_w1);
            end
        end
    end
    
    dw1_p1=0.5/batchsize*sum(dw1_1,3);

    %part-2(MMDmar)
    %MMDmar�ֿ��Էֳ�3������ (delta_h,Partial MMD lambda)
    delta_h1=(2/batchsize^2)*(Iout_ds-Iout_dt);
    delta_h2=-(2/batchsize^2)*(Iout_ds-Iout_dt);
    delta_h=[delta_h1,delta_h2];
    
    for iI=1:2*batchsize
        x=Input(:,iI);
        for j=1:midnum
            partial_MMD(:,j,iI)=FI(j,iI)*x;
        end
    end
    
    %��deltah��һ
    for im=1:2*batchsize
        for j=1:1:midnum
            dw1_2(:,j,im)=partial_MMD(:,j,im)*delta_h(j,im);
        end
    end

    dw1_p2=(lambda-1)*(0.5/batchsize*sum(dw1_2,3)');
    
    %���������������dw1_p2����
    dw1=dw1_p1+dw1_p2;

    %����ѧϰ����
    xite=xite-deltaxite;
    
    w1_1=w1;
    w2_1=w2;
    b1_1=b1;
    b2_1=b2;
    
    w1=w1_1+xite*dw1+((1-xite)*mo_w1);
    b1=b1_1+xite*db1+((1-xite)*mo_b1);
    w2=w2_1+xite*dw2+((1-xite)*mo_w2);
    b2=b2_1+xite*db2+((1-xite)*mo_b2);
    
    %momentum
    mo_w1=w1-w1_1;
    mo_b1=b1-b1_1;
    mo_w2=w2-w2_1;
    mo_b2=b2-b2_1;
end

end

