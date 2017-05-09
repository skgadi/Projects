clear
syms x
Sigmoid = 1/(1+exp(-x));
y = diff(Sigmoid);
% H = diff(diff(y));
% 
% [n d] = numden(H)

h = hessian(y,[x]);

syms x1 x2 x3
S1 = 1/(1+exp(-x1+0.5*x2));
S2 = 1/(1+exp(-x2));
S3 = 1/(1+exp(-x3));
Y = diff(S1)+diff(S2)+diff(S3);
H = hessian(Y,[x1; x2; x3]);
NewEle = expand(simplify(H(2,2)*H(1,1) - H(2,1)*H(1,2)));
[n d] = numden(NewEle);
expand(simplify(n))
expand(simplify(d));
double(subs(NewEle,{x1, x2}, {0.00,0.00}))
% eig(H)