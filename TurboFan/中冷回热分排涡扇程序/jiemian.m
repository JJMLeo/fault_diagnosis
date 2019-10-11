%function [ output_args ] = jiemian( input_args )
%JIEMIAN Summary of this function goes here
%  Detailed explanation goes here


figure;
Wfands=0;BPR=0;
inputpara;
h_menu1=uimenu(gcf,'label','性能计算');
h_menu2=uimenu(gcf,'label','性能计算结果');
h_submenu1=uimenu(h_menu1,'label','读入图表','Callback' ,'readmap(Wfands,BPR)');
h_submenu2=uimenu(h_menu1,'label','设计点初始化','Callback' ,'initial');
h_submenu3=uimenu(h_menu1,'label','设计点计算','Callback','ondesign');
h_submenu4=uimenu(h_menu1,'label','非设计点点计算','Callback','point');
h_submenu6=uimenu(h_menu2,'label','设计点计算结果','Callback','open(''design.txt'')');
h_submenu7=uimenu(h_menu2,'label','非设计点计算结果','Callback','open(''offdesign.txt'')');
