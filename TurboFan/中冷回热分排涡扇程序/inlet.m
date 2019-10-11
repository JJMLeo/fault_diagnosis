%function [Tino,Pino,Hino] = inlet(H,Ma)
%INLET Summary of this function goes here
%  Detailed explanation goes here


if f_specifyEtar %给定sigma
    SIGMA=SIGMAds; %总压恢复系数
else
      if Ma<=1.0
            SIGMA=0.97;
     else
          SIGMA=0.88722+0.1717*Ma-0.08986*Ma^2;
      end
  end
 SIGMA=SIGMAds,
 Tino=Ttenvo;%进气道出口总温
 Pino=SIGMA*Ptenvo;%进气道出口总压
 Hino=gashi(Tino,0);%进气道出口总焓


