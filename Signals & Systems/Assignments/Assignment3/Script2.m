t = -1.5:0.01:1.5;
x = zeros(size(t));
N = 100;
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
AK2 = 2/3*(2*sin(W*K)./(W*K) - cos(W*K)./(W.^2*K.^2) + 1./(W.^2*K.^2));
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