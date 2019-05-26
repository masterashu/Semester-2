% Sampling
close all;
clear;

% Time Vector and Continous Signal

W = 2*pi/3;

dt = 0.01;
t = 0 : dt : 10;
x = sin(W*t)- cos(W*t/2);

figure;

sampling_rate = floor((pi / W)/ dt) * dt : -dt : floor((pi /(W * 10))/dt) * dt;

for s_rate = sampling_rate
    
    clf;
    sample_time = t(1) : s_rate : t(end);
    sample_signal = zeros(size(sample_time));

    for tt = sample_time
        sample_signal(sample_time == tt) = x(abs(t - tt) < dt/2);
    end

    plot(t,x);
    hold on;
    stem(sample_time, sample_signal, 'rx');
    pause(0.1);
end

