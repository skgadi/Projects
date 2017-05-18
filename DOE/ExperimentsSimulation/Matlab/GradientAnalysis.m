clear
syms x1 x2
% Fun1 = -(x1+0.1*sin(x1+x2)).^2;
% Fun2 = -(x2+0.1*sin(x1+x2)).^2;

Fun1 = x1^2;
Fun2 = x2^2;
y =     exp(Fun1)+exp(Fun2);
grad = gradient(y);

[n1, d1] = numden(grad(1));
[n2, d2] = numden(grad(2));

latex(n1)
latex(d1)
latex(n2)
latex(d2)