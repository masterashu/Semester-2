AK2 = 1/3*(-2*W*K.*sin(W*K)./(W.^2*K.^2 - pi^2));
figure;
stem(K,real(AK2))
hold on;
stem(K,imag(AK2))
hold on;
stem(0, 0);
title('Theoretical Fourier Coefficients');
legend('Real AK Theoretical', 'Imaginary AK Theoritical', 'A0 Theoretical');
ylabel('Theoretical AK')
xlabel('K');