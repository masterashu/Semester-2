function x = x(t)
  x = zeros(size(t));
  x(t > -1 & t <= 0) = - 1 - t(t > -1 & t <= 0);
  x(t > 0 & t <= 1) = t(t > 0 & t <= 1);
  x(t > 1 & t <= 2) = 1;
  x(t > 2 & t <= 3) = 3 - t(t > 2 & t <= 3);
end
