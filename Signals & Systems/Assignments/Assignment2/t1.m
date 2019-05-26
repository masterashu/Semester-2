tic
x = [1,3,5,-4,6];
h = [3,6,-1,5];
  N = length(x);
  M = length(h);
  L = N + M - 1;
  Y = zeros(1,L);
  Xe = zeros(1,L);
  He = zeros(1,L);
  Xe(1:N) = x;
  He(1:M) = h;
  
  for n = 1:L
    Y(n) = 0;
    for k = 1:n
      Y(n) += He(k)*Xe(n-k+1); 
    end
  end
    disp(Y);
 tt = toc