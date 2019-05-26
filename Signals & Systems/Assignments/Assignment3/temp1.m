t = -50:0.01:50;
x = sin(2*pi*t) - 3*cos(4*pi*t) + sin(7*pi*t);
y = fft(x);
f = (0:length(y)-1)*100/length(y);
subplot(211);
plot(f,abs(y));
subplot(212);
plot(-50:50,FourierTransform(x,t,-50:50));

