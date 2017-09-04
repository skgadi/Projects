Ms=1.6; %kg, Masa del piso incluyendo al acelerometro
Mf=1.38; %kg, Masa del piso
Ks=500.8824;% N/m, rigidez del edificio
Mc=0.65;  %kg, masa total del AMD

Kg=3.71;
Kt=0.00767;
Km=Kt;
Rm=2.6;
rmp=6.35e-3;

Be=(Kg^2*Kt^2)/(rmp^2*Rm); %Constante beta
K=Kg*Kt/(rmp*Rm); %Constante K

A=[0,0,1,0;0,0,0,1;0,Ks/Ms,-Be*(Ms+Mc)/(Ms*Mc),0;0,-Ks/Ms,Be/Ms,0]
B=[0;0;K*(Ms+Mc)/(Mc*Ms);-K/Ms]
C=[1,0,0,0;0,-Ks/Ms,Be/Ms,0]
D=[0;-K/Ms]

J = [-2+j*2*sqrt(3) -2-j*2*sqrt(3) -10 -10]; %Polos deseados en lazo cerrado
Kc=acker(A,B,J) %Ganancia de retroalimentación de estado
 
L=[-30,-31,-32,-33]; %Polos deseados del observador de estado
Ko=place(A',C',L)'   %Ganacia del observador


