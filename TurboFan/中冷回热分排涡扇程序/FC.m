%% 等高等马赫数巡航  假定发动机工作状态是可调的，以保证等高等马赫数巡航




MTOM = 560000;%波音737-800数据，最大起飞重量
Swing = 845.0;%机翼面积
AltCruiseMain = 11582.4;%主巡航任务的高度  与初始巡航高度差3000ft 阶梯巡航是否有必要不一定
MissionSail =15000000;%单位是 m
CruiseRange = MissionSail;%飞机航程 参考波音737
Macr = 0.85;%巡航马赫数为0.85

 alti=AltCruiseMain;%巡航高度
 macr=Macr;%巡航马赫数
 wmi=MTOM*0.95;%飞机巡航开始总重量
 wmi=wmi+2000*4*2-10730;%%%%%%中冷回热器加上发动机增加的重量 飞机当量时发动机增加总重的2倍
dis=MissionSail;% 总航程
tim=0;%总航时
wmf=0;% 燃油消耗总量
enn=4;%发动机数量
Nengine=4;%发动机数量



       
%             public double Ak1;由升力求阻力的系数
%             public double Ak2;
        pPolar.Ak1=0.025;
         pPolar.Ak2=0.05;
         k=17.5;
pPropulsion.NacellDrag=0.05;%?????????????

TimeLast = 0.0;
 DisLast = 0.0;
 FuelLast = 0.0;

            q = 0.0;%%升力系数
            cd = 0.0;%阻力系数 
            dr = 0.0; %所需推力
            ds = 0.0;%小航段长度
             Ma = macr;dt = 0.0;
             wcr = wmi;tcr = 0.0;
             vcr=0.0;
%             pAtmosph.AtmosphPara(alti);

[Gasdens,Vsonic]=EnvirGas(alti);
pAtmosph.Vsonic=Vsonic;
 pAtmosph.EnvirGasDens=Gasdens;
vcr = macr * pAtmosph.Vsonic;%真实空速

            
            ds = dis / 100;

%             q = 0.5 * pAtmosph.EnvirGasDens * vcr * vcr;
%             cl = wcr * 9.81 / (q * Swing);%由飞机重量求升力系数
%             cd = pPolar.Ak1 + pPolar.Ak2 * cl * cl;
%             dr = q * Swing * cd*(1 + pPropulsion.NacellDrag);
% 
% %             //double Nmax = 110,Nmin = 50,N = 100.0;
%             pEngine.Performance(macr, dr/2); %由所需推力和马赫数求油门


            %%
            

            
for i=1:100
            
                q = 0.5*pAtmosph.EnvirGasDens * vcr*vcr;
%                 cl = wcr * 9.81 / (q * Swing);            
%                 cd = pPolar.Ak1 + pPolar.Ak2 * cl * cl;%巡航极曲线要变化   cd = 0.025 + 0.05 * cl * cl
%                 dr = q * Swing * cd * (1 + pPropulsion.NacellDrag);
%                 k=cl/cd;
                  dr=wcr*9.81/k;
                  xuyongtuili=dr / 40,
                EngineFC=SFCperform( dr / 40,Thruststr,SFCstr);
                dt = ds / vcr;
                tcr = tcr + dt;
                wcr = wcr -EngineFC * Nengine * dt;

%                 if (pEngine == pCruise)//等马赫数爬升
%                 {
%                     m = i / 10;
%                     if (m == n + 1)
%                     {
%                         using (StreamWriter sw = new StreamWriter(outputpath + @"飞行性能参数\巡航性能.txt", true, Encoding.Unicode))
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
CruiseFuel=wmi-wcr,%燃油消耗总量

                           
        
        
        
   
        
 
        
        
   
            
            
            
        
% fHangcheng=100000;
% iHangduan=10;
% fDuanFC=0;%每个航段燃油消耗量
% fZongFC=0;%总燃油消耗量
% fDetalHangcheng=0;
% fAircraftM=rand(1,iHangduan);%飞机质量
% for i=1:10
% fZhongjian=exp(SFCA(i)*g*fDetalHangcheng/(3600*Sudu*K))%K是升阻比，
% fAircraftM(i+1)=fAircraftM(i)/fZhongjian;
% fDuanFC(i)=fAircraftM(i)-fAircraftM(i+1);%每个航段的燃油消耗量
% 
% fZongFC=fZongFC+fDuanFC(i);
% end
