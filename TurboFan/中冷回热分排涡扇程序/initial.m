%function [ output_args ] = ini( input_args )
%INI Summary of this function goes here
%  Detailed explanation goes here

    f_specifyEtar = true;%指定进气道总压恢复系数
    inputpara,%赋值
    
	f_design = 1;	
	f_calCool = 0;	
	f_trans = false;	

		
	f_specifyN1= false;	
	f_specifyN2 = true;
    
	Wfands = Wfands*SIGMAds,%发动机进口流量，进气道总压恢复系数？？
	