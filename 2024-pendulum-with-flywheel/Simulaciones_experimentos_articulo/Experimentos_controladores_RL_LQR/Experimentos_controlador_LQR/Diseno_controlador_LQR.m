%Definición de parámetros del sistema péndulo-rueda
L1 = 0.133;  %m
L2 = 0.221;   %m
m1 = 0.567; %kg
m2 = 0.341;  %kg
I1 = 0.0045; %kg*m2
I2 = 0.0024; %kg*m2 
g=9.81;    %m*s^2  
Ts=0.01; %Período de muestreo

%parámetros del motor Pololu, relación 19:1
a=2.8;   
b=16.5;   
c=12;

%Parámetros beta definicos en el artículo
b1 = m1*(L1^2)+m2*(L2^2)+I1+I2;
b2 = (m1*L1+m2*L2)*g;
b3=I2*c+1;
b10=b1*b3-c*(I2^2);
b4=(b2*b3)/b10;
b5=[I2*a]/b10;
b6=[-b*I2]/b10;
b7=-[I2*c*b2]/b10;
b8=-a*b1/b10;
b9=b*b1/b10;

%Definición de las matrices del sistema____________________________________
A = [0, 1, 0, 0;b4, 0, 0, b5;0, 0, 0, 1;b7, 0, 0, b8]
B = [0;b6;0;b9]
C = [1,0,0,0;0,0,1,0]
D = [0;0];
fprintf('Los polos del sistema en lazo abierto son:')
eig(A)

%Diseño del controlador LQR
q11=12000;
q22=8.21;
q33=1.31;
q44=0.00032;
r=0.082;
Q = [q11 0 0 0;0 q22 0 0;0 0 q33 0;0 0 0 q44];
fprintf('La ganancia K_LQR es:')
K_LQR = lqr(A,B,Q,r)
fprintf('Los polos en lazo cerrado son:')
eig(A-B*K_LQR)

%Diseño del observador de estado
G=[-2,5,10,-11;8,1,-11,5]; %Matriz G arbitraria
Lambda=[50,0,0,0;0,51,0,0;0,0,52,0;0,0,0,53]; %Matriz con el negativo 
% de los valores propios deseados 
X = sylvester(A',Lambda,C'*G); %ecuación de Silvester
fprintf('La ganancia Ke es:')
Ke=[G*inv(X)]' %Ganacia del observador por la ecuación de Silvester



