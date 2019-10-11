clc
clear all
%5.386871 ��
tic

%����������
Error_Num=5;

%��ֵ����
mean_h=linspace(0.01,0.03,Error_Num);%Mainprogram.m�ļ����ƶ���
sigma_h=linspace(0.005,0.01,Error_Num);%Mainprogram.m�ļ����ƶ���

eta_rec=zeros(1,8);%Faultgeneration.m�ļ����ƶ���
Base=ones(1,8)+eta_rec;%Faultgeneration.m�ļ����ƶ���

%������ɹ���
for ii=1:Error_Num
Error_lv=normrnd(mean_h(ii),sigma_h(ii),1,8); %Mainprogram.m�ļ����ƶ���
Error_source(ii,:)=((ones(1,8)-Error_lv).*Base-ones(1,8));
end

Diagnostics0=Baseline_Engine(eta_rec);
%Diagnostics0=[164549.515335179,338.380823092353,1894055.41503232,733.607199635388,1091.92341326707,489642.928414467,874.539256472417,168525.450458184,1.01336969742748,42.4224900567488,0.170219702643162,1428.17060442361]

for j=1:Error_Num

%����ģʽ
%����8���������ܲ���(1.Fan_Eff;2.Fan_W;3.Com_Eff;4.Com_W;5.HPT_Eff;6.HPT_W;7.LPT_Eff;7.LPT_W)
Fault=-Error_source(j,:);

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

AmbCondition=[H,Ma];
EngineData=[PWX,ComprDefW];
%����ֵ����
Z_Fan=0.65;Z_Compr=0.58;Z_HPT=0.63;Z_LPT=0.63;Wf=0.05;NH=0.9;BPR=3;
%����ֵ����ʾ��
X=[Z_Fan,Z_Compr,Z_HPT,Z_LPT,Wf,NH,BPR];

%NR�����з���Ƶ��������
[X,Step,Norm_E,E0]=OffDesign_NR(AmbCondition,EngineData,X,NL,Fault);
%�õ����������GTF��������������
GTFEnginePeformance;
%ѡ��ļ�������[1,2,3,4,5,6,8,9,10]
%���Ⱥ���ѹ�����Ⱥ����£�ѹ��������ѹ��ѹ���������£���ѹ���ֺ��¶ȣ���ѹ���ֺ�ѹ������ѹ���ֺ��¶ȣ���ѹ���ֺ�ѹ������ѹת��ת��

Diagnostics=[Pt21,Tt21,Pt3,Tt3,Tt44,Pt44,Tt5,Pt5,NH,W13+W21,Wf,F./10];

DE0(j,:)=Diagnostics./Diagnostics0-1;

end

%��Ӧ�ı�׼�[0.3,0.2,0.3,0.2,0.5,0.3,0.2,0.3,0.1]%(��λ�ٷֱ�)
SD=0.01*[0.3,0.2,0.3,0.2,0.5,0.3,0.2,0.3,0.1];
ESD=diag(SD);

%��������
DE=DE0(:,[1,2,3,4,5,6,8,9,10])';
EL=Error_source';

for i=1:length(SD)
    Ds(i,:)=normrnd(DE(i,:),SD(i));
end

Ls=EL;

% Ds_noise(:,:,ii)=Ds;
% Ls_noise(:,:,ii)=Ls;

toc
%save('Sourcedomain(noise)','Ds_noise','Ls_noise') 