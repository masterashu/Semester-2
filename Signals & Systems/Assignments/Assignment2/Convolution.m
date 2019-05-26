function Y = Convolution(x,h)
  N = length(x);
  M = length(h);
  L = N + M - 1;
  Y = zeros(L);
  Xe = zeros(L);
  He = zeros(L);
  Xe(1:N) = x;
  He(1:M) = h;
  
  for n = 1:L
    Y(n) = 0;
    for k = 1:n
      Y(n) += He(k)*Xe(n-k+1); 
    end
  end
end
