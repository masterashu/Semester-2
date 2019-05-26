
%
close all; clear;

t = -5:0.01:5;
x = (sinc(t)).^2;
L = length(t);

X = fft(x);
X1 = X/L;

f1 = linspace(-L/2,L/2,L)/L/(t(2) - t(1));

figure;
plot(f1,X1);
hold on;
plot(f1,mean(X1), 'g');

mx = mean(X1)/2;
mx1 = max(find(X1(L/2:end) > mx))
mx2 = max(find(X1(1:L/2) > mx))
X11 = zeros(size(X1));
X11(mx1:end) = X1(mx1:end);
X11(1:mx2) = X1(1:mx2);

figure;
plot(f1,X11);
hold on;
plot(f1,mean(X1)/2, 'g');

Fs = 2*(f1(mx2)-f1(1));
s_rate = round(((1/Fs)/(t(2)-t(1))))*(t(2)-t(1));
sample_time = t(1) : s_rate : t(end);
sample_signal = zeros(size(t));
for tt = sample_time
    sample_signal(abs(t - tt) < (t(2)-t(1))/2) = x(abs(t - tt) < (t(2)-t(1))/2);
end

X12 = fft(sample_signal);
X12 = X12/L;

figure;
plot(f1,X12);



%X2 = X/L;
%X2 = X2(1:L/2 + 1);
%X2(1:end) = 2*X2(1:end);
%f2 = linspace(0,L/2,round(L/2))/L/(t(2) - t(1));

%figure;
%plot(f2,X2);
%hold on;
%plot(f2,mean(X2), 'g');

