% function [ output_args ] =
% main(kk,MECHN1,MECHN2,AREA,ALTITUDE,MACH,RC,RF)
%MAIN Summary of this function goes here
%  Detailed explanation goes here

kk=1,MECHN1=100,MECHN2=100,AREA=1,ALTITUDE=10668,MACH=0.8,RC=0.7,RF=0.4,icper=1.0/13.5;
% kk=1,MECHN1=100,MECHN2=100,AREA=1,ALTITUDE=0,MACH=0,RC=0.7,RF=0.4,icper=1.0/13.5;
   f_throttle=false;f_guess=0;f_trans =0;
   
   % A8ds =0; T1ds = 0; T2ds = 0;T3ds = 0;T4ds = 0;
   traditional=0;
   f_bleedgas=0;
   
    XI=[0,0,0,0,0,0,0,0];
    XII=[0,0,0,0,0,0,0,0];
    Z=[0,0,0,0,0,0,0,0];
  
    initial;
    ondesign_guan;