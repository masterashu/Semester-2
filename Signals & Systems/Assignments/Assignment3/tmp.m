W = -20*pi : pi/100 : 20*pi;
X = (W.*sin(W) - cos(W) + 1)./(W.^2);
plot(W, real(X));
hold on;
plot(W, imag(X));
title('Fourier Transform Theoretical X(W) = sin(W)/W - cos(W)/W^2 + 1/ W^2');
xlabel('W');
ylabel('X(W)');
legend('Real','Imaginary');