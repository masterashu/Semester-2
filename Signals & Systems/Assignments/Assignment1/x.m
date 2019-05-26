function x = x(t)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
x = zeros(size(t));
x(t>=0 & t<1) = t(t>=0 & t<1);
x(t>=1 & t<3) = 2 - t(t>=1 & t<3);
x(t>=3 & t<5) = t(t>=3 & t<5) - 4;
x(t >=5) = 1;
end
