function [measurement,performancement]=Faultgeneration(Error_lv,Num_Err)
%Faultgeneration
% Error_lv ���Ͼ��� 8*Num_Err
% Num_Err ����������

%����Ԥ����
noise = zeros(8,Num_Err);
Error_source = zeros(8,Num_Err);
measurement = zeros(Num_Err,12);


%������ɹ��ϡ�����ǩ
for i = 1:Num_Err
    Error_source(:,i) = ones(8,1)+Error_lv(:,i);
end

for j=1:Num_Err
%����ģʽ
%����8���������ܲ��� 
% 1.Fan_Eff;2.Fan_W;3.Com_Eff;4.Com_W;5.HPT_Eff;6.HPT_W;7.LPT_Eff;8.LPT_W
Fault=Error_lv(:,j);

%��Ƶ�����¼��
DesignPointData;
%���и߶��������
H=0;Ma=0;
%��ѹת�ӹ�����ȡ��kw��
PWX=0;
%ѹ�����м伶��������100%=1��
ComprDefW=0;
%���Ƶ�ѹת���������ת�٣�100%=1��
NL=1;

%��������
AmbCondition=[H,Ma];
%[��ѹת�ӹ�����ȡ���м伶����]
EngineData=[PWX,ComprDefW];
%����ֵ
Z_Fan=0.65;Z_Compr=0.58;Z_HPT=0.63;Z_LPT=0.63;Wf=0.05;NH=0.9;BPR=3;
%����ֵ����
X=[Z_Fan,Z_Compr,Z_HPT,Z_LPT,Wf,NH,BPR];

%NR�����з���Ƶ��������
[X,~,~,~]=OffDesign_NR(AmbCondition,EngineData,X,NL,Fault);
%�õ����������GTF��������������
GTFEnginePeformance;
% ���в���
%1���Ⱥ���ѹ��2���Ⱥ����£�3ѹ��������ѹ��4ѹ���������£�5��ѹ���ֺ��¶ȣ�
%6��ѹ���ֺ�ѹ����7��ѹ���ֺ��¶ȣ�7��ѹ���ֺ�ѹ����9��ѹת��ת��,10������
%11ȼ��������12����

measurement(j,:) = [Pt21,Tt21,Pt3,Tt3,Tt44,Pt44,Tt5,Pt5,NH,W13+W21,Wf,F./10];

end

%������������ѡȡ��Ҫ�Ĺ�����������
%���Ⱥ����£�ѹ��������ѹ��ѹ���������£���ѹ���ֺ���ѹ����ѹ���ֺ����£���ѹת��ת�٣���������ȼ������
% [Tt21,Pt3,Tt3,Pt44,Tt5,NH,W13+W21,Wf]
DE=measurement(:,[10,2,4,3,6,7,9,11])';% ��������˳��Ĳ�������

% ref���ݲ�������
% ��ֵҪ������
% ����������
% ��Ӧ�ı�׼�[0.5,0.2,0.2,0.3,0.3,0.3,0.1,0.3]%(��λ�ٷֱ�)
SD=0.01*[0.5,0.2,0.2,0.3,0.3,0.3,0.1,0.3];

for i=1:length(SD)
    noise(i,:)=normrnd(0,SD(i),1,Num_Err); %normrnd(MU��sigma) MU��ֵ��sigma��׼��
end

measurement = DE.*(noise+1);
% measurement = DE;
performancement = Error_source;

end