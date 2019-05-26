%Section 3

close;
t = -pi:1/1000:pi;
x = sin(5*pi*t) - cos(7*pi*t);
subplot(221);
plot(t,x);

subplot(222);
[W X] = FourierTransform(x,t);
plot(W,abs(X));
subplot(223);
x1 = ifft(X);
plot(linspace(t(1),t(end),length(x1)),real(x1));
subplot(224);
XX = -2i*(3*W.^2 - 6).*sin(W)./(W.^4) + ((6*W - W.^3).*cos(W))./(W.^4);
plot(W, real(XX));
titlehold on;
plot(W, imag(XX));
