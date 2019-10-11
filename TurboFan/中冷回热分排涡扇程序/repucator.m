function [Tltoi,Tcomoi,Deltp3,Deltp4,ytz,mcore2,L1,L2,L3]=repucator(Tcomo,Tlto,Pcomo,Plto,Wcomp,Wlto,BPR)
if Tlto<Tcomo
     error('��ѹ���ֳ����¶�С��ѹ���������¶�,�޷�����');
end;
%����Ч��
yita=0.6;
k=0.001;
t1j=Tlto-273;t2j=Tcomo-273;
qm1=Wcomp/8;qm2=Wlto/8;
%Ԥ������
t1c=t1j-yita*(t1j-t2j)
t2c=t2j+(qm1/qm2)*(t1j-t1c)
C=(qm1/qm2);
%�Ȳ�ƽ���¶�
tm1=(t1j+t1c)/2;
%����ƽ���²�
%Dtm=((t1j-t2c)-(t1c-t2j))/log((t1j-t2c)/(t1c-t2j));
%Dtm=t1j-t2c;
%���ƽ���¶�
tm2=(t2j+t2c)/2;
for i=1:1:500 
%���ȿ������Բ���
    if i>500
        error('������Ч�ʼ��㲻����');
    end;
mu1=1.50619*k*k*(273+tm1)^1.5/(tm1+395);mu2=1.50619*k*k*(273+tm2)^1.5/(tm2+395);
nam1=2.456*k*0.1*(tm1+273)^0.823;nam2=2.456*k*0.1*(tm2+273)^0.823;
cp1=1003+0.02*tm1+4*k*0.1*tm1^2;cp2=1003+0.02*tm2+4*k*0.1*tm2^2;
Pr1=0.6813;Pr2=0.6977;
%��Ƭ����
N1=70;N2=71;
%������������
k=0.001;
L1=100*k;L2=800*k;
%��Ƭ���
sf1=1.5*k;sf2=1.5*k;
%���� ������0.5 ��Ƭ���0.15 �����2 �������6
s1=7.5*k;s2=7.5*k;
%���������򳤶�
L3=N1*(s1+1*k)+N2*s2+4*k;
%��Ƭ��
h1=0.5*s1;
h2=0.5*s2;
%��������ֱ��
de1=2*(sf1*s1-2*h1*0.15*k)/(sf1+2*h1);
de2=2*(sf2*s2-2*h2*0.15*k)/(sf2+2*h2);
%��Ƭ�����
fai1=2*h1/(sf1-0.15+2*h1);
fai2=2*h2/(sf2-0.15+2*h2);
%��������ܶ�
beta1=(2*(sf1-0.15)+4*h1)/(s1*sf1);
beta2=(2*(sf2-0.15)+4*h2)/(s2*sf2);
%������ͨ��� 
Ac1=N1*(L2-2*6*k)*(s1-2*h1*0.15*k/sf1);
Ac2=N2*(L1-2*6*k)*(s2-2*h2*0.15*k/sf2);
%����ӭ�����
Ay1=(L2-2*6*k)*(L3-2*2*k);
Ay2=(L1-2*6*k)*(L3-2*2*k);
%�Ȳ�׶�
sim1=Ac1/Ay1
sim2=Ac2/Ay2
%һ�δ������
Ap=2*N1*(L1-2*6*k)*(L2-2*6*k);
%���δ������
Af1=N1*((L2-2*6*k)/sf1)*2*h1*L1*2;
Af2=N2*((L2-2*6*k)/sf2)*2*h2*L2*2;
%��������
gm1=qm1/Ac1
gm2=qm2/Ac2
%��ŵ��
Re1=gm1*de1/mu1
Re2=gm2*de2/mu2
%����ϵ��
if Re1>2200&Re1<10000
    Nu1=0.06*Re1^(2/3)
else
    Nu1=0.023*Re1^0.8*Pr1^0.3
end
if Re2>2200&Re2<10000
    Nu2=0.06*Re2^(2/3)
else
    Nu2=0.023*Re2^0.8*Pr2^0.4
end
arf1=Nu1*nam1/de1
arf2=Nu2*nam2/de2
%��Ƭ���� ���� ����ϵ��190
m1=(2*arf1/(190*0.15*k))^0.5;
m2=(2*arf2/(190*0.15*k))^0.5;
mh1=m1*h1;
mh2=m2*h2;
yf1=tanh(mh1)/mh1;
yf2=tanh(mh2)/mh2;
%��Ч�������
Aef1=Ap+yf1*Af1;
Aef2=Ap+yf2*Af2;
%�����ܴ������
A1=Ap+Af1;
A2=Ap+Af2;
%�������Ч��
y01=1-(Af1/A1)*(1-yf1);
y02=1-(Af2/A2)*(1-yf2);
%����������ܴ���ϵ��
Rw=0.0005/(190*Ap);
DKA=1/(y01*arf1*A1)+Rw+1/(y02*arf2*A2);
KA=1/DKA;
K1=KA/A1;
%���ȵ�Ԫ�� ������Ч�� ���������¶�
W1=qm1*cp1;
W2=qm2*cp2;
Wmin=min(W1,W2);
Wmax=max(W1,W2);
C=Wmin/Wmax
NTU=KA/W1
yi=1-exp((NTU^0.22/C)*(exp(-C*NTU^0.78)-1))
ytz=yi*0.998
Q=ytz*Wmin*(t1j-t2j);
t1cc=t1j-Q/W1
t2cc=t2j+Q/W2
i
if abs(t1cc-t1c)<1&abs(t2cc-t2c)<0.5
    zz1=t1cc-t1c
    zz2=t2cc-t2c
   break;
else
    tm1=0.5*(t1cc+t1j);
    tm2=0.5*(t2cc+t2j);
end
t1c=t1cc
t2c=t2cc
end
Tltoi=t1cc+273;
Tcomoi=t2cc+273;
[Deltp3,Deltp4]=pressureloss2(Plto,Re1,de1,L1,gm1,sim1,t1j,t1cc,Pcomo,Re2,de2,L2,gm2,sim2,t2j,t2cc);

mf1=N1*((L2-2*6*k)/sf1)*sqrt(s1^2+sf1^2)*L1*0.00015*7750;
mf2=N2*((L1-2*6*k)/sf2)*sqrt(s2^2+sf2^2)*L2*0.00015*7750;
mps=(N1*0.0005+2*0.002)*L1*L2*7750;
ms1=2*N1*L1*6*k*s1*7750;
ms2=2*N2*L2*6*k*s2*7750;
mcore2=mf1+mf2+mps+ms1+ms2;
%fid = fopen('shiyanshuju1.txt','at+');
%fprintf(fid,'��������Ч��=%5.2f   ����ѹ��=%5.2f   ѹ����ѹ��=%5.2f\r\n',ytz,Deltp3,Deltp4);
%fprintf(fid,'��������Ч��=%5.2f   ��=%5.2f   ��=%5.2f   ��=%5.2f N1=%5.2f   N2=%5.2f      ����=%5.2f\r\n',ytz,L1,L2,L3,N1,N2,mcore1);
%fprintf(fid,'��=%5.2f   ��=%5.2f   ��=%5.2f N1=%5.2f   N2=%5.2f      ����=%5.2f\r\n',L1,L2,L3,N1,N2,mcore2);
%fclose(fid);