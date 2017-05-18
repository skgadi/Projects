clear
set(0,'DefaultTextFontname', 'CMU Serif')
set(0,'DefaultAxesFontName', 'CMU Serif')
x = -10 : 0.01 : 10;
x1 = x;
[X1, X2] = meshgrid(x, x1);
% % % % One variable sigmoid based convex function
% Sigmoid = 1./(1 + exp(-x));
% plot(x, Sigmoid);
% DiffOfSig = Sigmoid .* (1 - Sigmoid);
% plot(x, DiffOfSig);
% xlabel('$x$','Interpreter','latex', 'FontSize', 20);
% ylabel('$y$','Interpreter','latex', 'FontSize', 20);
% set(gca,'fontsize',15)

% DiffOfSig = Sigmoid .* (1 - Sigmoid);
% plot(x, DiffOfSig);
% [X, X1] = meshgrid(x,x1);
% SigM = 1./(1 + exp(-X));
% SigM1 = 1./(1 + exp(-X1));
% Y = SigM .* (1 - SigM) + SigM1 .* (1 - SigM1);
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% xx = x;
% xx1 = x;
% [X, X1] = meshgrid(x,x1);
% [XX, XX1] = meshgrid(xx,xx1);
% SigM = 1./(1 + exp(-(X+X1 )));
% SigM1 = 1./(1 + exp(-(X1-X)));
% Y = SigM .* (1 - SigM) + SigM1 .* (1 - SigM1);
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

 
% xx = x;
% xx1 = x;
% [X, X1] = meshgrid(x,x1);
% [XX, XX1] = meshgrid(xx,xx1);
% SigM = 1./(1 + exp(-(X+X1 )));
% SigM1 = 1./(1 + exp(-(X1-X.*cos(X))));
% Y = exp(-X-X1.*abs(sin(X1)))./((1+exp(-X-X1.*abs(sin(X1)))).^2) ...
%     + exp(-X1+X.*abs(sin(X)))./((1+exp(-X1+X.*abs(sin(X)))).^2);
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% xx = x;
% xx1 = x;
% [X, X1] = meshgrid(x,x1);
% [XX, XX1] = meshgrid(xx,xx1);
% SigM = 1./(1 + exp(-(X+X1 )));
% SigM1 = 1./(1 + exp(-(X1-X.*cos(X))));
% Y = exp(-X+X1.*X1+X.*X + 2)./((1+exp(-X+X1.*X1+X.*X + 2)).^2) ...
%     + exp(-X1+X1.*X1+X.*X + 2)./((1+exp(-X1+X1.*X1+X.*X + 2)).^2);
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');



% % % Multivariate normal distribution
% xx = x;
% xx1 = x;
% [X, X1] = meshgrid(x,x1);
% [XX, XX1] = meshgrid(xx,xx1);
% N=1/sqrt(2^2*pi^2);
% Y = exp(-(X-1).^2-(X1-1).^2);
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');



% % % Quadratic
% xx = x;
% xx1 = x;
% [X, X1] = meshgrid(x,x1);
% [XX, XX1] = meshgrid(xx,xx1);
% N=1/sqrt(2^2*pi^2);
% Y = -(X-1).^2-(X1-1).^2;
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');


% % % Future version 1
% [X, X1] = meshgrid(x, x1);
% SigM = 1./(1 + exp(-X));
% SigM1 = 1./(1 + exp(-X1));
% Y =  exp(X+2*sign(X1).*X1.^2)./(exp(X+2*sign(X1).*X1.^2)+1).^2 ...
%     + exp(X1+2*sign(X).*X.^2)./(exp(X1+2*sign(X).*X.^2)+1).^2;
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% % % Future version 2
% [X, X1] = meshgrid(x, x1);
% SigM = 1./(1 + exp(-X));
% SigM1 = 1./(1 + exp(-X1));
% Y =	exp(X+0.5*X1.^3)./(exp(X+0.5*X1.^3)+1).^2 ...
%   + exp(X1+0.5*X.^3)./(exp(X1+0.5*X.^3)+1).^2;
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% 
% % % % % Future version 3
% x = -5 : 0.01 : 5;
% x1 = x;
% [X1, X2] = meshgrid(x, x1);
% Fun1 = -(X1+0.5*0.9*sin(X1+X2)).^2;
% Fun2 = -(X2+.5*0.9*sin(X1+X2)).^2;
% Y =	exp(Fun1) + exp(Fun2);
% surf (X1, X2, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% % % % Future version 3
% x = -5 : 0.01 : 5;
% x1 = x;
% [X1, X2] = meshgrid(x, x1);
% Y =	X2.*sin(X1)+X1;
% surf (X1, X2, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% % Normal distribution
% x = -5 : 0.01 : 5;
% x1 = x;
% [X, X1] = meshgrid(x, x1);
% SigM = 1./(1 + exp(-X));
% SigM1 = 1./(1 + exp(-X1));
% Y = exp(-(X.^2+X1.^2));
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% % Modified Normal distribution
% x = -5 : 0.01 : 5;
% x1 = x;
% [X, X1] = meshgrid(x, x1);
% Y = exp(-(X.^2)) + exp(-(X1.^2));
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% % % % Quadratic polynomial
% [X, X1] = meshgrid(x, x1);
% Y = -1/1.0*(X.^2+X1.^2);
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex');
% ylabel('$x_2$','Interpreter','latex');
% zlabel('$y$','Interpreter','latex');

% % % % Sigmoid based convex function
% [X, X1] = meshgrid(x, x1);
% SigM = 1./(1 + exp(-X));
% SigM1 = 1./(1 + exp(-X1));
% Y = SigM .* (1 - SigM) + SigM1 .* (1 - SigM1);
% surf (X, X1, Y, 'edgecolor', 'none')
% xlabel('$x_1$','Interpreter','latex', 'FontSize', 20);
% ylabel('$x_2$','Interpreter','latex', 'FontSize', 20);
% zlabel('$y$','Interpreter','latex', 'FontSize', 20);




% % % % Adapted function
x1 = -1 : 0.01 : 1;
x2 = -10 : 0.01 : 10;
Inter1 = (max(x1)-min(x1));
Inter2 = (max(x2)-min(x2));
% % Function value scaling
alpha = 0.2;
F_L = 0;
F_U = 10;
F_I = (F_U-F_L);
F_1 = F_I*alpha*rand();
F_2 = F_I*(1-2\alpha)*rand();
% % Factors scaling
beta = 0.2;
x1_m = min(x1) + Inter1*beta + rand()*(1-2*beta)*Inter1;
x2_m = min(x2) + Inter2*beta + rand()*(1-2*beta)*Inter2;
[X1, X2] = meshgrid(x1, x2);
% Fun1 = - ((X1+0.5*0.9*sin(10*X1./Inter1+10*X2./Inter2)).^2)/(2*(Inter1/10)^2);
% Fun2 = - ((X2+0.5*0.9*sin(10*X1./Inter1+10*X2./Inter2)).^2)/(2*(Inter2/10)^2);
XX1 = (X1 -x1_m)/Inter1*5;
XX2 = (X2 -x2_m)/Inter2*5;
Fun1 = - ((XX1+0.5*0.9*sin(XX1 + XX2)).^2);
Fun2 = - ((XX2+0.5*0.9*sin(XX1 + XX2)).^2)*5;
Y =	F_1 + (F_2)/2 * (exp(Fun1) + exp(Fun2)+0.1*gskrand(size(Fun1)));
surf (X1, X2, Y, 'edgecolor', 'none')
xlabel('$x_1$','Interpreter','latex');
ylabel('$x_2$','Interpreter','latex');
zlabel('$y$','Interpreter','latex');


set(gca,'fontsize',15)



