clear
syms x
Sigmoid = 1/(1+exp(-x));
y = diff(Sigmoid);
% H = diff(diff(y));
% 
% [n d] = numden(H)

h = hessian(y,[x]);

syms x1 x2 x3
S1 = exp(-x1^2);
S2 = exp(-x2^2);
S3 = exp(-x3^2);
Y = S1 + S2 + S3;
H = hessian(Y,[x1; x2; x3]);
[n d] = numden(H(1,1));