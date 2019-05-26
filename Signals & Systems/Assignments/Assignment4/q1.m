close all; clear;

t = 0:0.01:2;
x = zeros(size(t));
x(t >= 0 & t <= 2) = (t(t >= 0 & t <= 2) -1).^2;
L = length(t);
f = -4:0.01:4;
X = FourierTransform(x, t, 2*pi*f);

mx = abs(max(X)/sqrt(2));
mx1 = max(find(X(f > 0) >= mx)) + length(find(X(f <= 0)));
mx2 = min(find(X(f <= 0) >= mx));

figure;
plot(f,X);
title('FFT of x(t)'); ylabel('X(W)'); xlabel('f (Hz)');
hold on;
stem([f(mx1), f(mx2)], [X(mx1), X(mx2)], 'r', 'filled');
title('Fourier Transform for Continous Signal'); xlabel('W'); ylabel('X(W)');

s_rate = round(((1/Nr)/(t(2)-t(1))))*(t(2)-t(1));
sample_time = [fliplr([-s_rate + 1:-s_rate:t(1)]), 1 : s_rate : t(end)];
sample_signal = zeros(size(t));
it = 1;
for tt = sample_time
    sample_signal(abs(t - tt) < (t(2)-t(1))/2) = x(abs(t - tt) < (t(2)-t(1))/2);
    x2(it) = x(abs(t - tt) < (t(2)-t(1))/2);
    it = it + 1;
end

figure;
plot(t,x);
hold on;
stem(sample_time, x2, 'ro', 'LineWidth', 3);
