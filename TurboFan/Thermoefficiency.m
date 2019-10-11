clc
clear

N=10;

% 有效循环数为6 000时的健康参数退化规律
Case=[-2.85	-3.65 -9.40 -14.06 -3.81 2.57 -1.078 0.4226];

%u=linspace(0.05,0.1,N);

eta_t_List = zeros(N,1);

for ii=1:N
    
    Error_lv=0.01*Case*((ii-1)/10);
    
    %故障模式
    %考虑8个故障性能参数(1.Fan_Eff;2.Fan_W;3.Com_Eff;4.Com_W;5.HPT_Eff;6.HPT_W;7.LPT_Eff;8.LPT_W)
    Fault=Error_lv;

    %设计点数据录入
    DesignPointData;
    %飞行高度与马赫数
    H=0;Ma=0;
    %高压转子功率提取（kw）
    PWX=0;
    %压气机中间级放气量（100%=1）
    ComprDefW=0;
    %控制低压转子相对物理转速（100%=1）
    NL=1;

    AmbCondition=[H,Ma];
    EngineData=[PWX,ComprDefW];
    %初猜值向量
    Z_Fan=0.65;Z_Compr=0.58;Z_HPT=0.63;Z_LPT=0.63;Wf=0.05;NH=0.9;BPR=3;
    %初猜值向量示例
    X=[Z_Fan,Z_Compr,Z_HPT,Z_LPT,Wf,NH,BPR];

    %NR法进行非设计点迭代计算
    [X,Step,Norm_E,E0]=OffDesign_NR(AmbCondition,EngineData,X,NL,Fault);

    %用迭代结果进行GTF发动机热力计算
    GTFEnginePeformance;

    % 热效率序列记录
    eta_t_List(ii)=eta_t;
end



