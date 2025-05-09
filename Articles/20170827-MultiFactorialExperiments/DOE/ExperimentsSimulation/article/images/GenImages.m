set(0,'DefaultTextFontname', 'CMU Serif')
set(0,'DefaultAxesFontName', 'CMU Serif')
x = -10 : 0.01 : 10;
x1 = x;
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


% % % Future version
[X, X1] = meshgrid(x, x1);
SigM = 1./(1 + exp(-X));
SigM1 = 1./(1 + exp(-X1));
Y =  exp(X+2*sign(X1).*X1.^2)./(exp(X+2*sign(X1).*X1.^2)+1).^2 ...
    + exp(X1+2*sign(X).*X.^2)./(exp(X1+2*sign(X).*X.^2)+1).^2;
surf (X, X1, Y, 'edgecolor', 'none')
xlabel('$x_1$','Interpreter','latex');
ylabel('$x_2$','Interpreter','latex');
zlabel('$y$','Interpreter','latex');

% % % Normal distribution
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


set(gca,'fontsize',15)

