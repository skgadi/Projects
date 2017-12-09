
n=2;
F_1 = 160.49815877303246;
F_2 = 167.90759039534183;
K_R = 0.1;
ph = 1:0.01:13;
temp = 0:0.1:100;

x_M = [7.783725193305662, 23.606467197108323]';
K_D = 5;
x_I = [12, 100]';

P = 0.5*[1, 0; 0, 1];
Q = [2.1284803391965514, 0.6750566227777779; 0.6750566227777779, 1.4520060240801904];

[PH, TEMP]=meshgrid(ph,temp);

Y = ExperimentTwoFactorVerFive (PH, TEMP, P, Q, x_M, x_I, K_D, F_1, F_2, K_R);

set(0,'DefaultTextFontname', 'CMU Serif')
set(0,'DefaultAxesFontName', 'CMU Serif')
surf (PH, TEMP, Y, 'edgecolor', 'none')
xlabel('$x_1$','Interpreter','latex');
ylabel('$x_2$','Interpreter','latex');
zlabel('$y$','Interpreter','latex');




set(gca,'fontsize',15)



