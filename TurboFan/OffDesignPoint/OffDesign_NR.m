function [X,Step,Norm_E0,E0]=OffDesign_NR(AmbCondition,EngineData,X0,NL,Fault)
%非线性迭代

%input
% AmbCondition 飞行条件=[高度，马赫数]
% EngineData 耗散参数=[高压转子功率提取，中间级放气]
% X0 初猜值
% NL 低压转子转速——控制低压转子转速
% Fault 耦合因子
% Fault = [err_fan_eff,err_fan_W,err_com_eff,err_com_W,err_HPT_eff,err_HPT_W,err_LPT_eff,err_LPT_W]

%output
% X 迭代计算后的向量
% Step 迭代步数

Norm_E0=1;
Step=0;
while Norm_E0>=1e-6
    [E0,Norm_E0]=FcnGTFEngine(AmbCondition,EngineData,NL,X0,Fault);
    
    
    X1=[1.001*X0(1),X0(2),X0(3),X0(4),X0(5),X0(6),X0(7)];
    X2=[X0(1),1.001*X0(2),X0(3),X0(4),X0(5),X0(6),X0(7)];
    X3=[X0(1),X0(2),1.001*X0(3),X0(4),X0(5),X0(6),X0(7)];
    X4=[X0(1),X0(2),X0(3),1.001*X0(4),X0(5),X0(6),X0(7)];
    X5=[X0(1),X0(2),X0(3),X0(4),1.001*X0(5),X0(6),X0(7)];
    X6=[X0(1),X0(2),X0(3),X0(4),X0(5),1.001*X0(6),X0(7)];
    X7=[X0(1),X0(2),X0(3),X0(4),X0(5),X0(6),1.001*X0(7)];
    
    E1=FcnGTFEngine(AmbCondition,EngineData,NL,X1,Fault);
    E2=FcnGTFEngine(AmbCondition,EngineData,NL,X2,Fault);
    E3=FcnGTFEngine(AmbCondition,EngineData,NL,X3,Fault);
    E4=FcnGTFEngine(AmbCondition,EngineData,NL,X4,Fault);
    E5=FcnGTFEngine(AmbCondition,EngineData,NL,X5,Fault);
    E6=FcnGTFEngine(AmbCondition,EngineData,NL,X6,Fault);
    E7=FcnGTFEngine(AmbCondition,EngineData,NL,X7,Fault);
    
    E=[E1;E2;E3;E4;E5;E6;E7]';
    
    Jacobi=zeros(7,7);
    for j=1:7
        for i=1:7
            Jacobi(i,j)=(E(i,j)-E0(i))/(X0(j)*(0.001));
        end
    end
    
    X0=(X0'-(Jacobi)\E0')';
    
    Step=Step+1;
    if Step>=50
        break
    end
end
Z_Fan=X0(1);Z_Compr=X0(2);Z_HPT=X0(3);Z_LPT=X0(4);Wf=X0(5);NH=X0(6);BPR=X0(7);
X=[Z_Fan,Z_Compr,Z_HPT,Z_LPT,Wf,NH,BPR];