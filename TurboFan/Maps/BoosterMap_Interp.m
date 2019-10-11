function [Booster_PR,Booster_Wcor,Booster_Eff]=BoosterMap_Interp(N,ZC,DesignResult_Booster)
%��Ƶ���ѹ�����ܲ���
d_Booster_PR=DesignResult_Booster(1);
d_Booster_Eff=DesignResult_Booster(2);
%��Ƶ���ѹ��������ѹ����������������
Pt_ind=DesignResult_Booster(3);
Tt_ind=DesignResult_Booster(4);
W_ind=DesignResult_Booster(5);
%��Ƶ���ѹ����������
Wcord=W_ind*(101325/Pt_ind)*sqrt(Tt_ind/288.15);
%��Ի���ת��
N_x = [0.359 0.528 0.66 0.791 0.88 0.952 1 1.028 1.144];
%������ֵ
ZC_y =[0.00000 0.05263 0.10526 0.15789 0.21053 0.26316 0.31579 0.36842 0.42105 0.47368 0.52632 0.57895 0.63158 0.68421 0.73684 0.78947 0.84211 0.89474 0.94737 1.00000 ];
%��ѹ����ѹ������
Booster_PR_Map=[0.92409 0.94734 0.96963 0.99096 1.01134 1.03053 1.04829 1.06435 1.07862 1.09093 1.10134 1.11018 1.11784 1.12432 1.12985 1.13438 1.13781 1.13998 1.14089 1.14053 
              1.02208 1.05309 1.08321 1.11185 1.13901 1.16485 1.18827 1.20977 1.22913 1.24602 1.26129 1.27504 1.28725 1.29792 1.30725 1.31519 1.32188 1.32732 1.33149 1.33440 
              1.13784 1.17678 1.21531 1.25178 1.28764 1.32089 1.35288 1.38187 1.40852 1.43302 1.45487 1.47509 1.49313 1.50907 1.52333 1.53523 1.54583 1.55521 1.56338 1.57032 
              1.28787 1.33760 1.38622 1.43475 1.48210 1.52789 1.57310 1.61464 1.65541 1.69154 1.72617 1.75708 1.78578 1.81105 1.83355 1.85292 1.86922 1.88260 1.89482 1.90586 
              1.44146 1.49658 1.55171 1.60658 1.66130 1.71585 1.76806 1.82012 1.86911 1.91685 1.96055 2.00269 2.04006 2.07593 2.10726 2.13624 2.16125 2.18310 2.20155 2.21894 
              1.58279 1.64213 1.70147 1.76080 1.82014 1.87947 1.93865 1.99745 2.05553 2.11185 2.16638 2.21895 2.26762 2.31390 2.35757 2.39698 2.43365 2.46747 2.49641 2.52445 
              1.68344 1.74549 1.80755 1.86961 1.93167 1.99373 2.05579 2.11784 2.17990 2.24150 2.30258 2.36145 2.41837 2.47274 2.52417 2.57273 2.61817 2.65993 2.69827 2.73541 
              1.72120 1.78423 1.84726 1.91029 1.97332 2.03635 2.09938 2.16241 2.22544 2.28847 2.35115 2.41265 2.47255 2.53032 2.58541 2.63770 2.68715 2.73360 2.77692 2.81912 
              1.85698 1.92331 1.98964 2.05598 2.12231 2.18864 2.25497 2.32130 2.38763 2.45396 2.52029 2.58663 2.65253 2.71797 2.78294 2.84640 2.90744 2.96736 3.02546 3.08323];
%��ѹ��������������
Booster_Wcor_Map=[124.65775 121.75579 118.85383 115.95188 113.04992 110.06981 106.94243 103.60024 100.03992 96.23795 92.22882 88.13062 84.05632 80.00694 76.04159 72.14340 68.28065 64.41790 60.55515 56.69240
                  159.94666 158.07774 156.13965 153.98351 151.63368 149.14650 146.27401 143.16527 139.78906 136.09641 132.29239 128.41141 124.45399 120.42741 116.37470 112.29303 108.21136 104.12969 100.04802 95.96635 
                  191.17928 190.10637 189.02541 187.58557 186.12389 184.23666 182.22597 179.76842 177.02192 174.04072 170.75139 167.35222 163.75404 159.98319 156.11904 152.05645 147.97521 143.89396 139.81272 135.73147 
                  223.80188 223.78140 223.55710 223.33280 222.91831 222.26956 221.56322 220.31363 219.01290 217.07583 215.00973 212.49969 209.78584 206.70699 203.37328 199.74565 195.84441 191.70381 187.56322 183.42262 
                  251.99000 251.99000 251.99000 251.95132 251.89044 251.80959 251.39489 250.98019 250.16428 249.21887 247.78455 246.21073 244.09721 241.87838 239.18795 236.31107 233.06111 229.54917 225.75720 221.96523 
                  274.92100 274.92100 274.92100 274.92100 274.92100 274.92100 274.90015 274.83182 274.67440 274.30910 273.74230 272.96622 271.76761 270.34153 268.67402 266.59303 264.28247 261.74229 258.76241 255.77952 
                  289.95600 289.95600 289.95600 289.95600 289.95600 289.95600 289.95600 289.95600 289.95600 289.90237 289.79107 289.43447 288.87666 288.06252 286.96419 285.60089 283.96005 281.99595 279.74861 277.45013 
                  295.36700 295.36700 295.36700 295.36700 295.36700 295.36700 295.36700 295.36700 295.36700 295.36702 295.32713 295.15820 294.82257 294.27031 293.45730 292.38318 291.05662 289.47158 287.62652 285.72779 
                  313.92950 313.92950 313.92950 313.92950 313.92950 313.92950 313.92950 313.92950 313.92950 313.92950 313.92950 313.92950 313.88497 313.79592 313.66234 313.38620 312.88562 312.29459 311.55263 310.80288];
%��ѹ��Ч������
Booster_Eff_Map=[0.40000 0.48070 0.55010 0.60500 0.65170 0.68710 0.71340 0.72910 0.73780 0.74020 0.74000 0.73770 0.73290 0.72640 0.71840 0.70900 0.69820 0.68430 0.66970 0.65190
                  0.42840 0.51470 0.58910 0.64790 0.69790 0.73580 0.76390 0.78080 0.79010 0.79270 0.79250 0.78990 0.78490 0.77780 0.76930 0.75920 0.74770 0.73280 0.71710 0.69810
                  0.45429 0.54588 0.62478 0.68708 0.74015 0.78035 0.81018 0.82807 0.83789 0.84070 0.84048 0.83776 0.83241 0.82495 0.81593 0.80517 0.79298 0.77719 0.76053 0.74035 
                  0.55133 0.61502 0.66861 0.71648 0.75647 0.78861 0.81608 0.83368 0.84504 0.84962 0.85053 0.84842 0.84481 0.83789 0.82887 0.81758 0.80566 0.79386 0.78070 0.76754 
                  0.58742 0.63419 0.67700 0.71477 0.74840 0.77879 0.80391 0.82436 0.83880 0.84842 0.85263 0.85415 0.85285 0.85042 0.84566 0.83965 0.83188 0.82286 0.81208 0.80027 
                  0.59161 0.62825 0.66340 0.69501 0.72398 0.75070 0.77486 0.79583 0.81411 0.82856 0.83948 0.84701 0.85021 0.85156 0.85132 0.84887 0.84518 0.84033 0.83370 0.82689 
                  0.59311 0.62569 0.65576 0.68340 0.70822 0.73146 0.75342 0.77392 0.79233 0.80857 0.82269 0.83319 0.84071 0.84526 0.84741 0.84799 0.84701 0.84460 0.84092 0.83683 
                  0.59132 0.62153 0.64956 0.67561 0.69841 0.72092 0.74044 0.75923 0.77712 0.79379 0.80808 0.82010 0.82966 0.83636 0.84020 0.84216 0.84285 0.84216 0.84027 0.83794 
                  0.55993 0.58794 0.61411 0.63863 0.66179 0.68241 0.70227 0.71960 0.73587 0.74994 0.76316 0.77500 0.78531 0.79484 0.80361 0.81088 0.81703 0.82076 0.82265 0.82341];

%��ֵ������
Booster_PR_MapResult= interp2(ZC_y,N_x,Booster_PR_Map,ZC,N,'linear');
Booster_Wcor_MapResult= interp2(ZC_y,N_x,Booster_Wcor_Map,ZC,N,'linear');
Booster_Eff_MapResult= interp2(ZC_y,N_x,Booster_Eff_Map,ZC,N,'linear');

%��Ƶ��ֵλ��
Booster_PR_Mapd= interp2(ZC_y,N_x,Booster_PR_Map,0.78947,1,'linear');
Booster_Wcor_Mapd= interp2(ZC_y,N_x,Booster_Wcor_Map,0.78947,1,'linear');
Booster_Eff_Mapd= interp2(ZC_y,N_x,Booster_Eff_Map,0.78947,1,'linear');

%��ѹ����Ƶ������ϵ������
Booster_PR_d=d_Booster_PR;
Booster_Wcor_d=Wcord;
Booster_Eff_d=d_Booster_Eff;
CoupBooster_PR=(Booster_PR_d-1)/(Booster_PR_Mapd-1);
CoupBooster_Wcor=Booster_Wcor_d/Booster_Wcor_Mapd;
CoupBooster_Eff=Booster_Eff_d/Booster_Eff_Mapd;

%������
Booster_PR=CoupBooster_PR*(Booster_PR_MapResult-1)+1;
Booster_Wcor=CoupBooster_Wcor*Booster_Wcor_MapResult;
Booster_Eff=CoupBooster_Eff*Booster_Eff_MapResult;

% % ������ѹ������ͼ 
% for i=1:9
%  x=Booster_Wcor_Map(i,1:20);
%  y=Booster_PR_Map(i,1:20);
%  z=Booster_Eff_Map(i,1:20);
%  subplot(2,1,1);
%  plot(x,y,'b');
%  hold on 
%  subplot(2,1,2);
%  plot(x,z,'g');
%  hold on 
% end