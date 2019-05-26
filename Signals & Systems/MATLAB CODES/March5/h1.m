function output = h1(t)
  output = zeros(size(t));
  output(t >= 0) = exp(-3.* t(t>=0));
end
