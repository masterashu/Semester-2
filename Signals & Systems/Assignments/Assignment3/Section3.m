% Section 3
% Q.1 Fourier Transform x(t) = t^3, |t| < 1
t = -1:0.01:1;
x = t.^3;
figure; subplot(311);
plot(t,x);
title('Signal x(t) = t^3 , |t| < 1');
xlabel('time'); ylabel('x(t)'); grid;

W = -20*pi:pi/50:20*pi;
X = FourierTransform(x,t,W);
subplot(312);
plot(W, real(X), 'b');
hold on;
plot(W, imag(X), 'g');
title('Fourier Transform of x(t)');
xlabel('W'); ylabel('X(W)'); grid; legend('Real','Imaginary');

x_t = InvFourierTransform(X,W,t);
subplot(313);
plot(t,x_t);
title('Inverse Fourier Transform of X(W)');
xlabel('time'); ylabel('x(t)'); grid;


% Q.2 Fourier Transform x(t) = 1 - |t|/2, |t| < 1
t = -1:0.01:1;
x = 1 - abs(t)/2;
figure;  subplot(311);
plot(t,x);
title('Signal x(t) = 1 - |t|/2 , |t| < 1');
xlabel('time'); ylabel('x(t)'); grid;

W = -20*pi:pi/50:20*pi;
X = FourierTransform(x,t,W);
subplot(312);
plot(W, real(X), 'b');
hold on;
plot(W, imag(X), 'g');
title('Fourier Transform of x(t)');
xlabel('W'); ylabel('X(W)'); grid; legend('Real','Imaginary');

x_t = InvFourierTransform(X,W,t);
subplot(313);
plot(t,x_t);
title('Inverse Fourier Transform of X(W)');
xlabel('time'); ylabel('x(t)'); grid;


% Q.3 Fourier Transform x(t) = sinc(t), |t| < 2*pi
t = -2*pi:0.01:2*pi;
x = sinc(t);
figure;  subplot(311);
plot(t,x);
title('Signal x(t) = sinc(t), |t| < 1');
xlabel('time'); ylabel('x(t)'); grid;

W = -20*pi:pi/50:20*pi;
X = FourierTransform(x,t,W);
subplot(312);
plot(W, real(X), 'b');
hold on;
plot(W, imag(X), 'g');
title('Fourier Transform of x(t)');
xlabel('W'); ylabel('X(W)'); grid; legend('Real','Imaginary');

x_t = InvFourierTransform(X,W,t);
subplot(313);
plot(t,x_t);
title('Inverse Fourier Transform of X(W)');
xlabel('time'); ylabel('x(t)'); grid;


