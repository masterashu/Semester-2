
%
close all; clear;

t = -2:0.01:2;
x = sinc(t).^2;
L = length(t);
X = fft(x);
X1 = X/L;


X1 = X1(1:L/2 + 1);
X1(1:end) = 2*X1(1:end);
L = length(X1);
f1 = linspace(0,L,round(L))/L/(t(2) - t(1));


mx = max(abs(X1))/sqrt(2);

mx1 = max(find(abs(X1(2:L)) > mx))+1;
X11 = zeros(size(X1));
X11(1:mx1) = X1(1:mx1);

% FINDING NYQUIST RATE

Fs = 2*(f1(mx1)-f1(1));
sprintf('Nyquist Rate is: %.2f Heartz', Fs)

figure;
plot(f1,X11);
hold on;
plot(f1,mean(X1)/2, 'g');
stem(f1(mx1), max(X11),'r');
WM = sprintf('  Wm = %.2fHz', Fs);
text(f1(mx1), max(X11),WM);
title('Fourier Transform for Continous Signal'); xlabel('W'); ylabel('X(W)');
grid;
legend('X(W)','Avg. X(W)');

% SAMPLING SIGNAL
s_rate = round(((1/Fs)/(t(2)-t(1))))*(t(2)-t(1));
sample_time = t(1) : s_rate : t(end);
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
stem(sample_time, x2);
title('Continous Signal v/s Sampled Signal'); xlabel('time'); ylabel('x(t)');
grid;
legend('Continous','Sampled');

% FOURIER TRANSFORM OF SAMPLED SIGNAL
X12 = fft(sample_signal);
X12 = X12/L;
L = length(X12);
X12(1:end) = 2*X12(1:end);
f2 = linspace(0,L,round(L))/L/(t(2) - t(1));
figure;
plot(f2,X12);
title('Fourier Transform of Sampled Signal'); xlabel('W'); ylabel('X(W)');
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
plot(t,x, 'b');
hold on;
plot(t, xr2, 'k');
title('Original Signal v/s Signal Recreated from Sample'); xlabel('time'); ylabel('x(t)');
grid;
legend('Original','Reconstructed');