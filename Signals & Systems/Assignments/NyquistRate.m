function NyRate = NyquistRate(signal, time)
  L = length(time);
  X = fft(signal);
  X = abs(X/L);
  X = X(1:L/2 + 1);
  X(2:end-1) = 2*X(2:end-1);
  f = (0:L/2)/L/(time(2) - time(1));
  
  figure;
  plot(f,X);
  X_mean = mean(X);
  for i_x = length(X):-1:1
    if X(i_x) > 2*X_mean
      break;
    endif
  end
  NyRate = f(X == i_x);
  
end
