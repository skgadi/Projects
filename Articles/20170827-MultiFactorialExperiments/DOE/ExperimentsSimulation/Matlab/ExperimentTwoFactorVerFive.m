function [ Y ] = ExperimentTwoFactorVerFive (PH, TEMP, P, Q, x_M, x_I, K_D, F_1, F_2, K_R);
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
Y = zeros(size(PH));

for i = 1:size(PH, 1)
    for j = 1:size(TEMP, 2)
        z_1 = K_D * (PH(i,j)-x_M(1)) ./ x_I(1) ;
        z_2 = K_D * (TEMP(i, j) -x_M(2)) ./ x_I(2) ;
        z = [z_1; z_2];
        r = P*z;
        s = Q*z;
        Y(i,j) = F_1 + F_2/2*(K_R*2 * (rand() - 0.5) ...
            + (exp(-r(1)^2)*exp(-r(2)^2)) ...
            * (exp(-s(1)^2)+exp(-s(2)^2)));
    end
end
end

