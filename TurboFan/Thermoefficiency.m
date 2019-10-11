clc
clear

N=10;

% ��Чѭ����Ϊ6 000ʱ�Ľ��������˻�����
Case=[-2.85	-3.65 -9.40 -14.06 -3.81 2.57 -1.078 0.4226];

%u=linspace(0.05,0.1,N);

eta_t_List = zeros(N,1);

for ii=1:N
    
    Error_lv=0.01*Case*((ii-1)/10);
    
    %����ģʽ
    %����8���������ܲ���(1.Fan_Eff;2.Fan_W;3.Com_Eff;4.Com_W;5.HPT_Eff;6.HPT_W;7.LPT_Eff;8.LPT_W)
    Fault=Error_lv;

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

    % ��Ч�����м�¼
    eta_t_List(ii)=eta_t;
end



