function Diagnostics0=Baseline_Engine(eta_rec)

%生成偏移
%Fan,COM,LPT,HPT(Eff to Wcor)
Fault=eta_rec;

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
Diagnostics0=[Pt21,Tt21,Pt3,Tt3,Tt44,Pt44,Tt5,Pt5,NH,W13+W21,Wf,F./10];
end