%% �ȸߵ������Ѳ��  �ٶ�����������״̬�ǿɵ��ģ��Ա�֤�ȸߵ������Ѳ��




MTOM = 560000;%����737-800���ݣ�����������
Swing = 845.0;%�������
AltCruiseMain = 11582.4;%��Ѳ������ĸ߶�  ���ʼѲ���߶Ȳ�3000ft ����Ѳ���Ƿ��б�Ҫ��һ��
MissionSail =15000000;%��λ�� m
CruiseRange = MissionSail;%�ɻ����� �ο�����737
Macr = 0.85;%Ѳ�������Ϊ0.85

 alti=AltCruiseMain;%Ѳ���߶�
 macr=Macr;%Ѳ�������
 wmi=MTOM*0.95;%�ɻ�Ѳ����ʼ������
 wmi=wmi+2000*4*2-10730;%%%%%%������������Ϸ��������ӵ����� �ɻ�����ʱ�������������ص�2��
dis=MissionSail;% �ܺ���
tim=0;%�ܺ�ʱ
wmf=0;% ȼ����������
enn=4;%����������
Nengine=4;%����������



       
%             public double Ak1;��������������ϵ��
%             public double Ak2;
        pPolar.Ak1=0.025;
         pPolar.Ak2=0.05;
         k=17.5;
pPropulsion.NacellDrag=0.05;%?????????????

TimeLast = 0.0;
 DisLast = 0.0;
 FuelLast = 0.0;

            q = 0.0;%%����ϵ��
            cd = 0.0;%����ϵ�� 
            dr = 0.0; %��������
            ds = 0.0;%С���γ���
             Ma = macr;dt = 0.0;
             wcr = wmi;tcr = 0.0;
             vcr=0.0;
%             pAtmosph.AtmosphPara(alti);

[Gasdens,Vsonic]=EnvirGas(alti);
pAtmosph.Vsonic=Vsonic;
 pAtmosph.EnvirGasDens=Gasdens;
vcr = macr * pAtmosph.Vsonic;%��ʵ����

            
            ds = dis / 100;

%             q = 0.5 * pAtmosph.EnvirGasDens * vcr * vcr;
%             cl = wcr * 9.81 / (q * Swing);%�ɷɻ�����������ϵ��
%             cd = pPolar.Ak1 + pPolar.Ak2 * cl * cl;
%             dr = q * Swing * cd*(1 + pPropulsion.NacellDrag);
% 
% %             //double Nmax = 110,Nmin = 50,N = 100.0;
%             pEngine.Performance(macr, dr/2); %�����������������������


            %%
            

            
for i=1:100
            
                q = 0.5*pAtmosph.EnvirGasDens * vcr*vcr;
%                 cl = wcr * 9.81 / (q * Swing);            
%                 cd = pPolar.Ak1 + pPolar.Ak2 * cl * cl;%Ѳ��������Ҫ�仯   cd = 0.025 + 0.05 * cl * cl
%                 dr = q * Swing * cd * (1 + pPropulsion.NacellDrag);
%                 k=cl/cd;
                  dr=wcr*9.81/k;
                  xuyongtuili=dr / 40,
                EngineFC=SFCperform( dr / 40,Thruststr,SFCstr);
                dt = ds / vcr;
                tcr = tcr + dt;
                wcr = wcr -EngineFC * Nengine * dt;

%                 if (pEngine == pCruise)//�����������
%                 {
%                     m = i / 10;
%                     if (m == n + 1)
%                     {
%                         using (StreamWriter sw = new StreamWriter(outputpath + @"�������ܲ���\Ѳ������.txt", true, Encoding.Unicode))
%                         {
%                             sw.WriteLine("{0,-8:D}{1,8:F2}{2,14:F1}{3,12:F1}{4,11:F3}{5,12:F1}{6,14:F1}",
%                                     m, tcr, ds*i,wcr, pEngine.FuelRate * Nengine, pEngine.Fn * Nengine, dr);
%                         }
%                     }
%                     n = m;
%                 }
%                     end
%                 end
%%

%                 CruiseTime.Add(tcr + TimeLast);
%                 CruiseDis.Add(ds*i + DisLast);
%                 CruiseVel.Add(vcr);
%                 CruiseAlt.Add(alti);
%                 CruiseFuel.Add(wmi - wcr + FuelLast);
%                 CruiseWgt.Add(wcr);
%                 CruiseAngl.Add(0.0);
%                 CruiseThrust.Add(dr);
%                 CruiseDr.Add(dr);
%                 CruiseMechN.Add(pEngine.GVCruiseThrust.pPtData.X);
            
        end
            tim = tcr;
            wmf = wcr;
CruiseFuel=wmi-wcr,%ȼ����������

                           
        
        
        
   
        
 
        
        
   
            
            
            
        
% fHangcheng=100000;
% iHangduan=10;
% fDuanFC=0;%ÿ������ȼ��������
% fZongFC=0;%��ȼ��������
% fDetalHangcheng=0;
% fAircraftM=rand(1,iHangduan);%�ɻ�����
% for i=1:10
% fZhongjian=exp(SFCA(i)*g*fDetalHangcheng/(3600*Sudu*K))%K������ȣ�
% fAircraftM(i+1)=fAircraftM(i)/fZhongjian;
% fDuanFC(i)=fAircraftM(i)-fAircraftM(i+1);%ÿ�����ε�ȼ��������
% 
% fZongFC=fZongFC+fDuanFC(i);
% end
