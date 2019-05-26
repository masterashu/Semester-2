%Section 3

close;
t = -1:1/1000:1;
x = t.^3;
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
plot(W, XX);

