% Section 1
% Q.1
% Fourier Coefficients of x(t) = t^2

t = -1:0.01:2;
x = zeros(size(t));
N = 25;  W = 2*pi/3;
x = t.^2 - 7*t.^5 + 4 -t.^3;
t2 = -3:0.01:5;
ConvergeError = zeros(1,N+1);
  figure;
for ix = 0:1:N;
  clf;
  K = -ix:ix;
  AK = FourierCoeff(x, t, 3, K);
  plot(t,x,'k','LineWidth',2)
  hold on;
  y = Converge(AK, K, 3, t2);
  ConvergeError(ix+1) = 1/3*sum((Converge(AK,K,3,t)-x).^2);
  plot(t2,y,'r');
  title('Reconstructed Signal');  title(['K = -',int2str(ix),' to ',int2str(ix)]);
  xlabel('time');
  ylabel('x(t)');
  grid on;  axis equal;
  pause(0.1);
end
figure;
stem(0:N,ConvergeError);
title('Convergence');
ylabel('Error');
xlabel('K');
figure;
stem(K, real(AK),'r');
hold on;
stem(K, imag(AK),'b');
title('Fourier Coefficients');
xlabel('K');
ylabel('Ak');
grid on;
legend('Real part of Ak', 'Imaginary part of Ak');
AK2 = 1/3*(2*sin(W*K)./(W*K)) + 1/3*(4*cos(W*K)./(W.^2*K.^2)) - 4/3*(sin(W*K)./(W.^3*K.^3));
figure;
stem(K,real(AK2))
hold on;
stem(K,imag(AK2))
hold on;
stem(0, 2/9);
title('Theoretical Fourier Coefficients');
legend('Real AK Theoretical', 'Imaginary AK Theoritical', 'A0 Theoretical');
ylabel('Theoretical AK')
xlabel('K')

% Q.2
% Fourier Coefficients of x(t) = 1- |t|/3

t = -1.5:0.01:1.5;
x = zeros(size(t));
N = 100; W = 2*pi/3;
x(t<=1 & t >= -1) = 1- abs(t(t<=1 & t >= -1)/3);
t2 = -3:0.01:5;
ConvergeError = zeros(1,N+1);
figure;
for ix = 0:1:N;
  K = -ix:ix;
  AK = FourierCoeff(x, t, 3, K);
  y = Converge(AK, K, 3, t2);
  ConvergeError(ix+1) = sum((Converge(AK,K,3,t)-x).^2);
end
plot(t,x);
hold on;
plot(t2,y,'r');
title('Reconstructed Signal');  title(['K = -',int2str(ix),' to ',int2str(ix)]);
xlabel('time');
ylabel('x(t)');
grid on;  axis equal;
figure;
stem(0:N,ConvergeError);
title('Convergence');
ylabel('Error');
xlabel('K');
figure;
stem(K, real(AK),'r');
hold on;
stem(K, imag(AK),'b');
title('Fourier Coefficients');
l('K');
ylabel('Ak');
grid on;
legend('Real part of Ak', 'Imaginary part of Ak');
AK2 = 2/9*(2*sin(W*K)./(W*K) - cos(W*K)./(W.^2*K.^2) + 1./(W.^2*K.^2));
figure;
stem(K,real(AK2))
hold on;
stem(K,imag(AK2))
hold on;
stem(0, 5/9);
title('Theoretical Fourier Coefficients');
legend('Real AK Theoretical', 'Imaginary AK Theoritical', 'A0 Theoretical');
ylabel('Theoretical AK')
xlabel('K')

% Q.3 Fourier Coefficients of x(t) = cos(pi*t)

t = -1.5:0.01:1.5;
x = zeros(size(t));
N = 100;
x(t<=1 & t >= -1) = cos(pi .* t(t<=1 & t >= -1));
t2 = -3:0.01:5;
ConvergeError = zeros(1,N+1);
  figure;
for ix = 0:1:N;
  clf;
  K = -ix:ix;
  AK = FourierCoeff(x, t, 3, K);
  plot(t,x);
  hold on;
  y = Converge(AK, K, 3, t2);
  ConvergeError(ix+1) = sum((Converge(AK,K,3,t)-x).^2);
  plot(t2,y,'r');
  title('Reconstructed Signal');  title(['K = -',int2str(ix),' to ',int2str(ix)]);
  xlabel('time');
  ylabel('x(t)');
  grid on;  axis equal;
  pause(0.1);
end
figure;
stem(0:N,ConvergeError);
title('Convergence');
ylabel('Error');
xlabel('K');
figure;
stem(K, real(AK),'r');
hold on;
stem(K, imag(AK),'b');
title('Fourier Coefficients');
xlabel('K');
ylabel('Ak');
grid on;
legend('Real part of Ak', 'Imaginary part of Ak');
AK2 = 1/3*(-2*W*K.*sin(W*K)./(W.^2*k.^2 - pi^2));
figure;
stem(K,real(AK2))
hold on;
stem(K,imag(AK2))
hold on;
stem(0, 0);
title('Theoretical Fourier Coefficients');
legend('Real AK Theoretical', 'Imaginary AK Theoritical', 'A0 Theoretical');
ylabel('Theoretical AK');
xlabel('K');