function Diagnostics0=Baseline_Engine(eta_rec)

%����ƫ��
%Fan,COM,LPT,HPT(Eff to Wcor)
Fault=eta_rec;

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
Diagnostics0=[Pt21,Tt21,Pt3,Tt3,Tt44,Pt44,Tt5,Pt5,NH,W13+W21,Wf,F./10];
end