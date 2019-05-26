
%
close all; clear;

t = 0:0.01:2;
x = (t-1).^2;
L = length(t);
f = -10:0.001:10;
X = FT(x, t, 2*pi*f);

mx = abs(max(X)/sqrt(2));
mxi = min(find(X(f > 0) < mx)) + length(find(X(f <= 0)))

% FINDING NYQUIST RATE
figure;
plot(f,X);
hold on;
plot(f, mx, 'g');
stem(f(mxi), mx,'b');
title('Fourier Transform for Continous Signal'); xlabel('W'); ylabel('X(W)');
grid;
legend('X(W)','-3db Power', 'Nyquist Rate');

Fs = 2*(f(mxi));
sprintf('Nyquist Rate is: %.2f Heartz', Fs)

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
grid; axis equal;
legend('Continous','Sampled');

% FOURIER TRANSFORM OF SAMPLED SIGNAL
X = FT(sample_signal);
X = X/L;
figure;
plot(f,X);
title('Fourier Transform of Sampled Signal'); xlabel('W'); ylabel('X(W)');
grid;

% Recovering Signal
Ts = sample_time(2)- sample_time(1);
Tr = t(2) - t(1);

xr = zeros(size(t));
xr2 = zeros(size(t));

for it = 1:length(t)
    xr2(it) = xr2(it) + X*sinc((t(it) - sample_time)/Ts)';
    for ip = 1:length(sample_time)
        xr(it) = xr(it) + X(ip) * sinc(((it-1)*Tr - (ip-1)*Ts)/Ts);
    end
end

% PLOTTING THE RECOVERED SIGNAL
figure;
plot(t,x, 'b');
hold on;
plot(t, xr2, 'k');
title('Original Signal v/s Signal Recreated from Sample'); xlabel('time'); ylabel('x(t)');
grid; axis equal;
legend('Original','Reconstructed');


%X = X/L;
%X = X(1:L/2 + 1);
%X(1:end) = 2*X(1:end);
%f2 = linspace(0,L/2,round(L/2))/L/(t(2) - t(1));

%figure;
%plot(f2,X2);
%hold on;
%plot(f2,mean(X2), 'g');

