function ak = ak(n)
  ak  = zeros(size(n));
  ak = 1 + 2*cos(pi/5)*cos(2*pi*n/5) + 2*cos(2*pi/5)*cos(4*pi*n/5);
end
