x0=[0.0704 0.0795 0.0859 0.1044 0.1109 0.1221 0.1305 0.1451];
y0=[64732.179 63680.188 62953.721 61030.494 60311.417 59108.512 58210.156 56688.798];
y1=[27611.8665 27657.98 27685.595 27749.812 27768.16 27795.659 27813.979 27841.453];
[AX,H1,H2]=plotyy(x0,y0,x0,y1,'plot');

set(AX(1),'XColor','k','YColor','b');
set(AX(2),'XColor','k','YColor','r');

set(AX(1),'Ylim',[56600,64800])   
set(AX(2),'Ylim',[27600,27845]) 

set(AX(1),'Ytick',[56600:1640:64800])   
set(AX(2),'Ytick',[27600:49:27845]) 

HH1=get(AX(1),'Ylabel');
set(HH1,'String','低压涡轮出口压力/Pa','fontsize',15);
set(HH1,'color','k');

HH2=get(AX(2),'Ylabel');
set(HH2,'String','外涵出口静压/Pa','fontsize',15);
set(HH2,'color','k');

set(H1,'LineStyle','-');
set(H1,'Marker','o');
set(H1,'color','b');
set(H2,'LineStyle','-');
set(H2,'Marker','o');
set(H2,'color','r');

%legend([H1,H2],{'y1 = 200*exp(-0.05*x).*sin(x)';'y2 = 0.8*exp(-0.5*x).*sin(10*x)'});
xlabel('内涵压降','fontsize',15);
title('BPR=13.5 ');