function FT = FourierTransform(signal, time, W)
  iw = 1;
  FT = zeros(size(W));
  for w = W
    FT(iw) = Integrate(signal.*exp(-1i*w*time), time);
    % FT(iw) = trapz(time, signal.*exp(-1i*w*time));
    iw = iw + 1;
  end
end

