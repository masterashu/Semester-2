% Section 1

t = -1.5:0.01:1.5;
x = zeros(size(t));
x(t<=1 & t >= -1) = cos(pi*t(t<=1 & t >= -1));
figure;
for ix = 1:50;
  clf;
  K = -ix:ix;
  AK = FourierCoeff(x, t, 3, K);
  y = Converge(AK, K, 3, t);
  plot(t,x);
  hold on;
  plot(t,y,'r');
  title(['K = -',int2str(ix),' to ',int2str(ix)]);
  pause(0.25);
end
close;