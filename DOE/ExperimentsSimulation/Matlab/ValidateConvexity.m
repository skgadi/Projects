syms x
Sigmoid = 1/(1+exp(-x));
y = diff(Sigmoid);
% H = diff(diff(y));
% 
% [n d] = numden(H)

h = hessian(y,[x])

syms x1 x2 x3
S1 = 1/(1+exp(-x1-x2^2-x2));
S2 = 1/(1+exp(-x2));
S3 = 1/(1+exp(-x3));
Y = diff(S1)+diff(S2)+diff(S3)
H = hessian(Y,[x1; x2; x3])
