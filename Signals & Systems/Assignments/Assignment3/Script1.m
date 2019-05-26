% Section 1
% Q.1
% Fourier Coefficients of x(t) = t^2

t = -1.5:0.01:1.5;
x = zeros(size(t));
N = 100;
x(t<=1 & t >= -1) = t(t<=1 & t >= -1).^2;
t2 = -3:0.01:5;
figure;
ConvergeError = zeros(1,N+1);
for ix = 0:1:N;
  clf;
  K = -ix:ix;
  AK = FourierCoeff(x, t, 3, K);
  plot(t,x);
  hold on;
  y = Converge(AK, K, 3, t2);
  ConvergeError(ix+1) = sum(abs(y-x));
  % plot(t2,y,'r');
  % title('Reconstructed Signal');  title(['K = -',int2str(ix),' to ',int2str(ix)]);
  % xlabel('time');
  % ylabel('x(t)');
  % grid on;  axis equal;
  
  pause(0.2 + (5-4)/(ix + 1));
end
figure;
stem(0:N,ConvergeError);
figure;
stem(K, real(AK),'r');
hold on;
stem(K, imag(AK),'b');
title('Fourier Coefficients');
xlabel('K');
ylabel('Ak');
grid on;
legend('Real part of Ak', 'Imaginary part of Ak');

