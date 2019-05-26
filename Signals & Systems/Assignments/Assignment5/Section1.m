% CA-05
% CIRCULAR CONVOLUTION
close all; clear;

n = 0:7;
signal_1 = (1/4).^n;
signal_2 = cos((3*pi/8).*n);

y1 = CircularConv(signal_1, signal_2);

figure;
subplot(311);
stem(n,signal_1,'x','LineWidth', 2);
title('Signal x1[n] = 1/(4^n)'); ylabel('x1[n]'); xlabel('n');
grid;
subplot(312);
stem(n, signal_2,'x','LineWidth', 2);
title('Signal x2[n] = cos(3*pi/8*n'); ylabel('x2[n]'); xlabel('n');
grid;
subplot(313);
stem(n, y1,'x','LineWidth', 2);
title('Signal Y[n] = Circular Convolution X1[n] * X2[n]'); ylabel('y[n]'); xlabel('n');
grid;

% CIRCULAR CONVOLUTION USING DFT

n = 0:7;
signal_1 = (1/4).^n;
signal_2 = cos((3*pi/8).*n);

[y1, X1, X2, K] = CircularConvDFT(signal_1, signal_2, n);

figure;
subplot(311);
stem(n,signal_1,'x','LineWidth', 2);
title('Signal x1[n] = (1/4)^n'); ylabel('x1[n]'); xlabel('n');
grid;
subplot(312);
stem(n, signal_2,'x','LineWidth', 2);
title('Signal x2[n] = cos(3*pi/8*n)'); ylabel('x2[n]'); xlabel('n');
grid;
subplot(313);
stem(n, y1,'x','LineWidth', 2);
title('Signal Y[n] = Inverse DFT of X3[k] = X1[k] x X2[k]'); ylabel('Y[n]'); xlabel('n');
grid;
figure;
subplot(311);
stem(K, real(X1),'x','LineWidth', 2);
hold on;
stem(K, imag(X1),'o','LineWidth', 2);
title('Signal X1[k] => DFT of Signal x1[n]'); ylabel('X1[k]'); xlabel('K');
grid; legend('Real', 'Imag.');
subplot(312);
stem(K, real(X2),'x','LineWidth', 2);
hold on;
stem(K, imag(X2),'o','LineWidth', 2);
title('Signal X2[k] => DFT of Signal x2[n]'); ylabel('X2[k]'); xlabel('K');
grid; legend('Real', 'Imag.');
subplot(313);
stem(K, real(X1.*X2),'x','LineWidth', 2);
hold on;
stem(K, imag(X1.*X2),'o','LineWidth', 2);
title('Signal X3[k] = X1[k] x X2[k]'); ylabel('X2[k]'); xlabel('K');
grid; legend('Real', 'Imag.');
