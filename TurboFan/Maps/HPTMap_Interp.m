function [HPT_DHT,HPT_Wcor,HPT_Eff]=HPTMap_Interp(N,ZC,DesignResult_HPT,Fault)
%设计点高压涡轮性能参数
d_HPT_Eff=DesignResult_HPT(1);
%设计点高压涡轮进口总压、总温与物理流量
Pt_ind=DesignResult_HPT(2);
Tt_ind=DesignResult_HPT(3);
W_ind=DesignResult_HPT(4);
Load_HPSpool_d=DesignResult_HPT(5);
%设计点高压涡轮换算流量
Wcord=W_ind*(101325/Pt_ind)*sqrt(Tt_ind/288.15);
%相对换算转速
N_x = [0.2508 0.3763 0.5641 0.7869 1.0129 1.2542 1.3333];
%辅助线值
ZC_y =[0.05 0.1 0.2 0.3 0.4 0.5 0.6 0.8 1];
%高压涡轮单位换算功特性
HPT_DHT_Map=[0.05 0.1 0.2 0.3 0.4 0.5 0.6 0.8 1];
%高压涡轮换算流量特性
HPT_Wcor_Map=[0.7281 0.8297 0.9819 1.0212 1.0319 1.0340 1.034 1.034 1.0340
            0.6813 0.7819 0.9521 1.0031 1.0159 1.0212 1.0212 1.0212 1.0212
            0.6500 0.7617 0.9276 0.9840 1.0085 1.0170 1.0170 1.0170 1.0170
            0.6312 0.7340 0.9138 0.9766 1.0042 1.0106 1.0106 1.0106 1.0106
            0.6156 0.7181 0.9053 0.9702 0.9999 1.0106 1.0106 1.0106 1.0106
            0.6075 0.7021 0.9021 0.9681 0.9946 1.0106 1.0106 1.0106 1.0106
            0.6062 0.7000 0.9000 0.9656 0.9938 1.0106 1.0106 1.0106 1.0106];
%高压涡轮效率特性
HPT_Eff_Map=[0.463 0.4406 0.3843 0.3727 0.3797 0.4076 0.4386 0.5123 0.5728 
            0.6620 0.6296 0.5495 0.5014 0.4743 0.4720 0.4890 0.5456 0.6061 
            0.7241 0.7296 0.6796 0.6259 0.5898 0.5704 0.5704 0.6030 0.6526 
            0.7627 0.7766 0.7676 0.7454 0.7222 0.7065 0.6944 0.6921 0.7061 
            0.7454 0.7685 0.7870 0.7926 0.7907 0.7843 0.7806 0.7759 0.7722 
            0.5880 0.6389 0.7315 0.7778 0.8019 0.8148 0.8204 0.8203 0.8167 
            0.5619 0.6076 0.7061 0.7778 0.8019 0.8148 0.8204 0.8204 0.8167];

%插值计算
HPT_DHT_MapDHTesult=interp1(ZC_y,HPT_DHT_Map,ZC,'linear');
HPT_Wcor_MapDHTesult=interp2(ZC_y,N_x,HPT_Wcor_Map,ZC,N ,'linear');
HPT_Eff_MapDHTesult=interp2(ZC_y,N_x,HPT_Eff_Map,ZC,N ,'linear');

%设计点插值位置
HPT_DHT_Mapd= interp1(ZC_y,HPT_DHT_Map,0.65,'linear');
HPT_Wcor_Mapd= interp2(ZC_y,N_x,HPT_Wcor_Map,0.65,1,'linear');
HPT_Eff_Mapd= interp2(ZC_y,N_x,HPT_Eff_Map,0.65,1,'linear');

%高压涡轮设计点与耦合系数计算
HPT_DHT_d=Load_HPSpool_d/(W_ind*Tt_ind*1e-3);
HPT_Wcor_d=Wcord;
HPT_Eff_d=d_HPT_Eff;
CoupHPT_DHT=HPT_DHT_d/HPT_DHT_Mapd;
CoupHPT_Wcor=(1+Fault(6))*HPT_Wcor_d/HPT_Wcor_Mapd;
CoupHPT_Eff=(1+Fault(5))*HPT_Eff_d/HPT_Eff_Mapd;

%计算结果
HPT_DHT=CoupHPT_DHT*HPT_DHT_MapDHTesult;
HPT_Wcor=CoupHPT_Wcor*HPT_Wcor_MapDHTesult;
HPT_Eff=CoupHPT_Eff*HPT_Eff_MapDHTesult;

% % 绘制特性图 
% for i=1:7
%  x=HPT_DHT_Map(1,1:9);
%  y=HPT_Wcor_Map(i,1:9);
%  z=HPT_Eff_Map(i,1:9);
%  subplot(3,1,1);
%  plot(x,x,'r');
%  hold on 
%  subplot(3,1,2);
%  plot(x,y,'b');
%  hold on 
%  subplot(3,1,3);
%  plot(x,z,'g');
%  hold on 
% end