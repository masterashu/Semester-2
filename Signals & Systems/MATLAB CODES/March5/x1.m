function output = x1(t)
  output = zeros(size(t));
  output(t >= 3 & t <= 5) = 1;
end
