%function [ output_args ] = jiemian( input_args )
%JIEMIAN Summary of this function goes here
%  Detailed explanation goes here


figure;
Wfands=0;BPR=0;
inputpara;
h_menu1=uimenu(gcf,'label','���ܼ���');
h_menu2=uimenu(gcf,'label','���ܼ�����');
h_submenu1=uimenu(h_menu1,'label','����ͼ��','Callback' ,'readmap(Wfands,BPR)');
h_submenu2=uimenu(h_menu1,'label','��Ƶ��ʼ��','Callback' ,'initial');
h_submenu3=uimenu(h_menu1,'label','��Ƶ����','Callback','ondesign');
h_submenu4=uimenu(h_menu1,'label','����Ƶ�����','Callback','point');
h_submenu6=uimenu(h_menu2,'label','��Ƶ������','Callback','open(''design.txt'')');
h_submenu7=uimenu(h_menu2,'label','����Ƶ������','Callback','open(''offdesign.txt'')');
