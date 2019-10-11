t1j=168.76;t2j=6.3;
qm1=7.47;qm2=10.1;
yita=0.96;
t1c=t1j-yita*(t1j-t2j);
t2c=t2j+(qm1/qm2)*(t1j-t1c);
C=(qm1/qm2);
tm1=(t1j+t1c)/2;
Dtm=((t1j-t2c)-(t1c-t2j))/log((t1j-t2c)/(t1c-t2j));
tm2=tm1-Dtm;
N1=61;N2=60;L1=620;L2=400;
L3=N1*6+N2*7.5+4
h1=2.5;
h2=3.75;
de1=1.1467;
de2=2.25;
fai1=0.8547;
fai2=0.8475;
beta1=2340;
beta2=1573.3;
Ac1=N1*(L2-9)*4.25/1000000;
Ac2=N2*(L1-12)*6.75/1000000;
Ay1=(L2-9)*(L3-4)/1000000;
Ay2=(L1-12)*(L3-4)/1000000;
q1=Ac1/Ay1;
q2=Ac2/Ay2;
Ap=2*N1*(L1-12)*(L2-9)/1000000;
Af1=N1*(L2-9)*10*L1/1000000;
Af2=N2*(L1-12)*15*L1/1000000;
gm1=qm1/Ac1
gm2=qm2/Ac2
Re1=gm1*de1*1000/23.85;
Re2=gm2*de2*1000/22.079;
Nu1=0.06*Re1^(2/3);
Nu2=0.06*Re2^(2/3);
arf1=Nu1*35.3/de1;
arf2=Nu2*32.4/de2;
m1=(2*arf1/(0.175*0.15))^0.5;
m2=(2*arf2/(0.175*0.15))^0.5;
mh1=m1*0.0025;
mh2=m2*0.00375;
yf1=tanh(mh1)/mh1;
yf2=tanh(mh2)/mh2;
Aef1=Ap+yf1*Af1;
Aef2=Ap+yf2*Af2;
A1=Ap+Af1;
A2=Ap+Af2;
y01=1-(Af1/A1)*(1-yf1);
y02=1-(Af2/A2)*(1-yf2);
Rw=0.0005/(175*Ap);
DKA=1/(y01*arf1*A1)+Rw+1/(y02*arf2*A2);
KA=1/DKA;
K1=KA/A1;
W1=q1*1.0144*1000;
W2=q2*1.0094*1000;
C=W1/W2;
NTU=KA/W1;
yi=1-exp((NTU^0.22/C)*(exp(-C*NTU^0.78)-1));
ytz=yi*0.998;
Q=ytz*W1*(t1j-t2j);
t1cc=t1j-Q/W1
t2cc=t2j+Q/W1
y=[40.6 44 47 50.5];
x=[7 11.57 17.35 24.56];
plot(x,y);
ylabel('质量流速kg/m2·s','fontsize',20);
xlabel('压力损失%','fontsize',20);
axis([6 25 40 55]);



