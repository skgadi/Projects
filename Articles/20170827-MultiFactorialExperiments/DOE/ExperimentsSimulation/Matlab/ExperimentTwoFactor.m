function [ Y ] = ExperimentTwoFactor( x1, x2 )
%EXPERIMENTTWOFACTOR Summary of this function goes here
%   Detailed explanation goes here
x = [x1;x2];

Y = b0 + b1*(x1-9.56) + b2*(x2-73.21) + b3*(x1-9.56).^2 + b4*(x2-73.21).^2+(rand(size(x1,1), size(x1,2))-0.5)*50;

end

