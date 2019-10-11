function [Compr_PR,Compr_Wcor,Compr_Eff]=ComprMap_Interp(N,ZC,DesignResult_Compressor,Fault)
%设计点压气机性能参数
d_Sigma_ComprIn=DesignResult_Compressor(1);
d_Compr_PR=DesignResult_Compressor(2);
d_Compr_Eff=DesignResult_Compressor(3);
%设计点压气机进口总压、总温与物理流量
Pt_ind=DesignResult_Compressor(8)*d_Sigma_ComprIn;
Tt_ind=DesignResult_Compressor(9);
W_ind=DesignResult_Compressor(10);
%设计点压气机换算流量
Wcord=W_ind*(101325/Pt_ind)*sqrt(Tt_ind/288.15);
%相对换算转速
N_x = [0.389 0.5425 0.6461 0.7496 0.8032 0.8436 0.8782 0.9327 0.9673 1.0 1.05  1.120];
%辅助线值
ZC_y =[0.0	0.15	0.3	0.45	0.6	0.75	0.9	1.0];
%压气机增压比特性
Compr_PR_Map=reshape([1.0000    2.3175    2.6000    2.7675    2.8750    2.9037    2.9200    2.9278
1.0000    2.5575    2.8475    3.0000    3.1000    3.1400    3.1675    3.1753
1.0000    2.7675    3.0875    3.2625    3.3550    3.3875    3.4007    3.4017
1.0000    3.0150    3.3500    3.5250    3.6250    3.6725    3.6858    3.6868
1.0000    3.2550    3.6500    3.8250    3.9250    3.9725    4.0000    4.0010
1.0000    3.5550    3.9875    4.2000    4.3375    4.4375    4.4508    4.4517
1.0000    3.9300    4.4375    4.6500    4.7875    4.8500    4.8700    4.8777
1.0000    4.3050    4.7975    5.1000    5.2375    5.2632    5.2765    5.2775
1.0000    4.6275    5.1875    5.5125    5.6500    5.7125    5.7257    5.7268
1.0000    4.7700    5.4500    5.8500    6.1000    6.2000    6.2500    6.2510
1.0000    4.8675    5.5850    6.1025    6.3325    6.4550    6.5950    6.6028
1.0000    5.0700    5.7650    6.2900    6.6375    6.8125    6.8625    6.9703],12,8);
%压气机换算流量特性
Compr_Wcor_Map=reshape([3.9320    3.9320    3.5820    3.3220    2.8120    2.4520    1.9920    1.0820
4.2680    4.2680    3.8080    3.4580    2.9780    2.6280    2.1880    1.3380
4.5990    4.5990    4.1290    3.7390    3.3190    2.9590    2.4890    1.6590
4.8840    4.8840    4.3840    3.9740    3.6040    3.2540    2.7740    2.0140
5.1250    5.1250    4.6550    4.2650    3.9050    3.5950    3.1250    2.4750
5.3580    5.3580    4.9680    4.6080    4.2680    3.9880    3.5480    3.0980
5.5950    5.5950    5.2750    4.9550    4.6250    4.3250    3.9150    3.5050
5.8160    5.8160    5.5560    5.2660    4.9660    4.6460    4.2160    3.7560
6.0100    6.0100    5.8300    5.5800    5.2900    4.9800    4.5900    4.1800
6.1000    6.1000    6.0200    5.8500    5.6200    5.3700    5.0300    4.6200
6.1630    6.1630    6.1230    6.0830    5.9030    5.6930    5.3230    4.9330
6.2170    6.2170    6.2170    6.2170    6.1470    5.9770    5.6570    5.2370],12,8);
%压气机效率特性
Compr_Eff_Map=reshape([0.68	0.7	0.71	0.72	0.72	0.7	0.69	0.68
0.69	0.71	0.72	0.725	0.73	0.71	0.7	0.69
0.7	0.725	0.728	0.74	0.73	0.72	0.708	0.7
0.705	0.725	0.73	0.735	0.745	0.725	0.712	0.705
0.71	0.73	0.735	0.74	0.75	0.73	0.715	0.71
0.715	0.735	0.74	0.745	0.755	0.735	0.72	0.715
0.718	0.735	0.742	0.748	0.758	0.738	0.722	0.718
0.72	0.74	0.745	0.758	0.76	0.744	0.725	0.72
0.72	0.74	0.748	0.76	0.773	0.75	0.725	0.72
0.73	0.74	0.748	0.76	0.77	0.76	0.748	0.74
0.73	0.738	0.745	0.75	0.75	0.754	0.744	0.73
0.725	0.73	0.735	0.74	0.74	0.74	0.73	0.725],12,8);

%插值计算结果
Compr_PR_MapResult= interp2(ZC_y,N_x,Compr_PR_Map,ZC,N,'linear');
Compr_Wcor_MapResult= interp2(ZC_y,N_x,Compr_Wcor_Map,ZC,N,'linear');
Compr_Eff_MapResult= interp2(ZC_y,N_x,Compr_Eff_Map,ZC,N,'linear');

%设计点插值位置
Compr_PR_Mapd= interp2(ZC_y,N_x,Compr_PR_Map,0.52632,1,'linear');
Compr_Wcor_Mapd= interp2(ZC_y,N_x,Compr_Wcor_Map,0.52632,1,'linear');
Compr_Eff_Mapd= interp2(ZC_y,N_x,Compr_Eff_Map,0.52632,1,'linear');

%压气机设计点与耦合系数计算
Compr_PR_d=d_Compr_PR;
Compr_Wcor_d=Wcord;
Compr_Eff_d=d_Compr_Eff;
CoupCompr_PR=(Compr_PR_d-1)/(Compr_PR_Mapd-1);
CoupCompr_Wcor=(1+Fault(4))*Compr_Wcor_d/Compr_Wcor_Mapd;
CoupCompr_Eff=(1+Fault(3))*Compr_Eff_d/Compr_Eff_Mapd;

%计算结果
Compr_PR=CoupCompr_PR*(Compr_PR_MapResult-1)+1;
Compr_Wcor=CoupCompr_Wcor*Compr_Wcor_MapResult;
Compr_Eff=CoupCompr_Eff*Compr_Eff_MapResult;

% % 绘制特性图 
% for i=1:10
%  x=Compr_Wcor_Map(i,1:20);
%  y=Compr_PR_Map(i,1:20);
%  z=Compr_Eff_Map(i,1:20);
%  subplot(2,1,1);
%  plot(x,y,'b');
%  hold on 
%  subplot(2,1,2);
%  plot(x,z,'g');
%  hold on 
% end
