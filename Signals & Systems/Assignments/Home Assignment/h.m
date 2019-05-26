function h = h(t)
  h = zeros(size(t));
  h(t <= -1 & t > -2) = 1;
  h(t <= 0 & t > -1) = -1;
  h(t <= 1 & t > 0) = -1 + t(t <= 1 & t > 0);
  h(t <= 2 & t > 1) = 1;
end
