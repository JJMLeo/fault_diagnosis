%function [Tino,Pino,Hino] = inlet(H,Ma)
%INLET Summary of this function goes here
%  Detailed explanation goes here


if f_specifyEtar %����sigma
    SIGMA=SIGMAds; %��ѹ�ָ�ϵ��
else
      if Ma<=1.0
            SIGMA=0.97;
     else
          SIGMA=0.88722+0.1717*Ma-0.08986*Ma^2;
      end
  end
 SIGMA=SIGMAds,
 Tino=Ttenvo;%��������������
 Pino=SIGMA*Ptenvo;%������������ѹ
 Hino=gashi(Tino,0);%��������������


