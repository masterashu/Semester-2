function signal = Converge(AK, K, TimePeriod, time)
  W = (2*pi) / TimePeriod;
  signal = zeros(size(time));
  for ik = 1:length(K)
    y = AK(ik) * (exp(1i*K(ik)*W*time));
    signal = signal + y;
  end
end
