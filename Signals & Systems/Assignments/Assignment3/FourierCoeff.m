function AK = FourierCoeff(signal, time, TimePeriod, K)
  AK = zeros(size(K));
  W = (2 * pi) / TimePeriod;
  for ik = 1:length(K)
    y = signal .* exp(-i*K(ik)*W*time);
    AK(ik) = Integrate(y, time)/TimePeriod;
  end
end
