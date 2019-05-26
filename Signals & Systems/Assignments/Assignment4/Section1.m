close all; clear;

t = 0:0.01:2;
x = zeros(size(t));
x(t >= 0 & t <= 2) = (t(t >= 0 & t <= 2) -1).^2;
L = length(t);
f = -4:0.01:4;
X = FT(x, t, 2*pi*f);

mx = abs(max(X)/sqrt(2));
% mx1 = min(find(X(f > 0) < mx)) + length(find(X(f <= 0)));
mx1 = max(find(X(f > 0) >= mx)) + length(find(X(f <= 0))) + 1;
mx2 = min(find(X(f <= 0) >= mx)) - 1;

% Plotting the FFT
figure;
plot(f,X);
hold on;
stem([f(mx1), f(mx2)], [X(mx1), X(mx2)], 'r', 'filled');
title('Fourier Transform for Continous Signal'); xlabel('f (Hz)'); ylabel('X(W)');
grid;
mTxt = sprintf('  Wm = %.2f Hz',f(mx1));
text(f(mx1), X(mx1), mTxt);
mTxt = sprintf('  Wm = %.2f Hz',f(mx2));
text(f(mx2), X(mx2), mTxt, 'HorizontalAlignment', 'right');
Nr = 2*(f(mx1));
sprintf('Nyquist Rate is %.2f Hz.', Nr)

% SAMPLING SIGNAL
s_rate = round(((1/Nr)/(t(2)-t(1))))*(t(2)-t(1));
sample_time = [fliplr([-s_rate + 1:-s_rate:t(1)]), 1 : s_rate : t(end)];
sample_signal = zeros(size(t));
it = 1;
for tt = sample_time
    sample_signal(abs(t - tt) < (t(2)-t(1))/2) = x(abs(t - tt) < (t(2)-t(1))/2);
    x2(it) = x(abs(t - tt) < (t(2)-t(1))/2);
    it = it + 1;
end

% PLOTTING THE SAMPLED SIGNAL
figure;
plot(t,x);
hold on;
stem(sample_time, x2, 'ro', 'LineWidth', 3);
title('Continous Signal v/s Sampled Signal'); xlabel('time'); ylabel('x(t)');
grid; axis equal;
legend('Continous','Sampled');

% FOURIER TRANSFORM OF SAMPLED SIGNAL
X = FT(sample_signal, t, 2*pi*f);
X = X/L;
L = length(X);
X(1:end) = 2*X(1:end);
f2 = linspace(0,L,round(L))/L/(t(2) - t(1));
figure;
plot(f2,X);
title('Fourier Transform of Sampled Signal'); xlabel('f (Hz)'); ylabel('X(W)');
grid;

% Recovering Signal
Ts = sample_time(2)- sample_time(1);
Tr = t(2) - t(1);

xr = zeros(size(t));
xr2 = zeros(size(t));

for it = 1:length(t)
    xr2(it) = xr2(it) + x2*sinc((t(it) - sample_time)/Ts)';
    for ip = 1:length(sample_time)
        xr(it) = xr(it) + x2(ip) * sinc(((it-1)*Tr - (ip-1)*Ts)/Ts);
    end
end

% PLOTTING THE RECOVERED SIGNAL
figure;
plot(t,x, 'r');
hold on;
plot(t, xr2, 'k');
title('Original Signal v/s Signal Recreated from Sample'); xlabel('time'); ylabel('x(t)');
grid; axis equal;
legend('Original','Reconstructed');