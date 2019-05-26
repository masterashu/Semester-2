plot(f,X);
hold on;
stem([f(mx1), f(mx2)], [X(mx1), X(mx2)], 'r', 'filled');
title('Fourier Transform for Continous Signal'); xlabel('f (Hz)'); ylabel('X(W)');
grid;
mTxt = sprintf('  Wm = %.2f Hz',f(mx1));
text(f(mx1), X(mx1) + 0.1, mTxt);
mTxt = sprintf('  Wm = %.2f Hz',f(mx2));
text(f(mx2), X(mx2) + 0.1, mTxt, 'HorizontalAlignment', 'right');
Nr = 2*(f(mx1));
sprintf('Nyquist Rate is %.2f Hz.', Nr)